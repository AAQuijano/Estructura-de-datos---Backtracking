#ifndef Datos
#define Datos

#include<iostream>
#include<vector>
#include "Red.h"



class Data{
    public:
        std::vector<std::string> get_Provincia();

    private:
        std::string Provincia[8] = {"Panama","Herrera","Colon","Cocle","LosSantos","Chiriqui","Veraguas","BocasDelToro"};

};

std::vector<std::string> Data::get_Provincia(){
    std::vector<std::string> v(this->Provincia, 
                               this->Provincia + sizeof(this->Provincia)/sizeof(std::string));
    return v;
}

#endif