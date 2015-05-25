/*
 * Clase Pelota.
 *  Autores: Raul Cobos y Alvar Soler
 *  
 */
#include <GL/freeglut.h>
#include <iostream>

#include "PV2D.h"
#include "Pelota.h"
#include "Lapiz.h"
#include <math.h>

Pelota::Pelota() {
    Pelota(PV2D(0, 0), PV2D(0, 0), 10);
}

Pelota::Pelota(PV2D centro, PV2D vMov, GLdouble radio) {
    _centro = centro;
    _radio = radio;
    _vMov = vMov;
    _contorno = Lista<PV2D>();

    construir();
    this->draw();
}

void Pelota::construir() {

    GLdouble PI = 3.1415926;
    int nLados = 20;
    GLdouble alfa = (2.0 * PI) / nLados;
    GLdouble beta = (PI - alfa) / 2.0;
    GLdouble gamma = PI - beta;
    GLdouble lado = (2.0 * _radio) * cos(beta);

    Lapiz l = Lapiz();

    l.moveTo(_centro);
    l.turnTo(0.0);
    l.avanza(_radio);
    l.gira(gamma * 180.0 / PI);

    _contorno.ponDr(l.getPos());

    for (int i = 1; i < nLados; i++) {

        l.avanza(lado);
        _contorno.ponDr(l.getPos());
        l.gira(alfa * 180.0 / PI);
    }

}

void Pelota::avanza() {
    _centro = PV2D(_centro.getX() + _vMov.getX(), _centro.getY() + _vMov.getY());
    _contorno = avanzarContorno(_contorno);
}

Lista<PV2D> Pelota::avanzarContorno(Lista<PV2D> _vContorno) {
    Lista<PV2D> _conAux = Lista<PV2D>();
    for (int i = 0; i < _vContorno.numElems(); i++)
        _conAux.ponDr(PV2D(_vContorno.elem(i).getX() + _vMov.getX(), _vContorno.elem(i).getY() + _vMov.getY()));
    return _conAux;
}

void Pelota::rebotar(PV2D superficie) {
    _vMov = _vMov.reflejo(superficie);
}

void Pelota::draw() {
    glColor3d(0.0, 0.0, 1.0);

    /*Contorno*/
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < _contorno.numElems() - 1; i++) {

        glVertex2d(_contorno.elem(i).getX(), _contorno.elem(i).getY());
        glVertex2d(_contorno.elem(i + 1).getX(), _contorno.elem(i + 1).getY());
    }
    glEnd();

    /* Vector de movimiento*/
    glBegin(GL_LINES);
    glColor3d(0.0, 0.0, 0.0);
    glVertex2d(_centro.getX(), _centro.getY());
    glVertex2d((_centro.getX() + (_vMov.normalizar().getX() * _radio)), (_centro.getY() + (_vMov.normalizar().getY() * _radio)));
    glEnd();

    /* Normal izquierda */
    glBegin(GL_LINES);
    glColor3d(1.0, 0.0, 0.0);
    glVertex2d(_centro.getX(), _centro.getY());
    PV2D normal = _vMov.normalIzq();
    glVertex2d((_centro.getX() + (normal.normalizar().getX() * _radio)), (_centro.getY() + (normal.normalizar().getY() * _radio)));
    glEnd();
}

PV2D* Pelota::getCentro() {

    return &_centro;
}

PV2D* Pelota::getMovimiento() {

    return &_vMov;
}

Pelota::~Pelota() {
}