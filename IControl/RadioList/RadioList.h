#pragma once

#include "../CheckList/CheckList.h"

class RadioList: public CheckList
{
protected:
	vector<string> options;
public:
	RadioList();
	RadioList(int _height, int _width, vector<string> _options);
	~RadioList();
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

