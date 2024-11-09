#include "../include/paciente.hpp"

#include <stdexcept>
using namespace std;

Paciente::Paciente() : nss(""), code(""), name() {}
Paciente::Paciente(const Paciente &p) : nss(p.nss), code(p.code), name(p.name) {}

string Paciente::getNss() {return nss;}
string Paciente::getCode() {return code;}
Name Paciente::getName() {return name;}

void Paciente::setNss(const string &n) {nss = n;}
void Paciente::setCode(const string &c) {code = c;}

string Paciente::toString() const {
    return "NSS: " + nss + "\n" +
           "Código: " + code + "\n" +
           "Nombre: " + name.toString();
}

Paciente& Paciente::operator=(const Paciente &p) {
    if (this != &p) {
        nss = p.nss;
        code = p.code;
        name = p.name;
    }   return *this;}

bool Paciente::operator==(const Paciente &p) const {return nss == p.nss && code == p.code && name == p.name;}
bool Paciente::operator!=(const Paciente &p) const {return !(*this == p);}
bool Paciente::operator<(const Paciente &p) const {return nss < p.nss; }
bool Paciente::operator<=(const Paciente &p) const {return *this < p || *this == p;}
bool Paciente::operator>(const Paciente &p) const {return !(*this <= p);}
bool Paciente::operator>=(const Paciente &p) const {return !(*this < p);}

istream &operator>>(istream &is, Paciente &p) {
    is >> p.nss;
    is >> p.code;
    is >> p.name;
    return is;
}

ostream &operator<<(ostream &os, const Paciente &p) {
    os << p.toString();
    return os;
}
