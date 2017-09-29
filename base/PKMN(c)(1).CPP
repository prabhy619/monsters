#include <conio.h>
#include <iomanip.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <graphics.h>
#include <dos.h>
#include <ctype.h>

struct poke
{
  char name[18];
  float hp[2],atk,def,spd,typ[2];
};

struct atk
{
  char name[20];
  float pow,acc,typ;
};

int h1=0,h2=0;

void dialogue(int no, char Pname[20])
{
  clrscr();
  int driver=DETECT,gmd;
  int r,len; char a[500];
  initgraph(&driver,&gmd,"C:\\TC\\BGI");
  int x=getmaxx()/2, y=getmaxy()/2;
  cleardevice();
  setbkcolor(0);

  if(no==4)
  {
    setbkcolor(15);
    sprintf(a,"So %s, you've come to face the elite 4!",Pname);
    settextstyle(TRIPLEX_FONT,HORIZ_DIR,2);
    int tht=textheight(a);
    outtextxy(0,y-tht,a);
    closegraph();
    clrscr();

    strcpy(a,"So you've come to face the elite 4! You are brave, I give you that, but also foolish. I am the first elite 4 member, Adarsh. Although I deserved to be the champion, but they denied me from teaching all my pokemon darkvoid...haha..just kidding...nobody can be stupid enough to do that. But still to move forward, you have to go through me. Be ready to face the fury of psychic types!");
    cout<<"Adarsh : ";
    len=strlen(a);
    for(int i=0;i<len;i++)
    {
      delay(30);
      putchar(a[i]);

      if (i==382-98)
      { /*clrscr();

	 for (int j=0; j<360; j++)
	  { initgraph(&driver,&gmd,"C:\\TC\\BGI");
	    cleardevice();
	    setcolor(8);
	    setbkcolor(0);

	     for (int s=j; s<360+j; s+=45)
	      {
		 for (int i=(x+y)/3.14159265358979,t=s; i>0; i--,t+=1)
		  {
		      arc(x, y, t, t+1, i);
		  }
	      }delay(50);
	  }cleardevice();
	closegraph();
	getch();*/
	cout<<'\n'<<"Danish: Except you."<<'\n'<<"Adarsh: ";
	//clrscr();
      }
      if(a[i]==','||a[i]=='.'||a[i]=='!')
      {
	      if(r+1!=i)
	       getch();
	      r=i;
      }
    }
  }else if(no==3)
  {
    strcpy(a,"Ahoy! I am prabhy.....2nd elite 4 member. I might look helpless(more like a clutz), stupid, confused......uhn.......less experienced and.......what did i forgot?.....yeah!, and forgetful.But believe me when I say I am toughest of all. With the power of normal types (and god Pokemon Arceus), i am going to defeat you.");
    cout<<"Prabhy : ";
    len=strlen(a);
    for(int i=0;i<len;i++)
    {
      delay(30);
      putchar(a[i]);
      if(a[i]==','||a[i]=='.'||a[i]=='!')
      {
	if(r+1!=i)
	getch();
	r=i;
      }
    }
  }else if(no==2)
  {
    strcpy(a,"I am The Master of Dragons.....Akhouri! I can fool people with my mind tricks and poker face.....and my secret weapon is.................pseudo sarcasm! With all this combined with the Mystical Powers of The Dragons.....I become UNDEFEATABLE!");
    cout<<"Akhouri : ";
    len=strlen(a);

    for(int i=0;i<len;i++)
    {
      delay(30);
      putchar(a[i]);
      if(a[i]==','||a[i]=='.'||a[i]=='!')
      {
	if (i==167-16)
	{
	  clrscr();
	  for(int l=0; l<20; l++)
	  {
	    for(int k=0; k<8; k++)
	    {
	      for(int m=0; m<8;m++)
	      {
			sound(10*random(100));
			delay(30);
			textbackground(k);
			cprintf(" ");
			nosound();
	      }
	    }textbackground(0); cprintf("\n\r");
	  }getch();
	  clrscr();

	  cleardevice();
	  setbkcolor(15);
	  char msg[]="Psuedo Sarcasm";
	  setcolor(9);
	  settextstyle(TRIPLEX_FONT, HORIZ_DIR,2);
	  outtextxy((getmaxx()/2)-(textwidth(msg)/2),(getmaxy()/2)-(textheight(msg)/2), msg);
	  getch();
	  closegraph();
	  clrscr();
	}
	if(r+1!=i)
	getch();
	r=i;
      }
    }
  }else if(no==1)
  {
    strcpy(a,"Welcome to the DARK side of the force!.....I am Danish....The master of Darkness, The Darth.......and also file handling(Ph.D).....I was born on friday the 13th and I am mostly associated with number 13 or 666 (other disasters included) or...... 69(if you are a hot female)....you have come far....but your journey ends here!");
    cout<<"Danish : ";
    len=strlen(a);
    for(int i=0;i<len;i++)
    {
      delay(30);
      putchar(a[i]);
      if(a[i]==','||a[i]=='.'||a[i]=='!')
      {
	if(r+1!=i)
	getch();
	r=i;
      }
    }
  }else if (no==0)
  {
    setcolor(15);
    setfillstyle(INTERLEAVE_FILL, getmaxcolor()-1);
    bar3d(0, 3*y/2, x*2-10, y*2, 7, 1);
    //bar3d(left,top,right,bottom,depth,topflag);vertices of the bar
    sprintf(a,"Champion Anant: Hmmm....strong with you the force is.");
    int tht=textheight(a);
    settextstyle(SMALL_FONT,HORIZ_DIR,7);
    outtextxy(7,3*y/2,a);
    getch();
    sprintf(a,"Done exceptionally well you have ..........");
    settextstyle(SMALL_FONT,HORIZ_DIR,7);
    outtextxy(7,3*y/2+(2*tht),a);
    tht=textheight(a);
    getch();
    sprintf(a,"And who am I you ask?.........");
    settextstyle(SMALL_FONT,HORIZ_DIR,7);
    outtextxy(7,3*y/2+(2*tht),a);
    tht=textheight(a);
    getch();
    sprintf(a,"the master of the Jedis and the champion I am.......");
    settextstyle(SMALL_FONT,HORIZ_DIR,7);
    outtextxy(7,3*y/2+(3*tht),a);
    tht=textheight(a);
    getch();
    sprintf(a,"and I am very modest (sarcasm,that is not)");
    settextstyle(SMALL_FONT,HORIZ_DIR,7);
    outtextxy(7,3*y/2+(4*tht),a);
    tht=textheight(a);
    getch();
    cleardevice();
    setfillstyle(INTERLEAVE_FILL, getmaxcolor()-1);
    bar3d(0, 3*y/2, x*2-10, y*2, 7, 1);
    //bar3d(left,top,right,bottom,depth,topflag);
    sprintf(a,"and I am very modest (sarcasm,that is not)");
    settextstyle(SMALL_FONT,HORIZ_DIR,7);
    outtextxy(7,3*y/2,a);
    tht=textheight(a);
    getch();
    sprintf(a,"you can be a good Paduwan/apprentice......");
    settextstyle(SMALL_FONT,HORIZ_DIR,7);
    outtextxy(7,3*y/2+tht,a);
    tht=textheight(a);
    getch();
    //"Hmmm....strong with you the force is. Done exceptionally well you have ...And who am I you ask?...... the master of the Jedis and the champion I am.......and I am very modest (sarcasm,that is not) ...you can be a good Paduwan/apprentice...But always two there are, an apprentice and a MASTER....and an apprentice can never get better than the master!");
    sprintf(a,"But always two there are, an apprentice and");
    settextstyle(SMALL_FONT,HORIZ_DIR,7);
    outtextxy(7,3*y/2+(2*tht),a);
    tht=textheight(a);
    getch();
    sprintf(a,"a MASTER....");
    settextstyle(SMALL_FONT,HORIZ_DIR,7);
    outtextxy(7,3*y/2+(3*tht),a);
    tht=textheight(a);
    getch();
    cleardevice();
    setfillstyle(INTERLEAVE_FILL, getmaxcolor()-1);
    bar3d(0, 3*y/2, x*2-10, y*2, 7, 1);
    //bar3d(left,top,right,bottom,depth,topflag);
    sprintf(a,"and an apprentice can never get");
    settextstyle(SMALL_FONT,HORIZ_DIR,7);
    outtextxy(7,3*y/2,a);
    tht=textheight(a);
    getch();
    sprintf(a,"better than the master!");
    settextstyle(SMALL_FONT,HORIZ_DIR,7);
    outtextxy(7,3*y/2+tht,a);
    getch();
    cleardevice();
    closegraph();
  }else if(no==-1)
  {
    strcpy(a,"Many years lived I have, but never encountered someone as strong and brave as you......the force connects you and your pokemon...making your team strong...destined for greatness you are....your journey has just begun...as is the tradition....you will now be registered in hall of fame ...and remembered as a great trainer for years to come................................................................................What doesn't kill you makes you stronger & what kills you makes you feel alive");
    cout<<"Anant : ";
    len=strlen(a);
    for(int i=0;i<len;i++)
    {
      delay(30);
      putchar(a[i]);
      if(a[i]==','||a[i]=='.'||a[i]=='!')
      {
	if(r+1!=i)
	getch();
	r=i;
      }
    }
  }else
  {
    settextstyle(TRIPLEX_FONT, HORIZ_DIR, 4);
    outtextxy(x, y, "FcuK YOU");
    getch();
    cleardevice();
    closegraph();
  }//if-else Ladder end
}//Function end

