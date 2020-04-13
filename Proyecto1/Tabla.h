/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Tabla.h
 * Author: mari2bar
 *
 * Created on 5 de abril de 2020, 17:52
 */

#ifndef TABLA_H
#define TABLA_H
#include "Indice.h"
#include <string>
#include "Dato.h"

using namespace std;

class Tabla {
public:
    Tabla(Indice *primero);
    Tabla(const Tabla& orig);
    virtual ~Tabla();
    void agregarIndice(Indice *i);
    Indice *obtenerUltimo(Indice *actual);
    Indice *getLista(){
        return listaindices;
    }
    Indice *getUltimo(){
        return ultimo;
    }
    void setId(string id){
        this->id = id;
    }
    string getId(){
        return id;
    }
    Tabla *getArriba(){
        return arriba;
    }
    Tabla *getAbajo(){
        return abajo;
    }
    void setArriba(Tabla *arriba){
        this->arriba = arriba;
    }
    void setAbajo(Tabla *abajo){
        this->abajo = abajo;
    }
    bool verificarIDS();
    void agregarTabla(Tabla *tabla);
    Tabla *verificar(string idtabla);
    void dibujarTabla();
    bool ingresarDatos(Dato *dato, Indice *lista);
    bool ingresarDatos(Dato *dato);
    Dato *obtenerDato(string *s);
    void setLista(Indice *listaindices){
        this->listaindices = listaindices;
    }
    int getCantidadDatos(Indice *indice);
    int getTotalDatos();
private:
    int posicion;
    string id;
    Tabla *arriba, *abajo;
    Indice *listaindices;
    Indice *ultimo;
};

#endif /* TABLA_H */

