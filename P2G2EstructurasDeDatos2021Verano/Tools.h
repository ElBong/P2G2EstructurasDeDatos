/*
* @author Arnoldo González Quesada, Boris Monge Chaves,Carlos Álvarez Ramírez.
* @ v1.0
* .h file that contain some useful functions in order to interact with
* the program's console.
*
*/
#ifndef TOOLS_H
#define TOOLS_H
#include "Libraries.h"
string read(); //Function that reads a string
void print(string x);
void printn(string x); //prints with\n 
void printnError(string x);
int readInt();
float readFloat();
long long readLongLong();
void cont(); //continue
void clearScreen();
void programExit();
bool readBoolean();
#endif