#include "../include/CargarDatos.hpp"
#include <sstream>

Hemocultivo* cargarHemocultivoDesdeArchivo(const std::string& nombreArchivo) {
    std::ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        std::cerr << "No se pudo abrir el archivo: " << nombreArchivo << std::endl;
        return nullptr;
    }

    std::string linea;
    std::string clave, valor;
    Hemocultivo* hemocultivo = new Hemocultivo();

    // Leer línea por línea
    while (std::getline(archivo, linea)) {
        std::istringstream iss(linea);

        // Evitar líneas vacías y líneas con delimitadores como "---"
        if (linea.empty() || linea.find("---") != std::string::npos) {
            continue;
        }

        // Leer clave y valor separados por ':'
        if (std::getline(iss, clave, ':') && std::getline(iss, valor)) {
            valor = valor.substr(1); // Eliminar espacio después de ":"

            // Mostrar clave y valor para depuración
            std::cout << "Leyendo: " << clave << " -> " << valor << std::endl;

            // Asignar los valores correspondientes a los atributos
            if (clave == "Folio del Análisis") {
                hemocultivo->setFolio(valor);
            } else if (clave == "Fecha del Análisis") {
                hemocultivo->setFechaAnalisis(valor);
            } else if (clave == "Interpretación") {
                hemocultivo->setInterpretacion(valor);
            } else if (clave == "Comentarios Adicionales") {
                hemocultivo->setComentariosAdicionales(valor);
            } else if (clave == "Nombre del Laboratorio") {
                hemocultivo->setNombreLaboratorio(valor);
            } else if (clave == "Fecha de Firma del Informe") {
                hemocultivo->setFechaAnalisis(valor);
            } else if (clave == "Nombre del Médico") {
                hemocultivo->getMedico().setNombre(valor); // Suponiendo que tienes un setter para el médico
            } else if (clave == "Especialidad del Médico") {
                hemocultivo->getMedico().setEspecialidad(valor); // Similar para la especialidad
            }
            // Agregar más asignaciones según sea necesario, por ejemplo:
            // Si hay una sección con "Muestra Aerobia" o "Muestra Anaerobia", deberás decidir cómo procesarla
        }
    }

    archivo.close();
    return hemocultivo;
}
