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
	//IControl::setFocus(c);
	
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
			if (record.Event.KeyEvent.wVirtualKeyCode == VK_TAB)
				moveFocus(c, f);
			else
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


void EventEngine::moveFocus(IControl &main, IControl *focused)
{
	vector<IControl*> controls;
	main.getAllControls(controls);
	auto it = find(controls.begin(), controls.end(), focused);
	do
		if (++it == controls.end())
			it = controls.begin();
	while (!(*it)->canGetFocus());
	IControl::setFocus(**it);
}