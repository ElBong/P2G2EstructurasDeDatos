#include "Menu.h"
int main() {
	Menu* main = new Menu();
	main->mainMenu();
	//delete main; //This is done internally
	return 0;
}