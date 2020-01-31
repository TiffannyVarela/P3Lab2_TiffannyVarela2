#include <iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;

int menu();
void Ejercicio1();
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

void Ejercicio3();
void readArray2(int*,int,int);//leer el numero de cuatro digitos
int num_iguales(int*,int);//revisar en el arreglo sihay numeros iguales
void arreglarArregloMenor(int*, int);//arreglar de mayor a menor
int devolver_numero(int*, int);//devolver el numero desde el arreglo
void readArray3(int*,int,int);//agregar ceros

int main(){//inicio del main
	int resp=-1;
	int opc;

	do{//inicio del do while
		switch(opc=menu()){//inicio del switch
			case 1:
				Ejercicio1();
				break;
			case 2:
				Ejercicio2();
				break;
			case 3:
				Ejercicio3();
				break;
		}//fin del switch
		cout<<"Desea volver al programa \n1.Si\n2.No"<<endl;
		cin>>resp;
	}while(resp!=2);//fin del do while
	return 0;
}//fin main

int menu(){//inicio metodo menu
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
}//fin metodo menu

void Ejercicio1(){//inicio ejercicio 1
	int n1, n2;
	cout<<"Ingrese numero 1: ";
	cin>>n1;
	while(n1<0){
	        cout<<"Ingrese un numero positivo: ";
                cin>>n1;
	}
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
}//fin ejercicio 1

void MCD(int a, int b){//inicio MCD
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
}//fin MCD

void Ejercicio2(){//inicio ejercicio 2
	int tam=0;
	cout<<"Ingrese el tamanio: ";
	cin>>tam;
	int* arreglo = inicializar(tam);
	readArray(arreglo,tam);
	printArray(arreglo,tam);
	arreglarArreglo(arreglo,tam);
	printArray(arreglo,tam);
	freeArray(arreglo);
}//fin ejercicio 2

int* inicializar( int size){//inicio inicializar
	int* retval = new int[size];
	return retval;
}//fin inicializar

void printArray (int* array, int size){//inicio print array
	cout<<"El contenido del arreglo es: ";
	for(int i=0; i<size;i++){
		cout<<" ["<<array[i]<<"] ";
	}
	cout<<endl;
}//fin print array

void freeArray(int* array){//inicio free array
	if (array!=NULL){
		delete[] array;
	}
}//fin free array

void readArray(int* array,int size){//inicio read array
	srand(time(NULL));
	for(int i=0; i<size;i++){
		array[i]=rand()%100;
	}
}//fin read array


void arreglarArreglo(int* arreglo, int size){//inicio arreglar arreglo
	int temp=-1;
	for(int i=0; i<size; i++){
		for(int j=0; j<size-i; j++){
			if(arreglo[j-1]>arreglo[j]){
				temp=arreglo[j-1];
				arreglo[j-1]=arreglo[j];
				arreglo[j]=temp;
			}
		}
	}
}//fin arreglar arreglo

void Ejercicio3(){//inicio ejercicio 3
	int num;
	int* temp=inicializar(4);
	int* temp2=inicializar(4);
	int num1, num2, resp;
	cout<<"Ingrese un numero de 4 digitos: ";
	cin>>num;
	while(num<1234||num>9999){
		cout<<"Ingrese un numero de cuatro digitos: ";
		cin>>num;
	}
	readArray2(temp,4,num);
	readArray2(temp2,4,num);
	if(num_iguales(temp,4)==-1){
		cout<<"Numero invalido"<<endl;
	}
	else{
		arreglarArreglo(temp,4);
	        arreglarArregloMenor(temp2,4);
		do{
			num1=devolver_numero(temp,4);
			num2=devolver_numero(temp2,4);
			resp=num2-num1;
			cout<<num1<<" - "<<num2<<" = "<<resp<<endl;
			readArray2(temp,4,resp);
			readArray2(temp2,4,resp);
			arreglarArreglo(temp,4);
	                arreglarArregloMenor(temp2,4);

		}while(resp!=6174);
	}
	freeArray(temp);
	freeArray(temp2);
}//fin ejercicio 3

void readArray2(int* array,int size, int num){//inicio read array 2
	while(num>0){
		array[size-1]=num%10;
		num=num/10;
		size--;
	}
}//fin read array 2


int num_iguales(int* arreglo, int size){//inicio num_iguales
	int resp = 0;
	for(int i=0; i<size; i++){
		for(int j=0; j<size-i; j++){
			if(arreglo[j-1]==arreglo[j]){
				resp = -1;
			}
		}
	}
	return resp;
}//fin num_iguales

void arreglarArregloMenor(int* arreglo, int size){//inicio arreglar arreglo menor
        int temp=0;
        for(int i=0; i<size; i++){
                for(int j=0; j<size-i-1; j++){
			if(arreglo[j+1]>arreglo[j]){
                                temp=arreglo[j+1];
                                arreglo[j+1]=arreglo[j];
                                arreglo[j]=temp;
                        }
                }
        }
}//fin arreglar arreglo menor

int devolver_numero(int* arreglo, int size){//inicio devolver numero
	int num=0;
	for(int i=0; i<size; i++){
		switch(i){
			case 0:
				num+=arreglo[i]*1000;
				break;

			case 1:
				num+=arreglo[i]*100;
				break;

			case 2:
				num+=arreglo[i]*10;
				break;

			case 3:
				num+=arreglo[i];
				break;
		}
	}
	return num;
}//fin devolver numero

