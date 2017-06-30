#include<iostream>
#include<stdlib.h>
#include<GL/glut.h>
#include<string.h>
#include<math.h>
using namespace std;
void points(float cx,float cy)
{
	glColor3f(1.0,0.0,0.0);
	cx=(cx-300)/300;cy=(cy-300)/300;
	glPushMatrix();
	glBegin(GL_POLYGON);
	glVertex2f(cx,cy);
	glVertex2f(cx,cy);
	glVertex2f(cx,cy);
	glVertex2f(cx,cy);
	glEnd();
	glPopMatrix();
}
void square(float cx,float cy,float cz,int i)
{
	if(i==0)
	{
		glColor3f(1.0,0.0,0.0);
		//printf("%d",i);	
	}
	else
	{
		glColor3f(0.0,1.0,0.0);
		//printf("%d",i);
	} 
	cx=(cx-300)/300;cy=-(cy-300)/300;
	glBegin(GL_POLYGON);
	glVertex3f(cx-0.005,cy-0.005,cz);	
	glVertex3f(cx+0.005,cy-0.005,cz);
	glVertex3f(cx+0.005,cy+0.005,cz);
	glVertex3f(cx-0.005,cy+0.005,cz);
	glEnd();
	//glutPostRedisplay();
}
void line(float ax,float ay,float bx,float by)
{
	glColor3f(0.0,0.0,1.0);
	ax=(ax-300)/300;ay=-(ay-300)/300;
	bx=(bx-300)/300;by=-(by-300)/300;
	glBegin(GL_LINES);
	glVertex3f(ax,ay,0);
	glVertex3f(bx,by,0);
	glEnd();
}
float distance(int fx,int fy,int sx,int sy)
{
	//cout<<sqrt(((fx-sx)*(fx-sx))+((fy-sy)*(fy-sy)));
	return sqrt(((fx-sx)*(fx-sx))+((fy-sy)*(fy-sy)));
}
