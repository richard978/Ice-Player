#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include"mainWindow.h"

void mainWindow::initUI() {
	
	//背景色
	QPalette palette;
	palette.setColor(QPalette::Background, QColor(221, 230, 240));
	this->setPalette(palette);
	//无边框
	setWindowFlags(Qt::FramelessWindowHint);
	//半透明
	setWindowOpacity(0.9);


	//第一行布局
	exitMainWindow = new newButton();
	exitMainWindow->set_Button_Icons(QIcon("Resources/exit.png"), QIcon("Resources/exit2.png"));
	exitMainWindow->setIconSize(QSize(25, 25));
	exitMainWindow->setStyleSheet("QPushButton{background-color:rgba(255,255,255,0);border-style:solid;border-width:0px;border-color:rgba(255,255,255,0);}"
		);
	toMiniWindow = new newButton();
	toMiniWindow->set_Button_Icons(QIcon("Resources/mini.png"), QIcon("Resources/mini2.png"));
	toMiniWindow->setIconSize(QSize(25, 25));
	toMiniWindow->setStyleSheet("QPushButton{background-color:rgba(255,255,255,0);border-style:solid;border-width:0px;border-color:rgba(255,255,255,0);}"
		);
	hideMainWindow = new newButton();
	hideMainWindow->set_Button_Icons(QIcon("Resources/small.png"), QIcon("Resources/small2.png"));
	hideMainWindow->setIconSize(QSize(25, 25));
	hideMainWindow->setStyleSheet("QPushButton{background-color:rgba(255,255,255,0);border-style:solid;border-width:0px;border-color:rgba(255,255,255,0);}"
		);
	developerInf = new newButton();

	developerInf->setObjectName(QStringLiteral("logoButton"));
	developerInf->set_Button_Icons(QIcon("Resources/logo.png"), QIcon("Resources/logo2.png"));
	developerInf->setIconSize(QSize(120, 48));
	developerInf->setStyleSheet("QPushButton{background-color:rgba(255,255,255,0);border-style:solid;border-width:0px;border-color:rgba(255,255,255,0);}"
		);

	QHBoxLayout *firstlineBox1 = new QHBoxLayout();
	QHBoxLayout *firstlineBox2 = new QHBoxLayout();
	QHBoxLayout *firstlineBox = new QHBoxLayout();
	firstlineBox1->addWidget(developerInf);
	firstlineBox1->setContentsMargins(QMargins(0, 0, 100, 0));
	firstlineBox2->addWidget(hideMainWindow);
	firstlineBox2->addWidget(toMiniWindow);
	firstlineBox2->addWidget(exitMainWindow);
	firstlineBox->addLayout(firstlineBox1);
	firstlineBox->addLayout(firstlineBox2);

	//第二行布局
	albumImage = new QLabel();
	QPixmap *albumjpg = new QPixmap();
	albumjpg->load("Resources/default_album.jpg");
	//调整专辑图片大小
	QPixmap fitpixmap = albumjpg->scaled(150, 150, Qt::KeepAspectRatioByExpanding);
	albumImage->setPixmap(fitpixmap);
	albumImage->setStyleSheet("QLabel{margin-left:20px;margin-right:20px}");
	songName = new QLabel(tr("Name"));
	songName->setFont(QFont(QString::fromLocal8Bit("微软雅黑"), 15));
	songSinger = new QLabel(tr("Singer"));
	songSinger->setFont(QFont(QString::fromLocal8Bit("微软雅黑"), 10));
	songAlbum = new QLabel(tr("Album"));
	songAlbum->setFont(QFont(QString::fromLocal8Bit("微软雅黑"), 10));

	QVBoxLayout *secondlineBox1 = new QVBoxLayout();
	QHBoxLayout *secondlineBox = new QHBoxLayout();
	secondlineBox1->addWidget(songName);
	secondlineBox1->addWidget(songSinger);
	secondlineBox1->addWidget(songAlbum);
	secondlineBox->addWidget(albumImage);
	secondlineBox->addLayout(secondlineBox1);
	secondlineBox->setContentsMargins(QMargins(0, 20, 0, 0));


	//第三行布局
	playSlider = new QSlider(Qt::Horizontal);
	/*--------------------------------------------------------*/
	songTime = new QLabel(tr("00:00"));
	playSlider->setMinimum(0);
	playSlider->setMaximum(300);         //设置歌词总长度
	playSlider->setSingleStep(1);
	playSlider->setTracking(false);
	/*--------------------------------------------------------*/

	QHBoxLayout *thridlineBox = new QHBoxLayout();
	thridlineBox->addWidget(playSlider);
	thridlineBox->addWidget(songTime);
	thridlineBox->setContentsMargins(QMargins(10, 30, 10, 0));


	//第四行布局
	addFile = new newButton();
	addFile->set_Button_Icons(QIcon("Resources/addSong.png"), QIcon("Resources/addSong2.png"));
	addFile->setIconSize(QSize(30, 30));
	addFile->setStyleSheet("QPushButton{background-color:rgba(255,255,255,0);border-style:solid;border-width:0px;border-color:rgba(255,255,255,0);}"
		"QPushButton{margin-left:5px;}"
		);
	showLrc = new newButton();
	showLrc->set_Button_Icons(QIcon("Resources/showLrc.png"), QIcon("Resources/showLrc2.png"));
	showLrc->setIconSize(QSize(30, 30));
	showLrc->setStyleSheet("QPushButton{background-color:rgba(255,255,255,0);border-style:solid;border-width:0px;border-color:rgba(255,255,255,0);}"
		"QPushButton{margin-left:5px;}"
		);
	lastSong = new newButton();
	lastSong->set_Button_Icons(QIcon("Resources/lastSong.png"), QIcon("Resources/lastSong2.png"));
	lastSong->setIconSize(QSize(30, 30));
	lastSong->setStyleSheet("QPushButton{background-color:rgba(255,255,255,0);border-style:solid;border-width:0px;border-color:rgba(255,255,255,0);}"
		"QPushButton{margin-left:5px;}"
		);
	pause = new newButton();
	pause->set_Button_Icons(QIcon("Resources/play.png"), QIcon("Resources/play2.png"));
	pause->setIconSize(QSize(60, 60));
	pause->setStyleSheet("QPushButton{background-color:rgba(255,255,255,0);border-style:solid;border-width:0px;border-color:rgba(255,255,255,0);}"
		"QPushButton{margin-left:5px;}"
		);
	nextSong = new newButton();
	nextSong->set_Button_Icons(QIcon("Resources/nextSong.png"), QIcon("Resources/nextSong2.png"));
	nextSong->setIconSize(QSize(30, 30));
	nextSong->setStyleSheet("QPushButton{background-color:rgba(255,255,255,0);border-style:solid;border-width:0px;border-color:rgba(255,255,255,0);}"
		"QPushButton{margin-left:2px;}"
		);
	playMode = new QMenu();
	playModeBar = new newButton();
	playModeBar->set_Button_Icons(QIcon("Resources/playModeBar.png"), QIcon("Resources/playModeBar2.png"));
	playModeBar->setIconSize(QSize(30, 30));
	playModeBar->setStyleSheet(
		"QPushButton{background-color:rgba(255,255,255,0);border-style:solid;border-width:0px;border-color:rgba(255,255,255,0);}"
		"QPushButton::menu-indicator{image:none;}"
		"QPushButton{margin-left:5px;}"
		);
	single = new QAction("单曲循环");
	listCircle = new QAction("列表循环");
	listRandom = new QAction("随机播放");
	playMode->addAction(single);
	playMode->addAction(listCircle);
	playMode->addAction(listRandom);
	playModeBar->setMenu(playMode);
	volSetting = new VolButton();

	QHBoxLayout *forthlineBox = new QHBoxLayout();
	forthlineBox->addWidget(addFile);
	forthlineBox->addWidget(showLrc);
	forthlineBox->addWidget(lastSong);
	forthlineBox->addWidget(pause);
	forthlineBox->addWidget(nextSong);
	forthlineBox->addWidget(playModeBar);
	forthlineBox->addWidget(volSetting);
	forthlineBox->setContentsMargins(QMargins(0, 20, 0, 0));


	//第五行布局
	playlistTable = new QTableWidget();
	playlistTable->setObjectName(QStringLiteral("playlistTable"));
	playlistTable->setColumnCount(1);
	//隐藏行号列号
	QHeaderView *hv1 = playlistTable->verticalHeader();
	hv1->setHidden(true);
	QHeaderView *hv2 = playlistTable->horizontalHeader();
	hv2->setHidden(true);
	//playlistTable->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
	playlistTable->setColumnWidth(0, playlistTable->width());
	//playlistTable->setColumnWidth(1, 45);
	playlistTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
	playlistTable->setShowGrid(false);
	playlistTable->setStyleSheet("QTableWidget{padding-top:2px;padding-bottom:2px}");

	QVBoxLayout *fifthlineBox = new QVBoxLayout();
	fifthlineBox->addWidget(playlistTable);
	fifthlineBox->setContentsMargins(QMargins(0, 20, 0, 10));


	//总布局
	QVBoxLayout *totalBox = new QVBoxLayout();
	totalBox->addLayout(firstlineBox);
	totalBox->addLayout(secondlineBox);
	totalBox->addLayout(thridlineBox);
	totalBox->addLayout(forthlineBox);
	totalBox->addLayout(fifthlineBox);
	setLayout(totalBox);

	/*--------------------------------------------------------*/
	//歌词窗口布局
	lrcView = new lrc(this);
	lrcView->setFixedSize(300, 618);
	lrcView->setTotalTime(200);
	lrcView->move(geometry().left() + 375, geometry().top());
	/*--------------------------------------------------------*/
	
}

