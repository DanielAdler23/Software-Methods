#include "RadioList.h"



RadioList::RadioList()
{
}

RadioList::RadioList(int _height, int _width, vector<string> _options)
{
	this->height = _height;
	this->width = _width;
	this->border = BorderType::None;
	chosen.resize(_options.size());
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


//void RadioList::Show()
//{
//	_graphics.setForeground(this->foreground);
//	_graphics.setBackground(this->background);
//	this->printBorder(height, width, left, top, border);
//	for (int i = 0; i < options.size(); i++)
//	{
//		
//		if (border != BorderType::None)
//			_graphics.moveTo(left + 1, i + top + 1);
//		else
//			_graphics.moveTo(left, i + top);
//		if (i == 0) {
//			_graphics.setBackground(BackgroundColor::White);
//			_graphics.setForeground(ForegroundColor::Black);
//		}
//		else
//			_graphics.resetColor();
//		cout << "( )" << options[i];
//		_graphics.moveTo(left, top);
//	}
//}

//void RadioList::Hide()
//{
//}

//void RadioList::SetForeground(ForegroundColor color)
//{
//}
//
//void RadioList::SetBackground(BackgroundColor color)
//{
//}
//
//void RadioList::SetBorder(BorderType _border)
//{
//	this->border = _border;
//}
//
//BorderType RadioList::getBorder()
//{
//	return this->border;
//}
//
//void RadioList::mouseEvent(MOUSE_EVENT_RECORD mer)
//{
//	int x = mer.dwMousePosition.X;
//	int y = mer.dwMousePosition.Y;
//	switch (mer.dwEventFlags)
//	{
//	case 0:
//
//		if (mer.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED && y >= top && y <= top + options.size() && x >= left && x < left + width)
//		{
//			mouseClick(y);
//		}
//		break;
//	case MOUSE_MOVED:
//		if (y >= top && y <= top + options.size() && x >= left && x < left + width)
//		{
//			mouseMove(y);
//		}
//
//		break;
//	default:
//		//Nothing...
//		break;
//	}
//}
//
void RadioList::keyPress(KEY_EVENT_RECORD ker)
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
				cout << "o";
			}
			--row;
			_graphics.setBackground(BackgroundColor::White);
			_graphics.setForeground(ForegroundColor::Black);
			_graphics.moveTo(left, row + top);
			cout << "[ ]" << options[row];
			if (chosen[row] == 1) {
				_graphics.moveTo(left + 1, row + top);
				cout << "o";
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
				cout << "o";
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
			clearAll();
			_graphics.moveTo(left + 1, row + top);
			cout << "o";
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

bool RadioList::canGetFocus()
{
	return true;
}

void RadioList::mouseMove(int _row)
{
	for (int i = 0; i < options.size(); i++)
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
			cout << "o";
		}
	}
	_graphics.moveTo(left, _row);
}

void RadioList::mouseClick(int _y)
{
	if (chosen[_y - top] == 0) {
		clearAll();
		_graphics.moveTo(left + 1, _y);
		cout << "o";
		chosen[_y - top]++;
	}
	else {
		_graphics.moveTo(left + 1, _y);
		cout << " ";
		chosen[_y - top]--;
	}
}

void RadioList::clearAll()
{
	_graphics.resetColor();
	for (int i = 0; i < options.size(); i++)
	{
		chosen[i] = 0;
		_graphics.moveTo(left + 1, i + top);
		cout << " ";
	}
}
