/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Indice.h
 * Author: mari2bar
 *
 * Created on 5 de abril de 2020, 17:57
 */

#ifndef INDICE_H
#define INDICE_H
#include <string>

#include "Hash.h"
#include "Dato.h"

using namespace std;

class Indice {
public:
    Indice(string tipo, string id);
    Indice(string id);
    Indice(const Indice& orig);
    virtual ~Indice();
    void setId(string id){
        this->id = id;
    }
    int getPosicion(){
        return posicion;
    }
    string getID(){
        return id;
    }
    string getTipo(){
        return tipo;
    }
    Indice *getDerecha(){
        return derecha;
    }
    Indice *getIzquierda(){
        return izquierda;
    }
    Hash *getHash(){
        return hash;
    }
    void setDerecha(Indice *derecha){
        this->derecha = derecha;
    }
    void setIzquierda(Indice *izquierda){
        this->izquierda = izquierda;
    }
    void addIndice(Indice *indice);
    bool comparararSiguientes();
    bool compararTodos();
    string dibujarse();
    Indice *obtenerIndice(string id);
    Dato *getDato(Dato *dato);
    Dato *getIzquierdas(Dato *dato);
private:
    int posicion;
    string id, tipo;
    Hash *hash;
    Indice *derecha, *izquierda;
};

#endif /* INDICE_H */

