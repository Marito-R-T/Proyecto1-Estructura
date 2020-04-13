/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Indice.cpp
 * Author: mari2bar
 * 
 * Created on 5 de abril de 2020, 17:57
 */

#include "Indice.h"
#include "Hash.h"
#include <string>

using namespace std;

Indice::Indice(string tipo, string id) {
    this->tipo = tipo;
    this->id = id;
    Hash *h = new Hash(tipo);
    this->hash = h;
}

Indice::Indice(string id) {
    this->id = id;
}

Indice::Indice(const Indice& orig) {
}

Indice::~Indice() {
}

void Indice::addIndice(Indice* indice) {
    if (indice != NULL) {
        if (this->derecha != NULL) {
            this->derecha->addIndice(indice);
        } else {
            this->derecha = indice;
            indice->setIzquierda(this);
        }
    }
}

bool Indice::comparararSiguientes(){
    if(this->derecha!=NULL){
        return this->compararTodos() && this->derecha->comparararSiguientes();
    }else{
        return true;
    }
}

bool Indice::compararTodos(){
    Indice *d = this->derecha;
    while(d!=NULL){
        if(this->id==d->getID()){
            return false;
        }
        d = d->getDerecha();
    }
    return true;
}

string Indice::dibujarse(){
    string dibujo = "|  "+this->id+" ("+this->tipo+")  ";
    if(this->derecha!=NULL){
        return dibujo + this->derecha->dibujarse();
    }else{
        return dibujo + "\n\n";
    }
    
}

Indice *Indice::obtenerIndice(string id){
    if(this->id == id){
        return this;
    }else{
        if(this->derecha!=NULL){
            return this->derecha->obtenerIndice(id);
        }else{
            return NULL;
        }
    }
}

Dato *Indice::getDato(Dato* dato){
    if(dato->getIndice()==this->id){
        return dato;
    }else{
        if(dato->getTuplad()!=NULL){
            return this->getDato(dato->getTuplad());
        }else{
            return this->getIzquierdas(dato);
        }
    }
}

Dato *Indice::getIzquierdas(Dato *dato){
    if(dato->getIndice()==this->id){
        return dato;
    }else{
        if(dato->getTuplai()!=NULL){
            return this->getIzquierdas(dato->getTuplai());
        }else{
            return NULL;
        }
    }
}