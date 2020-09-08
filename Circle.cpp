#include<windows.h>
#include <GL/glut.h>
#include <math.h>
void display()
{
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(1,1,0);
glBegin(GL_POLYGON);
glVertex2f(-0.5,0.5);
for(int i = 0; i <= 20;i++)
glVertex2f(-0.5 + (0.1 * cos(i *  2.0f * 3.14 / 20)), 0.5 + (0.1 * sin(i * 2.0f * 3.14 / 20)));
glEnd();
glFlush();
}
int main(int argc,char** argv)
{
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
glutInitWindowSize(900,900);
glutInitWindowPosition(300,500);
glutCreateWindow("CG: Circle");
glutDisplayFunc(display);
glutMainLoop();
return 0;
}
