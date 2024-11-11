#include "../include/Hemocultivo.hpp"

Hemocultivo::Hemocultivo() {
    // Aquí puedes inicializar los valores de los atributos si es necesario
}

Hemocultivo::Hemocultivo(std::string example) {
    // Puedes inicializar los atributos con el parámetro si lo deseas
}

void Hemocultivo::mostrarDatos() const {
    std::cout << "Hemocultivo - Interpretación: " << interpretacion << std::endl;
    std::cout << "Folio: " << folio << std::endl;
    std::cout << "Nombre paciente: " << nombrePaciente << std::endl;
}

void Hemocultivo::setFolio(const std::string& folio) {
    this->folio = folio;  // Asignación correcta
}

std::string Hemocultivo::getFolio() const {
    return folio;
}

void Hemocultivo::setFechaAnalisis(const std::string& fecha) {
    this->fechaAnalisis = fecha;
}

std::string Hemocultivo::getFechaAnalisis() const {
    return fechaAnalisis;
}

void Hemocultivo::setNombrePaciente(const std::string& nombre) {
    this->nombrePaciente = nombre;
}

std::string Hemocultivo::getNombrePaciente() const {
    return nombrePaciente;
}

void Hemocultivo::setInterpretacion(const std::string& valor) {
    interpretacion = valor;
}

void Hemocultivo::setComentariosAdicionales(const std::string& valor) {
    comentariosAdicionales = valor;
}

void Hemocultivo::setNombreLaboratorio(const std::string& valor) {
    laboratorio.setNombre(valor);  // Asumiendo que 'Laboratorio' tiene un setter
}

