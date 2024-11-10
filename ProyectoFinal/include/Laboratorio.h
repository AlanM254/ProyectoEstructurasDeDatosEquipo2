#ifndef LABORATORIO_H_INCLUDED
#define LABORATORIO_H_INCLUDED

#include <iostream>

using namespace std;

class Laboratorio {
private:
    string nombre;
    string direccion;
    string telefono;

public:
    // Setters
    void setNombre(const string& nombre) {
        this->nombre = nombre;
    }

    void setDireccion(const string& direccion) {
        this->direccion = direccion;
    }

    void setTelefono(const string& telefono) {
        this->telefono = telefono;
    }

    // Getters
    string getNombre() const {
        return nombre;
    }

    string getDireccion() const {
        return direccion;
    }

    string getTelefono() const {
        return telefono;
    }

    // Metodo que retorna la informacion del objeto
    string toString() const {
        return "Nombre: " + nombre + "\nDirección: " + direccion + "\nTeléfono: " + telefono;
    }
};

#endif // LABORATORIO_H_INCLUDED