void pkball(int mode, char Pname[20], char Ename[20])
{
  clrscr();
  int driver=DETECT,gmd;
  int twidth;
  initgraph(&driver,&gmd,"C:\\TC\\BGI");
  int x=getmaxx()/2, y=getmaxy()/2;

  cleardevice();
  setbkcolor(0);
  for (int k=0;k<80;k++)
  {
    setcolor(4);
    arc(x,y-k,6,174,100);
    arc(x,y-k,20,160,30)  ;
    line(x-100,y-10-k,x-28,y-10-k);
    line(x+28,y-10-k,x+100,y-10-k);
    setcolor(15);
    line(x-100,y+10+k,x-28,y+10+k);
    line(x+28,y+10+k,x+100,y+10+k);
    circle(x,y-k,20);
    arc(x,y+k,186,354,100);
    arc(x,y+k,200,340,30);
    if(k==0||k>74)
    {
      setfillstyle(SOLID_FILL,RED);
      floodfill(x,y-50-k,4);
      setfillstyle(SOLID_FILL,WHITE);
      floodfill(x,y+50+k,15);
      floodfill(x,y-k,15);
    }
    if(k==0)
    getch();

    k=k+4;
    delay(25);

    if(k<75)
    cleardevice();
  }

  if(mode==0)
  {
    settextstyle(SMALL_FONT,HORIZ_DIR,12);
    twidth=textwidth(Pname);
    setcolor(2);
    outtextxy(x-40-twidth ,y,Pname);
    setcolor(4);
    outtextxy(x+40,y,Ename);
    setcolor(14);
    twidth=textwidth("Vs")/2;
    outtextxy(x-twidth ,y,"Vs");
    getch();
  }else
  {
    delay(8);setcolor(14);
    settextstyle(SMALL_FONT,HORIZ_DIR,12);
    outtextxy(x-80,y-20,"Pokemon");
    getch();
  }
  closegraph();
}

void ldscr()
{
  clrscr();
  int driver=DETECT,gmd;
  int twidth;
  initgraph(&driver,&gmd,"C:\\TC\\BGI");
  int x=getmaxx()/2, y=getmaxy()/2;

  for(int i=0;i<10;i++)
  {
    cleardevice();
    int shift,rad;
    setcolor(9);
    settextstyle(SMALL_FONT,HORIZ_DIR,8);
    outtextxy(x,y,"LOADING");
    delay(76);
    shift=70;
    rad=20;
    for(int j=0;j<4;j++)
    {
      outtextxy(x+30+shift,y,".");
      circle(x,y,rad);
      delay(80);
      rad+=50 ;
      shift+=10;
    }
    clrscr();
  }
  closegraph();
}

/*sequences for Elite four
ie; starting with #4 adarsh as mode=4, anant mode=0
& mode=-1 means hall of fame, anything else is simply start screen*/
void graphics(int mode, char Pname[20])
{
  clrscr();
  char msg[60];
  int driver=DETECT,gmd;
  int twidth;
  initgraph(&driver,&gmd,"C:\\TC\\BGI");
  int x=getmaxx()/2, y=getmaxy()/2;

  if(mode==4)
  {
    cleardevice();
    setcolor(2);
    settextstyle(4,HORIZ_DIR,6);
    sprintf(msg, "Elite 4 member #%i",mode);
    twidth=textwidth(msg)/2;
    outtextxy(x-twidth ,y+90,msg);

    setcolor(13);
    arc(x,y-25,193,347,100);
    arc(x,y+25,13,167,100);
    arc(x,y-25,190,350,80);
    arc(x,y+25,10,170,80);
    arc(x,y-40,180,360,50);
    arc(x,y-40,156,384,30);
    putpixel(x,y-60,15);
    setfillstyle(SOLID_FILL,LIGHTMAGENTA);
    floodfill(x,y-60,13);
    floodfill(x,y,13);
    getch();
    dialogue(mode,Pname);
    pkball(0,Pname,"Adarsh");
  }
  else if(mode==3)
  {
    cleardevice();
    setcolor(2);
    settextstyle(4,HORIZ_DIR,6);
    sprintf(msg, "Elite 4 member #%i",mode);
    twidth=textwidth(msg)/2;
    outtextxy(x-twidth ,y+90,msg);
    setcolor(15);

   /*circle(x,y, (x+y)/3.14159);
    for (int j=0; j<360; j++)
    {
      for (int s=j; s<360+j; s+=45)
      {
	      for (int i=(x+y)/3.1415926, t=s; i>0; i--,t+=1)
	      {
		arc(x, y, t, t+1, i);
	      }
      }
    }  */

    arc(x+40,y-40,180,270,80);
    arc(x-40,y-40,270,360,80);
    arc(x-40,y+40,0,90,80);
    arc(x+40,y+40,90,180,80);
    arc(x,y-52,220,320,80);
    arc(x,y+52,40,140,80);
    arc(x-52,y,310,50,80);
    arc(x+52,y,130,230,80);

    circle(x,y,65);
    setfillstyle(SOLID_FILL,WHITE);
    floodfill(x,y+50,15);
    floodfill(x,y-50,15);
    floodfill(x-50,y,15);
    floodfill(x+50,y,15);
    floodfill(x-20,y-20,15);
    floodfill(x-20,y+20,15);
    floodfill(x+20,y+20,15);
    floodfill(x+20,y-20,15);
    floodfill(x-30,y-30,15);
    floodfill(x-30,y+30,15);
    floodfill(x+30,y+30,15);
    floodfill(x+30,y-30,15);
    floodfill(x,y,15);
    getch();
    dialogue(mode,Pname);
    pkball(0,Pname,"Prabhjyot");
  }
  else if(mode==2)
  {
    cleardevice();
  /*  setcolor(15);
    circle(x,y, (x+y)/3.14159);
    for (int j=0; j<360; j++)
    {
      for (int s=j; s<360+j; s+=45)
      {
	      for (int i=(x+y)/3.14159,t=s; i>0; i--,t+=1)
	      {
		arc(x, y, t, t+1, i);
	      }
      }
    }  */
    getch();
    cleardevice();
    setcolor(2);
    settextstyle(4,HORIZ_DIR,6);
    sprintf(msg, "Elite 4 member #%i",mode);
    twidth=textwidth(msg)/2;
    outtextxy(x-twidth ,y+90,msg);

    setcolor(12);
    line(x-60,y-40,x-75,y-85);
    line(x+60,y-40,x+75,y-85);
    line(x-30,y-60,x-75,y-85);
    line(x+30,y-60,x+75,y-85);
    line(x-60,y-40,x-30,y-60);
    line(x+60,y-40,x+30,y-60);
    line(x-20,y-60,x+20,y-60);
    line(x-20,y-60,x,y-120);
    line(x+20,y-60,x,y-120);
    line(x-55,y-30,x-25,y-50);
    line(x+55,y-30,x+25,y-50);
    line(x-25,y-50,x+25,y-50);
    line(x-55,y-30,x,y+20);
    line(x+55,y-30,x,y+20);
    setfillstyle(SOLID_FILL,12);
    floodfill(x-55,y-60,12);
    floodfill(x+55,y-60,12);
    floodfill(x,y-70,12);
    floodfill(x,y,12);
    getch();
    dialogue(mode,Pname);
    pkball(0,Pname,"Akhouri");
  }
  else if(mode==1)
  {
    cleardevice();
    setcolor(DARKGRAY);
    circle(x,y+15,80);
    circle(x,y-5,30);
    circle(x,y-55,50);
    circle(x-60,y+70,30);
    circle(x+60,y+70,30);

    setfillstyle(SOLID_FILL,RED);
    floodfill(x,y+40,DARKGRAY);

    setfillstyle(SOLID_FILL,BLACK);
    floodfill(x,y+200,RED);
    floodfill(x,y-5,RED);

    setcolor(2);
    settextstyle(4,HORIZ_DIR,6);
    sprintf(msg, "Elite 4 member #%i",mode);
    twidth=textwidth(msg)/2;
    outtextxy(x-twidth ,y+90,msg);
    getch();
    dialogue(mode,Pname);
    pkball(0,Pname,"Danish");
  }
  else if(mode==0)
  {
    cleardevice();
    setcolor(4);
    settextstyle(4,HORIZ_DIR,6);
    sprintf(msg,"The Champion");
    twidth=textwidth(msg)/2;
    outtextxy(x-twidth ,y+90,msg);

    setcolor(7);
    line(x,y+20,x+15,y);
    line(x,y+20,x-15,y);
    line(x+70,y-45,x+75,y-120);
    line(x-70,y-45,x-75,y-120);
    line(x-75,y-120,x-20,y-100);
    line(x+75,y-120,x+20,y-100);
    line(x-20,y-100,x,y-75);
    line(x+20,y-100,x,y-75);
    line(x-15,y-45,x-48,y-60);
    line(x+15,y-45,x+48,y-60);
    line(x-15,y,x-15,y-45);
    line(x-48,y-60,x-48,y-45);
    line(x-45,y-15,x-70,y-45);
    line(x+48,y-60,x+48,y-45);
    line(x+15,y,x+15,y-45);
    line(x+45,y-15,x+70,y-45);
    line(x-25,y-33,x-25,y+40);
    line(x+25,y-33,x+25,y+40);
    line(x-48,y-45,x-25,y-33);
    line(x+48,y-45,x+25,y-33);
    line(x-25,y+40,x-45,y+25);
    line(x+25,y+40,x+45,y+25);
    line(x-45,y+25,x-45,y-15);
    line(x+45,y+25,x+45,y-15);
    setfillstyle(SOLID_FILL,7);
    floodfill(x,y,7);
    getch();
    dialogue(mode,Pname);
    pkball(0,Pname,"Anant");
  }else if(mode==-1)
  {
    ldscr();
    randomize();
    for(int i=0;i<15;i++)
    {
      dialogue(mode,Pname);
      setcolor(4);
      settextstyle(4,HORIZ_DIR,6);
      sprintf(msg,"HALL OF FAME");
      twidth=(textwidth(msg))/2  ;
      outtextxy(x-twidth ,y-100,msg);
      setcolor(3);
      settextstyle(3,HORIZ_DIR,4);
      sprintf(msg,"The new Champion %s",Pname);
      twidth=(textwidth(msg))/2;
      outtextxy(x-twidth ,y+90,msg);
      delay(75);
      for(int i=0;i<10;i++)
      {
	       putpixel(rand()%(2*x), rand()%(2*y), rand()%16);
	 putpixel(rand()%(2*x), rand()%(2*y), rand()%16);
	       putpixel(rand()%(2*x), rand()%(2*y), rand()%16);
	       putpixel(rand()%(2*x), rand()%(2*y), rand()%16);
	       delay(45);
	       cleardevice();
      }
    }
    cleardevice();
  }else
  {
    ldscr();
    pkball(1,Pname,"World");
  }
  closegraph();
}

