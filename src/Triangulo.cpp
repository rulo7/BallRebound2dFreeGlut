#include "Triangulo.h"

Triangulo::Triangulo() {
}

Triangulo::Triangulo(PV2D v0, PV2D v1, PV2D v2) {
    _vertices[0] = v0;
    _vertices[1] = v1;
    _vertices[2] = v2;
    _baricentro = construirBaricentro();
    _normal[0] = PV2D(v2.getX() - v0.getX(), v2.getY() - v0.getY()).normalDer().normalizar();
    _normal[1] = PV2D(v1.getX() - v2.getX(), v1.getY() - v2.getY()).normalDer().normalizar();
    _normal[2] = PV2D(v0.getX() - v1.getX(), v0.getY() - v1.getY()).normalDer().normalizar();
}

bool Triangulo::interseccion(PV2D* p, PV2D* v, double &tIn, PV2D* &normalIn) {

    //creamos valores necesarios        
    GLdouble dist[3];
    GLdouble proj[3];
    int sign[3];

    PV2D aux = v->normalizar();
    PV2D* _v = &aux;

    //Calculamos proj dist y sign

    for (int i = 0; i < 3; i++) {

        dist[i] = PV2D(_vertices[i].getX() - p->getX(), _vertices[i].getY() - p->getY()).productoEscalar(_v->normalIzq());
        proj[i] = PV2D(_vertices[i].getX() - p->getX(), _vertices[i].getY() - p->getY()).productoEscalar(*_v);


        if (dist[i] > 0) {
            sign[i] = 1;
        } else if (dist[i] < 0) {
            sign[i] = -1;
        } else { // dist[i] == 0
            sign[i] = 0;
        }

    }

    int sum = sign[0] + sign[1] + sign[2];

    if (abs(sum) == 3) {
        return false;
    }
    
    
    

    int nHits = 0;
    double hit[3];
    PV2D n[3];

    for (int i = 0; i < 3; i++) {
        int j = (i + 1) % 3;

        if ((sign[i] * sign[j] < 0)) {
            double numerator = (proj[i] * dist[j]) - (dist[i] * proj[j]);
            double denominator = dist[j] - dist[i];

            hit[nHits] = numerator / denominator;
            n[nHits] = PV2D(_vertices[i].getX() - _vertices[j].getX(), _vertices[i].getY() - _vertices[j].getY()).normalIzq().normalizar();
            nHits++;

        }
    }

    if (nHits < 2) {

        for (int k = 0; k < 3; k++) {
            if (sign[k] == 0) {
                hit[nHits] = proj[k];
                n[nHits] = PV2D(_vertices[k].getX() - _baricentro.getX(), _vertices[k].getY() - _baricentro.getY());
                nHits++;
            }
        }
    }

    int m;

    if (hit[0] < hit[1]) {
        m = 0;
    } else {
        m = 1;
    }

    if (hit[2] < hit[m]) {
        m = 2;
    }

    tIn = hit[m];

    normalIn = &n[m];
    return true;


}

void Triangulo::draw() {

    //glColor3f(1.0, 1.0, 0.0);

    glBegin(GL_LINE_LOOP);
    glVertex2d(_vertices[0].getX(), _vertices[0].getY());
    glVertex2d(_vertices[1].getX(), _vertices[1].getY());
    glVertex2d(_vertices[2].getX(), _vertices[2].getY());

    glEnd();
    glColor3f(0.0, 0.0, 0.0);
    /* Normales*/
    glBegin(GL_LINES);

    glVertex2d((_vertices[0].getX() + _vertices[2]. getX()) / 2.0, (_vertices[0].getY() + _vertices[2]. getY()) / 2.0);
    glVertex2d((((_vertices[0].getX() + _vertices[2]. getX()) / 2.0) + _normal[0].getX()* 10.0), ((_vertices[0].getY() + _vertices[2]. getY()) / 2.0) + _normal[0].getY()* 10.0);

    glVertex2d((_vertices[2].getX() + _vertices[1]. getX()) / 2.0, (_vertices[2].getY() + _vertices[1]. getY()) / 2.0);
    glVertex2d((((_vertices[2].getX() + _vertices[1]. getX()) / 2.0) + _normal[1].getX()* 10.0), ((_vertices[1].getY() + _vertices[2]. getY()) / 2.0) + _normal[1].getY()* 10.0);

    glVertex2d((_vertices[1].getX() + _vertices[0]. getX()) / 2.0, (_vertices[1].getY() + _vertices[0]. getY()) / 2.0);
    glVertex2d((((_vertices[1].getX() + _vertices[0]. getX()) / 2.0) + _normal[2].getX() * 10.0), ((_vertices[1].getY() + _vertices[0]. getY()) / 2.0) + _normal[2].getY()* 10.0);

    glEnd();
}

PV2D Triangulo::construirBaricentro() {
    return PV2D((_vertices[0].getX() + _vertices[1].getX() + _vertices[2].getX()) / 3.0,
            (_vertices[0].getY() + _vertices[1].getY() + _vertices[2].getY()) / 3.0);
}