void mainWindow::initPlayer() {

	mediaPlayer = new QMediaPlayer(this);
	mediaList = new QMediaPlaylist(this);
	mediaPlayer->setPlaylist(mediaList);
	volSetting->set_Volume(50);
	/*-----------------*/
	isSlide = 0;
	/*-----------------*/
}


void mainWindow::initConnection() {

	connect(exitMainWindow, SIGNAL(clicked()), this, SLOT(close()));
	connect(hideMainWindow, SIGNAL(clicked()), this, SLOT(showMinimized()));
	connect(addFile, SIGNAL(clicked()), this, SLOT(f_addFile()));
	connect(showLrc, SIGNAL(clicked()), this, SLOT(f_showLrc()));
	connect(lastSong, SIGNAL(clicked()), this, SLOT(f_lastSong()));
	connect(pause, SIGNAL(clicked()), this, SLOT(f_pause()));
	connect(nextSong, SIGNAL(clicked()), this, SLOT(f_nextSong()));
	connect(playlistTable, SIGNAL(cellDoubleClicked(int, int)), this, SLOT(tablePlay(int, int)));
	connect(volSetting, SIGNAL(volume_Changed(int)), this, SLOT(setPlayerVolumn(int)));
	connect(mediaPlayer, SIGNAL(metaDataChanged()), this, SLOT(updateLabel()));

	/*-----------------------------------------------------------------------------------*/
	connect(playSlider, SIGNAL(valueChanged(int)), this, SLOT(seek(int)));
	connect(playSlider, SIGNAL(sliderPressed()), this, SLOT(pressState()));
	connect(playSlider, SIGNAL(sliderReleased()), this, SLOT(releaseState()));
	connect(mediaPlayer, &QMediaPlayer::positionChanged, [this](qint64 position){
		if ((double)mediaPlayer->metaData(QMediaMetaData::Duration).toDouble() / 1000 != playSlider->maximum())
		{
			playSlider->setMaximum((double)mediaPlayer->metaData(QMediaMetaData::Duration).toDouble() / 1000);
		}
		playSlider->setValue(position/1000);
	});
	/*-----------------------------------------------------------------------------------*/
}

