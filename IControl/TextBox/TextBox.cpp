#include "TextBox.h"



TextBox::TextBox()
{
}

TextBox::TextBox(int _width)
{
	this->width = _width;
}

TextBox::~TextBox()
{
}

void TextBox::SetValue(string value)
{
}

string TextBox::GetValue()
{
	return string();
}

int TextBox::getWidth()
{
	return this->width;
}

int TextBox::getHeight()
{
	return this->height;
}

void TextBox::Show()
{
	_graphics.setForeground(this->foreground);
	_graphics.setBackground(this->background);
	this->printBorder(height, width, left, top, border);
}

void TextBox::Hide()
{
}

void TextBox::SetForeground(ForegroundColor color)
{
	this->foreground = color;
}

void TextBox::SetBackground(BackgroundColor color)
{
	this->background = color;
}

void TextBox::SetBorder(BorderType _border)
{
	this->border = _border;
}

BorderType TextBox::getBorder()
{
	return this->border;
}

void TextBox::mouseEvent(MOUSE_EVENT_RECORD mer)
{
	int x = mer.dwMousePosition.X;
	int y = mer.dwMousePosition.Y;
	switch (mer.dwEventFlags)
	{
	case 0:
		if (mer.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED && y == top + 1 && x > left && x < left + width)
		{
			_graphics.moveTo(mer.dwMousePosition.X, top + 1);
		}
		break;
	default:
		//Nothing...
		break;
	}
}

void TextBox::keyPress(KEY_EVENT_RECORD ker)
{
	_graphics.setCursorVisibility(TRUE);
	if (ker.bKeyDown)
	{
		if (ker.wVirtualKeyCode == VK_RETURN)
		{
			//nothing...
		}
		else if (ker.wVirtualKeyCode == VK_BACK)
		{
			_graphics.getPosition(coord);
			if (coord.X <= left + 1)
				_graphics.moveTo(left + 1, top + 1);
			else
			{
				cout << "\b" << " " << "\b";
				myString.erase(coord.X - left - 2, 1);
				_graphics.moveTo(left + 1, top + 1);
				for (int j = 0; j < width - 2; j++)
					cout << " ";
				_graphics.moveTo(left + 1, top + 1);
				cout << myString;
				_graphics.moveTo(coord.X - 1, coord.Y);
			}
		}
		else if (ker.wVirtualKeyCode == VK_LEFT)
		{
			_graphics.getPosition(coord);
			if (coord.X <= left + 1)
				_graphics.moveTo(left + 1, top + 1);
			else
				_graphics.moveTo(--coord.X, top + 1);
		}
		else if (ker.wVirtualKeyCode == VK_RIGHT)
		{
			_graphics.getPosition(coord);
			if (coord.X >= left + width - 1)
				_graphics.moveTo(left + width - 1, top + 1);
			else
				_graphics.moveTo(++coord.X, coord.Y);
		}
		else if (ker.uChar.AsciiChar)
		{
			_graphics.getPosition(coord);
			if (coord.X >= left + width - 1)
			{
				_graphics.moveTo(left + width - 2, top + 1);
				myString.pop_back();
			}
			myString += ker.uChar.AsciiChar;
			cout << ker.uChar.AsciiChar;
		}
	}	
}

bool TextBox::canGetFocus()
{
	return true;
}
