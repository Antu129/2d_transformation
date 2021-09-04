#include<windows.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include<iostream>

#include<math.h>
using namespace std;

int pntx1,pnty1;
int pntx2,pnty2,pntx3,pnty3;


void translation(int x,int y)
{

     glColor3f(0,0,1);
     glBegin(GL_LINE_LOOP);

        glVertex2i(pntx1+x,pnty1+y);
        glVertex2i(pntx2+x,pnty2+y);
        glVertex2i(pntx3+x,pnty3+y);


      glEnd();

     glFlush();
}


void scale(float x, float y)
{
     glColor3f(0,0,1);
     glBegin(GL_LINE_LOOP);

        glVertex2f(pntx1*x,pnty1*y);
        glVertex2f(pntx2*x,pnty2*y);
        glVertex2f(pntx3*x,pnty3*y);


      glEnd();

     glFlush();
}


void myInit()
{
    glClearColor(1,1,1,1);

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

        glVertex2i(pntx1,pnty1);
        glVertex2i(pntx2,pnty2);
        glVertex2i(pntx3,pnty3);
      glEnd();

     glFlush();
}







int main(int argC,char *argV[])
{
    int opt;

    cout << "Enter the co-ordinates of the three points of the triangle:" << endl;
    cout << "x1: "; cin >> pntx1;
    cout << "y1: "; cin >> pnty1;
    cout << "x2: "; cin >> pntx2;
    cout << "y2: "; cin >> pnty2;
    cout << "x3: "; cin >> pntx3;
    cout << "y3: "; cin >> pnty3;

    glutInit(&argC,argV);


    glutInitWindowSize(800,800);
    glutInitWindowPosition(0,0);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutCreateWindow("Transformation");

    myInit();

    int tx,ty;
    float sx,sy;
    cout << "Press 1 to translate \n\nPress 2 to scale\n\nPress 3 to break\n\n\n";
    cin >> opt;

   if(opt==1)
   {
      cout << "Translation in x axis:"; cin >> tx;
      cout << "translation in y axis:"; cin >> ty;


      translation(tx,ty);
   }
   else if(opt==2)
   {
      cout << "Scaling in x axis:"; cin >> sx;
      cout << "Scaling in y axis:"; cin >> sy;

      scale(sx,sy);
   }
   else
   {
       cout << "BOOM BOOM";
   }

   glutDisplayFunc(Draw);
   if(opt==1 || opt==2){
        glutMainLoop();}

}
