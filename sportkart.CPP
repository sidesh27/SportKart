//PROGRAM TO DEVELOP A GUI SIMULATION OF SPORTS GOODS ONLINE SHOPPING WEBSITE - SportKart
#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<iostream.h>
#include<graphics.h>
#include<dos.h>
#include<fstream.h>
#include<process.h>
#include<math.h>
#include<dos.h>
#include<stdlib.h>

//Graphics initialisation
int gdrive=DETECT,gmode=DETECT;

//Function defenitions
int main_menu();
int callmouse();
int mousehide();
void joy();
void tnx();
void disp_template(int);
void sub_template(int);


//Global declarations
 int x,y,cl;
 //sports name
 char sname[][100]={"CRICKET","BASKETBALL","FOOTBALL","BADMINTON","TENNIS"};
 //coloumn 1
 char s1[][100]={"BATS","BALLS","BALLS","RAQUET","RAQUET"};
 //coloumn 2
 char s2[][100]={"PADS","HOOPS","CLEATS","BIRDS","BALLS"};
 //coloumn 3
 char s3[][100]={"BALLS","KITS","T.GEAR","GRIPS","NETS"};
 //coloumn 4
 char s4[][100]={"KITS","SHOES","JERSEY","STRING","SHOES"};
 //coloumn 5
 char s5[][100]={"OTHERS","OTHERS","OTHERS","OTHERS","OTHERS"};
    int b,c,d,loop=0;

//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$

  //global structure for storing products
    struct product
    {
     char pname[30];
     char pprice[30];
     }sk[30];
//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$

  //global class for each sport
  class spo
  {  public:
     char p[20][40];
     char p1[20][40];
     char p2[20][40];
     char p3[20][40];
     char p4[20][40];
     char p5[20][40];
     char pr1[10][10];
     char pr2[10][10];
     char pr3[10][10];
     char pr4[10][10];
     char pr5[10][10];
  } s[5]={{{"BATS","PADS","BALLS","KITS","OTHERS"},{"Kookaburra","RS Robinson","HRS Seamer","SS","Formaxis Helmet"},{"Adidas","SG Prolite","AVM Paxton","MRF","Dixon Helmet"},{"MRF-Genius", "SG Levitate", "CW Pink Leather","Adidas", "GM Gloves"},{"Puma", "Protoner WSG","SG Club Leather","SG","SG gloves"},{"Spartan", "MRF Pads","NIVIA", "NIKE","HRS Protective Gaurd"} ,
   {"1700", "2200", "340", "1505", "3000"},{"1000", "1400", "235", "1345", "2000"},{"2000","1400","150","1600","2400"},{"2500","400","300","3500","2000"},{"1000","2000","300","650","1500"}},
   {{"BALLS","HOOPS","KITS","SHOES","OTHERS"},{"Wilson Killer","Nerf Hoops","Wilson","Nike","Mesh bag"},{"Spalding NBA","Jordan hoops","Spalding","Jordan shoes","Top tie vest"},
     {"Radzon","Spadling-Beast","Nerf","Lovehike","Baden"},{"Baden Elite","Detrut","Glowcuit","DALLY","MOLPE"},{"EMISH","Iserhden Hoops","Dribble up","Stephens wears","Arm sleeve"},
     {"160","1800","2000","2000","1000"},{"150","2500","1500","3000","1000"},{"200","3000","3200","2500","1500"},{"250","2500","2100","1499","1000"},{"300","2499","4000","1500","800"}},

   {{"BALLS","CLEATS","T.GEAR","JERSEY","OTHERS"},{"Vector X","Nivia pro","Araina Konex","Liverpool Jersey","Kipsta Holdbag"},
    {"Cosco Rio","Gowin","Labzio","FC barcelona","Pepup Bag"},{"Nivia","Vector x","Smiledrive","Real madrid jersey","Dixon Net"},
    {"Nike Hi vis","Nivia Dominate","Accesplit","Argentina jersey","Cintz mesh bag"},{"Avatoz","Nike vortex","Basers","Germany jersey","Tube bag"},
    {"200","1000","2100","600","300"},{"150","1500","2500","500","400"},{"140","2400","2300","500","799"},{"210","2670","3200","300","850"},{"370","3110","2100","600","800"}},

    {{"RAQUET","BIRDS","GRIPS","STRINGS","OTHERS"}, {"Yonex Gr","Cosco Aero","Bloomon","Yonex-litanium","Victor kit'"},{"silver sb","Victor white","Aaine korex","Yonex nanogy","Get unisex net"},
     {"Yonex Nanogy","Yonex Mavis","Li-Ning","Victor Vs","One o one net"},{ "Hrs dynamax","ZOZO","Yonex grip","Li ning 7","Maspro Bag"},
     {"APACS","Straus Mavis","Gosen 0G10","Gosen G-Tone 9","Li ning net"},
     {"1000","400","100","900","1000"},{"1500","500","150","1000","800"},{"1200","600","200","1600","750"},{"1875","500","170","1700","870"},{"2300","780","300","2200","1100"}},


     {{"RAQUET","BALLS","NETS","SHOES","OTHERS"},{"HRS spidexx","Balobalt Golt","Metro Nylon","Addidas","Headband"},{"Spinway","JUKA UOKA","Edwards strap","Nike","Writsband"},{"Balobat","Spinway mini","Rol Dri Nets","Reebok","Karahul Pu grips"},{"Wilson Fusion","Head ATP","ILARTE","ASICS","Bushnell Velocity"},
      {"Nivia G-21","Head Out","Macgregor Nets","Nivia","Head protection tape"},
      {"2000","300","5000","2000","500"},{"1000","500","2800","2500","650"},{"1500","450","2500","3000","800"},{"2100","530","3010","2300","1010"},{"1450","300","3100","2345","1200"}}};

