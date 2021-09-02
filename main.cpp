#include<windows.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include<iostream>
#include<stdio.h>
using namespace std;

int x1,y1,x2,y2,x3,y3;


void translation(int x,int y)
{

     glColor3f(0,0,1);
     glBegin(GL_LINE_LOOP);

        glVertex2i(300+x,400+y);
        glVertex2i(500+x,400+y);
        glVertex2i(400+x,700+y);


      glEnd();

     glFlush();
}


void myInit()
{
    glClearColor(1,1,1,1);
    glPointSize(12);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0,1000.0,0.0,1000.0);
    glPointSize(40);
}






void Draw()
{

      glColor3f(1,0,0);
      glBegin(GL_LINE_LOOP);

        glVertex2i(300,400);
        glVertex2i(500,400);
        glVertex2i(400,700);
      glEnd();

     glFlush();
}







int main(int argC,char *argV[])
{
    //cout << "Enter the co-ordinates of the three points of the triangle:" << endl;
  //  cout << "x1: "; cin >> x1;
   // cout << "y1: "; cin >> y1;
  //  cout << "x2: "; cin >> x2;
  //  cout << "y2: "; cin >> y2;
  //  cout << "x3: "; cin >> x3;
  //  cout << "y3: "; cin >> y3;

    glutInit(&argC,argV);


    glutInitWindowSize(800,800);
    glutInitWindowPosition(0,0);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutCreateWindow("Transformation");

    myInit();

    glutDisplayFunc(Draw);
    translation(50,50);
    translation(100,100);

    glutMainLoop();

}
