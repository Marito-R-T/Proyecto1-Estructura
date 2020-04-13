/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BaseDatos.h
 * Author: mari2bar
 *
 * Created on 9 de abril de 2020, 00:16
 */

#ifndef BASEDATOS_H
#define BASEDATOS_H

#include "Accion.h"
#include "Tabla.h"

class BaseDatos {
public:
    BaseDatos();
    BaseDatos(const BaseDatos& orig);
    virtual ~BaseDatos();
    void empezarFuncionamiento();
    void mostrarOpciones();
    string pedirComando();
    void agregarTabla();
    void hacerSelect(Accion *accion);
    void hacerInsert(Accion *accion);
    void hacerCreate(Accion *accion);
private:
    Tabla *tabla;
};

#endif /* BASEDATOS_H */

