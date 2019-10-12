#include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;

struct nodo{
	int valor;
	struct nodo *anterior;
	struct nodo *siguiente;
};
void menu();
void insertar(nodo*&,int );
void imprimir(nodo*);

nodo*lista=NULL;

int main(){

    menu();	
    
	getch();
	return 0;
}
void insertar(nodo*&lista, int dato){
	nodo*nodonuevo = new nodo();
	nodonuevo->siguiente=NULL;
	nodonuevo->anterior=NULL;
	nodonuevo->valor =dato;
	if(lista==NULL){
		lista=nodonuevo;
	}else{
		nodo * auxiliar=lista;
		while(auxiliar->siguiente!=NULL){
			auxiliar= auxiliar->siguiente;
		}
		auxiliar->siguiente=nodonuevo;
		nodonuevo->anterior=auxiliar;
	}
	
    cout<<dato<<" numero guardado\n";
}
void imprimir(nodo*lista){
	nodo*inicio=new nodo();
	inicio=lista;
	
	while(inicio !=NULL){
		cout<<inicio->valor<<"-";
		inicio=inicio->siguiente;
	}
}
	
void menu(){
	int opcion, valor;
	
	do{
		cout<<"\t.:::MENU:::.\n";
		cout<<"1.- agregar valores\n";
		cout<<"2.- imprimir\n";
		cout<<"3.- salir\n";
		cout<<"elije una opcion: ";
		cin>>opcion;
		
		switch(opcion){
			case 1:
				cout<<"\n ingrese un numero: ";
				cin>>valor;
				insertar(lista,valor);
				cout<<"\n";
				system("pause");
			break;
			
			case 2:
				imprimir(lista);
				cout<<"\n";
				system("pause");
			break;		
		}
		system("cls");
	}while(opcion !=3);
}
