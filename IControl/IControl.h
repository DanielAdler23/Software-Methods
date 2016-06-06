#pragma once

#include <iostream>
#include <Windows.h>
#include <vector>
#include <string>
#include "Graphics\Graphics.h"

using namespace std;


class IControl
{
protected:
	int width, height = 3, left, top;
	COORD coord;
	BorderType border;
	ForegroundColor foreground = ForegroundColor::White;
	BackgroundColor background = BackgroundColor::Black;

	Graphics _graphics;
	HANDLE _console;
	DWORD _consoleMode;

	static IControl* focus;

public:

	static void setFocus(IControl& control);
	static IControl& getFocus();

	IControl(DWORD input = STD_INPUT_HANDLE, DWORD output = STD_OUTPUT_HANDLE);
	~IControl();
	void printBorder(int height, int width, int left, int top, BorderType type);
	virtual void setLeft(int _left);
	virtual void setTop(int _top);
	virtual int getLeft();
	virtual int getTop();
	virtual int getWidth() = 0;
	virtual int getHeight() = 0;
	virtual void Show() = 0;
	virtual void Hide() = 0;
	virtual void SetForeground(ForegroundColor color) = 0;
	virtual void SetBackground(BackgroundColor color) = 0;
	virtual void SetBorder(BorderType _border) = 0;
	virtual BorderType getBorder() = 0;
	virtual void mouseEvent(MOUSE_EVENT_RECORD mer) = 0;
	virtual void keyPress(KEY_EVENT_RECORD ker) = 0;
};