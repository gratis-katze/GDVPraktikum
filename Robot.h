//
// Created by Felix Ruff on 17.05.22.
//

#ifndef GDV_ROBOT_H
#define GDV_ROBOT_H


#include "Wuerfel.h"

class Robot {
    int walkCounter = 0;
    bool walkForward = true;

public:
    Robot() {

        // body
        //
        body = Wuerfel(0.3,0.6,0.1,    1,1,1,  0,0,0,    0,0,0,0);
        //
        // head
        //
        head = Wuerfel(0.2,0.2,0.2,    1,1,1,  0,0.45,0,    0,0,0,0);

        //
        // right arm
        //
        rightArm1 = Wuerfel(0.2,0.1,0.1,    1,1,1,  0.1,0.0,0,    0,0,0,0);
        //
        // right forearm
        //
        rightArm2 = Wuerfel(0.3,0.1,0.1,    1,1,1,  0.15,0.0,0,    0,0,0,0);
        //
        // left arm
        //
        leftArm1 = Wuerfel(0.2,0.1,0.1,    1,1,1,  -0.1,0.0,0,    0,0,0,0);
        //
        // left forearm
        //
        leftArm2 = Wuerfel(0.3,0.1,0.1,    1,1,1,  -0.15,0.0,0,    0,0,0,0);

        //
        // right leg
        //
        rightLeg = Wuerfel(0.1,0.35,0.1,    1,1,1,  0.1,-0.525,0,    0,0,0,0);
        //
        // left leg
        //
        leftLeg = Wuerfel(0.1,0.35,0.1,    1,1,1,  -0.1,-0.525,0,    0,0,0,0);
        //
        // hat
        //
        /*
        hat1 = Wuerfel(0.3,0.1,0.1,    1,1,1,  0,0.65,0,    0,0,0,0);
        hat2 = Wuerfel(0.1,0.15,0.1,    1,1,1,  0,0.75,0,    0,0,0,0);
        */
    }
    void createRobot() {
        //
        // body
        //
        glPushMatrix();
        glRotatef(robotRotate[0],robotRotate[1],robotRotate[2],robotRotate[3]);
        glScalef(robotScale[0],robotScale[1],robotScale[2]);
        glTranslatef(robotTranslate[0],robotTranslate[1],robotTranslate[2]);
        creatLeftLeg();
        createRightLeg();
        body = Wuerfel(
                body.seitenLx,body.seitenLy,body.seitenLz,
                body.scaleX,body.scaleY,body.scaleZ,
                body.translX,body.translY,body.translZ,
                body.rotateAngle,body.rotateX,body.rotateY,body.rotateZ
                ); body.create();
        //
        // head
        //
        head = Wuerfel(
                head.seitenLx,head.seitenLy,head.seitenLz,
                head.scaleX,head.scaleY,head.scaleZ,
                head.translX,head.translY,head.translZ,
                head.rotateAngle,head.rotateX,head.rotateY,head.rotateZ
        ); head.create();

        createRightArm();
        createLeftArm();

        //
        // leftLeg
        //

        //
        // hat
        //
        hat1 = Wuerfel(
                hat1.seitenLx,hat1.seitenLy,hat1.seitenLz,
                hat1.scaleX,hat1.scaleY,hat1.scaleZ,
                hat1.translX,hat1.translY,hat1.translZ,
                hat1.rotateAngle,hat1.rotateX,hat1.rotateY,hat1.rotateZ
        ); hat1.create();
        hat2 = Wuerfel(
                hat2.seitenLx,hat2.seitenLy,hat2.seitenLz,
                hat2.scaleX,hat2.scaleY,hat2.scaleZ,
                hat2.translX,hat2.translY,hat2.translZ,
                hat2.rotateAngle,hat2.rotateX,hat2.rotateY,hat2.rotateZ
        ); hat2.create();
        glPopMatrix();
    }
    void walk() {
        rotateLeftLeg(walkCounter, 0, 0, 0);
        rotateRightLeg(-walkCounter, 0, 0, 0);
        if (walkForward) {
         ++walkCounter;
        } else {
            --walkCounter;
        }
        if (walkForward) {
            if (walkCounter > 35) {
                walkForward = false;
            }
        } else {
            if (walkCounter <  (-35)) {
                walkForward = true;
            }
        }
    }
    void creatLeftLeg() {
        glPushMatrix();
        glTranslatef(leftLegTranslate[0],leftLegTranslate[1],leftLegTranslate[2]);
        glRotatef(leftLegRotate[0],leftLegRotate[1],leftLegRotate[2],leftLegRotate[3]);
        glScalef(leftLegScale[0],leftLegScale[1],leftLegScale[2]);
        leftLeg = Wuerfel(
                leftLeg.seitenLx,leftLeg.seitenLy,leftLeg.seitenLz,
                leftLeg.scaleX,leftLeg.scaleY,leftLeg.scaleZ,
                leftLeg.translX,leftLeg.translY,leftLeg.translZ,
                leftLeg.rotateAngle,leftLeg.rotateX,leftLeg.rotateY,leftLeg.rotateZ
        ); leftLeg.create();
        glPopMatrix();
    }
    void createRightLeg() {
        glPushMatrix();
        glTranslatef(rightLegTranslate[0],rightLegTranslate[1],rightLegTranslate[2]);
        glRotatef(rightLegRotate[0],rightLegRotate[1],rightLegRotate[2],rightLegRotate[3]);
        glScalef(rightLegScale[0],rightLegScale[1],rightLegScale[2]);
        rightLeg = Wuerfel(
                rightLeg.seitenLx,rightLeg.seitenLy,rightLeg.seitenLz,
                rightLeg.scaleX,rightLeg.scaleY,rightLeg.scaleZ,
                rightLeg.translX,rightLeg.translY,rightLeg.translZ,
                rightLeg.rotateAngle,rightLeg.rotateX,rightLeg.rotateY,rightLeg.rotateZ
        ); rightLeg.create();
        glPopMatrix();
    }
    void createLeftArm() {
        //
        // leftArm1
        //
        glPushMatrix();
        glTranslatef(leftArmTranslate[0],leftArmTranslate[1],leftArmTranslate[2]);
        glRotatef(leftArmRotate[0],leftArmRotate[1],leftArmRotate[2],leftArmRotate[3]);
        glScalef(leftArmScale[0],leftArmScale[1],leftArmScale[2]);
        leftArm1 = Wuerfel(
                leftArm1.seitenLx,leftArm1.seitenLy,leftArm1.seitenLz,
                leftArm1.scaleX,leftArm1.scaleY,leftArm1.scaleZ,
                leftArm1.translX,leftArm1.translY,leftArm1.translZ,
                leftArm1.rotateAngle,leftArm1.rotateX,leftArm1.rotateY,leftArm1.rotateZ
        ); leftArm1.create();
        //
        // leftArm2
        //
        glPushMatrix();
        glTranslatef(leftForearmTranslateArray[0],leftForearmTranslateArray[1],leftForearmTranslateArray[2]);
        glRotatef(leftForearmRotateArray[0],leftForearmRotateArray[1],leftForearmRotateArray[2],leftForearmRotateArray[3]);
        leftArm2 = Wuerfel(
                leftArm2.seitenLx,leftArm2.seitenLy,leftArm2.seitenLz,
                leftArm2.scaleX,leftArm2.scaleY,leftArm2.scaleZ,
                leftArm2.translX,leftArm2.translY,leftArm2.translZ,
                leftArm2.rotateAngle,leftArm2.rotateX,leftArm2.rotateY,leftArm2.rotateZ
        ); leftArm2.create();
        glPopMatrix();
        glPopMatrix();
    }
    void createRightArm() {
        glPushMatrix();
        glTranslatef(rightArmTranslate[0],rightArmTranslate[1],rightArmTranslate[2]);
        glRotatef(rightArmRotate[0],rightArmRotate[1],rightArmRotate[2],rightArmRotate[3]);
        glScalef(rightArmScale[0],rightArmScale[1],rightArmScale[2]);
        //
        // rightArm1
        //
        rightArm1 = Wuerfel(
                rightArm1.seitenLx,rightArm1.seitenLy,rightArm1.seitenLz,
                rightArm1.scaleX,rightArm1.scaleY,rightArm1.scaleZ,
                rightArm1.translX,rightArm1.translY,rightArm1.translZ,
                rightArm1.rotateAngle,rightArm1.rotateX,rightArm1.rotateY,rightArm1.rotateZ
        ); rightArm1.create();
        //
        // rightArm2
        //
        glPushMatrix();
        glTranslatef(rightForearmTranslateArray[0],rightForearmTranslateArray[1],rightForearmTranslateArray[2]);
        glRotatef(rightForearmRotateArray[0],rightForearmRotateArray[1],rightForearmRotateArray[2],rightForearmRotateArray[3]);
        rightArm2 = Wuerfel(
                rightArm2.seitenLx,rightArm2.seitenLy,rightArm2.seitenLz,
                rightArm2.scaleX,rightArm2.scaleY,rightArm2.scaleZ,
                rightArm2.translX,rightArm2.translY,rightArm2.translZ,
                rightArm2.rotateAngle,rightArm2.rotateX,rightArm2.rotateY,rightArm2.rotateZ
        ); rightArm2.create();
        glPopMatrix();
        glPopMatrix();
    }
    void scaleRobot(double x,double y,double z) {
        robotScale[2] = z;
        robotScale[1] = y;
        robotScale[0] = x;
    }
    void rotateRobot(double x,double y,double z, double v) {
        robotRotate[0] = v;
        robotRotate[1] = x;
        robotRotate[2] = y;
        robotRotate[3] = z;
    }
    void rotateLeftLeg(double ang, double xx, double yy, double zz) {
        leftLegRotate[0] = ang;
        leftLegRotate[1] = xx;
        leftLegRotate[2] = yy;
        leftLegRotate[3] = zz;
    }
    void rotateLeftArm(double ang, double xx, double yy, double zz) {
        leftArmRotate[0] = ang;
        leftArmRotate[1] = xx;
        leftArmRotate[2] = yy;
        leftArmRotate[3] = zz;
    }
    void rotateRightLeg(double ang, double xx, double yy, double zz) {
        /*
        double x,y,z;
        x = rightLeg.translX;
        y = rightLeg.translY;
        z = rightLeg.translZ;
        rightLeg.translate(0,-0.35,0);
        rightLeg.rotate(ang,xx,yy,zz);
        rightLeg.translate(x,y,z);
         */
        rightLegRotate[0] = ang;
        rightLegRotate[1] = xx;
        rightLegRotate[2] = yy;
        rightLegRotate[3] = zz;
    }
    void rotateBody(double ang, double xx, double yy, double zz) {
        body.rotate(ang, xx, yy, zz);
    }
    void rotateHead(double ang, double xx, double yy, double zz) {

        head.rotateAngle = ang;
        head.rotateX = xx;
        head.rotateY = yy;
        head.rotateZ = zz;


    }
    void rotateRightArm(double ang, double xx, double yy, double zz) {
        rightArmRotate[0] = ang;
        rightArmRotate[1] = xx;
        rightArmRotate[2] = yy;
        rightArmRotate[3] = zz;
    }
    void rightForearmRotate(double ang, double xx, double yy, double zz) {
        rightForearmRotateArray[1] = xx;
        rightForearmRotateArray[2] = yy;
        rightForearmRotateArray[3] = zz;
        rightForearmRotateArray[0] = ang;
    }
    void leftForearmRotate(double ang, double xx, double yy, double zz) {
        leftForearmRotateArray[1] = xx;
        leftForearmRotateArray[2] = yy;
        leftForearmRotateArray[3] = zz;
        leftForearmRotateArray[0] = ang;
    }
    double robotScale[3] = {1,1,1};
    double robotTranslate[3] = {0,0,0};
    double robotRotate[4] = {0,0,0,0};

    double leftArmScale[3] = {1,1,1};
    double leftArmTranslate[3] = {-0.2,0.2,0};
    double leftArmRotate[4] = {0,0,0,0};

    double rightArmScale[3] = {1,1,1};
    double rightArmTranslate[3] = {0.2,0.2,0};
    double rightArmRotate[4] = {0,0,0,0};
    double rightForearmRotateArray[4] = {0,0,0,0};
    double rightForearmTranslateArray[3] = {0.25,0,0};

    double leftForearmTranslateArray[3] = {-0.25,0,0};
    double leftForearmRotateArray[4] = {0,0,0,0};

    double leftLegScale[3] = {1,1,1};
    double leftLegTranslate[3] = {0.0,0.0,0};
    double leftLegRotate[4] = {0,0,0,0};

    double rightLegScale[3] = {1,1,1};
    double rightLegTranslate[3] = {0.0,0.0,0};
    double rightLegRotate[4] = {0,0,0,0};

private:
    Wuerfel body, head, leftArm1, leftArm2, rightArm1, rightArm2, leftLeg, rightLeg, hat1, hat2;
};


#endif //GDV_ROBOT_H
