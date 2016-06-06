#include "EventEngine.h"

EventEngine::EventEngine(DWORD input, DWORD output) : _console(GetStdHandle(input))
{
	GetConsoleMode(_console, &_consoleMode);
	SetConsoleMode(_console, ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT);
}

EventEngine::~EventEngine()
{
}

void EventEngine::run(IControl & c)
{
	c.Show();
	IControl::setFocus(c);
	
	for (;;)
	{
		INPUT_RECORD record;
		DWORD count;
		ReadConsoleInput(_console, &record, 1, &count);
		IControl* f = &IControl::getFocus();
		switch (record.EventType)
		{
		case KEY_EVENT:
		{
			f->keyPress(record.Event.KeyEvent);
		}
		case MOUSE_EVENT:
		{
			f->mouseEvent(record.Event.MouseEvent);
		}
		default:

			break;
		}
	}
}
