/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Hash.cpp
 * Author: mari2bar
 * 
 * Created on 5 de abril de 2020, 19:43
 */

#include "Hash.h"
#include "Dato.h"
#include "Entero.h"
#include "String.h"
#include "Decimal.h"
#include "Char.h"
#include <string>

using namespace std;

Hash::Hash(string tipo) {
    this->tipo = tipo;
    Arbol *a = new Arbol(0, this->tipo);
    this->primero = a;
    Arbol *b = new Arbol(1, this->tipo);
    a->setAbajo(b);
    Arbol *c = new Arbol(2, this->tipo);
    b->setAbajo(c);
    Arbol *d = new Arbol(3, this->tipo);
    c->setAbajo(d);
    Arbol *e = new Arbol(4, this->tipo);
    d->setAbajo(e);
    this->setUltimo(e);
    this->tamanoHash = 5;
    this->cantidadDatos = 0;
}

Hash::Hash(const Hash& orig) {
}

Hash::~Hash() {
}

void Hash::rehashing() {
    Arbol *a = new Arbol(tamanoHash, this->tipo);
    Arbol *b = new Arbol(tamanoHash+1, this->tipo);
    a->setAbajo(b);
    Arbol *c = new Arbol(tamanoHash+2, this->tipo);
    b->setAbajo(c);
    Arbol *d = new Arbol(tamanoHash+3, this->tipo);
    c->setAbajo(d);
    Arbol *e = new Arbol(tamanoHash+4, this->tipo);
    d->setAbajo(e);
    this->ultimo->setAbajo(a);
    this->setUltimo(e);
    this->tamanoHash = this->tamanoHash + 5;
}

void Hash::ingresarDato(int posicionTabla, Dato *dato) {

}

bool Hash::ingresarDato(Dato* dato) {
    if (this->tipo == dato->getTipo()) {
        this->cantidadDatos=this->cantidadDatos+1;
        dato->setIdDato(this->cantidadDatos);
        if (this->tipo == "Entero") {
            Entero *entero = new Entero();
            int pos = entero->HashEntero(dato, dato->getDato(), this->tamanoHash);
            Arbol *a = this->primero->obtenerArbol(pos);
            a->ingresarDato(dato);
            delete entero;
        } else if (this->tipo == "String") {
            String *cadena = new String();
            int pos = cadena->HashString(dato, dato->getDato(), this->tamanoHash);
            Arbol *a = this->primero->obtenerArbol(pos);
            a->ingresarDato(dato);
            delete cadena;
        } else if (this->tipo == "Decimal") {
            Decimal *decimal = new Decimal();
            int pos = decimal->HashDecimal(dato, dato->getDato(), this->tamanoHash);
            Arbol *a = this->primero->obtenerArbol(pos);
            a->ingresarDato(dato);
            delete decimal;
        } else if (this->tipo == "Caracter") {
            Char *caracter = new Char();
            int pos = caracter->HashCaracter(dato, dato->getDato(), this->tamanoHash);
            Arbol *a = this->primero->obtenerArbol(pos);
            a->ingresarDato(dato);
            delete caracter;
        }
        double porcentaje = this->cantidadDatos / this->tamanoHash;
        if (porcentaje > 0.60) {
            this->rehashing();
        }
        return true;
    } else {
        return false;
    }
}

