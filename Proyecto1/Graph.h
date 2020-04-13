/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Graph.h
 * Author: mari2bar
 *
 * Created on 11 de abril de 2020, 00:04
 */

#ifndef GRAPH_H
#define GRAPH_H
#include <string>

#include "Indice.h"

using namespace std;

class Graph {
public:
    Graph();
    Graph(const Graph& orig);
    virtual ~Graph();
    string getGrafica(){
        return grafica;
    }
    void iniciarGrafica(Indice *lista, Indice *escogidos);
    string regresarIndicesHash(Indice *lista, Indice *escogido);
    string regresarArbolBinario(Indice *escogido);
    string regresarEscogidos(Indice *escogidos);
    void producirImagen();
private:
    string grafica;
};

#endif /* GRAPH_H */

