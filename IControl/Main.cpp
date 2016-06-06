#include "IControl.h"
#include "Panel\Panel.h"
#include "Label\Label.h"
#include "TextBox\TextBox.h"
#include "ComboBox\ComboBox.h"
#include "CheckList\CheckList.h"
#include "EventEngine\EventEngine.h"

using namespace std;

int main()
{
	/*TextBox textbox1(20);
	textbox1.SetBorder(BorderType::Double);
	textbox1.SetForeground(ForegroundColor::Teal);
	textbox1.setLeft(10);
	textbox1.setTop(10);*/

	vector<string> options = { "Option 1", "Option 2", "Option 3", "Option 4", "Option 5" };

	/*ComboBox combobox1(20, options);
	combobox1.SetForeground(ForegroundColor::Purple);
	combobox1.setLeft(15);
	combobox1.setTop(10);*/

	CheckList checklist1(10, 20, options);
	//checklist1.SetBorder(BorderType::Single);

	EventEngine engine;

	engine.run(checklist1);

	getchar();
	return 0;
}