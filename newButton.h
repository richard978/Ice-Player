#pragma once
#include<QtWidgets>

class newButton : public QPushButton{
private:
	QIcon normalIcon;
	QIcon focusIcon;
	QIcon pressedIcon;

protected:

	//���ء����롱�͡��뿪���¼�������ʱ�л�Ϊ��һ��ͼ�꣬�뿪ʱ��ԭ 
	void enterEvent(QEvent *event) {
		if (!focusIcon.isNull())
			setIcon(focusIcon);
	}
	void leaveEvent(QEvent *event) {
		if (!normalIcon.isNull())
			setIcon(normalIcon);
	}

	//������갴�º��ɿ��¼� ���л�ͼ��
	void mousePressEvent(QMouseEvent *event) {
		if (!pressedIcon.isNull())
			setIcon(pressedIcon);
		QPushButton::mousePressEvent(event);
	}
	void mouseReleaseEvent(QMouseEvent *event) {
		if (!focusIcon.isNull())
			setIcon(focusIcon);
		QPushButton::mouseReleaseEvent(event);
	}

public:
	//����ͼ��
	//��ָֻ��һ��ͼ�꣬��Ĭ�ϡ����롱�����£��ɿ���Ϊ��ͼ��
	void set_Button_Icons(const QIcon &normal, const QIcon &focus = QIcon(), const QIcon &pressed = QIcon()) {
		normalIcon = normal;
		focusIcon = focus;
		pressedIcon = pressed;
		setIcon(normalIcon);
	}
};