void mainWindow::f_addFile() {
	QStringList list = QFileDialog::getOpenFileNames(this, QString::fromLocal8Bit("添加音乐"), QString(), QString("MP3 (*.mp3)"));
	//QStringList list = QFileDialog::getOpenFileNames(this, tr("选择歌曲"), "/", "*.mp3");
	for each (QString str in list) {
		/*----------------------------------------*/
		QString dir = str.section(".", 0, -2) + ".lrc";
		lrcView->readLrc(dir);
		/*----------------------------------------*/
		if (playList.contains(str)) {
			continue;
		}
		playList.append(str);
		mediaList->addMedia(QUrl::fromLocalFile(str));
		playlistTable->insertRow(playlistTable->rowCount());
		int j = playlistTable->rowCount();
		QTableWidgetItem *item = new QTableWidgetItem;
		item->setFont(QFont(QString::fromLocal8Bit("微软雅黑"), 10));
		playlistTable->setItem(playlistTable->rowCount() - 1, 0, item);
		playlistTable->item(playlistTable->rowCount() - 1, 0)->setText(QFileInfo(str).baseName());
		if (playList.size() == 1) {
			mediaList->setCurrentIndex(0);
		}
	}

}

void mainWindow::f_showLrc() {

}

void mainWindow::f_lastSong() {

	mediaList->setPlaybackMode(QMediaPlaylist::Loop);
	mediaList->setCurrentIndex(mediaList->previousIndex());
	mediaPlayer->play();

}

void mainWindow::f_pause() {

	if (playList.isEmpty()) {
		return;
	}
	if (mediaPlayer->state() == QMediaPlayer::PlayingState) {
		mediaPlayer->pause();
		pause->set_Button_Icons(QIcon("Resources/play.png"), QIcon("Resources/play2.png"));
		pause->setIconSize(QSize(60, 60));
	}
	else {
		mediaPlayer->play();
		pause->set_Button_Icons(QIcon("Resources/pause.png"), QIcon("Resources/pause2.png"));
		pause->setIconSize(QSize(60, 60));
	}
}


void mainWindow::f_nextSong() {

	mediaList->setPlaybackMode(QMediaPlaylist::Loop);
	mediaList->setCurrentIndex(mediaList->nextIndex());
	mediaPlayer->play();

}

