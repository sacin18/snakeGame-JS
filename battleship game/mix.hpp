#include<GL/glut.h>
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include <unistd.h>
#include <stdio.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include "crypto.hpp"
using namespace std;
int points[10][10]={0};
int oppoints[10][10]={0};
int ship[10][10]={0};
int turn=0;
int place=0;//placing the boats
int s=2,mal=0;
int ss[5]={0};
int hv=0;

int init=0;
int change=0;

char sendbuf[30],recbuf[30];
int sused[200],snow=0;
int cused[200]={0},cnow=0;
//socket var
int sockfd, newsockfd, portno,n;
socklen_t clilen;
struct sockaddr_in serv_addr, cli_addr;
struct hostent *server;
int decider=0;
int cliser=0;

void funs()
{

   
   /* First call to socket() function */
   sockfd = socket(AF_INET, SOCK_STREAM, 0);
   
   if (sockfd < 0) {
      perror("ERROR opening socket");
      exit(1);
   }
   
   /* Initialize socket structure */
   bzero((char *) &serv_addr, sizeof(serv_addr));
   portno = atoi("12305");
   
   serv_addr.sin_family = AF_INET;
   serv_addr.sin_addr.s_addr = INADDR_ANY;
   serv_addr.sin_port = htons(portno);
	
	if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
      perror("ERROR on binding");
      exit(1);
   }
      
   /* Now start listening for the clients, here process will go in sleep mode and will wait for the incoming connection */
   
   listen(sockfd,5);
   clilen = sizeof(cli_addr);
   
   /* Accept actual connection from the client */
   newsockfd=accept(sockfd,(struct sockaddr *)&cli_addr,&clilen);
	
   if (newsockfd < 0) {
      perror("ERROR on accept");
      exit(1);
   }
//for(int h=0;h<200;h++)sused[h]=-1;
init=1;
	
}
//server side
void sends(int i,int j)
{
	//change=0;	
	if(place==3)return;
	bzero(sendbuf,30);
    if(points[i][j]==1 && turn==0)
    {
        for(int k=0;k<200;k++)if(sused[k]==((i+1)*10+j)){cout<<i<<j<<endl;return;}
        sused[snow]=(i+1)*10+j;snow++;
        sendbuf[0]='0';sendbuf[1]='p';sendbuf[2]='t';sendbuf[3]='o';sendbuf[4]='x';sendbuf[5]=i+48;sendbuf[6]='y';sendbuf[7]=j+48;sendbuf[8]='1';
        //send sendbuff to client
		strcpy(sendbuf,enmain(sendbuf));
	n = write(newsockfd,sendbuf,9);
		cout<<"server sent "<<sendbuf<<endl;  
		//listen(sockfd,1); //newly added 
  if (n < 0) {
      perror("ERROR writing to socket");
      exit(1);
		}
		//cout<<"haha";
		turn=2; //newly added
   }	


    
}
void recieves()
{
	if(place==3)return;
    bzero(recbuf,30);
	bzero(sendbuf,30);
    //store client message in recbuf
/*n =*/ read( newsockfd,recbuf,9);
	cout<<"server recieved  "<<recbuf<<endl;
	strcpy(recbuf,demain(recbuf));
   //cout<<"decrypted message "<<recbuf<<endl;
   /*if (n < 0) {
      perror("ERROR reading from socket");
      exit(1);
   }*/

    //strcpy(recbuf,message);

    //strcpy(recbuf,"1otpx7y71");
cout<<turn<<endl;
    if(recbuf[0]=='0')
    {
        if(recbuf[1]=='o'&&recbuf[2]=='t'&&recbuf[3]=='p')
        {
            int x,y;
            x=recbuf[5]-48;y=recbuf[7]-48;
            if(recbuf[8]=='1');//{turn=0;return;}
            else if(recbuf[8]=='2')
            {
                points[x][y]=2;
                cout<<"points["<<x<<"]["<<y<<"]"<<"now :: "<<points[x][y]<<endl;
                turn=1;change=1;
				glutPostRedisplay();
            }
        }
    }
    else if(recbuf[0]=='1')
    {
        if(recbuf[1]=='o'&&recbuf[2]=='t'&&recbuf[3]=='p')
        {
            int x,y;
            x=recbuf[5]-48;y=recbuf[7]-48;
            oppoints[x][y]=1;
            if(ship[x][y]>1)oppoints[x][y]=2;
            //acknowledge to client
            if(oppoints[x][y]==2)
{sendbuf[0]='1';sendbuf[1]='p';sendbuf[2]='t';sendbuf[3]='o';sendbuf[4]='x';sendbuf[5]=x+48;sendbuf[6]='y';sendbuf[7]=y+48;sendbuf[8]='2';}
			else 
{sendbuf[0]='1';sendbuf[1]='p';sendbuf[2]='t';sendbuf[3]='o';sendbuf[4]='x';sendbuf[5]=x+48;sendbuf[6]='y';sendbuf[7]=y+48;sendbuf[8]='1';}
            //send sendbuf to client as acknowledge

			strcpy(sendbuf,enmain(sendbuf));
	/*n =*/ write(newsockfd,sendbuf,9);
   	cout<<"server sent "<<sendbuf<<endl;
  /*if (n < 0) {
      perror("ERROR writing to socket");
      exit(1);*/
			change=1;
            turn=0;
			glutPostRedisplay();
        }
    }
}
void func()
{

	portno = atoi("12305");
   
   /* Create a socket point */
   sockfd = socket(AF_INET, SOCK_STREAM, 0);
   
   if (sockfd < 0) {
      perror("ERROR opening socket");
      exit(1);
   }
	//change ip address here
   server = gethostbyname("127.0.0.1");
   
   if (server == NULL) {
      //fprintf(stderr,"ERROR, no such host\n");
      //exit(0);
		cliser=1;return;
   }
   
   bzero((char *) &serv_addr, sizeof(serv_addr));
   serv_addr.sin_family = AF_INET;
   bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
   serv_addr.sin_port = htons(portno);
   
   /* Now connect to the server */
   if (connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
      //perror("ERROR connecting");
      //exit(1);
		cliser=1;return;cout<<"i should be server"<<endl;
   }

init=1;

}



