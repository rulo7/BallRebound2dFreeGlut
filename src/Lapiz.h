/**
 * Cabeceras de la clase lápiz.
 * Autores: Raul Cobos y Alvar Soler 
 * 
 * */

#ifndef LAPIZ_H
#define	LAPIZ_H
#include <GL/freeglut.h>
#include "PV2D.h"
#include "Lista.h"

class Lapiz {
public:
    Lapiz();
    Lapiz(PV2D pto, GLdouble direcc);
    virtual ~Lapiz();

    /* Métodos get */
    PV2D getPos();
    GLdouble getDire();
    /* Métodos set */
    void moveTo(PV2D p);
    /**
     * Gira el lapiz al angulo a dado.
     * @param a nuevo angulo
     */
    void turnTo(GLdouble a);
    /* Métodos de movimiento */
    /**
     * Avanza el lapiz una distancia dada en el ángulo en el que se encuentra.
     * @param dist a avanzar
     */
    void avanza(GLdouble dist);
    /**
     * Gira el lapiz direccGiro grados.
     * @param direccGiro grados del giro
     */
    void gira(GLdouble direccGiro);
    /**
     * Getter del recorrido del lapiz.
     * @return Lista<PV2D> con los puntos
     */
    Lista<PV2D> getRecorrido();
private:
    Lista<PV2D> recorrido;
    GLdouble direcc;
};

#endif	/* LAPIZ_H */

