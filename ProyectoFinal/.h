#ifndef ANALISIS_CLINICO_H
#define ANALISIS_CLINICO_H

#include <iostream>
#include <string>
#include <vector>
#include <type_traits>

using namespace std;

// Clase base para análisis clínicos
class AnalisisClinico {
public:
    string fecha;    // Fecha del análisis
    string paciente; // Nombre del paciente

    AnalisisClinico(string f, string p);
    virtual ~AnalisisClinico(); // Destructor virtual
};

// Clase derivada para química sanguínea
class QuimicaSanguinea : public AnalisisClinico {
public:
    vector<float> glucosa;
    vector<float> colesterol;
    vector<float> acidoUrico;
    vector<float> urea;
    vector<float> trigliceridos;
    vector<float> creatinina;

    QuimicaSanguinea(string f, string p, vector<float> g, vector<float> c, vector<float> au,
                     vector<float> u, vector<float> t, vector<float> cr);
};

// Clase derivada para análisis de orina (ego)
class Ego : public AnalisisClinico {
public:
    vector<string> color;
    vector<float> densidad;
    vector<string> aspecto;
    vector<float> pH;
    vector<float> proteinas;
    vector<float> glucosa;
    vector<float> hemoglobina;
    vector<float> cCetonicos;
    vector<float> celulas;
    vector<float> cristales;
    vector<float> globulosRojos;
    vector<float> globulosBlancos;

    Ego(string f, string p, vector<string> c, vector<float> d, vector<string> a, vector<float> ph,
        vector<float> pr, vector<float> g, vector<float> h, vector<float> cc, vector<float> cel,
        vector<float> cr, vector<float> gr, vector<float> gb);
};

// Clase para los nodos de la lista enlazada
template <typename T>
class Node {
public:
    T data;      // Almacena el análisis clínico
    Node* next;  // Puntero al siguiente nodo

    Node(T value);
};

// Clase para la lista simplemente enlazada
template <typename T>
class LinkedList {
private:
    Node<T>* head; // Puntero al inicio de la lista

public:
    LinkedList();
    void insert(T value);
    void display() const;
    ~LinkedList();
};

#include "analisis_clinico.cpp"

#endif // ANALISIS_CLINICO_H
