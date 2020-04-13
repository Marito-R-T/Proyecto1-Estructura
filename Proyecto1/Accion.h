/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Accion.h
 * Author: mari2bar
 *
 * Created on 8 de abril de 2020, 21:25
 */

#ifndef ACCION_H
#define ACCION_H

#include "Tabla.h"
#include <string>
#include "Dato.h"

using namespace std;

class Accion {
public:
    Accion(string tipo);
    Accion(const Accion& orig);
    virtual ~Accion();
    void setTabla(Tabla *tabla){
        this->tabla = tabla;
    }
    Tabla *getTabla(){
        return tabla;
    }
    string getTipoAccion(){
        return this->tipoAccion;
    }
    void setTipoAccion(string tipoAccion){
        this->tipoAccion = tipoAccion;
    }
    void setDato(Dato *dato){
        this->dato = dato;
    }
    Dato *getDato(){
        return this->dato;
    }
    void setCondicion(string *condicion){
        this->condicion = condicion;
    }
    string *getCondicion(){
        return this->condicion;
    }
private:
    Tabla *tabla;
    Dato *dato;
    string tipoAccion;
    string *condicion;
};

#endif /* ACCION_H */

