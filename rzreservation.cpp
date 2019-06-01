#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<iostream>

//out train  have 4 coaches every coach has two chambers having 8-8 seats in ofthem each
using namespace std;
void clrscr()
{
    system("cls");
}

int count2=0;//for determining coach and seats
int count1=0;
int wait=0;
#define N 64//total no of seats
struct Traindetails
 {
  int seat;
  int status;//if status is zero then not booked
  int age;
  //char *berth;
  char berth[10];
  //char *coach;
  char coach[15];
  int pnr;
  int w;//if w is zero ,then ticket booked
  char name[20];
  struct Traindetails* next;
 };
typedef struct Traindetails* Train;

Train q1,q2,q3,c4,c5,c6;
Train findvacancy(Train);
int checkvacancy(Train);
void Delete();
void reform(Train);


void welcome(Train);
void welcome(Train t)
 {
  if(t->status==0)
   {
    //clrscr();
    cout<<"\n\n     CANCELLATION DETAILS\n\n";
    cout<<"PNR no.  :  "<<t->pnr;
    cout<<"\nName     :  "<<t->name;
    cout<<"\nAge      :   "<<t->age;
    cout<<"\nStatus   :  Cancelled \n\n";
    getch();
   }
  else
   if(t->w==0)
    {
    //clrscr();
     cout<<"\n\n     TICKET DETAILS\n\n";
     cout<<"PNR no.  :   "<<t->pnr;
     cout<<"\nName     :   "<<t->name;
     cout<<"\nAge      :   "<<t->age;
     cout<<"\nCoach    :   "<<t->coach;
     cout<<"\nSeat no. :   "<<t->seat;
     cout<<"\nBerth    :   "<<t->berth;
     cout<<"\nStatus   :  Booked \n\n";
     getch();

    }
   else
    {
    //clrscr();
     cout<<"\n\n     TICKET DETAILS\n\n";
    cout<<"PNR no.  :  "<<t->pnr;
    cout<<"\nName     :  "<<t->name;
    cout<<"\nAge      :   "<<t->age;
     cout<<"\nStatus   :  Waiting \n\n";
     getch();
    }

  }



