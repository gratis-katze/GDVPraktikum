// GD-Praktikum:   teil_1.cpp  (Teil 1: Start-Programm)
// Hergenroether / Groch    Last Update: 05.07.2014

#include <iostream>
//#include <GL/freeglut.h>         //lädt alles für OpenGL
#include <OpenGL/gl.h>
#include <GLUT/glut.h>

void Init()
{
    // Hier finden jene Aktionen statt, die zum Progammstart einmalig
    // durchgeführt werden müssen
    glEnable (GL_CULL_FACE) ;
    glFrontFace (GL_CCW) ;
    glCullFace ( GL_BACK ) ;

}

void createFelix(){

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
void RenderScene() {    //Zeichenfunktion
    glClearColor(1.0, 1.0, 0.0, 1.0); //->zuerst Fearben .. dann ausfuehren
    glClear(GL_COLOR_BUFFER_BIT);
    // Hier befindet sich der Code der in jedem Frame ausgefuehrt werden muss
    glLoadIdentity ();   // Aktuelle Model-/View-Transformations-Matrix zuruecksetzen
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

    createKonrad();
    glutSwapBuffers();

}

void Reshape(int width,int height)
{
    // Hier finden die Reaktionen auf eine Veränderung der Größe des
    // Graphikfensters statt
}

void Animate (int value)
{
    // Hier werden Berechnungen durchgeführt, die zu einer Animation der Szene
    // erforderlich sind. Dieser Prozess läuft im Hintergrund und wird alle
    // 1000 msec aufgerufen. Der Parameter "value" wird einfach nur um eins
    // inkrementiert und dem Callback wieder uebergeben.
    std::cout << "value=" << value << std::endl;
    // RenderScene aufrufen
    glutPostRedisplay();
    // Timer wieder registrieren - Animate wird so nach 10 msec mit value+=1 aufgerufen.
    int wait_msec = 10;
    glutTimerFunc(wait_msec, Animate, ++value);
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
