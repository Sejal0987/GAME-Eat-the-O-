// Work on Turbo C++...........
#include<fstream.h>
#include<graphics.h>
#include<conio.h>
#include<stdlib.h>
#include<dos.h>
#include<process.h>
#define CLIP_ON 1
fstream file;
const int w=20;
const int h=20;
int x=0,y=0,fx,fy,l=200,b=200;
int scr=0;
int dely=10;
class result
{
  public:
  int score11;
  char name[20];
void input()
  {
  cout<<"enter your name"<<endl;
  gotoxy(2,2);
  cin>>name;

  }
  void output()
  {

  cout<<"   name and score is"<<endl;

  cout<<"     "<<name<<endl;

  cout<<"     "<<score11<<endl;
  }
} obj;
void page3()
{
  cleardevice();
setbkcolor(1);
  file.open("result.dat",ios::in|ios::out|ios::app|ios::binary);
  obj.input();
  file.write((char*)&obj,sizeof(obj));
  file.close();
}
void page4()
{
  cleardevice();
  file.open("result.dat",ios::in|ios::out|ios::app|ios::binary);
  file.seekg(0);
  while(file.read((char*)&obj,sizeof(obj)))
    {
      obj.output();
      cout<<endl;
    }
    file.close();
}
void page2()
{
   setcolor(RED);
   settextstyle(4,0,3);
   setcolor(14);
   circle(200,220,100);
   circle(450,220,100);
   outtextxy(130,210,"a. play game");
   outtextxy(380,210,"b. show result");
   char  c;
   if (kbhit)
   {
      c=getch();
      if(c=='a')
      {
	 page3();
	 cleardevice();
      }
      else if (c=='b')
      {
	 page4();
	 getch();
	 exit(0);
      }
      else
	exit(0);
   }
}

void fropage()   //front page
{
  int i,j,z,k,l;
  int gd=DETECT,gm;
  initgraph(&gd,&gm,"C:\\turboc3\\bgi");
  setbkcolor(7);
  setcolor(12);
  for(i=0;i<360;i++)
  {
    cleardevice();
    setcolor(12);
    for(int j=0;j<5;j++)
      ellipse(310+j,85+j,0,i,135,30);
    delay(10);
  }
  setfillstyle(8,4);
  settextstyle(4,0,3);
  setcolor(12);
  outtextxy(20,15,"INSTITUTE OF ENGINEERING AND TECHNOLOGY (IET-DAVV)");
  outtextxy(250,64,"2018-2022");
  outtextxy(200,130,"A game-eat the 'o'");
  settextstyle(3,0,2);
  outtextxy(20,250,"C++ Project");
  outtextxy(20,275,"Made using graphics");
  outtextxy(350,250,"Submitted by:");
  outtextxy(350,275,"Sejal Jaiswal");
  outtextxy(350,300,"Information Technology");
  getch();
  cleardevice();
}

void delydec()      //increase the SPEED
{
  if(5%scr==0)
  {
    dely--;
  }
}
void ifover(int scr)
{
  cleardevice();
  settextstyle(7,0,15);
  setcolor(3);
  outtextxy(100,5,"GAME");
  outtextxy(100,200,"OVER") ;
  settextstyle(7,0,5);
  setcolor(BLUE);
  outtextxy(60,320,"Your Score Is=");
  gotoxy(52,23);
  cout<<scr;
  file.open("result.dat",ios::in|ios::out|ios::app|ios::binary);
  obj.score11=scr;
  file.write((char*)&obj,sizeof(obj));
  file.close();
  getch();
  exit(0);
}

void foodpla(int fx,int fy)       //to place the FOOD
{
  clearviewport();
  setviewport(10,10,400,400,0);
  setcolor(YELLOW);
  circle(fx,fy,2);
}

