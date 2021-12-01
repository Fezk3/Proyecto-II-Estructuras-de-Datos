#ifndef ARBOL_H
#define ARBOL_H

#include "nodo.h"

class arbol {
	
public:
	
	arbol();
	void pregunta(nodo* raiz, nodo* ante);
	void cargarArbol(nodo*& raiz, fstream& file);
	void actualizaArbol(nodo* fin, nodo*& prefin);
	void preguntaFinal(nodo* raiz, nodo* ante);
	void guardaArbol(nodo*& raiz, fstream& file);
	void preorder(nodo *raiz);
	
	// Atributos
	nodo *raiz , *inicio;
	
};

#endif

