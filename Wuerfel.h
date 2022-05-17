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
            create();
        }
        void create( ) const  {

        GLfloat x = seitenLx / 2.0f;
        GLfloat y = seitenLy / 2.0f;
        GLfloat z = seitenLz / 2.0f;

        glPushMatrix();
        glRotatef(rotateAngle,rotateX,rotateY,rotateZ);
        glScalef(scaleX,scaleY,scaleZ);
        glTranslatef(translX,translY,translZ);


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
        void clear() {
            std::vector<double> tmp{};
            tmp.push_back(seitenLx);tmp.push_back(seitenLy);
            tmp.push_back(seitenLz);tmp.push_back(scaleX);
            tmp.push_back(scaleY);tmp.push_back(scaleZ);
            tmp.push_back(translX);tmp.push_back(translY);
            tmp.push_back(translZ);tmp.push_back(rotateAngle);
            tmp.push_back(rotateX);tmp.push_back(rotateY);
            tmp.push_back(rotateZ);
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
            create();
            seitenLx = tmp.at(0);
            seitenLy = tmp.at(1);
            seitenLz = tmp.at(2);
            scaleX = tmp.at(3);
            scaleY = tmp.at(4);
            scaleZ = tmp.at(5);
            translX = tmp.at(6);
            translY = tmp.at(7);
            translZ = tmp.at(8);
            rotateAngle = tmp.at(9);
            rotateX = tmp.at(10);
            rotateY = tmp.at(11);
            rotateZ = tmp.at(12);
        }
        void rotate(double angle,double x,double y,double z) {
            //clear();
            rotateAngle = angle;
            rotateX = x;
            rotateY = y;
            rotateZ = z;
            //create();
        }
        GLfloat seitenLx;GLfloat seitenLy;GLfloat seitenLz;double scaleX;double scaleY;double scaleZ;
        double translX;double translY;double translZ;double rotateAngle;double rotateX;double rotateY;double rotateZ;
    private:
};

#endif //GDV_WUERFEL_H