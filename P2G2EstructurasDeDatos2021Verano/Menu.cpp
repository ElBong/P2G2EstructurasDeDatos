#include "Menu.h"
Menu::Menu() {
	tf = new TwoFour();
}
Menu::~Menu() { delete tf; }
void Menu::startScreen() {
	setlocale(LC_ALL, "");
	printn("..............................................................................");
	printn("Autores: ");
	printn("	-Arnoldo González Quesada.");
	printn("	-Boris Monge Chaves.");
	printn("	-Carlos Álvarez Ramírez.");
	printn("Grupo #2.");
	printn("Proyecto II. Estructuras de datos. EIF-207.");
	printn("Escuela de informática. Universidad Nacional. Heredia, Costa Rica.");
	printn("Profesor: Ms.C Gregorio Villalobos Camacho.");
	printn("Enero, 2021.");
	printn("..............................................................................");
	cont();
}
void Menu::mainMenu() {
	setlocale(LC_ALL, ""); //For spanish accents
	startScreen();
	while (true) {
		clearScreen();
		printn("..............................................................................");
		printn("¡Bienvenido!");
		printn("Seleccione una de las opciones: ");
		printn("1- Insertar números enteros aleatorios.");
		printn("2- Realizar operaciones 2n con probabilidad.");
		printn("3- Imprimir \"In-Order\".");
		printn("4- Ver el árbol nivel por nivel.");
		printn("5- Insertar un elemento.");
		printn("6- Eliminar un elemento.");
		printn("7- Buscar un elemento.");
		printn("8- Salir del programa.");
		printn("..............................................................................");
		try {
			switch (_getch()) {
				case '1': option1(); break;
				case '2': option2(); break;
				case '3': option3(); break;
				case '4': option4(); break;
				case '5': option5(); break;
				case '6': option6(); break;
				case '7': option7(); break;
				case '8': option8(); break;
				default: throw InvalidOption("La opción de menú digitada es inválida.");
			}
		}
		catch (RuntimeException e) { printnError(e.ErrorMessage()); cont(); }
	}
}

void Menu::option1() {
	clearScreen();
	printn("..............................................................................");
	printn("Opción 1: Insertar números enteros aleatorios.");
	printn("..............................................................................");


	cont();
}
void Menu::option2() {
	clearScreen();
	printn("..............................................................................");
	printn("Opción 2: Realizar operaciones 2n con probabilidad.");
	printn("..............................................................................");


	cont();
}
void Menu::option3() {
	clearScreen();
	printn("..............................................................................");
	printn("Opción 3: Imprimir \"In-Order\".");
	printn("..............................................................................");


	cont();
}
void Menu::option4() {
	clearScreen();
	printn("..............................................................................");
	printn("Opción 4: Ver el árbol nivel por nivel.");
	printn("..............................................................................");


	cont();
}
void Menu::option5() {
	clearScreen();
	printn("..............................................................................");
	printn("Opción 5: Insertar un elemento.");
	printn("..............................................................................");


	cont();
}
void Menu::option6() {
	clearScreen();
	printn("..............................................................................");
	printn("Opción 6: Eliminar un elemento.");
	printn("..............................................................................");


	cont();
}
void Menu::option7() {
	clearScreen();
	printn("..............................................................................");
	printn("Opción 7: Buscar un elemento.");
	printn("..............................................................................");


	cont();
}
void Menu::option8() {
	printn("Gracias por usar este programa!");
	delete this;
	exit(0);
}