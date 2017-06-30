#include "mousefunc.hpp"
#include<iomanip>
static float m[20][20];
static int state=0;
static int statec=0;
static int trials=0;
static int stack[20][20];
static float sum[20]={0};
float sumstack[20]={0};int sumcount=0;
float carry[20]={0};
static int officialstack[20]={0};
void resetall()
{
	for(int i=0;i<20;i++)
	for(int j=0;j<20;j++)
	{
		m[i][j]=0;stack[i][j]=0;
		sum[i]=0;sumstack[i]=0;carry[i]=0;
		officialstack[i]=0;px[i]=py[i]=c[i]=path[i]=0;
	}
	state=0;statec=0;trials=0;sumcount=0;count=0;done=0;ans=0;pc=0;
	ready=0;glutPostRedisplay();reset=0;
}
void matrix()
{
	cout<<endl<<"here is you matrix"<<endl;
	for(int i=1;i<=count;i++)
	{
		for(int j=2+i-1;j<=count;j++)
		{
			m[j][i]=m[i][j]=distance(px[i-1],py[i-1],px[j-1],py[j-1]);
		}
	}
	for(int i=1;i<=count;i++)m[i][i]=1200;
	for(int i=1;i<=count;i++)
	{
		for(int j=1;j<=count;j++)
		{
			cout<<setw(7)<<m[i][j]<<"  ";
		}
		cout<<endl;
	}
}
void remat()
{
	for(int i=1;i<=count;i++)
	{
		for(int j=2+i-1;j<=count;j++)
		{
			m[j][i]=m[i][j]=distance(px[i-1],py[i-1],px[j-1],py[j-1]);
		}
	}
	for(int i=1;i<=count;i++)m[i][i]=1200;
	statec=0;
}
int min(int row)
{
	int c=0,i;
	for(i=1;i<=count;i++)
	{
		c=0;
		for(int j=1;j<=count;j++)
		{
			if(m[row][i]>m[row][j]||m[row][i]==0)c++;
		}
		if(c==0)
		{
			if(pc==0)
			{
				//cout<<m[row][i]<<"  "<<pc<<"  ";
				sumstack[sumcount]=m[row][i];
				m[row][i]=m[i][row]=1200;
				for(int h=1;h<=count;h++)
				{
					m[h][i]=1200;
				}
				path[pc]=i-1;
				pc=1;
				sumcount++;
				break;
			}
			else
			{
				//cout<<m[row][i]<<"  "<<pc<<"  ";
				sumstack[sumcount]=m[row][i];
				path[pc]=i-1;
				m[row][i]=m[i][row]=1200;
				++pc;
				sumcount++;
				break;
			}
		}
	}
	return i;	
}
/*void TSP()
{
	for(int i=1;i<=count;i++)
	{
			cout<<min(i);cout<<"  "<<pc-1<<"  "<<path[pc-1]<<"   "<<count<<endl;	
	}
	ready=1;		
}*/
void TSP(int k)
{
	//remat();
	sumcount=0;
	state=k;
	stack[trials][statec]=state;statec++;
	while(statec!=count)
	{
		int j;
		j=state;
		state=min(state);
		stack[trials][statec]=state;
		//cout<<state<<endl;
		/*for(int i=1;i<=count;i++)
		{
			for(int j=1;j<=count;j++)
			{
				cout<<setw(7)<<m[i][j]<<"  ";
			}
			cout<<endl;
		}cout<<endl;*/
		for(int i=0;i<statec;i++)
		{
			if(stack[trials][statec]==stack[trials][i])
			{
				sumcount--;
				state=min(j);
				stack[trials][statec]=state;
				i=0;
			}
		}
		statec++;
	}
	stack[trials][statec]=k;
	//if(trials!=count-1)TSP(trials);
	cout<<endl<<endl;
	for(int i=0;i<sumcount;i++)
	{
		cout<<sumstack[i]<<"+";
	}
	int r=(stack[trials][statec-1])-1;
	cout<<distance(px[r],py[r],px[k],py[k])<<endl;
	for(int i=0;i<sumcount;i++)
	{
		sum[trials]=sum[trials]+sumstack[i];
	}
	cout<<(sum[trials]=sum[trials]+distance(px[r],py[r],px[k],py[k]))<<endl;
	trials++;
	//cout<<endl<<endl;
	ready=1;		
}
void solution()
{
	for(int j=0;j<count;j++)
	{
		for(int i=0;i<=count;i++)
		{
			cout<<"|||||"<<stack[j][i];
		}
		cout<<endl;	
	}
	int ct=0;
	for(int i=0;i<count;i++)
	{
		ct=0;
		for(int j=0;j<count;j++)
		{
			if(sum[i]>sum[j])ct++;
		}
		if(ct==0)
		{
			cout<<endl<<endl;
			for(int k=0;k<=count;k++)
			{
				officialstack[k]=stack[i][k];
				cout<<"|||||"<<stack[i][k];
			}
		}
	}
	//draw
	int draw1,draw2;
	for(int i=0;i<count;i++)
	{
		draw1=officialstack[i]-1;
		draw2=officialstack[i+1]-1;
		line(px[draw1],py[draw1],px[draw2],py[draw2]);
	}
}
