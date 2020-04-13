/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BaseDatos.cpp
 * Author: mari2bar
 * 
 * Created on 9 de abril de 2020, 00:16
 */

#include "BaseDatos.h"
#include <string>
#include <iostream>
#include "Analizador.h"
#include "Graph.h"

using namespace std;

BaseDatos::BaseDatos() {
}

BaseDatos::BaseDatos(const BaseDatos& orig) {
}

BaseDatos::~BaseDatos() {
}

void BaseDatos::empezarFuncionamiento() {
    cout << "BIENVENIDO A NUESTRA BASE DE DATOS (BASADO EN UN SISTEMA DE TABLAS HASH Y ARBOLES AVL)" << endl;
    bool t = true;
    while (t) {
        this->mostrarOpciones();
        string opcion;
        string extra;
        cin>>opcion;
        std::getline(std::cin, extra);
        if (opcion == "4") {
            string idtabla;
            cout << endl << "Ingresar Id de la Tabla para ver su Estructura" << endl;
            cin>>idtabla;
            if (this->tabla != NULL) {
                Tabla *t = this->tabla->verificar(idtabla);
                if (t != NULL) {
                    t->dibujarTabla();
                } else {
                    cout << "Tabla No Encontrada" << endl;
                }
            }
        } else if (opcion == "1") {
            string idtabla;
            cout << endl << "De que tabla desea Saber el numero  de datos que existen?" << endl;
            cin>>idtabla;
            if (this->tabla != NULL) {
                Tabla *t = this->tabla->verificar(idtabla);
                if (t != NULL) {
                    int datos = t->getCantidadDatos(t->getLista());
                    cout << "El numero de datos en la tabla " << idtabla << " es de: " << datos << endl;
                } else {
                    cout << "No existe una tabla con ese id" << endl;
                }
            } else {
                cout << "No existen tablas" << endl;
            }
        } else if (opcion == "2") {
            if (this->tabla != NULL) {
                int datos = this->tabla->getTotalDatos();
                cout << endl << "El numero de datos en la base de datos es de: " << datos << endl;
            } else {
                cout << endl << "Hay 0 datos ya que no existe ninguna tabla";
            }
        } else {
            opcion += extra;
            Analizador *analizar = new Analizador();
            Accion *accion = analizar->EmpezarAnalizar(opcion);
            if (accion != NULL) {
                if (accion->getTipoAccion() == "SELECT") {
                    this->hacerSelect(accion);
                } else if (accion->getTipoAccion() == "INSERT") {
                    this->hacerInsert(accion);
                } else if (accion->getTipoAccion() == "CREATE") {
                    this->hacerCreate(accion);
                }
            } else {
                cout << endl << "NO ES NINGUN COMANDO ACEPTADO LO SIENTO" << endl;
            }
            delete analizar;
            delete accion;
        }
    }
}

void BaseDatos::hacerSelect(Accion *accion) {
    if (accion != NULL && accion->getTabla() != NULL) {
        if (accion != NULL && accion->getCondicion() != NULL) {
            Tabla *ref = this->tabla->verificar(accion->getTabla()->getId());
            if (accion->getTabla()->getLista()->getID() == "$") {
                accion->getTabla()->setLista(ref->getLista());
            }
            Dato *dato = ref->obtenerDato(accion->getCondicion());
            if (dato != NULL) {
                Indice *i = accion->getTabla()->getLista();
                cout << endl << i->dibujarse();
                while (i != NULL) {
                    Dato *d = i->getDato(dato);
                    if (d != NULL) {
                        cout << "  " << d->getDato() << "  ";
                    } else {
                        cout << "              ";
                    }
                    i = i->getDerecha();
                }
                cout << endl << endl;
            } else {
                cout << endl << "Datos no encontrados" << endl;
            }
        } else if (accion != NULL && accion->getCondicion() == NULL) {
            Tabla *ref = this->tabla->verificar(accion->getTabla()->getId());
            if (accion->getTabla()->getLista()->getID() == "$") {
                accion->getTabla()->setLista(ref->getLista());
            }
            Graph *graph = new Graph();
            graph->iniciarGrafica(ref->getLista(), accion->getTabla()->getLista());
            graph->producirImagen();
            delete graph;
        }
    } else {
        cout << endl << "NO SE PUDO SELECCIONAR LA LINEA, POR UN ERROR" << endl;
    }
}

void BaseDatos::hacerInsert(Accion *accion) {
    Tabla *ref = this->tabla->verificar(accion->getTabla()->getId());
    if (accion->getTabla() != NULL && accion->getTabla()->getLista() != NULL) {
        if (accion->getTabla()->getLista()->getID() == "$") {
            accion->getTabla()->setLista(ref->getLista());
        }
        if (accion->getTabla()->verificarIDS() && this->tabla != NULL && accion->getTipoAccion() == "INSERT") {
            if (ref != NULL) {
                if (accion->getTabla()->getLista() != NULL) {
                    if (ref->ingresarDatos(accion->getDato(), accion->getTabla()->getLista())) {
                        cout << endl << "DATOS AGREGADOS CON EXITO" << endl << "*********************************************" << endl;
                    } else {
                        cout << endl << "DATOS SIN AGREGAR" << endl << "*********************************************" << endl;
                    }
                } else {
                    if (ref->ingresarDatos(accion->getDato())) {
                        cout << endl << "DATOS AGREGADOS CON EXITO" << endl << "*********************************************" << endl;
                    } else {
                        cout << endl << "DATOS SIN AGREGAR" << endl << "*********************************************" << endl;
                    }
                }
            }
        } else {
            if (this->tabla == NULL) {
                cout << endl << "SIN TABLAS A EVALUAR" << endl;
            } else {
                cout << endl << "NO SE PUDO INSERTAR LA LINEA, POR UN ERROR" << endl;
            }
        }
    } else {
        cout << endl << "NO SE PUDO INSERTAR LA LINEA, POR UN ERROR" << endl;
    }
}

void BaseDatos::hacerCreate(Accion *accion) {
    if (accion != NULL && accion->getTabla() != NULL && accion->getTipoAccion() == "CREATE") {
        bool aceptado = accion->getTabla()->verificarIDS();
        if (aceptado) {
            if (this->tabla != NULL) {
                this->tabla->agregarTabla(accion->getTabla());
            } else {
                this->tabla = accion->getTabla();
            }
            cout << endl << "Tabla agregada con exito" << endl << "*****************************************" << endl;
        } else {
            cout << endl << "Tabla no agregada por indices repetidos" << endl << "***********************************" << endl;
        }
    } else {
        cout << endl << "Tabla no agregada por problemas en la sintaxis" << endl << "***********************************" << endl;
    }
}

void BaseDatos::mostrarOpciones() {
    cout << "------------------------------" << endl;
    cout << "         BASE DE DATOS        " << endl;
    cout << "|____________________________|" << endl;
    cout << "| 1) Datos de una tabla      |" << endl;
    cout << "| 2) Total de datos          |" << endl;
    cout << "| 4) VER TABLA               |" << endl;
    cout << "| c) CERRAR                  |" << endl;
    cout << "------------------------------" << endl << endl << endl;
}

string BaseDatos::pedirComando() {
    cout << "IngresarComando: " << endl;
    string paran;
    string extra;
    cin>>paran;
    std::getline(std::cin, extra);
    cout << paran << extra;
    paran += extra;
    return paran;
}