Train Book(Train t,int ag,char nam[20])
 {
    // cout<<"\nwe are inside book fun";
   int s,d,v;
   Train t2,temp2,new1,temp,new2,t1;
   if(t==NULL)
    {
        //cout<<"\ninside if loop";
     count2++;
     count1++;
    // t=(Train)malloc(sizeof(struct Traindetails));
    t=new Traindetails;
    // t=new Train;
     t->age=ag;
     strcpy(t->name,nam);
     s=count2%8;//for berth

     t->status=1;
     t->w=0;

     //cout<<"\njust outside switch\n";
    // cout<<s;

     switch(s)
      {
          //cout<<"\ninside switch";
       case 1 : strcpy(t->berth,"L");
		break;
       case 2 : strcpy(t->berth,"M");
		break;
       case 3 : strcpy(t->berth,"U");
		break;
       case 4 : strcpy(t->berth,"L");
		break;
       case 5 : strcpy(t->berth,"M");
		break;
       case 6 : strcpy(t->berth,"U");
		break;
       case 7 : strcpy(t->berth,"SL");
		break;
       case 0 : strcpy(t->berth,"SU");
       //cout<<"\ninside switch";
		break;
      }
     // cout<<"\noutside if\n";
     t->pnr=count2;
     d=(count2-1)/16;//for coach
     t->next=NULL;
     //cout<<d;
     switch(d)
      {
         // cout<<"\ninside 2nd switch";
       case 0 : strcpy(t->coach,"s1");
		break;
       case 1 : strcpy(t->coach,"s2");
		break;
       case 2 : strcpy(t->coach,"s3");
		break;
       case 3 : strcpy(t->coach,"s4");
		break;
      }
     // cout<<"\noutside 2nd switch";
     if(count2%16==0)
      t->seat=16;
     else
      t->seat=count2%16;

     welcome(t);
    }
   else
    {
     v=checkvacancy(t);
     if(count2==N&&v==1)
      {
       clrscr();
       cout<<"\n\nSORRY NO TICKETS AVAILABLE ! ! !\n\n";
       cout<<"WAITING LIST ! ! !\n\n\n";
       if(q1==NULL)
	{
	 count1++;
	 wait++;
	 //q1=(Train)malloc(sizeof(struct Traindetails));
	 q1=new Traindetails;
	 //q1=new Train;
	 q1->age=ag;
	 strcpy(q1->name,nam);
	 q1->w=wait;
	 q1->next=NULL;
	 q1->pnr=count1;
	 q1->status=1;

	 welcome(q1);
	}
       else
	{
	 temp2=q1;
	 while(temp2->next!=NULL)
	  temp2=temp2->next;
	 //new1=(Train)malloc(sizeof(struct Traindetails));
	 new1=new Traindetails;
	 //new1=new Train;
	 temp2->next=new1;
	 new1->age=ag;
	 strcpy(new1->name,nam);
	 wait++;
	 new1->w=wait;
	 new1->status=1;
	 count1++;
	 new1->pnr=count1;
	 new1->next=NULL;
	 welcome(new1);
	}
      }
      else

      if(count2<N)
       {
	temp=t;
	while(temp->next!=NULL)
	 temp=temp->next;
	count2++;
	count1++;
	//new2=(Train)malloc(sizeof(struct Traindetails));
	new2=new Traindetails;
	//new2=new Train;
	temp->next=new2;
	new2->next=NULL;
	new2->age=ag;
	strcpy(new2->name,nam);
	new2->status=1;
	s=count2%8;
	new2->status=1;
	switch(s)
	 {
	  case 1 : strcpy(new2->berth,"L");
		   break;
	  case 2 : strcpy(new2->berth,"M");
		   break;
	  case 3 : strcpy(new2->berth,"U");
		   break;
	  case 4 : strcpy(new2->berth,"L");
		   break;
	  case 5 : strcpy(new2->berth,"M");
		   break;
	  case 6 : strcpy(new2->berth,"U");
		   break;
	  case 7 : strcpy(new2->berth,"SL");
		   break;
	  case 0 : strcpy(new2->berth,"SU");
		   break;
	 }
	new2->pnr=count2;
	d=(count2-1)/16;
	new2->w=0;
	switch(d)
	 {
	  case 0 : strcpy(new2->coach,"s1");
		   break;
	  case 1 : strcpy(new2->coach,"s2");
		   break;
	  case 2 : strcpy(new2->coach,"s3");
		   break;
	  case 3 : strcpy(new2->coach,"s4");
		   break;
	 }
	if(count2%16==0)
	 new2->seat=16;
	else
	 new2->seat=count2%16;
	welcome(new2);
       }
/*      else
       if(v==0)
	{
	  if(q1==NULL)
	  {
	   t1=(Train)findvacancy(t);
	   t1->age=ag;
	   strcpy(t1->name,nam);
	   t1->status=1;
	  }
	  else
	  {
	   t1=(Train)findvacancy(t);
	   t1->age=q1->age;
	   strcpy(t1->name,q1->name);
	   t1->status=1;
	   t1->w=0;
	   q1=(Train)Delete(q1);
	   reform(q1);
	}
   } */

    }

   return t;
 }


Train Cancellist(Train t)
 {
  Train temp=c5,new2;
  if(c5==NULL)
   {
    //c5=(Train)malloc(sizeof(struct Traindetails));
   c5=new Traindetails;
    // c5=new Train;
    c5->pnr=t->pnr;
    c5->age=t->age;
    strcpy(c5->name,t->name);
    c5->next=NULL;
    c5->status=0;//status zero means ticket cancel
    c5->w=0;
    return c5;
   }
  else
   {
    while(temp->next!=NULL)
       temp=temp->next;
    //new=(Train)malloc(sizeof(struct Traindetails));
    new2=new Traindetails;
    // new2=new Train;
    temp=new2;
    new2->age=t->age;
    strcpy(new2->name,t->name);
    new2->status=0;
    new2->w=0;
    new2->next=NULL;
    return t;
   }
  }

