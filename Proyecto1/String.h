/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   String.h
 * Author: mari2bar
 *
 * Created on 2 de abril de 2020, 16:20
 */

#ifndef STRING_H
#define STRING_H
#include <string>
#include "Dato.h"

using namespace std;

class String {
public:
    String();
    String(const String& orig);
    virtual ~String();
    Dato *bajar(Dato *nuevo, Dato *encurso);
    int HashString(Dato *dato,  string cadena, int tamano);
    Dato *obtener(string dato, Dato *encurso);
private:

};

#endif /* STRING_H */