int menu()
{
  graphics(13,"Welcome");
  //initializing graph
  int gdriver=DETECT, gmode, errorcode;
  initgraph(&gdriver, &gmode, "C:\\TC\\BGI");

  //initializing variables
  char msg[20], navi;
  int x, y, ht, nav=1;

  /* read result of initialization */
  errorcode = graphresult();
  if (errorcode != grOk)  /* an error occurred */
  {
    printf("Graphics errorcode: %i\n Graphics error: %s", errorcode, grapherrormsg(errorcode));
    printf("Press any key to halt: ");
    getch();
    exit(1); /* terminate with an error code */
  }
  x=getmaxx()/2;
  y=getmaxy()/2;

  do
  {
    if(nav>5)
      nav=1;
    else if(nav<1)
      nav=5;
    cleardevice();
    setcolor(LIGHTBLUE);
    settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 4);

    if (nav==1)
      setfillstyle(CLOSE_DOT_FILL, CYAN);
    else
      setfillstyle(WIDE_DOT_FILL, BLUE);
    sprintf(msg,"1. Single player");
    ht=textheight(msg);
    bar3d(x-(textwidth(msg)/2)-10, y-(3*ht)-60, x+(textwidth(msg)/2)+10, y-(2*ht)-50, 10, 1);
    outtextxy(x-(textwidth(msg)/2),y-(3*ht)-60, msg);

    if (nav==2)
      setfillstyle(CLOSE_DOT_FILL, CYAN);
    else
      setfillstyle(WIDE_DOT_FILL, BLUE);
    sprintf(msg,"2.Double player");
    bar3d(x-(textwidth(msg)/2)-10, y-(2*ht)-35, x+(textwidth(msg)/2)+10, y-ht-25, 10, 1);
    outtextxy(x-(textwidth(msg)/2), y-(2*ht)-35, msg);

    if (nav==3)
      setfillstyle(CLOSE_DOT_FILL, CYAN);
    else
      setfillstyle(WIDE_DOT_FILL, BLUE);
    sprintf(msg,"3.Championship");
    bar3d(x-(textwidth(msg)/2)-10, y-ht-10, x+(textwidth(msg)/2)+10, y, 10, 1);
    outtextxy(x-(textwidth(msg)/2), y-ht-10, msg);

    if (nav==4)
      setfillstyle(CLOSE_DOT_FILL, CYAN);
    else
      setfillstyle(WIDE_DOT_FILL, BLUE);
    sprintf(msg,"4.Re-login");
    bar3d(x-(textwidth(msg)/2)-10, y+15, x+(textwidth(msg)/2)+10, y+ht+25, 10, 1);
    outtextxy(x-(textwidth(msg)/2), y+15, msg);

    if (nav==5)
      setfillstyle(CLOSE_DOT_FILL, CYAN);
    else
      setfillstyle(WIDE_DOT_FILL, BLUE);
    sprintf(msg,"5.Exit");
    bar3d(x-(textwidth(msg)/2)-10, y+ht+40, x+(textwidth(msg)/2)+10, y+(2*ht)+50, 10, 1);
    outtextxy(x-(textwidth(msg)/2), y+ht+40, msg);

    navi=getch();

    if(isalpha(navi))
    {
      if(navi=='s')
	     nav++;
      else if(navi=='w')
	     nav--;
      else if(navi=='a')
	     nav=1;
      else if(navi=='d')
	     nav=5;
    }/*
    else if(isdigit(navi))
    {
      nav=int(navi);//nav=atoi(navi);
    }  */
  }while(navi!=13);

  /* clean up */
  cleardevice();
  closegraph();
  return nav;
}
//-------------------------------your normal code-------------------------------
float effectiveness(float a,float b)
{
       if(a==0)
       {
       if(b==5||b==8)
       return 0.5;
       else if(b==7)
       return 0.0  ;
       else
       return 1.0 ;
       }
       else if(a==1)
       {
       if(b==0||b==5||b==8||b==14||b==16)
       return 2.0  ;
       else if(b==7)
       return 0.0   ;
       else if(b==2||b==3||b==6||b==13||b==17)
       return 0.5   ;
       else
	   return 1.0 ;
       }
       else if(a==2)
       {
       if(b==1||b==6||b==11)
       return 2.0   ;
       else if(b==5||b==8||b==12)
       return 0.5   ;
       else
	   return 1.0  ;
       }
       else  if(a==3)
       {       if(b==11||b==17)
	   return 2.0;
	   else if (b==3||b==4||b==5||b==7)
       return 0.5  ;
       else if(b==8)
       return 0.0 ;
       else
	   return 1.0;
       }

       else if(a==4)
       {
       if(b==3||b==5||b==8||b==9||b==12)
       return 2.0;
	   else if(b==6||b==11)
       return 0.5;
	   else if(b==2)
       return 0.0;
       else
       return 1.0;
       }
       else if(a==5)
       {
       if(b==2||b==6||b==9||b==14)
       return 2.0;
	   else if(b==1||b==8||b==4||b==11)
       return 0.5;
	   else if(b==2)
       return 0.0;
       else
       return 1.0;
       }
       else if(a==6)
       {
       if(b==11||b==13||b==16)
       return 2.0;
       else if(b==1||b==2||b==3||b==7||b==8||b==9||b==17)
       return 0.5;
       else
       return 1.0;
       }

       else if(a==7)
       {
       if(b==7||b==13)
       return 2.0;
       else if(b==16)
       return 0.5;
       else if(b==0)
       return 0.0;
       else return 1.0;
       }
       else if(a==8)
       {
       if(b==14||b==17||b== 5)
       return 2.0;
       else if(b==8||b==9||b==10||       b==12)
       return 0.5;
    //else if(b==2)
     //eturn 0.0;
       else
       return 1.0;
       }
       else if(a==9)
       {
       if(b==8||b==11||b==6||b==14)
       return 2.0;
       else if(b==5||b==9||b==10||b==15)
       return 0.5;
       else
       return 1.0;
	}
       else if(a==10)
       {
       if(b==5 ||b== 4||b== 9)
       return 2.0;
       else if(b==10||b==11||b==15)
       return 0.5;
       else
       return 1.0;}
       if(a==11)
       {
       if(b==4 ||b== 5||b==10)
       return 2.0;
       else if(b==2||b==3||b==6||b==6||b==8||b==11||b==15||b==9)
       return 0.5;
       else
       return 1.0;}
       else  if(a==12)
       {
       if(b==2 ||b== 10)
       return 2.0;
	   else if(b==11||b==12||b==15)
       return 0.5;
       else if(b==4)
       return 0.0;
       else
       return 1.0;}
       else if(a==13)
     {
       if(b==1 ||b== 3||b==11)
       return 2.0;
	   else if(b==8||b==13)
	   return 0.5;
       else if(b==16)
       return 0.0;
       else
       return 1.0;}
       else if(a==14)
      {
      if(b==2 ||b== 5||b==11||b==15)
      return 2.0;
      else if(b==8||b==9  ||b==10||b==14)
      return 0.5;
      else
      return 1.0;
      }
	 //0normal,1fighting 2flying 3poison 4grounud 5rock 6bug 7ghost
       //8seee 9fir 10wat 11grass 12elec 13psy 14ice 15drag 16dark 17fair
      else if(a==15)
      {
       if(b==15)
       return 2.0;
	   else if(b==8)
       return 0.5;
       else if(b==17 )
       return 0.0;
       else
       return 1.0;}
       if(a==16)
       {
       if(b==7               ||b==13)
       return 2.0;
	   else if(b==1||b==16||b==17)
	   return 0.5;
       else
       return 1.0;}
       else  if(a==17)
       {
       if(b==1||b==16||b==15)
       return 2.0;
	   else if(b==3||b==8||b== 9)
	   return 0.5;
       else
       return 1.0;
       }
      else
      return 1.0;
       }

// a fontion that sort outs the stab moves from a given arrary of attacks
//it will return 10 if no such move exists, 10 is a default for failed search everywhere in the progranme
int stab(struct poke p,struct atk a[4],int b[],int c)
{
  for(int i=0;i<c;i++)
  {
    if(a[b[i]].typ==p.typ[0]||a[b[i]].typ==p.typ[1])
      return b[i];
  }
  return 10;
}