Train Cancel(Train t,int no)
  {
     Train temp=t,tt=q1;
     int c1=0,c2=0;
     while(temp->pnr!=no&&temp!=NULL)
      temp=temp->next;
      if(temp==NULL)
      {
       c1=1;
       while(tt!=NULL&&tt->pnr!=no)
	tt=tt->next;
      }
     else
      {
       temp->status=0;
       welcome(temp);
      }

      if(tt==NULL)
       c2=1;
      if(c1&&c2)
       {
	cout<<"Not yet booked ! ! !\n\n\n";
	getch();
       }
      else
       if(c1)
	{
	 tt->status=0;
	 welcome(tt);
	}


     if(q1!=NULL)
      {
       c5=Cancellist(temp);
       temp->status=1;
       temp->age=q1->age;
       strcpy(temp->name,q1->name);
       temp->pnr=q1->pnr;

       Delete();

       reform(q1);
      }
     return t;


  }



void Delete()
 {
  Train t=q1;
  q1=q1->next;
  free(t);

 }

void reform(Train q)
 {
  Train t=q;
  wait--;
  //count1--;
  while(t!=NULL)
   {
    t->w--;
  //  t->pnr--;
    t=t->next;
   }
 }


int checkvacancy(Train t)  //if no vacancy available then it will return 1 otherwise 0
 {
  Train temp=t;
  while(temp!=NULL)
    {
     if(temp->status==0)
       return 0;
     temp=temp->next;
    }
  return 1;
 }


Train findvacancy(Train t)
 {
  Train temp=t;
  while(temp!=NULL)
   {
    if(temp->status==0)
     return temp;
    temp=temp->next;
   }
  return temp;

 }

int checkavailable(Train t)
 {
  if(count2<N)
   return 1;
  else
   if(!checkvacancy(t))
    return 1;
   else
    return 0;
 }

void Printwait(Train  q)
 {
  Train t=q;
  if(t==NULL)
   {

    clrscr();
    cout<<"\n\nNO WAITING LIST\n\n";

   }
  while(t!=NULL)
   {
    cout<<"  %d     %d       %s      %d\n\n"<<t->pnr<<t->age<<t->name<<t->w;
    t=t->next;
   }
  getch();

 }


void Printchart(Train t)
 {
  Train temp=t;
  clrscr();
  cout<<"\n\n----------------------------------------------------------------------------------------\n\n";
  cout<<" PNR\t\t SEAT \t\tCOACH\t\t AGE\t\t NAME\t\t BERTH\n\n";
  cout<<"--------------------------------------------------------------------------------------------\n\n";
  while(temp!=NULL)
   {
    if(temp->status==1)
      cout<<"\t \n\n"<<temp->pnr<<"\t\t"<<temp->seat<<"\t\t"<<temp->coach<<"\t\t"<<temp->age<<"\t\t"<<temp->name<<"\t\t"<<temp->berth;
    else
      cout<<"  \n\n       NOT BOOKED    \n\n";
    temp=temp->next;
   }
  //cout<<"----------------------------------------\n\n";
  getch();

 }


void Printcancellist(int no,Train t)
 {
  Train temp=t;
  while(temp!=NULL)
   {
     if(temp->pnr==no)
      {
       clrscr();
       cout<<"\n\nPNR no.   :  \n\n"<<temp->pnr;
       cout<<"\nName     :  \n\n"<<temp->name;
       cout<<"\nAge      :  \n\n"<<temp->age;
       cout<<"\nStatus   :  Cancelled\n\n\n";
       getch();
      }
     temp=temp->next;
   }
 }

