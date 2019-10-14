#pragma once
#include<QtWidgets>

class newButton : public QPushButton{
private:
	QIcon normalIcon;
	QIcon focusIcon;
	QIcon pressedIcon;

protected:

	//重载“进入”和“离开”事件，进入时切换为另一个图标，离开时还原 
	void enterEvent(QEvent *event) {
		if (!focusIcon.isNull())
			setIcon(focusIcon);
	}
	void leaveEvent(QEvent *event) {
		if (!normalIcon.isNull())
			setIcon(normalIcon);
	}

	//重载鼠标按下和松开事件 ，切换图标
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
	//设置图标
	//若只指定一个图标，则默认“进入”，按下，松开都为此图标
	void set_Button_Icons(const QIcon &normal, const QIcon &focus = QIcon(), const QIcon &pressed = QIcon()) {
		normalIcon = normal;
		focusIcon = focus;
		pressedIcon = pressed;
		setIcon(normalIcon);
	}
};



