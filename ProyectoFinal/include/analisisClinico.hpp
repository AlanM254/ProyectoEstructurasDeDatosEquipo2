#ifndef __ANALISISCLINICO_H__
#define __ANALISISCLINICO_H__

#include<iostream>
#include<string>

#include "name.hpp"
#include "fecha.hpp"
#include "paciente.hpp"
#include "sanguinea.hpp"

class AnalisisClinico{
    //folio, Medico
    protected:
    Name name;
    Fecha fecha;
    Paciente paciente;
    Sanguinea sanguinea;


    public:
    virtual void mostrarDatos() const = 0; // Método virtual puro
    virtual ~AnalisisClinico() = default; // Destructor virtual

    AnalisisClinico();
    AnalisisClinico(const AnalisisClinico&);

    std::string toString()const;
    AnalisisClinico& operator=(const AnalisisClinico&);

    Name getName();
    Fecha getFecha();
    Paciente getPaciente();
    Sanguinea getDanguinea();

    void setName(const Name&);
    void setFecha(const Fecha&);
    void setPaciente(const Paciente&);
    void setSanguinea(const Sanguinea&);

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
