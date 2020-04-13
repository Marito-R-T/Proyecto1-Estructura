/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Accion.cpp
 * Author: mari2bar
 * 
 * Created on 8 de abril de 2020, 21:25
 */

#include "Accion.h"
#include <string>

using namespace std;

Accion::Accion(string tipo) {
    this->tipoAccion = tipo;
}

Accion::Accion(const Accion& orig) {
}

Accion::~Accion() {
}

