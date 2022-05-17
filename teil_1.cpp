// GD-Praktikum:   teil_1.cpp  (Teil 1: Start-Programm)
// Hergenroether / Groch    Last Update: 05.07.2014
#define GL_SILENCE_DEPRECATION

#include <iostream>
//#include <GL/freeglut.h>         //lädt alles für OpenGL
#include <OpenGL/gl.h>
#include <GLUT/glut.h>
#include "Wuerfel.h"
#include "Robot.h"

Robot herbie = Robot();
Wuerfel test = Wuerfel(0.2,0.2,0.2, 0.5,0.5,0.5,  0,0,0,  0,0,0,0);
Wuerfel test2 = Wuerfel(0.2,0.2,0.2, 1,1,1,  0.5,0,0,  0,0,0,0);
int tmp = 0;
double tmps[3];

void Init()
{
    // Hier finden jene Aktionen statt, die zum Progammstart einmalig
    // durchgeführt werden müssen
    glEnable (GL_CULL_FACE) ;
    glFrontFace (GL_CCW) ;
    glCullFace ( GL_BACK ) ;
}
void RenderScene() {

    //glClearColor(1.0, 1.0, 0.0, 1.0); //->zuerst Fearben .. dann ausfuehren
    glClear(GL_COLOR_BUFFER_BIT);
    // Hier befindet sich der Code der in jedem Frame ausgefuehrt werden muss
    glLoadIdentity ();   // Aktuelle Model-/View-Transformations-Matrix zuruecksetzen
    gluPerspective(1,1,1,1);
    gluLookAt(0.1,0.1,0.5,0,0.0,0.0,0,0.1,0);
    herbie.createRobot();
    herbie.rotateRobot(0.0,0,0,5);
    //glScalef(0.6,0.6,0.6);
    //glPushMatrix();
    //test.create();test2.create();
    //glPopMatrix();
    glutSwapBuffers();
}
void Animate (int value)
{
    // Hier werden Berechnungen durchgeführt, die zu einer Animation der Szene
    // erforderlich sind. Dieser Prozess läuft im Hintergrund und wird alle
    // 1000 msec aufgerufen. Der Parameter "value" wird einfach nur um eins
    // inkrementiert und dem Callback wieder uebergeben.
    std::cout << "value=" << value << std::endl;

    //herbie.rotateLeftLeg(value,0,0,0);
    herbie.walk();
    herbie.rotateHead(value,0,1,0);
    herbie.rotateLeftArm(value,0,0,1);
    /*
    if ( tmp == 0 ) {
        tmps[0] = herbie.leftArmTranslate[0];
        tmps[1] = herbie.leftArmTranslate[1];
        tmps[2] = herbie.leftArmTranslate[2];
        herbie.translateLeftArm(0,0,0);
    }
    if ( tmp == 1 ) {
        herbie.rotateLeftArm(value,0,0,0);
    }
    if ( tmp == 2 ) {
        herbie.translateLeftArm(tmps[0],tmps[1],tmps[2]);
    }
    ++tmp;
    if (tmp > 2) {
        tmp = 0;
    }*/
    // RenderScene aufrufen
    glutPostRedisplay();
    // Timer wieder registrieren - Animate wird so nach 10 msec mit value+=1 aufgerufen.
    int wait_msec = 10;
    glutTimerFunc(wait_msec, Animate, ++value);
}
void Reshape(int width,int height)
{
    // Hier finden die Reaktionen auf eine Veränderung der Größe des
    // Graphikfensters statt
}
int main(int argc, char **argv)
{
    glutInit( &argc, argv );                // GLUT initialisieren
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB );
    glutInitWindowSize( 600, 600 );         // Fenster-Konfiguration
    glutCreateWindow( "KonradMucha; FelixRuff" );   // Fenster-Erzeugung
    glutDisplayFunc( RenderScene );         // Zeichenfunktion bekannt machen
    glutReshapeFunc( Reshape );
    // TimerCallback registrieren; wird nach 10 msec aufgerufen mit Parameter 0
    glutTimerFunc( 10, Animate, 0);
    Init();
    glutMainLoop();
    return 0;
}