//it will search for move or a pokemon against the opponent's pokemon
int pkmn_move_search(struct poke pk[],int s2,struct poke p,struct atk move[4],int typ,int st,float eft,int gmtyp)//needs to improve
{
  int x,y,b[4],c[4],d[4],eff[3]={0,0,0};
  float a,cmp[3];

  if(st==0||st==2)  //st stands for search type......if st is 0...it means search for a pokemon...if st is 2...search fo a move
  {
    if(st==0)
      y=0;
    else
      y=2;
    if(gmtyp==2&&y==2)
      y=-(y*gmtyp);
    cmp[0]=4;cmp[1]=2;cmp[2]=1;
  }
  //this is a special search type...it searches fir a pokemon that can best withstand a perticular move of the opponent pokemon
  else if(st==1)
 {
  y=1;
  cmp[0]=0;cmp[1]=0.5;cmp[2]=1;
 }

  //the parameters baove are set accordingly to the search that has to be conducted
  //the search beginns from here...also if game type is 2...it will search from a party of 6 pokemons...and if the gametype is 1...it will search from a party of 3 pokemons....moves in each case is searched from a list of 4 moves with the current ai pokemon
 for(int i=0;i<(3*gmtyp)+(y/2);i++)//needs to improve
 {
   if(y==1)
     a=effectiveness(typ,pk[i].typ[0])*effectiveness(typ,pk[i].typ[1]);
     //searching a pokemon against the opponent pokemon(offensive)
   else if(y==0)
     a=effectiveness(pk[i].typ[0],typ)*effectiveness(pk[i].typ[1],typ);//searching a pokemon to defend the the perticular "type"  (defensive)
   else
     a=effectiveness(move[i].typ,p.typ[0])*effectiveness(move[i].typ,p.typ[1]);//searching for a move against the opponent pokemon

   if(a==cmp[0]&&(pk[i].hp[0]>0||y==2||y==-4))
   //selects the X4 times move or X4 times pokemon types...also mkaes sure the if it is in pokemon search mode...it only selects not fainted pokemons
   {
    b[eff[0]]=i;
    eff[0]++;
   }
   else if(a==cmp[1]&&(pk[i].hp[0]>0||y==2||y==-4))
   //selects X2 times
   {
     c[eff[1]]=i; //c[eff[1]]=i; eff[1]++;
     eff[1]++;
   }
   else if(a==cmp[2]&&(pk[i].hp[0]>0||y==2||y==-4))//selects X1 times
   {
     d[eff[2]]=i; //d[eff[2]]=i; eff[2]++;
     eff[2]++;
   }
   //if(y==2&&(move[i].typ==pk[i].typ[0]||move[i].typ==pk[
 }

  if(eff[0]==0 && eff[1]==0&& eff[2]==0)
  {
    if(eft!=1)
    //eft parameter is used a s a filter...if i want it to search only for a super effective move or supper effective type of pokemon against the opponent pokemon...i will set eft as 2...and if no such pokemon or move is found...it will return 10
      return 10;
    else if(y!=2&&y!=-4)//this checks the condition of search... if it is searching for pokemon... will not have 2 or -4 value
    {
      do
      {
	       x=(rand()%6);//after making sure its in pokemon search mode...it will randomly select a pokemon when no good pokemon is found
      }while(pk[x].hp[0]<=0);
    }
    else
     x=(rand()%4);
     //else it will randomly select 4 moves
  }
  else if(eff[0]==0&&eff[1]==0)
  {
    if(eft!=1)
      return 10;
    else if(stab(pk[s2],move,d,eff[2])!=10)
    //checks weather there is a stab move in the list ....if there is one stab move...it will be giben higher priority
      x=stab(pk[s2],move,d,eff[2]);
    else
    {
      eff[2]=(rand()%eff[2]);
      x=d[eff[2]];
    }
  }
  else if(eff[0]==0)
  {
    if(stab(pk[s2],move,c,eff[1])!=10)
       x=stab(pk[s2],move,c,eff[1]);
    else
    {
      eff[1]=(rand()%eff[1]);
      x=c[eff[1]];
    }
  }
  else
  {
    if(stab(pk[s2],move,b,eff[0])!=10)
       x=stab(pk[s2],move,b,eff[0]);
    else
    {
      eff[0]=(rand()%eff[0]);
      x=b[eff[0]];
    }
  }
  return x;
}

//this function is used to search 2 X ...one time with type 1 of the opponent pokemon..seconf]d time with type 2 of the opponent pokemon
int ch_pkmn2(struct poke pk[],int s2,struct poke p,struct atk move[4],int filt)
{
  //searching for pokemon with the filter on mode..
	if(pkmn_move_search(pk,s2,p,move,p.typ[0],0,2,2)!=10)
	   return pkmn_move_search(pk,s2,p,move,p.typ[0],0,2,2);
	else if(pkmn_move_search(pk,s2,p,move,p.typ[1],0,2,2)!=10&&p.typ[1]!=18)
	   return pkmn_move_search(pk,s2,p,move,p.typ[1],0,2,2);
	else if(filt!=1)
  //again to filter out....it wil return 10 if no good pokemon is found against the opponent pokemon
	   return 10;
	else
	   return pkmn_move_search(pk,s2,p,move,p.typ[0],0,1,2);//if no good pokemon is found....it will return the result of search in filter off mode
}

float damage(struct atk c,struct poke a,struct poke b)
{
  float x,y;

  randomize();
  int d=(rand()%100)+1; //chance of missing the hit(accuracy)

  if(d>=c.acc)
    x=0;
  else
    x=1;
  if(a.typ[0]==c.typ||a.typ[1]==c.typ) //stab
    x=x*13/10;

  randomize();
  y=(rand()%11)+90; //removing every effect..every attacks hit strength ranges from 90 to 100%
  y=y/100;

  float d1=21*a.atk*c.pow;
  float d2=25*b.def;d1=d1/d2;d1=d1+2;d1=d1*x*y;
  float dmg=d1*(effectiveness(c.typ,b.typ[0]))*(effectiveness(c.typ,b.typ[1]));
  //float dmg=((21*a.atk*c.pow/(25*b.def)+2)*x*y)*(effectiveness(c.typ,b.typ[0]))*(effectiveness(c.typ,b.typ[1]));
  return dmg;
}

//switching comments and random switching for a normal ai
void swt(char p1[20],int &s,struct poke p[],int i)
{
  if(i>3)
  {
 do{
  cprintf(p1);
  cout<<" choose your next pkmn"<<endl;
  cin>>s;
  s=s-1;
  if(p[s].hp[0]<=0)
  cprintf("%s will no longer will be able to battle",p[s].name);
  cout<<endl;
  }while(p[s].hp[0]<=0);
 cprintf("%s sends out %s",p1,p[s].name);
 delay(600);
 }
  else
  {
    randomize();
    do
    {   if(i<3)
	s=i;
	else
	s=(rand()%3)+0;
     }while(p[s].hp[0]<=0);
   cprintf("%s sends out %s",p1,p[s].name);
   delay(600);
     }

  }

//pokemon selection and pokemon list
void pkmn_list(int a,int b,struct poke p1[],struct poke p2[],int log,int l)
{
  if(l==1)
  {
    for(int i=0;i<a;i++)
    {
      cprintf("%i %s",i+1,p1[i].name);cout<<'\t';
      if(i%2!=0)
	cout<<endl;
      if(i==a-1)
	cout<<endl;
    }
    if(log!=0)
    {
      textcolor(14) ;
      cprintf("legendary unlocked : %i %s",100+log,p2[b-1+log].name);
      cout<<endl;
    }
  }
  else
  {
    for(int i=0;i<b;i++)
    {
      cprintf("%i %s",i+1,p2[i].name);cout<<'\t';
      if(i%2!=0)
	cout<<endl;
      if(i==b-1)
	cout<<endl;
    }
    if(log!=0)
    {
      textcolor(14) ;
      cprintf("legendary unlocked : %i %s",100+log,p2[b-1+log].name);
      cout<<endl;
    }
  }
}

//pokemon choosing and randome pokemon choosing for normal ai
void choosep(struct poke a[],struct poke b[],struct poke c[],int p_no,int d,int e,int lg)
{
  pkmn_list(18,19,b,c,lg,1);
  int x,y=1;
  cout<<"to go to next list,type 100"<<endl<<"choose "<<p_no<<" pokemons";
  if(d==0)
  {
    for(int i=0;i<p_no;i++)
    {
      cin>>x;
      if(x==100)
      {
	      clrscr();
	      y=y*(-1);
	      pkmn_list(18,19,b,c,lg,y);i--;
      }
      else if(x==500&&lg==1)
	break;
      else
      {
	x--;
	if(x>99)
	  a[i]=c[18+lg];
	else if(y==1)
	  a[i]=b[x];
	else if(y==-1)
	  a[i]=c[x];
      }
    }
    if(x==500)
    {
      a[0]=b[14];
      a[1]=b[0];
      a[2]=b[10];
      a[3]=b[5];
      a[4]=c[13];
      a[5]=c[18+lg];
    }
  }
  else
  {
    randomize();
    for(int i=0;i<p_no;i++)
    {
      int y=rand()%e;
      if(stricmp(b[y].name,a[0].name)==0||stricmp(b[y].name,a[1].name)==0||stricmp(b[y].name,a[2].name)==0||stricmp(b[y].name,a[3].name)==0||stricmp(b[y].name,a[4].name)==0||stricmp(b[y].name,a[5].name)==0)
	i--;
      else
	a[i]=b[y];
    }
  }
}

