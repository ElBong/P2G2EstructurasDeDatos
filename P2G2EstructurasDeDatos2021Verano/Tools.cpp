/*
* @author Arnoldo González Quesada, Boris Monge Chaves,Carlos Álvarez Ramírez.
* @ v1.0
* .cpp file that contain some useful functions in order to interact with
* the program's console.
*
*/
#include "Tools.h"

string read() {
	string x;
	getline(cin, x);
	return x;
}
void print(string x) { cout << x; }
void printn(string x) { cout << x <<"\n"; }
void printnError(string x) { cerr << "ERROR: " << x << "\n"; }

int readInt() {
	while (1) {
		try {
			return stoi(read());
		}catch (...) {
			throw InvalidInput("Digite un número entero.\n");
		}
	}
}
float readFloat() {
	while (1) {
		try {
			return stof(read());
		}
		catch (...) {
			throw InvalidInput("Digite un número real.\n");
		}
	}
}

long long readLongLong() {
	while (1) {
		try {
			return stoll(read());
		}
		catch (...) {
			throw InvalidInput("Digite un numero entero.\n");
		}
	}
}

void cont() { //continue
	printn("Digite cualquier tecla para continuar.");
	_getch();

}
void clearScreen() {
	if (system("cls")) system("clear");
}

void programExit()
{
	exit(0);
}

bool readBoolean() {
	int n;
	while (1) {
		try {
			n = readInt();
			if (n == 1) return true;
			if (n == 0) return false;
		}
		catch (RuntimeException) {
			throw InvalidInput("Digite 1 o 0.");
		}
	}
}

long long getTime() {
	return chrono::time_point_cast<chrono::nanoseconds>(
		chrono::high_resolution_clock::now()
		).time_since_epoch().count();
}
float rdmFloat()
{
	//Genera un float aleatorio entre 0 y 1
	//srand(time(NULL)); //This should be done only once
	float n = 7.0f;
	return (float)(((rand() % int(n)) / n));
}

int rdmInt(int n)
{
	return rand() % n;
}