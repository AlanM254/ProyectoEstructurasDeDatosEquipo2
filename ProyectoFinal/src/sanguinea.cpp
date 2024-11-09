#include "../include/sanguinea.hpp"

#include <stdexcept>
#include <sstream>
using namespace std;

const map<Sanguinea::Tipo, vector<string>> Sanguinea::elementosxTipo = {
    {BASICA, {"Glucosa", "Colesterol", "Triglicéridos", "Creatinina", "Bilirrubina", "Proteínas"}},

    {MEDIA, {"Glucosa", "Colesterol", "Triglicéridos", "Creatinina", "Bilirrubina", "Proteínas",
              "Ácido úrico", "Calcio", "Fósforo", "Magnesio", "Sodio", "Potasio", "Cloro", "Albumina"}},

    {FULL, {"Glucosa", "Colesterol", "Triglicéridos", "Creatinina", "Bilirrubina", "Proteínas",
             "Ácido úrico", "Calcio", "Fósforo", "Magnesio", "Sodio", "Potasio", "Cloro", "Albumina",
             "Hemoglobina", "Hematocrito", "Recuento de glóbulos rojos", "Recuento de glóbulos blancos",
             "Recuento de plaquetas", "Vitamina D", "Tiroxina", "T3", "T4", "Insulina", "Cortisol"}}
};

Sanguinea::Sanguinea() : tipo(BASICA) {
    inicializar();}

Sanguinea::Sanguinea(Tipo tipo) : tipo(tipo) {
    inicializar();}

Sanguinea::Sanguinea(const Sanguinea &s) : tipo(s.tipo), elementos(s.elementos) {}

void Sanguinea::inicializar() {
    auto it = elementosxTipo.find(tipo);
    if (it != elementosxTipo.end()) {
        elementos = it->second;
    } else {
        throw invalid_argument("Tipo de química sanguínea inválido.");
    }
}

Sanguinea::Tipo Sanguinea::getTipo() const {
    return tipo;
}

vector<string> Sanguinea::getElementos() const {
    return elementos;
}

void Sanguinea::mostrar() const {
    cout << "Tipo: " << toString() << endl;
    cout << "Elementos: " << endl;
    for (const auto &elemento : elementos) {
        cout << "- " << elemento << endl;
    }
}

string Sanguinea::toString() const {
    switch (tipo) {
        case BASICA: return "Básica";
        case MEDIA: return "Media";
        case FULL: return "Full";
        default: return "Desconocido"; // Por si hay un tipo no definido
    }
}

Sanguinea& Sanguinea::operator=(const Sanguinea &s) {
    if (this != &s) {
        tipo = s.tipo;
        elementos = s.elementos;
    }
    return *this;
}

bool Sanguinea::operator==(const Sanguinea &s) const { return tipo == s.tipo && elementos == s.elementos;}

bool Sanguinea::operator!=(const Sanguinea &s) const {return !(*this == s);}

bool Sanguinea::operator<(const Sanguinea &s) const {return tipo < s.tipo; }

bool Sanguinea::operator<=(const Sanguinea &s) const {return *this < s || *this == s;}

bool Sanguinea::operator>(const Sanguinea &s) const {return !(*this <= s);}

bool Sanguinea::operator>=(const Sanguinea &s) const {return !(*this < s);}

istream &operator>>(istream &is, Sanguinea &s) {
    string tipoStr;
    getline(is, tipoStr);
    if (tipoStr == "Básica") {
        s.tipo = Sanguinea::BASICA;
    } else if (tipoStr == "Media") {
        s.tipo = Sanguinea::MEDIA;
    } else if (tipoStr == "Full") {
        s.tipo = Sanguinea::FULL;
    } else {
        throw invalid_argument("Tipo de química sanguínea inválido.");
    }
    s.inicializar(); // Inicializa los elementos después de establecer el tipo
    return is;
}

ostream &operator<<(ostream &os, const Sanguinea &s) {
    os << "Tipo: " << s.toString() << "\nElementos:\n";
    for (const auto &elemento : s.elementos) {
        os << "- " << elemento << "\n";
    }
    return os;
}
