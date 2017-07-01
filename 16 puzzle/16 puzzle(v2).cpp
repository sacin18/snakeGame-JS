#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<algorithm>
#include<time.h>
#include<cstdio>
#include<windows.h>
#include<limits.h>
using namespace std;
int puz[4][4];char spot=178;
void print();
int main()
{
	int sol[4][4],k=0,end=1,x=0,y=0,count=0,a[16]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16},win=0,parity=1,r,steps=0;
	char s=0,buffer[1000]={0};
	for(int i=0;i<4;i++)for(int j=0;j<4;j++){puz[i][j]=sol[i][j]=a[k];k++;}
	cout<<endl<<endl<<endl;
	cout<<"||====\\   ||    ||  =====//   ====//  ||        ||======         ||    //====\\"<<endl;
	cout<<"||    ||  ||    ||     //       //    ||        ||               ||    ||"<<endl;
	cout<<"||====//  ||    ||    //       //     ||        ||======         ||    ||====\\"<<endl;
	cout<<"||        ||    ||   //       //      ||        ||               ||    ||    ||"<<endl;
	cout<<"||         \\====//  //=====  //=====  ||=====   ||======         ||    \\====//"<<endl; 
	cout<<endl<<endl<<"press any key to continue....";getch();
	system("CLS");
	print();
	cout<<endl<<endl<<"This is what our result should look like."<<endl<<"			press any key to play the game..."<<endl;getch();
	system("CLS");
	cout<<"use the keys ::"<<endl;
	cout<<"			        _____     			"<<endl;
	cout<<"			       |  "<<char(24)<<"  |				"<<endl;
	cout<<"			  _____|_____|_____				"<<endl;
	cout<<"			 | <-  |  "<<char(25)<<"  | ->  |"<<endl;
	cout<<"			 |_____|_____|_____|"<<endl;
	cout<<endl<<"to move from occupied blocks to the empty block"<<endl;
	cout<<endl<<"press esc at any time after this screen to exit"<<endl;
	cout<<"press any other key to continue"<<endl;
	getch();
	again:
	steps=0;
	parity=1;
	while(parity==1)
	{
		//system("CLS");
		parity=0;
		srand(time(NULL));
		r=rand();
		for(int i=1;i<=r%17;i++)random_shuffle(&a[0],&a[15]);
		//for(int i=0;i<16;i++)cout<<a[i]<<"  ";
		k=0;
		for(int i=0;i<4;i++)for(int j=0;j<4;j++){puz[i][j]=a[k];k++;}
		for(int i=0;i<16;i++)for(int j=i;j<16;j++)if(a[i]>a[j])parity++;
		//cout<<parity<<endl;
		if(parity==0)parity=1;
		else if((parity=parity%2)==1)continue;
	}
	system("CLS");
	print();
	//system("CLS");
	int bi=0;
	for(bi;bi<1000;bi++)buffer[bi]=0;
	bi=0;
	while(end)
	{	
		for(int i=0;i<4;i++)for(int j=0;j<4;j++)if(puz[i][j]==16){x=i;y=j;}
		count=0;
		if((GetAsyncKeyState ( VK_DOWN ) & SHRT_MAX)&&x!=0){puz[x][y]=(puz[x][y]+puz[x-1][y])-(puz[x-1][y]=puz[x][y]);system("CLS");print();}
		else if((GetAsyncKeyState ( VK_RIGHT ) & SHRT_MAX)&&y!=0){puz[x][y]=(puz[x][y]+puz[x][y-1])-(puz[x][y-1]=puz[x][y]);system("CLS");print();}
		else if((GetAsyncKeyState ( VK_UP ) & SHRT_MAX)&&x!=3){puz[x][y]=(puz[x+1][y]+puz[x][y])-(puz[x+1][y]=puz[x][y]);system("CLS");print();}
		else if((GetAsyncKeyState ( VK_LEFT ) & SHRT_MAX)&&y!=3){puz[x][y]=(puz[x][y]+puz[x][y+1])-(puz[x][y+1]=puz[x][y]);system("CLS");print();}
		else if(GetAsyncKeyState ( VK_ESCAPE ))end=0;
		if(end==0)break;
		//else {system("CLS");print();}
		if(puz[3][2]==15)for(int i=0;i<4;i++)for(int j=0;j<4;j++)if(puz[i][j]==sol[i][j])count++;
		if(count==16){end=0;win=1;break;}
		if(getch()==224){buffer[bi]=getch();bi++;}
		
		//if(count>=12&&count<16)
		//if((puz[2][2]==12&&puz[2][3]==11)||(puz[3][3]==12&&puz[3][2]==11)||(puz[2][3]==12&&puz[3][3]==11)||(puz[3][3]==12&&puz[3][2]==11)||(puz[3][2]==12&&puz[2][3]==11&&puz[3][3]==15)||(puz[2][2]==12&&puz[3][3]==11&&puz[3][2]==15))
		//{cout<<"very sorry !! this puzzle is not solvable due to parity error, hence a new one will be given on a key press";getch();goto again;}
		
	}
	//Sleep(1000);
	//for(int j=0;j<1000;j++){if(getch()==224)buffer[j]=getch();else break;}
	for(int j=0;j<1000;j++)if(buffer[j]!=0)steps++;else break;
	//Sleep(1000);
	system("CLS");
	if(win==1)
	{
		cout<<"\\    //  //==\\   ||   ||        \\      //\\      //  ||  ||\\   ||"<<endl;
		cout<<" \\  //  ||   ||  ||   ||         \\    //  \\    //   ||  || \\  ||"<<endl;
		cout<<"  ||    ||   ||  ||   ||          \\  //    \\  //    ||  ||  \\ ||"<<endl;
		cout<<"  ||     \\==//    \\==//            \\//      \\//     ||  ||   \\||"<<endl;
		cout<<endl<<endl<<"you have made "<<steps<<" moves!!"<<endl<<endl;
		Sleep(2000);
	}
	else {cout<<"ok, maybe next time!";Sleep(1000);return 0;}
	cout<<endl<<endl<<"wanna play again!! (y//n) ::";
	s=getch();cout<<s<<endl;
	while(s!='y'&&s!='n'){cout<<"wrong input!! press again :: ";s=getch();cout<<s<<endl;}
	if(s=='y'){end=1;win=0;goto again;}
	else if(s=='n')return 0;
	getch();
}
void print()
{
	for(int i=0;i<4;i++)
	{
		cout<<"                |               |               |               |"<<endl<<"                |               |               |               |"<<endl;
		for(int j=0;j<4;j++)
		{
			if(puz[i][j]==16)cout<<"\t"<<" "<<"\t"<<"|";
			else cout<<"\t"<<puz[i][j]<<"\t"<<"|";
		}
		cout<<endl<<"                |               |               |               |"<<endl;
		cout<<"________________|_______________|_______________|_______________|"<<endl;
	}
}
