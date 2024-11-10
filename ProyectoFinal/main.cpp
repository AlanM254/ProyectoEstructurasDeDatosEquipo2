
#include <iostream>
#include "include/ListaEnlazada.hpp"
#include "include/analisisClinico.hpp"
#include "include/Hemocultivo.hpp"

using namespace std;

int main(){
    /*ListaEnlazada<AnalisisClinico*> ac;
    ac.insertarAlInicio(new Hemocultivo());

    cout << "Hello world!" << endl;
    ac.mostrar();
    return 0;*/

    // Crear instancias de las clases necesarias
    Hemocultivo* hemocultivo = new Hemocultivo();

    /*/ Crear e inicializar Muestra
    Muestra muestra;
    muestra.setTipo("Sangre");
    muestra.setResultado("Positivo");
    muestra.setMicroorganismoAislado("Escherichia coli");

    // Crear y llenar la lista de sensibilidad a antibióticos
    PSA psa1, psa2;
    psa1.setAntibiotico("Amoxicilina");
    psa1.setSensibilidad("Sensible");
    psa2.setAntibiotico("Ciprofloxacina");
    psa2.setSensibilidad("Resistente");

    muestra.setSensibilidadAntibioticos(psa1);
    muestra.setSensibilidadAntibioticos(psa2);
    // Establecer los valores para Hemocultivo
    hemocultivo->setMuestra(muestra);
    hemocultivo->setInterpretacion("Infección bacteriana confirmada");
    hemocultivo->setComentariosAdicionales("Se recomienda tratamiento con antibióticos.");

    // Crear objetos de laboratorio y médico
    Laboratorio laboratorio;
    laboratorio.setNombre("Laboratorio Central");
    laboratorio.setDireccion("Av. Principal 123");

    Medico medico;
    medico.setNombre("Dr. Juan Pérez");
    medico.setEspecialidad("Microbiología");

    // Establecer el laboratorio y el médico en el Hemocultivo
    hemocultivo->setLaboratorio(laboratorio);
    hemocultivo->setMedico(medico);

    // Establecer la fecha de firma
    Fecha fecha;
    fecha.setDay(12);
    fecha.setMonth(11);
    fecha.setYear(2024);
    hemocultivo->setFechaDeFirma(fecha);

    */
      // Crear el objeto Paciente
    Paciente paciente;
    paciente.setNss("2024-HEMO-001234");
    paciente.setCode("123456");
    Name nombrePaciente("Pérez", "Juan", "Masculino");
    paciente.setName(nombrePaciente);

    // Crear las muestras de hemocultivo
    Muestra muestraAerobia;
    muestraAerobia.setTipo("Aerobia");
    muestraAerobia.setResultado("Positivo");
    muestraAerobia.setMicroorganismoAislado("Staphylococcus aureus");

    // Crear objetos PSA para la sensibilidad a antibióticos
    PSA penicilina("Penicilina", "Resistente");
    PSA vancomicina("Vancomicina", "Sensible");
    PSA ceftriaxona("Ceftriaxona", "Sensible");

    // Agregar los resultados de sensibilidad
    muestraAerobia.setSensibilidadAntibioticos(penicilina);
    muestraAerobia.setSensibilidadAntibioticos(vancomicina);
    muestraAerobia.setSensibilidadAntibioticos(ceftriaxona);

    // Crear la muestra anaerobia
    Muestra muestraAnaerobia;
    muestraAnaerobia.setTipo("Anaerobia");
    muestraAnaerobia.setResultado("Negativo");
    muestraAnaerobia.setMicroorganismoAislado("No se aislaron microorganismos");

    // Crear el laboratorio
    Laboratorio laboratorio;
    laboratorio.setNombre("Laboratorio Clínico XYZ");
    laboratorio.setDireccion("Calle Salud No. 123, Ciudad");
    laboratorio.setTelefono("555-123-4567");

    // Crear el médico
    Medico medico;
    medico.setNombre("Dra. Ana López");
    medico.setEspecialidad("Microbiología Clínica");
    medico.setNumeroLicencia("789012");

    // Crear la fecha de firma
    Fecha fechaFirma;
    fechaFirma.setDay(1);
    fechaFirma.setMonth(11);
    fechaFirma.setYear(2024);

    // Crear la fecha de toma de muestra
    Fecha fechaTomaMuestra;
    fechaTomaMuestra.setDay(30);
    fechaTomaMuestra.setMonth(10);
    fechaTomaMuestra.setYear(2024);

    // Crear el objeto Hemocultivo
    hemocultivo->setFolio("2024-HEMO-001234");
    hemocultivo->setPaciente(paciente);
    hemocultivo->setMuestra(muestraAerobia);  // Asumiendo que es solo una muestra (aerobia)
    hemocultivo->setInterpretacion("La presencia de Staphylococcus aureus en la muestra aerobia indica una posible bacteriemia. Se recomienda iniciar tratamiento con vancomicina y realizar un seguimiento clínico del paciente.");
    hemocultivo->setComentariosAdicionales("Se sugiere repetir el hemocultivo en 48 horas para confirmar la erradicación del microorganismo. Considerar la evaluación de posibles focos de infección secundaria.");
    hemocultivo->setLaboratorio(laboratorio);
    hemocultivo->setMedico(medico);
    hemocultivo->setFechaDeFirma(fechaFirma);

    // Crear la lista de análisis clínicos y agregar el Hemocultivo
    ListaEnlazada<AnalisisClinico*> ac;
    ac.insertarAlInicio(hemocultivo);

    // Mostrar todos los elementos de la lista
    cout << "Hello world!" << endl;
    ac.mostrar();

    // Limpiar memoria
    delete hemocultivo;

    return 0;

}
