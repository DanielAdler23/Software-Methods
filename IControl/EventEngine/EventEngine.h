#pragma once

#include "../IControl.h"

class EventEngine
{
private:

	HANDLE _console;
	DWORD _consoleMode;
public:
	EventEngine(DWORD input = STD_INPUT_HANDLE, DWORD output = STD_OUTPUT_HANDLE);
	virtual ~EventEngine();

	void run(IControl &c);
};
