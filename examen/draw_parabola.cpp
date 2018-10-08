#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>
using namespace std;

void putPixel(int x,int y)
{	
	glBegin(GL_POINTS);
	glVertex2i(x,y);
	glEnd();
}


void drawLine(GLint x1, GLint y1,GLint x2,GLint y2)
{
	double dx,dy , incE , incNE,d,x,y;
	dx=x2-x1;
	dy=y2-y1;
	
	d=2*dy-dx;
	incE=2*dy;
	incNE=2*(dy-dx);
	
	x=x1;
	y=y1;
	
	putPixel(x,y);
	
	while(x < x2)
	{
		if(d<=0)
		{
			d+=incE;
			x++;
		}
		else
		{
			d+=incNE;
			x++;
			y++;
		}
		putPixel(x,y);
	}
}



void parabola(GLint xc, GLint yc, GLint p, GLint bound){
	int x,y,d;
	int p2, p4;
	p2 = 2*p;
	p4 = 2*p2;
	x = 0;
	y = 0;
	d = 1 - p;
	//region 1
	while(y < p && x<=bound){
		drawLine(xc+x,yc+y,xc+x,yc+y);
		drawLine(xc+x,yc-y,xc+x,yc-y);
		if(d >= 0){
			x++;
			d = d - p2;
		}
		y++;
		d = d + 2*y +1;
	}
	if(d == 1) d = 1 - p4;
	else d = 1 - p2;
	//region 2
	while(x<=bound){
		drawLine(xc+x,yc+y,xc+x,yc+y);
	    drawLine(xc+x,yc-y,xc+x,yc-y);
		if(d <= 0){
			y++;
			d = d + 4*y;
		}
		x++;
		d = d - p4;
	}
}


 
void displayMe(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	parabola(0,0,100,100); 
	glFlush();
}

int main(int argc, char** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowPosition(330,100);
	glutInitWindowSize(400,400);
	glutCreateWindow("Pregunta 4");
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(-200,200,-200,200);
	
	
	
	
	
	glutDisplayFunc(displayMe);
	glutMainLoop();
	
	return 0;
}


