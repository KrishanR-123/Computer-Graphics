#include<windows.h>
#include<GL/glut.h>
#include<stdio.h>
GLint ww=200, wh=200;
GLint x1=0,y1=0,x2=0,y2=0,gx1=0,gx2=0,gy1=0,gy2=0;
GLint count = 0;
void init(void)
{
 glClearColor(1.0,1.0,1.0,0.0);
 glMatrixMode(GL_PROJECTION);
 gluOrtho2D(-200,200,-200,200.0);
}
void draw_pixel(GLfloat x,GLfloat y)
{
 glPointSize(2);
 glBegin(GL_POINTS);
  glVertex2f(x,y);
 glEnd();
}
void BresLine(GLint x1,GLint y1,GLint x2,GLint y2)
{
 glColor3f(0.0,1.0,1.0);
glBegin(GL_LINES);
  glVertex2i(-200,0);
  glVertex2i(200,0);
  glVertex2i(0,-200);
  glVertex2i(0,200);
 glEnd();
glColor3f(0.1,1.0,0.0);
 glPointSize(4);
 glBegin(GL_POINTS);
  glVertex2i(0,0);
 glEnd();
glColor3f(1.0,0.0,0.0);
int dx, dy, i, e;
int incx, incy, inc1, inc2;
int x,y;
dx = x2-x1;
dy = y2-y1;
if (dx < 0) dx = -dx;
if (dy < 0) dy = -dy;
incx = 1;
if (x2 < x1) incx = -1;
incy = 1;
if (y2 < y1) incy = -1;
x = x1; y = y1;
if (dx > dy) {
draw_pixel(x, y);
e = 2 * dy-dx;
inc1 = 2*(dy-dx);
inc2 = 2*dy;
for (i=0; i<dx; i++) {
if (e >= 0) {
y += incy;
e += inc1;
}
else
e += inc2;
x += incx;
draw_pixel(x, y);
}
} else {
draw_pixel(x, y);
e = 2*dx-dy;
inc1 = 2*(dx-dy);
inc2 = 2*dx;
for (i=0; i<dy; i++) {
if (e >= 0) {
x += incx;
e += inc1;
}
else
e += inc2;
y += incy;
draw_pixel(x, y);
}
}
}
void mousePtPlot(GLint button, GLint action, GLint xMouse, GLint yMouse)
{
 if(button == GLUT_LEFT_BUTTON && action == GLUT_UP)
 {
  if(!count)
  {
   glClear(GL_COLOR_BUFFER_BIT);
   x1=-(ww-xMouse);
   y1=wh-yMouse;
   count = 1;
  gx1=x1;
gy1=y1;
draw_pixel(x1,y1);
   printf("First point %d, %d entered.\n",x1,y1);
  }
  else
  {
   x2=-(ww-xMouse);
   y2=wh-yMouse;
   printf("Second point %d, %d entered.\n",x2,y2);
   gx2=x2;
gy2=y2;
draw_pixel(x2,y2);

   count=0;
BresLine(gx1,gy1,gx2,gy2);
   printf("Points reset.\n");
  }
 }
 glFlush();
}
void display(void)
{
 glClear(GL_COLOR_BUFFER_BIT);
 BresLine(gx1,gy1,gx2,gy2); //m > 1 steep,positive

glFlush();
}
int main(int argc, char** argv)
{
 glutInit(&argc,argv);
 glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
 glutInitWindowPosition(50,100);
 glutInitWindowSize(400,400);
 glutCreateWindow("Line Drawing: Bresenham");
  init();
 glutDisplayFunc(display);
 glutMouseFunc(mousePtPlot);
 //glutReshapeFunc(winReshape);
 glutMainLoop();
 return 0;
}
