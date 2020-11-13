#include "computadora.h"

Computadora::Computadora(){

}

void Computadora::setmarca(const string &v){
    
    marca=v;
}

string Computadora::getmarca(){
    
    return marca;
}

void Computadora::setso(const string &v){
    
    so=v;
}

string Computadora::getso(){
  
    return so;
}

void Computadora::setram(int v){
    
    ram=v;
}

int Computadora::getram(){
    
    return ram;
}

void Computadora::sethdd(int v){
    
    hdd=v;
}

int Computadora::gethdd(){

    return hdd;
}