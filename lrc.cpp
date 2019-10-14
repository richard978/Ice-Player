//#pragma execution_character_set("utf-8") 

#include "lrc.h"
#include <QTextCodec>
#include <QFile>

lrc::lrc(QWidget *parent){
	lastTime = 0;
	offset = 0;
	count = 0;
	maxHeight = 0;
	lrcMap = new map<long, QString>;
	
	initUI();

	connect(closeLrc, SIGNAL(clicked(bool)), this, SLOT(on_closeLrc_clicked()));
	connect(this, SIGNAL(timeChanged(int)), this, SLOT(slideLrc(int)));
}

lrc::~lrc(){
}

void lrc::initUI(){
	QPalette palette;
	palette.setColor(QPalette::Background, QColor(221, 230, 240));
	this->setPalette(palette);

	setWindowFlags(Qt::FramelessWindowHint);

	setWindowOpacity(0.9);

	closeLrc = new newButton();
	closeLrc->set_Button_Icons(QIcon("Resources/exit.png"), QIcon("Resources/exit2.png"));
	closeLrc->setIconSize(QSize(25, 25));
	closeLrc->setStyleSheet("QPushButton{background-color:rgba(255,255,255,0);border-style:solid;border-width:0px;border-color:rgba(255,255,255,0);}");

	QHBoxLayout *firstlineBox = new QHBoxLayout();
	firstlineBox->addStretch();
	firstlineBox->addWidget(closeLrc);

	lrcText = new QTextEdit();
	lrcText->setAlignment(Qt::AlignCenter);
	QPalette lrcBg;
	lrcBg.setColor(QPalette::Base, QColor(231, 240, 250));
	lrcText->setPalette(lrcBg);
	lrcText->setStyleSheet("border-width:0px;border-radius:5px; font-size:16px;font:bold; color:rgb(181,126,220); margin-bottom:10px;");
	lrcText->verticalScrollBar()->setVisible(false);
	lrcText->setAlignment(Qt::AlignCenter);
	lrcText->setReadOnly(true);

	QVBoxLayout *totalBox = new QVBoxLayout();
	totalBox->addLayout(firstlineBox);
	totalBox->addWidget(lrcText);

	setLayout(totalBox);
}

int str2int(const string &string_temp)
{
	int int_temp = 0;
	stringstream stream(string_temp);
	stream >> int_temp;
	return int_temp;
}

void lrc::readLrc(QString filename){
	if (filename.isEmpty())
		return;
	lrcMap->clear();
	QFile file1(filename);
	if (!file1.open(QIODevice::ReadOnly | QIODevice::Text)){
		cout << "Read failed" << endl;
	}
	else{
		while (!file1.atEnd()){
			QByteArray line = file1.readLine();
			QString str(line);
			QRegExp rx("\\[\\d{2}:\\d{2}\\.\\d{2}\\]");
			int pos = 0;
			int finalPos = 0;
			while ((pos = rx.indexIn(str, pos)) != -1){
				pos += rx.matchedLength();
				finalPos = pos;
			}
			pos = 0;
			while ((pos = rx.indexIn(str, pos)) != -1)
			{
				pos += rx.matchedLength();
				int minute = str2int(rx.cap(0).toStdString().substr(1, 2));
				int sec = str2int(rx.cap(0).toStdString().substr(4, 5));
				int miliSec = str2int(rx.cap(0).toStdString().substr(7, 8));
				long totalTime = minute * 60000 + sec * 1000 + miliSec * 10;
				if (line.mid(finalPos) != "\n")
					lrcMap->insert(pair<long, QString>(totalTime, line.mid(finalPos)));
			}
		}
	}
	/*string temp;
	regex reg("\\[\\d{2}:\\d{2}\\.\\d{2}\\]");
	smatch matchRes;

	ifstream file(filename);
	while (getline(file, temp)){
		regex_search(temp, matchRes, reg);
		if (!temp.empty()&&temp[temp.length() - 1] != ']'){
			int minute = str2int(matchRes.str(0).substr(1, 2));
			int sec = str2int(matchRes.str(0).substr(4, 5));
			int miliSec = str2int(matchRes.str(0).substr(7, 8));
			long totalTime = minute * 60000 + sec * 1000 + miliSec * 10;
			lrcMap->insert(pair<long, string>(totalTime, temp.substr(10)));
		}
	}
	file.close();*/
}

void lrc::changeLrc(int time){
	lrcText->clear();
	map<long, QString>::iterator i;
	QString finText;
	int pos = 0;
	int nowIdx = 0;
	double temp = 9999;
	for (i = lrcMap->begin(); i != lrcMap->end(); i++){
		if (temp > abs((double)((double)i->first / 1000) - (double)time)){
			if ((double)time >= abs((double)((double)i->first / 1000))){
				temp = abs((double)((double)i->first / 1000) - (double)time);
				nowIdx = pos;
			}
		}
		pos++;
	}
	pos = 0;
	for (i = lrcMap->begin(); i != lrcMap->end(); i++){
		QString tempText;
		if (pos == nowIdx){
			tempText.append("<font color=\"purple\">" + i->second + "</font><br>");
		}
		else
			tempText.append(i->second);
		lrcText->setAlignment(Qt::AlignCenter);
		lrcText->append(tempText);
		lrcText->setAlignment(Qt::AlignCenter);
		pos++;
	}

	double interval = 0;
	if (pos != 0){
		interval = maxHeight / pos + 10;
	}
	if (nowIdx * interval<250)
		lrcText->verticalScrollBar()->setValue(0);
	else{
		if (nowIdx * interval != offset){
			count++;
			lrcText->verticalScrollBar()->setValue(nowIdx * interval - interval*3/4 - 250);
		}
		else if (count == 1){
			lrcText->verticalScrollBar()->setValue(nowIdx * interval - interval / 2 - 250);
			count++;
		}
		else if (count == 2){
			lrcText->verticalScrollBar()->setValue(nowIdx * interval - interval / 4 - 250);
			count++;
		}
		else{
			count = 0;
			lrcText->verticalScrollBar()->setValue(nowIdx * interval - 250);
		}
	}
	offset = nowIdx * interval;
}
void lrc::slideLrc(int time){
	maxHeight = lrcText->verticalScrollBar()->maximum();
	//double pos = (double)max / (double)totalTime;
	changeLrc(time);
	lastTime = time;
}
void lrc::on_closeLrc_clicked(){
	if (isHidden() == 0)
		hide();
}

void lrc::setTotalTime(double time){
	totalTime = time;
}