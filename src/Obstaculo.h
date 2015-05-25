#ifndef OBSTACULO_H
#define	OBSTACULO_H

#include "Obstaculo.h"
#include "Lista.h"
#include "Pelota.h"
#include "PV2D.h"

class Obstaculo {
public:

    virtual bool interseccion(PV2D* p, PV2D* v, double &tIn, PV2D* &normalIn);
    virtual void draw();
};


#endif	/* OBSTACULO_H */