//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
	      //  MOUSE  FUNCTION

union REGS in,out;


void mouseposi(int *xpos,int *ypos,int *click)
{

 in.x.ax=3;
 int86(51,&in,&out);
 *click=out.x.bx;
 *xpos=out.x.cx;
 *ypos=out.x.dx;

}
//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
	    //                 MODE OF PAYMENT
void MOP()
{
cleardevice();
setfillstyle(7,9);
bar(0,0,getmaxx(),getmaxy());   //outer fill

setfillstyle(4,1);
bar(10,10,628,470);          //1st inner fill

setfillstyle(10,4);
bar(20,20,620,460);         //2nd inner fill

rectangle(10,10,628,470); //outer
rectangle(20,20,620,460); //inner
settextstyle(3,HORIZ_DIR,7);
outtextxy(160,30,"SPORTKART");
outtextxy(40,100,"MODE OF PAYMENT:");
settextstyle(3,HORIZ_DIR,6);
outtextxy(40,190,"CASH ON DELIVERY ");
outtextxy(40,260,"CARD ON DELIVERY ");
outtextxy(40,325,"REDEEM POINTS");
rectangle(540,200,590,250);
rectangle(540,270,590,320);
rectangle(540,340,590,390);
settextstyle(3,HORIZ_DIR,3);
outtextxy(550,210,"GO");
outtextxy(550,280,"GO");
outtextxy(550,350,"GO");
callmouse(); //function to get mouse pointer

	  //function to implement click and further actions

while(!kbhit())
   {
   //delay(100);
   mouseposi(&x,&y,&cl);
   if((cl&1==1)&&x>540&&x<590&&y>200&&y<250)
    {mousehide;tnx();     }
   else if((cl&1==1)&&x>540&&x<590&&y>270&&y<320)
    {mousehide();tnx(); }
    else if((cl&1==1)&&x>540&&x<590&&y>340&&y<390)
   { mousehide();tnx(); }

    }

}

//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
		  // THANK YOU AND FINAL PAGE
void tnx()
{             cleardevice();
setfillstyle(7,9);
bar(0,0,getmaxx(),getmaxy());   //outer fill

setfillstyle(4,1);
bar(10,10,628,470);          //1st inner fill

setfillstyle(10,3);
bar(20,20,620,460);         //2nd inner fill

rectangle(10,10,628,470); //outer
rectangle(20,20,620,460); //inner
 settextstyle(3,HORIZ_DIR,7);
outtextxy(160,30,"SPORTKART");
settextstyle(3,HORIZ_DIR,5);
outtextxy(50,140,"THANK YOU FOR CHOOSING");
outtextxy(50,180,"OUR SERVICES.WE WAIT TO ");
outtextxy(80,220,"SERVE YOU AGAIN SOON");
outtextxy(90,310,"VISIT FREQUENTLY FOR");
outtextxy(70,350,"EXCITING OFFERS & DEALS");
rectangle((getmaxx()/2)-40,410,(getmaxx()/2)+40,450);
outtextxy((getmaxx()/2)-35,404,"EXIT");
callmouse();

   callmouse();

//Function implementing click and further actions

   while(!kbhit())
   {
   //delay(100);
   mouseposi(&x,&y,&cl);
   if((cl&1==1)&&(x>(getmaxx()/2)-40)&&(x<(getmaxx()/2)+40)&&y>410&&y<450)
    exit(0);
    }
}



//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//                CART -DISPLAYING PDT AND DETAILS


void fun()
{
closegraph();
initgraph(&gdrive,&gmode,"c://turboc3//bgi");


setfillstyle(7,9);
bar(0,0,getmaxx(),getmaxy());   //outer fill

setfillstyle(4,1);
bar(10,10,628,470);          //1st inner fill

setfillstyle(10,5);
bar(20,20,620,460);         //2nd inner fill

rectangle(10,10,628,470); //outer
rectangle(20,20,620,460); //inner
settextstyle(3,HORIZ_DIR,5);
outtextxy(170,30,"CART");
//line(20,70,620,70);   //1st horiz line
//line(20,140,620,140);  //2nd horiz line
settextstyle(6,HORIZ_DIR,4);
outtextxy(30,80,"S.NO");
outtextxy(120,80,"PRODUCT");
outtextxy(325,80,"PRICE");
settextstyle(6,HORIZ_DIR,3);
int k=0,yin=125;double bill=0; char str[40];


while(k<=loop)
{

outtextxy(120,yin,sk[k].pname);
outtextxy(320,yin,sk[k].pprice);
yin+=30;
bill+=atoi(sk[k].pprice);
k++;
if(k<=loop)
{
itoa(k,str,10);
outtextxy(40,yin-30,str);
}
}

outtextxy(40,423,"BILL AMOUNT:");
 char string[50];
bill+=(0.13*bill);
itoa(bill,string,10);
outtextxy(250,423,string);
outtextxy(220,423,"Rs.");
 rectangle(510,406,615,456);
  outtextxy(462,60,"--INVOICE--");
 outtextxy(512,412,"CHECKOUT");
 outtextxy(460,120,"BILL NO.:");

 int hv;
 randomize();
 hv=1000+random(1001);
 itoa(hv,str,10);
 outtextxy(540,120,str);
 outtextxy(420,160,"DATE:");

 outtextxy(475,160,"22/01/2018");
 outtextxy(420,200,"GST: 15%");
 outtextxy(420,240,"SERVICE TAX: 3%");
 outtextxy(420,280,"DISCOUT:5%");

callmouse();
while(!kbhit())
   {

   mouseposi(&x,&y,&cl);
   if(loop<10)
   {
   rectangle(510,340,615,380);
  outtextxy(512,346,"BACK");
   if((cl&1==1)&&(x>510)&&(x<615)&&y>406&&y<456)
    {mousehide();MOP();   }

     if((cl&1==1)&&(x>510)&&(x<615)&&y>340&&y<380)
    {mousehide();joy();  }
    }

    else
    {
     if((cl&1==1)&&(x>510)&&(x<615)&&y>406&&y<456)
    {mousehide();MOP();   }
    }

    }

}
//*********************************************************
//                   FUNCTION TO ADD PDTs INTO CART

