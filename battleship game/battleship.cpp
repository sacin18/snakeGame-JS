//#include "server2.hpp"
//#include "client2.hpp"
#include "backbone.hpp"

void draw()
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	//glRenderCoolImage();
	/*glBegin(GL_LINES);
	glVertex3f(0.8,0.8,0.0);
	glVertex3f(-0.8,-0.8,0.0);
	glEnd();
	glBegin(GL_LINES);
	glVertex3f(-0.8,0.8,0.0);
	glVertex3f(0.8,-0.8,0.0);
	glEnd();*/
	//opponenthit();
	//if(init==0){funs();}
	xx=glutGet(GLUT_WINDOW_WIDTH);
	yy=glutGet(GLUT_WINDOW_HEIGHT); 
	if(turn==0)glutPassiveMotionFunc(hover);
	glutKeyboardFunc(keyboard);
	if(turn==0)glutMouseFunc(mouse);
	check();
if(place<3)	
{	q();
	q0();
	hits();
	miss();
	show();
	shiptest();
	if(cliser==1)
	{	
		if(init==1 && (turn==2 || turn==1 || initrecieve==0)){recieves();initrecieve=1;}
		if(change==1){q0();hits();show();cout<<"update"<<endl;change=0;}
	}
	else if(cliser==0)
	{
		if(init==1 && (turn==0 ||turn==2))recievec();
		if(change==1){q0();hits();show();cout<<"update"<<endl;change=0;}
	}
	//glutPostRedisplay();
	
}	
else if(place==3)win();
else if(place==4)lose();
glutSwapBuffers();
}
int main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DEPTH|GLUT_DOUBLE|GLUT_RGBA);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glutInitWindowPosition(100,0);
	xx=800;yy=350;
	glutInitWindowSize(xx,yy);
	glutCreateWindow("BATTLESHIP");
	//glClearDepth(1.0f);
	//glEnable(GL_DEPTH_TEST);
	//glDepthRange(-0.1,0.1);
	glClearColor(1.0f,1.0f,1.0f,0.0f);
	glutDisplayFunc(draw);
	glutMainLoop();
	return 1;
}