//move choosing and randome move choosing for normal ai
void choosem(struct atk a[][4],struct atk b[12],int c,int d,int e,int f)
{
  int x;
  if(d==0)
  {
    for(int i=0;i<c;i++)
    {
      cin>>x;
      x--;
      a[f][i]=b[x];
    }
  }
  else
  {
    randomize();
    for(int i=f;i<c;i++)
    {
      int z=i/4;
      int  y=rand()%e;
      if(stricmp(b[y].name,a[z][0].name)==0||stricmp(b[y].name,a[z][1].name)==0||stricmp(b[y].name,a[z][2].name)==0||stricmp(b[y].name,a[z][3].name)==0)
	i--;
      else
	a[z][i-4*z]=b[y];
    }
  }
}

//health bar graphics
int health_bar(struct poke c, struct poke d, struct atk lst[4])
{
   clrscr();
   int gdriver = DETECT, gmode, errorcode;
   initgraph(&gdriver, &gmode, "C:\\TC\\BGI");
   int x, color[2], ht, wd, nav=1; char navi;
   float hp[2];
   char msg[20];

   hp[0]=((c.hp[0]/c.hp[1])*200);
   hp[1]=((d.hp[0]/d.hp[1])*200);

   // read result of initialization
   errorcode = graphresult();
   if (errorcode != grOk)  // an error occurred
   {
      printf("Graphics error: %s\n", grapherrormsg(errorcode));
      printf("Press any key to halt:");
      getch();
      exit(1); // terminate with an error code
   }

   cleardevice();
   wd=textwidth("Fletchinder: 123.45");
   ht=textheight("Fletchinder: 123.56");

  do
  {
    if(nav>5){
      nav=1;}
    else if(nav<1){
      nav=5;}
    cleardevice();

    sprintf(msg,"%s: %.2f",c.name, hp[0]);
    x=200+textwidth(msg);
    if(x>360){
      x=320;}

   setfillstyle(CLOSE_DOT_FILL, RED);
   bar(5, 32, 5+200, 42);
   bar(x, 32, x+200, 42);

   if (hp[0]>110){
     color[0]=GREEN;}
   else if (hp[0]<40){
     color[0]=RED;}
   else{
     color[0]=YELLOW;}

   setfillstyle(SOLID_FILL, color[0]);
   bar(x, 32, x+hp[0], 42);

   if (hp[1]>110){
     color[1]=GREEN;}
   else if (hp[1]<40){
     color[1]=RED;}
   else{
     color[1]=YELLOW;}

   setfillstyle(SOLID_FILL, color[1]);
   bar(5, 32, 5+hp[1], 42);

   setcolor(GREEN);
   outtextxy(5,2*textheight(msg),msg);
   sprintf(msg,"%s: %.2f",d.name, hp[1]);
   setcolor(RED);
   outtextxy(x,2*textheight(msg),msg);

   setcolor(LIGHTBLUE);
   sprintf(msg,"What will %s do?",c.name);
   outtextxy((x/2)-wd-5, ((10)*ht), msg);

   for(int i=8; i<=20; i+=4)
    {
      if (nav==(i/4)-1){
       setcolor(LIGHTGRAY);}
      else{
       setcolor(LIGHTBLUE);}
      sprintf(msg,"%i. %s",(i/4)-1, lst[(i/4)-2].name);
      outtextxy((x/2)-wd-5, ((i+5)*ht), msg);
    }
      if (nav==5){
       setcolor(LIGHTGRAY);}
      else{
       setcolor(LIGHTBLUE);}
      sprintf(msg,"5. Switch");
      outtextxy((x/2)-wd-5, ((24+5)*ht), msg);

    navi=getch();
    tolower(navi);

    if(isalpha(navi))
    {
      if(navi=='s'){
	     nav++;}
      else if(navi=='w'){
	     nav--;}
      else if(navi=='a'){
	     nav=1;}
      else if(navi=='d'){
	     nav=5;}
    }
  }while(navi!=13);

   cleardevice();
   closegraph();
   return nav;
}

//diaplay of moves of a pokemon while battling
void moveset(int a,int b,struct poke p1[],struct poke p2[],struct atk m[][4],struct atk n[][4],int gametyp)
{
  clrscr();
  textcolor(2);
  cprintf("%-10s",p1[a].name);
  textcolor(15);
  cprintf(": %.1f",p1[a].hp[0]);
  cout<<'\t'<<'\t'<<'\t';
  textcolor(4);
  cprintf("%s",p2[b].name);
  cprintf(": %.1f",p2[b].hp[0]);
  cout<<endl;
  for(int y=0;y<5;y++)
  {
    if(y==4)
    {
      textcolor(14);
      cprintf("%i switch",y+1); cout<<'\t'<<'\t'<<'\t'<<'\t';
      if(gametyp==1)
	cprintf("%i switch",y+1);
      cout<<endl<<endl;
    }
    else
    {
      textcolor(15);
      cprintf("%i %s",y+1,m[a][y].name);
      if(gametyp==1)
      {
	cout<<'\t'<<'\t'<<'\t'<<'\t';
	cprintf("%i %s ",y+1,n[b][y].name);
      }
      cout<<endl;//display of final selected attacks
    }
  }
}

//the ai switching conditions
int swit_ai(struct poke p1[],struct poke p2[],struct atk a1[][4],struct atk a2[][4],int s1,int s2,int &m,int gametyp)
{
  float y,hp=p2[s2].hp[0]/p2[s2].hp[1];
  int n,z[3],k=0;
  for(int i=0;i<4;i++)
  {
    y=effectiveness(a1[s1][i].typ,p2[s2].typ[0])*effectiveness(a1[s1][i].typ,p2[s2].typ[1]);
    if(y==4&&(p2[s2].spd<p1[s2].spd||(p1[s1].hp[0]/p1[s1].hp[1])>0.6)&&((p2[s2].hp[0]/p2[s2].hp[1])>0.60))
    {
	    n=m;
	    if(pkmn_move_search(p2,s2,p1[s1],a2[s2],a1[s1][i].typ,1,0.5,gametyp)!=10)
	    {
	      m=pkmn_move_search(p2,s2,p1[s1],a2[s2],a1[s1][i].typ,1,0.5,gametyp);
	      return 0;
	    }
	    else if(ch_pkmn2(p2,s2,p1[s1],a2[s2],1)!=10)
	    {
	      m=ch_pkmn2(p2,s2,p1[s1],a2[s2],1);
	      return 0;
	    }
      else
      {
	      m=s2;
	      return 0;
      }
    }
  }
  int a =pkmn_move_search(p1,s1,p2[s2],a1[s1],18,2,2,2);

  if((pkmn_move_search(p2,s2,p1[s1],a2[s2],18,2,2,gametyp)==10)&&(effectiveness(p1[s1].typ[0],p2[s2].typ[0])>1)&&(p2[s2].hp[0]>0.60)&&(p2[s2].spd<p1[s2].spd||(p1[s1].hp[0]/p1[s1].hp[1])>0.3))
  {
    if(ch_pkmn2(p2,s2,p1[s1],a2[s2],2)!=10)
    {
      m=ch_pkmn2(p2,s2,p1[s1],a2[s2],2);
      return 0;
    }
    else if(pkmn_move_search(p2,s2,p1[s1],a2[s2],a1[s1][a].typ,1,0.5,gametyp)!=10&&a!=10)
    {
      m=pkmn_move_search(p2,s2,p1[s1],a2[s2],a1[s1][a].typ,1,0.5,gametyp);
      return 0;
    }
    else
      m=s2;
    return 0;
  }
  if((pkmn_move_search(p1,s1,p2[s2],a1[s1],18,2,2,gametyp)!=10)&&(pkmn_move_search(p2,s2,p1[s1],a2[s2],18,2,2,gametyp)==10)&&(p2[s2].spd<p1[s1].spd)&&(p2[s2].hp[0]>0.6)&&(p2[s2].spd<p1[s2].spd||(p1[s1].hp[0]/p1[s1].hp[1])>0.3))
  {
    if(ch_pkmn2(p2,s2,p1[s1],a2[s2],2)!=10)
    {
      m=ch_pkmn2(p2,s2,p1[s1],a2[s2],2);
      return 0;
    }
    else if(pkmn_move_search(p2,s2,p1[s1],a2[s2],a1[s1][a].typ,1,0.5,gametyp)!=10&&a!=10)
    {
      m=pkmn_move_search(p2,s2,p1[s1],a2[s2],a1[s1][a].typ,1,0.5,gametyp);
      return 0;
    }
    else
      m=s2;
    return 0;
  }
  m=s2;
  return 0;
}

//checks spd
int spdchk(struct poke p1,struct poke p2)
{
  int z;
  if(p1.spd<p2.spd)
    z=2;
  else if(p1.spd>p2.spd)
    z=1;
  else
  {
    randomize();   //random first move when speed is equal
    z=(rand()%3)+1;
  }
  return z;
}

