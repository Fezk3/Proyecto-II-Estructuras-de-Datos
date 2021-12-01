#include "arbol.h"

arbol::arbol() {
	
	raiz = NULL;
	inicio = NULL;
	
}

void arbol::preorder(nodo *raiz){  // preordena el arbol 
	
	if(raiz == NULL){
		
		return;
		
	}
	else{
		
		cout<<raiz->preg<<endl;
		preorder(raiz->izq);
		preorder(raiz->dere);
		
	}
	
}

void arbol::pregunta(nodo* raiz, nodo* ante){
	
	string opc;
	
	if(raiz->izq!=NULL && raiz->dere!=NULL){
		
		cout<<raiz->preg<<endl;
		cin>>opc;
		
		// decidiendo a que lado del arbol ir izq(si) o derecha(no)
		if(opc=="Si" || opc=="si"){
			
			pregunta(raiz->izq,raiz);
			
		}
		else if(opc=="no" || opc=="NO"){
			
			pregunta(raiz->dere,raiz);
			
		}
		else{
			
			cout<<"\nRespuesta invalida, intente con Si/si o No/no"<<endl;
			system("pause");
			system("cls");
			pregunta(raiz,ante);
			
		}
	}
	else{ // ultima pregunta de la rama
		
		preguntaFinal(raiz,ante);
		
	}
	
}

void arbol::preguntaFinal(nodo* raiz, nodo* ante){
	
	string opc;
	
	cout<<"Estas pensando en: '"<<raiz->preg<<"' ?"<<"\n";  // posible respuesta segun lo contestado
	cin>>opc;
	
	if(opc=="Si" || opc=="si"){  // si lo adivina
		
		cout<<"\n\nLO ADIVINE!!!"<<endl;
		system("pause");
		system("cls");
		cout<<"Quiere jugar otra vez?\n";
		cin>>opc;
		
		if(opc=="Si" || opc=="si"){
			
			system("pause");
			system("cls");
			pregunta(inicio,ante);
			
		}
		else if(opc=="no" || opc=="NO"){
			
			cout<<"\nGracias por haber jugado!"<<endl;
			system("pause");
			system("cls");
			
		}
	}
	else if(opc=="no" || opc=="NO"){  // si no lo adivina, tiene que actualizar el arbol con la pregunta y la respuesta del nuevo personaje
		
	   actualizaArbol(raiz, ante);
	   
	}
	else{
		
		cout<<"\nRespuesta invalida, intente con Si/si o No/no"<<endl;
		system("pause");
		system("cls");
		preguntaFinal(raiz,ante);
		
	}
	
}

void arbol::actualizaArbol(nodo* fin, nodo*& prefin){
	
	string respuesta,preg;
	
	cout<<"\n\nAcepto mi derrota"<<endl;
	system("pause");
	system("cls");
	cout<<"En quien estabas pensando?"<<"\t";
	cin.ignore();
	getline(cin,respuesta);
	cout<<"\n\nAhora, escriba una caracteristica que identifique a "<<respuesta<<" para una respuesta de si o no que lo diferencie \n";
	getline(cin,preg);
	system("pause");
	system("cls");
	
	// creando nodo con respuesta (es una hoja)
	nodo *nodoResp, *nodoPreg;
	nodoResp = new nodo("");
	nodoResp->preg = respuesta;
	nodoResp->izq = NULL;
	nodoResp->dere = NULL;
	
	// guardando la pregunta en el nodo
	nodoPreg = new nodo("");
	nodoPreg->preg = preg;
	nodoPreg->izq = nodoResp;
	nodoPreg->dere = fin;
	
	// seleccionando donde colocar el nodo dere o izq
	if(prefin->izq == fin){
		
		prefin->izq = nodoPreg;
		
	}
	else if(prefin->dere == fin){
		
		prefin->dere = nodoPreg;
		
	}
	
	// guardando el nuevo nodo del arbol en el archivo
	fstream file;
	file.open("datos.txt",ios::out);
	guardaArbol(inicio,file);
	string opc;
	cout<<"Quiere jugar otra vez?\n";
	cin>>opc;
	
	if(opc=="Si" || opc=="si"){
		
		system("pause");
		system("cls");
		pregunta(inicio,NULL);
		
	}
	else if(opc=="no" || opc=="NO"){
		
		cout<<"\nGracias por haber jugado!"<<endl;
		system("pause");
		system("cls");
	}
	
	system("pause");
	
}

void arbol::guardaArbol(nodo*& raiz, fstream& file){  // guarda el arbol en el archivo
	
	if(raiz == NULL){
		
		file<<"+"<<endl;
		
	}
	else{
		
		file<<raiz->preg<<endl;
		guardaArbol(raiz->izq,file);
		guardaArbol(raiz->dere,file);
		
	}
	
}

void arbol::cargarArbol(nodo*& raiz,fstream& file){ // carga el arbol del archivos
	
	string contenido;
	
	if(!file.eof()){ // si el file tiene info
		
		getline(file,contenido);
		cin.clear();
		
	}
	else{  // no sigue mas si el archivo llega al eof
		
		return;
		
	}
	if(contenido!="+"){ // si la respuesta del nodo no es carga toda la parte izq primero y luego la derecha
		
		raiz = new nodo("");
		raiz->preg = contenido;
		cargarArbol(raiz->izq,file);  // cargando recursivamente la rama izq del arbol 
		cargarArbol(raiz->dere,file); // cargando recursivamente la rama derecha del arbol 
		
	}
	else{ // si se encuentra un + como respuesta pondra la raiz en null
		
		raiz = NULL;
		
	}
	
}
