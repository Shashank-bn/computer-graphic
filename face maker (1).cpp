#include<windows.h>
#include<gl\glut.h>
#include<math.h>
#include<stdio.h>
#include<string.h>

#define FACE1 1
#define FACE2 2
#define FACE3 3
#define EAR1 1
#define NOSE1 1
#define NOSE2 2
#define EYES1 1
#define EYES2 2
#define EYES3 3
#define EYEBROW1 1
#define HAIR1 1
#define HAIR2 2
#define HAIR3 3
#define HAT1 1
#define HAT2 2
#define HAIRCOLOR1 1
#define HAIRCOLOR2 2
#define HAIRCOLOR3 3
#define SKIN1 1
#define SKIN2 2
#define SKIN3 3
#define EXPR1 1
#define EXPR2 2
#define EXPR3 3

short face, nose, ear, eyes, eyebrow, hair, hat, skin, haircolor, expr;

void initIt()
{
face=FACE1;
ear=EAR1;
nose=NOSE1;
eyes=EYES1;
eyebrow=EYEBROW1;
hat=HAT1;
skin=SKIN1;
haircolor=HAIRCOLOR1;
hair=HAIR1;
expr=EXPR1;
}

void keyboard(unsigned char key, int x, int y)
{
switch (key)
{
case 'q':
case 'Q':
case 27:exit(0);
break;
}
}


void printText(int x, int y, char *t)
{
int l,i;
l=strlen(t);
glRasterPos2i(x,y);
for( i=0;i<l;i++)
{
glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, t[i]);
}
}


void drawFace()
{
if(skin==SKIN1)
glColor3f(0.99,0.9,0.8);
else if(skin==SKIN2)
glColor3f(0.8,0.5,0.6);
else glColor3f(1.0,0.5,0.2);

glBegin(GL_POLYGON);//neck
glVertex2i(200,50);
glVertex2i(300,400);
glVertex2i(400,50);
glEnd();
if(face==FACE1)//square face
{
glBegin(GL_POLYGON);
glVertex2i(100,150);
glVertex2i(80,450);
glVertex2i(520,450);
glVertex2i(500,150);
glEnd();
}
if(face==FACE3)
{
for(int r=1;r<220;r++)
{
for(float thet=0;thet<180;thet=thet+0.2)
{
float tR=3.14*thet/180;
glBegin(GL_POINTS);
glVertex2f(300+r*cos(tR),300+r*sin(tR));
glEnd();
}
}
}

if(face==FACE2)//round face
{
for(int r=1;r<220;r++)
{
for(float thet=0;thet<360;thet=thet+0.2)
{
float tR=3.14*thet/180;
glBegin(GL_POINTS);
glVertex2f(300+r*cos(tR),300+r*sin(tR));
glEnd();
}
}
}
glColor3f(1,0,0);
glPointSize(2);
if(expr==EXPR1)
for(float thet=240;thet<300;thet=thet+0.2)
{
float tR=3.14*thet/180;
glBegin(GL_POINTS);
glVertex2f(300+75*cos(tR),250+75*sin(tR));
glEnd();
for(float thet=60;thet<120;thet=thet+0.2)
{
float tR=3.14*thet/180;
glBegin(GL_POINTS);
glVertex2f(300+75*cos(tR),120+75*sin(tR));
glEnd();
}
}
else
if(expr==EXPR2)
for(float thet=240;thet<300;thet=thet+0.2)
{
float tR=3.14*thet/180;
glBegin(GL_POINTS);
glVertex2f(300+75*cos(tR),250+75*sin(tR));
glEnd();
}
else
if(expr==EXPR3)
for(float thet=60;thet<120;thet=thet+0.2)
{
float tR=3.14*thet/180;
glBegin(GL_POINTS);
glVertex2f(300+75*cos(tR),120+75*sin(tR));
glEnd();
}
}

