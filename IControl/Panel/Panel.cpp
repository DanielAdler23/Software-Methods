#include "Panel.h"

Panel::Panel()
{
}

Panel::Panel(int _height, int _width)
{
	this->height = _height;
	this->width = _width;
}


Panel::~Panel()
{
}

int Panel::getWidth()
{
	return this->width;
}

int Panel::getHeight()
{
	return this->height;
}

void Panel::addControl(IControl & control, int _left, int _top)
{
	control.setLeft(_left);
	control.setTop(_top);
	controllers.push_back(&control);
}

void Panel::Show()
{
	IControl::setFocus(*controllers[0]);
	this->printBorder(height, width, left, top, border);
	for (int i = 0; i < controllers.size(); i++)
	{
		controllers[i]->Show();
	}
	IControl* tmp = &IControl::getFocus();
	_graphics.moveTo(tmp->getLeft() + 1, tmp->getTop() + 1); 
}

void Panel::Hide()
{
}

void Panel::SetForeground(ForegroundColor color)
{
}

void Panel::SetBackground(BackgroundColor color)
{
}

void Panel::SetBorder(BorderType _border)
{
	this->border = _border;
}

BorderType Panel::getBorder()
{
	return this->border;
}

void Panel::mouseEvent(MOUSE_EVENT_RECORD mer)
{
}

void Panel::keyPress(KEY_EVENT_RECORD ker)
{
}

bool Panel::canGetFocus()
{
	return false;
}

void Panel::getAllControls(vector<IControl*>& v)
{
	v.push_back(this);
	for (auto c : controllers)
	{
		c->getAllControls(v);
	}
}


