/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Hash.h
 * Author: mari2bar
 *
 * Created on 5 de abril de 2020, 19:43
 */

#ifndef HASH_H
#define HASH_H
#include "Arbol.h"
#include <string>
#include "Dato.h"

using namespace std;

class Hash {
public:
    Hash(string tipo);
    Hash(const Hash& orig);
    void rehashing();
    void ingresarDato(int posicionTabla, Dato *dato);
    virtual ~Hash();
    void setPrimero(Arbol *primero){
        this->primero = primero;
    }
    void setUltimo(Arbol *ultimo){
        this->ultimo = ultimo;
    }
    Arbol *getUltimo(){
        return ultimo;
    }
    Arbol *getPrimero(){
        return primero;
    }
    int getTamanoHash(){
        return tamanoHash;
    }
    int getCantidadDatos(){
        return cantidadDatos;
    }
    void setCantidadDatos(int cantidad){
        this->cantidadDatos = cantidad;
    }
    bool ingresarDato(Dato *dato);
    Dato *obtenerDato(string *str, int tamano);
    string dibujarArbol(string indice, int posArbol);
    string dibujarDato(string indice, Dato *dato, bool israiz, int posArbol);
    string dibujarRefsHash(int posHash);
    string dibujarHash(string indice);
private:
    int tamanoHash, cantidadDatos;
    string tipo;
    Arbol *primero, *ultimo;
};

#endif /* HASH_H */