Dato *Hash::obtenerDato(string *str, int tamano) {
    if (str[2] == "Entero" && this->tipo == "Entero") {
        Entero *entero = new Entero();
        int pos = entero->HashEntero(NULL, str[1], tamano);
        Arbol *a = this->primero->obtenerArbol(pos);
        Dato *d = a->obtenerDato(str[1]);
        delete entero;
        if (d == NULL && this->tamanoHash > tamano) {
            return this->obtenerDato(str, tamano + 5);
        } else if (d != NULL) {
            return d;
        } else {
            return NULL;
        }
        delete entero;
    } else if (str[2] == "String" && this->tipo == "String") {
        String *cadena = new String();
        int pos = cadena->HashString(NULL, str[1], tamano);
        Arbol *a = this->primero->obtenerArbol(pos);
        Dato *d = a->obtenerDato(str[1]);
        delete cadena;
        if (d == NULL && this->tamanoHash > tamano) {
            return this->obtenerDato(str, tamano + 5);
        } else if (d != NULL) {
            return d;
        } else {
            return NULL;
        }

    } else if (str[2] == "Decimal" && this->tipo == "Decimal") {
        Decimal *decimal = new Decimal();
        int pos = decimal->HashDecimal(NULL, str[1], tamano);
        Arbol *a = this->primero->obtenerArbol(pos);
        Dato *d = a->obtenerDato(str[1]);
        delete decimal;
        if (d == NULL && this->tamanoHash > tamano) {
            return this->obtenerDato(str, tamano + 5);
        } else if (d != NULL) {
            return d;
        } else {
            return NULL;
        }
    } else if (str[2] == "Caracter" && this->tipo == "Caracter") {
        Char *caracter = new Char();
        int pos = caracter->HashCaracter(NULL, str[1], tamano);
        Arbol *a = this->primero->obtenerArbol(pos);
        Dato *d = a->obtenerDato(str[1]);
        delete caracter;
        if (d == NULL && this->tamanoHash > tamano) {
            return this->obtenerDato(str, tamano + 5);
        } else if (d != NULL) {
            return d;
        } else {
            return NULL;
        }

    } else {
        return NULL;
    }
}

string Hash::dibujarHash(string indice){
    string refsHash = "node"+indice+" [label = \""+this->dibujarRefsHash(0)+"\",height=2.5]; \n";
    int medio = this->tamanoHash/2;
    string refref = "nodeIndices:"+indice+" -> node"+indice+":f"+std::to_string(medio)+";\n";
    return refsHash + refref + this->dibujarArbol(indice, 0);
}

string Hash::dibujarArbol(string indice, int posArbol) {
    /*POS ARBOL EMPIEZA EN 0*/
    Arbol *a = this->getPrimero()->obtenerArbol(posArbol);
    if(a!=NULL){
        return this->dibujarDato(indice, a->getRaiz(), true, posArbol) + this->dibujarArbol(indice, posArbol+1);
    }else{
        return "";
    }
}

string Hash::dibujarDato(string indice, Dato *dato, bool israiz, int posArbol) {
    if (dato != NULL) {
        string node1 = "node" + indice + std::to_string(dato->getIdDato()) + " [label = \"<f0> |<f1> " + dato->getDato() + "|<f2> \"];\n";
        string d = this->dibujarDato(indice, dato->getDerecho(), false, posArbol);
        string i = this->dibujarDato(indice, dato->getIzquierdo(), false, posArbol);
        string refs ="";
        if(d!=""){
            refs+="\"node"+indice+std::to_string(dato->getIdDato())+"\":f2 -> \"node"+indice+std::to_string(dato->getDerecho()->getIdDato())+"\":f1;\n";
        }
        if(i!=""){
            refs+="\"node"+indice+std::to_string(dato->getIdDato())+"\":f0 -> \"node"+indice+std::to_string(dato->getIzquierdo()->getIdDato())+"\":f1;\n";
        }
        if(israiz){
            refs+="node"+indice+":f"+std::to_string(posArbol)+" -> \"node"+indice+std::to_string(dato->getIdDato())+"\":f1;\n";
        }
        return node1+d+i+refs;
    } else {
        return "";
    }
}

string Hash::dibujarRefsHash(int posHash){
    if(this->tamanoHash>posHash){
        string st = "<f"+std::to_string(posHash)+"> ";
        if(this->tamanoHash-1 >posHash){
            st += "|";
        }
        return st + this->dibujarRefsHash(posHash+1);
    }else{
        return " ";
    }
}