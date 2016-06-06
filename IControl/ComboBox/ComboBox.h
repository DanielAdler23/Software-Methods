#pragma once

#include "../IControl.h"

class ComboBox: public IControl
{
protected:
	vector<string> options;
public:
	ComboBox();
	ComboBox(int _width, vector<string> _options);
	~ComboBox();
	size_t GetSelectedIndex();
	void SetSelectedIndex(size_t index);
	virtual void Show() const;
	virtual void Hide();
	virtual void SetForeground(ForegroundColor color);
	virtual void SetBackground(BackgroundColor color);
	virtual void SetBorder(BorderType _border);
	virtual BorderType getBorder();
	virtual void mouseEvent(MOUSE_EVENT_RECORD mer);
	virtual void keyPress(KEY_EVENT_RECORD ker, COORD);
};