void sendc(int i,int j)
{
	//change=0; 
	if(place==3)return;   
	if(points[i][j]==1 && turn==1)
    {
        for(int k=0;k<200;k++)if(cused[k]==((i+1)*10+j))return;
        cused[cnow]=(i+1)*10+j;cnow++;
        sendbuf[0]='1';sendbuf[1]='o';sendbuf[2]='t';sendbuf[3]='p';sendbuf[4]='x';sendbuf[5]=i+48;sendbuf[6]='y';sendbuf[7]=j+48;sendbuf[8]='1';
        //send sendbuff to server
		strcpy(sendbuf,enmain(sendbuf));
	n = write(sockfd,sendbuf,9);
		cout<<"client sent "<<sendbuf<<endl; 
		//cout<<"client dec sent "<<demain(sendbuf)<<endl;   
  if (n < 0) {
      perror("ERROR writing to socket");
      exit(1);
	}
		turn=2;

    }
}
void recievec()
{
    char *message;
cout<<turn<<endl;
    //store client message in recbuf

/*n =*/ read(sockfd,recbuf,9);
	cout<<"client recieved  "<<recbuf<<endl;
   strcpy(recbuf,demain(recbuf));
   cout<<"decrypted mess "<<recbuf<<endl;
   /*if (n < 0) {
      perror("ERROR reading from socket");
      exit(1);
   }*/


    //strcpy(recbuf,message);

    //strcpy(recbuf,"1otpx7y71");
	if(place==3)return;
    if(recbuf[0]=='1')
    {
        if(recbuf[1]=='p'&&recbuf[2]=='t'&&recbuf[3]=='o')
        {
            int x,y;
            x=recbuf[5]-48;y=recbuf[7]-48;
            if(recbuf[8]=='1');//{turn=1;return;}
            else if(recbuf[8]=='2')
            {
                points[x][y]=2;
                cout<<"points["<<x<<"]["<<y<<"]"<<"now :: "<<points[x][y]<<endl;
                turn=0;change=1;
				glutPostRedisplay();
            }
        }
    }
    else if(recbuf[0]=='0')
    {
        if(recbuf[1]=='p'&&recbuf[2]=='t'&&recbuf[3]=='o')
        {
            int x,y;cout<<"mad man"<<endl;
            x=recbuf[5]-48;y=recbuf[7]-48;
            oppoints[x][y]=1;
            if(ship[x][y]>1)oppoints[x][y]=2;
            //acknowledge to client
            if(oppoints[x][y]==2)
{sendbuf[0]='0';sendbuf[1]='o';sendbuf[2]='t';sendbuf[3]='p';sendbuf[4]='x';sendbuf[5]=x+48;sendbuf[6]='y';sendbuf[7]=y+48;sendbuf[8]='2';}
			else 
{sendbuf[0]='0';sendbuf[1]='o';sendbuf[2]='t';sendbuf[3]='p';sendbuf[4]='x';sendbuf[5]=x+48;sendbuf[6]='y';sendbuf[7]=y+48;sendbuf[8]='1';}
            //send sendbuf to client as acknowledge
			strcpy(sendbuf,enmain(sendbuf));
/*n =*/ write(sockfd,sendbuf,9);
		cout<<"client sent "<<sendbuf<<endl;   
  /*if (n < 0) {
      perror("ERROR writing to socket");
      exit(1);*/
			change=1;
            turn=1;
			glutPostRedisplay();
        }
    }
}

