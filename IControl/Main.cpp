#include "IControl.h"
#include "Panel\Panel.h"
#include "TextBox\TextBox.h"
#include "EventEngine\EventEngine.h"

using namespace std;

int main()
{
	TextBox textbox1(20);
	textbox1.SetBorder(BorderType::Double);
	textbox1.SetForeground(ForegroundColor::Teal);
	textbox1.setLeft(10);
	textbox1.setTop(10);

	TextBox textbox2(30);

	//Panel panel(60, 25);

	//panel.addControl(textbox1, 5, 5);
	//panel.addControl(textbox2, 10, 10);

	EventEngine engine;

	engine.run(textbox1);

	getchar();
	return 0;
}