/**
 * 
 * Autores: Raul Cobos y Alvar Soler 
 * Funciones de la clase Lapiz.
 * */
#include "Lapiz.h"
#include "Lista.h"
#include <cmath>
#include <iostream>
#include <GL/freeglut.h>

#define PI 3.14159265

Lapiz::Lapiz() {
    recorrido.ponDr(PV2D(0, 0));

    this->direcc = 0;
}

/**
 *  Constructor del lapiz.
 * @param x coordenada x donde empieza
 * @param y coordenada y donde empieza
 * @param theta angulo con el que empieza
 */
Lapiz::Lapiz(PV2D pto, GLdouble theta) {
    recorrido.ponDr(pto);
    this->direcc = theta;
}

Lapiz::~Lapiz() {
    recorrido.~Lista();
}

/**
 * Avanza el lápiz una distancia dada
 * @param dist que se quiere que avance
 */
void Lapiz::avanza(GLdouble dist) {
    /* Almacenamos la vieja posición para poder dibujar la línea de un punto a otro */
    PV2D vPos = getPos();

    /* Calculamos la nueva posición */
    GLdouble difX, difY;
    /* Transformamos el ángulo a radianes */
    GLdouble a = getDire() / 180.0 * PI;
    difX = cos((double) a) * dist;
    difY = sin((double) a) * dist;
    /* Calculamos la nueva posición */
    PV2D nPos = PV2D(vPos.getX() + difX, vPos.getY() + difY);
    recorrido.ponDr(nPos);

    /* Dibujamos la línea de la posición anterior a la actual*/
    std::cout << "Dibujando línea de (" << vPos.getX() << "," << vPos.getY() << ") a (" << nPos.getX() << "," << nPos.getY() << ")." << std::endl;


}

/**
 * Gira el lapiz thetaGiro grados. this->direcc += thetaGiro;
 * @param thetaGiro
 */
void Lapiz::gira(GLdouble thetaGiro) {
    this->direcc += thetaGiro;
    std::cout << "El angulo del lápiz ha cambiado a : " << this->direcc << std::endl;
}


/* Setters */

/**
 * Cambiamos la posicion actual del lapiz y pintamos si draw.
 * @param p nueva posicion del lapiz
 * 
 */
void Lapiz::moveTo(PV2D p) {
    PV2D uP = recorrido.ultimo(); // Ultimo punto (en el que estamos)
    /* Calculo la distancia entre los dos puntos por el teorema de Euclides */
    GLdouble dist = sqrt((int) pow((p.getX() - uP.getX()), 2) + pow((p.getY() - uP.getY()), 2));
    GLdouble difY = p.getY() - uP.getY();
    GLdouble difX = p.getX() - uP.getX();
    /* Calculo el ángulo con el que tiene que encarar el lapiz para llegar al punto objetivo */
    GLdouble a = atan2(difY, difX); //1 / sin((p.getY() - uP.getY()) / dist); // En radianes 
    //this->direcc = a * 180.0 / PI; // Pasamos a angulos y cambiamos nuestro angulo
    turnTo(a * 180.0 / PI);
    /* Dibujo la linea con la funcion avanza si draw */

    this->avanza(dist);

}

/**
 * Se cambia el angulo a otro dado
 * @param a nuevo ángulo
 */
void Lapiz::turnTo(GLdouble a) {
    this->direcc = a;
    std::cout << "El angulo del lápiz ha cambiado a : " << this->direcc << std::endl;

}


/* Getters */

/**
 * Posicion actual
 * @return Punto pos. actual
 */
PV2D Lapiz::getPos() {
    return recorrido.ultimo();
}

/**
 * Direccion en angulos
 * @return direcc. angulos
 */
GLdouble Lapiz::getDire() {
    return this->direcc;
}

Lista<PV2D> Lapiz::getRecorrido() {
    return this->recorrido;
}