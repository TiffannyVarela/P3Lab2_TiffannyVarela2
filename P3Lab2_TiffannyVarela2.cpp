#include <iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;

int menu();
void Ejercicio1();
//int val_negativos(int);
void MCD(int,int);


void Ejercicio2();
//inicialice un arreglo 
int* inicializar(int);
//imprimir el contenido del arreglo
void printArray(int*, int);
//libere la memoria del arreglo
void freeArray(int*);
//leer el contenido
void readArray(int*,int);
void arreglarArreglo(int*, int);

int main(){
	int resp=-1;
	int opc;

	do{
		switch(opc=menu()){
			case 1:
				Ejercicio1();
				break;
			case 2:
				Ejercicio2();
				break;
			case 3:
				break;
		}
		cout<<"Desea volver al programa \n1.Si\n2.No"<<endl;
		cin>>resp;
	}while(resp!=2);
	return 0;
}

int menu(){
        while(true){
        cout<<"MENU"<<endl
        <<"1.- Ejercicio 1"<<endl
        <<"2.- Ejercicio 2"<<endl
	<<"3.- Ejercicio 3"<<endl
	<<"4.- Salir"<<endl;
        cout<<"Ingrese una opcion: ";
        int opcion =0;
        cin>>opcion;
        if(opcion>=1 && opcion<= 4){
                return opcion;
        }
	else{
        cout<<"La opcion elegida no es valida, ingrese una opcion entre 1 y 4"<<endl;
        }
 	 }//end del while
        return 0;
}

void Ejercicio1(){
	int n1, n2;
	cout<<"Ingrese numero 1: ";
	cin>>n1;
//	cout<<"Numero1: "<<n1<<endl;
	while(n1<0){
	        cout<<"Ingrese un numero positivo: ";
                cin>>n1;
	}
//	cout<<"Numero1: "<<n1<<endl;
	cout<<"Ingrese numero 2: ";
	cin>>n2;
	while(n2<0){
                cout<<"Ingrese un numero positivo: ";
                cin>>n2;
        }
	if(n2>n1){
		cout<<"Numero 2 No puede ser mayor"<<endl;
	}
	else{
		MCD(n1,n2);
	}


}

void MCD(int a, int b){
	int r;
	if(b==0){
		cout<<"MCD: "<<a<<endl;
	}
	else{
		r=a%b;
		cout<<"mcd("<<a<<","<<b<<")="<<r<<endl;
		a=b;
		b=r;
		return MCD(a,b);
	}
}

void Ejercicio2(){
	int tam=0;
	cout<<"Ingrese el tamanio: ";
	cin>>tam;
	int* arreglo = inicializar(tam);
	readArray(arreglo,tam);
	printArray(arreglo,tam);
	arreglarArreglo(arreglo,tam);
	freeArray(arreglo);
}

int* inicializar( int size){
	int* retval = new int[size];
	return retval;
}

void printArray (int* array, int size){
	cout<<"El contenido del arreglo es: ";
	for(int i=0; i<size;i++){
		cout<<" ["<<array[i]<<"] ";
	}
	cout<<endl;
}

void freeArray(int* array){
	if (array!=NULL){
		delete[] array;
	}
}

void readArray(int* array,int size){
	srand(time(NULL));
	for(int i=0; i<size;i++){
		array[i]=rand()%100;
	}
}


void arreglarArreglo(int* arreglo, int size){
	for(int i=0; i<size; i++){
		for(int j=0; j<size; j++){

		}
	}
}


/*int val_negativos( int num){
	while(num<<0){
		cout<<"Ingrese un numero positivo: ";
		cin>>num;
	}
	return num;
}*/

