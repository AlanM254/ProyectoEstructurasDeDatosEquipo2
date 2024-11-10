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
    // Setters
    void setMuestra(const Muestra& m) {
        muestra = m;
    }

    void setInterpretacion(const string& i) {
        interpretacion = i;
    }

    void setComentariosAdicionales(const string& ca) {
        comentariosAdicionales = ca;
    }

    void setLaboratorio(const Laboratorio& l) {
        laboratorio = l;
    }

    void setMedico(const Medico& m) {
        medico = m;
    }

    void setFechaDeFirma(const Fecha& f) {
        fechaDeFirma = f;
    }

    // Getters
    Muestra getMuestra() const {
        return muestra;
    }

    string getInterpretacion() const {
        return interpretacion;
    }

    string getComentariosAdicionales() const {
        return comentariosAdicionales;
    }

    Laboratorio getLaboratorio() const {
        return laboratorio;
    }

    Medico getMedico() const {
        return medico;
    }

    Fecha getFechaDeFirma() const {
        return fechaDeFirma;
    }

    // Implementación del método mostrarDatos
    void mostrarDatos() const override {
        cout << this->toString();
        cout << "Muestra: " << muestra.obtenerInformacion() << endl;
        cout << "Interpretación: " << interpretacion << endl;
        cout << "Comentarios Adicionales: " << comentariosAdicionales << endl;
        cout << "Laboratorio: " << laboratorio.toString() << endl;
        cout << "Médico: " << medico.toString() << endl;
        cout << "Fecha de Firma: " << fechaDeFirma.toString() << endl;
    }
};


#endif // HEMOCULTIVO_HPP_INCLUDED
