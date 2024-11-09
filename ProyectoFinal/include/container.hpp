#ifndef __CONTAINER_H__
#define __CONTAINER_H__

#include "analisisClinico.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <memory>
#include <functional>
#include <vector>
#include <algorithm>

class Nodo {
public:
    AnalisisClinico data;
    std::shared_ptr<Nodo> next;

    Nodo(const AnalisisClinico& a) : data(a), next(nullptr) {}
};

class Container {
private:
    std::shared_ptr<Nodo> head;
    int count; // contador de nodos

public:
    Container() : head(nullptr), count(0) {}
    ~Container() { clear();}

    void add(const AnalisisClinico& a);
    void del(const AnalisisClinico& a);
    void sort(const std::function<bool(const AnalisisClinico&, const AnalisisClinico&)>& comp);
    void show() const;
    void readFromDisk(const std::string& filename);
    void writeToDisk(const std::string& filename);
    bool isThere(const AnalisisClinico& a) const; // Ver si existe en disco
    void clear(); 
    int size() const { return count; }

    Container& operator=(const Container& other);
    Container operator+(const Container& other) const;
    Container& operator+=(const Container& other);
    Container& operator+=(const AnalisisClinico& a);

    friend std::istream& operator>>(std::istream& is, Container& c);
    friend std::ostream& operator<<(std::ostream& os, const Container& c);
};

using namespace std;

void Container::add(const AnalisisClinico& a){
    if(!isThere (a)){
        auto newNodo = make_shared<Nodo>(a);
        newNodo -> next = head;
        head = newNodo;
        count++;
    }
}

void Container::del(const AnalisisClinico& a){
    shared_ptr<Nodo> current = head;
    shared_ptr<Nodo> previous = nullptr;

    while (current &&!(current->data == a)){
        previous = current;
        current = current->next;
    }
    if (current){
        if (previous){
            previous->next =current->next;
        }else{
            head = current->next;
        }
        count--;
    }
}

void Container::sort(const function<bool(const AnalisisClinico&, const AnalisisClinico&)>& comp) {
    vector<AnalisisClinico> elements;
    shared_ptr<Nodo> current = head;

    // Paso 1: Llenar el vector con los elementos de la lista enlazada
    while (current) {
        elements.push_back(current->data);
        current = current->next;
    }

    // Paso 2: Ordenar el vector con el comparador proporcionado
    std::sort(elements.begin(), elements.end(), comp);

    // Paso 3: Volver a llenar la lista enlazada con los elementos ordenados
    current = head;
    for (const auto& el : elements) {
        current->data = el;
        current = current->next;
    }
}


void Container::show() const{
    shared_ptr<Nodo> current = head;
    while (current){
        cout<< current->data<<endl;
        current = current->next;
    }
}

void Container::readFromDisk(const string& filename){
    ifstream file(filename);
    if(!file.is_open()) throw runtime_error("Error al abrir el archivo");

    AnalisisClinico a;
    while(file >> a){
        add(a);
    }
    file.close();
}

void Container::writeToDisk(const string& filename){
    ofstream file(filename);
    if(!file.is_open()) throw runtime_error("Error al abrir el archivo");

    shared_ptr<Nodo> current = head;
    while(current){
        file << current->data <<endl;
        current = current->next;
    }
    file.close();
}

bool Container::isThere(const AnalisisClinico& a) const {
    shared_ptr<Nodo> current = head;
    while (current) {
        if (current->data == a) return true;
        current = current->next;
    }
    return false;
}

void Container::clear(){
    head = nullptr;
    count = 0;
}

Container& Container::operator=(const Container& other) {
    if (this != &other) {
        clear();
        shared_ptr<Nodo> current = other.head;
        while (current) {
            add(current->data);
            current = current->next;
        }
    }
    return *this;
}
Container Container::operator+(const Container& other) const {
    Container result(*this);
    shared_ptr<Nodo> current = other.head;
    while (current) {
        result.add(current->data);
        current = current->next;
    }
    return result;
}
Container& Container::operator+=(const Container& other) {
    shared_ptr<Nodo> current = other.head;
    while (current) {
        add(current->data);
        current = current->next;
    }
    return *this;
}
Container& Container::operator+=(const AnalisisClinico& a) {
    add(a);
    return *this;
}

istream& operator>>(istream& is, Container& c) {
    AnalisisClinico a;
    while (is >> a) {
        c.add(a);
    }
    return is;
}

ostream& operator<<(ostream& os, const Container& c) {
    shared_ptr<Nodo> current = c.head;
    while (current) {
        os << current->data << "#";
        current = current->next;
    }
    return os;
}
#endif // __CONTAINER_H__