//execution of selected attacks during gameplay
void atkf(struct poke c, struct poke d, struct atk m)
{
   clrscr();
   int gdriver = DETECT, gmode, errorcode;
   initgraph(&gdriver, &gmode, "C:\\TC\\BGI");
   int x, color[2], ht, wd; float dmg,q;
   float hp[2];
   char msg[20];

   hp[0]=((c.hp[0]/c.hp[1])*200);
   hp[1]=((d.hp[0]/d.hp[1])*200);

   // read result of initialization
   errorcode = graphresult();
   if (errorcode != grOk)  // an error occurred
   {
      printf("Graphics error: %s\n", grapherrormsg(errorcode));
      printf("Press any key to halt:");
      getch();
      exit(1); // terminate with an error code
   }

   cleardevice();
   wd=textwidth("Fletchinder: 123.45");
   ht=textheight("Fletchinder: 123.56");

   cleardevice();

   sprintf(msg,"%s: %.2f",c.name, hp[0]);
   x=200+textwidth(msg);
   if(x>360){
      x=320;}

   setfillstyle(CLOSE_DOT_FILL, RED);
   bar(5, 32, 5+200, 42);
   bar(x, 32, x+200, 42);

   if (hp[0]>110){
     color[0]=GREEN;}
   else if (hp[0]<40){
     color[0]=RED;}
   else{
     color[0]=YELLOW;}

   setfillstyle(SOLID_FILL, color[0]);
   bar(x, 32, x+hp[0], 42);

   if (hp[1]>110){
     color[1]=GREEN;}
   else if (hp[1]<40){
     color[1]=RED;}
   else{
     color[1]=YELLOW;}

   setfillstyle(SOLID_FILL, color[1]);
   bar(5, 32, 5+hp[1], 42);

   setcolor(GREEN);
   outtextxy(5,2*textheight(msg),msg);
   sprintf(msg,"%s: %.2f",d.name, hp[1]);
   setcolor(RED);
   outtextxy(x,2*textheight(msg),msg);
   //health_bars end

   setcolor(LIGHTGREEN);
   setfillstyle(SOLID_FILL, CYAN);
   bar3d(10, (25*ht)-5, getmaxx()-25, (33*ht),10,1);//void far bar3d(int left, int top, int right, int bottom, int depth, int topflag);
   setcolor(LIGHTBLUE);
   sprintf(msg,"%s attacks",c.name);
   outtextxy((x/2)-wd, (25*ht), msg);
   sprintf(msg,"%s uses %s",c.name, m.name);
   outtextxy((x/2)-wd, ((28)*ht), msg);
   dmg=damage(m,c,d);
   d.hp[1]=d.hp[1]-dmg;
   q=effectiveness(m.typ,d.typ[0])*effectiveness(m.typ,d.typ[1]);
   getch();
   setcolor(LIGHTGREEN);
   setfillstyle(SOLID_FILL, CYAN);
   bar3d(10, (25*ht)-5, getmaxx()-25, (33*ht),10,1);
   if(q==0)
   {
     setcolor(WHITE);
     sprintf(msg,"%s doesnt affects %s",c.name, d.name);
     outtextxy((x/2)-wd, (25*ht), msg);
   }
   else if(dmg==0)
   {
     setcolor(RED);
     sprintf(msg,"attack misses");
     outtextxy((x/2)-wd, (25*ht), msg);
   }
   else if(q>=2)
   {
     setcolor(GREEN);
     sprintf(msg,"%s is super effective against %s", m.name, d.name);
     outtextxy((x/2)-wd, (25*ht), msg);
   }
   else if(q<=0.5)
   {
     setcolor(DARKGRAY);
     sprintf(msg,"%s is not very effective against %s", m.name, d.name);
     outtextxy((x/2)-wd, (25*ht), msg);
   }
   setcolor(LIGHTBLUE);
   sprintf(msg, "Damage Done = %.2f", dmg);
   outtextxy((x/2)-wd, (28*ht), msg);
/*
   for (int j = dmg; j > 0; j--) {
     cleardevice();
     sprintf(msg,"%s: %.2f",c.name, hp[0]);
     x=200+textwidth(msg);
     if(x>360){
        x=320;}

     hp[0]=((c.hp[0]/c.hp[1])*200);
     hp[1]=(((d.hp[0]+j)/d.hp[1])*200);

     setfillstyle(CLOSE_DOT_FILL, RED);
     bar(5, 32, 5+200, 42);
     bar(x, 32, x+200, 42);

     if (hp[0]>110){
       color[0]=GREEN;}
     else if (hp[0]<40){
       color[0]=RED;}
     else{
       color[0]=YELLOW;}

     setfillstyle(SOLID_FILL, color[0]);
     bar(x, 32, x+hp[0], 42);

     if (hp[1]>110){
       color[1]=GREEN;}
     else if (hp[1]<40){
       color[1]=RED;}
     else{
       color[1]=YELLOW;}

     setfillstyle(SOLID_FILL, color[1]);
     bar(5, 32, 5+hp[1], 42);

     setcolor(GREEN);
     outtextxy(5,2*textheight(msg),msg);
     sprintf(msg,"%s: %.2f",d.name, hp[1]);
     setcolor(RED);
     outtextxy(x,2*textheight(msg),msg);
   }*/

   getch();
   cleardevice();
   closegraph();
}

//checks for alive pokemons
int pkmn_check(struct poke p[],int a)
{
  int b=0;
  for(int i=0;i<a;i++)
  {
    if(p[i].hp[0]>0)
    b++;
  }
  return b;
}

//heals pokemon
void pkmn_refresh(struct poke p[6],int a)
{
  for(int i=0;i<a;i++)
  {
    p[i].hp[0]=p[i].hp[1];
  }
  cout<<"pokemon healed";
  getch();
}

//displays party pokemon when switching
void party_pkmn(struct poke p[],int c)
{
  cout<<endl;
  for(int i=0;i<c;i++)
  {
    if(p[i].hp[0]>0)
      textcolor(2);
    else
      textcolor(4);
    cprintf("%i %s\n\r",i+1,p[i].name);
  }
  cout<<endl;
}

int login(char p1[20])
{
  again:
  ;
  system("cls");
  int gdriver=DETECT, gmode, errorcode;
  initgraph(&gdriver, &gmode, "C:\\TC\\BGI");
  char msg[20], psw[20];
  int x, y;
  /* read result of initialization */
  errorcode = graphresult();
  if (errorcode != grOk)  /* an error occurred */
  {
    printf("Graphics errorcode: %i\n Graphics error: %s", errorcode, grapherrormsg(errorcode));
    printf("Press any key to halt: ");
    getch();
    exit(1); /* terminate with an error code */
  }
  x=getmaxx()/2;
  y=getmaxy()/2;

  cleardevice();
  setcolor(CYAN);
  settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 4);
  sprintf(msg,"Username:");
  setfillstyle(INTERLEAVE_FILL, LIGHTBLUE);
  bar3d((x/2)-(textwidth(msg)/2)-60, y-textheight(msg)-5, (x/2)+(2*textwidth(msg))-60, y+(2*textheight(msg))+10, 10, 1);
  outtextxy((x/2)-(textwidth(msg)/2)-50,y-textheight(msg),msg);
  sprintf(msg,"Password:");
  outtextxy((x/2)-(textwidth(msg)/2)-50,y+textheight(msg),msg);
  setfillstyle(SOLID_FILL, BLACK);
  bar((x/2)+(textwidth(msg)/2)-40, y-textheight(msg)+10, (x/2)+(2*textwidth(msg))-60, y+textheight(msg)-15);
  bar((x/2)+(textwidth(msg)/2)-40, y+textheight(msg), (x/2)+(2*textwidth(msg))-60, y+(2*textheight(msg))+5);

  gotoxy(30,15); //for username
  gets(p1);
  gotoxy(27, 19); //for password
  int i=0;
  do
  {
    psw[i]=getch();
    if((psw[i]=='\b')&&(i>0))
    {
      printf("\b \b");
      i--;
    }
    else if(psw[i]!=13)
    {
      printf("*");
      i++;
    }
  }while(psw[i]!=13);
  psw[i]='\0';
  cleardevice();
  closegraph();

  if(stricmp(p1,"Anant Rai")!=0&&stricmp(p1,"Prabhy")!=0&&stricmp(p1,"Akhauri")!=0&&stricmp(p1,"Adarsh")!=0&&stricmp(p1,"Danish")!=0)
  {
    cout<<endl;
    textcolor(3);
    cprintf("welcome %s ,trainer",p1);
    getch();
    clrscr();
    return 0;
  }

  if(stricmp(p1,"Anant rai")==0&&strcmp(psw,"Qwerty")==0)
  {
    cout<<endl;
    cprintf("Welcome Anant rai, The Champion.") ;
    getch();
    clrscr();
    return 1;
  }
  else if(stricmp(p1,"Danish")==0&&strcmp(psw,"bselectdown")==0)
  {
    cout<<endl;
    cprintf("Welcome Danish, Elite 4 member #1") ;
    getch();
    clrscr();
    return 2;
  }
  else if(stricmp(p1,"Akhauri")==0&&strcmp(psw,"wasdijkl")==0)
  {
    cout<<endl;
    cprintf("Welcome Akhauri, Elite 4 member #2") ;
    getch();
    clrscr();
    return 3;
  }
  else if(stricmp(p1,"Prabhy")==0&&strcmp(psw,"dontcopy")==0)
  {
    cout<<endl;
    cprintf("Welcome Prabhy, Elite 4 member #3 (yeah really...no sarcasm, seriously just believe it for arceus's sake !)") ;
    getch();
    clrscr();
    return 4;
  }
  else if(stricmp(p1,"Adarsh")==0&&strcmp(psw,"patanahi")==0)
  {
    cout<<endl;
    cprintf("Welcome Adarsh, elite 4 member #4 (why are you here?) ") ;
    getch();
    clrscr();
    return 5;
  }
  else
  {
    cout<<endl;
    cprintf("Wrong password, try again.");
    getch();
    clrscr();
    goto again;//return login(p1);
  }
}

/*void test()
{
  cout<<"create pokemon";
  struct poke p[2];struct atk at;char a[2][20];
  for(int i=0;i<2;i++)
  {
    cout<<"choose the name of pkmn";
    gets(a[i]);
    strcpy(p[i].name,a[i]);
    cout<<"enter health"  ;
    cin>>p[i].hp[0];
    cout<<"enter atk stat" ;
    cin>>p[i].atk;
    cout<<"enter def stat";
    cin>>p[i].def;
    cout<< "type 1 and typ 2" ;
    cin>>p[i].typ[0];cin>>p[i].typ[1];
  }
  cout<<"choose the atack pow";
  cin>>at.pow;
  at.acc=100;
  cout<<"choose the atk typ";
  cin>>at.typ;
}*/

