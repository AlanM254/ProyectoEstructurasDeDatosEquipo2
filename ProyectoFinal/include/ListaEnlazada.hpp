#ifndef LISTAENLAZADA_H_INCLUDED
#define LISTAENLAZADA_H_INCLUDED

#include <iostream>
#include <type_traits>

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

    /*// Función auxiliar para mostrar elementos
    // Caso 1: para punteros a clases con el método mostrarDatos
    template<typename U = T>
    typename std::enable_if<std::is_member_function_pointer<
    decltype(&std::remove_pointer<U>::type::mostrarDatos)>::value>::type
    mostrarElemento(const U& elemento) const {
        elemento->mostrarDatos(); // Usa -> para punteros
    }

    // Caso 2: para objetos con el método mostrarDatos (no punteros)
    template<typename U = T>
    typename enable_if<std::is_member_function_pointer<decltype(&U::mostrarDatos)>::value>::type
    mostrarElemento(const U& elemento) const {
        elemento.mostrarDatos();
    }

    // Caso 3: para tipos sin el método mostrarDatos
    template<typename U = T>
    typename enable_if<!std::is_member_function_pointer<decltype(&U::mostrarDatos)>::value>::type
    mostrarElemento(const U& elemento) const {
        cout << elemento << endl;
    }*/
    // Caso 1: punteros a clases con el método mostrarDatos que retorna un string o imprime
    template<typename U = T>
    typename std::enable_if<
        std::is_pointer<U>::value &&
        std::is_member_function_pointer<decltype(&std::remove_pointer<U>::type::mostrarDatos)>::value
    >::type
    mostrarElemento(const U& elemento) const {
        elemento->mostrarDatos();
    }

    // Caso 2: objetos con el método mostrarDatos
    template<typename U = T>
    typename std::enable_if<
        !std::is_pointer<U>::value &&
        std::is_member_function_pointer<decltype(&U::mostrarDatos)>::value
    >::type
    mostrarElemento(const U& elemento) const {
        elemento.mostrarDatos();
    }

    // Caso 3: tipos sin el método mostrarDatos
    template<typename U = T>
    typename std::enable_if<
        !std::is_member_function_pointer<decltype(&U::mostrarDatos)>::value
    >::type
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

    // Método para agregar un nodo al inicio
    void insertarAlInicio(T dato) {
        Nodo<T>* nuevoNodo = new Nodo<T>(dato);
        nuevoNodo->siguiente = cabeza;
        cabeza = nuevoNodo;
    }

    // Método para agregar un nodo al final
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

    // Método para eliminar un nodo con un valor específico
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

     // Método para mostrar todos los elementos
    void mostrar() const {
        Nodo<T>* actual = cabeza;
        while (actual != nullptr) {
            mostrarElemento(actual->dato); // Llama a la función mostrarElemento adecuada
            actual = actual->siguiente;
        }
        std::cout << "nullptr" << std::endl;
    }

};

#endif // LISTAENLAZADA_H_INCLUDED
