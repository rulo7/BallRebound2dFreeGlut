#include "Circulo.h"
#include "Lapiz.h"

Circulo::Circulo() {
    Circulo(PV2D(0, 0), 10);
}

Circulo::Circulo(PV2D centro, GLdouble radio) {
    _centro = centro;
    _radio = radio;
    _contorno = Lista<PV2D>();

    construir();
    this->draw();
}

void Circulo::construir() {

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

void Circulo::draw() {
    glColor3d(0.0, 0.0, 1.0);

    /*Contorno*/
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < _contorno.numElems() - 1; i++) {

        glVertex2d(_contorno.elem(i).getX(), _contorno.elem(i).getY());
        glVertex2d(_contorno.elem(i + 1).getX(), _contorno.elem(i + 1).getY());
    }
    glEnd();

}

bool Circulo::interseccion(PV2D* p, PV2D* v, double &tIn, PV2D* &normalIn) {

    PV2D CP = PV2D(p->getX() - _centro.getX(), p->getY() - _centro.getY());
    GLdouble A = v->productoEscalar(*v);
    GLdouble B = v->productoEscalar(CP);
    GLdouble C = CP.productoEscalar(CP) - pow(_radio, 2);

    GLdouble incr = pow(B, 2) - (4 * A * C);



    if (incr < 0) {
        return false;
    }


    if (incr == 0) {
        tIn = -B / (2 * A);
    } else {

        double t1 = (-B - sqrt(incr)) / (2 * A);
        double t2 = (-B + sqrt(incr)) / (2 * A);

        if (t1 < t2) {
            tIn = t1;
        } else {
            tIn = t2;
        }
    }

    PV2D _cp = PV2D(p->getX() - _centro.getX(), p->getY() - _centro.getY()).normalizar();
    normalIn = &_cp;

    return true;
}