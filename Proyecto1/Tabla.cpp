/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Tabla.cpp
 * Author: mari2bar
 * 
 * Created on 5 de abril de 2020, 17:52
 */

#include "Tabla.h"
#include "Indice.h"
#include "Dato.h"
#include <string>
#include <iostream>

using namespace std;

Tabla::Tabla(Indice *primero) {
    if (primero != NULL) {
        this->listaindices = primero;
        ultimo = obtenerUltimo(primero);
    }
}

Tabla::Tabla(const Tabla& orig) {
}

Tabla::~Tabla() {
}

Indice *Tabla::obtenerUltimo(Indice *actual) {
    if (actual->getDerecha() != NULL) {
        return obtenerUltimo(actual->getDerecha());
    } else {
        return actual;
    }
}

void Tabla::agregarIndice(Indice* i) {
    if (this->listaindices == NULL) {
        this->listaindices = i;
        this->ultimo = i;
    } else {
        this->ultimo->setDerecha(i);
        i->setIzquierda(this->ultimo);
        this->ultimo = i;
    }
}

bool Tabla::verificarIDS() {
    if (listaindices != NULL) {
        return listaindices->comparararSiguientes();
    } else {
        return true;
    }
}

void Tabla::agregarTabla(Tabla *nuevo) {
    if (this->abajo != NULL) {
        this->abajo->agregarTabla(nuevo);
    } else {
        this->abajo = nuevo;
        nuevo->setArriba(this);
    }
}

Tabla *Tabla::verificar(string idtabla) {
    if (this->id == idtabla) {
        return this;
    } else {
        if (this->abajo != NULL) {
            return this->abajo->verificar(idtabla);
        } else {
            return NULL;
        }
    }
}

void Tabla::dibujarTabla() {
    cout << endl << "__________________________________________";
    cout << endl << "TABLA:  " << this->id << endl;
    cout << "------------------------------------------" << endl;
    string indices = listaindices->dibujarse();
    cout << indices;
}

bool Tabla::ingresarDatos(Dato *dato) {
    return this->ingresarDatos(dato, this->listaindices);
}

bool Tabla::ingresarDatos(Dato *dato, Indice *lista) {
    if (dato != NULL) {
        if (lista != NULL) {
            Indice *i = this->listaindices->obtenerIndice(lista->getID());
            if (i != NULL) {
                dato->setIndice(i->getID());
                return i->getHash()->ingresarDato(dato) && this->ingresarDatos(dato->getTuplad(), lista->getDerecha());
            } else {
                return false;
            }
        } else {
            return false;
        }
    } else {
        if (lista != NULL) {
            return false;
        } else {
            return true;
        }
    }
}

Dato *Tabla::obtenerDato(string* s){
    Indice *indice = this->listaindices->obtenerIndice(s[0]);
    if(indice != NULL){
        Dato *dato = indice->getHash()->obtenerDato(s, 5);
        return dato;
    }else{
        return NULL;
    }
}

int Tabla::getCantidadDatos(Indice* indice){
    if(indice!=NULL){
        return indice->getHash()->getCantidadDatos() + this->getCantidadDatos(indice->getDerecha());
    }else{
        return 0;
    }
}

int Tabla::getTotalDatos(){
    if(this->getAbajo()!=NULL){
        return this->getCantidadDatos(this->listaindices) + this->abajo->getTotalDatos();
    }else{
        return this->getCantidadDatos(this->listaindices);
    }
}