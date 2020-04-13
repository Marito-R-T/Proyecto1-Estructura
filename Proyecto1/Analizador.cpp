/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Analizador.cpp
 * Author: mari2bar
 * 
 * Created on 8 de abril de 2020, 00:26
 */

#include "Analizador.h"
#include "Indice.h"
#include "Tabla.h"
#include "Accion.h"
#include <string>
#include <iostream>
#include <stdio.h>

using namespace std;

Analizador::Analizador() {
    this->pos = 0;
}

Analizador::Analizador(const Analizador& orig) {
}

Analizador::~Analizador() {
}

Accion *Analizador::EmpezarAnalizar(string s) {
    this->tamano = s.size();
    pos = 0;
    this->array = s.c_str();
    this->enelmomento = array[pos];
    return this->Funcion();
}

void Analizador::consumirToken(char aconsumir) {
    cout << enelmomento;
    if (aconsumir == enelmomento) {
        pos++;
        if (pos < tamano) {
            enelmomento = array[pos];
        } else {
            enelmomento = '$';
            if (pos > tamano + 1) {
                throw enelmomento;
            }
        }
    } else {
        throw enelmomento;
    }
}

void Analizador::consumirAlphaNumerico() {
    cout << enelmomento;
    pos++;
    if (pos < tamano) {
        this->enelmomento = array[pos];
    } else {
        enelmomento = '$';
        if (pos > tamano + 1) {
            throw enelmomento;
        }
    }
}

Accion *Analizador::Funcion() {
    try {
        Accion *accion;
        if (this->enelmomento == 'S') {
            accion = this->SELECT();
            consumirToken('$');
        } else if (this->enelmomento == 'I') {
            accion = this->INSERT();
            consumirToken('$');
        } else if (this->enelmomento == 'C') {
            Tabla *tabla = this->CREATE();
            string ac = "CREATE";
            accion = new Accion(ac);
            accion->setTabla(tabla);
            consumirToken('$');
        } else {
            throw enelmomento;
        }
        cout << endl << "Leido correctamente";
        return accion;
    } catch (char caracter) {
        cout << endl << "error en: " << caracter << "  posición: " << pos << endl;
        return NULL;
    }
}

Accion *Analizador::SELECT() {
    if (this->enelmomento == 'S') {
        this->Select();
        this->e();
        Indice *indices = this->VS();
        if (indices->getID() == "$") {
            indices->setDerecha(NULL);
        }
        this->From();
        this->e();
        string tablaid = this->Id();
        /*CREAR TABLA*/ Tabla *t = new Tabla(indices);
        t->setId(tablaid);
        string *where = this->WHERE();
        string ac = "SELECT";
        /*CREAR ACCION*/Accion *accion = new Accion(ac);
        accion->setTabla(t);
        accion->setCondicion(where);
        this->consumirToken(';');
        return accion;
    } else {
        throw enelmomento;
    }
}

Indice *Analizador::VS() {
    if (isalpha(this->enelmomento)) {
        string idIndice = this->Id();
        /*CREAR INDICE*/Indice *i = new Indice(idIndice);
        i->addIndice(this->VSP());
        this->e();
        return i;
    } else if (this->enelmomento == '*') {
        consumirToken('*');
        this->e();
        return new Indice("$");
    } else {
        throw enelmomento;
    }
}

Indice *Analizador::VSP() {
    if (this->enelmomento == ',') {
        this->consumirToken(',');
        this->ep();
        string idIndice = this->Id();
        /*Agregar Indice*/ Indice *i = new Indice(idIndice);
        i->addIndice(this->VSP());
    } else if (this->enelmomento == ' ' || this->enelmomento == ')') {
        /*NO HACEMOS NADA*/
        return NULL;
    } else {
        throw enelmomento;
    }
}