//initialising pokemons and moves for character...notthing much
void crt_elite4(int x,struct poke pl1[],struct poke pl2[],struct poke pk[6],struct atk a[],struct atk at[6][4],char p2[20])
{
  if(x==4)
  {
    strcpy(p2,"adarsh");
    pk[0]=pl2[1];pk[1]=pl1[7];pk[2]=pl1[12];pk[3]=pl1[11];pk[4]=pl2[0];pk[5]=pl2[23];pk[3].atk+=4;pk[3].def+=4;pk[3].spd+=4;
    at[0][0]=a[17];at[0][1]=a[1];at[0][2]=a[6];at[0][3]=a[12];at[1][0]=a[3];at[1][1]=a[0];at[1][2]=a[11];at[1][3]=a[7];
    at[2][0]=a[3];at[2][1]=a[1];at[2][2]=a[2];at[2][3]=a[6];at[3][0]=a[3];at[3][1]=a[13];at[3][2]=a[10];at[3][3]=a[9];
    at[4][0]=a[17];at[4][1]=a[12];at[4][2]=a[16];at[4][3]=a[7];at[5][0]=a[27];at[5][1]=a[3];at[5][2]=a[5];at[5][3]=a[4];
  }
  else if(x==3)
  {
    strcpy(p2,"prabhy");
    pk[0]=pl2[3];pk[1]=pl2[2];pk[2]=pl2[4];pk[3]=pl2[5];pk[4]=pl2[6];pk[5]=pl2[22];pk[1].atk+=4;pk[1].def+=4;pk[1].spd+=4;
    at[0][0]=a[14];at[0][1]=a[8];at[0][2]=a[7];at[0][3]=a[2];at[1][0]=a[18];at[1][1]=a[12];at[1][2]=a[9];at[1][3]=a[3];
    pk[0].atk+=1;pk[0].def+=1;pk[0].spd+=1;
    at[2][0]=a[14];at[2][1]=a[1];at[2][2]=a[10];at[2][3]=a[0];at[3][0]=a[18];at[3][1]=a[12];at[3][2]=a[3];at[3][3]=a[15];
    at[4][0]=a[14];at[4][1]=a[0];at[4][2]=a[2];at[4][3]=a[10];at[5][0]=a[26];at[5][1]=a[11];at[5][2]=a[7];at[5][3]=a[5];
  }
  else if(x==2)
  {
    strcpy(p2,"akhouri");
    pk[0]=pl2[7];pk[1]=pl2[8];pk[2]=pl2[9];pk[3]=pl2[10];pk[4]=pl2[11];pk[5]=pl2[21];pk[2].atk+=4;pk[2].def+=4;pk[2].spd+=4;
    at[0][0]=a[5];at[0][1]=a[10];at[0][2]=a[13];at[0][3]=a[9];at[1][0]=a[5];at[1][1]=a[8];at[1][2]=a[0];at[1][3]=a[7];pk[1].atk+=2;pk[1].def+=2;pk[1].spd+=2;
    at[2][0]=a[19];at[2][1]=a[15];at[2][2]=a[7];at[2][3]=a[1];at[3][0]=a[5];at[3][1]=a[16];at[3][2]=a[6];at[3][3]=a[2];
    at[4][0]=a[19];at[4][1]=a[9];at[4][2]=a[11];at[4][3]=a[7];at[5][0]=a[25];at[5][1]=a[19];at[5][2]=a[1];at[5][3]=a[7];
  }
  else if(x==1)
  {
    strcpy(p2,"danish");
    pk[0]=pl2[12];pk[1]=pl2[13];pk[2]=pl2[14];pk[3]=pl2[15];pk[4]=pl1[13];pk[5]=pl2[20];pk[4].atk+=4;pk[4].def+=4;pk[4].spd+=3;
    at[0][0]=a[11];at[0][1]=a[6];at[0][2]=a[3];at[0][3]=a[1];at[1][0]=a[20];at[1][1]=a[5];at[1][2]=a[0];at[1][3]=a[7];pk[0].atk+=2;pk[0].def+=2;pk[0].spd+=2;
    at[2][0]=a[11];at[2][1]=a[8];at[2][2]=a[14];at[2][3]=a[4];at[3][0]=a[20];at[3][1]=a[3];at[3][2]=a[10];at[3][3]=a[12];
    at[4][0]=a[11];at[4][1]=a[4];at[4][2]=a[0];at[4][3]=a[7];at[5][0]=a[24];at[5][1]=a[8];at[5][2]=a[5];at[5][3]=a[7];
  }
  else if(x==0)
  {
    strcpy(p2,"anant");
    pk[0]=pl1[10];pk[1]=pl1[0];pk[2]=pl1[3];pk[3]=pl1[5];pk[4]=pl1[14];pk[5]=pl2[19];pk[0].atk+=2;pk[0].def+=2;pk[0].spd+=2;pk[1].atk+=2;pk[1].def+=2;pk[1].spd+=1;
    at[0][0]=a[20];at[0][1]=a[9];at[0][2]=a[9];at[0][3]=a[0];at[1][0]=a[21];at[1][1]=a[8];at[1][2]=a[2];at[1][3]=a[0];pk[2].atk+=2;pk[2].def+=2;pk[2].spd+=1;
    at[2][0]=a[19];at[2][1]=a[7];at[2][2]=a[1];at[2][3]=a[3];at[3][0]=a[22];at[3][1]=a[13];at[3][2]=a[4];at[3][3]=a[14];pk[3].atk+=2;pk[3].def+=2;pk[3].spd+=1;
    at[4][0]=a[12];at[4][1]=a[13];at[4][2]=a[5];at[4][3]=a[10];at[5][0]=a[23];at[5][1]=a[11];at[5][2]=a[7];at[5][3]=a[0];pk[4].atk+=2;pk[4].def+=2;pk[4].spd+=1;
  }
}

void championship(struct poke pk_list1[],struct poke pk_list2[],struct atk at[],char p1[],char p2[],int log1)
{
  struct poke pk1[6],pk2[6];
  struct atk at1[6][4], at2[6][4];
  int s1,s2,a1,a2,next,c,i;
  clrscr();

  choosep(pk1,pk_list1,pk_list2,6,0,0,log1);//working on log required
  clrscr();

  for( i=0;i<24;i++)
  {
    if(i==0||i==4||i==8||i==12||i==16||i==20)//(i%4==0)
    {
      clrscr();
      for(int x=0;x<17;x++)
      {
	       cprintf("      %i %s",x+1,at[x].name);cout<<'\t';
	       if(x%2!=0)
	       cout<<endl;
      }
      cout<<endl;
      int e=i/4;
      cprintf("%s choose your 4 atks for %s",p1,pk1[e].name);
      choosem(at1,at,4,0,0,e);
    }
  }

  for( i=4;i>=0;i--)
  {
    clrscr();
    crt_elite4(i,pk_list1,pk_list2,pk2,at,at2,p2);
    graphics(i,p1);
    s1=0;s2=0;
    clrscr();
    for(int k=0;k<30;k++)
    {
      int z=spdchk(pk1[s1],pk2[s2]);
      c=0;
      for(int l=0;l<2;l++)
      {
	       if(l==0)
	       {
	          a1=health_bar(pk1[s1],pk2[s2], at1[s1]);
		        a1=a1-1;
		        swit_ai(pk1,pk2,at1,at2,s1,s2,next,2);
		        if(next==s2)
		          a2=pkmn_move_search(pk2,s2,pk1[s1],at2[s2],18,2,1,2);
		        else
		          a2=4;
	       }
	       if(a1==4)
	      {
		      party_pkmn(pk1,6);
		      swt(p1,s1,pk1,4);
		      z=2;
		      l=l+1;
	      }
	      if(a2==4)
	      {
	        s2=next;
	        cprintf("%s sends out %s",p2,pk2[s2].name);
	        delay(600);
	        z=1;
	        l=l+1;
	      }
	      if(z==1)
	      {
	        atkf(pk1[s1],pk2[s2],at1[s1][a1]);
	        z=2;
	      }
	      else
	      {
	        atkf(pk2[s2],pk1[s1],at2[s2][a2]);
	        z=1;
	      }

	      if(pk1[s1].hp[0]<=0)
	      {
	        cprintf("%s fainted",pk1[s1].name);cout<<endl;
	        delay(600);
	        c=2;
	        break;
	      }
	      if(pk2[s2].hp[0]<=0)
	      {
	        cprintf("%s fainted",pk2[s2].name);
	        cout<<endl;
	        delay(600);
	        c=1;
	        break;
	      }
	      getch();
      }

      if(pkmn_check(pk1,6)==0)
      {
	      c=2;
	      break;
      }
      else if(pkmn_check(pk2,6)==0)
      {
	      c=1;
	      break;
      }
      else if(c==2)
      {
	      party_pkmn(pk1,6);
	      swt(p1,s1,pk1,4);
      }
      else if(c==1)
      {
	      s2=ch_pkmn2(pk2,s2,pk1[s1],at2[s2],1);
	      cprintf("%s sends out %s",p2,pk2[s2].name);
	      delay(600);
      }
    }
    textcolor(1);
    if(c==1)
    {
      if(i<=0)
	    break;
      cprintf("%s won",p1);
      clrscr();
      cout<<"next battle"<<endl;
      getch();
      pkmn_refresh(pk1,6);
    }
    else if(c==2)
    {
      cprintf("%s won",p2);
      getch();
      break;
    }
  }

  if(c==1&&i<=0)
  {
    graphics(-1,p1);
  }
}

