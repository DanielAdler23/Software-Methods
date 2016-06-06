#pragma once

#include "../IControl.h"

class CheckList: public IControl
{
protected:
	vector<string> options;
public:
	CheckList();
	CheckList(int _height, int _width, vector<string> _options);
	~CheckList();
	vector<size_t> GetSelectedIndices();
	void SelectIndex(size_t index);
	void DeselectIndex(size_t index);
	virtual void Show() const;
	virtual void Hide();
	virtual void SetForeground(ForegroundColor color);
	virtual void SetBackground(BackgroundColor color);
	virtual void SetBorder(BorderType _border);
	virtual BorderType getBorder();
	virtual void mouseEvent(MOUSE_EVENT_RECORD mer);
	virtual void keyPress(KEY_EVENT_RECORD ker, COORD);
};

