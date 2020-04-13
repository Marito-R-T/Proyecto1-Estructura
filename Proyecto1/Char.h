/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Char.h
 * Author: mari2bar
 *
 * Created on 2 de abril de 2020, 16:21
 */

#ifndef CHAR_H
#define CHAR_H
#include <string>
#include "Dato.h"

using namespace std;

class Char {
public:
    Char();
    Char(const Char& orig);
    virtual ~Char();
    Dato *bajar(Dato *nuevo, Dato *encurso);
    int HashCaracter(Dato *dato,  string cadena, int tamano);
    Dato *obtener(string dato, Dato *encurso);
private:

};

#endif /* CHAR_H */

