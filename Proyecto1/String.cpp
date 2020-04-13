/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   String.cpp
 * Author: mari2bar
 * 
 * Created on 2 de abril de 2020, 16:20
 */

#include "String.h"
#include "Dato.h"
#include <string>

using namespace std;

String::String() {
}

String::String(const String& orig) {
}

String::~String() {
}

int String::HashString(Dato *dato, string cadena, int tamano) {
    int h = cadena.size() % tamano;
}

Dato *String::bajar(Dato* nuevo, Dato* encurso) {
    if (encurso->getDato().compare(nuevo->getDato())>0) {
        if (encurso->getIzquierdo() != NULL) {
            return this->bajar(nuevo, encurso->getIzquierdo());
        } else {
            encurso->setIzquierdo(nuevo);
            nuevo->setPadre(encurso);
            return nuevo->Equilibrar();
        }
    } else {
        if (encurso->getDerecho() != NULL) {
            return this->bajar(nuevo, encurso->getDerecho());
        } else {
            encurso->setDerecho(nuevo);
            nuevo->setPadre(encurso);
            return nuevo->Equilibrar();
        }
    }
}

Dato *String::obtener(string dato, Dato* encurso){
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