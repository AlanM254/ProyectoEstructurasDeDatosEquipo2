#ifndef CARGARDATOS_HPP
#define CARGARDATOS_HPP

#include <fstream>
#include <sstream>
#include <string>
#include "Hemocultivo.hpp"

// Declaraci�n de la funci�n de carga
Hemocultivo* cargarHemocultivoDesdeArchivo(const std::string& nombreArchivo);

#endif // CARGARDATOS_HPP
