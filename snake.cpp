#include <iostream.h>
#include <dos.h>
#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
int  is_food=0,score=0;
char score1[5];

void border()
{
  setcolor(12);
  //making border//
  // setfillstyle(1,12);
  rectangle(0,0,getmaxx(),getmaxy());
  rectangle(2,2,getmaxx()-2,getmaxy()-2);
  rectangle(4,4,getmaxx()-4,getmaxy()-4);
  rectangle(6,6,getmaxx()-6,getmaxy()-6);
  rectangle(8,8,getmaxx()-8,getmaxy()-8);
  //setfillstyle(1,7);
  rectangle(10,10,(getmaxx()-10),(getmaxy()-10));
  itoa(score,score1,10);
  settextstyle(1,0,1);
  textcolor(0);
  outtextxy(550,25,"SCORE : ");
  outtextxy(618,25,score1);

}


class snake_body
{
 public:

  int left,
      top ,
      right,
      bottom ;
  snake_body()
   {
    //randomising snake place//
    randomize();
    left=(random(10))*34;
    right=left+15;

    randomize();
    top=(random(10))*17;
    bottom=top+15;

   }
}s;

class snake_food
{
 public:
 int left,top,right,bottom;
 void generate_food()
  {
   is_food=1;
   //randomising food place//
   randomize();
   left=(random(10)+10)*34;
   right=left+15;

   randomize();
   top=((random(10))*34);
   bottom=top+15;

   //making food block//

   setcolor(5);
   setfillstyle(1,15);
   bar(left,top,right,bottom) ;

  }
}food,tempfood;

class transform
{
 public:

 void move(snake_body [],char,char&,int&);
 void snake(snake_body [],int &);

}t;

void transform::snake(snake_body body[],int &sz)
  {

    setcolor(5);
    setbkcolor(7);
    for(int i=0,dist=0;i<sz;i++,dist+=17)
     {
       if(i==sz-1)
	{
	 setfillstyle(1,4);
	 bar(body[i].left+dist,body[i].top,body[i].right+dist,body[i].bottom);
	}
       else
	{
	 setfillstyle(1,1);
	 bar(body[i].left+dist,body[i].top,body[i].right+dist,body[i].bottom);
	}

     }
  }

