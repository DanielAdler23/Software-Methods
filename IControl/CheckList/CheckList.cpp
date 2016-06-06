#include "CheckList.h"



CheckList::CheckList()
{
}

CheckList::CheckList(int _height, int _width, vector<string>& _options)
{
	this->height = _height;
	this->width = _width;
	this->border = BorderType::None;
	chosen.resize(_options.size());
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

int CheckList::getWidth()
{
	return this->width;
}

int CheckList::getHeight()
{
	return this->height;
}

void CheckList::Show()
{
	_graphics.setForeground(this->foreground);
	_graphics.setBackground(this->background);
	this->printBorder(height, width, left, top, border);
	for (int i = 0; i < options.size(); i++)
	{
		if (border != BorderType::None)
			_graphics.moveTo(left + 1, i + top + 1);
		else
			_graphics.moveTo(left, i + top);
		if (i == 0) {
			_graphics.setBackground(BackgroundColor::White);
			_graphics.setForeground(ForegroundColor::Black);
		}
		else
			_graphics.resetColor();
		cout << "[ ]" << options[i];
		_graphics.moveTo(left, top);
	}
}

void CheckList::Hide()
{
}

void CheckList::SetForeground(ForegroundColor color)
{
	this->foreground = color;
}

void CheckList::SetBackground(BackgroundColor color)
{
	this->background = color;
}

void CheckList::SetBorder(BorderType _border)
{
	if (_border != BorderType::None)
		ifBorder = 1;
	this->border = _border;
}

BorderType CheckList::getBorder()
{
	return this->border;
}

void CheckList::mouseEvent(MOUSE_EVENT_RECORD mer)
{
	int x = mer.dwMousePosition.X;
	int y = mer.dwMousePosition.Y;
	switch (mer.dwEventFlags)
	{
	case 0:

		if (mer.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED && y >= top && y <= top + options.size() && x >= left && x < left + width)
		{
			mouseClick(y);
		}
		break;
	case MOUSE_MOVED:
		if (y >= top && y <= top + options.size() && x >= left && x < left + width)
		{
			mouseMove(y);
		}

		break;
	default:
		//Nothing...
		break;
	}
}

void CheckList::keyPress(KEY_EVENT_RECORD ker)
{
	if (ifBorder == 1) {
		left++;
		top++;
		ifBorder = 0;
	}
	if (GetAsyncKeyState(VK_UP) != 0)
	{
		_graphics.getPosition(coord);
		if (coord.Y <= top)
			_graphics.moveTo(left, top);
		else
		{
			_graphics.resetColor();
			_graphics.moveTo(left, row + top);
			cout << "[ ]" << options[row];
			if (chosen[row] == 1) {
				_graphics.moveTo(left + 1, row + top);
				cout << "#";
			}
			--row;
			_graphics.setBackground(BackgroundColor::White);
			_graphics.setForeground(ForegroundColor::Black);
			_graphics.moveTo(left, row + top);
			cout << "[ ]" << options[row];
			if (chosen[row] == 1) {
				_graphics.moveTo(left + 1, row + top);
				cout << "#";
			}
		}

	}
	else if (GetAsyncKeyState(VK_DOWN) != 0)
	{
		_graphics.getPosition(coord);
		if (coord.Y >= top + options.size() - 1)
			_graphics.moveTo(left, top + options.size());
		else
		{
			_graphics.resetColor();
			_graphics.moveTo(left, row + top);
			cout << "[ ]" << options[row];
			if (chosen[row] == 1) {
				_graphics.moveTo(left + 1, row + top);
				cout << "#";
			}
			++row;
			_graphics.setBackground(BackgroundColor::White);
			_graphics.setForeground(ForegroundColor::Black);
			_graphics.moveTo(left, row + top);
			cout << "[ ]" << options[row];
			if (chosen[row] == 1) {
				_graphics.moveTo(left + 1, row + top);
				cout << "#";
			}
		}
	}
	else if (GetAsyncKeyState(VK_RETURN) != 0)
	{
		if (chosen[row] == 0) {
			
			_graphics.moveTo(left + 1, row + top);
			cout << "#";
			chosen[row]++;
		}
		else {
			_graphics.moveTo(left + 1, row + top);
			cout << " ";
			chosen[row]--;
		}
	}
	else if (ker.bKeyDown)
	{
		//Do nothing...
	}
}

void CheckList::mouseMove(int _row)
{
	for (int i = 0; i < 5; i++)
	{
		_graphics.moveTo(left, top + i);
		if (i == _row - top)
		{
			_graphics.setBackground(BackgroundColor::White);
			_graphics.setForeground(ForegroundColor::Black);
		}
		else
		{
			_graphics.resetColor();
		}
		row = _row - top;
		cout << "[ ]" << options[i];
		if (chosen[i] == 1) {
			_graphics.moveTo(left + 1, top + i);
			cout << "#";
		}
	}
	_graphics.moveTo(left, _row);
}

void CheckList::mouseClick(int _y)
{
	if (chosen[_y - top] == 0) {
		_graphics.moveTo(left + 1, _y);
		cout << "#";
		chosen[_y - top]++;
	}
	else {
		_graphics.moveTo(left + 1, _y);
		cout << " ";
		chosen[_y - top]--;
	}
}