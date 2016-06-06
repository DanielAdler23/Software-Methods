#include "CheckList.h"



CheckList::CheckList()
{
}

CheckList::CheckList(int _height, int _width, vector<string> _options)
{
	this->height = _height;
	this->width = _width;
	options.swap(_options);
}


CheckList::~CheckList()
{
}

vector<size_t> CheckList::GetSelectedIndices()
{
	return vector<size_t>();
}

void CheckList::SelectIndex(size_t index)
{
}

void CheckList::DeselectIndex(size_t index)
{
}

void CheckList::Show() const
{
}

void CheckList::Hide()
{
}

void CheckList::SetForeground(ForegroundColor color)
{
}

void CheckList::SetBackground(BackgroundColor color)
{
}

void CheckList::SetBorder(BorderType _border)
{
	this->border = _border;
}

BorderType CheckList::getBorder()
{
	return this->border;
}

void CheckList::mouseEvent(MOUSE_EVENT_RECORD mer)
{
}

void CheckList::keyPress(KEY_EVENT_RECORD ker, COORD)
{
}