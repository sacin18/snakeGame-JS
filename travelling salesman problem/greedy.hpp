#include "nodes.hpp"
int d=0;
void solution()
{
if(ans==1)
{
	cout<<"doom";
	for(int i=0;i<count;i++)
	{
		for(int j=i+1;j<count;j++)
		{
			d=0;
			for(int k=j;k<count;k++)
			{
				if(distance(px[i],px[i],px[j],py[j])>distance(px[i],px[i],px[k],py[k]))d++;
			}
			if(d==0)
			{
				line(px[i],py[i],px[j],py[j]);
				cout<<px[i]<<","<<py[i]<<"&&"<<px[j]<<","<<py[j]<<" : "<<distance(px[i],py[i],px[j],py[j])<<endl;
			}
		}
	}
}
}


