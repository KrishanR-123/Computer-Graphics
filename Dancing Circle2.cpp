#include<windows.h>
#include<iostream>
#include<stdlib.h>
#include<GL/glut.h>

float X = -0.5;
float Y = 0.0;
float Z = -1.0;

bool flag=1;

void init()
{
 glClearColor(0,0,0,0);
 glMatrixMode(GL_PROJECTION);
 glOrtho(-10,100,-10,100,20,-20);
}
void drawBall(void) {
        glColor3f(1.0, 1.0, 0.0);
        glTranslatef(Y,X,Z);
        glutSolidSphere (0.05, 100, 100);
}



void handleResize(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

}

void drawScene()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    drawBall();
    glutSwapBuffers();
}


void update(int value) {
    if(flag)
    {
    X += 0.001f;
       if(X>0.3)
       {
           flag=0;
       }
    }
    else
    {
        X -= 0.001f;
        if(X<-0.3)
       {
           flag=1;
       }
    }
    glutPostRedisplay();
    glutTimerFunc(1, update, 0);
}

int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
    glutInitWindowSize(400,400);
    glutCreateWindow("Q2");
    init();
    glutDisplayFunc(drawScene);
    glutReshapeFunc(handleResize);
    glutTimerFunc(1, update, 0);
    glutMainLoop();
    return(0);
}
