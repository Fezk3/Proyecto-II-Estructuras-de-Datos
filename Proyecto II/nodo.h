#ifndef NODO_H
#define NODO_H

#include <iostream>
#include <fstream>
#include <string.h>
#include <conio.h>
#include <sys/stat.h>

using namespace std;

class nodo {
public:
	
	nodo(string preg);
	~nodo();
	
	// atributos
	string preg;
	nodo* izq;
	nodo* dere;
	
};

#endif