void happy(int a)
{
closegraph();
initgraph(&gdrive,&gmode,"c://turboc3//bgi");

int mj=0;
if(a!=0)
{

setfillstyle(7,9);
bar(0,0,getmaxx(),getmaxy());   //outer fill

setfillstyle(4,1);
bar(10,10,628,470);          //1st inner fill

setfillstyle(10,5);
bar(20,20,620,460);         //2nd inner fill

rectangle(10,10,628,470); //outer
rectangle(20,20,620,460); //inner

line(20,70,620,70);   //1st horiz line
line(20,140,620,140);  //2nd horiz line

line(40,20,40,70); //vertical line for <=

line(140,70,140,140);
line(260,70,260,140);
line(380,70,380,140);
line(500,70,500,140);

   settextstyle(6,HORIZ_DIR,4);

   outtextxy(40,85,s1[a-1]);
   outtextxy(160,85,s2[a-1]);
   outtextxy(280,85,s3[a-1]);
   outtextxy(400,85,s4[a-1]);
   outtextxy(510,85,s5[a-1]);
   outtextxy(200,25,sname[a-1]);
   settextstyle(8,HORIZ_DIR,3);

   outtextxy(80,160,s[a-1].p1[b]);
   outtextxy(80,216,s[a-1].p2[b]);
   outtextxy(80,272,s[a-1].p3[b]);
   outtextxy(80,328,s[a-1].p4[b]);
   outtextxy(80,384,s[a-1].p5[b]);
   outtextxy(360,160,s[a-1].pr1[b]);
   outtextxy(360,216,s[a-1].pr2[b]);
   outtextxy(360,272,s[a-1].pr3[b]);
   outtextxy(360,328,s[a-1].pr4[b]);
   outtextxy(360,384,s[a-1].pr5[b]);
   settextstyle(6,HORIZ_DIR,4);
    outtextxy(360,25,s[a-1].p[b]);
   outtextxy(23,20,"<");


//cart box
   rectangle(460,150,540,200);
   rectangle(460,206,540,256);
   rectangle(460,262,540,312);
   rectangle(460,318,540,374);
   rectangle(460,380,540,430);

   //display "CART"
   settextstyle(3,HORIZ_DIR,4);
   for(int v=160,w=0;w<5;v+=56,w++)
   {outtextxy(465,v,"CART");}


   line(598,20,598,70);
   outtextxy(602,20,">");
   callmouse();
   int a1,a2,a3,a4,a5; a1=a2=a3=a4=a5=0;

   while(!kbhit())
   {
   delay(100);
   mouseposi(&x,&y,&cl);
   if((cl&1==1)&&(x>460&&x<540&&y>150&&y<200))
   { if(a1<1)
   {
     strcpy(sk[loop].pname,s[a-1].p1[b]);
     strcpy(sk[loop].pprice,s[a-1].pr1[b]);
     settextstyle(3,HORIZ_DIR,3);
  outtextxy(545,160,"ADDED");

     loop++; }
    a1++;
    if(loop>=10)
    {mj=1;
    break;}

   }
   else if((cl&1==1)&&(x>460&&x<540&&y>206&&y<256))
   { if(a2<1)
   {
    strcpy(sk[loop].pname,s[a-1].p2[b]);
    strcpy(sk[loop].pprice,s[a-1].pr2[b]);
    settextstyle(3,HORIZ_DIR,3);
  outtextxy(545,216,"ADDED");

   loop++;}
   a2++;
   if(loop>=10)
    { 
mj=1;
break;}
   }
   else if((cl&1==1)&&(x>460&&x<540&&y>262&&y<312))
   {if(a3<1)
   {
    strcpy(sk[loop].pname,s[a-1].p3[b]);
    strcpy(sk[loop].pprice,s[a-1].pr3[b]);
    settextstyle(3,HORIZ_DIR,3);
  outtextxy(545,272,"ADDED");

    loop++;}
    a3++;
    if(loop>=10)
    {mj=1;
    break;}
   }
   else if((cl&1==1)&&(x>460&&x<540&&y>318&&y<374))
   {c=3;
   if(a4<1)
   {
    strcpy(sk[loop].pname,s[a-1].p4[b]);
    strcpy(sk[loop].pprice,s[a-1].pr4[b]);
    settextstyle(3,HORIZ_DIR,3);
  outtextxy(545,328,"ADDED");

    loop++;
    }
    a4++;
    if(loop>=10)
    {mj=1;
    break;}
   }
   else if((cl&1==1)&&(x>460&&x<540&&y>380&&y<430))
   {c=4;
   if(a5<1)
   {
    strcpy(sk[loop].pname,s[a-1].p5[b]);
    strcpy(sk[loop].pprice,s[a-1].pr5[b]);
    settextstyle(3,HORIZ_DIR,3);
  outtextxy(545,384,"ADDED");

    loop++; }
    a5++;
    if(loop>=10)
    {mj=1;
    break;}
   }

   else if((cl&1==1)&&(x>598&&x<620&&y>20&&y<70))
   {
   fun();
   break;
   }
   else if((cl&1==1)&&(x>20&&x<140&&y>70&&y<140))
  {
    mousehide();
    b=0;
    cleardevice();
    sub_template(a);

  }

else  if((cl&1==1)&&(x>140&&x<260&&y>70&&y<140))
  { mousehide();
  b=1;
  cleardevice();
    sub_template(a);
		    }
 else if((cl&1==1)&&(x>260&&x<380&&y>70&&y<140))
  {      mousehide();
  b=2;             cleardevice();
	            sub_template(a);

   }

else  if((cl&1==1)&&(x>380&&x<500&&y>70&&y<140))
  {mousehide();
  b=3;
  cleardevice();
  sub_template(a);

    }
 else if((cl&1==1)&&(x>500&&x<620&&y>70&&y<140))
  {mousehide();
  b=4;
  cleardevice();
  sub_template(a);

  }

  else if((cl&1==1)&&(x>20&&x<40&&y>20&&y<70))
  {

  mousehide();
   cleardevice();
   joy();

  }
   }

}
if(mj==1)
{
settextstyle(5,HORIZ_DIR,2);
outtextxy(40,425,"CART FULL (10 ITEMS) - CLICK > FOR BILL");
callmouse();
while(1)
{
mouseposi(&x,&y,&cl);
if((cl&1==1)&&(x>598&&x<620&&y>20&&y<70))
   {

   fun();
   break;
   }
}
}
}

