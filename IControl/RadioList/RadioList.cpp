#include "RadioList.h"



RadioList::RadioList()
{
}

RadioList::RadioList(int _height, int _width, vector<string> _options)
{
	this->height = _height;
	this->width = _width;
	options.swap(_options);
}


RadioList::~RadioList()
{
}

size_t RadioList::GetSelectedIndex()
{
	return size_t();
}

void RadioList::SetSelectedIndex(size_t index)
{
}

void RadioList::Show()
{
}

void RadioList::Hide()
{
}

void RadioList::SetForeground(ForegroundColor color)
{
}

void RadioList::SetBackground(BackgroundColor color)
{
}

void RadioList::SetBorder(BorderType _border)
{
	this->border = _border;
}

BorderType RadioList::getBorder()
{
	return this->border;
}

void RadioList::mouseEvent(MOUSE_EVENT_RECORD mer)
{
}

void RadioList::keyPress(KEY_EVENT_RECORD ker, COORD)
{
}
