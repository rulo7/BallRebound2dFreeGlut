
#ifndef TRIANGULO_H
#define TRIANGULO_H
#include "Obstaculo.h"
#include "PV2D.h"
#include "freeglut.h"
#include "Pelota.h"

class Triangulo : public Obstaculo {
public:

    Triangulo();

    Triangulo(PV2D v0, PV2D v1, PV2D v2);

    /**
     * Devuelve si existe la interseccion y en caso afirmativo el punto de entrada (Tin) en tHit
     * @param pelota
     * @param thit
     * @param normalImplicada
     * @return 
     */
    bool interseccion(PV2D* p, PV2D* v, double &tIn, PV2D* &normalIn);

    void draw();
private:

    /**
     * Construye el baricentro de un triangulo.
     * @return PV2D del baricentro
     */
    PV2D construirBaricentro();

    PV2D _vertices[3];
    PV2D _normal[3];
    PV2D _baricentro;
};

#endif	/* TRIANGULO_H */

