#include "Label.h"


Label::Label(int _width, string value)
{
	this->width = _width;
	myString = value;
	border = BorderType::None;
}

Label::~Label()
{
}

void Label::SetValue(string value)
{
	myString = value;
}

void Label::Show()
{
	_graphics.setForeground(this->foreground);
	_graphics.setBackground(this->background);
	this->printBorder(height, width, left, top, border);
	cout << myString;
}

void Label::Hide()
{
}

void Label::SetForeground(ForegroundColor color)
{
}

void Label::SetBackground(BackgroundColor color)
{
}

void Label::SetBorder(BorderType _border)
{
	this->border = _border;
}

BorderType Label::getBorder()
{
	return this->border;
}

void Label::mouseEvent(MOUSE_EVENT_RECORD mer)
{
	//Do Nothing...
}

void Label::keyPress(KEY_EVENT_RECORD ker)
{
	//Do Nothing...
}
