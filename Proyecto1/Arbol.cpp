/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Arbol.cpp
 * Author: mari2bar
 * 
 * Created on 5 de abril de 2020, 17:50
 */

#include "Arbol.h"
#include "Entero.h"
#include "String.h"
#include "Dato.h"
#include "Decimal.h"
#include "Char.h"

Arbol::Arbol(int posHash, string tipo) {
    this->posHash=posHash;
    this->tipo = tipo;
}

Arbol::Arbol(const Arbol& orig) {
}

Arbol::~Arbol() {
}

void Arbol::ingresarDato(Dato* dato) {
    if (this->raiz == NULL) {
        raiz = dato;
    } else {
        this->bajar(dato, raiz);
    }
}

void Arbol::bajar(Dato* nuevo, Dato* encurso) {
    if (this->tipo == "String") {
        String *string = new String();
        this->raiz = string->bajar(nuevo, encurso);
        delete string;
    } else if (this->tipo == "Entero") {
        Entero *entero = new Entero();
        this->raiz = entero->bajar(nuevo, encurso);
        delete entero;
    } else if (this->tipo == "Decimal") {
        Decimal *decimal = new Decimal();
        this->raiz =decimal->bajar(nuevo, encurso);
        delete decimal;
    } else if (this->tipo == "Caracter") {
        Char *caracter = new Char();
        this->raiz = caracter->bajar(nuevo, encurso);
        delete caracter;
    }
}

Arbol *Arbol::obtenerArbol(int i){
    if(this->posHash == i){
        return this;
    }else{
        if(this->abajo!=NULL){
            return this->abajo->obtenerArbol(i);
        }else{
            return NULL;
        }
    }
}

Dato *Arbol::obtenerDato(string dato){
    if (this->tipo == "String") {
        String *string = new String();
        Dato *buscado = string->obtener(dato, raiz);
        delete string;
        return buscado;
    } else if (this->tipo == "Entero") {
        Entero *entero = new Entero();
        Dato *buscado = entero->obtener(dato, raiz);
        delete entero;
        return buscado;
    } else if (this->tipo == "Decimal") {
        Decimal *decimal = new Decimal();
        Dato *buscado = decimal->obtener(dato, raiz);
        delete decimal;
        return buscado;
    } else if (this->tipo == "Caracter") {
        Char *caracter = new Char();
        Dato *buscado = caracter->obtener(dato, raiz);
        delete caracter;
        return buscado;
    }else{
        return NULL;
    }
}
