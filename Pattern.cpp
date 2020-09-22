#include<windows.h>
#include <GL/glut.h>
#include <math.h>
void init()
{
 glClearColor(0,0,0,0);
 glMatrixMode(GL_PROJECTION);
 glOrtho(-10,100,-10,100,20,-20);
}
void triangle1()
{
glClear(GL_COLOR_BUFFER_BIT);
glBegin(GL_LINE_LOOP);
glVertex2f(0,50);
glVertex2f(10,40);
glVertex2f(-10,40);
glEnd();
glFlush();
}
void square1()
{
glBegin(GL_LINE_LOOP);
glVertex2f(10,40);
glVertex2f(20,40);
glVertex2f(20,30);
glVertex2f(10,30);
glEnd();
glFlush();
}
void circle1()
{
glBegin(GL_LINE_LOOP);
float th;
for(int i=0; i<360; i++){
    th=i*3.142/180;
    glVertex2f(15+5*cos(th),35+5*sin(th));
}
glEnd();
glFlush();
}

void triangle2()
{
glBegin(GL_LINE_LOOP);
glVertex2f(30,50);
glVertex2f(40,40);
glVertex2f(20,40);
glEnd();
glFlush();
}
void square2()
{
glBegin(GL_LINE_LOOP);
glVertex2f(40,40);
glVertex2f(50,40);
glVertex2f(50,30);
glVertex2f(40,30);
glEnd();
glFlush();
}
void circle2()
{
glBegin(GL_LINE_LOOP);
float th;
for(int i=0; i<360; i++){
    th=i*3.142/180;
    glVertex2f(45+5*cos(th),35+5*sin(th));
}
glEnd();
glFlush();
}
void triangle3()
{
glBegin(GL_LINE_LOOP);
glVertex2f(60,50);
glVertex2f(70,40);
glVertex2f(50,40);
glEnd();
glFlush();
}
void displayMe(void)
{
triangle1();
square1();
circle1();
triangle2();
square2();
circle2();
triangle3();
}

int main(int argc, char** argv)
{
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_SINGLE);
glutInitWindowSize(500, 500);
glutInitWindowPosition(100, 100);
glutCreateWindow("Q3");
glutDisplayFunc(displayMe);
init();
glutMainLoop();
return 0;
}
