#include "mix.hpp"
//#include "client2.hpp"
#include<math.h>
int xx=1000,yy=600;
int initrecieve=0;
void win()
{
	float l=0.225;
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glColor3f(11.0/255,172.0/255,83.0/255);
	glBegin(GL_POLYGON);
	glVertex3f(-0.92+l,0.3,0);
	glVertex3f(-0.85+l,0.3,0);
	glVertex3f(-0.85+l,0.2,0);
	glVertex3f(-0.97+l,0.2,0);
	glVertex3f(-0.97+l,0.5,0);
	glVertex3f(-0.92+l,0.5,0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(-0.845+l,0.5,0);
	glVertex3f(-0.845+l,-0.1,0);
	glVertex3f(-0.795+l,-0.1,0);
	glVertex3f(-0.795+l,0.5,0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(-0.845+0.1+l,0.5,0);
	glVertex3f(-0.845+0.1+l,-0.1,0);
	glVertex3f(-0.795+0.1+l,-0.1,0);
	glVertex3f(-0.795+0.1+l,0.4,0);
	glVertex3f(-0.705+0.1+l,0.4,0);
	glVertex3f(-0.705+0.1+l,0.5,0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(-0.845+0.245+l,-0.0,0);
	glVertex3f(-0.935+0.245+l,-0.0,0);
	glVertex3f(-0.935+0.245+l,-0.1,0);
	glVertex3f(-0.795+0.245+l,-0.1,0);
	glVertex3f(-0.795+0.245+l,0.5,0);
	glVertex3f(-0.845+0.245+l,0.5,0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(-0.475+l,-0.0,0);
	glVertex3f(-0.335+l,0,0);
	glVertex3f(-0.335+l,-0.1,0);
	glVertex3f(-0.525+l,-0.1,0);
	glVertex3f(-0.525+l,0.5,0);
	glVertex3f(-0.475+l,0.5,0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(-0.385+l,0.5,0);
	glVertex3f(-0.335+l,0.5,0);
	glVertex3f(-0.335+l,0.015,0);
	glVertex3f(-0.385+l,0.015,0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(-0.05+l,0.0,0);
	glVertex3f(0.2+l,0.0,0);
	glVertex3f(0.2+l,-0.1,0);
	glVertex3f(-0.1+l,-0.1,0);
	glVertex3f(-0.1+l,0.5,0);
	glVertex3f(-0.05+l,0.5,0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(0.03+l,0.4,0);
	glVertex3f(0.08+l,0.4,0);
	glVertex3f(0.08+l,0.01,0);
	glVertex3f(0.03+l,0.01,0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(0.15+l,0.5,0);
	glVertex3f(0.2+l,0.5,0);
	glVertex3f(0.2+l,0.01,0);
	glVertex3f(0.15+l,0.01,0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(0.25+l,0.5,0);
	glVertex3f(0.3+l,0.5,0);
	glVertex3f(0.3+l,-0.1,0);
	glVertex3f(0.25+l,-0.1,0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(0.35+l,0.38,0);
	glVertex3f(0.4+l,0.38,0);
	glVertex3f(0.4+l,-0.1,0);
	glVertex3f(0.35+l,-0.1,0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(0.475+l,0.4,0);
	glVertex3f(0.35+l,0.4,0);
	glVertex3f(0.35+l,0.5,0);
	glVertex3f(0.525+l,0.5,0);
	glVertex3f(0.525+l,-0.1,0);
	glVertex3f(0.475+l,-0.1,0);
	glEnd();
}
void lose()
{
	float l=0.1;
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glColor3f(215.0/255,17.0/255,27.0/255);
	glBegin(GL_POLYGON);
	glVertex3f(-0.93+l,0.3,0);
	glVertex3f(-0.85+l,0.3,0);
	glVertex3f(-0.85+l,0.2,0);
	glVertex3f(-0.98+l,0.2,0);
	glVertex3f(-0.98+l,0.5,0);
	glVertex3f(-0.93+l,0.5,0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(-0.845+l,0.5,0);
	glVertex3f(-0.845+l,-0.1,0);
	glVertex3f(-0.795+l,-0.1,0);
	glVertex3f(-0.795+l,0.5,0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(-0.845+0.1+l,0.5,0);
	glVertex3f(-0.845+0.1+l,-0.1,0);
	glVertex3f(-0.795+0.1+l,-0.1,0);
	glVertex3f(-0.795+0.1+l,0.4,0);
	glVertex3f(-0.705+0.1+l,0.4,0);
	glVertex3f(-0.705+0.1+l,0.5,0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(-0.845+0.245+l,-0.0,0);
	glVertex3f(-0.935+0.245+l,-0.0,0);
	glVertex3f(-0.935+0.245+l,-0.1,0);
	glVertex3f(-0.795+0.245+l,-0.1,0);
	glVertex3f(-0.795+0.245+l,0.5,0);
	glVertex3f(-0.845+0.245+l,0.5,0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(-0.475+l,-0.0,0);
	glVertex3f(-0.335+l,0,0);
	glVertex3f(-0.335+l,-0.1,0);
	glVertex3f(-0.525+l,-0.1,0);
	glVertex3f(-0.525+l,0.5,0);
	glVertex3f(-0.475+l,0.5,0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(-0.385+l,0.5,0);
	glVertex3f(-0.335+l,0.5,0);
	glVertex3f(-0.335+l,0.015,0);
	glVertex3f(-0.385+l,0.015,0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(-0.05+l,0.0,0);
	glVertex3f(0.1+l,0.0,0);
	glVertex3f(0.1+l,-0.1,0);
	glVertex3f(-0.1+l,-0.1,0);
	glVertex3f(-0.1+l,0.5,0);
	glVertex3f(-0.05+l,0.5,0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(0.12+l,0.5,0);
	glVertex3f(0.12+l,-0.1,0);
	glVertex3f(0.17+l,-0.1,0);
	glVertex3f(0.17+l,0.4,0);
	glVertex3f(0.26+l,0.4,0);
	glVertex3f(0.26+l,0.5,0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(0.265+l,-0.0,0);
	glVertex3f(0.175+l,-0.0,0);
	glVertex3f(0.175+l,-0.1,0);
	glVertex3f(0.315+l,-0.1,0);
	glVertex3f(0.315+l,0.5,0);
	glVertex3f(0.265+l,0.5,0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(0.345+l,0.5,0);
	glVertex3f(0.345+l,0.15,0);
	glVertex3f(0.395+l,0.15,0);
	glVertex3f(0.395+l,0.4,0);
	glVertex3f(0.535+l,0.4,0);
	glVertex3f(0.535+l,0.5,0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(0.485+l,0.15,0);
	glVertex3f(0.397+l,0.15,0);
	glVertex3f(0.397+l,0.25,0);
	glVertex3f(0.535+l,0.25,0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(0.485+l,0,0);
	glVertex3f(0.345+l,0,0);
	glVertex3f(0.345+l,-0.1,0);
	glVertex3f(0.535+l,-0.1,0);
	glVertex3f(0.535+l,0.25,0);
	glVertex3f(0.485+l,0.25,0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(0.6+l,0.0,0);
	glVertex3f(0.775+l,0.0,0);
	glVertex3f(0.775+l,-0.1,0);
	glVertex3f(0.55+l,-0.1,0);
	glVertex3f(0.55+l,0.5,0);
	glVertex3f(0.6+l,0.5,0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(0.605+l,0.25,0);
	glVertex3f(0.775+l,0.25,0);
	glVertex3f(0.775+l,0.15,0);
	glVertex3f(0.605+l,0.15,0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(0.60+l,0.5,0);
	glVertex3f(0.775+l,0.5,0);
	glVertex3f(0.775+l,0.4,0);
	glVertex3f(0.60+l,0.4,0);
	glEnd();
}
void circle()
{
	glColor3f(1,104/255.0,4/255.0);	
	glBegin(GL_POLYGON);
    for(int ii = 0; ii < 255; ii++)
    {
        float theta = 2.0f * 3.1415926f * float(ii) / float(255);//get the current angle

        float x = -0.07 * cosf(theta);//calculate the x component
        float y = -0.15 * sinf(theta);//calculate the y component

        glVertex3f(x-0.9, y-0.82,0.0);//output vertex

    }
    glEnd();
}
void stop()
{
	glColor3f(1,0,0);	
	glBegin(GL_POLYGON);
	glVertex3f(-0.9,-0.7,0.0);
	glVertex3f(-0.8,-0.7,0.0);
	glVertex3f(-0.8,-0.9,0.0);
	glVertex3f(-0.9,-0.9,0.0);
	glEnd();
}
void play()
{
	glColor3f(0,1,0);	
	glBegin(GL_POLYGON);
	glVertex3f(-0.9,-0.7,0.0);
	glVertex3f(-0.8,-0.8,0.0);
	glVertex3f(-0.9,-0.9,0.0);
	glEnd();
}
void check()
{
	int c=0;//oppoints[1][0]=1;
	if(place==0)for(int i=1;i<5;i++)if(ss[i]==1)c++;
	if(c==4&&place==0)
	{
		for(int i=0;i<9;i++)for(int j=0;j<9;j++){if(ship[i][j]==4||ship[i][j]==5)ship[i][j]=0;}

		place=1;
	}
	if(place==1){c=0;for(int i=0;i<9;i++)for(int j=0;j<9;j++)if(points[i][j]==2)c++;if(c==14){place=3;cout<<endl<<"win!!"<<endl;}}
	if(place==1){c=0;for(int i=0;i<9;i++)for(int j=0;j<9;j++)if(oppoints[i][j]==2)c++;if(c==14){place=4;cout<<endl<<"looser!!"<<endl;}}
}
void hover(int x,int y)
{
	float cx,cy;
	if(place==1)
	{
		//cout<<x<<"\t"<<y<<endl;
		x=x-(xx/2);y=(yy/2)-y;
		cx=x/float(xx/2);cy=y/float(yy/2);
		//cout<<cx<<"  "<<cy<<endl;
		float f=0.1,l=0.15;
		for(int i=0;i<9;i++)for(int j=0;j<10;j++)if(points[i][j]==3)points[i][j]=0;
		for(int i=0;i<9;i++)
		if(cx>-0.95+i*f && cx<-0.85+i*f)
		for(int j=0;j<9;j++)
			if(cy<0.9-j*l && cy>0.75-j*l){if(points[i][j]==0)points[i][j]=3;}
		//cout<<"hell"<<endl;
		glutPostRedisplay();
		if(init==0)
		{
			func();turn=1;cout<<"decide time"<<endl;
			if(cliser==1){funs();turn=0;cout<<"i am server"<<endl;}
		}
	}
	else if(place==0)
	{
		//cout<<x<<"\t"<<y<<endl;
		x=x-(xx/2);y=(yy/2)-y;
		cx=x/float(xx/2);cy=y/float(yy/2);
		//cout<<cx<<"  "<<cy<<endl;
		float f=0.1,l=0.15;
		for(int i=0;i<9;i++)for(int j=0;j<10;j++)if(ship[i][j]==4||ship[i][j]==5)ship[i][j]=0;
		if(hv==1 && ss[s-1]==0 && mal==0)
		{
			for(int j=0;j<9;j++)
			if(cy<0.9-j*l && cy>0.75-j*l)
			for(int i=0;i<9;i++)
			{
				if(cx>0.05+i*f && cx<0.15+i*f)
				{
					if(j<10-s)
					{
						mal=0;
						for(int k=j;k<j+s;k++){if(ship[i][k]==0)ship[i][k]=4;else if(ship[i][k]>6)mal=1;else mal=1;}
					}
					else
					{
						for(int k=j;k<10;k++){if(ship[i][k]==0||ship[i][k]==4)ship[i][k]=5;}
					}
				}
			}
			glutPostRedisplay();
		}
		else if(hv==0 && ss[s-1]==0 && mal==0)
		{
			for(int i=0;i<9;i++)
			if(cx>0.05+i*f && cx<0.15+i*f)
			for(int j=0;j<9;j++)
			{
				if(cy<0.9-j*l && cy>0.75-j*l)
				{
					if(i<10-s)
					{
						mal=0;
						for(int k=i;k<i+s;k++){if(ship[k][j]==0)ship[k][j]=4;else if(ship[k][j]>6)mal=1;else mal=1;}
					}
					else
					{
						for(int k=i;k<10;k++){if(ship[k][j]==0||ship[k][j]==4)ship[k][j]=5;}
					}
				}
			}
			glutPostRedisplay();
		}
		else if(ss[s-1]==1 || mal==1)
		{
			if(hv==0)
			{
				int i=0,j=0;
				for(i=0;i<=10;i++)
				if(cx>0.05+i*f && cx<0.15+i*f)
				for(j=0;j<=10;j++)
				{
					if(cy<0.9-j*l && cy>0.75-j*l)
					{
						if(i<=10)
						{
							mal=0;
							for(int k=i;k<i+s;k++){if(ship[k][j]==0)ship[k][j]=5;else if(ship[k][j]>6)mal=1;else mal=1;}
						}
					}
				}
				else mal=0;
				glutPostRedisplay();
			}
			else
			{
				int i=0,j=0;				
				for(i=0;i<=10;i++)
				if(cx>0.05+i*f && cx<0.15+i*f)
				for(j=0;j<=10;j++)
				{
					if(cy<0.9-j*l && cy>0.75-j*l)
					{
						if(j<10)
						{
							mal=0;
							for(int k=j;k<j+s;k++){if(ship[i][k]==0)ship[i][k]=5;else if(ship[i][k]>6)mal=1;else mal=1;}
						}
					}
				}
				else mal=0;
				glutPostRedisplay();
			}
		}
	}
	/*{
		if(s==4 && hv ==0 && ss[3]==0)
		{
			float f=0.1,l=0.15;int i,j,count;
			for(i=0;i<9;i++)
			{
				for(j=0;j<9;j++)
				{
					count=0;
					if(ship[i][j]>1)count++;
				}
				if(count>=s)
				{
					count=0;
					for(int k=0;k<10-s;k++)
					{
						if(s==4&&(ship[i][k]==11&&ship[i][k+1]==111&&ship[i][k+2]==111&&ship[i][k+3]==1111))
						{ship[i][k]=0;ship[i][k+1]=0;ship[i][k+2]=0;ship[i][k+3]=0;}
					}
				}
			}
			for(i=0;i<9;i++)
			if(cx>0.05+i*f && cx<0.15+i*f)
			for(j=0;j<9;j++)
			{
				if(cy<0.9-j*l && cy>0.75-j*l)
				{
					if(j<7)
					{
						ship[i][j]=11;ship[i][j+1]=111;ship[i][j+2]=111;ship[i][j+3]=1111;
						glutPostRedisplay();
					}
				}
			}
		}
	}*/
}
void keyboard(unsigned char key,int x,int y)
{
	if(key==27)exit(0);
	else if(key=='5')s=5;
	else if(key=='4')s=4;
	else if(key=='3')s=3;
	else if(key=='2')s=2;
	else if(key=='x')hv=1-hv;
}
void shiporient(int i,int j,float f,float l)
{
	glColor3f(0.5,0.5,0.5);
	//horizontal
	if(oppoints[i][j]==1&&place==1){glColor3f(1,0,0);oppoints[i][j]=2;}
	else if(oppoints[i][j]==2 && place==1)glColor3f(1,0,0);
	if(ship[i][j]==11)
		{
			glBegin(GL_POLYGON);
			glVertex3f(0.08+i*f,0.8625-j*l,0);
			glVertex3f(0.06+i*f,0.825-j*l,0);
			glVertex3f(0.08+i*f,0.7875-j*l,0);
			glVertex3f(0.15+i*f,0.7875-j*l,0);
			glVertex3f(0.15+i*f,0.8625-j*l,0);
			glEnd();
		}
		else if(ship[i][j]==111)
		{
			glBegin(GL_POLYGON);
			glVertex3f(0.05+i*f,0.8625-j*l,0);
			glVertex3f(0.05+i*f,0.7875-j*l,0);
			glVertex3f(0.15+i*f,0.7875-j*l,0);
			glVertex3f(0.15+i*f,0.8625-j*l,0);
			glEnd();
		}
		else if(ship[i][j]==1111)
		{
			glBegin(GL_POLYGON);
			glVertex3f(0.05+i*f,0.8625-j*l,0);
			glVertex3f(0.05+i*f,0.7875-j*l,0);
			glVertex3f(0.12+i*f,0.7875-j*l,0);
			glVertex3f(0.14+i*f,0.825-j*l,0);
			glVertex3f(0.12+i*f,0.8625-j*l,0);
			glEnd();
		}
		//vertical
	else if(ship[i][j]==12)
		{
			glBegin(GL_POLYGON);
			glVertex3f(0.075+i*f,0.85-j*l,0);
			glVertex3f(0.1+i*f,0.88-j*l,0);
			glVertex3f(0.125+i*f,0.85-j*l,0);
			glVertex3f(0.125+i*f,0.75-j*l,0);
			glVertex3f(0.075+i*f,0.75-j*l,0);
			glEnd();
		}
		else if(ship[i][j]==122)
		{
			glBegin(GL_POLYGON);
			glVertex3f(0.075+i*f,0.9-j*l,0);
			glVertex3f(0.075+i*f,0.75-j*l,0);
			glVertex3f(0.125+i*f,0.75-j*l,0);
			glVertex3f(0.125+i*f,0.9-j*l,0);
			glEnd();
		}
		else if(ship[i][j]==1222)
		{
			glBegin(GL_POLYGON);
			glVertex3f(0.075+i*f,0.9-j*l,0);
			glVertex3f(0.075+i*f,0.825-j*l,0);
			glVertex3f(0.1+i*f,0.795-j*l,0);
			glVertex3f(0.125+i*f,0.825-j*l,0);
			glVertex3f(0.125+i*f,0.9-j*l,0);
			glEnd();
		}
}
void hits()
{
	if(place==1)
	{
		glLineWidth(20);
		int i,j;
		float f=0.1;
		for(i=0;i<10;i++)for(j=0;j<10;j++)
		{
			if(points[i][j]==2)
			{
				glColor3f(1,0,0);
				glBegin(GL_LINES);
				glVertex3f(-0.925+i*f,0.8625-j*(f+0.05),0);
				glVertex3f(-0.875+i*f,0.7875-j*(f+0.05),0);
				glEnd();
				glBegin(GL_LINES);
				glVertex3f(-0.875+i*f,0.8625-j*(f+0.05),0);
				glVertex3f(-0.925+i*f,0.7875-j*(f+0.05),0);
				glEnd();
			}
		}
	}
}
void miss()
{
	if(place==1)
	{
		glLineWidth(20);
		int i,j;
		float f=0.1;
		for(i=0;i<10;i++)for(j=0;j<10;j++)
		{
			if(points[i][j]==1)
			{
				glColor3f(0,0,1);
				glBegin(GL_LINES);
				glVertex3f(-0.925+i*f,0.8625-j*(f+0.05),0);
				glVertex3f(-0.875+i*f,0.7875-j*(f+0.05),0);
				glEnd();
				glBegin(GL_LINES);
				glVertex3f(-0.875+i*f,0.8625-j*(f+0.05),0);
				glVertex3f(-0.925+i*f,0.7875-j*(f+0.05),0);
				glEnd();
			}
		}
	}
}
void show()
{
	glLineWidth(3);
	int i,j;
	float f=0.1,l=0.15;
	for(i=0;i<10;i++)for(j=0;j<10;j++)
	{
		if(points[i][j]==3)
		{
			//glColor3f(0.4235,0.79,0.882);
			glColor3f(0,0,0);
			glLineWidth(3);
			glBegin(GL_LINE_LOOP);
			glVertex3f(-0.925+i*f,0.825-j*l,0);
			glVertex3f(-0.9+i*f,0.7875-j*l,0);
			glVertex3f(-0.875+i*f,0.825-j*l,0);
			glVertex3f(-0.9+i*f,0.8625-j*l,0);
			glEnd();
			glBegin(GL_LINES);
			glVertex3f(-0.925+i*f,0.8625-j*l,0);
			glVertex3f(-0.875+i*f,0.7875-j*l,0);
			glVertex3f(-0.875+i*f,0.8625-j*l,0);
			glVertex3f(-0.925+i*f,0.7875-j*l,0);
			glEnd();
		}
	}
}
void opponenthit()
{
	int i,j;float f=0.1,l=0.15;
	if(place==1)
	for(i=0;i<9;i++)for(j=0;j<9;j++)
	{
		if(ship[i][j]==0)
		{
			if(oppoints[i][j]==1)
			{
				//cout<<"opphit";
				glColor3f(0.6,0.85,0.917);
				glBegin(GL_POLYGON);
				glVertex3f(0.05+i*f,0.9-j*l,0);
				glVertex3f(0.05+i*f,0.75-j*l,0);
				glVertex3f(0.15+i*f,0.75-j*l,0);
				glVertex3f(0.15+i*f,0.9-j*l,0);
				glEnd();
				glColor3f(0,0.635,0.91);
				glLineWidth(1);
				glBegin(GL_LINES);
				glVertex3f(0.05+i*f,0.9-j*l,0);
				glVertex3f(0.05+i*f,0.75-j*l,0);
				glEnd();
				glBegin(GL_LINES);
				glVertex3f(0.05+i*f,0.75-j*l,0);
				glVertex3f(0.15+i*f,0.75-j*l,0);
				glEnd();
				glBegin(GL_LINES);
				glVertex3f(0.15+i*f,0.75-j*l,0);
				glVertex3f(0.15+i*f,0.9-j*l,0);
				glEnd();
				glBegin(GL_LINES);
				glVertex3f(0.05+i*f,0.9-j*l,0);
				glVertex3f(0.15+i*f,0.9-j*l,0);
				glEnd();
				glColor3f(4.0/255,0.6667,100.0/255);
				glLineWidth(2);
				glBegin(GL_LINE_LOOP);
				glVertex3f(0.075+i*f,0.825-j*l,0);
				glVertex3f(0.1+i*f,0.7875-j*l,0);
				glVertex3f(0.125+i*f,0.825-j*l,0);
				glVertex3f(0.1+i*f,0.8625-j*l,0);
				glEnd();
				glBegin(GL_LINE_LOOP);
				glVertex3f(0.085+i*f,0.825-j*l,0);
				glVertex3f(0.1+i*f,0.8075-j*l,0);
				glVertex3f(0.115+i*f,0.825-j*l,0);
				glVertex3f(0.1+i*f,0.8425-j*l,0);
				glEnd();
			}
		}
	}
	//glutPostRedisplay();
}
void shiptest()
{
	int i,j;float f=0.1,l=0.15;
	for(i=0;i<9;i++)for(j=0;j<9;j++)
	{
		if(ship[i][j]==4)
		{
			glColor3f(0.4235,0.79,0.882);
			glBegin(GL_POLYGON);
			glVertex3f(0.075+i*f,0.8625-j*l,0);
			glVertex3f(0.075+i*f,0.7875-j*l,0);
			glVertex3f(0.125+i*f,0.7875-j*l,0);
			glVertex3f(0.125+i*f,0.8625-j*l,0);
			glEnd();
		}
		else if(ship[i][j]==5)
		{
			glColor3f(1,0,0);
			glBegin(GL_POLYGON);
			glVertex3f(0.075+i*f,0.8625-j*l,0);
			glVertex3f(0.075+i*f,0.7875-j*l,0);
			glVertex3f(0.125+i*f,0.7875-j*l,0);
			glVertex3f(0.125+i*f,0.8625-j*l,0);
			glEnd();
		}
	}
}
void q()
{
	glLineWidth(1);
	float f=0.1,l=0.15;int i,j;
	for(j=0;j<9;j++)
	for(i=0;i<9;i++)
	{
		glColor3f(0.6,0.85,0.917);
		glBegin(GL_POLYGON);
		glVertex3f(-0.95+i*f,0.9-j*l,0);
		glVertex3f(-0.95+i*f,0.75-j*l,0);
		glVertex3f(-0.85+i*f,0.75-j*l,0);
		glVertex3f(-0.85+i*f,0.9-j*l,0);
		glEnd();
		glColor3f(0,0.635,0.91);
		glBegin(GL_LINES);
		glVertex3f(-0.95+i*f,0.9-j*l,0);
		glVertex3f(-0.95+i*f,0.75-j*l,0);
		//glEnd();
		//glBegin(GL_LINES);
		glVertex3f(-0.95+i*f,0.75-j*l,0);
		glVertex3f(-0.85+i*f,0.75-j*l,0);
		//glEnd();
		//glBegin(GL_LINES);
		glVertex3f(-0.85+i*f,0.75-j*l,0);
		glVertex3f(-0.85+i*f,0.9-j*l,0);
		//glEnd();
		//glBegin(GL_LINES);
		glVertex3f(-0.95+i*f,0.9-j*l,0);
		glVertex3f(-0.85+i*f,0.9-j*l,0);
		glEnd();
	}
	if(place==0)circle();
	else{if(turn==0 && initrecieve==1)play();else if(turn==1 && cliser==0)play();else stop();}
}
void q0()
{
	glLineWidth(1);
	float f=0.1,l=0.15;int i,j;
	for(j=0;j<9;j++)
	for(i=0;i<9;i++)
	{
		if(oppoints[i][j]==1 && place==1 && ship[i][j]==0)opponenthit();
		else
		{
			//opponenthit();
			glColor3f(0.6,0.85,0.917);
			glBegin(GL_POLYGON);
			glVertex3f(0.05+i*f,0.9-j*l,0);
			glVertex3f(0.05+i*f,0.75-j*l,0);
			glVertex3f(0.15+i*f,0.75-j*l,0);
			glVertex3f(0.15+i*f,0.9-j*l,0);
			glEnd();
			//opponenthit();
			shiporient(i,j,f,l);
			//opponenthit();
			glColor3f(0,0.635,0.91);
			glLineWidth(1);
			glBegin(GL_LINES);
			glVertex3f(0.05+i*f,0.9-j*l,0);
			glVertex3f(0.05+i*f,0.75-j*l,0);
			glEnd();
			glBegin(GL_LINES);
			glVertex3f(0.05+i*f,0.75-j*l,0);
			glVertex3f(0.15+i*f,0.75-j*l,0);
			glEnd();
			glBegin(GL_LINES);
			glVertex3f(0.15+i*f,0.75-j*l,0);
			glVertex3f(0.15+i*f,0.9-j*l,0);
			glEnd();
			glBegin(GL_LINES);
			glVertex3f(0.05+i*f,0.9-j*l,0);
			glVertex3f(0.15+i*f,0.9-j*l,0);
			glEnd();
			//opponenthit();
		}
	}
}
void mouse(int buton,int state,int x,int y)
{
	float cx,cy;
	switch(buton)
	{
		case GLUT_LEFT_BUTTON:
			cout<<"im here"<<endl;
			if(state==GLUT_DOWN)//careful about turn
			{
				cout<<x<<" "<<y<<endl;
				x=x-(xx/2);y=(yy/2)-y;
				cx=x/float(xx/2);cy=y/float(yy/2);
				cout<<cx<<"  "<<cy<<endl;
				float f=0.1,l=0.15;
				if(place==1)
				{if((cliser==0 && turn==1)||(cliser==1 && turn==0))
				{
					for(int i=0;i<9;i++)
						if(cx>-0.95+i*f && cx<-0.85+i*f)
							for(int j=0;j<9;j++)
								if(cy<0.9-j*l && cy>0.75-j*l)
									{
										if(points[i][j]==0||points[i][j]==3)points[i][j]=1;
										if(cliser==1)sends(i,j);else sendc(i,j);
										break;
									}
					cout<<"LB hell"<<endl;
					glutPostRedisplay();
				}}
				else if(place==0)
				{
					for(int i=0;i<9;i++)
						if(cx>0.05+i*f && cx<0.15+i*f)
							for(int j=0;j<9;j++)
								if(cy<0.9-j*l && cy>0.75-j*l)
								{
									if(ship[i][j]==4&&mal==0)
									{
										if(s==2 && hv==0){ship[i][j]=11;ship[i+1][j]=1111;ss[1]=1;}
										if(s==2 && hv==1){ship[i][j]=12;ship[i][j+1]=1222;ss[1]=1;}
										if(s==3 && hv==0){ship[i][j]=11;ship[i+1][j]=111;ship[i+2][j]=1111;ss[2]=1;}
										if(s==3 && hv==1){ship[i][j]=12;ship[i][j+1]=122;ship[i][j+2]=1222;ss[2]=1;}
										if(s==4 && hv==0){ship[i][j]=11;ship[i+1][j]=111;ship[i+2][j]=111;ship[i+3][j]=1111;ss[3]=1;}
										if(s==4 && hv==1){ship[i][j]=12;ship[i][j+1]=122;ship[i][j+2]=122;ship[i][j+3]=1222;ss[3]=1;}
										if(s==5 && hv==0){ship[i][j]=11;ship[i+1][j]=111;ship[i+2][j]=111;ship[i+3][j]=111;ship[i+4][j]=1111;ss[4]=1;}
										if(s==5 && hv==1){ship[i][j]=12;ship[i][j+1]=122;ship[i][j+2]=122;ship[i][j+3]=122;ship[i][j+4]=1222;ss[4]=1;}
									}
								}
					cout<<"LB hell"<<endl;
					glutPostRedisplay();
				}
			}break;
		/*case GLUT_RIGHT_BUTTON:
			if(state==GLUT_DOWN)
			{
				//cout<<"rb begin"<<endl;
				cout<<x<<" "<<y<<endl;
				x=x-500;y=300-y;
				cx=x/500.0;cy=y/300.0;
				cout<<cx<<"  "<<cy<<endl;
				float f=0.1,l=0.15;
				//if(cx<0&&cy>0)
				{
					for(int i=0;i<9;i++)
						if(cx>-0.95+i*f && cx<-0.85+i*f)
							for(int j=0;j<9;j++)
								if(cy<0.9-j*l && cy>0.75-j*l){if(points[i][j]==0||points[i][j]==3)points[i][j]=2;oppoints[i][j]=1;break;}//remove opp
					cout<<"RB hell"<<endl;
					glutPostRedisplay();
				}
				//cout<<"rb end"<<endl;
			}break;*/
	}
}

