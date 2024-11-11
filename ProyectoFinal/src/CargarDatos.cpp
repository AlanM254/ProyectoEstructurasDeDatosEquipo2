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

    // Leer l�nea por l�nea
    while (std::getline(archivo, linea)) {
        std::istringstream iss(linea);

        // Evitar l�neas vac�as y l�neas con delimitadores como "---"
        if (linea.empty() || linea.find("---") != std::string::npos) {
            continue;
        }

        // Leer clave y valor separados por ':'
        if (std::getline(iss, clave, ':') && std::getline(iss, valor)) {
            valor = valor.substr(1); // Eliminar espacio despu�s de ":"

            // Mostrar clave y valor para depuraci�n
            std::cout << "Leyendo: " << clave << " -> " << valor << std::endl;

            // Asignar los valores correspondientes a los atributos
            if (clave == "Folio del An�lisis") {
                hemocultivo->setFolio(valor);
            } else if (clave == "Fecha del An�lisis") {
                hemocultivo->setFechaAnalisis(valor);
            } else if (clave == "Interpretaci�n") {
                hemocultivo->setInterpretacion(valor);
            } else if (clave == "Comentarios Adicionales") {
                hemocultivo->setComentariosAdicionales(valor);
            } else if (clave == "Nombre del Laboratorio") {
                hemocultivo->setNombreLaboratorio(valor);
            } else if (clave == "Fecha de Firma del Informe") {
                hemocultivo->setFechaAnalisis(valor);
            } else if (clave == "Nombre del M�dico") {
                hemocultivo->getMedico().setNombre(valor); // Suponiendo que tienes un setter para el m�dico
            } else if (clave == "Especialidad del M�dico") {
                hemocultivo->getMedico().setEspecialidad(valor); // Similar para la especialidad
            }
            // Agregar m�s asignaciones seg�n sea necesario, por ejemplo:
            // Si hay una secci�n con "Muestra Aerobia" o "Muestra Anaerobia", deber�s decidir c�mo procesarla
        }
    }

    archivo.close();
    return hemocultivo;
}
