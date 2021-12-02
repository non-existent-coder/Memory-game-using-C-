
/*

GAME ... (project)
FIND THE RIGHT HOUSE
  by Nandhika S
*/

#include<stdlib.h>
#include<conio.h>
#include<stdio.h>
#include<graphics.h>
#include<dos.h>
#include<fstream.h>
#include<string.h>





       int v=0;
       char player[20];


  struct highscore
 {
  int gameno;
  char name[15],level[15];
  int score;
 }Struct;



// game coding

 void game(int n)      //n denotes the level
{
  fstream f;
  f.open("highscore.dat",ios::binary|ios::app);

  int w,y,d,i,a[10],p[10],r;
  int sco;
  char *buf,c;
 void inst();
 inst();

 startover:
   w=0;
   sco=0;
  randomize();
  for(i=0;i<n;i++)
  a[i]=1+rand()%5;

  for(i=0;i<n;i++)     // random colors display
     {
       setbkcolor(a[i]);
       sprintf(buf,"%d",i+1); //displays th color's order
       setcolor(8);
       settextstyle(1,0,100);
       outtextxy(200,200,buf);
	if(n==5)
       delay(1500);
	else if(n==7)
       delay(1000);
	else if(n==10)
       delay(800);
       cleardevice();
     }

  setbkcolor(0);


    for(i=0;i<n;i++)
      {
	randomize();
	p[i]=1+rand()%2;

	// correct house
		switch(p[i])
		 {
		   case 1 :     setcolor(a[i]);
				setfillstyle(SOLID_FILL,a[i]);
				rectangle(100,200,200,250);
				floodfill(150,240,a[i]);
				int t1[]={75,200,150,150,225,200,75,200};
				fillpoly(4,t1);
				d=2;
				break;

		   case 2 :	setcolor(a[i]);
				setfillstyle(SOLID_FILL,a[i]);
				rectangle(400,200,500,250);
				floodfill(450,240,a[i]);
				int t2[]={375,200,450,150,525,200,375,200};
				fillpoly(4,t2);
				d=1;
				break;
		 }

	//dummy house
	dummy:
	randomize();
	r=1+rand()%13;

	if(r==a[i])
	goto dummy;

		 switch(d)
		   {
		     case 1 :   setcolor(r);
				setfillstyle(SOLID_FILL,r);
				rectangle(100,200,200,250);
				floodfill(150,240,r);
				int t1[]={75,200,150,150,225,200,75,200};
				fillpoly(4,t1);
				break;

		     case 2 :	setcolor(r);
				setfillstyle(SOLID_FILL,r);
				rectangle(400,200,500,250);
				floodfill(450,240,r);
				int t2[]={375,200,450,150,525,200,375,200};
				fillpoly(4,t2);
				break;
		    }


	setcolor(15);
	settextstyle(3,0,4);
	outtextxy(50,300,"1st house     or     2nd house");
       //inputing answer
	again:
	cin>>y;

	  if(y==p[i])
	   {
	     cleardevice();
	     settextstyle(7,0,4);
	     outtextxy(250,200,"CORRECT");
	     w++;
	   sco+=10;
	   }
	  else if ((y!=1)&&(y!=2))
	   {
	     settextstyle(5,0,2);
	     outtextxy(200,400,"only press 1 or 2" );
	     goto again;
	   }
	  else
	   {
	     cleardevice();
	     settextstyle(1,0,4);
	     outtextxy(100,200,"BETTER LUCK NEXT TIME");
	     delay(500);
	     cleardevice();
	     break;
	   }

	delay(500);
	cleardevice();

      }
      //winner display
    if(w==n)
     {  for(i=0;i<3;i++)
	  { for(int j=1;j<15;j++)
	     { setcolor(j);
	       settextstyle(3,0,10);
	       outtextxy(50,150,"YOU WON");
	       delay(100);
	     }
	  }
     }
     cleardevice();

for(i=1;i<10;i++)
{
   setcolor(i);
   settextstyle(3,0,4);
   outtextxy(90,100,"DO YOU WANT TO TRY AGAIN ?");
   delay(100);
}

	 //score board
	   v++;
	  Struct.score=sco;
	  Struct.gameno=v;
	     if(n==5)
	  strcpy(Struct.level,"easy");
	     else if(n==7)
	  strcpy(Struct.level,"normal");
	     else if(n==10)
	  strcpy(Struct.level,"Hard");


  f.write((char*)&Struct,sizeof(Struct));



  setcolor(15);
  settextstyle(6,0,2);
  outtextxy(10,300,"  to continue press y if not then press any key");

  cin>>c;

  cleardevice();

   if(c=='y')
  goto startover;

    f.close();
}


						//MAIN

   void main()
 {
   clrscr();
   fstream f;
   int gdriver = DETECT,gmode,a[5],p[5],i,d,r,s;
   char title[ ]={"FIND THE HOUSE"};

  initgraph(&gdriver,&gmode,"c:\\turboc3\\bgi");

     //welcome
     settextstyle(3,0,1);
     outtextxy(220,150,"WELCOME to");
     settextstyle(2,0,5);
     outtextxy(200,250,"REMEMBER THE COLOURs");

  for (i=0 ;title[i+1]!='\0'  ;i++)
  {
   setcolor(i+1);
   settextstyle(3,0,6);
   outtextxy(100,170,title);
   delay(100);
  }

  setcolor(15);
  settextstyle(0,0,1);
  outtextxy(400,400,"Press any key to continue....");

  getch();
  cleardevice();

     f.open("highscore.dat",ios::binary|ios::out);
     f.close();


	 //player info
   cout<<"\n\n\n\nENTER YOUR NAME : ";
   gets(player);
   cleardevice();

   strcpy(Struct.name,player);

   //levels display
   gameplay:
    cleardevice();

      setcolor(10);
      settextstyle(3,0,8);
      outtextxy(180,10,"LEVELS");
      setcolor(12);
      settextstyle(0,0,2);
      outtextxy(10,150,"1.EASY");
      outtextxy(10,200,"2.NORMAL");
      outtextxy(10,250,"3.HARD");
      outtextxy(10,300,"4.EXIT");
      settextstyle(0,0,1);
      outtextxy(1,400,"enter your option");


	int c;

	  cin>>c;

 //opening the game accoring to users request

       switch(c)
    {
       case 1 : game(5);goto gameplay;
       case 2 : game(7);goto gameplay;
       case 3 : game(10);goto gameplay;
       default : break;
    }

 cleardevice();

     if(v!=0)
 {
   void highscores();
   highscores();
 }
   getch();
   cleardevice();
   closegraph();

}



   void highscores()                       //score board

  {
    int m=0;
    highscore h;
    fstream f;

     f.open("highscore.dat",ios::in|ios::binary);

 setcolor(12);
 settextstyle(5,0,5);
 outtextxy(160,10,"That's All Folks !");
 setcolor(5);
 settextstyle(9,0,1);
 outtextxy(190,80,"SCORE BOARD");
 setcolor(9);
 settextstyle(2,0,9);
 outtextxy(10,130,"Game No.");
 outtextxy(200,130,"Name");
 outtextxy(350,130,"Level");
 outtextxy(500,130,"Score");

    int i=0;
    char *buf,*dum;

     f.read((char*)&Struct,sizeof(Struct));
     if(f)
     {
      h=Struct;
     }

     f.seekg(0);


       setcolor(2);
       settextstyle(2,0,6);
   while(!f.eof())
  {

     f.read((char*)&Struct,sizeof(Struct));
     if(f)
     {
	 sprintf(buf,"%d",Struct.gameno);
	 outtextxy(60,180+(i+1)*20,buf);
	 outtextxy(200,180+(i+1)*20,Struct.name);
	 outtextxy(350,180+(i+1)*20,Struct.level);
	 sprintf(dum,"%d",Struct.score);
	 outtextxy(500,180+(i+1)*20,dum);

      m+=Struct.score;

      if(Struct.score>h.score)
      h=Struct;
      i++;
     }
  }
   f.close();

   char *dumm,*duum;
   outtextxy(10,420,"your highest score is");
   sprintf(dumm,"%d",h.score);
   outtextxy(300,420,dumm);

   sprintf(duum,"%d",m);
   outtextxy(300,440,duum);
   outtextxy(10,440,"your total score is ");

}







  void inst()
{
					//instructions
   cleardevice();
   for(int i=1;i<10;i++)
   {
    setcolor(i);
    settextstyle(3,0,6);
    outtextxy(50,50,"INSTRUCTIONS");
    setcolor(i+1);
    settextstyle(0,0,1);
    outtextxy(50,150,"Remember all the colors displayed in the order");
    setcolor(i+2);
    outtextxy(50,200,"Go to the houses according to the order of colors displayed");
    setcolor(i+3);
    outtextxy(50,250,"To go to the left house press 1 and enter");
    setcolor(i+4);
    outtextxy(50,300,"To go to the right house press 2 and enter");

   delay(250);
   }
    setcolor(15);
    outtextxy(400,400,"Press any key to continue....");
    getch();
    cleardevice();

}
