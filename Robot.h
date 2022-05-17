//
// Created by Felix Ruff on 17.05.22.
//

#ifndef GDV_ROBOT_H
#define GDV_ROBOT_H


#include "Wuerfel.h"

class Robot {
public:
    Robot() {
        //
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
        rightArm1 = Wuerfel(0.25,0.1,0.1,    1,1,1,  0.325,0.2,0,    0,0,0,0);
        //
        // right under arm
        //
        rightArm2 = Wuerfel(0.25,0.1,0.1,    1,1,1,  0.625,0.2,0,    0,0,0,0);
        //
        // left arm
        //
        leftArm1 = Wuerfel(0.25,0.1,0.1,    1,1,1,  -0.325,0.2,0,    0,0,0,0);
        //
        // left under arm
        //
        leftArm2 = Wuerfel(0.25,0.1,0.1,    1,1,1,  -0.625,0.2,0,    0,0,0,0);

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
        hat1 = Wuerfel(0.3,0.1,0.1,    1,1,1,  0,0.65,0,    0,0,0,0);
        hat2 = Wuerfel(0.1,0.15,0.1,    1,1,1,  0,0.75,0,    0,0,0,0);

    }
    void createRobot() {
        //
        // body
        //
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
        //
        // leftArm1
        //
        leftArm1 = Wuerfel(
                leftArm1.seitenLx,leftArm1.seitenLy,leftArm1.seitenLz,
                leftArm1.scaleX,leftArm1.scaleY,leftArm1.scaleZ,
                leftArm1.translX,leftArm1.translY,leftArm1.translZ,
                leftArm1.rotateAngle,leftArm1.rotateX,leftArm1.rotateY,leftArm1.rotateZ
        ); leftArm1.create();
        //
        // leftArm2
        //
        leftArm2 = Wuerfel(
                leftArm2.seitenLx,leftArm2.seitenLy,leftArm2.seitenLz,
                leftArm2.scaleX,leftArm2.scaleY,leftArm2.scaleZ,
                leftArm2.translX,leftArm2.translY,leftArm2.translZ,
                leftArm2.rotateAngle,leftArm2.rotateX,leftArm2.rotateY,leftArm2.rotateZ
        ); leftArm2.create();
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
        rightArm2 = Wuerfel(
                rightArm2.seitenLx,rightArm2.seitenLy,rightArm2.seitenLz,
                rightArm2.scaleX,rightArm2.scaleY,rightArm2.scaleZ,
                rightArm2.translX,rightArm2.translY,rightArm2.translZ,
                rightArm2.rotateAngle,rightArm2.rotateX,rightArm2.rotateY,rightArm2.rotateZ
        ); rightArm2.create();
        //
        // leftLeg
        //
        leftLeg = Wuerfel(
                leftLeg.seitenLx,leftLeg.seitenLy,leftLeg.seitenLz,
                leftLeg.scaleX,leftLeg.scaleY,leftLeg.scaleZ,
                leftLeg.translX,leftLeg.translY,leftLeg.translZ,
                leftLeg.rotateAngle,leftLeg.rotateX,leftLeg.rotateY,leftLeg.rotateZ
        ); leftLeg.create();
        //
        // rightLeg
        //
        rightLeg = Wuerfel(
                rightLeg.seitenLx,rightLeg.seitenLy,rightLeg.seitenLz,
                rightLeg.scaleX,rightLeg.scaleY,rightLeg.scaleZ,
                rightLeg.translX,rightLeg.translY,rightLeg.translZ,
                rightLeg.rotateAngle,rightLeg.rotateX,rightLeg.rotateY,rightLeg.rotateZ
        ); rightLeg.create();
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
    }
    void rotateLeftLeg(double ang, double xx, double yy, double zz) {
        leftLeg.rotate(ang,xx,yy,zz);
    }
    void clearLeftLeg(){
        leftLeg.clear();
    }
private:
    Wuerfel body, head, leftArm1, leftArm2, rightArm1, rightArm2, leftLeg, rightLeg, hat1, hat2;

};


#endif //GDV_ROBOT_H