string *Analizador::WHERE() {
    if (this->enelmomento == ' ') {
        this->e();
        string *where = new string[3];
        this->Where();
        this->e();
        string id = this->Id();
        where[0] = id;
        this->e();
        this->consumirToken('=');
        this->e();
        string *s = this->Opcion();
        where[1] = s[0];
        where[2] = s[1];
        this->ep();
        return where;
    } else if (this->enelmomento == ';') {
        /*NO HACEMOS NADA*/
        return NULL;
    } else {
        throw enelmomento;
    }
}

void Analizador::Select() {
    if (this->enelmomento == 'S') {
        consumirToken('S');
        consumirToken('E');
        consumirToken('L');
        consumirToken('E');
        consumirToken('C');
        consumirToken('T');
    } else {
        throw enelmomento;
    }
}

void Analizador::From() {
    if (this->enelmomento == 'F') {
        consumirToken('F');
        consumirToken('R');
        consumirToken('O');
        consumirToken('M');
    } else {
        throw enelmomento;
    }
}

void Analizador::Where() {
    if (this->enelmomento == 'W') {
        consumirToken('W');
        consumirToken('H');
        consumirToken('E');
        consumirToken('R');
        consumirToken('E');
    } else {
        throw enelmomento;
    }
}

Accion *Analizador::INSERT() {
    if (this->enelmomento == 'I') {
        this->Insert();
        this->e();
        this->Into();
        this->e();
        string idtabla = this->Id();
        /*Agregar indices*/
        this->e();
        Indice *i = this->VI();
        if (i->getID() == "$") {
            i->setDerecha(NULL);
        }
        this->Values();
        this->e();
        Dato *dato = this->VIV();
        consumirToken(';');
        string ac = "INSERT";
        Accion *accion = new Accion(ac);
        Tabla *t = new Tabla(i);
        t->setId(idtabla);
        accion->setTabla(t);
        accion->setDato(dato);
        return accion;
    } else {
        throw enelmomento;
    }
}

Indice *Analizador::VI() {
    if (this->enelmomento == '(') {
        consumirToken('(');
        this->ep();
        string idIndice = this->Id();
        /*AGREGAR INDICE*/ Indice *i = new Indice(idIndice);
        i->addIndice(this->VSP());
        consumirToken(')');
        this->e();
        return i;
    } else if (this->enelmomento == 'V') {
        /*NO HACER NADA*/
        return new Indice("$");
    } else {
        throw enelmomento;
    }
}

Dato *Analizador::VIV() {
    if (this->enelmomento == '(') {
        consumirToken('(');
        this->ep();
        string *opcion = this->Opcion();
        /*CREAR DATO*/ Dato *d = new Dato();
        d->setDato(opcion[0]);
        d->setTipo(opcion[1]);
        this->ep();
        d->agregarTupla(this->VIVP());
        consumirToken(')');
        this->ep();
        return d;
    } else {
        throw enelmomento;
    }
}

Dato *Analizador::VIVP() {
    if (this->enelmomento == ',') {
        consumirToken(',');
        this->ep();
        string *opcion = this->Opcion();
        /*CREAR DATO*/ Dato *d = new Dato();
        d->setDato(opcion[0]);
        d->setTipo(opcion[1]);
        this->ep();
        d->agregarTupla(this->VIVP());
        return d;
    } else if (this->enelmomento == ')') {
        /*NO HACER NADA*/
        return NULL;
    } else {
        throw enelmomento;
    }
}

void Analizador::Insert() {
    if (this->enelmomento == 'I') {
        consumirToken('I');
        consumirToken('N');
        consumirToken('S');
        consumirToken('E');
        consumirToken('R');
        consumirToken('T');
    } else {
        throw enelmomento;
    }
}

void Analizador::Into() {
    if (this->enelmomento == 'I') {
        consumirToken('I');
        consumirToken('N');
        consumirToken('T');
        consumirToken('O');
    } else {
        throw enelmomento;
    }

}

