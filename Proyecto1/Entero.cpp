/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Entero.cpp
 * Author: mari2bar
 * 
 * Created on 2 de abril de 2020, 16:20
 */

#include "Entero.h"
#include <string>
#include <stdio.h> 
#include <iostream>

using namespace std;

Entero::Entero() {
}

Entero::Entero(const Entero& orig) {
}

Entero::~Entero() {
}

int Entero::HashEntero(Dato *dato, string entero, int tamano) {
    int en = stoi(entero, nullptr, 10);
    return en % tamano;
}

Dato *Entero::bajar(Dato* nuevo, Dato* encurso) {
    int n = stoi(nuevo->getDato(), nullptr, 10);
    int e = stoi(encurso->getDato(), nullptr, 10);
    if (n < e) {
        if (encurso->getIzquierdo() != NULL) {
            return this->bajar(nuevo, encurso->getIzquierdo());
        } else {
            encurso->setIzquierdo(nuevo);
            nuevo->setPadre(encurso);
            encurso->sumarHijoIzquierdo();
            return nuevo->Equilibrar();
        }
    } else {
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

Dato *Entero::obtener(string dato, Dato* encurso){
    int n = stoi(dato, nullptr, 10);
    int e = stoi(encurso->getDato(), nullptr, 10);
    if (n < e) {
        if (encurso->getIzquierdo() != NULL) {
            return this->obtener(dato, encurso->getIzquierdo());
        } else {
            return NULL;
        }
    } else if (n > e){
        if (encurso->getDerecho() != NULL) {
            return this->obtener(dato, encurso->getDerecho());
        } else {
            return NULL;
        }
    } else{
        return encurso;
    }
}