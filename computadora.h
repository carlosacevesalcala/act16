#ifndef COMPUTADORA_H
#define COMPUTADORA_H

#include <iostream>
#include <iomanip>

using namespace std;

class Computadora{
private:
    string marca;
    string so;
    int ram;
    int hdd;
public:
    Computadora();
    
    void setmarca(const string &v);
    string getmarca();
    void setso(const string &v);
    string getso();
    void setram(int v);
    int getram();
    void sethdd(int v);
    int gethdd();

    friend ostream& operator<<(ostream &out, const Computadora &c)
    {
        out<<left;
        out<<setw(10)<<c.marca;
        out<<setw(20)<<c.so;
        out<<setw(10)<<c.ram;
        out<<setw(10)<<c.hdd;
        out<<endl;
        return out;
    }

    friend istream& operator>>(istream &in, Computadora &c)
    {
        //string temp;
        //int ram;
        //int hdd;

        cout<<"marca: ";
        getline(cin, c.marca);
        cout<<"sistema operativo: ";
        getline(cin, c.so);
        cout<<"ram: ";
        cin>>c.ram;
        cout<<"almacenamiento: ";
        cin>>c.hdd;
        return in;
    }

    
    bool operator==(const Computadora& c)
    {
        return marca == c.marca;
    }
    bool operator==(const Computadora& c) const
    {
        return marca == c.marca;
    }
    
    bool operator<(const Computadora& c)
    {
        return marca < c.marca;
    }
     bool operator<(const Computadora& c) const
    {
        return marca < c.marca;
    }
    
    };

#endif