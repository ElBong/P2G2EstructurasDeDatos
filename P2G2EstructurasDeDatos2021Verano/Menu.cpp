#include "Menu.h"
Menu::Menu() {
	tf = new TwoFour();
}
Menu::~Menu() { delete tf; }
const int Menu::MAX_RAND = 500;
void Menu::startScreen() {
	setlocale(LC_ALL, "");
	printn("..............................................................................");
	printn("Estudiantes: ");
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
		printn("3- Mostrar recorrido \"In-Order\".");
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
	printn("Digite la cantidad de valores que desea insertar: ");
	int rdm, n = readInt();
	srand(time(NULL));
	for (int a = 0; a < n; a++) {
		rdm = rand() % MAX_RAND + 1;
		if (!tf->find(rdm)) { //Si el elemento no existe
			printf("Insertando a: %d.\n", rdm);
			tf->insert(rdm);
		}
	}
	cont();
}
void Menu::option2() {
	clearScreen();
	printn("..............................................................................");
	printn("Opción 2: Realizar operaciones 2n con probabilidad.");
	printn("..............................................................................");
	int n, operation = 0, searchCount = 0, insertCount = 0, deleteCount = 0;
	long long startTime, endTime;
	printn("Digite el valor de n: ");
	n = readInt();
	srand(time(NULL));
	startTime = getTime();
	while (operation < (2 * n)) {
		try {
			float rand = rndFloat();
			if (rand < 0.4) {
				// Making sure insert operation runs at 0.4 probability
				int x = rndInt(n);
				Node* present = tf->find(x);
				if (present != nullptr) {
					//printn("Data Already present!!");
				}else
					tf->insert(x);
				operation++;
				insertCount++;
			}
			rand = rndFloat();
			if (rand < 0.25) { // Making sure delete operation runs at 0.25 probability
				int x = rndInt(n);
				Node* del = tf->find(x);
				if (del) {
					tf->remove(del, x);
				}else
					operation++;
				deleteCount++;
			}
			rand = rndFloat();
			if (rand < 0.35) { // Making sure search operation runs at 0.35 probability
				tf->find(rndInt(n));
				operation++;
				searchCount++;
			}
		}
		catch (...) { continue; }
	}
	endTime = getTime();
	printf("Total de operaciones de búsqueda realizadas: %d.\n", searchCount);
	printf("Total de operaciones de eliminación realizadas: %d.\n", deleteCount);
	printf("Total de operaciones de inserción realizadas: %d.\n", insertCount);
	printf("Cantidad de tiempo empleado: %lld nanosegundos.\n", endTime - startTime);
	cont();
}

void Menu::option3() {
	clearScreen();
	printn("..............................................................................");
	printn("Opción 3: Mostrar recorrido \"In-Order\".");
	printn("..............................................................................");
	if (tf->isEmpty())
		throw EmptyTree(
			"¡El árbol se encuentra vacío! Debe introducir elementos antes de usar esta opción");
	printn(tf->toString(1));
	cont();
}
void Menu::option4() {
	clearScreen();
	printn("..............................................................................");
	printn("Opción 4: Ver el árbol nivel por nivel.");
	printn("..............................................................................");
	if (tf->isEmpty())
		throw EmptyTree(
			"¡El árbol se encuentra vacío! Debe introducir elementos antes de usar esta opción");
	printn(tf->toString());
	cont();
}
void Menu::option5() {
	clearScreen();
	printn("..............................................................................");
	printn("Opción 5: Insertar un elemento.");
	printn("..............................................................................");
	printn("El árbol se encuentra conformado de la siguiente manera: ");
	printn(tf->toString());
	printn("..............................................................................");
	printn("Digite el valor que desea insertar: ");
	int value = readInt();
	if (tf->find(value))
		throw ExistingData("¡El dato ya existe!");
	else {
		tf->insert(value);
		printn("El valor fuer insertado. El árbol queda de la siguiente manera: ");
		printn(tf->toString());
	}

	cont();
}
void Menu::option6() {
	clearScreen();
	printn("..............................................................................");
	printn("Opción 6: Eliminar un elemento.");
	printn("..............................................................................");
	if (tf->isEmpty())
		throw EmptyTree(
			"¡El árbol se encuentra vacío! Debe introducir elementos antes de usar esta opción.");
	printn("El árbol se encuentra conformado de la siguiente manera: ");
	printn(tf->toString());
	printn("..............................................................................");
	printn("Digite el valor que desea eliminar: ");
	int value = readInt();
	Node* aux = tf->find(value);
	if (aux) {
		if (tf->remove(aux, value)) {
			printn("Al eliminar el valor, el árbol queda de la siguiente manera: ");
			printn(tf->toString());
		}
	}
	else
		throw DataNotFound("El elemento no existe.");
	cont();
}
void Menu::option7() {
	clearScreen();
	printn("..............................................................................");
	printn("Opción 7: Buscar un elemento.");
	printn("..............................................................................");
	if (tf->isEmpty())
		throw EmptyTree(
			"¡El árbol se encuentra vacío! Debe introducir elementos antes de usar esta opción.");
	printn("Digite el valor a buscar: ");
	int value = readInt();
	Node* found = tf->find(value);
	if (found)
		printf("¡El valor %d fue encontrado!\n",value);
	else
		printf("¡El valor %d no fue encontrado!\n", value);
	cont();
}
void Menu::option8() {
	printn("Gracias por usar este programa!");
	delete this;
	exit(0);
}