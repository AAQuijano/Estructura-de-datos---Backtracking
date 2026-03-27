#ifndef estructura
#define estrutura

#include<iostream>
//#include<string>

struct nodo{
    std::string name;
    struct nodo *neu;
    struct arista *axo;
}; typedef struct nodo *Tnodo;

struct arista{
    float km;
    float time;
    float price;
    struct nodo *destino;
    struct arista *sig;

}; typedef struct arista *Tarista;

Tnodo neuron;
Tarista axon;

class Grafo{
    public:
        void create_neuron(std::string name);

       void create_axon(std::string name, Tnodo &nodo);

       void add_axon(Tnodo &nodo1, Tnodo &nodo2, Tarista &nuevo);
};

#endif