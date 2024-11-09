#ifndef LABORATORIO_H_INCLUDED
#define LABORATORIO_H_INCLUDED

#include <iostream>
using namespace std;

class Laboratorio{
    string nombre;
    string direccion;
    string telefono;
public:

    // Getters
    std::string getNombre() const {
        return nombre;
    }

    std::string getDireccion() const {
        return direccion;
    }

    std::string getTelefono() const {
        return telefono;
    }

    // Setters
    void setNombre(const std::string& nuevoNombre) {
        nombre = nuevoNombre;
    }

    void setDireccion(const std::string& nuevaDireccion) {
        direccion = nuevaDireccion;
    }

    void setTelefono(const std::string& nuevoTelefono) {
        telefono = nuevoTelefono;
    }

};
#endif // LABORATORIO_H_INCLUDED
