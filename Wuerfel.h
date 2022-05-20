#include <iostream>
#include <OpenGL/gl.h>
#include <GLUT/glut.h>
#include <vector>

#ifndef GDV_WUERFEL_H
#define GDV_WUERFEL_H

class Wuerfel {
    public:
        Wuerfel(){
            seitenLx = 0;
            seitenLy = 0;
            seitenLz = 0;
            scaleX = 0;
            scaleY = 0;
            scaleZ = 0;
            translX = 0;
            translY = 0;
            translZ = 0;
            rotateAngle = 0;
            rotateX = 0;
            rotateY = 0;
            rotateZ = 0;
        }
        Wuerfel( GLfloat seitenLxx,GLfloat seitenLyy,GLfloat seitenLzz,double scaleXX, double scaleYY, double scaleZZ,
                 double translXX, double translYY, double translZZ, double rotateAnglee, double rotateXX, double rotateYY, double rotateZZ) {
            seitenLx = seitenLxx;
            seitenLy = seitenLyy;
            seitenLz = seitenLzz;
            scaleX = scaleXX;
            scaleY = scaleYY;
            scaleZ = scaleZZ;
            translX = translXX;
            translY = translYY;
            translZ = translZZ;
            rotateAngle = rotateAnglee;
            rotateX = rotateXX;
            rotateY = rotateYY;
            rotateZ = rotateZZ;
        }
        void create( ) const  {

        GLfloat x = seitenLx / 2.0f;
        GLfloat y = seitenLy / 2.0f;
        GLfloat z = seitenLz / 2.0f;

        glPushMatrix();
        glTranslatef(translX,translY,translZ);
        glRotatef(rotateAngle,rotateX,rotateY,rotateZ);
        glScalef(scaleX,scaleY,scaleZ);

        glBegin(GL_POLYGON);   //Vorderseite
        glColor4f(1.0f,0.0f,0.0f,1.0f);	//ROT
        glVertex3f(-x,-y,+z);
        glColor4f(1.0f,0.0f,0.0f,1.0f);	//ROT
        glVertex3f(+x,-y,+z);
        glColor4f(1.0f,0.0f,0.0f,1.0f);	//ROT
        glVertex3f(+x,+y,+z);
        glColor4f(1.0f,0.0f,0.0f,1.0f);	//ROT
        glVertex3f(-x,+y,+z);
        glEnd();


        glBegin(GL_POLYGON);   //Rechte Seite
        glColor4f(1.0f,1.0f,1.0f,1.0f); //WEISS
        glVertex3f(+x,-y,+z);
        glColor4f(1.0f,1.0f,1.0f,1.0f); //WEISS
        glVertex3f(+x,-y,-z);
        glColor4f(1.0f,1.0f,1.0f,1.0f); //WEISS
        glVertex3f(+x,+y,-z);
        glColor4f(1.0f,1.0f,1.0f,1.0f); //WEISS
        glVertex3f(+x,+y,+z);
        glEnd();


        glBegin(GL_POLYGON);   //Rueckseite
        glColor4f(0.0f,1.0f,1.0f,1.0f); //CYAN
        glVertex3f(+x,+y,-z);
        glColor4f(0.0f,1.0f,1.0f,1.0f); //CYAN
        glVertex3f(+x,-y,-z);
        glColor4f(0.0f,1.0f,1.0f,1.0f); //CYAN
        glVertex3f(-x,-y,-z);
        glColor4f(0.0f,1.0f,1.0f,1.0f); //CYAN
        glVertex3f(-x,+y,-z);
        glEnd();


        glBegin(GL_POLYGON);   //Linke Seite
        glColor4f(0.0f,0.0f,1.0f,1.0f); //BLAU
        glVertex3f(-x,+y,-z);
        glColor4f(0.0f,0.0f,1.0f,1.0f); //BLAU
        glVertex3f(-x,-y,-z);
        glColor4f(0.0f,0.0f,1.0f,1.0f); //BLAU
        glVertex3f(-x,-y,+z);
        glColor4f(0.0f,0.0f,1.0f,1.0f); //BLAU
        glVertex3f(-x,+y,+z);
        glEnd();

        glBegin(GL_POLYGON);   //Deckflaeche
        glColor4f(1.0f,0.0f,1.0f,1.0f); //MAGENTA
        glVertex3f(-x,+y,+z);
        glColor4f(1.0f,0.0f,1.0f,1.0f); //MAGENTA
        glVertex3f(+x,+y,+z);
        glColor4f(1.0f,0.0f,1.0f,1.0f); //MAGENTA
        glVertex3f(+x,+y,-z);
        glColor4f(1.0f,0.0f,1.0f,1.0f); //MAGENTA
        glVertex3f(-x,+y,-z);
        glEnd();


        glBegin(GL_POLYGON);   //Bodenflaeche
        glColor4f(1.0f,1.0f,0.0f,1.0f); //GELB
        glVertex3f(-x,-y,-z);
        glColor4f(1.0f,1.0f,0.0f,1.0f); //GELB
        glVertex3f(+x,-y,-z);
        glColor4f(1.0f,1.0f,0.0f,1.0f); //GELB
        glVertex3f(+x,-y,+z);
        glColor4f(1.0f,1.0f,0.0f,1.0f); //GELB
        glVertex3f(-x,-y,+z);
        glEnd();

        glPopMatrix();

        return;
    }
        void rotate(double angle,double x,double y,double z) {
            rotateAngle = angle;
            rotateX = x;
            rotateY = y;
            rotateZ = z;
        }
        void translate(double x,double y,double z) {
            translX = x;
            translY = y;
            translZ = z;
        }
        GLfloat seitenLx;GLfloat seitenLy;GLfloat seitenLz;double scaleX;double scaleY;double scaleZ;
        double translX;double translY;double translZ;double rotateAngle;double rotateX;double rotateY;double rotateZ;
    private:
};

#endif //GDV_WUERFEL_H