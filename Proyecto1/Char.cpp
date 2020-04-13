/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Char.cpp
 * Author: mari2bar
 * 
 * Created on 2 de abril de 2020, 16:21
 */

#include "Char.h"
#include <string>

Char::Char() {
}

Char::Char(const Char& orig) {
}

Char::~Char() {
}

int Char::HashCaracter(Dato* dato, string cadena, int tamano){
    int numero = cadena.c_str()[0];
    return numero % tamano;
}

Dato *Char::bajar(Dato* nuevo, Dato* encurso){
    if (encurso->getDato().compare(nuevo->getDato())>0) {
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

Dato *Char::obtener(string dato, Dato* encurso){
    if (encurso->getDato().compare(dato)>0) {
        if (encurso->getIzquierdo() != NULL) {
            return this->obtener(dato, encurso->getIzquierdo());
        } else {
            return NULL;
        }
    } else if (dato.compare(encurso->getDato())>0){
        if (encurso->getDerecho() != NULL) {
            return this->obtener(dato, encurso->getDerecho());
        } else {
            return NULL;
        }
    } else{
        return encurso;
    }
}