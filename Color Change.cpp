#include<windows.h>
#include<GL/glut.h>
GLfloat x,y=1,z;
void init(){
    glClearColor(1,1,1,0);
    glMatrixMode(GL_PROJECTION);
    glOrtho(0,500,0,500,0,10);
}
void display(){
     glClear(GL_COLOR_BUFFER_BIT);
     glColor3f(x,y,z);
     glBegin(GL_TRIANGLES);
     glVertex2f(50,50);
     glVertex2f(200,50);
     glVertex2f(125,250);
     glEnd();
     glFlush();
}


void key(unsigned char key,int x,int y){
    switch(key){
     case 32:
        x=1;
        y=1;
        z=1;
        glutPostRedisplay();
        break;
    }
}


void mouse(int button,int state,int x,int y){

    if(button==GLUT_RIGHT_BUTTON){
        x=1;
        y=0;
        z=1;
    }
    else{

    }
    glutPostRedisplay();
}
int main(int argc,char **argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(600,600);
    glutCreateWindow("Change color: CG");
    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(key);
    glutMouseFunc(mouse);
    glutMainLoop();
}