void checkstatus(int no,Train t,Train q)
 {
  Train temp;
  int c=0;
  if(no<=N)
   {
    temp=t;
    while(temp!=NULL)
     {
      if(temp->pnr==no)
	{
	 if(temp->status==1)
	  {
	   //clrscr();
	   cout<<"\n\nPNR number :  "<<temp->pnr;
	   cout<<"\nName       :  "<<temp->name;
	   cout<<"\nAge        :  "<<temp->age;
	   cout<<"\nSeat number : "<<temp->seat;
	   cout<<"\nCoach      : "<<temp->coach;
	   cout<<"\nBerth      : "<<temp->berth;
	   cout<<"\nStatus     :  Confirm\n\n";
	   getch();
	  }
	 else
	  {
	   //clrscr();
	   cout<<"\n\nPNR number : \n\n"<<temp->pnr;
	   cout<<"Name       :  \n\n"<<temp->name;
	   cout<<"Age        :  \n\n"<<temp->age;
//	   printf("Seat number : %d\n\n",temp->seat);
//	   printf("Coach      : %s \n\n",temp->coach);
	   cout<<"Status     :  Cancelled\n\n";
	   getch();
	  }

	 c=1;
	 break;
	}
      temp=temp->next;
     }
   }
  else
   {
     temp=q;
     while(temp!=NULL)
      {
       if(temp->pnr==no)

	  {
	   //clrscr();
	   cout<<"\n\nPNR number : "<<temp->pnr;
	   cout<<"\nName       :  "<<temp->name;
	   cout<<"\nAge        :  "<<temp->age;
//	   printf("Seat number : %d\n\n",temp->seat);
//	   printf("Coach      : %s \n\n",temp->coach);
	   cout<<"\nStatus     :  Waiting\n\n";
	   getch();

	  c=1;
	  break;
	 }
       temp=temp->next;
      }

   }
  if(c==0)
   {
    if(no>count1)
     cout<<"\n\nTicket not yet booked ! ! !\n\n\n";
    else
     Printcancellist(no,c5);
    getch();
   }
 }



int main()
 {
  Train t1,t2,t3;
  int ch,ch1,age,pnr;
  char nam[20];
  t1=NULL;
  q1=NULL;
  //clrscr();
/*  printf("Select the train number. . .\n\n");
  printf("1 . 2693     Pearl city express\n\n");
  printf("2 . 2679     Pandian express\n\n");
  printf("3 . 2685     Nellai express\n\n");
  scanf("%d",&ch);
  switch(ch)
   {
    case 1 :*/
	 while(1)
	     {
	     //clrscr();
//	     printf("Enter your choice. . .\n\n");
	     cout<<"1 . Book a ticket\n\n";
         cout<<"2 . Cancel a ticket\n\n";
	     cout<<"3 . Check availability\n\n";
	     cout<<"4 . Check PNR status\n\n";
	     cout<<"5 . Print the chart of booked tickets\n\n";
	     cout<<"6 . Print the waiting list\n\n";
	     cout<<"7 . Exit\n\n";
	     //scanf("%d",&ch1);
	     cin>>ch1;
	     switch(ch1)
	      {

	       case 1 : if(count2==N&&checkvacancy(t1))
			  cout<<"\n\nSorry ! ! Waiting list ! ! !\n\n";
			cout<<"\nEnter age and name of the person. . .";
			 //cout<<"\ninside main switch";
			//scanf("%d%s",&age,nam);
			cin>>age;
			cin>>nam;
			//gets(nam);

			t1=Book(t1,age,nam);
			break;
	       case 2 : cout<<"Enter the pnr number. . .";
			//scanf("%d",&pnr);
			cin>>pnr;
			t1=Cancel(t1,pnr);
			break;
	       case 3 : if(checkavailable(t1))
			  cout<<"\n\nTICKET AVAILABLE\n\n";
			else
			 cout<<"\n\nNOT AVAILABLE\n\n";
			getch();
			break;
	       case 4 : cout<<"Enter the PNR number. . .";
			//scanf("%d",&pnr);
			cin>>pnr;
			checkstatus(pnr,t1,q1);
			break;
	       case 5 : Printchart(t1);
			break;
	       case 6 : Printwait(q1);
			break;
	      }
	   // clrscr();
	    if(ch1==7)
	     break;


   }
   return 0;
 }
