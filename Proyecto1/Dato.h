/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Dato.h
 * Author: mari2bar
 *
 * Created on 2 de abril de 2020, 16:26
 */

#ifndef DATO_H
#define DATO_H
#include <string>


using namespace std;

class Dato {
public:
    Dato();
    Dato(const Dato& orig);
    virtual ~Dato();
    void sumarHijoDerecho();
    void sumarHijoIzquierdo();
    Dato *Equilibrar();
    void RotacionIzquierda();
    void RotacionDerecha();
    void RotacionID();
    void RotacionDI();
    void agregarTupla(Dato *tupla);
    int getAltura(){
        return altura;
    }
    string getDato(){
        return dato;
    }
    void setTipo(string tipo){
        this->tipo = tipo;
    }
    Dato *getDerecho(){
        return derecho;
    }
    Dato *getIzquierdo(){
        return izquierdo;
    }
    Dato *getPadre(){
        return padre;
    }
    Dato *getTuplad(){
        return tuplad;
    }
    Dato *getTuplai(){
        return tuplai;
    }
    void setTuplad(Dato *tuplad){
        this->tuplad = tuplad;
    }
    void setTuplai(Dato *tuplai){
        this->tuplai = tuplai;
    }
    void setDerecho(Dato *derecho){
        this->derecho = derecho;
    }
    void setIzquierdo(Dato *izquierdo){
        this->izquierdo = izquierdo;
    }
    void setPadre(Dato *padre){
        this->padre = padre;
    }
    int getAlturaD(){
        return alturad;
    }
    int getAlturaI(){
        return alturai;
    }
    void setDato(string dato){
        this->dato = dato;
    }
    string getTipo(){
        return tipo;
    }
    void setAlturai(int alturai){
        this->alturai = alturai;
    }
    void setAlturad(int alturad){
        this->alturad = alturad;
    }
    void setIndice(string indice){
        this->indice = indice;
    }
    string getIndice(){
        return this->indice;
    }
    int getIdDato(){
        return idDato;
    }
    void setIdDato(int iddato){
        this->idDato = iddato;
    }
private:
    int altura, idDato;
    int alturai, alturad;
    string dato, tipo, indice;
    Dato *derecho;
    Dato *izquierdo;
    Dato *padre;
    Dato *tuplad;
    Dato *tuplai;
};

#endif /* DATO_H */

