/* 
 * File:   Escena.h
 * Author: furia
 *
 * Created on 19 de noviembre de 2013, 18:22
 */

#ifndef ESCENA_H
#define	ESCENA_H
#include "Obstaculo.h"
#include "Lista.h"
#include "Pelota.h"
#include "Triangulo.h"
#include "Circulo.h"
//#include "Circulo.h"

class Escena {
public:

    Escena() {
        _p = PV2D(250, 150);
        _vm = PV2D(0, 1).normalizar();
        n = 6;

        _obstaculos[0] = new Circulo(PV2D(350.0, 250.0), 50);
        _obstaculos[1] = new Triangulo(PV2D(200, 100), PV2D(600, 100), PV2D(425, 10));
        _obstaculos[2] = new Triangulo(PV2D(200, 350), PV2D(200, 100), PV2D(100, 250));
        _obstaculos[3] = new Triangulo(PV2D(600, 100), PV2D(600, 350), PV2D(700, 225));
        _obstaculos[4] = new Triangulo(PV2D(425, 500), PV2D(600, 300), PV2D(200, 300));
        _obstaculos[5] = new Triangulo(PV2D(400, 200), PV2D(400, 250), PV2D(600, 125));

        _pelota = Pelota(_p, _vm, 25);


    }

    void draw() {
        // Dibuja obstaculos    
        _pelota.draw();
        //for (int i = 0; i < _lista.numElems(); i++)
        //  _lista.elem(i).draw();
        for (int i = 0; i < n; i++) _obstaculos[i]->draw();
    }

    void step() {

        //double tmin = 0.6;
        PV2D* normal;
        bool colision = false;
        PV2D _normal;
        double _t;



        for (int i = 0; i < n; i++) {

            bool hayinterseccion = _obstaculos[i]->interseccion(_pelota.getCentro(), _pelota.getMovimiento(), _t, normal);

            if (hayinterseccion) {

                if (_t == 0) {
                    _normal = PV2D(normal->getX(), normal->getY());
                    colision = true;
                }
            }
        }

        if (!colision)
            _pelota.avanza();
        else {
//            _pelota.rebotar(_normal);
//            _pelota.avanza();
//            colision = false;
        }

    }

private:
    Pelota _pelota;
    PV2D _p;
    PV2D _vm;

    Obstaculo * _obstaculos[6];
    GLdouble xRight, xLeft, yTop, yBot;
    int n;

};


#endif	/* ESCENA_H */

