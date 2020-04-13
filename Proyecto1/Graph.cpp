/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Graph.cpp
 * Author: mari2bar
 * 
 * Created on 11 de abril de 2020, 00:04
 */

#include "Graph.h"
#include <string>
#include <fstream>

using namespace std;

Graph::Graph() {
}

Graph::Graph(const Graph& orig) {
}

Graph::~Graph() {
}

void Graph::iniciarGrafica(Indice* lista, Indice* escogidos){
    this->grafica = "digraph G { \n"
            "nodesep=.05; \n"
            "rankdir=LR; \n"
            "node [shape=record,width=.1,height=.1] \n"
            "nodeIndices [label = \""+this->regresarEscogidos(escogidos)+"\",height=2.5]; \n"
            +this->regresarIndicesHash(lista, escogidos)
            +"}";
}

string Graph::regresarArbolBinario(Indice* escogido){
    string arbol = escogido->getHash()->dibujarHash(escogido->getID());
    return arbol;
}

string Graph::regresarIndicesHash(Indice* lista, Indice *escogido){
    if(escogido!=NULL){
        return this->regresarArbolBinario(lista->obtenerIndice(escogido->getID()))+this->regresarIndicesHash(lista, escogido->getDerecha());
    }else{
        return "";
    }
}

string Graph::regresarEscogidos(Indice* escogidos){
    if(escogidos!=NULL){
        string st = "<"+escogidos->getID()+"> "+escogidos->getID()+" ";
        if(escogidos->getDerecha()!=NULL){
            st += "|";
        }
        return st + this->regresarEscogidos(escogidos->getDerecha());
    }else{
        string st = " ";
        return st;
    }
}

void Graph::producirImagen(){
    ofstream file;
    file.open("archivo.dot");
    file<<this->grafica;
    file.close();
    system("dot -Tpng archivo.dot -o imagen.png");
    system("feh imagen.png");
}