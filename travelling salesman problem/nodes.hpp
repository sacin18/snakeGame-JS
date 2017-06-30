//#include "mousefunc.hpp"
#include "matrix.hpp"
void nodes()
{
	glutMouseFunc(mouse);
	glutKeyboardFunc(keyboard);
	square(px[count-1],py[count-1],0,0);
	for(int i=0;i<count;i++)square(px[i],py[i],0,c[i]);
	if(ans==0)
	{
		for(int i=0;i<count&&done==1;i++)
		{
			for(int j=i+1;j<count;j++)
			{
				line(px[i],py[i],px[j],py[j]);
			}
		}	
	}
	else
	{//testing--below
	int d=0;
		for(int i=0;i<count;i++)
		{
			for(int j=i+1;j<count;j++)
			{
				d=0;
				//algorithm part
				/*for(int k=j;k<count-1;k++)
				{
					if(distance(px[i],py[i],px[j],py[j])>distance(px[i],py[i],px[k],py[k]))
					{
						d++;
					}
				}*/
				if(d==0)
				{
					line(px[i],py[i],px[j],py[j]);
					cout<<px[i]<<","<<py[i]<<"&&"<<px[j]<<","<<py[j]<<" : "<<distance(px[i],py[i],px[j],py[j])<<endl;
				}
			}
		}
		matrix();
		//TSP(1);	
		for(int q=1;q<=count;q++)
		{
			remat();
			TSP(q);
		}
		//TSP(1);
	}
}