void Analizador::Values() {
    if (this->enelmomento == 'V') {
        consumirToken('V');
        consumirToken('A');
        consumirToken('L');
        consumirToken('U');
        consumirToken('E');
        consumirToken('S');
    } else {
        throw enelmomento;
    }
}

Tabla *Analizador::CREATE() {
    if (this->enelmomento == 'C') {
        this->Create();
        this->e();
        this->Table();
        this->e();
        string nombreTabla = this->Id();
        this->e();
        consumirToken('(');
        this->ep();
        string idIndice = this->Id();
        this->e();
        string tipoindice = this->Tipo();
        /*Crear los indices: */ Indice *i = new Indice(tipoindice, idIndice);
        this->ep();
        i->addIndice(this->CREATEP());
        consumirToken(')');
        this->ep();
        consumirToken(';');
        /*Crear la tabla: */ Tabla *t = new Tabla(i);
        t->setId(nombreTabla);
        return t;
    } else {
        throw enelmomento;
    }
}

Indice *Analizador::CREATEP() {
    if (this->enelmomento == ',') {
        consumirToken(',');
        this->ep();
        string idIndice = this->Id();
        this->e();
        string tipoindice = this->Tipo();
        this->ep();
        /*Crear los indices: */ Indice *i = new Indice(tipoindice, idIndice);
        i->addIndice(this->CREATEP());
        return i;
    } else if (this->enelmomento == ')') {
        /*NO HACER NADA*/
        return NULL;
    } else {
        throw enelmomento;
    }
}

string Analizador::Tipo() {
    if (this->enelmomento == 'E') {
        consumirToken('E');
        consumirToken('n');
        consumirToken('t');
        consumirToken('e');
        consumirToken('r');
        consumirToken('o');
        return "Entero";
    } else if (this->enelmomento == 'D') {
        consumirToken('D');
        consumirToken('e');
        consumirToken('c');
        consumirToken('i');
        consumirToken('m');
        consumirToken('a');
        consumirToken('l');
        return "Decimal";
    } else if (this->enelmomento == 'S') {
        consumirToken('S');
        consumirToken('t');
        consumirToken('r');
        consumirToken('i');
        consumirToken('n');
        consumirToken('g');
        return "String";
    } else if (this->enelmomento == 'C') {
        consumirToken('C');
        consumirToken('a');
        consumirToken('r');
        consumirToken('a');
        consumirToken('c');
        consumirToken('t');
        consumirToken('e');
        consumirToken('r');
        return "Caracter";
    } else {
        throw this->enelmomento;
    }
}

void Analizador::Create() {
    if (this->enelmomento == 'C') {
        consumirToken('C');
        consumirToken('R');
        consumirToken('E');
        consumirToken('A');
        consumirToken('T');
        consumirToken('E');
    } else {
        throw enelmomento;
    }
}

void Analizador::Table() {
    if (this->enelmomento == 'T') {
        consumirToken('T');
        consumirToken('A');
        consumirToken('B');
        consumirToken('L');
        consumirToken('E');
    } else {
        throw enelmomento;
    }
}

string Analizador::Id() {
    string id = "";
    if (isalpha(this->enelmomento)) {
        id.push_back(this->enelmomento);
        consumirAlphaNumerico();
        id += this->IdP();
        return id;
    } else {
        throw this->enelmomento;
    }
}

string Analizador::IdP() {
    string idp = "";
    if (isalpha(this->enelmomento) || isdigit(this->enelmomento)) {
        idp.push_back(this->enelmomento);
        consumirAlphaNumerico();
        idp += this->IdP();
        return idp;
    } else if (this->enelmomento == ',' || this->enelmomento == ' ' || this->enelmomento == ')' || this->enelmomento == ';') {
        /*NO HACER NADA*/
        return idp;
    } else {
        throw this->enelmomento;
    }
}

