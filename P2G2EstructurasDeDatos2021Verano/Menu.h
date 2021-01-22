#pragma once
#include "Libraries.h"
#include "RuntimeException.h"
#include "Tools.h"
#include "TwoFour.h"
class Menu {
private:
	TwoFour* tf;
public:
	Menu();
	~Menu();
	void startScreen();
	void mainMenu();
	void option1();
	void option2();
	void option3();
	void option4();
	void option5();
	void option6();
	void option7();
	void option8();
};