void main()
{
  char p1[20], p2[20];
  clrscr();
  lg:
    ;
  int log1=login(p1);
  char bv;
  do
  {
    list:
	  ;
    clrscr();
    int e,x,y,z,a,c=0,pla, s1=0,s2=0,next=7;
    struct poke pk1[6], pk2[6];
    atk m[3][4], n[3][4];

    struct poke pk_list1[18]={{"Charizard",{305,305},240,200,221,{9,2}},
					  {"Venusaur",{330,330},200,230,180,{11,3}},
					  {"Blastoise",{315,315},185,256,164,{10,18}},
					  {"Dragonite",{321,321},235,215,216,{15,2}},
					  {"Gengar",{295,295},250,186,233,{7,3}},
					  {"Electiwire",{313,313},236,210,201,{12,18}},//Lavalue=5
					  {"Mamoswine",{320,320},205,218,173,{14,4}},
					  {"Alakazam",{300,300},243,198,234,{13,18}},
					  {"Gyrados",{309,309},230,194,190,{10,2}},
					  {"Pidgeot",{290,290},231,180,238,{2,18}},
					  {"Tyranitar",{315,315},205,257,146,{5,16}},//Lvalue=10
					  {"Metagross",{305,305},210,240,200,{8,13}},
					  {"Delfox",{301,301},234,206,211,{9,13}},
					  {"Greninja",{305,305},232,200,235,{10,16}},
					  {"Lucario",{310,310},237,211,190,{1,8}},
					  {"Feraligator",{312,312},220,220,200,{10,18}},
					  {"Torterra",{320,320},213,243,180,{11,5}},
					  {"Blaziken",{308,308},247,200,223,{9,1}}
					  };
    struct poke pk_list2[24]={{"Gallade",{285,285},234,217,206,{1,13}},
					  {"Espeon",{325,325},193,229,197,{13,18}},
					  {"Slacking",{308,398},238,226,175,{0,18}},
				    {"Togekiss",{290,290},204,238,231,{2,0}},
			      {"Pyroar",{285,285},246,192,220,{9,0}},
					  {"Meliotta",{314,314},226,226,184,{1,0}},//Lvalue=5
					  {"heloisk",{295,295},224,188,226,{12,0}},
					  {"Tyrantrum",{305,305},194,237,170,{5,15}},
					  {"Noivern",{300,300},222,210,234,{2,15}},
					  {"Haxorus",{310,310},232,206,201,{15,18}},
					  {"Dragalge",{295,295},226,220,198,{3,15}},
					  {"Flygon",{290,290},221,221,211,{4,15}},
					  {"Spiritomb",{286,286},233,221,224,{7,16}},
					  {"Hydreigon",{316,316},234,218,209,{15,16}},
					  {"Mandibuzz",{300,300},188,247,224,{2,16}},
					  {"Zoroark",{290,290},241,193,233,{16,18}},//Lvalue=15
					  {"Scrafty",{290,290},226,200,186,{1,16}},
					  {"Foritress",{313,313},200,252,203,{6,8}},
					  {"Aerodactyl",{314,314},230,215,225,{5,2}},//Lvalue=20
					  {"Mewtwo",{300,300},265,204,237,{13,18}},
					  {"Yveltal",{305,305},260,196,234,{16,2}},
					  {"Rayquaza",{300,300},243,220,227,{15,2}},
					  {"Arceus",{260,260},240,240,200,{0,18}},
					  {"Lugia",{320,320},210,250,228,{2,13}}
					  };
    atk at[28]={{"Thunderbolt",80,90,12},//Lvalue=0
			    {"Flamethrower",85,85,9},
			    {"Solarbeam",110,80,11},
			    {"Psychic",92,86,13},
			    {"watergun",75,100,10},
			    {"Dragon Pulse",102,88,15},
			    {"Shadow Ball",86,92,7},
			    {"Ice Beam",87,90,14},
			    {"Brave Bird",103,85,2},
			    {"Earthquake",100,94,4},
			    {"Rock Slide",90,88,5},//Lvalue=10
			    {"Dark Pulse",88,93,16},
			    {"Aura Sphere",96,93,1},
			    {"Meteor Mash",102,86,8},
			    {"Double-Edge",90,92,0},
			    {"Megahorn",101,87,6},
			    {"Poison Jab",84,100,3},
			    {"Psybeam",88,95,13},
			    {"Thrash",100,91,0},
			    {"Outrage",105,94,15},
			    {"Crunch",86,100,16},//Lvalue=20
			    {"Fire Blast",100,83,9},
			    {"Thunder Punch",86,100,12},
		      {"Psystrike",115,85,13},
			    {"Oblivion Wing",118,76,16},
			    {"Dragon Ascent",110,90,2},
			    {"Judgement",120,80,0},
			    {"Aeroblast",106,88,2}
			    };

    pla=menu();

    if(pla==4)
      goto lg;
    else if(pla==5)
      exit(0);//break; was replaced
    else if(pla==3)
    {
      championship(pk_list1,pk_list2,at,p1,p2,log1);
      goto list;
    }
    textcolor(1);
    float b,q;
    clrscr();
    textcolor(8);
    choosep(pk1,pk_list1,pk_list2,3,0,0,log1);
    //working on log required
    clrscr();
    if(pla==2)
    {
      clrscr();
      textcolor(4);
      cprintf("PLAYER 2 ");
      int log2=login(p2);
      clrscr();
      choosep(pk2,pk_list1,pk_list2,3,0,0,log2);
      //working on log required
      clrscr();
    }
    else
    choosep(pk2,pk_list1,pk_list2,3,1,15,log1);
    // choosep(pk2,p,3,1,11,log1);
    textcolor(11);
    cout<<endl;
    clrscr();
    textcolor(14);
    for(int i=0;i<12;i++)
    {
      if(i%4==0||i==0)
      {
	      clrscr();
	      for(int x=0;x<17;x++)
	      {
		      cprintf("      %i %s",x+1,at[x].name);cout<<'\t';
	        if(x%2!=0)
		      cout<<endl;
	      }
	      cout<<endl;
	      int e=i/4;
	      cprintf("%s choose your 4 atks for %s",p1,pk1[e].name);
	      choosem(m,at,4,0,0,e);
      }
    }
    if(pla==2)
    {
      for(i=0;i<12;i++)
      {
	      if(i%4==0||i==0)
	      {
		      clrscr();
		      for(int x=0;x<17;x++)
		      {
		        cprintf("      %i %s",x+1,at[x].name);cout<<'\t';
		        if(x%2!=0)
		        cout<<endl;
		      }
		      cout<<endl;
		      int e=i/4;
		      cprintf("%s choose your 4 atks for %s",p2,pk2[e].name);
		      choosem(n,at,4,0,0,e);
	      }
      }
    }
    else
      choosem(n,at,12,1,17,0);
    for(int k=0;k<15;k++)
    {
      z=spdchk(pk1[s1],pk2[s2]);
      c=0;
      for(int l=0;l<2;l++)
      {
	      if(l==0)
	      {
		      a=health_bar(pk1[s1],pk2[s2],m[s2]);;
		      a=a-1;
		      textcolor(12);
		      if(pla==2)
		      {
		        e=health_bar(pk2[s2],pk1[s1],n[s1]);;
		        e=e-1;
		      }
		      else
		      {
	          //swit_ai(pk1,pk2,m,n,s1,s2,next);
		        //if(next==s2)
		        //e=move_ai(pk1,pk2,m,n,s1,s2,next);
		        e=pkmn_move_search(pk2,s2,pk1[s1],n[s2],18,2,1,2);
		      }
	      }
	      if(a==4)
	      {
		      party_pkmn(pk1,3);
		      swt(p1,s1,pk1,4);
		      z=2;
		      l=l+1;
		      //health_bar(pk1[s1],pk2[s2],m[s1]);
	      }
	      if(e==4)
	      {
		      party_pkmn(pk2,6);
		      swt(p2,s2,pk2,4);
		      z=1;
		      l=l+1;
		      //health_bar(pk2[s2],pk1[s1],n[s2]);
	      }
	      if(z==1)
	      {
		      atkf(pk1[s1],pk2[s2],m[s1][a]);
		      z=2;
	      }
	      else
	      {
		      atkf(pk2[s2],pk1[s1],n[s2][e]);
		      z=1;
	      }
	      if(pk1[s1].hp[0]<=0)
	      {
		      cprintf("%s fainted",pk1[s1].name);cout<<endl;
		      delay(600);
		      c=2;
		      break;
	      }
	      if(pk2[s2].hp[0]<=0)
	      {
		      cprintf("%s fainted",pk2[s2].name);
		      cout<<endl;
		      delay(600);
		      c=1;
		      break;
	      }
	      getch();
      }
      if(pkmn_check(pk1,3)==0)
      {
	      c=2;
	      break;
      }
      else if(pkmn_check(pk2,3)==0)
      {
	      c=1;
	      break;
      }
      else if(c==2)
      {
	      party_pkmn(pk1,3);
	      swt(p1,s1,pk1,4);
      }
      else if(c==1)
      {
	      if(pla==2)
	      {
		      party_pkmn(pk2,3);
		      swt(p2,s2,pk2,4);
	      }
	      else
	      {
		      swt(p2,s2,pk2,3);
	      }
      }
    }
    textcolor(1);
    cprintf("Player %d won",c);
    textcolor(2);
    cprintf("Play Again?(y/n)");
    cin>>bv;
    tolower(bv);
  }while(bv=='y');
}
