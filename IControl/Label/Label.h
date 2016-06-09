#pragma once

#include "../TextBox/TextBox.h"

class Label: public TextBox
{
protected:
	string myString;
public:
	Label(int _width, string value);
	~Label();
	void SetValue(string value);
	virtual void Show();
	virtual void Hide();
	//virtual void SetForeground(ForegroundColor color);
	//virtual void SetBackground(BackgroundColor color);
	virtual void SetBorder(BorderType _border);
	virtual BorderType getBorder();
	virtual void mouseEvent(MOUSE_EVENT_RECORD mer);
	virtual void keyPress(KEY_EVENT_RECORD ker);
	virtual bool canGetFocus();
};

