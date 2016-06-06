#include "IControl.h"

IControl* IControl::focus = 0;

IControl::IControl(DWORD input, DWORD output)
	: _console(GetStdHandle(input)), _graphics(output)
{
	GetConsoleMode(_console, &_consoleMode);
	SetConsoleMode(_console, ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT);
	_graphics.setCursorVisibility(false);
}

IControl::~IControl()
{
}

void IControl::printBorder(int height, int width, int left, int top, BorderType type)
{
	char topLeft, topRight, bottomLeft, bottomRight, vertical, horizontal;
	switch (type)
	{
	case BorderType::Single:
		topLeft = '\xDA'; topRight = '\xBF'; bottomLeft = '\xC0'; bottomRight = '\xD9'; vertical = '\xB3'; horizontal = '\xC4';
		break;

	case BorderType::Double:
		topLeft = '\xC9'; topRight = '\xBB'; bottomLeft = '\xC8'; bottomRight = '\xBC'; vertical = '\xBA'; horizontal = '\xCD';
		break;

	case BorderType::None:
		_graphics.moveTo(left, top);
		return;
		break;
	}

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (i == 0 || i == height - 1)
			{
				_graphics.moveTo(left + j, top + i);
				if (i == 0 && j == 0) cout << topLeft;
				else if (i == 0 && j == width - 1) cout << topRight;
				else if (i == height - 1 && j == 0) cout << bottomLeft;
				else if (i == height - 1 && j == width - 1) cout << bottomRight;
				else cout << horizontal;
			}
			else
			{
				_graphics.moveTo(left, top + i);
				cout << vertical;
				_graphics.moveTo(left + width - 1, top + i);
				cout << vertical;
			}
		}
	}
	_graphics.moveTo(left + 1, top + 1);
}

void IControl::setLeft(int _left)
{
	this->left = _left;
}

void IControl::setTop(int _top)
{
	this->top = _top;
}

int IControl::getLeft()
{
	return this->left;
}

int IControl::getTop()
{
	return this->top;
}

void IControl::setFocus(IControl & control)
{
	focus = &control;
}

IControl & IControl::getFocus()
{
	return *focus;
}