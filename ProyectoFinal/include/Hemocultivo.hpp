#ifndef HEMOCULTIVO_HPP_INCLUDED
#define HEMOCULTIVO_HPP_INCLUDED

#include <iostream>
#include "analisisClinico.hpp"
#include "Laboratorio.h"
#include "Muestra.h"
#include "Medico.hpp"


class Hemocultivo:public AnalisisClinico{
    Muestra muestra;
    string interpretacion;
    string comentariosAdicionales;
    Laboratorio laboratorio;
    Medico medico;
    Fecha fechaDeFirma;
public:
    Hemocultivo(){
        interpretacion="1";
    };
    Hemocultivo(string example){
        interpretacion=example;
    }
    void mostrarDatos()const override{
        cout<<"Hemocultivo"<<interpretacion<<endl;
    }

};


#endif // HEMOCULTIVO_HPP_INCLUDED