void createFelix(){
    //F
    glBegin(GL_TRIANGLES);
    glVertex3f(0.0, 1.0, 0.0);
    glVertex3f(0.0, 0.5, 0.0);
    glVertex3f(0.1, 1.0, 0.0);
    glEnd();
    glBegin(GL_TRIANGLES);
    glVertex3f(0.0, 0.5, 0.0);
    glVertex3f(0.1, 0.5, 0.0);
    glVertex3f(0.1, 1.0, 0.0);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex3f(0.1, 1.0, 0.0);
    glVertex3f(0.1, 0.9, 0.0);
    glVertex3f(0.4, 1.0, 0.0);
    glEnd();
    glBegin(GL_TRIANGLES);
    glVertex3f(0.1, 0.9, 0.0);
    glVertex3f(0.4, 0.9, 0.0);
    glVertex3f(0.4, 1.0, 0.0);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex3f(0.1, 0.8, 0.0);
    glVertex3f(0.1, 0.7, 0.0);
    glVertex3f(0.4, 0.8, 0.0);
    glEnd();
    glBegin(GL_TRIANGLES);
    glVertex3f(0.1, 0.7, 0.0);
    glVertex3f(0.4, 0.7, 0.0);
    glVertex3f(0.4, 0.8, 0.0);
    glEnd();

    // R
    glBegin(GL_TRIANGLES);
    glVertex3f(0.5, 1.0, 0.0);
    glVertex3f(0.5, 0.5, 0.0);
    glVertex3f(0.6, 1.0, 0.0);
    glEnd();
    glBegin(GL_TRIANGLES);
    glVertex3f(0.5, 0.5, 0.0);
    glVertex3f(0.6, 0.5, 0.0);
    glVertex3f(0.6, 1.0, 0.0);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex3f(0.6, 1.0, 0.0);
    glVertex3f(0.6, 0.9, 0.0);
    glVertex3f(0.9, 1.0, 0.0);
    glEnd();
    glBegin(GL_TRIANGLES);
    glVertex3f(0.6, 0.9, 0.0);
    glVertex3f(0.9, 0.9, 0.0);
    glVertex3f(0.9, 1.0, 0.0);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex3f(0.6, 0.8, 0.0);
    glVertex3f(0.6, 0.7, 0.0);
    glVertex3f(0.9, 0.8, 0.0);
    glEnd();
    glBegin(GL_TRIANGLES);
    glVertex3f(0.6, 0.7, 0.0);
    glVertex3f(0.9, 0.7, 0.0);
    glVertex3f(0.9, 0.8, 0.0);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex3f(0.8, 1.0, 0.0);
    glVertex3f(0.8, 0.7, 0.0);
    glVertex3f(0.9, 1.0, 0.0);
    glEnd();
    glBegin(GL_TRIANGLES);
    glVertex3f(0.8, 0.7, 0.0);
    glVertex3f(0.9, 0.7, 0.0);
    glVertex3f(0.9, 1.0, 0.0);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex3f(0.9, 0.5, 0.0);
    glVertex3f(1.0, 0.5, 0.0);
    glVertex3f(1.0, 0.8, 0.0);
    glEnd();
    glBegin(GL_TRIANGLES);
    glVertex3f(0.9, 0.8, 0.0);
    glVertex3f(0.9, 0.5, 0.0);
    glVertex3f(1.0, 0.8, 0.0);
    glEnd();

}
void createQuad() {
    glBegin( GL_POLYGON );	// bestimmt Eckpunktestart
    glColor4f( 1.0, 0.0, 0.0, 1.0);
    //glColor4f(GLUT_RED, GLUT_GREEN, GLUT_BLUE, GLUT_ALPHA);          //-> meine addition
    glVertex3f( -0.5, -0.5, -0.5 );  //-> positionen im Koordinatensystem
    glColor4f(0.0, 0.0,1.0, 1.0);
    glVertex3f(  0.5, -0.5, -0.5 );
    glColor4f(0.0, 0.0, 1.0, 1.0);
    glVertex3f(  0.5,  0.5, -0.5 );
    glColor4f( 0.0, 0.0, 1.0, 1.0);
    glVertex3f( -0.5,  0.5, -0.5 );
    glEnd();                 // bestimmt Eckpunkteende
}
void createKonrad() {
    //mein Namen
    //K
    glBegin(GL_TRIANGLES);
    glVertex3f(-1, 0.17, -0.5);
    glVertex3f(-1, 0.0, -0.5);
    glVertex3f(-0.90, 0.17, -0.5);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex3f(-1.0, 0.0, -0.5);
    glVertex3f(-1.0, -0.17, -0.5);
    glVertex3f(-0.90, -0.17, -0.5);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex3f(-1.0, 0.0, -0.5);
    glVertex3f(-0.80, 0.1, -0.5);
    glVertex3f(-0.80, 0.17, -0.5);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex3f(-1.0, 0.0, -0.5);
    glVertex3f(-0.80,- 0.17, -0.5);
    glVertex3f(-0.80,-0.1, -0.5);
    glEnd();
    //M
    glBegin(GL_TRIANGLES);
    glVertex3f(-0.70, -0.17, -0.5);
    glVertex3f(-0.60, -0.17, -0.5);
    glVertex3f(-0.60, 0.17, -0.5);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex3f(-0.6, 0.17, -0.5);
    glVertex3f(-0.5, -0.17, -0.5);
    glVertex3f(-0.4, -0.17, -0.5);
    glEnd();


    glBegin(GL_TRIANGLES);
    glVertex3f(-0.5, -0.17, -0.5);
    glVertex3f(-0.4, -0.17, -0.5);
    glVertex3f(-0.3, 0.17, -0.5);
    glEnd();


    glBegin(GL_TRIANGLES);
    glVertex3f(-0.3, 0.17, -0.5);
    glVertex3f(-0.3, -0.17, -0.5);
    glVertex3f(-0.2, -0.17, -0.5);
    glEnd();


}
void createRobot() {
    //gluOrtho2D(-10,10,-10,10); // not needed!?

    //
    // body
    //
    Wuerfel body = Wuerfel(0.3,0.6,0.1,    1,1,1,  0,0,0,    0,0,0,0);
    //
    // head
    //
    Wuerfel head = Wuerfel(0.2,0.2,0.2,    1,1,1,  0,0.45,0,    0,0,0,0);

    //
    // right arm
    //
    Wuerfel(0.25,0.1,0.1,    1,1,1,  0.325,0.2,0,    0,0,0,0);
    //
    // right under arm
    //
    Wuerfel(0.25,0.1,0.1,    1,1,1,  0.625,0.2,0,    0,0,0,0);
    //
    // left arm
    //
    Wuerfel(0.25,0.1,0.1,    1,1,1,  -0.325,0.2,0,    0,0,0,0);
    //
    // left under arm
    //
    Wuerfel(0.25,0.1,0.1,    1,1,1,  -0.625,0.2,0,    0,0,0,0);

    //
    // right leg
    //
    Wuerfel(0.1,0.35,0.1,    1,1,1,  0.1,-0.525,0,    0,0,0,0);
    //
    // left leg
    //
    Wuerfel(0.1,0.35,0.1,    1,1,1,  -0.1,-0.525,0,    0,0,0,0);
    //
    // hat
    //
    Wuerfel(0.3,0.1,0.1,    1,1,1,  0,0.65,0,    0,0,0,0);
    Wuerfel(0.1,0.15,0.1,    1,1,1,  0,0.75,0,    0,0,0,0);


    //


}
