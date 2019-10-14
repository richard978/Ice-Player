#pragma once
#include"newButton.h"
#include<QtWidgets>

class VolButton : public QWidget
{
	Q_OBJECT

public:
	VolButton(QWidget *parent = 0);
	~VolButton();

	//��������ֵ��0~100��
	int get_Volume() const;

	//�����������Ƿ�ɼ�
	void set_Slider_Visiable(bool);

	public slots:

	//���������ʹ��������һ����	
	//void increase_Volume();

	//���������ʹ��������һ����
	//void descrease_Volume();

	//��������
	void set_Volume(int volume);

	//��ť�����¼��������˵�
	void button_Clicked();

signals:

	//�����ı��źţ������������϶�ʱ���䣩
	void volume_Changed(int volume);

private:
	newButton * button;
	QSlider *slider;
	QMenu *menu;
	QWidgetAction *action;
};
