#ifndef MUESTRA_H_INCLUDED
#define MUESTRA_H_INCLUDED

#include <iostream>
#include "SensibilidadAntibiotica.h"
#include "ListaEnlazada.hpp"

using namespace std;

class Muestra {
    string tipo;
    string resultado;
    string microorganismo_aislado;
    ListaEnlazada<PSA> sensibilidad_antibioticos;

public:
    // Setters
    void setTipo(const string& tipo) {
        this->tipo = tipo;
    }

    void setResultado(const string& resultado) {
        this->resultado = resultado;
    }

    void setMicroorganismoAislado(const string& microorganismo_aislado) {
        this->microorganismo_aislado = microorganismo_aislado;
    }

    void setSensibilidadAntibioticos(const PSA& psa) {
        this->sensibilidad_antibioticos.insertarAlFinal(psa);
    }

    // Getters
    string getTipo() const {
        return tipo;
    }

    string getResultado() const {
        return resultado;
    }

    string getMicroorganismoAislado() const {
        return microorganismo_aislado;
    }

    void getSensibilidadAntibioticos() const {
        return sensibilidad_antibioticos.mostrar();
    }

    /*void obtenerInformacion() const {
        cout<<"Tipo: " + tipo + "\nResultado: " + resultado + "\nMicroorganismo Aislado: " + microorganismo_aislado +
                "\nSensibilidad a Antibióticos: ";
        sensibilidad_antibioticos.mostrar();
    }*/
    string obtenerInformacion() const {
        return  "Tipo: " + tipo + "\nResultado: " + resultado + "\nMicroorganismo Aislado: " +
                microorganismo_aislado + "\nSensibilidad a Antibióticos: "; //+
                //sensibilidad_antibioticos.mostrar();
    }

};

#endif // MUESTRA_H_INCLUDED
