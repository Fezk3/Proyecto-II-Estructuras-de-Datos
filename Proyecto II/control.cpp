#include "control.h"

control::control(){
	
}

void control::instrucciones(){
	
	cout<<"Instrucciones: \n\n";
	cout<<"Responda a las preguntas con:\tSi/si o No/no \n\n";
	system("pause");
	system("cls");
	
}

void control::menuPrincipal(){
	
	string op;
	
	do{
		
		cout<<"Bienvenido al Akinator Tico!\n";
		cout<<"\nSeleccione una opcion:\n\n";
		cout<<"1. Jugar\n";
		cout<<"2. Salir\n\n";
		
		cin>>op;
		
		if(op == "1"){
			
			system("cls");
			menuJuego();
			
		}else if(op=="2"){
			
			system("cls");
			cout<<"Gracias por jugar, hasta pronto!\n\n";
			system("pause");
			system("cls");
			break;
			
		}else{
			
			system("cls");
			cout<<"Opcion invalida\n\n";
			system("pause");
			system("cls");
			
		}
		

	} while(op!="2");
	
}

void control::menuJuego(){
	
	fstream file;
	file.open("datos.txt",ios::in);
	arbolito.cargarArbol(arbolito.inicio,file);
	file.close();
	instrucciones();
	cout<<"Responda las siguientes preguntas\n\n";
	arbolito.pregunta(arbolito.inicio,NULL);
	file.open("datos.txt",ios::out);
	arbolito.guardaArbol(arbolito.inicio,file);
	file.close();
	
}