void design()
{
  setcolor(WHITE);
  rectangle(1,1,400,400);
  setcolor(BLUE);
  for(int i=0;i<5;i++)
  {
    rectangle(450+i,5+i,600+i,450+i);
  }
  settextstyle(4,0,6);
  setcolor(MAGENTA);
  outtextxy(20,410,"##EAT THE O##");
  for(i=0;i<4;i++)
  {
    setcolor(MAGENTA);
    circle(525+i,33+i,15);
    circle(500+i,70+i,15);
    circle(540+i,72+i,15);
    circle(520+i,105+i,15);
  }
  settextstyle(8,0,1);
  setcolor(RED);
  outtextxy(518,21,"W");
  outtextxy(498,56,"A");
  outtextxy(538,56,"D");
  outtextxy(518,91,"S");
  setcolor(6);
  settextstyle(10,0,1);
  outtextxy(460,159,"SCORE=");
  gotoxy(73,12);
  cout<<scr;
  settextstyle(8,0,1);
  setcolor(7);
  outtextxy(460,220,"PRESS ANY");
  outtextxy(469,240,"OTHER KEY");
  outtextxy(460,260,"TO PAUSE");
setcolor(8);
  outtextxy(460, 290,"EXIT:ecs");
}
void main()
{
  int gd=DETECT,gm;
  initgraph(&gd,&gm,"C:\\turboc3\\bgi");
  fropage();
  page2();                        //frontpage
  setbkcolor(BLACK);
  design();                         //instructions of the game
  setfillstyle(9,BLUE);
  fillellipse(l,b,10,6);
  setcolor(6);
  for(int i=0;i<10;i++)
  {
    rectangle(0+i,0+1,400+i,400+i);
  }
  setviewport(10,10,400,400,0);
  randomize();
  int fx=(random(150)+20);
  int fy=(random(150)+20);
  setcolor(YELLOW);
  circle(fx,fy,2);
  char  c;
  while(kbhit)
  {
    c=getch();
    if(c=='w')
    {
      x=0;
      y=1;
      while(!kbhit())
      {
	delay(dely);
	y++;
	b=b-y;
	setcolor(WHITE);
	foodpla(fx,fy);
setfillstyle(9,BLUE);
	fillellipse(l,b,6,10);
	x=0;
	y=0;
	if(((b-10)==fy)&&((l-6)<=fx)&&(fx<=(l+6)))
	{
	fx=(random(150)+20);
	fy=(random(200)+20);
	scr=scr+5;
	gotoxy(73,12);
	cout<<scr;
	delydec();
	}
	if (b<10)
	{
	ifover(scr);
	}
      }
    }
     else if (c=='d')
     {
       x=1;y=0;
       while(!kbhit())
       {
       delay(dely);
       x++;
       l=l+x;
       setcolor(WHITE);
       foodpla(fx,fy);
       setfillstyle(9,BLUE);
       fillellipse(l,b,10,6);
       x=0;y=0;
       if(((l+10)==fx)&&((b-6)<=fy)&&(fy<=(b+6)))
       {
	 fx=(random(150)+20);
	 fy=(random(150)+20);
	 scr=scr+5;
	 gotoxy(73,12);
 cout<<scr;
	 delydec();
       }
      if (l>380)
      {
	ifover(scr);
      }
    }
  }
  if (c=='a')
  {
    x=-1;y=0;
    while(!kbhit())
    {
      delay(dely);
      x--;
      l=l+x;
      setcolor(WHITE);
      foodpla(fx,fy);
      setfillstyle(9,BLUE);
      fillellipse(l,b,10,6);
      x=0;y=0;
      if(((l-10)==fx)&&((b-6)<=fy)&&(fy<=(b+6)))
      {
	fx=(random(200)+20);
	fy=(random(200)+20);
	scr=scr+5;
	gotoxy(73,12);
	cout<<scr;
	delydec();
      }
      if (l<10)
      {
	ifover(scr);
      }
    }
  }
  if (c=='s')
  {
    x=0;y=1;
    while(!kbhit())
    {
      delay(dely);
      y++;
      b=b+y;
      setcolor(WHITE);
      foodpla(fx,fy);
      setfillstyle(9,BLUE);
      fillellipse(l,b,6,10);
      x=0;y=0;
      if(((b+10)==fy)&&((l-6)<=fx)&&(fx<=(l+6)))
      {
	 fx=(random(150)+20);
	 fy=(random(150)+20);
	 scr=scr+5;
	 gotoxy(73,12);
	 cout<<scr;
	 delydec();
       }
       if (b>380)
       {
	 ifover(scr);
       }
     }
   }
  if(c==27)
    exit(0);
  }
}



