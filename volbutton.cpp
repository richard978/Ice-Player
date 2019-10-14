#include"volbutton.h"

VolButton::~VolButton() {

}

VolButton::VolButton(QWidget *parent) :QWidget(parent) {

	slider = new QSlider(Qt::Horizontal);
	slider->setRange(0, 100);
	slider->setStyleSheet("QSlider::groove:horizontal{border:0px;height:4px;}"
		"QSlider::sub-page:horizontal{background:#0096ff;}"
		"QSlider::add-page:horizontal{background:lightgray;} "
		"QSlider::handle:horizontal{background:white;width:10px;border:#51b5fb 10px;border-radius:5px;margin:-3px 0px -3px 0px;}");

	button = new newButton;
	button->set_Button_Icons(QIcon("Resources/voice.png"), QIcon("Resources/voice2.png"));
	button->setIconSize(QSize(30, 30));
	button->setStyleSheet("QPushButton{background-color:rgba(255,255,255,0);border-style:solid;border-width:0px;border-color:rgba(255,255,255,0);}");

	connect(button, SIGNAL(clicked()), this, SLOT(button_Clicked()));
	connect(slider, SIGNAL(valueChanged(int)), this, SIGNAL(volume_Changed(int)));

	menu = new QMenu;
	action = new QWidgetAction(this);
	action->setDefaultWidget(slider);
	menu->addAction(action);

	QVBoxLayout *h = new QVBoxLayout;
	h->addWidget(button);
	h->setContentsMargins(QMargins(0, 0, 10, 0));
	setLayout(h);

}

int VolButton::get_Volume() const {
	return slider->value();
}


void VolButton::set_Slider_Visiable(bool a) {
	slider->setVisible(a);
}
/*
void VolButton::increase_Volume() {
slider->triggerAction(QSlider::SliderPageStepAdd);
emit volume_Changed(get_Volume());
}

void VolButton::descrease_Volume() {
slider->triggerAction(QSlider::SliderPageStepSub);
emit volume_Changed(get_Volume());
int a = get_Volume();

}
*/
void VolButton::set_Volume(int volume) {
	slider->setValue(volume);
	emit volume_Changed(volume);
}

void VolButton::button_Clicked() {
	menu->exec(QCursor::pos());
}