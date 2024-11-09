
#include <iostream>
#include <memory>
#include "include/ListaEnlazada.hpp"
#include "include/analisisClinico.hpp"
#include "include/Hemocultivo.hpp"

using namespace std;

int main(){
    ListaEnlazada<AnalisisClinico*> ac;
    ac.insertarAlInicio(new Hemocultivo());
    Hemocultivo* a =new Hemocultivo("2");
    ac.insertarAlInicio(a);

    cout << "Hello world!" << endl;
    ac.mostrar();
    return 0;
}