//888888888888888888888888888888888888888888888888888888888
//  FUNCTION TO DISPLAY CATEGORIES OF SPORT PRODUCTS

void sub_template(int a)
{
closegraph();
initgraph(&gdrive,&gmode,"c://turboc3//bgi");
int mj=0;
if(a!=0)
{

setfillstyle(7,9);
bar(0,0,getmaxx(),getmaxy());   //outer fill

setfillstyle(4,1);
bar(10,10,628,470);          //1st inner fill

setfillstyle(10,5);
bar(20,20,620,460);         //2nd inner fill

rectangle(10,10,628,470); //outer
rectangle(20,20,620,460); //inner

line(20,70,620,70);   //1st horiz line
line(20,140,620,140);  //2nd horiz line

line(40,20,40,70); //vertical line for <=

line(140,70,140,140);
line(260,70,260,140);
line(380,70,380,140);
line(500,70,500,140);

   settextstyle(6,HORIZ_DIR,4);

   outtextxy(40,85,s1[a-1]);
   outtextxy(160,85,s2[a-1]);
   outtextxy(280,85,s3[a-1]);
   outtextxy(400,85,s4[a-1]);
   outtextxy(510,85,s5[a-1]);
   outtextxy(200,25,sname[a-1]);
   settextstyle(8,HORIZ_DIR,3);

   outtextxy(80,160,s[a-1].p1[b]);
   outtextxy(80,216,s[a-1].p2[b]);
   outtextxy(80,272,s[a-1].p3[b]);
   outtextxy(80,328,s[a-1].p4[b]);
   outtextxy(80,384,s[a-1].p5[b]);
   outtextxy(360,160,s[a-1].pr1[b]);
   outtextxy(360,216,s[a-1].pr2[b]);
   outtextxy(360,272,s[a-1].pr3[b]);
   outtextxy(360,328,s[a-1].pr4[b]);
   outtextxy(360,384,s[a-1].pr5[b]);
   settextstyle(6,HORIZ_DIR,4);
    outtextxy(360,25,s[a-1].p[b]);
   outtextxy(23,20,"<");

//cart box
   rectangle(460,150,540,200);
   rectangle(460,206,540,256);
   rectangle(460,262,540,312);
   rectangle(460,318,540,374);
   rectangle(460,380,540,430);
   //display "CART"
   settextstyle(3,HORIZ_DIR,4);
   for(int v=160,w=0;w<5;v+=56,w++)
   {outtextxy(465,v,"CART");
    }
   line(598,20,598,70);
   outtextxy(602,20,">");
   callmouse();
   int a1,a2,a3,a4,a5; a1=a2=a3=a4=a5=0;

   while(!kbhit())
   {
   delay(100);
   mouseposi(&x,&y,&cl);
   if((cl&1==1)&&(x>460&&x<540&&y>150&&y<200))
   { if(a1<1)
   {
     strcpy(sk[loop].pname,s[a-1].p1[b]);
     strcpy(sk[loop].pprice,s[a-1].pr1[b]);
     settextstyle(3,HORIZ_DIR,3);
  outtextxy(545,160,"ADDED");
     loop++; }
    a1++;
    if(loop>=10)
    {mj=1;
    break;}

   }
   else if((cl&1==1)&&(x>460&&x<540&&y>206&&y<256))
   { if(a2<1)
   {
    strcpy(sk[loop].pname,s[a-1].p2[b]);
    strcpy(sk[loop].pprice,s[a-1].pr2[b]);
    settextstyle(3,HORIZ_DIR,3);
  outtextxy(545,216,"ADDED");
   loop++;}
   a2++;
   if(loop>=10)
    {mj=1;
    break;}
   }
   else if((cl&1==1)&&(x>460&&x<540&&y>262&&y<312))
   {if(a3<1)
   {
    strcpy(sk[loop].pname,s[a-1].p3[b]);
    strcpy(sk[loop].pprice,s[a-1].pr3[b]);
    settextstyle(3,HORIZ_DIR,3);
  outtextxy(545,272,"ADDED");
    loop++;}
    a3++;
    if(loop>=10)
    {mj=1;
    break;}
   }
   else if((cl&1==1)&&(x>460&&x<540&&y>318&&y<374))
   {c=3;
   if(a4<1)
   {
    strcpy(sk[loop].pname,s[a-1].p4[b]);
    strcpy(sk[loop].pprice,s[a-1].pr4[b]);
    settextstyle(3,HORIZ_DIR,3);
  outtextxy(545,328,"ADDED");
    loop++;
    }
    a4++;
    if(loop>=10)
    {mj=1;
    break;}
   }
   else if((cl&1==1)&&(x>460&&x<540&&y>380&&y<430))
   {c=4;
   if(a5<1)
   {
    strcpy(sk[loop].pname,s[a-1].p5[b]);
    strcpy(sk[loop].pprice,s[a-1].pr5[b]);
    settextstyle(3,HORIZ_DIR,3);
  outtextxy(545,384,"ADDED");
    loop++; }
    a5++;
    if(loop>=10)
    {mj=1;
    break;}
   }

   else if((cl&1==1)&&(x>598&&x<620&&y>20&&y<70))
   {
   fun();
   break;
   }
   else if((cl&1==1)&&(x>20&&x<140&&y>70&&y<140))
  {
    mousehide();
    b=0;
    cleardevice();
    sub_template(a);

  }

else  if((cl&1==1)&&(x>140&&x<260&&y>70&&y<140))
  { mousehide();
  b=1;
  cleardevice();
    sub_template(a);

		    }
 else if((cl&1==1)&&(x>260&&x<380&&y>70&&y<140))
  {      mousehide();
  b=2;          cleardevice();
	 sub_template(a);
 }

else  if((cl&1==1)&&(x>380&&x<500&&y>70&&y<140))
  {mousehide();
  b=3;
  cleardevice();
  sub_template(a);

    }
 else if((cl&1==1)&&(x>500&&x<620&&y>70&&y<140))
  {mousehide();
  b=4;
  cleardevice();
  sub_template(a);

  }

  else if((cl&1==1)&&(x>20&&x<40&&y>20&&y<70))
  {

  mousehide();
   cleardevice();
   joy();

  }
  }

}
if(mj==1)
{
settextstyle(8,HORIZ_DIR,3);
outtextxy(40,425,"CART FULL (10 ITEMS) - CLICK > FOR BILL");
callmouse();int sj=0;
while(sj==0)
{
mouseposi(&x,&y,&cl);
if((cl&1==1)&&(x>598&&x<620&&y>20&&y<70))
   {       sj=1;
   fun();
   break;
   }
}
}
}

//NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN
//                FUNCTION TO SHOW MOUSE POINTER
int callmouse()
{
 in.x.ax=1;
 int86(51,&in,&out);
 return 1;
}
//NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN
//                  FUNCTION TO RESTRICT MOUSE
void restrictmouseptr(int x1,int y1,int x2,int y2)
{

 in.x.ax=7;
 in.x.cx=x1;
 in.x.dx=x2;
 int86(51,&in,&out);
 in.x.ax=8;
 in.x.cx=y1;
 in.x.dx=y2;
 int86(51,&in,&out);

}

//YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY
//                               FUNCTION TO HIDE MOUSE
int mousehide()
{
in.x.ax=2;
int86(51,&in,&out);
return 1;
}
//UUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUU
void help();
void about();
void disclaimer();
//void mousehide();

//RRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRR

		 // FUNCTION TO DISPLAY HELP PAGE

void help()
{
closegraph();
initgraph(&gdrive,&gmode,"c://turboc3//bgi");
setfillstyle(7,9);
bar(0,0,getmaxx(),getmaxy());   //outer fill


setfillstyle(4,1);
bar(10,10,628,470);          //1st inner fill

setfillstyle(CLOSE_DOT_FILL,13);

bar(20,20,620,460);         //2nd inner fill

rectangle(30,25,90,70);
settextstyle(3,HORIZ_DIR,4);
outtextxy(40,25,"<=");
rectangle(10,10,628,470); //outer
rectangle(20,20,620,460); //i
settextstyle(3,HORIZ_DIR,6);
outtextxy(270,35,"HELP");
settextstyle(3,HORIZ_DIR,4);
outtextxy(135,120,"WELCOME TO SPORTKART");
outtextxy(200,420,"ENJOY SHOPPING");
outtextxy(35,160,"Login into your account or Sign up");
settextstyle(3,HORIZ_DIR,3.8);
outtextxy(35,210,"Use mouse to select the sport and choose products");
outtextxy(35,240,"click < to go back to the main menu and ");
outtextxy(35,270,"click > to view items in your cart");
outtextxy(35,310,"click on the equipment name to explore products");
outtextxy(35,350,"in the billing section review products enter quantity,");
outtextxy(35,380,"avail offers,choose mode of payment and checkout");
 callmouse();
 int status=0;
 while(status==0)
 {
  mouseposi(&x,&y,&cl);
   if((cl&1)==1&&(x>35&&x<620&&y>20&&y<460))
{mousehide();
main_menu();status=1;}
}
}
//#########################################################

