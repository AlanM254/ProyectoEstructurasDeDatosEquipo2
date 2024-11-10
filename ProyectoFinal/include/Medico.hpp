#ifndef MEDICO_HPP_INCLUDED
#define MEDICO_HPP_INCLUDED

#include <iostream>

using namespace std;

class Medico {
private:
    string nombre;
    string especialidad;
    string numeroLicencia;

public:
    // Setters
    void setNombre(const string& nombre) {
        this->nombre = nombre;
    }

    void setEspecialidad(const string& especialidad) {
        this->especialidad = especialidad;
    }

    void setNumeroLicencia(const string& numeroLicencia) {
        this->numeroLicencia = numeroLicencia;
    }

    // Getters
    string getNombre() const {
        return nombre;
    }

    string getEspecialidad() const {
        return especialidad;
    }

    string getNumeroLicencia() const {
        return numeroLicencia;
    }

    string toString() const {
        return "Nombre: " + nombre + "\nEspecialidad: " + especialidad + "\nNúmero de Licencia: " + numeroLicencia;
    }
};

#endif // MEDICO_HPP_INCLUDED
