/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: mari2bar
 *
 * Created on 2 de abril de 2020, 16:02
 */

#include <cstdlib>
#include <stdio.h>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <iostream>

#include "Analizador.h"
#include "BaseDatos.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    /*string c = "digraph G { \n"
            "nodesep=.05; \n"
            "rankdir=LR; \n"
            "node [shape=record,width=.1,height=.1]; \n"
            "node0 [label = \"<f0> abc |<f1> |<f2> |<f3> |<f4> |<f5> |<f6> | \",height=2.5]; \n"
            "node [width = 1.5]; \n"
            "node1 [label = \"{<n> n14 | 719 |<p> }\"]; \n"
            "node2 [label = \"{<n> a1  | 805 |<p> }\"]; \n"
            "node3 [label = \"{<n> i9  | 718 |<p> }\"]; \n"
            "node4 [label = \"{<n> e5  | 989 |<p> }\"]; \n"
            "node5 [label = \"{<n> t20 | 959 |<p> }\"] ; \n"
            "node6 [label = \"{<n> o15 | 794 |<p> }\"] ; \n"
            "node7 [label = \"{<n> s19 | 659 |<p> }\"] ; \n"
            "node0:f0 -> node1:n; \n"
            "node0:f1 -> node2:n; \n"
            "node0:f2 -> node3:n; \n"
            "node0:f5 -> node4:n; \n"
            "node0:f6 -> node5:n; \n"
            "node2:p -> node6:n; \n"
            "node4:p -> node7:n; \n"
            "}";
    ofstream file;
    file.open("archivo.dot");
    file<<c;
    file.close();
    system("dot -Tpng archivo.dot -o imagen.png");
    system("nohup display imagen.png");*/
    BaseDatos *base = new BaseDatos();
    base->empezarFuncionamiento();
    return 0;
}