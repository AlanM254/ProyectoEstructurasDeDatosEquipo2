#ifndef CARGARDATOS_HPP
#define CARGARDATOS_HPP

#include <fstream>
#include <sstream>
#include <string>
#include "Hemocultivo.hpp"

// Declaración de la función de carga
Hemocultivo* cargarHemocultivoDesdeArchivo(const std::string& nombreArchivo);

#endif // CARGARDATOS_HPP