void drawEyes()
{
int r1,r2;
if(eyes==EYES1)
{
r1=10;
r2=30;
}
else
if(eyes==EYES2)
{
r1=15;
r2=40;
}
else
if(eyes==EYES3)
{
r1=20;
r2=50;
}
if(eyebrow==EYEBROW1)
{
glColor3f(0,0,0);
for(float thet=60;thet<120;thet=thet+0.2)
{
float tR=3.14*thet/180;
glBegin(GL_POINTS);
glVertex2f(200+75*cos(tR),320+75*sin(tR));
glEnd();
}
for(float thet=60;thet<120;thet=thet+0.2)
{
float tR=3.14*thet/180;
glBegin(GL_POINTS);
glVertex2f(400+75*cos(tR),320+75*sin(tR));
glEnd();
}
}
int c1x=200,c1y=350,c2x=400,c2y=350;
glColor3f(1,1,1);//left outer eye
for(int r=1;r<r2;r++)
{
for(float thet=0;thet<360;thet=thet+0.2)
{
float tR=3.14*thet/180;
glBegin(GL_POINTS);
glVertex2f(c1x+r*cos(tR),c1y+r*sin(tR));
glEnd();
}
}
glColor3f(0,0,0);//left inner eye
for(int r=1;r<r1;r++)
{
for(float thet=0;thet<360;thet=thet+0.2)
{
float tR=3.14*thet/180;
glBegin(GL_POINTS);
glVertex2f(c1x+r*cos(tR),c1y+r*sin(tR));
glEnd();
}
}
glColor3f(1,1,1);//right outer eye
for(int r=1;r<r2;r++)
{
for(float thet=0;thet<360;thet=thet+0.2)
{
float tR=3.14*thet/180;
glBegin(GL_POINTS);
glVertex2f(c2x+r*cos(tR),c2y+r*sin(tR));
glEnd();
}
}
glColor3f(0,0,0);//right inner eye
for(int r=1;r<r1;r++)
{
for(float thet=0;thet<360;thet=thet+0.2)
{
float tR=3.14*thet/180;
glBegin(GL_POINTS);
glVertex2f(c2x+r*cos(tR),c2y+r*sin(tR));
glEnd();
}
}
}
void drawEar()//ears
{
glColor3f(0,0,0);
if(ear==EAR1)
    if(face==FACE1)
{
for(float thet=240;thet<300;thet=thet+0.2)
{
float tR=2.14*thet/180;
glBegin(GL_POINTS);
glVertex2f(175+95*cos(tR),300+95*sin(tR));
glEnd();
}
for(float thet=240;thet<300;thet=thet+0.2)
{
float tR=2.14*thet/180;
glBegin(GL_POINTS);
glVertex2f(425-95*cos(tR),300+95*sin(tR));
glEnd();
}
for(float thet=240;thet<300;thet=thet+0.2)
{
float tR=2.14*thet/180;
glBegin(GL_POINTS);
glVertex2f(174+95*cos(tR),300+95*sin(tR));
glEnd();
}
for(float thet=240;thet<300;thet=thet+0.2)
{
float tR=2.14*thet/180;
glBegin(GL_POINTS);
glVertex2f(426-95*cos(tR),300+95*sin(tR));
glEnd();
}
for(float thet=240;thet<300;thet=thet+0.2)
{
float tR=2.14*thet/180;
glBegin(GL_POINTS);
glVertex2f(173+95*cos(tR),300+95*sin(tR));
glEnd();
}
for(float thet=240;thet<300;thet=thet+0.2)
{
float tR=2.14*thet/180;
glBegin(GL_POINTS);
glVertex2f(427-95*cos(tR),300+95*sin(tR));
glEnd();
}
}
if(face==FACE2)
{
for(float thet=240;thet<300;thet=thet+0.2)
{
float tR=2.10*thet/180;
glBegin(GL_POINTS);
glVertex2f(170+95*cos(tR),300+95*sin(tR));
glEnd();
}
for(float thet=240;thet<300;thet=thet+0.2)
{
float tR=2.10*thet/180;
glBegin(GL_POINTS);
glVertex2f(430-95*cos(tR),300+95*sin(tR));
glEnd();
}
}
}
void drawNose()//nose
{
glColor3f(0,0,0);
if(nose==NOSE2)
{
glBegin(GL_POLYGON);
glVertex2i(290,270);
glVertex2i(310,270);
glVertex2i(330,230);
glVertex2i(270,230);
glEnd();
}
else if(nose==NOSE1)
{
glBegin(GL_POLYGON);
glVertex2i(285,275);
glVertex2i(315,275);
glVertex2i(340,220);
glVertex2i(260,220);
glEnd();
}
}

void drawHair()//hair
{
if(haircolor==1)//haircolor
glColor3f(0,0,0);//black
else if(haircolor==2)
glColor3f(1,1,1);//white
else glColor3f(1,1,0);

if(hair==1)
{
glBegin(GL_POLYGON);//square type
glVertex2i(125,500);
glVertex2i(475,500);
glVertex2i(150,400);
glVertex2i(450,400);
glEnd();
}
else if(hair==2)
{
glBegin(GL_POLYGON);//default
glVertex2i(125,500);
glVertex2i(475,500);
glVertex2i(450,400);
glVertex2i(150,400);
glEnd();
glBegin(GL_POLYGON);
glVertex2i(280,500);
glVertex2i(300,540);
glVertex2i(320,500);
glEnd();
}
else if(hair==3)//curly
{
int a[7][2]={{125,430},
{175,480},
{255,455},
{300,480},
{375,450},
{425,450},
{500,430}};
for(int j=0;j<7;j++)
{
for(int r=1;r<50;r++)
{
for(float thet=0;thet<360;thet=thet+0.2)
{
float tR=3.14*thet/180;
glBegin(GL_POINTS);
glVertex2f(a[j][0]+r*cos(tR),a[j][1]+r*sin(tR));
glEnd();
}
}
}
}
}

void drawHat()
{
if(hat==HAT1)
{
glColor3f(1,0.2,0.1);//hat
glBegin(GL_POLYGON);
glVertex2i(140,500);
glVertex2i(460,500);
glVertex2i(460,550);
glVertex2i(140,550);
glEnd();
glBegin(GL_POLYGON);
glVertex2i(100,470);
glVertex2i(500,470);
glVertex2i(500,500);
glVertex2i(100,500);
glEnd();
}
}


