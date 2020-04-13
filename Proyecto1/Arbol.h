/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Arbol.h
 * Author: mari2bar
 *
 * Created on 5 de abril de 2020, 17:50
 */

#ifndef ARBOL_H
#define ARBOL_H
#include <string>
#include "Dato.h"

using namespace std;

class Arbol {
public:
    Arbol(int posHash, string tipo);
    Arbol(const Arbol& orig);
    virtual ~Arbol();
    void ingresarDato(Dato *dato);
    void bajar(Dato *nuevo, Dato *encurso);
    void setTipo(string tipo){
        this->tipo = tipo;
    }
    string getTipo(){
        return tipo;
    }
    Dato *getRaiz(){
        return raiz;
    }
    void setAbajo(Arbol *abajo){
        this->abajo = abajo;
    }
    void setPosicionHash(int posHash){
        this->posHash = posHash;
    }
    Arbol *getAbajo(){
        return abajo;
    }
    int getPosHash(){
        return posHash;
    }
    Arbol *obtenerArbol(int i);
    Dato *obtenerDato(string dato);
private:
    Dato *raiz;
    string tipo;
    Arbol *abajo;
    int posHash;
};

#endif /* ARBOL_H */

