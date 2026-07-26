#ifndef Red
#define Red

#include<iostream>

struct nodo{
    std::string name;
    struct nodo *neu_sig;
    struct arista *axo;
}; typedef struct nodo *Tnodo;

struct arista{
    float km;
    float time;
    float price;
    struct nodo *destino;
    struct arista *sig;

}; typedef struct arista *Tarista;



class Grafo{
    public:
       void insert_neuron(std::string name);

       void insert_axon(float km, float time, float price, std::string nodoIni, std::string nodoFin);

       void add_axon(Tnodo &nodo1, Tnodo &nodo2, Tarista &nuevo);

       void see_red();

    private:
        Tnodo neuron = NULL, nodo_puntero = NULL;
        Tarista axon = NULL, axon_puntero = NULL;

};


void Grafo::insert_neuron(std::string name){

    Tnodo aux, nuevo = new struct nodo;
    nuevo->name = name;
    nuevo->neu_sig = NULL;
    nuevo->axo = NULL;
    

    if(this->neuron == NULL){
        this->neuron = nuevo;
        std::cout<<"Primer nodo\n";
    }
    else{
        aux = this->neuron;
        while(aux->neu_sig != NULL){
            aux = aux->neu_sig;
        }
        aux->neu_sig = nuevo;
        std::cout<<"Nuevo Nodo\n";

    }

}

void Grafo::add_axon(Tnodo &nodo1, Tnodo &nodo2, Tarista &nuevo){

    Tarista a = NULL;

    if(nodo1->axo == NULL){
        nodo1->axo = nuevo;
        nuevo->destino = nodo2;
        std::cout<< "Primera arista agregada\n";

    }
    else{
        a = nodo1->axo;
        while(a->sig != NULL){
            a = a->sig;
        }
        nuevo->destino = nodo2;
        a->sig = nuevo;
        std::cout<<"Nueva arista\n";
        
    }
}

void Grafo::insert_axon(float km, float time, float price, std::string nodoIni, std::string nodoFin){


    Tarista nuevoA = new struct arista;

    if(this->neuron == NULL){
        std::cout<<"Grafo vacio\n";
        return;
    }

    Tnodo aux = this->neuron, aux2 = this->neuron;
    nuevoA->km = km;
    nuevoA->time = time;
    nuevoA->price = price;
    nuevoA->sig = NULL;
    
    while(aux2 != NULL){

        if(aux2->name == nodoFin){
            break;
        }

        aux2 = aux2->neu_sig;
    }

    while(aux != NULL){

        if(aux->name == nodoIni)
        {
            add_axon(aux, aux2, nuevoA);
            return;
        }

        aux = aux->neu_sig;
    }


}


void Grafo::see_red(){
    Tnodo ndo;
    Tarista ari;

    std::cout<<"Grafo: Nodos y sus aristas\n";
    ndo = this->neuron;

    while(ndo != NULL){
        std::cout<<ndo->name<<":\n";

        if(ndo->axo != NULL){
            ari = ndo->axo;
            
            while(ari != NULL){
                std::cout<<" --> "<<ari->destino->name<<"\n";
                ari = ari->sig;
            }
        }

        ndo = ndo->neu_sig;
        std::cout<<"\n";
    }

}

#endif