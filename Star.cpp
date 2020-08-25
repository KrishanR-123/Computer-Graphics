#include<windows.h>
#include<GL/glut.h>
void display (void)
{

glClear (GL_COLOR_BUFFER_BIT);
glLoadIdentity ();


glBegin (GL_LINE_LOOP);
glVertex3f(0.0,0.2,0.0);
glVertex3f(0.1,0.1,0.0);
glVertex3f(0.2,0.05,0.0);
glVertex3f(0.1,0.0,0.0);
glVertex3f(0.2,-0.1,0.0);
glVertex3f(0.0,0.0,0.0);
glVertex3f(-0.2,-0.1,0.0);
glVertex3f(-0.1,0.0,0.0);
glVertex3f(-0.2,0.05,0.0);
glVertex3f(-0.1,0.1,0.0);
glEnd();
glFlush();
}


int main(int argc, char **argv)
{
glutInit (&argc, argv);
glutInitWindowSize (800,600);
glutInitWindowPosition (100,100);
glutCreateWindow ("Computer Graphics: Star");
glutDisplayFunc(display);
glutMainLoop ();
return 0;
}




