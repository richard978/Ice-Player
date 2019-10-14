#pragma once
#include"newButton.h"
#include<QtWidgets>

class VolButton : public QWidget
{
	Q_OBJECT

public:
	VolButton(QWidget *parent = 0);
	~VolButton();

	//返回音量值（0~100）
	int get_Volume() const;

	//设置音量条是否可见
	void set_Slider_Visiable(bool);

	public slots:

	//点击音量条使音量增加一部分	
	//void increase_Volume();

	//点击音量条使音量减少一部分
	//void descrease_Volume();

	//设置音量
	void set_Volume(int volume);

	//按钮单击事件，弹出菜单
	void button_Clicked();

signals:

	//音量改变信号（当音量条被拖动时发射）
	void volume_Changed(int volume);

private:
	newButton * button;
	QSlider *slider;
	QMenu *menu;
	QWidgetAction *action;
};
