#include<iostream>
#include "estructura.h"

void create_neuron(std::string name){

    Tnodo aux, nuevo = new struct nodo;
    nuevo->name = name;
    nuevo->neu = NULL;
    

    if(neuron == NULL){
        neuron = nuevo;
        std::cout<<"Primer nodo";
    }
    else{
        aux = neuron;
        while(aux->neu != NULL){
            aux = aux->neu;
        }
        aux->neu = nuevo;
        std::cout<<"Nuevo Nodo";

    }

}

void add_axon(Tnodo &nodo1, Tnodo &nodo2, Tarista &nuevo){

    Tarista a;

    if(nodo1->axo == NULL){
        nodo1->axo = nuevo;
        nuevo->destino = nodo2;
        std::cout<< "Primera arista agregada";

    }
    else{
        a = nodo1->axo;
        while(a->sig != NULL){
            a = a->sig;
        }
        nuevo->destino = nodo2;
        a->sig = nuevo;
        std::cout<<"Nueva arista";
        
    }
}

void create_axon(float km, float time, float price, Tnodo &nodo){

    Tarista aux, nuevo = new struct arista;
    nuevo->km = km;
    nuevo->time = time;
    nuevo->price = price;
    nuevo->destino = nodo;

    if(axon == NULL){
        axon = nuevo;
        std::cout<<"Primera arista";
    }
    else{
        aux = axon;
        while(aux->sig != NULL){
            aux = aux->sig;
        }
        aux->sig = nuevo;
        std::cout<<"Arista insertada";
    }

}