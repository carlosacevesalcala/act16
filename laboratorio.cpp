#include "laboratorio.h"
#include <fstream>
#include <algorithm>

Laboratorio::Laboratorio(){
    
}

void Laboratorio::agregaralfinal(const Computadora &c){
    computadoras.push_back(c);
}

void Laboratorio::mostrar(){
    cout<<left;
    cout<<setw(10)<<"marca";
    cout<<setw(20)<<"sistema operativo";
    cout<<setw(10)<<"ram";
    cout<<setw(10)<<"almacenamiento";
    cout<<endl;
    for(size_t i = 0; i<computadoras.size(); i++){
        Computadora &c = computadoras[i];
        cout<<c;

    }
}

void Laboratorio::respaldar_tabla()
{
    ofstream archivo("computadoras_tabla.txt");
    if (archivo.is_open()){
        archivo<<left;
        archivo<<setw(10)<<"marca";
        archivo<<setw(20)<<"sistema operativo";
        archivo<<setw(10)<<"ram";
        archivo<<setw(10)<<"almacenamiento";
        archivo<<endl;
        for(size_t i = 0; i<computadoras.size(); i++){
            Computadora &c = computadoras[i];
            archivo<<c;
        }
    }
    archivo.close();
}

void Laboratorio::respaldar()
{
    ofstream archivo("computadoras.txt");
    if (archivo.is_open()){
        for(size_t i = 0; i<computadoras.size(); i++){
            Computadora &c = computadoras[i];
            archivo<<c.getmarca()<<endl;
            archivo<<c.getso()<<endl;
            archivo<<c.getram()<<endl;
            archivo<<c.gethdd()<<endl;
        }
    }
    archivo.close();
}

void Laboratorio::recuperar()
{
    ifstream archivo("computadoras.txt");
    if (archivo.is_open()){
        string temp;
        int ram;
        int hdd;
        Computadora c;

        while(true)
        {
            getline(archivo, temp);
            if(archivo.eof()){
                break;
            }
            c.setmarca(temp);
            getline(archivo, temp);
            c.setso(temp);
            getline(archivo, temp);
            ram = stoi(temp);
            c.setram(ram);
            getline(archivo, temp);
            hdd = stoi(temp);
            c.sethdd(hdd);

            agregaralfinal(c);
        }
    }
    archivo.close();
}

void Laboratorio::insertar(const Computadora &c, size_t pos){
    computadoras.insert(computadoras.begin()+pos, c);
}

size_t Laboratorio::size(){
    return computadoras.size();
}

void Laboratorio::inicializar(const Computadora &c, size_t n)
{
    computadoras = vector<Computadora>(n, c);
}

void Laboratorio::eliminar(size_t pos)
{
    computadoras.erase(computadoras.begin()+pos);
}

void Laboratorio::ordenar()
{
    sort(computadoras.begin(), computadoras.end());
}

Computadora* Laboratorio::buscar(const Computadora &c)
{
    auto it = find(computadoras.begin(), computadoras.end(), c);
    if (it == computadoras.end())
    {
        return nullptr;
    }
    else{
        return &(*it);
    }
}