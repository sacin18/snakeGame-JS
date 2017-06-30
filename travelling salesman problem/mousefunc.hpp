#include "points.hpp"
static int count=0;
static int px[20]={0};
static int py[20]={0};
static int c[20]={0};
static int done=0,ans=0;
static int path[20];
static int pc=0;
static int ready=0;
static int reset=0;
void mouse(int buton,int state,int x,int y)
{
	int cx,cy;
	switch(buton)
	{
		case GLUT_LEFT_BUTTON:
			if(state==GLUT_DOWN&&count<15&&done!=1)
			{
				if(x!=0||y!=0)
				{
					px[count]=x;py[count]=y;
					square(px[count],py[count],0,0);
					//for(int i=0;i<count;i++)point(px[i],py[i]);
					count++;
					cout<<count<<" "<<px[count-1]<<","<<py[count-1]<<endl;
					glutPostRedisplay();
				}
			}
			else if(state==GLUT_DOWN&&done==1)
			{
				for(int i=0;i<count;i++)
				{
					if(px[i]==x&&py[i]==y)
					{
						c[i]=1;
					}
				}
			}
			break;
		case GLUT_RIGHT_BUTTON:
			if(state==GLUT_DOWN)
			{
				px[count-1]=py[count-1]=0;
				if(count!=0)count--;
				done=0;ans=0;
				glutPostRedisplay();
			}
	}
}
//void glutKeyboardFunc(void (*func) (unsigned char key, int x, int y));
//void processNormalKeys(unsigned char key, int x, int y)
void keyboard(unsigned char key,int x,int y)
{
	if(key==27)exit(0);
	else if(key==13&&done==1)
	{
		ans=1;cout<<"answer called"<<endl;
		glutPostRedisplay();
		//glutPostRedisplay();
	}
	else if(key=='r')
	{
		reset=1;
		glutPostRedisplay();
	}
	else if(key==13||count==15)
	{
		done=1;
		glutPostRedisplay();
	}
}
