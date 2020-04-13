/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Dato.cpp
 * Author: mari2bar
 * 
 * Created on 2 de abril de 2020, 16:26
 */

#include "Dato.h"

Dato::Dato() {
    this->altura = 0;
    this->alturad = 0;
    this->alturai = 0;
    this->tuplad =NULL;
    this->tuplai = NULL;
    this->derecho = NULL;
    this->izquierdo = NULL;
    this->padre = NULL;
    this->tipo = "";
}

Dato::Dato(const Dato& orig) {
    
}

Dato::~Dato() {
}

void Dato::sumarHijoDerecho() {
    this->alturad = this->alturad + 1;
    if (this->alturai < this->alturad && this->padre != NULL) {
        if (this->padre->getDerecho() == this) {
            this->padre->sumarHijoDerecho();
        } else {
            this->padre->sumarHijoIzquierdo();
        }
    }
}

void Dato::sumarHijoIzquierdo() {
    this->alturai = this->alturai + 1;
    if (this->alturad <this->alturai && this->padre != NULL) {
        if (this->padre->getDerecho() == this) {
            this->padre->sumarHijoDerecho();
        } else {
            this->padre->sumarHijoIzquierdo();
        }
    }
}

Dato *Dato::Equilibrar() {
    int resta = this->alturad - this->alturai;
    int sig = 0;
    Dato *padre = this->padre;
    if (resta > 1) {
        sig = this->derecho->getAlturaD() - this->derecho->getAlturaI();
        if (sig >= 0) {
            this->RotacionIzquierda();
        } else {
            this->RotacionDI();
        }
    } else if (resta<-1) {
        sig = this->izquierdo->getAlturaD() - this->izquierdo->getAlturaI();
        if (sig <= 0) {
            this->RotacionDerecha();
        } else {
            this->RotacionID();
        }
    } else {
        if (padre != NULL) {
            if (padre->getDerecho() == this) {
                padre->setAlturad(padre->getAlturaD() + 1);
            } else if (padre->getIzquierdo() == this) {
                padre->setAlturai(padre->getAlturaI() + 1);
            }
        }
    }
    if (padre != NULL) {
        return padre->Equilibrar();
    } else {
        if (this->padre == NULL) {
            return this;
        } else {
            return this->padre;
        }
    }

}

void Dato::RotacionDerecha() {
    Dato *d = this->getIzquierdo()->getDerecho();
    Dato *p = this->getPadre();
    if (p != NULL) {
        if (p->getDerecho() == this) {
            p->setDerecho(this->izquierdo);
        } else {
            p->setIzquierdo(this->izquierdo);
        }
        this->izquierdo->setPadre(p);
        this->izquierdo->setDerecho(this);
        this->setPadre(this->izquierdo);
        if (d != NULL) {
            this->setIzquierdo(d);
            d->setPadre(this);
        } else {
            this->setIzquierdo(NULL);
        }
        int al = this->padre->alturad;
        this->padre->setAlturad(this->alturad + 1);
        this->alturai = al;
    } else {
        this->izquierdo->setPadre(NULL);
        this->izquierdo->setDerecho(this);
        this->setPadre(this->izquierdo);
        if (d != NULL) {
            this->setIzquierdo(d);
            d->setPadre(this);
        } else {
            this->setIzquierdo(NULL);
        }
        int al = this->padre->alturad;
        this->padre->setAlturad(this->alturad + 1);
        this->alturai = al;
    }
}

void Dato::RotacionIzquierda() {
    Dato *i = this->getDerecho()->getIzquierdo();
    Dato *p = this->getPadre();
    if (p != NULL) {
        if (p->getDerecho() == this) {
            p->setDerecho(this->derecho);
        } else {
            p->setIzquierdo(this->derecho);
        }
        this->derecho->setPadre(p);
        this->derecho->setIzquierdo(this);
        this->setPadre(this->derecho);
        if (i != NULL) {
            this->setDerecho(i);
            i->setPadre(this);
        } else {
            this->setIzquierdo(NULL);
        }
        int al = this->padre->alturai;
        this->padre->setAlturai(this->alturai + 1);
        this->alturad = al;
    } else {
        this->derecho->setPadre(NULL);
        this->derecho->setIzquierdo(this);
        this->setPadre(this->derecho);
        if (i != NULL) {
            this->setDerecho(i);
            i->setPadre(this);
        } else {
            this->setDerecho(NULL);
        }
        int al = this->padre->alturai;
        this->padre->setAlturad(this->alturai + 1);
        this->alturad = al;
    }
}

void Dato::RotacionDI() {
    this->derecho->RotacionDerecha();
    this->RotacionIzquierda();
}

void Dato::RotacionID() {
    this->izquierdo->RotacionIzquierda();
    this->RotacionDerecha();
}

void Dato::agregarTupla(Dato *tupla) {
    if (tupla != NULL) {
        if (this->tuplad != NULL) {
            this->tuplad->agregarTupla(tupla);
        } else {
            this->tuplad = tupla;
            tupla->setTuplai(this);
        }
    }
}
