/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Entero.h
 * Author: mari2bar
 *
 * Created on 2 de abril de 2020, 16:20
 */

#ifndef ENTERO_H
#define ENTERO_H

#include "Dato.h"
#include <string>

using namespace std;

class Entero {
public:
    Entero();
    Entero(const Entero& orig);
    Dato *bajar(Dato *nuevo, Dato *encurso);
    virtual ~Entero();
    int HashEntero(Dato *dato, string entero, int tamano);
    void probar(double g){
        throw g;
    }
    Dato *obtener(string dato, Dato *encurso);
private:
};

#endif /* ENTERO_H */

