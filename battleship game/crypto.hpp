#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<iostream>
using namespace std;
long int ppp=7,qqq=17,nnn=0,ttt=0,flag=0,eee[100]={0},ddd[100]={0},tempp[100]={0},jjj=0,mmm[100]={0},ennn[100]={0},iii=0;
char msgg[100]={0};
int prime(long int);
void ce();
long int cd(long int);
void encrypt();
void decrypt(); 
char* enmain(char *message) 
{
	//printf("\nENTER FIRST PRIME NUMBER\n");
 
	//scanf("%d",&p);
	//int x,y;
	//p=7;
	//flag=prime(p);
	/*if(flag==0) 
	{
		printf("\nWRONG INPUT\n");
		getch();
		exit(1);
	}*/
 
//		printf("\nENTER ANOTHER PRIME NUMBER\n");
 
	//scanf("%d",&q);
	//q=17;
	//flag=prime(q);
	/*if(flag==0||p==q) 
	{
		printf("\nWRONG INPUT\n");
		getch();
		exit(1);
	}*/
	//printf("\nENTER MESSAGE\n");
	//fflush(stdin);
	//scanf("%s",msg);
	//msg[4]=x+48;msg[6]=y+48;
	strcpy(msgg,message);
	for(iii=0;iii<strlen(msgg);iii++)mmm[iii]=msgg[iii];
	//printf("\nmessage :: %s",msgg);
	nnn=ppp*qqq;
	ttt=(ppp-1)*(qqq-1);
	//printf("\n");
	//for(i=0;i<strlen(msg);i++)printf("%d\t",m[i]);
	//printf("\n");
	ce();
 
//	printf("\nPOSSIBLE VALUES OF e AND d ARE\n");
 
/*	for (i=0;i<j-1;i++)
 
	printf("\n%ld\t%ld",e[i],d[i]);*/
 
	encrypt();
	for(iii=0;iii<strlen(msgg);iii++)msgg[iii]=ennn[iii];
	strcpy(message,msgg);
	//decrypt();
	return message;
} 
int prime(long int pr) 
{
	int i;
	jjj=sqrt(pr);
	for (i=2;i<=jjj;i++) 
	{ 
		if(pr%i==0)return 0;
	}
	return 1;
}
void ce() 
{ 
	int k;
	k=0;
	for (iii=2;iii<ttt;iii++) 
	{
		if(ttt%iii==0)continue;
		flag=prime(iii);
		if(flag==1&&iii!=ppp&&iii!=qqq) 
		{
			eee[k]=iii;
			flag=cd(eee[k]);
			if(flag>0) 
			{
				ddd[k]=flag;
				k++;
			}
			if(k==99)break;
		}
	}
	//printf("\n");
	//for(i=0;i<strlen(msg);i++)printf("%d\t",m[i]);
	//printf("\n");
} 
long int cd(long int x) 
{
	long int k=1;
	while(1) 
	{
		k=k+ttt;
		if(k%x==0)return(k/x);
	}
	//printf("\n");
	//for(i=0;i<strlen(msg);i++)printf("%d\t",m[i]);
	//printf("\n");
}
void encrypt() 
{
	long int pt,ct,key=eee[0],k,len;
	iii=0;
	len=strlen(msgg);
	while(iii!=len) 
	{
		pt=mmm[iii];
		pt=pt-128;
		k=1;
		//printf("\nkey :: %d and n = %d\n",key,n);
		for (jjj=0;jjj<key;jjj++) {
		//	printf("k=%d pt=%d\n",k,pt);
			k=k*pt;
			k=k%nnn;
		//	printf("k=%d pt=%d\n",k,pt);
		}
		tempp[iii]=k;
		ct=k+128;
		ennn[iii]=ct;
		iii++;
	}
	ennn[iii]=-1;
	//printf("\nTHE ENCRYPTED MESSAGE IS :: ");
	//for (iii=0;ennn[iii]!=-1;iii++)printf("%c",ennn[iii]);
}
char* demain(char *message)
{
	//cout<<"executed 0"<<endl;	
	strcpy(msgg,message);
	for(iii=0;iii<strlen(msgg);iii++)mmm[iii]=msgg[iii];
	//printf("\nmessage :: %s",msgg);
	nnn=ppp*qqq;
	ttt=(ppp-1)*(qqq-1);
	//printf("\n");
	//for(i=0;i<strlen(msg);i++)printf("%d\t",m[i]);
	//printf("\n");
	//cout<<"executed 1 "<<msgg<<endl;	
	ce();
	//cout<<"executed 2"<<endl;	
	decrypt();
	//cout<<"executed 3"<<endl;	
	for(iii=0;iii<strlen(msgg);iii++)msgg[iii]=mmm[iii];
	//cout<<"executed 4"<<endl;	
	strcpy(message,msgg);
	return message;
}
void decrypt()
{
	long int pt=0,ct=0,key=ddd[0],k=0;
	iii=0;
	//cout<<key<<endl;
	ennn[strlen(msgg)]=-1;
	while(ennn[iii]!=-1) 
	{
		ct=mmm[iii]-128;
		k=1;
		for (jjj=0;jjj<key;jjj++) 
		{
			k=k*ct;
			k=k%nnn;
		}
		pt=k+128;
		mmm[iii]=pt;
		iii++;
	}
	mmm[iii]=-1;
	//printf("\nTHE DECRYPTED MESSAGE IS:: ");
	//for(iii=0;mmm[iii]!=-1;iii++)cout<<(char)mmm[iii];
}

