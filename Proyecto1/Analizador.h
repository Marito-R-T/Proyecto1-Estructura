/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Analizador.h
 * Author: mari2bar
 *
 * Created on 8 de abril de 2020, 00:26
 */

#ifndef ANALIZADOR_H
#define ANALIZADOR_H
#include <string>

#include "Indice.h"
#include "Tabla.h"
#include "Accion.h"

using namespace std;

class Analizador {
public:
    Analizador();
    Analizador(const Analizador& orig);
    virtual ~Analizador();
    Accion *EmpezarAnalizar(string s);
    void consumirToken(char aconsumir);
    void consumirAlphaNumerico();
    string consumirCadena();
    const char *array;
    char enelmomento;
    int pos;
    int tamano;
private:
    Accion *Funcion();
    Accion *SELECT();
    Indice *VS();
    Indice *VSP();
    string *WHERE();
    void Select();
    void From();
    void Where();
    Accion *INSERT();
    Indice *VI();
    Dato *VIV();
    Dato *VIVP();
    void Insert();
    void Into();
    void Values();
    Tabla *CREATE();
    Indice *CREATEP();
    string Tipo();
    void Create();
    void Table();
    string Id();
    string IdP();
    string *Opcion();
    string *Digito();
    string Entero();
    string EnteroP();
    string Fraccion();
    void Decimal();
    string Caracter();
    string Cadena();
    string CadenaP();
    void e();
    void ep();
    void error();
};

#endif /* ANALIZADOR_H */

