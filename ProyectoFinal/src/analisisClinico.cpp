#include "../include/analisisClinico.hpp"
#include <stdexcept>
using namespace std;

AnalisisClinico::AnalisisClinico() : folio(),name(), fecha(), paciente(), sanguinea() {}

AnalisisClinico::AnalisisClinico(const AnalisisClinico &a)
    : folio(a.folio), name(a.name), fecha(a.fecha), paciente(a.paciente), sanguinea(a.sanguinea) {}

string AnalisisClinico::toString() const {
    return "Folio:" + folio +"\n" +
           "Nombre: " + name.toString() + "\n" +
           "Fecha: " + fecha.toString() + "\n" +
           "Paciente: \n" + paciente.toString() + "\n";
}

AnalisisClinico& AnalisisClinico::operator=(const AnalisisClinico &a) {
    if (this != &a) {
        folio =a.folio;
        name = a.name;
        fecha = a.fecha;
        paciente = a.paciente;
        sanguinea = a.sanguinea;
    }
    return *this;
}

string AnalisisClinico::getFolio(){return folio;}
Name AnalisisClinico::getName() {return name;}
Fecha AnalisisClinico::getFecha() {return fecha;}
Paciente AnalisisClinico::getPaciente() {return paciente;}
Sanguinea AnalisisClinico::getDanguinea() {return sanguinea;}

void AnalisisClinico::setFolio(const string &f){folio = f;}
void AnalisisClinico::setName(const Name &n) {name = n;}
void AnalisisClinico::setFecha(const Fecha &f) {fecha = f;}
void AnalisisClinico::setPaciente(const Paciente &p) {paciente = p;}
void AnalisisClinico::setSanguinea(const Sanguinea &s) {sanguinea = s;}

bool AnalisisClinico::operator==(const AnalisisClinico &a) const {return name == a.name && fecha == a.fecha && paciente == a.paciente && sanguinea == a.sanguinea;}
bool AnalisisClinico::operator!=(const AnalisisClinico &a) const {return !(*this == a);}
bool AnalisisClinico::operator<(const AnalisisClinico &a) const {return fecha < a.fecha; }
bool AnalisisClinico::operator<=(const AnalisisClinico &a) const {return *this < a || *this == a;}
bool AnalisisClinico::operator>(const AnalisisClinico &a) const {return !(*this <= a);}
bool AnalisisClinico::operator>=(const AnalisisClinico &a) const {return !(*this < a);}

istream &operator>>(istream &is, AnalisisClinico &a) {
    is >> a.name;
    is >> a.fecha;
    is >> a.paciente;
    is >> a.sanguinea;
    return is;
}

ostream &operator<<(ostream &os, const AnalisisClinico &a) {
    os << a.toString();
    return os;
}
