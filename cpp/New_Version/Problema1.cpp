#include<iostream>
#include<conio.h>
#include<windows.h>
#include<string>
#include "Red.h"
#include "Datos.h"


using namespace std;


int main(void){
    
    Grafo red;

    Data datos;

    vector<string> prov = datos.get_Provincia();

    red.insert_neuron(prov[0]);
    red.insert_neuron(prov[1]);

    red.insert_axon(2414.0, 60*(2414.0/945), 1.56*60*(2414.0/945), prov[0], prov[1]);
    red.see_red();


    return 0;
}