//               FUNCTION TO DISPLAY DISCLAIMER 

void disclaimer()
{
closegraph();
initgraph(&gdrive,&gmode,"c://turboc3//bgi");
setfillstyle(7,9);
bar(0,0,getmaxx(),getmaxy());   //outer fill

setfillstyle(4,1);
bar(10,10,628,470);          //1st inner fill

setfillstyle(CLOSE_DOT_FILL,13);
bar(20,20,620,460);         //2nd inner fill
settextstyle(3,HORIZ_DIR,4);
rectangle(30,25,90,70);
outtextxy(40,25,"<=");
rectangle(10,10,628,470); //outer
rectangle(20,20,620,460); //i
settextstyle(3,HORIZ_DIR,6);
outtextxy(200,35,"DISCLAIMER");

settextstyle(3,HORIZ_DIR,4);
outtextxy(35,120,"ALL PRODUCTS SOLD ON SPORTKART");
outtextxy(130,150,"ARE GENUINE AND ORGINAL");
settextstyle(3,HORIZ_DIR,3.8);
outtextxy(35,200,"The seller only and not Sportkart is responsible for");
outtextxy(35,230,"quality,warranty,replacement of defective products");
settextstyle(3,HORIZ_DIR,4);
outtextxy(35,280,"Terms and Conditions apply for all");
outtextxy(35,310,"all promotions,discounts and offers");
outtextxy(35,360,"Return,Replacement/Refund would be ");
outtextxy(35,390,"provided if defective or damaged");
outtextxy(150,420,"product is delivered");
 callmouse();
 int status=0;
 while(status==0)
 {
  mouseposi(&x,&y,&cl);
   if((cl&1)==1&&(x>35&&x<620&&y>20&&y<460))
{mousehide(); main_menu();status=1;}
}
}

//DDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDD

		     //FUNCTION TO DISPLAY ABOUT PAGE
void about()
{
closegraph();
initgraph(&gdrive,&gmode,"c://turboc3//bgi");
rectangle(30,25,90,70);
outtextxy(40,25,"<=");
 setfillstyle(7,9);
bar(0,0,getmaxx(),getmaxy());   //outer fill


setfillstyle(4,1);
bar(10,10,628,470);          //1st inner fill

setfillstyle(CLOSE_DOT_FILL,13);
bar(20,20,620,460);         //2nd inner fill
settextstyle(3,HORIZ_DIR,4);
rectangle(30,25,90,70);
outtextxy(40,25,"<=");
rectangle(10,10,628,470); //outer
rectangle(20,20,620,460); //i
settextstyle(3,HORIZ_DIR,6);
 outtextxy(250,30,"ABOUT");
 settextstyle(3,HORIZ_DIR,4);
 outtextxy(35,100,"VERSION\t\t\t :\t2.0");
 outtextxy(35,150,"LAST MODIFIED:  22/11/17");
 outtextxy(35,190,"DEVELOPED BY:  JB SIDDHESHWAR");
 outtextxy(300,220,"KRISHNA KUMAR");
 outtextxy(300,260,"VISHAL B");
 outtextxy(300,300,"CHIRAG J");
 outtextxy(35,350,"DEVELOPED AT:  VCSK STUDIOS");
 outtextxy(35,390,"CONTACT\t\t\t:\tvcsk22@gmail.com");
 callmouse();
 int status=0;
 while(status==0)
 {
  mouseposi(&x,&y,&cl);
   if((cl&1)==1&&(x>35&&x<620&&y>20&&y<460))
{mousehide(); main_menu();status=1;}
} }

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

//                      structure for password
struct passcheck
{
char name[15];
char pass[15];
char cpass[15];
}f,g,h;


void joy();
void signup();
//    &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&


		      //     LOGIN  FUNCTION
void login()
{
closegraph();
initgraph(&gdrive,&gmode,"c://turboc3//bgi");
fstream r;
r.open("PASS1k.dat",ios::in);
char user[15];
char pas[15];
setfillstyle(7,9);
bar(0,0,getmaxx(),getmaxy());   //outer fill

setfillstyle(4,1);
bar(10,10,628,470);          //1st inner fill

setfillstyle(CLOSE_DOT_FILL,17);
bar(20,20,620,460);         //2nd inner fill

rectangle(10,10,628,470); //outer
rectangle(20,20,620,460); //inner
settextstyle(3,HORIZ_DIR,9);
 outtextxy(70,30,"SPORTKART");
 settextstyle(3,HORIZ_DIR,9);
 outtextxy(70,30,"SPORTKART");
  settextstyle(2,HORIZ_DIR,15);
  outtextxy(240,150,"Login");
   settextstyle(2,HORIZ_DIR,7);
 outtextxy(185,234,"Enter Username:");
 gotoxy(47,16);
  gets(user);
 outtextxy(185,282,"Enter Password:");

 gotoxy(47,19);
 int i;

  for(i=0;;i++)
 {
   pas[i]=(char)getch();
   if(pas[i]!=13&&pas[i]!=8)
   cout<<"*";
   else if(pas[i]==13)
   break;

 }
   int s=1;


 while(r.read((char*)&g,sizeof(g)))
 {
 if(strcmp(g.name,user)==0)
 {s=0;
 break;
 }
 }
 int stata=2;

for(int j=0;j<strlen(g.pass);j++)
 if(g.pass[j]==pas[j])
 stata=0;
 else
 {
 stata=1;
 break;
 }

 r.close();
 int bk=0;
 char qr;

 if(s==0&&stata==0)
 {
 outtextxy(200,330,"VALID CREDENTIALS");

 rectangle(240,380,350,420);
 outtextxy(270,390,"SHOP");
 outtextxy(200,430,"ENTER 'S' TO SHOP");
 bk=0;
 while(bk==0)
 {
 qr=getch();
  if(qr=='S'||qr=='s')
   {
   joy();
   bk=1;
   }
   else
   {
    bk=0;
   }
   }
   return;

 }
 else
 {
 outtextxy(180,330,"INVALID CREDENTIALS");
 rectangle(230,380,340,420);
 outtextxy(260,390,"MENU");
 outtextxy(60,430,"FIRST SIGNUP AS MEMBER--PRESS ANY KEY TO MENU");
 qr=getch();
 mousehide();
 main_menu();

}
}

