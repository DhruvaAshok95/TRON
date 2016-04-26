#include<iostream.h>
#include<conio.h>
#include<process.h>
#include<ctype.h>
#include<graphics.h>
#include<bios.h>
#include<dos.h>
#include"MOUSE.CPP" //refer mouse.cpp in list of files
int px,py; //for moving a pixel p
int qx,qy;  // for moving a pixel q
char player1[20]; //name of player 1 
char player2[20]; //name of player 2
int curkey;
class mm
{
	public: void main_menu();
	void inst();
}m;
void disp_win2() // to display the winner
{
	char s[30];
	int i;
	for(i=0; player2[i]!='\0'; i++)
	{
		s[i]=player2[i];
	}
	s[i]=' ';
	i++;
	s[i]='W';
	i++;
	s[i]='I';
	i++;
	s[i]='N';
	i++;
	s[i]='S';
	i++;
	s[i]='!';
	i++;
	s[i]='\0';
	cleardevice();
	setcolor(WHITE);
	rectangle(10,10,getmaxx()-10,getmaxy()-10);
	setcolor(3);
	settextstyle(3,0,4);
	outtextxy(100,100,s);
	delay(200);
}
void disp_win1() //to display the winner
{
	char s[30];
	int i;
	for(i=0; player1[i]!='\0'; i++)
	{
		s[i]=player1[i];
	}
	s[i]=' ';
	i++;
	s[i]='W';
	i++;
	s[i]='I';
	i++;
	s[i]='N';
	i++;
	s[i]='S';
	i++;
	s[i]='!';
	i++;
	s[i]='\0';
	cleardevice();
	setcolor(WHITE);
	rectangle(10,10,getmaxx()-10,getmaxy()-10);
	setcolor(3);
	settextstyle(3,0,4);
	outtextxy(100,100,s);
	delay(200);
}
int check_collision(int mode)
/* Collision detection is done by getting the NEXT pixel in the direction in which a line from either player is currently moving.
If the returned pixel is NOT black, it indicates that a collision has occured, and appropriately, the winner is decided, 
based on whose line collided. Additionally, it checks if the line goes out of the boundaries as well.
*/
{
	int ret=0;
	if(px<0||px>getmaxx()||py<0||py>getmaxy())
	{ disp_win2(); return 1;}
	else if(qx<0||qx>getmaxx()||qy<0||qy>getmaxy())
	{ disp_win1(); return 1;}

	if (mode==1)    //p up
	{
		int ptemp=py-1;
		int color=getpixel(px,ptemp);
		if(color==10||color==6)
		{
		       disp_win2(); return 1;
		}
	}
	else if (mode==2) //p left
	{
		int ptemp=px-1;
		int color=getpixel(ptemp,py);
		if(color==10||color==6)
		{
			disp_win2(); return 1;
		}
	}
	else if (mode==3) //p right
	{
		int ptemp=px+1;
		int color=getpixel(ptemp,py);
		if(color==10||color==6)
		{
			disp_win2(); return 1;
		}
	}
	else if (mode==4) //p down
	{
		int ptemp=py+1;
		int color=getpixel(px,ptemp);
		if(color==10||color==6)
		{
			disp_win2(); return 1;
		}
	}
	else if (mode==5) //q left
	{
		int qtemp=qx-1;
		int color=getpixel(qtemp,qy);
		if(color==10||color==6)
		{
			disp_win1(); return 1;
		}
	}
	else if (mode==6) //q up
	{
		int qtemp=qy-1;
		int color=getpixel(qx,qtemp);
		if(color==10||color==6)
		{
			disp_win1(); return 1;
		}
	}
	else if (mode==7) //q down
	{
		int qtemp=qy+1;
		int color=getpixel(qx,qtemp);
		if(color==10||color==6)
		{
			disp_win1(); return 1;
		}
	}
	else if (mode==8) //q right
	{
		int qtemp=qx+1;
		int color=getpixel(qtemp,qy);
		if(color==10||color==6)
		{
			disp_win1(); return 1;
		}
	}

	return ret;
}
void start_screen()
{
	int p1=10,q1=0,p2=50,q2=0,p3=180,q3=0,p4=250,q4=0,ph=0,qh=200;
	setcolor(WHITE);
	settextstyle(3,0,6);
	outtextxy(250,200,"TRON");
	while(q1<getmaxy())
	{
		putpixel(p1,q1,3);
		q1++;
		putpixel(p2,q2,10);
		q2++;
		putpixel(p3,q3,6);
		q3++;
		putpixel(p4,q4,3);
		q4++;
		delay(3);
	}
	int qb=0;
	while(qb<getmaxy())
	{
		putpixel(p1,qb,0);
		putpixel(p2,qb,0);
		putpixel(p3,qb,0);
		putpixel(p4,qb,0);
		qb++;
		delay(3);
	}

	getch();
}
void mm::inst() //Instructions on how to play the game
{
	cleardevice();
	settextstyle(3,0,2);
	char ch;
	int flag=0;
	setcolor(WHITE);
	rectangle(10,10,getmaxx()-10,getmaxy()-10);
	setcolor(3);
	outtextxy(30,30,"1. This is a two player game.");
	outtextxy(30,60,"2. Player 1 uses W A S D to move.");
	outtextxy(30,90,"3. Player 2 uses arrow keys to move.");
	outtextxy(30,120,"4. The aim is to block the other person's path trail.");
	outtextxy(30,150,"5. A player loses if they crash into the opponents trail");
	outtextxy(30,170,"or their own trail.");
	outtextxy(30,250,"Enter b to go back to the previous menu.");
	while(flag==0)
	{
		ch=getch();
		switch(ch)
		{
			case 'b' : flag=1; main_menu();
		}
	}
}
void enter_names()
{
	cleardevice();
	cout<<"Player 1 : Enter your name : ";
	cin>>player1;
	cout<<"Player 2 : Enter your name : ";
	cin>>player2;
	clrscr();

}
void start_game()
{
// the program uses bioskey(int) to return what key has been pressed, and therefore decide how each user's line should behave.
	
	cleardevice();
	int key,ree=0, curkey2=8292, curkey3=19200;px=0; py=200; qy=200; qx=getmaxx()-1;
	while(curkey!=283&&ree!=1)
	{

		putpixel(px,py,10);
		putpixel(qx,qy,6);
		if(bioskey(1))
		{
			key=bioskey(0);
 //			cout<<key;
			delay(10);
			if(ree==0)
			{
			switch(curkey2)
			{
				case 4471 : py--; ree=check_collision(1); break;
				case 7777 : px--; ree=check_collision(2); break;
				case 8292 : px++;ree=check_collision(3); break;
				case 8051 : py++;ree=check_collision(4); break;
			}
			}
			if(ree==0)
			{
			switch(curkey3)
			{
				case 19200 : qx--; ree=check_collision(5); break;
				case 18432 : qy--; ree=check_collision(6); break;
				case 20480 : qy++; ree=check_collision(7); break;
				case 19712 : qx++; ree=check_collision(8); break;
			}
			}
		}
		else
		{
			delay(10);
//			cout<<"no";
			if(ree==0)
			{
			switch(curkey2)
			{
				case 4471 :ree=check_collision(1); py--; break;
				case 7777 :ree=check_collision(2); px--; break;
				case 8292 :ree=check_collision(3); px++; break;
				case 8051 :ree=check_collision(4); py++; break;
			}
			}
			if(ree==0)
			{
			switch(curkey3)
			{
				case 19200 :ree=check_collision(5); qx--; break;
				case 18432 :ree=check_collision(6); qy--; break;
				case 20480 :ree=check_collision(7); qy++; break;
				case 19712 :ree=check_collision(8); qx++; break;
			}
			}
		  //	delay(10);
		}
		curkey=key;
		if(key==4471||key==7777||key==8292||key==8051)curkey2=key;
		if(key==19200||key==18432||key==20480||key==19712)curkey3=key;
	}
}
void mm::main_menu()
{
	cleardevice();
	int flag=0;
	rectangle(200,100,400,150);
	rectangle(200,200,400,250);
	rectangle(200,300,400,350);
	setcolor(3);
	settextstyle(3,0,5);
	outtextxy(230,30,"-TRON-");
	settextstyle(3,0,2);
	outtextxy(230,110,"START GAME");
	outtextxy(230,210,"INSTRUCTIONS");
	outtextxy(230,310,"EXIT");
	int i=0;
	cx=10; cy=10;
	while(flag==0)
	{
		mo.show_mouse();
		mo.get_status(); //maps click of mouse
		if(i==0){ cx=10; cy=10;delay(100); }
		if((cx>=200&&cx<=400)&&(cy>=100&&cy<=150)){mo.hide_mouse(); flag=1; enter_names(); start_game();}
		else if((cx>=200&&cx<=400)&&(cy>=200&&cy<=250)){mo.hide_mouse();flag=1; inst();}
		else if((cx>=200&&cx<=400)&& (cy>=300&&cy<=350)){exit(0);}
		i=1;
		delay(100);
	}


}
char again() //asking the user if he/she wants to play again
{
	cleardevice();
	setcolor(WHITE);
	char ch;
	rectangle(10,10,getmaxx()-10,getmaxy()-10);
	setcolor(3);
	outtextxy(30,30,"PLAY AGAIN? Y/N");
	ch=getch();
	ch=toupper(ch);
	if(ch=='Y') { return ch; }
	else if(ch=='N') { return ch; }
	else again();
}
void main()
{
	int a=9, b=2,i=0;
	initgraph(&a,&b,"c://tc//bgi");
	char ch='N';
	if(i==0)
	start_screen();
	while(1)
	{
		if(ch=='Y')
		{
			cleardevice();
			start_game();
			getch();
			getch();
		}
		else
		{
			cleardevice();
			m.main_menu();
			getch(); getch();
		}
		ch=again();
		
	}
}
