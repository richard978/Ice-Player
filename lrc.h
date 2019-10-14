#pragma once

#include<iostream>
#include<QtWidgets>
#include"newButton.h"
#include<string>
#include<fstream>
#include<map>
#include<regex>
#include<sstream>

using namespace std;

class lrc :public QWidget{

	Q_OBJECT

private:
	void initUI();
	void changeLrc(int nowtime);

	newButton *closeLrc;
	map<long, QString> *lrcMap;
	QTextEdit *lrcText;
	QTextCursor myCursor;
	double totalTime;
	int lastTime;
	int count;
	int maxHeight;
	double offset;

public:
	explicit lrc(QWidget *parent = 0);
	~lrc();
	void setTotalTime(double time);
	void readLrc(QString filename);

private slots:
	void on_closeLrc_clicked();
	void slideLrc(int time);

signals:
	void timeChanged(int time);
};