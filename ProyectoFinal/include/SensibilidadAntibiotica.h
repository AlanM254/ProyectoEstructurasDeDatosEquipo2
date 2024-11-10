#ifndef SENSIBILIDADANTIBIOTICA_INCLUDED
#define SENSIBILIDADANTIBIOTICA_INCLUDED

#include <iostream>

using namespace std;

class PSA{
    string antibiotico;
    string sensibilidad;

public:
    PSA(){};
    PSA(const string& antibiotico,const string& sensibilidad){
        this->antibiotico=antibiotico;
        this->sensibilidad=sensibilidad;
    }
    // Setters
    void setAntibiotico(const string& antibiotico) {
        this->antibiotico = antibiotico;
    }

    void setSensibilidad(const string& sensibilidad) {
        this->sensibilidad = sensibilidad;
    }

    // Getters
    string getAntibiotico() const {
        return antibiotico;
    }

    string getSensibilidad() const {
        return sensibilidad;
    }

    // Metodo que retorna la informacion del objeto
    string mostrarDatos() const {
        return antibiotico + " : " + sensibilidad + "\n";
    }/*
    void mostrarDatos()const{
        cout<<antibiotico<<" : "<<sensibilidad <<endl;
    }*/
};

#endif // SENSIBILIDADANTIBIOTICA_INCLUDED
