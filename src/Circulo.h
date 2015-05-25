/* 
 * File:   Circulo.h
 * Author: usuario_local
 *
 * Created on 11 de noviembre de 2013, 13:37
 */

#ifndef CIRCULO_H
#define	CIRCULO_H

#include "Obstaculo.h"
#include "Lista.h"
#include "Pelota.h"
#include "Triangulo.h"
#include "PV2D.h"

class Circulo : public Obstaculo {
    
public:

    Circulo();
    Circulo(PV2D centro, GLdouble radio);

    virtual bool interseccion(PV2D* p, PV2D* v, double &tIn, PV2D* &normalIn);
    virtual void draw();
        
    
private:
    PV2D _centro;
    GLdouble _radio;
    Lista<PV2D> _contorno;
    GLint _nLados;
    
    void construir();
    
};


#endif	/* CIRCULO_H */

