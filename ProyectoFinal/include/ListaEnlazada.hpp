#ifndef LISTAENLAZADA_H_INCLUDED
#define LISTAENLAZADA_H_INCLUDED

#include <iostream>

using namespace std;

template <typename T>
class Nodo {
public:
    T dato;
    Nodo* siguiente;

    Nodo(T dato) : dato(dato), siguiente(nullptr) {}
};

template <typename T>
class ListaEnlazada {
private:
    Nodo<T>* cabeza;

    // Funci�n auxiliar para mostrar elementos
    // Caso 1: para punteros a clases con el m�todo mostrarDatos
    template<typename U = T>
    typename std::enable_if<std::is_member_function_pointer<decltype(&std::remove_pointer<U>::type::mostrarDatos)>::value>::type
    mostrarElemento(const U& elemento) const {
        elemento->mostrarDatos(); // Usa -> para punteros
    }

    // Caso 2: para objetos con el m�todo mostrarDatos (no punteros)
    template<typename U = T>
    typename enable_if<std::is_member_function_pointer<decltype(&U::mostrarDatos)>::value>::type
    mostrarElemento(const U& elemento) const {
        elemento.mostrarDatos();
    }

    // Caso 3: para tipos sin el m�todo mostrarDatos
    template<typename U = T>
    typename enable_if<!std::is_member_function_pointer<decltype(&U::mostrarDatos)>::value>::type
    mostrarElemento(const U& elemento) const {
        cout << elemento << endl;
    }

public:
    ListaEnlazada() : cabeza(nullptr) {}

    // Destructor para liberar la memoria
    ~ListaEnlazada() {
        Nodo<T>* actual = cabeza;
        while (actual != nullptr) {
            Nodo<T>* siguiente = actual->siguiente;
            delete actual;
            actual = siguiente;
        }
    }

    // M�todo para agregar un nodo al inicio
    void insertarAlInicio(T dato) {
        Nodo<T>* nuevoNodo = new Nodo<T>(dato);
        nuevoNodo->siguiente = cabeza;
        cabeza = nuevoNodo;
    }

    // M�todo para agregar un nodo al final
    void insertarAlFinal(T dato) {
        Nodo<T>* nuevoNodo = new Nodo<T>(dato);
        if (cabeza == nullptr) {
            cabeza = nuevoNodo;
        } else {
            Nodo<T>* temp = cabeza;
            while (temp->siguiente != nullptr) {
                temp = temp->siguiente;
            }
            temp->siguiente = nuevoNodo;
        }
    }

    // M�todo para eliminar un nodo con un valor espec�fico
    void eliminarNodo(T valor) {
        if (cabeza == nullptr) return;

        if (cabeza->dato == valor) {
            Nodo<T>* temp = cabeza;
            cabeza = cabeza->siguiente;
            delete temp;
            return;
        }

        Nodo<T>* actual = cabeza;
        while (actual->siguiente != nullptr && actual->siguiente->dato != valor) {
            actual = actual->siguiente;
        }

        if (actual->siguiente == nullptr) return;

        Nodo<T>* temp = actual->siguiente;
        actual->siguiente = actual->siguiente->siguiente;
        delete temp;
    }

     // M�todo para mostrar todos los elementos
    void mostrar() const {
        Nodo<T>* actual = cabeza;
        while (actual != nullptr) {
            mostrarElemento(actual->dato); // Llama a la funci�n mostrarElemento adecuada
            actual = actual->siguiente;
        }
        std::cout << "nullptr" << std::endl;
    }
    /*
    // M�todo para mostrar los elementos de la lista
    void mostrar() const {
        Nodo<T>* actual = cabeza;
        while (actual != nullptr) {
            std::cout << actual->dato->mostrarDatos() << " -> ";
            actual = actual->siguiente;
        }
        std::cout << "nullptr" << std::endl;
    }
    */
};

#endif // LISTAENLAZADA_H_INCLUDED
