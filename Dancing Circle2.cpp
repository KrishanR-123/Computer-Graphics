#include<windows.h>
#include<iostream>
#include<stdlib.h>
#include<GL/glut.h>

float ballX = -0.5;
float ballY = 0.0;
float ballZ = -1.0;

static int flag=1;

void init()
{
 glClearColor(0,0,0,0);
 glMatrixMode(GL_PROJECTION);
 glOrtho(-10,100,-10,100,20,-20);
}
void drawBall(void) {
        glColor3f(1.0, 1.0, 0.0);
        glTranslatef(ballY,ballX,ballZ);
        glutSolidSphere (0.05, 100, 100);
}
void drawBall2(void) {

        glColor3f(1.0, 1.0, 0.0);
        glTranslatef(ballX,ballY,ballZ);
        glutSolidSphere (0.05, 100, 100);
}



void initRendering()
{
    glEnable(GL_DEPTH_TEST);
}


void handleResize(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0,
                   (double)w / (double)h,
                   1.0,
                   200.0);
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
    ballX += 0.001f;
       if(ballX>0.3)
       {
           flag=0;

       }
    }
    if (!flag)
    {
        ballX -= 0.001f;
        if(ballX<-0.3)
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
    initRendering();

    glutDisplayFunc(drawScene);

    glutReshapeFunc(handleResize);
    glutTimerFunc(1, update, 0);
    glutMainLoop();
    return(0);
}
