#include<windows.h>
#include <GL/glut.h>
#include <math.h>

void line_join(float x1 , float y1 , float x2 , float y2){

    glBegin(GL_LINES);
    glVertex2f(x1,y1);
    glVertex2f(x2,y2);

    glEnd();
    glFlush();

}
void drawCircle2(GLfloat x, GLfloat y, GLfloat radius){
    glBegin(GL_LINE_LOOP);
    glColor3f(1,1,1);
    glBegin(GL_POLYGON);
    int i;
    int lineAmount = 100;
    GLfloat twicePi = 2.0f * 3.14;


    for(i = 0; i <= lineAmount;i++) {
        glVertex2f(
                   x + (radius * cos(i *  twicePi / lineAmount)),
                   y + (radius* sin(i * twicePi / lineAmount))
                   );
    }
    glEnd();
    glFlush();
}

void drawCircle(GLfloat x, GLfloat y, GLfloat radius){
    glBegin(GL_LINE_LOOP);
    glColor3f(1,1,0);
    glBegin(GL_POLYGON);
    int i;
    int lineAmount = 100;
    GLfloat twicePi = 2.0f * 3.14;


    for(i = 0; i <= lineAmount;i++) {
        glVertex2f(
                   x + (radius * cos(i *  twicePi / lineAmount)),
                   y + (radius* sin(i * twicePi / lineAmount))
                   );
    }
    glEnd();
    glFlush();
}




void drawSemiCircle(GLfloat x, GLfloat y, GLfloat radius){
    glBegin(GL_LINE_LOOP);
    glColor3f(1,0,0);
    glBegin(GL_POLYGON);
    int i;
    int lineAmount = 100;

    GLfloat twicePi = 2.0f * 3.14;


    for(i = 62; i <= 88;i++) {
        glVertex2f(
                   x + (radius * cos(i *  twicePi / lineAmount)),
                   y + (radius* sin(i * twicePi / lineAmount))
                   );
    }
    glEnd();
    glFlush();
}

void displayMe(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    drawCircle(0.0, 0.25, 0.5);
    drawCircle2(-0.2, 0.5, 0.05);
    drawCircle2(-0.2, 0.5, 0.05);
    drawCircle2(0.2, 0.5, 0.05);
    drawCircle2(0.2, 0.5, 0.05);
    line_join(0.0, 0.15, 0.0, 0.35);
    drawSemiCircle(0.0, 0.20, 0.25);


}


int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowSize(550, 550);
    glutCreateWindow("Keep smiling :)");
    glutDisplayFunc(displayMe);
    glutMainLoop();
    return 0;
}