void menuFunc(int item)
{
switch(item)
{
case 1:	initIt();//default appearance
glutPostRedisplay();
break;
case 2:	exit(0);//exit
break;
}
}

void hairFunc(int item)
{
switch(item)
{
case 1:	hair=HAIR1;
break;
case 2:	hair=HAIR2;
break;
case 3: hair=HAIR3;
break;
}
glutPostRedisplay();
}
void eyesFunc(int item)
{
switch(item)
{
case 1:	eyes=EYES1;
break;
case 2:	eyes=EYES2;
break;
case 3: eyes=EYES3;
break;
}
glutPostRedisplay();
}
void earFunc(int item)
{
switch(item)
{
case 1:	ear=EAR1;
}
glutPostRedisplay();
}
void noseFunc(int item)
{
switch(item)
{
case 1:	nose=NOSE1;
break;
case 2:	nose=NOSE2;
break;
}
glutPostRedisplay();
}

void exprFunc(int item)
{
switch(item)
{
case 1:	expr=EXPR1;
break;
case 2:	expr=EXPR2;
break;
case 3:	expr=EXPR3;
break;
}
glutPostRedisplay();
}

void skinFunc(int item)
{
switch(item)
{
case 1:	skin=SKIN1;
break;
case 2:	skin=SKIN2;
break;
case 3: skin=SKIN3;
break;
}
glutPostRedisplay();
}
void hairColorFunc(int item)
{
switch(item)
{
case 1:	haircolor=HAIRCOLOR1;
break;
case 2:	haircolor=HAIRCOLOR2;
break;
case 3: haircolor=HAIRCOLOR3;
break;
}
glutPostRedisplay();
}
void hatFunc(int item)
{
switch(item)
{
case 1:	hat=HAT1;
break;
case 2:	hat=HAT2;
break;
}
glutPostRedisplay();
}
void faceFunc(int item)
{
switch(item)
{
case 1:	face=FACE1;
break;
case 2:	face=FACE2;
break;
case 3:	face=FACE3;
break;
}
glutPostRedisplay();
}

void createMenu()
{
   int hairmenu=glutCreateMenu(hairFunc);
   glutAddMenuEntry("Style 1",1);
   glutAddMenuEntry("Style 2",2);
   glutAddMenuEntry("Style 3",3);
   int haircolormenu=glutCreateMenu(hairColorFunc);
   glutAddMenuEntry("Black",1);
   glutAddMenuEntry("White",2);
   glutAddMenuEntry("Yellow",3);
   int facemenu=glutCreateMenu(faceFunc);
   glutAddMenuEntry("Square",1);
   glutAddMenuEntry("Circle",2);
   glutAddMenuEntry("shape3",3);
   int nosemenu=glutCreateMenu(noseFunc);
   glutAddMenuEntry("Big",1);
   glutAddMenuEntry("Small",2);
   int eyesmenu=glutCreateMenu(eyesFunc);
   glutAddMenuEntry("small",1);
   glutAddMenuEntry("Medium",2);
   glutAddMenuEntry("Large",3);
   int exprmenu=glutCreateMenu(exprFunc);
   glutAddMenuEntry("Normal",1);
   glutAddMenuEntry("Happy",2);
   glutAddMenuEntry("Sad",3);
   int skinmenu=glutCreateMenu(skinFunc);
   glutAddMenuEntry("skin1",1);
   glutAddMenuEntry("skin2",2);
   glutAddMenuEntry("skin3",3);
   int hatmenu=glutCreateMenu(hatFunc);
   glutAddMenuEntry("Hat",1);
   glutAddMenuEntry("No Hat",2);
   glutCreateMenu(menuFunc);
   glutAddSubMenu("Face",facemenu);
   glutAddSubMenu("Expression",exprmenu);
   glutAddSubMenu("Skin",skinmenu);
   glutAddSubMenu("Eyes",eyesmenu);
   glutAddSubMenu("Nose",nosemenu);
   glutAddSubMenu("Hair Style",hairmenu);
   glutAddSubMenu("Hair Color",haircolormenu);
   glutAddSubMenu("Hat",hatmenu);
   glutAddMenuEntry("Reset",1);
   glutAddMenuEntry("Quit",2);
   glutAttachMenu(GLUT_RIGHT_BUTTON);
}

void myInit()
{
glClearColor(0.0,0.7,0.7,0.0);
gluOrtho2D(0,600,0,600);
}

void display()
{
glClear(GL_COLOR_BUFFER_BIT);
drawFace();
drawEyes();
drawEar();
drawNose();
drawHair();
drawHat();
glColor3f(0,0,0);
printText(10,10,"OpenGL mini Project By MADHU(4GH19CS406) and RAMU(4GH19CS413)");
printText(10,30,"Right-Click for menu");
glFlush();
}

int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
   glutInitWindowSize(800, 600);
   glutInitWindowPosition(10,10);
   glutCreateWindow("Avatar");
   myInit();
   initIt();
   createMenu();
   glutKeyboardFunc(keyboard);
   glutDisplayFunc(display);
   glutMainLoop();
}
