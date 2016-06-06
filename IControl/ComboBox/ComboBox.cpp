#include "ComboBox.h"



ComboBox::ComboBox()
{
}

ComboBox::ComboBox(int _width, vector<string> _options)
{
	this->width = _width;
	options.swap(_options);
}


ComboBox::~ComboBox()
{
}

size_t ComboBox::GetSelectedIndex()
{
	return size_t();
}

void ComboBox::SetSelectedIndex(size_t index)
{
}

void ComboBox::Show() const
{
}

void ComboBox::Hide()
{
}

void ComboBox::SetForeground(ForegroundColor color)
{
}

void ComboBox::SetBackground(BackgroundColor color)
{
}

void ComboBox::SetBorder(BorderType _border)
{
	this->border = _border;
}

BorderType ComboBox::getBorder()
{
	return this->border;
}

void ComboBox::mouseEvent(MOUSE_EVENT_RECORD mer)
{
}

void ComboBox::keyPress(KEY_EVENT_RECORD ker, COORD)
{
}
