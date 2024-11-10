#ifndef __ANALISISCLINICO_H__
#define __ANALISISCLINICO_H__

#include<iostream>
#include<string>

#include "name.hpp"
#include "fecha.hpp"
#include "paciente.hpp"
#include "sanguinea.hpp"

using namespace std;

class AnalisisClinico{
    protected:
    std::string folio;
    Name name;
    Fecha fecha;
    Paciente paciente;
    Sanguinea sanguinea;


    public:

    AnalisisClinico();
    AnalisisClinico(const AnalisisClinico&);
    virtual ~AnalisisClinico() = default; // Destructor virtual

    std::string toString()const;
    AnalisisClinico& operator=(const AnalisisClinico&);

    std::string getFolio();
    Name getName();
    Fecha getFecha();
    Paciente getPaciente();
    Sanguinea getDanguinea();

    void setFolio(const string&);
    void setName(const Name&);
    void setFecha(const Fecha&);
    void setPaciente(const Paciente&);
    void setSanguinea(const Sanguinea&);
    virtual void mostrarDatos() const = 0; // Método virtual puro

    bool operator==(const AnalisisClinico&) const;
    bool operator!=(const AnalisisClinico&) const;
    bool operator<(const AnalisisClinico&) const;
    bool operator<=(const AnalisisClinico&) const;
    bool operator>(const AnalisisClinico&) const;
    bool operator>=(const AnalisisClinico&) const;

    friend std::ostream& operator<<(std::ostream&, const AnalisisClinico&);
    friend std::istream& operator>>(std::istream&, AnalisisClinico&);
};

#endif // __ANALISISCLINICO_H__
