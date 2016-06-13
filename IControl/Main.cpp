#include "IControl.h"
#include "Panel\Panel.h"
#include "Label\Label.h"
#include "TextBox\TextBox.h"
#include "ComboBox\ComboBox.h"
#include "CheckList\CheckList.h"
#include "RadioList\RadioList.h"
#include "EventEngine\EventEngine.h"

using namespace std;

int main()
{
	vector<string> options = { "Option 1", "Option 2", "Option 3", "Option 4", "Option 5" };

	Label label1(10, "Hello, World!");
	label1.SetForeground(ForegroundColor::Red);
	label1.SetBackground(BackgroundColor::Teal);

	IControl::setFocus(label1);

	TextBox textbox1(20);
	textbox1.SetBorder(BorderType::Double);
	textbox1.SetForeground(ForegroundColor::Teal);
	textbox1.setLeft(10);
	textbox1.setTop(10);

	

	ComboBox combobox1(20, options);
	combobox1.SetForeground(ForegroundColor::Purple);
	combobox1.setLeft(15);
	combobox1.setTop(10);

	CheckList checklist1(10, 20, options);
	checklist1.SetBorder(BorderType::Single);

	RadioList radiolist1(10, 20, options);


	Panel panel1(25, 60);

	panel1.addControl(combobox1, 1, 1);
	panel1.addControl(textbox1, 1, 10);
	panel1.addControl(radiolist1, 1, 15);
	panel1.addControl(label1, 20, 20);


	EventEngine engine;

	engine.run(panel1);

	getchar();
	return 0;
}