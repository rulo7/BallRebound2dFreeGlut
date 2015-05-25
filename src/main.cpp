#include <GL/glu.h>
#include <GL/gl.h>
#include <GL/freeglut.h> // make -lglut
//#include <GL/glut.h>
#include <iostream>

#include "Pelota.h"
#include "Triangulo.h"
#include "Escena.h"

using namespace std;

// Freeglut parameters
// Flag telling us to keep processing events
// bool continue_in_main_loop= true; //(**)

// Viewport size
int WIDTH = 850, HEIGHT = 450;

// Scene visible area size
GLdouble xLeft = 0.0, xRight = 850.0, yBot = 0.0, yTop = 450.0;
GLdouble zoomF = 1.0;
// Pelota
Escena escena;

bool automatico = false;
unsigned int ms = 0.25;

void intitGL() {

    glClearColor(0.0, 1.0, 0.0, 1.0);
    glColor3f(1.0, 0.0, 0.0);

    glPointSize(4.0);
    glLineWidth(2.0);

    // Viewport
    glViewport(0, 0, WIDTH, HEIGHT); // ViewPort empieza en 0,0 con altura y ancho dados

    // Model transformation
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Scene Visible Area
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(xLeft, xRight, yBot, yTop);
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    escena.draw();
    glFlush();
    glutSwapBuffers();
}

void resize(int newWidth, int newHeight) {
    GLdouble difWi = (WIDTH - newWidth) / zoomF;
    GLdouble difHe = (HEIGHT - newHeight) / zoomF;

    //Resize Viewport
    WIDTH = newWidth;
    HEIGHT = newHeight;

    glViewport(0, 0, WIDTH, HEIGHT);

    yTop -= difHe / 2.0;
    yBot += difHe / 2.0;
    xRight -= difWi / 2.0;
    xLeft += difWi / 2.0;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(xLeft, xRight, yBot, yTop);

}

void zoom(GLdouble f) {
    zoomF *= f;
    GLdouble nuevoAncho = (xRight - xLeft) / f;
    GLdouble nuevoAlto = (yTop - yBot) / f;

    GLdouble centroX = (xRight + xLeft) / 2.0;
    GLdouble centroY = (yTop + yBot) / 2.0;

    xRight = centroX + nuevoAncho / 2.0;
    xLeft = centroX - nuevoAncho / 2.0;
    yBot = centroY - nuevoAlto / 2.0;
    yTop = centroY + nuevoAlto / 2.0;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(xLeft, xRight, yBot, yTop);
    std::cout << "Zoom: " << zoomF << std::endl;
}

void click(int button, int state, int x, int y) {
    // Multiplicamos la coordenada que nos dan por el factor del zoom
    // en las x se suma xLeft y en las y se resta el valor de yTop

    cout << "CLICK: ";
    cout << "Boton: " << button << " State: " << state << "  " << x << " " << y << endl;

    if (button == 0 && state == 1) {
        float xN = xLeft + x*zoomF;
        float yN = yTop - y *zoomF;
        cout << "Calc:  " << xN << " " << yN << endl;
    }


}

void key(unsigned char key, int x, int y) {

    bool need_redisplay = true;

    switch (key) {
        case 27: /* Escape key */
            //continue_in_main_loop = false; // (**)
            glutLeaveMainLoop(); //Freeglut's sentence for stopping glut's main loop (*)
            break;
        case 'a':
            escena.step();
            break;
        case 's':
            automatico = !automatico;
            break;
        case '+':
            zoom(1.2);
            break;
        case '-':
            // Zoom out 0.9
            zoom(0.8);
            break;
        default:
            need_redisplay = false;
            break;
    }//switch

    if (need_redisplay)
        glutPostRedisplay();
}

void keySpecial(int key, int x, int y) {
    bool need_redisplay = true;
    /* Para explorar la escena */
    switch (key) {
        case GLUT_KEY_UP:
            yBot += HEIGHT * 0.1;
            yTop += HEIGHT * 0.1;
            break;
        case GLUT_KEY_DOWN:
            yBot -= HEIGHT * 0.1;
            yTop -= HEIGHT * 0.1;
            break;
        case GLUT_KEY_RIGHT:
            xLeft += WIDTH * 0.1;
            xRight += WIDTH * 0.1;
            break;
        case GLUT_KEY_LEFT:
            xLeft -= WIDTH * 0.1;
            xRight -= WIDTH * 0.1;
            break;

        default:
            need_redisplay = false;
            break;
    }//switch

    if (need_redisplay) {
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluOrtho2D(xLeft, xRight, yBot, yTop);
        glutPostRedisplay();

    }
}

void tick(int value) {
    //cout << "TICK: " << value << endl;
    if (automatico) {
        escena.step();
        glutPostRedisplay();
    }
    glutTimerFunc(ms, tick, value + 1);
}

int main(int argc, char *argv[]) {
    cout << "Starting console..." << endl;

    int my_window; //my window's identifier

    //Initialization
    glutInitWindowSize(WIDTH, HEIGHT);
    glutInitWindowPosition(140, 140);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInit(&argc, argv);

    //Window construction
    my_window = glutCreateWindow("Pelota");
    escena = Escena();


    //Callback registration
    glutReshapeFunc(resize);
    glutKeyboardFunc(key);
    glutSpecialFunc(keySpecial);
    glutMouseFunc(click);
    glutDisplayFunc(display);
    glutTimerFunc(ms, tick, 1);
    //OpenGL basic setting
    intitGL();

    // Freeglut's main loop can be stopped executing (**)
    //while ( continue_in_main_loop )
    //  glutMainLoopEvent();

    // Classic glut's main loop can be stopped after X-closing the window,
    // using the following freeglut's setting (*)
    glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_CONTINUE_EXECUTION);

    // Classic glut's main loop can be stopped in freeglut using (*)
    glutMainLoop();

    // We would never reach this point using classic glut
    system("PAUSE");

    return 0;
}