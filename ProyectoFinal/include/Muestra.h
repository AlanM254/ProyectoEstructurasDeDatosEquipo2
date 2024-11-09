#ifndef MUESTRA_H_INCLUDED
#define MUESTRA_H_INCLUDED

#include <iostream>
using namespace std;

class Muestra{
    string tipo;
    string resultado;
    string microorganismo_aislado;
    string sencibilidad_antibioticos;
public:
    void setTipo(string t){
        tipo=t;
    }
    void setResultado(string res){
        resultado=res;
    }
};


#endif // MUESTRA_H_INCLUDED