string *Analizador::Opcion() {
    string *opcion = new string[2];
    if (this->enelmomento == '"') {
        opcion[0] = this->Cadena();
        opcion[1] = "String";
        return opcion;
    } else if (this->enelmomento == '\'') {
        opcion[0] = this->Caracter();
        opcion[1] = "Caracter";
        return opcion;
    } else if (isdigit(this->enelmomento)) {
        return this->Digito();
    } else {
        throw this->enelmomento;
    }
}

string *Analizador::Digito() {
    string *opcion = new string[2];
    if (isdigit(this->enelmomento)) {
        string digito;
        string fraccion;
        digito = this->Entero();
        fraccion = this->Fraccion();
        digito += fraccion;
        opcion[0] = digito;
        if (fraccion == "") {
            opcion[1] = "Entero";
        } else {
            opcion[1] = "Decimal";
        }
        return opcion;
    } else {
        throw this->enelmomento;
    }
}

string Analizador::Entero() {
    if (isdigit(this->enelmomento)) {
        string entero;
        entero.push_back(enelmomento);
        consumirAlphaNumerico();
        entero += this->EnteroP();
        return entero;
    } else {
        throw this->enelmomento;
    }
}

string Analizador::EnteroP() {
    if (isdigit(this->enelmomento)) {
        string enterop;
        enterop.push_back(enelmomento);
        consumirAlphaNumerico();
        enterop += this->EnteroP();
        return enterop;
    } else if (this->enelmomento == ',' || this->enelmomento == ';' || this->enelmomento == '.'
            || this->enelmomento == ' ' || this->enelmomento == ')') {
        /*NO HACER NADA*/
        string nada = "";
        return nada;
    } else {
        throw this->enelmomento;
    }
}

string Analizador::Fraccion() {
    if (this->enelmomento == '.') {
        string fraccion = ".";
        consumirToken('.');
        fraccion += this->Entero();
        return fraccion;
    } else if (this->enelmomento == ',' || this->enelmomento == ';' || this->enelmomento == ' '
            || this->enelmomento == ')' || this->enelmomento == '"') {
        /*NO HACER NADA*/
        string nada = "";
        return nada;
    } else {
        throw this->enelmomento;
    }
}

void Analizador::Decimal() {
    if (isdigit(this->enelmomento)) {
        this->Entero();
        consumirToken('.');
        this->Entero();
    } else {
        throw enelmomento;
    }
}

string Analizador::Caracter() {
    if (this->enelmomento == '\'') {
        string caracter;
        consumirToken('\'');
        caracter.push_back(this->enelmomento);
        consumirAlphaNumerico();
        consumirToken('\'');
        return caracter;
    } else {
        throw enelmomento;
    }
}

string Analizador::Cadena() {
    if (this->enelmomento == '"') {
        consumirToken('"');
        string cadena = consumirCadena();
        consumirToken('"');
        return cadena;
    } else {
        throw enelmomento;
    }
}

string Analizador::CadenaP() {
}

void Analizador::e() {
    if (this->enelmomento == ' ') {
        consumirToken(' ');
        this->ep();
    } else {
        throw this->enelmomento;
    }
}

void Analizador::ep() {
    if (this->enelmomento == ' ') {
        consumirToken(' ');
        this->ep();
    } else if (this->enelmomento == ',' || this->enelmomento == ';' || this->enelmomento == ')'
            || this->enelmomento == '"' || this->enelmomento == '\'' || this->enelmomento == '('
            || this->enelmomento == '*' || this->enelmomento == '=' || isalpha(this->enelmomento)
            || isdigit(this->enelmomento)) {
        /*NO HACER NADA*/
    } else {
        throw this->enelmomento;
    }
}

void Analizador::error() {

}

string Analizador::consumirCadena() {
    string cadena = "";
    while (this->enelmomento != '"') {
        cadena.push_back(this->enelmomento);
        consumirAlphaNumerico();
    }
    return cadena;
}