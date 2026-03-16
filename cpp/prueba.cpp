#include<iostream>
#include<conio.h>
#include<windows.h>

using namespace std;


struct nodo{
    string name;
    struct nodo *sig;
    //struct nodo *right;
}; typedef struct nodo *Tnodo;

Tnodo head;


void fun(string name){

    Tnodo aux, nuevo = new struct nodo;
    nuevo->name = name;
    nuevo->sig = NULL;
    

    if(head == NULL){
        head = nuevo;
        cout<<"Primer nodo";
    }
    else{
        aux = head;
        while(aux->sig != NULL){
            aux = aux->sig;
        }
        aux->sig = nuevo;
        cout<<"Nodo insertado";

    }

}

int main(void){
    cout<<"Hola Mundo";
    return 0;
}