/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Decimal.cpp
 * Author: mari2bar
 * 
 * Created on 2 de abril de 2020, 16:21
 */

#include "Decimal.h"
#include "Dato.h"
#include <string>

using namespace std;

Decimal::Decimal() {
}

Decimal::Decimal(const Decimal& orig) {
}

Decimal::~Decimal() {
}

int Decimal::HashDecimal(Dato *dato, string decimal, int tamano){
    decimal.erase(decimal.rfind('.',decimal.length()),1);
    int n = stoi(decimal, nullptr, 10);
    n = n-(n/2);
    return n % tamano;
}

Dato *Decimal::bajar(Dato* nuevo, Dato* encurso){
    double n = atof(nuevo->getDato().c_str());
    double e = atof(encurso->getDato().c_str());
    if (n < e) {
        encurso->sumarHijoIzquierdo();
        if (encurso->getIzquierdo() != NULL) {
            return this->bajar(nuevo, encurso->getIzquierdo());
        } else {
            encurso->setIzquierdo(nuevo);
            nuevo->setPadre(encurso);
            encurso->sumarHijoIzquierdo();
            return nuevo->Equilibrar();
        }
    } else {
        encurso->sumarHijoDerecho();
        if (encurso->getDerecho() != NULL) {
            return this->bajar(nuevo, encurso->getDerecho());
        } else {
            encurso->setDerecho(nuevo);
            nuevo->setPadre(encurso);
            encurso->sumarHijoDerecho();
            return nuevo->Equilibrar();
        }
    }
}

Dato *Decimal::obtener(string dato, Dato* encurso){
    double n = atof(dato.c_str());
    double e = atof(encurso->getDato().c_str());
    if (n<e) {
        if (encurso->getIzquierdo() != NULL) {
            return this->obtener(dato, encurso->getIzquierdo());
        } else {
            return NULL;
        }
    } else if (n>e){
        if (encurso->getDerecho() != NULL) {
            return this->obtener(dato, encurso->getDerecho());
        } else {
            return NULL;
        }
    } else{
        return encurso;
    }
}
