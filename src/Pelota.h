/*
 * Clase Pelota.
 *  Autores: Raul Cobos y Alvar Soler
 *  
 */
#ifndef PELOTA_H
#define	PELOTA_H

#include <GL/freeglut.h>
#include "Lista.h"
#include "PV2D.h"

class Pelota {
public:

    Pelota();
    Pelota(PV2D centro, PV2D vMov, GLdouble radio);

    /**
     * Avanza la pelota en su dirección una unidad por la velocidad
     */
    void avanza();
    
    /**
     * pinta la pelota en la escena
     */
    void draw();
    
    /**
     * cambia el vector de movimiento de la pelota por su vector Rebote
     * @param incidente
     */
    void rebotar( PV2D incidente);
    
    /**
     * destructor
     */
    virtual ~Pelota();

    /**
     * Devuelve la posicion del centro de la pelota
     * @return 
     */
    PV2D* getCentro();
    
    /**
     * Devuelve el vector de movimiento de la pelota
     * @return 
     */
    PV2D* getMovimiento();
    
private:
    PV2D _centro;
    PV2D _vMov; // Vector de velocidad
    Lista <PV2D> _contorno; // Array de puntos del contorno
    GLdouble _radio;
    void construir();
    Lista<PV2D> avanzarContorno(Lista<PV2D> _vContorno);

};

#endif	/* PELOTA_H */