//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//                                         SIGN UP FUNCTION

void signup()
{

closegraph();
initgraph(&gdrive,&gmode,"c://turboc3//bgi");

fstream q("PASS1k.dat",ios::app);
x:
setfillstyle(7,9);
bar(0,0,getmaxx(),getmaxy());   //outer fill


setfillstyle(4,1);
bar(10,10,628,470);          //1st inner fill

setfillstyle(CLOSE_DOT_FILL,17);
bar(20,20,620,460);         //2nd inner fill


 rectangle(10,10,628,470); //outer
 rectangle(20,20,620,460); //inner
 settextstyle(3,HORIZ_DIR,9);
 outtextxy(70,30,"SPORTKART");
 settextstyle(2,HORIZ_DIR,15);
  outtextxy(235,150,"SignUP");
 settextstyle(2,HORIZ_DIR,7);
 outtextxy(185,234,"Enter Username:");
 char ps[15];
 settextstyle(2,HORIZ_DIR,7);
 outtextxy(185,234,"Enter Username:");
 gotoxy(47,16);
 gets(ps);
 if(strlen(ps)>12||ps[0]=='\0'||ps[0]=='\b')
 {
 outtextxy(130,350,"Username must be greater than one");
 outtextxy(190,380,"and less than 12 letters");
 outtextxy(175,430,"Press ENTER to Continue");
 getch();
 goto x;
 }
 else
 strcpy(f.name,ps);

 outtextxy(185,282,"Enter Password:");
 gotoxy(47,19);
 gets(f.pass);
 if(strlen(f.pass)>12||f.pass[0]=='\0'||f.pass[0]=='\b')
 { outtextxy(130,350,"Username must be greater than one");
 outtextxy(190,380,"and less than 12 letters");
 outtextxy(175,430,"Press ENTER to Continue");
 getch();
 goto x;
 }
 outtextxy(185,330,"Confirm Password:");
 gotoxy(49,22);
 gets(f.cpass);
 int t;

 if(strcmp(f.pass,f.cpass)!=0)
{ outtextxy(200,390,"Password Mismatch!!");
 outtextxy(175,430,"Press ENTER to Continue");
  t=0;
  getch();
  goto x;
  }
  else
  {
  t=1;
 rectangle(260,380,335,420);
 outtextxy(265,390,"SIGNUP");
 outtextxy(35,430,"ACCOUNT CREATION SUCCESSFUL!! PRESS ENTER TO LOGIN");
 g=f;
 q.write((char*)&g,sizeof(g));//login();
 }
 q.close();
 char v;
 v=getch();
 if(v==13&&t==1)
 {
 login();
 }

 }

//????????????????????????????????????????????????????????????????
//                                     MAIN MENU FUNCTION

int main_menu()
{
closegraph();
initgraph(&gdrive,&gmode,"c://turboc3//bgi");
setfillstyle(7,9);
bar(0,0,getmaxx(),getmaxy());   //outer fill

setfillstyle(4,1);
bar(10,10,628,470);          //1st inner fill

setfillstyle(CLOSE_DOT_FILL,13);
bar(20,20,620,460);         //2nd inner fill


rectangle(10,10,628,470); //outer
rectangle(20,20,620,460); //i
settextstyle(3,HORIZ_DIR,9);

 outtextxy(70,30,"SPORTKART");

 settextstyle(8,HORIZ_DIR,5);
 rectangle(35,190,325,265);
 settextstyle(8,HORIZ_DIR,5);
 outtextxy(120,200,"LOGIN");
 rectangle(340,190,605,265);
 outtextxy(375,200,"SIGN-UP");
 rectangle(35,290,190,350);
 outtextxy(40,290,"ABOUT");
 rectangle(200,290,480,350);
 outtextxy(215,290,"DISCLAIMER");
 rectangle(490,290,615,350);
 outtextxy(500,290,"HELP");
 rectangle(260,370,390,430);
 outtextxy(280,370,"EXIT");
 callmouse();
 while(!kbhit())
 { mouseposi(&x,&y,&cl);
   if((cl&1)==1&&(x>490&&x<615&&y>290&&y<350))

   {
   mousehide();//cleardevice();
   help();
   return(0);
}
  else if((cl&1)==1&&(x>200&&x<480&&y>290&&y<350))
  {mousehide();//cleardevice();

   disclaimer();
   return(0);
   }
   else if((cl&1)==1&&(x>35&&x<190&&y>290&&y<350))
 {  mousehide();//cleardevice();

 about();
 return(0);
 }
  else if((cl&1)==1&&(x>340&&x<605&&y>190&&y<265))
  { mousehide();
    signup();
    return(0);
 }
 else if((cl&1)==1&&(x>260&&y>370&&x<390&&y<430))
 {
 exit(0);
 }
 else if((cl&1)==1&&(x>35&&x<325&&y>190&&y<265))
{mousehide();
login();

}
}
return 0;
}