void transform::move(snake_body body[],char ch,char &snake_direction,int &sz)
  {

    //move dist =17 unit//
    int dist=17;

    border();

    setfillstyle(1,15);
    bar(tempfood.left,tempfood.top,tempfood.right,tempfood.bottom);

    //making new block part of snake//

   if(body[sz-1].left==tempfood.left && body[sz-1].top==tempfood.top && body[sz-1].right==tempfood.right && body[sz-1].bottom==tempfood.bottom)
     {

	is_food=0;
	score++;
	sz++;
	if(snake_direction=='w')
	{

	 body[sz-1].left= body[sz-2].left;
	 body[sz-1].right=body[sz-2].right;

	 body[sz-1].top=body[sz-2].top-dist;
	 body[sz-1].bottom=body[sz-2].bottom-dist;
	 bar(body[sz-1].left,body[sz-1].top,body[sz-1].right,body[sz-1].bottom);

	}
	if(snake_direction=='s')
	{
	 body[sz-1].left= body[sz-2].left;
	 body[sz-1].right=body[sz-2].right;

	 body[sz-1].top=body[sz-2].top+dist;
	 body[sz-1].bottom=body[sz-2].bottom+dist;
	 bar(body[sz-1].left,body[sz-1].top,body[sz-1].right,body[sz-1].bottom);

	}
	if(snake_direction=='d')
	{

	 body[sz-1].top=body[sz-2].top;
	 body[sz-1].bottom=body[sz-2].bottom;

	 body[sz-1].left= body[sz-2].left+dist;
	 body[sz-1].right=body[sz-2].right+dist;

	 bar(body[sz-1].left,body[sz-1].top,body[sz-1].right,body[sz-1].bottom);


	}
	if(snake_direction=='a')
	{

	 body[sz-1].top=body[sz-2].top;
	 body[sz-1].bottom=body[sz-2].bottom;

	 body[sz-1].left=body[sz-2].left-dist;
	 body[sz-1].right=body[sz-2].right-dist;
	 bar(body[sz-1].left,body[sz-1].top,body[sz-1].right,body[sz-1].bottom);
	}
       sound(4000);

     }

   else
     {

      //clearing old blocks//
      cleardevice();

      border();

      setfillstyle(1,15);
      bar(tempfood.left,tempfood.top,tempfood.right,tempfood.bottom);

      for(int i=0;i<sz-1;i++)
       {
	body[i]=body[i+1];
       // body[i].left=body[i+1].left;
       // body[i].right=body[i+1].right;
	setfillstyle(1,1);
	bar(body[i].left,body[i].top,body[i].right,body[i].bottom);
       }

      setfillstyle(1,4);
     if(ch=='d'|| ch=='M')
       {
	body[sz-1].left+=dist;
	body[sz-1].right+=dist;
	bar(body[sz-1].left,body[sz-1].top,body[sz-1].right,body[sz-1].bottom);

	snake_direction='d';
       }


     if(ch=='a'|| ch=='K')
       {
	body[sz-1].left-=dist;
	body[sz-1].right-=dist;
	bar(body[sz-1].left,body[sz-1].top,body[sz-1].right,body[sz-1].bottom);

	snake_direction='a';
       }

     if(ch=='w'|| ch=='H')
       {
	body[sz-1].top-=dist;
	body[sz-1].bottom-=dist;
	bar(body[sz-1].left,body[sz-1].top,body[sz-1].right,body[sz-1].bottom);

	snake_direction='w';
       }

     if(ch=='s'|| ch=='P')
       {
	body[sz-1].top+=dist;
	body[sz-1].bottom+=dist;
	bar(body[sz-1].left,body[sz-1].top,body[sz-1].right,body[sz-1].bottom);

	snake_direction='s';
       }
     }

   }

//function without classes//

void load_graphics()
{
  /* request auto detection */
  int gdriver = DETECT, gmode, errorcode;

  /* initialize graphics and local variables */
  initgraph(&gdriver, &gmode, "");

  /* read result of initialization */
  errorcode = graphresult();
   if(errorcode != grOk)  /* an error occurred */
     {
      printf("Graphics error: %s\n", grapherrormsg(errorcode));
      printf("Press any key to halt:");
      getch();
      exit(1); /* terminate with an error code */
     }
}

void load_game()
{
  setbkcolor(7);
  setcolor(4);
  rectangle(200,130,400,250);
  cout<<"\n\n\n\n\n\n\n\n\n\t\t\t\t PLEASE WAIT !!\n\n\n\t\t\t\tLOADING ..";
  delay(700);
  cout<<".";
  delay(700);
  cout<<".";
  delay(700);
  cout<<".";
  delay(700);
  cout<<".";
  delay(700);
  cout<<".";
  delay(700);
  cout<<".";
  delay(700);
  cleardevice();
}


void main()
{
  int sz=5;
  char snake_direction='d';

  // loading graphics //
  load_graphics();

  snake_body body[80];

  // loading screen//
  load_game();

  border();
  //making snake//
  t.snake(body,sz);

  // moving snake//
  char ch='d';
  while(body[sz-1].right<(getmaxx()-10) && body[sz-1].bottom<(getmaxy()-10) && body[sz-1].left>10 && body[sz-1].top>10)
   {
     if(kbhit())
      {
       ch=getch();
      }
     if(is_food==0)
      {
       food.generate_food();
       tempfood=food;
      }
     delay(150);
     nosound();

     t.move(body,ch,snake_direction,sz);
   }

   for(int i=0;i<3;i++)
    {
      sound(1000);
      delay(500/3);
      nosound();
      delay(150);
     }

  cleardevice();
  border();
  cout<<" \n\n\n\n\n\n\n\t\t\t\t YOU DEAD !!";
  cout<<" \n\n\t\t\t\t YOUR SCORE IS "<<score;
 getch();
 closegraph();
}
