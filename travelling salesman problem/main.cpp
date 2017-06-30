#include "nodes.hpp"
//#include "greedy.hpp"
//#include "Untitled10.cpp"
void progmain()
{
	//cout<<endl<<"prog1"<<endl;
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glLineWidth(3);
	if(reset==1)resetall();
	if(ready==0)nodes();
	else solution();
	glutSwapBuffers();
}
/*void progmain2()
{
	cout<<endl<<"prog2"<<endl;
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glLineWidth(3);
	solution();
	glutSwapBuffers();
}*/
int main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
	glutInitWindowSize(600,600);
	glutCreateWindow("Travelling Salesman Problem");
	glClearColor(1.0f,1.0f,1.0f,0.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	//glutMouseFunc(mouse);
	//glutPassiveMotionFunc(mou);
//	if(ready==0)
	glutDisplayFunc(progmain);  
//	else 
//	{
//		glutDisplayFunc(progmain2);
//		glutPostRedisplay();	
//	}   
	glutMainLoop();
}
