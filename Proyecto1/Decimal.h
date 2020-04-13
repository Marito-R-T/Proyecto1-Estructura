/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Decimal.h
 * Author: mari2bar
 *
 * Created on 2 de abril de 2020, 16:21
 */

#ifndef DECIMAL_H
#define DECIMAL_H
#include <string>
#include "Dato.h"

using namespace std;

class Decimal {
public:
    Decimal();
    Decimal(const Decimal& orig);
    virtual ~Decimal();
    Dato *bajar(Dato *nuevo, Dato *encurso);
    int HashDecimal(Dato *dato, string decimal, int tamano);
    Dato *obtener(string dato, Dato *encurso);
private:

};

#endif /* DECIMAL_H */

