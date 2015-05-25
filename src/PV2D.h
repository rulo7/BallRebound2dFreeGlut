/**
 * Clase punto.
 * Autores: Raul Cobos y Alvar Soler 
 * 
 * */

#ifndef PUNTO_H
#define	PUNTO_H
#include <math.h>
#include <iostream>

class PV2D {
private:
    GLdouble _x, _y;
public:

    PV2D() {
        this->_x = 0;
        this->_y = 0;
    };

    PV2D(GLfloat x, GLfloat y) {
        this->_x = x;
        this->_y = y;
    };

    GLdouble getX() {
        return _x;
    };

    GLdouble getY() {
        return _y;
    };

    GLdouble distanciaPto2Pto(PV2D pto) {
        return abs(sqrt(pow((this->_x - pto._x), 2.0) + pow((this->_y - pto._y), 2.0)));
    }

    GLdouble modulo() {

        GLdouble sum = pow(this->_x, 2) + pow(this->_y, 2);

        if (sum != 0.0) {
            return sqrt(sum);
        } else {
            return 0.0;
        }

    }

    PV2D normalizar() {
        if (this->modulo() == 0) {
            return PV2D(this->_x, this->_y);
        } else {
            return PV2D(this->_x / this->modulo(), this->_y / this->modulo());
        }
    }

    GLdouble productoEscalar(PV2D v) {
        return (_x * v._x) + (_y * v._y);
    }

    PV2D normalIzq() {
        return PV2D(-this->_y, this->_x);
    }

    PV2D normalDer() {
        return PV2D(this->_y, -this->_x);
    }

    bool esPerpendicular(const PV2D v) {
        return (productoEscalar(v) == 0);
    }

    /**
     * Devuelve el vector de reflejo
     * @param n
     * @return 
     */
    PV2D reflejo(PV2D n) {

        n = n.normalizar();
        PV2D _v = this->normalizar();

        GLdouble a = _v.productoEscalar(n);
        return PV2D(_v.getX() - (2 * a * n.getX()), (_v.getY() - (2 * a * n.getY())));

    }

    void mostrar() {
        std::cout << "(" << _x << "," << _y << ")" << std::endl;
    }
};

#endif	/* PUNTO_H */