int mret;
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//         FUNCTION FOR CHECKING CIRCLE COORDINATES

int cir_check(double x,double y)
{
 double a,b,c,d,e,f,g,h,i,j,k;
 a=pow((x-110),2);
 b=pow((y-110),2);
 d=pow(x-(getmaxx()/2),2);
 e=pow(y-(getmaxy()/2),2);
 f=pow((x-530),2);
 g=pow((y-110),2);
 h=pow((x-110),2);
 i=pow((y-360),2);
 j=pow((x-530),2);
 k=pow((y-360),2);
 c=pow(82,2);

 if((a+b)<c)
 return 1;
 else if((d+e)<c)
 return 5;
 else if((f+g)<c)
 return 2;
 else if((h+i)<c)
 return 3;
 else if((j+k)<c)
 return 4;
 else
 return 0;

}

//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
//                     GENERAL TEMPLATE FOR ALL SPORTS

void disp_template(int a)   //template for each sport
{
closegraph();
initgraph(&gdrive,&gmode,"c://turboc3//bgi");
callmouse();

if(a!=0)
{

setfillstyle(7,9);
bar(0,0,getmaxx(),getmaxy());   //outer fill

setfillstyle(4,1);
bar(10,10,628,470);          //1st inner fill

setfillstyle(10,5);
bar(20,20,620,460);         //2nd inner fill

rectangle(10,10,628,470); //outer
rectangle(20,20,620,460); //inner

line(20,70,620,70);   //1st horiz line
line(20,140,620,140);  //2nd horiz line

line(40,20,40,70); //vertical line for <=

line(140,70,140,140);
line(260,70,260,140);
line(380,70,380,140);
line(500,70,500,140);

   settextstyle(6,HORIZ_DIR,4);

   outtextxy(40,85,s1[a-1]);
   outtextxy(160,85,s2[a-1]);
   outtextxy(280,85,s3[a-1]);
   outtextxy(400,85,s4[a-1]);
   outtextxy(510,85,s5[a-1]);

   outtextxy(280,25,sname[a-1]);
   outtextxy(23,20,"<");

while(!kbhit())
{

  restrictmouseptr(20,20,620,450);
   mouseposi(&x,&y,&cl);
 if((cl&1==1)&&(x>20&&x<140&&y>70&&y<140))
  {

  mousehide();
  b=0;
  sub_template(a);

  }


else  if((cl&1==1)&&(x>140&&x<260&&y>70&&y<140))
  {
  mousehide();
  b=1;
  sub_template(a);

  }
 else if((cl&1==1)&&(x>260&&x<380&&y>70&&y<140))
  {
  mousehide();
  b=2;
  sub_template(a);

  }

else  if((cl&1==1)&&(x>380&&x<500&&y>70&&y<140))
  {
  mousehide();
  b=3;
  sub_template(a);

  }
 else if((cl&1==1)&&(x>500&&x<620&&y>70&&y<140))
  {
  mousehide();
  b=4;
  sub_template(a);

  }


  else if((cl&1==1)&&(x>20&&x<40&&y>20&&y<70))
  { mousehide();
    joy();
  }
  }}}

//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//                 FUNCTION FOR SEELECTING SPORT

void joy()
{
closegraph();
initgraph(&gdrive,&gmode,"c://turboc3//bgi");
setfillstyle(7,9);
bar(0,0,getmaxx(),getmaxy());   //outer fill


setfillstyle(4,1);
bar(10,10,628,470);          //1st inner fill

setfillstyle(10,5);
bar(20,20,620,460);         //2nd inner fill


rectangle(10,10,628,470); //outer
rectangle(20,20,620,460); //inner


circle(getmaxx()/2,getmaxy()/2,82);  //drawing 5 circles for each sport
circle(110,110,82);
circle(530,110,82);
circle(110,360,82);
circle(530,360,82);

    settextstyle(6,HORIZ_DIR,4);     //displaying names for each sport inside circle
    outtextxy(50,76,"CRICKET");
    outtextxy(275,215,"TENNIS");
    outtextxy(47,337,"FOOTBALL");
    outtextxy(458,340,"BADMINTON");
    outtextxy(450,85,"BASKETBALL");

line(20,240,129,240);   //4 lines for cross
line(620,240,510,240);
line(320,20,320,88);
line(320,460,320,390);

line(129,240,320,88);  //4 lines for diamond
line(129,240,320,390);
line(510,240,320,390);
line(510,240,320,88);


  callmouse();      //enables mouse
delay(100);
while(!kbhit())
{

 restrictmouseptr(20,20,620,450);
  mouseposi(&x,&y,&cl);   //obtaining mouse coordinates and click status

  if((cl&1)==1)
  { mousehide();
   disp_template(cir_check(x,y));  //display each sport table separately
   }
}}
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&

void main()

{
clrscr();

closegraph();
initgraph(&gdrive,&gmode,"c://turboc3//bgi");

mret=main_menu();
}

