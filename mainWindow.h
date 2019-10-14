#pragma once

#include<QtWidgets>
#include<QMediaplayer>
#include<QMediaplaylist>
#include<QMediametadata>
#include"newButton.h"
#include"volbutton.h"
#include"lrc.h"

class mainWindow : public QWidget{

	//使用信号和槽
	Q_OBJECT

	//设置mini窗口类为主窗口类的友元类，从而可以调用主窗口类的私有函数和私有对象
	friend class miniWindow;

protected:
	void mousePressEvent(QMouseEvent *);
	void mouseMoveEvent(QMouseEvent *);
	void mouseReleaseEvent(QMouseEvent *);

private:
	void initUI();
	void initPlayer();
	void initConnection();
	void initLrcView();

	//鼠标按下的初始位置
	QPoint startPoint;
	QPoint windowPoint;
	bool isDrag;

	//判断是否拖动进度条
	bool isSlide;
	QString playingFile;

	QStringList playList;

	//歌名
	QLabel *songName;
	//歌手
	QLabel *songSinger;
	//歌曲专辑
	QLabel *songAlbum;
	//歌曲时间进度
	QLabel *songTime;
	//专辑图片
	QLabel *albumImage;

	//退出
	newButton *exitMainWindow;
	//切换mini窗口
	newButton *toMiniWindow;
	//隐藏窗口
	newButton *hideMainWindow;
	//开发者信息
	newButton *developerInf;
	//添加文件
	newButton *addFile;
	//显示歌词
	newButton *showLrc;
	//上一首
	newButton *lastSong;
	//暂停
	newButton *pause;
	//下一首
	newButton *nextSong;
	
	//播放模式
	newButton *playModeBar;
	QMenu *playMode;

	//单曲循环
	QAction *single;
	//列表循环
	QAction *listCircle;
	//随机播放
	QAction *listRandom;
	//声音按钮
	VolButton *volSetting;

	//音乐列表
	QTableWidget *playlistTable;

	//音乐媒体
	QMediaPlayer *mediaPlayer;

	//媒体列表
	QMediaPlaylist *mediaList;

	//进度条
	QSlider *playSlider;

	//音量调节,需要定义新的类，点击可见
	QSlider *volSlider;

	//创建歌词窗口对象
	lrc *lrcView;

private slots:

	//添加文件
	void f_addFile();

	//显示歌词
	void f_showLrc();

	//上一曲
	void f_lastSong();

	//暂停或者播放
	void f_pause();

	//下一曲
	void f_nextSong();

	//双击列表播放
	void tablePlay(int, int);

	//设置音量
	void setPlayerVolumn(int);

	//更新Label标签
	void updateLabel();

	/*--------------------------------------------------------*/
	void seek(int sec);

	void pressState();

	void releaseState();
	
	//歌词相关槽函数
	void on_showLrc_clicked();

	void slide_lrc(int time);

	void change_slider_time(int time);
	/*--------------------------------------------------------*/

public:
	explicit mainWindow(QWidget *parent = 0);
	~mainWindow();
};