void mainWindow::tablePlay(int row, int col) {

	QFile file(playList.at(row));
	if (!file.open(QIODevice::ReadOnly)) {
		playlistTable->removeRow(row);
		playList.removeAt(row);
		mediaList->removeMedia(row);
		return;
	}
	file.close();
	/*-----------------------------------------------------------*/
	QString dir = playList.at(row).section(".", 0, -2) + ".lrc";
	lrcView->readLrc(dir);
	/*-----------------------------------------------------------*/
	mediaList->setCurrentIndex(row);
	mediaPlayer->play();
	pause->set_Button_Icons(QIcon("Resources/pause.png"), QIcon("Resources/pause2.png"));
	pause->setIconSize(QSize(60, 60));

}

void mainWindow::setPlayerVolumn(int vol) {
	mediaPlayer->setVolume(vol);
}

void mainWindow::updateLabel() {
	QString author = mediaPlayer->metaData(QMediaMetaData::Author).toString();
	QString title = mediaPlayer->metaData(QMediaMetaData::Title).toString();
	QString albumTitle = mediaPlayer->metaData(QMediaMetaData::AlbumTitle).toString();
	if (!author.isEmpty()) {
		songName->setText(author);
	}
	if (!title.isEmpty()) {
		songSinger->setText(title);
	}
	if (!albumTitle.isEmpty()) {
		songAlbum->setText(albumTitle);
	}
}

mainWindow::~mainWindow()
{

}


mainWindow::mainWindow(QWidget *parent) :QWidget(parent){

	/*初始化各个模块*/
	initUI();
	initPlayer();
	initConnection();
	/*--------------------------------------------------------*/
	initLrcView();
	/*--------------------------------------------------------*/
}

bool isClickOnButton() {
	int mouse_x = QCursor::pos().x();//鼠标点击处横坐标
	int mouse_y = QCursor::pos().y();//鼠标点击处纵坐标
	QWidget *action = QApplication::widgetAt(mouse_x, mouse_y);//获取鼠标点击处的控件
	return action->inherits("newButton");//判断点击的是不是newButton
}

int qqq = 1;
void mainWindow::mousePressEvent(QMouseEvent *e) {
	if (e->button() == Qt::LeftButton && !isClickOnButton())
	{
		isDrag = true;
		startPoint = e->globalPos();
		windowPoint = frameGeometry().topLeft();
	}
}

void mainWindow::mouseMoveEvent(QMouseEvent *e) {
	if (e->buttons() & Qt::LeftButton  && isDrag) {
		QPoint offset = e->globalPos() - startPoint;
		//实现移动操作
		move(windowPoint + offset);

		/*--------------------------------------------------------*/
		//设定歌词窗口位置
		lrcView->move(frameGeometry().left() + 375, frameGeometry().top());
		/*--------------------------------------------------------*/
	}
}

void mainWindow::mouseReleaseEvent(QMouseEvent *) {
	isDrag = false;
}

/*--------------------------------------------------------*/

//初始化歌词窗口在mainWindow的显示
void mainWindow::initLrcView(){
	//显示歌词、滑动歌词、歌曲时间显示的槽
	connect(showLrc, SIGNAL(clicked(bool)), this, SLOT(on_showLrc_clicked()));
	connect(playSlider, SIGNAL(valueChanged(int)), this, SLOT(slide_lrc(int)));
	connect(playSlider, SIGNAL(valueChanged(int)), this, SLOT(change_slider_time(int)));

	lrcView->show();
	emit lrcView->timeChanged(0);
	lrcView->hide();
}
//显示歌词
void mainWindow::on_showLrc_clicked(){
	if (lrcView->isHidden() == 1)
		lrcView->show();
	else
		lrcView->hide();
}
//滑动歌词
void mainWindow::slide_lrc(int time){
	lrcView->timeChanged(time);
}
//歌曲时间显示
void mainWindow::change_slider_time(int time){
	int min = time / 60;
	int sec = time - 60 * min;
	QString m = QString::number(min, 10);
	QString s = QString::number(sec, 10);

	if (s.length() == 1)
		s = "0" + s;
	QString t = m + ":" + s;
	songTime->setText(t);
}

void mainWindow::pressState(){
	if (mediaPlayer->state() == QMediaPlayer::PlayingState)
		mediaPlayer->pause();
}

void mainWindow::releaseState(){
	if (!(mediaPlayer->state() == QMediaPlayer::PlayingState))
		mediaPlayer->play();
	isSlide = !isSlide;
}

void mainWindow::seek(int sec){
	if (isSlide){
		mediaPlayer->setPosition(sec * 1000);
		isSlide = !isSlide;
	}
	
}
/*--------------------------------------------------------*/

#endif