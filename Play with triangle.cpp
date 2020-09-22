#include<windows.h>
#include <GL/glut.h>

double spin=0;
void displayMe3(void)
{
glClear(GL_COLOR_BUFFER_BIT);
glBegin(GL_POLYGON);
glVertex3f(-0.5, 0.0, 0.0);
glVertex3f(0.0, 0.5, 0.0);
glVertex3f(0.0, 0.0, 0.5);
glEnd();
glFlush();
}
void displayMe2(void)
{
glClear(GL_COLOR_BUFFER_BIT);
glBegin(GL_POLYGON);
glVertex3f(0.5, 0.0, 0.0);
glVertex3f(0.0, -0.5, 0.0);
glVertex3f(0.0, 0.0, 0.5);
glEnd();
glFlush();
}
void displayMe(void)
{
glClear(GL_COLOR_BUFFER_BIT);
glBegin(GL_POLYGON);
glVertex3f(0.5, 0.0, 0.0);
glVertex3f(0.0, 0.5, 0.0);
glVertex3f(0.0, 0.0, 0.5);
glEnd();
glFlush();
}


void key(unsigned char key,int x,int y){
     switch(key){
     case 65:
         glScaled(1.5f, 1.5f, 1.5f);
         break;
     case 83:
         glScaled(0.5f, 0.5f, 0.5f);
         break;
     case 81:
        spin+=5;
        glRotated(spin,-1.0f, 1.5f, -5.0f );
        break;
     case 87:
        spin-=5;
        glRotated(spin,-1.0f, 1.5f, -5.0f );
        break;
     case 69:
        glutDisplayFunc(displayMe2);
        break;
     case 82:
        glutDisplayFunc(displayMe3);
        break;
     }
glutPostRedisplay();
}

int main(int argc, char** argv)
{
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_SINGLE);
glutInitWindowSize(400, 400);
glutInitWindowPosition(100, 100);
glutCreateWindow("Hello world!");
glutDisplayFunc(displayMe);
glutKeyboardFunc(key);
glutMainLoop();
return 0;
}
