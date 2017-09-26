/////////HEADERS
#include <iostream.h>
#include <conio.h>
#include <fstream.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<graphics.h>
#include<dos.h>
#include<time.h>
///////////////////GLOBAL VARIABLES//////////
char dcst[20],arr[20],type[20],airliner[40],hotelier[40];
int dur,budget,ch,/*choice of hotel  */ac/*choice of plane */;
int day,month,year;
int cid;
int acode,dcode,hc,people;
////////////////GLOABAL FUNCTIONS///////
load(char[]);
void admin();
///////////////////////////////////////FLIGHT///////////////////////////////////////////

class flight
{
    int flight_no;
    char from[20];//source of flight
    char to[20];//destination of flight
    int depttime,arrtime;
    int code1,code2;
    char airline[20];
    float fare;


    public:
    void add();        //to add a flight
    void display1();    //to display the Flight record
    void seats();    //to display alloted seats
    int price()  // to return the tariff
    {return fare;}
    int rcode1()
    {return code1;}
    int rcode2()
    {return code2;}
    void edit();    //to edit the Hotel record
    void modify(int);    //to modify the record
    void delete_rec(int);   //to delete the record
    void flightdisp(); //display for customer
    int retan() // to return the hotel code
    { return flight_no;}
   /* char retad()
    { return address[30];} */
}ft;//object
fstream f,fout;

void flight::add()
{

    int r;
    char ch;
    f.open("Flight.dat",ios::binary|ios::app);
    do{
    cout<<"\n Enter Flight Details";
    cout<<"\n **********************";
    cout<<"\n\n Flight no: ";
    cin>>r;
    flight_no=r;
    cout<<" \nAirline: ";
    gets(airline);
    cout<<" \nDeparture city: ";
    gets(from);
    if(strcmp(from,"Kolkata")==0)
    code1=1;
    else
    code1=0;
    cout<<" \nArrival city: ";
    gets(to);
    if(strcmp(to,"Delhi")==0)
    code2=2;
    else if(strcmp(to,"Mumbai")==0)
    code2=3;
    else if(strcmp(to,"Dubai")==0)
    code2=4;
    else if(strcmp(to,"Singapore")==0)
    code2=5;
    else
    code2=0;
    cout<<" \nAirfare: ";
    cin>>fare;
    cout<<" \nDeparture time: ";
    cin>>depttime;
    cout<<" \nArrival time: ";
    cin>>arrtime;
    f.write((char*)&ft,sizeof(ft));
    cout<<"\n Flight added!!!";
    cout<<"\nWant to enter more records?";
    cin>>ch;
    }while(ch=='y'||ch=='Y');
    f.close();
}
void flight::flightdisp()
{
	f.open("Flight.dat",ios::binary|ios::in);
	while(f.read((char*)&ft,sizeof(ft)))
	{
	    cout<<"\n Flight Details";
	    cout<<"\n ****************";
	    cout<<"\n\n Flight no: "<<flight_no;
	    cout<<"\n Airline: "<<airline;
	    cout<<"\n Departure city: "<<from;
	    cout<<"\n Arrival city: "<<to;
	    cout<<"\n Departure time: "<<depttime;
	    cout<<"\n Arrival time: "<<arrtime;
	    cout<<"\n Airfare :"<<fare;

	}
	f.close();
}
void flight::display1()
{

    f.open("Flight.dat",ios::binary|ios::in);
    int r;
    cout<<"\n Enter Flight no: ";
    cin>>r;
     int q=0;
    while(f.read((char*)&ft,sizeof(ft)))
	{
	    if(flight_no==r)
	       {
		cout<<"\n Flight Details";
		cout<<"\n ****************";
		cout<<"\n\n Flight no: "<<flight_no;
		cout<<"\n Airlines: "<<airline;
		cout<<"\n Departure city: "<<from;
		cout<<"\n Arrival city: "<<to;
		q++;
		break;
	       }
    }
    if(q==0)
    cout<<"Flight not found "<<endl;
     cout<<"\n Press any key to continue!!!";
    getch();
    f.close();
}
void flight::edit()
{

    int choice,r;

    cout<<"\n EDIT MENU";
    cout<<"\n *********";
    cout<<"\n\n 1.Modify Flight Record";
    cout<<"\n 2.Delete Flight Record";

    cout<<"\n Enter your choice: ";
    cin>>choice;


    cout<<"\n Enter Flight no: ";
    cin>>r;

    switch(choice)
    {
	case 1: modify(r);
		break;
	case 2: delete_rec(r);
		break;
	default: cout<<"\n Wrong Choice!!";
    }

    cout<<"\n Press any key to continue!!!";
    getch();
}


void flight::modify(int r)
{
    long pos,flag=0;
    fstream file("flight.dat",ios::in|ios::out|ios::binary);


	while(file.read((char*)&ft,sizeof(ft)))
	{
	 pos=file.tellg();
	 if(flight_no==r)
	  {
	    cout<<"\n Enter New Details";
	    cout<<"\n *****************";
	    cout<<"\n Airline: ";
	    gets(airline);
	    cout<<" \nDeparture city: ";
	    gets(from);
	    cout<<" /nArrival city: ";
	    gets(to);
	    if(strcmp(to,"Delhi")==0)
	    code2=2;
	    else if(strcmp(to,"Mumbai")==0)
	    code2=3;
	    else if(strcmp(to,"Dubai")==0)
	    code2=4;
	    else if(strcmp(to,"Singapore")==0)
	    code2=5;
	    else
	    code2=0;
	    cout<<" /nDepatrture time: ";
	    cin>>depttime;
	    cout<<" \nArrival time: ";
	    cin>>arrtime;
	    cout<<" \nAirfare: ";
	    cin>>fare;
	    file.seekg(pos);
	    file.write((char*)&ft,sizeof(ft));
	    cout<<"\n Record is modified!!";
	    flag=1;
	    break;
	}
    }

    if(flag==0)
	cout<<"\n Sorry Flight no. not found!!";
    file.close();
}

void flight::delete_rec(int r)
{
    int flag=0;
    char ch;
    f.open("flight.dat",ios::binary|ios::in);
    fout.open("temp1.dat",ios::binary|ios::out);

    while(f.read((char*)&ft,sizeof(ft)))
    {
	if(flight_no==r)
	{
	    cout<<"\n Airline: "<<airline;
	    cout<<"\n Departure city: "<<from;
	    cout<<"\n Arrival city: "<<to;
	    cout<<"\n\n Do you want to delete this record(y/n): ";
	    cin>>ch;

	    if(ch=='n')
	    f.write((char*)&ft,sizeof(ft));

	    flag=1;
	}
	else
	    f.write((char*)&ft,sizeof(ft));
    }

    f.close();
    fout.close();

    if(flag==0)
	cout<<"\n Sorry Flight no. not found!!";
    else
    {
	remove("flight.dat");
	rename("temp1.dat","flight.dat");
    }
}
void flight_menu()
{
    int choice;

    while(choice!=4)
    {
	system("cls");
	cout<<"\n\t\t\t\t*************";
	cout<<"\n\t\t\t\t* MAIN MENU *";
	cout<<"\n\t\t\t\t*************";
	cout<<"\n\n\n\t\t\t1.Add a Flight";
	cout<<"\n\t\t\t2.Specific Flights Record";
	cout<<"\n\t\t\t3.Display records ";
	cout<<"\n\t\t\t4.Edit Record";
	cout<<"\n\t\t\t5.Exit";
	cout<<"\n\n\t\t\tEnter Your Choice: ";
	cin>>choice;
	switch(choice)
	{
	    case 1: ft.add();
		    break;
	    case 2: ft.display1();
		    break;
	    case 3: ft.flightdisp();
		    getch();
		    break;
	    case 4: ft.edit();
		    break;
	    case 5: admin();
		    break;
	}
    }
}
////////////////////////////FLIGHT END/////////////////////////////////////////////////
/////////////////////////////HOTEL////////////////////////////////////////////////
class hotel
{
    int Hotel_no;
    int room_no;
    char name[30];
    char address[30];
    long int phone ;
    float tariff;
    int hcode;

    public:
    void add();        //to book a Hotel
    void display();    //to display the Hotel record
    int rtariff()  // to return the tariff
    {return tariff;}
    void edit();    //to edit the Hotel record
    void modify(int);    //to modify the record
    void delete_rec(int);   //to delete the record
    void hoteldisp(); //display for customer
    int rethn() // to return the hotel code
    { return Hotel_no;}
    int rhcode()
     {return hcode;}
}h;
fstream f1,fout1;

void hotel::add()
{

    int r;
    char ch;
    f1.open("Record.dat",ios::binary|ios::app);
    do{
    cout<<"\n Enter Hotel Details";
    cout<<"\n **********************";
    cout<<"\n\n Hotel no: ";
    cin>>r;
    Hotel_no=r;
    cout<<" Name: ";
    gets(name);
    cout<<" Address: ";
    gets(address);
    if(strcmp(address,"Kolkata")==0)
    hcode=1;
    else if(strcmp(address,"Delhi")==0)
    hcode=2;
    else if(strcmp(address,"Mumbai")==0)
    hcode=3;
    else if(strcmp(address,"Dubai")==0)
    hcode=4;
    else if(strcmp(address,"Singapore")==0)
    hcode=5;
    else
    hcode=0;
    cout<<" Phone No: ";
    cin>>phone;
    cout<<"Tariff: ";
    cin>>tariff;
    f1.write((char*)this,sizeof(hotel));
    cout<<"\n Hotel added!!!";
    cout<<"\nWant to enter more records?";
    cin>>ch;
    }while(ch=='y'||ch=='Y');
    f1.close();
}
void hotel::hoteldisp()
{
	f1.open("Record.dat",ios::binary|ios::in);
	while(f1.read((char*)&h,sizeof(h))){
	    cout<<"\n Hotel Details";
	    cout<<"\n ****************";
	    cout<<"\n\n Hotel no: "<<Hotel_no;
	    cout<<"\n Name: "<<name;
	    cout<<"\n Address: "<<address;
	    cout<<"\n Phone no: "<<phone;
	}
	f1.close();
}
void hotel::display()
{

    f1.open("Record.dat",ios::binary|ios::in);
    int r;
    cout<<"\n Enter Hotel no: ";
    cin>>r;
     int q=0;
    while(f1.read((char*)&h,sizeof(h)))
	{
	    if(Hotel_no==r)
	       {
		cout<<"\n Hotel Details";
		cout<<"\n ****************";
		cout<<"\n\n Hotel no: "<<Hotel_no;
		cout<<"\n Name: "<<name;
		cout<<"\n Address: "<<address;
		cout<<"\n Phone no: "<<phone;
		q++;
			       }

    }
    if(q==0)
    cout<<"Hotel not found "<<endl;
     cout<<"\n Press any key to continue!!!";
    getch();
    f1.close();
}
void hotel::edit()
{

    int choice,r;
    cout<<"\n EDIT MENU";
    cout<<"\n *********";
    cout<<"\n\n 1.Modify Hotel Record";
    cout<<"\n 2.Delete Hotel Record";
    cout<<"\n Enter your choice: ";
    cin>>choice;
    cout<<"\n Enter Hotel no: ";
    cin>>r;
    switch(choice)
    {
	case 1: modify(r);
		break;
	case 2: delete_rec(r);
		break;
	default: cout<<"\n Wrong Choice!!";
    }

    cout<<"\n Press any key to continue!!!";
    getch();
}


void hotel::modify(int r)
{
    long pos,flag=0;
    fstream file("Record.dat",ios::in|ios::out|ios::binary);


	while(file.read((char*)this,sizeof(hotel)))
	{
	 pos=file.tellg();
	 if(Hotel_no==r)
	  {
	    cout<<"\n Enter New Details";
	    cout<<"\n *****************";
	    cout<<"\n Name: ";
	    gets(name);
	    cout<<" Address: ";
	    gets(address);
	     if(strcmp(address,"Kolkata")==0)
    hcode=1;
    else if(strcmp(address,"Delhi")==0)
    hcode=2;
    else if(strcmp(address,"Mumbai")==0)
    hcode=3;
    else if(strcmp(address,"Dubai")==0)
    hcode=4;
    else if(strcmp(address,"Singapore")==0)
    hcode=5;
    else
    hcode=0;
	    cout<<" Phone no: ";
	    cin>>phone;
	    file.seekg(pos);
	    file.write((char*)this,sizeof(hotel));
	    cout<<"\n Record is modified!!";
	    flag=1;
	    break;
	}
    }

    if(flag==0)
	cout<<"\n Sorry Hotel no. not found!!";
    file.close();
}

void hotel::delete_rec(int r)
{
    int flag=0;
    char ch;
    f1.open("Record.dat",ios::binary|ios::in);
    fout1.open("temp.dat",ios::binary|ios::out);

    while(f1.read((char*)this,sizeof(hotel)))
    {
	if(Hotel_no==r)
	{
	    cout<<"\n Name: "<<name;
	    cout<<"\n Address: "<<address;
	    cout<<"\n Phone No: "<<phone;
	    cout<<"\n\n Do you want to delete this record(y/n): ";
	    cin>>ch;

	    if(ch=='n')
	    f1.write((char*)this,sizeof(hotel));

	    flag=1;
	}
	else
	    f1.write((char*)this,sizeof(hotel));
    }

    f1.close();
    fout1.close();

    if(flag==0)
	cout<<"\n Sorry Hotel no. not found!!";
    else
    {
	remove("Record.dat");
	rename("temp.dat","Record.dat");
    }
}
void hotel_menu()
{
    int choice;

    while(choice!=4)
    {
	system("cls");
	cout<<"\n\t\t\t\t*************";
	cout<<"\n\t\t\t\t* MAIN MENU *";
	cout<<"\n\t\t\t\t*************";
	cout<<"\n\n\n\t\t\t1.Add a Hotel";
	cout<<"\n\t\t\t2.Specific Hotel Record";
	cout<<"\n\t\t\t3.Display records ";
	cout<<"\n\t\t\t4.Edit Record";
	cout<<"\n\t\t\t5.Exit";
	cout<<"\n\n\t\t\tEnter Your Choice: ";
	cin>>choice;
	switch(choice)
	{
	    case 1: h.add();
		    break;
	    case 2: h.display();
		    break;
	    case 3: h.hoteldisp();
		    getch();
		    break;
	    case 4: h.edit();
		    break;
	    case 5: admin();
		    break;
	}
    }
}
/////////////////////////////////HOTEL END/////////////////////////////////
/////////////////////////////////PERSONAL DETAILS////////////////////////
class persdetails
{
  int trvlcode;
  int  age;
  char name[20];
  char add[20];
  long  phnum;
  char sex;
  char passnum[20];
  char familyname[20];
  int num;
  int numppl;
  public:
  void p_input(int);
  void p_output();
  void givefam();
  int givecode();
  int give();
}pob;//object of pers details
int persdetails::give()
{
  return num;
}
void persdetails::givefam()
{
  cout<<familyname;
}
int persdetails::givecode()
{
  return trvlcode;
}

//pers details is another class

void persdetails::p_input(int cd)
{
  trvlcode=cd;
  num=0;
  clrscr();
  cout<<"\n\n\t:::::::::::::::::::::: PERSONAL DETAILS ::::::::::::::::::::::\n";
  cout<<"\t\t\t\t~~~~~~~~~~~~~~\n";
  cout<<"\n\t\t* Please fill in the details:\n\n\n\t\t\t1.Family Name: ";
  gets(familyname);
  cout<<"\n\t\t\t2.Address: ";
  gets(add);
  cout<<"\n\t\t\t3.Contact Number(10 Digit Mobile Number) : ";
  cin>>phnum;
/*  if(phnum>999999999&&phnum<1000000000)
  continue;
  else
  cout<<"Input correct number"<<endl; */
  cout<<"\n\n\n\t\tEnter The No of People Travelling: ";
  cin>>numppl;
  clrscr();
  if(numppl>0)
  {
    cout<<"\n\t\tPlease Enter The Details of each Member/Members: "<<endl;
    cout<<"\t\t \n";
    int i=0;
    while(i!=numppl)
    {
      cout<<endl<<"\n\t\tMember "<<i+1;
      cout<<"\n\t\t~~~~~~~~";
      cout<<"\n\n\t\tFirst Name: ";
      gets(name);
      cout<<"\n\t\tAge: ";
      cin>>age;
      cout<<"\n\t\tSex (M/F): ";
      cin>>sex;
      cout<<"\n\t\tPassport Number: ";
      gets(passnum);
      if(age>5)
      {
	num++;    //to calculate no of travellers below 5 yrs
      }
      i++;
    }
  }
  ::people=num;
	cout<<"Press any key to continue!";
	    getch();

}
void persdetails::p_output() //output func() of class1
{
  clrscr();
  cout<<"\n\n\t ******************** PERSONAL DETAILS ******************** "<<endl;
  cout<<"\n\n\t\t\tFamily Name:\t "<<familyname<<endl;
  cout<<"\t\t\tAddress:\t "<<add<<endl;
  cout<<"\t\t\tPhone Number:\t "<<phnum<<endl;
  cout<<"\n\n\tName\t\tAge\t\tSex\t\tPassport Number\n"<<endl;
  for(int i=0;i<numppl;i++)
  {
    cout<<"\t"<<name<<"\t\t"<<age<<"\t\t"<<sex<<"\t\t"<<passnum<<endl;
  }
  getch();
};
////////////////////////////////////////PERSONALDET END///////////////////
//////////////////////////////QUESTIONS//////////////////////////////
persdetails pd;
void getans()
	{
	    a:
	    clrscr();
	    int domesticchoice,internationalchoice,departurechoice;
	    cout<<"\n\t\t\t\t**********************";
	    cout<<"\n\t\t\t\t* BOOK YOUR TRIP *";
	    cout<<"\n\t\t\t\t**********************";
	    cout<<"\n\nSelect from our available departure cities";
	    cout<<"\n\t\t1.Kolkata";//code=1
	    cout<<"\n\t\t2.Delhi";   //code=2
	    cout<<"\n\t\t3.Mumbai";  //code=3
	    cout<<"\nEnter your choice:";
	    cin>>departurechoice;
	    if(departurechoice==1)
	    {
		     strcpy(dcst,"Kolkata");
		     ::dcode=1;

	    }
	    else if(departurechoice==2)
	    {
	     strcpy(dcst,"Delhi");
		     ::dcode=2;

		     }
	     else if(departurechoice==3)
	     {
	      strcpy(dcst,"Mumbai");
		     ::dcode=3;

	     }
	    else{
	    cout<<"Enter correct code";
	    delay(2);
	    goto a;
	    }
	    cout<<"\n1.Type of travel -->1.Domestic 2.International";
	    cout<<"\nEnter your choice:";
	    cin>>ch;
	    if(ch==1)
	    {
	    strcpy(type,"Domestic");
	    cout<<"Select from our available destinations:"<<endl;
	    cout<<"1.Delhi"<<endl;   //code=2
	    cout<<"2.Mumbai"<<endl;  //code=3
	    cin>>domesticchoice;
	     switch(domesticchoice)
	      {
	      case 1: strcpy(arr,"Delhi");
		     ::acode=2;
		      break;
	      case 2: strcpy(arr,"Mumbai");
		     ::acode=3;
		      break;
	      }
	    }
	    else if(ch==2)
	     {
		    strcpy(type,"International");
		    cout<<"Select from our avaiable destinations:"<<endl;
		    cout<<"1.Dubai "<<endl; //code=4
		    cout<<"2.Singapore"<<endl; //code=5
		    cin>>internationalchoice;
		     switch(internationalchoice)
		      {
		      case 1: strcpy(arr,"Dubai");
			     ::acode=4;
			      break;
		      case 2: strcpy(arr,"Singapore");
			     ::acode=5;
			      break;

		      }


	     }
	    else {cout<<"Invalid choice!";
	    goto a; }
	    cout<<"\n4.Duration of the trip(Number of days) -->";
	    cin>>dur;
	    cout<<"\n5.Choose airline"<<endl;
	    cout<<"1.Emirates"<<endl;
	    cout<<"2.JetAirways"<<endl;
	    cout<<"3. Lufthansa"<<endl;
	    cin>>ac;
	     switch(ac)
	       {
	       case 1: strcpy(airliner,"Emirates");
		       break;
	       case 2: strcpy(airliner,"JetAirways");
		       break;
	       case 3: strcpy(airliner,"Luthansa");
		       break;
	       }
	    cout<<"\n5.Choose Hotel"<<endl;
	    cout<<"1.Premium"<<endl;
	    cout<<"2.Deluxe"<<endl;
	    cout<<"3.Standard"<<endl;
	    cin>>::hc;
	     switch(::hc)
	       {
	       case 1: strcpy(hotelier,"Premium");
		       break;
	       case 2: strcpy(hotelier,"Deluxe");
		       break;
	       case 3: strcpy(hotelier,"Standard");
		       break;
	       }
	    cout<<"Enter the travel date (Day/Month/Year)"<<endl;
	    cin>>day;
	    cin>>month;
	    cin>>year;
	    cout<<"\n\5.Budget of travel(>10000) -->";
	    cin>>::budget;

}
int callq(){
     getans();
     cout<<"Press any key to continue!";
     getch();
     clrscr();
    srand(time(NULL));
    ::cid=rand()%9000+1000;
    pd.p_input(::cid);
    return 0;
}
/////////////////////////////QUESTIONS END////////////////////////////////
//////////////////////////////BILLING//////////////////////////////////
void billing()   //compution+bill generation
{
  fstream f2,f3;
  int fn;
  int hn;
  long float gttl=0;
  char discount[10];
  cleardevice();
  cout<<"\n\nContinue to choose your flight"<<endl;
 f2.open("flight.dat",ios::binary||ios::in);


 while(f2.read((char*)&ft,sizeof(ft)))
  { ft.rcode1();
  ft.rcode2();
	if(::dcode==ft.rcode1()&&::acode==ft.rcode2())
	{ ft.flightdisp();}
  }
  f2.close();

   cout<<"\nEnter flight number of your choice: "  ;
  cin>>fn;

  f3.open("Record.dat",ios::binary||ios::in);
     while(f3.read((char*)&h,sizeof(h)))
	{
	if(::acode==h.rhcode())
	   { h.hoteldisp();}
	}
       f3.close();
  cout<<"Enter hotel number of your choice: "  ;
  cin>>hn;
  cleardevice();
  load("GENERATING YOUR BILL");
  clrscr();
  cout<<"\n\n\t\t:::::::::::::::::::::: BILL ::::::::::::::::::::::::::";
  cout<<"\n\n\t\tCustomer ID:\t\t "<<::cid;
  cout<<"\n\n\t\tBoarding point:\t\t ";
  puts(dcst);
  cout<<"\n\n\t\tDestination:\t\t ";
  puts(arr);
  cout<<"\n\n\t\tDate of Departure: ";
  cout<<day<<"/"<<month<<"/"<<year;
  int arrday,arrmonth,arryear;
  arrday=day+dur;
  arrmonth=month;
  arryear=year;
 if(arrmonth==1||arrmonth==3||arrmonth==5||arrmonth==7||arrmonth==8||arrmonth==10||arrmonth==12)
  {
    if(arrday>31)
    {
      arrmonth=arrmonth+1;
      arrday=arrday%31;
    }
  }
  if(arrmonth==4||arrmonth==6||arrmonth==9||arrmonth==11)
  {
    if(arrday>30)
    {
      arrmonth=arrmonth+1;
     arrday=arrday%30;
    }
  }
  if(arrmonth==2)
  {
    if(arrday>28)
    {
      arrmonth=arrmonth+1;
      arrday=arrday%28;
    }
  }
  if(arrmonth==13)
  {
    arrmonth=1;
    arryear++;
  }
  cout<<"\n\n\t\tDate of Arrival: ";
  cout<<arrday<<"/"<<arrmonth<<"/"<<arryear;

  fstream f5,f6;
  f5.open("flight.dat",ios::binary||ios::in);
  while(f5.read((char*)&ft,sizeof(ft)))
  {
   if(ft.retan()==fn)
    {
     cout<<"\n\t\tAirline\t\t";
     puts(airliner);
     cout<<"\nThe airfare is:"<<ft.price();
     gttl=gttl+ft.price();
    }
  }
  f5.close();
 f6.open("Record.dat",ios::binary||ios::in);
while(f6.read((char*)&h,sizeof(h)))
 {

 if(h.rethn()==hn)
  {
   cout<<"\n\t\tHotel\t\t";
   puts(hotelier);
   cout<<"The Room tariff is "<<h.rtariff();
   gttl=gttl+(h.rtariff()*dur);
   }
  }
  f6.close();
 switch(::hc)
  {
  case 1:gttl=gttl+5000;
	 break;
  case 2:gttl=gttl+2000;
	 break;
  case 3:gttl=gttl+0;
	 break;
  default:gttl=gttl+0;
	   break;

  }

  cout<<"\n\nDo you have discount code?(Y/N)"<<endl;
  char z;
  cin>>z;
  if(z=='y'||z=='Y')
     { cout<<"Enter the code"<<endl;
       gets(discount);
	if(strcmp(discount,"abcde")==0)
	 { cout<<"5% discount applied "<<gttl*.05;
	   gttl=gttl*(.95);
	 }
     }
  else
  gttl=gttl+0;
  cout<<"\n\n\n\t\t\t  Grand Total:Rs ";
  cout<<gttl*::people;
  if(::budget<gttl){
	cout<<"\n\n\t\t\tBudget Exceeded!";
  }
  cout<<"\n\n\t ! All Travellers below the age of 5 have not been charged ! ";
  getch();
}
////////////////////////BILLING END////////////////////////////////////////////////
///////////////////////////LOGIN////////////////////////////////////////////////////
int login()
{
    start:
    cleardevice();
    char u[20],p[20];
    rectangle(250,30,387,48);
    rectangle(275,143,398,160);
    rectangle(275,175,398,192);
    gotoxy(39,3);
    cout<<"Login";
    gotoxy(25,10);
    cout<<"Username:";
    gotoxy(25,12);
    cout<<"Password:";
    gotoxy(51,10);
    cout<<"(Press enter after entering)";
    gotoxy(51,12);
    cout<<"(9 characters only)";
    gotoxy(36,10);
    gets(u);
    gotoxy(36,12);
   for(int i=0;i<9;++i)
		{
		p[i]=getch();
		if(p[i]=='\b')
		{
		printf("\b \b");
		i=i-2;
		}
		else
		cout<<"*";
		}
		p[i]=' ';
		getch();
	char un[]="user", up[]="123456789", an[]="admin", ap[]="letmepass";
	for(int l=0; l<9; ++l){
	if (u[l]==un[l]&&p[l]==up[l]){
		gotoxy(20,20);
		cout<<"Please wait Redirecting";
		for(int j=0;j<5;++j)
		{
		sleep(1);
		cout<<".";
		}
	    cleardevice();
	    callq();
	    cleardevice();
	   load("LOADING YOUR OPTIONS");
	    cleardevice();
	    billing();
	    return 0;

}
else if (u[l]==an[l]&&p[l]==ap[l]){
gotoxy(20,20);
cout<<"Please wait Redirecting";
for(int j=0;j<5;++j)
{
sleep(1);
cout<<".";
}
	cleardevice();
	admin();
	return 0;
}
else
{
 gotoxy(40,20);
 cout << "\nLogin failed";
    sleep(3);
    clrscr();
    goto start;}
}//end of for

 return 0;
}
////////////////////////////////LOGIN END////////////////////////////////////
///////////////////////////////ADMIN ///////////////////////////////////////
void admin()
{
    int choice;
    clrscr();
    while(choice!=4)
    {

	cout<<"\n\t\t\t\t**********************";
	cout<<"\n\t\t\t\t* ADMINISTRATOR MENU *";
	cout<<"\n\t\t\t\t**********************";
	cout<<"\n\n\n\t\t\t1.Hotels Menu";
	cout<<"\n\t\t\t2.Flights Menu";
	cout<<"\n\t\t\t3.Exit";
	cout<<"\n\n\t\t\tEnter Your Choice: ";
	cin>>choice;
	switch(choice)
	{
	    case 1: clrscr();
		    hotel_menu();
		    break;
	    case 2:clrscr();
		    flight_menu();
		    break;
	    case 3: exit(0);
		    break;
	}
    }

	getch();
 }
/////////////////////////////ADMIN END//////////////////////////////////////
///////////////////////////////WELCOME//////////////////////////////////////
int welcome()
{
	cleardevice();
	char *str1,*str2,ch;
      int i,j,location,n,flag=0,c=10;
      strcpy(str1,"           SMART TRAVEL          ");
       for(i=0;!kbhit();){
	cleardevice();
	 setfillstyle(SOLID_FILL,BLACK);
	 bar(50,50,600,90);
       while(c!=14){

	 c++;
       setcolor(c);
       }
       //////
       settextstyle(TRIPLEX_FONT,HORIZ_DIR,4);
       outtextxy(50,50,str1);
       delay(350);
       ch = str1[0];
       //////substring logic
       n=strlen(str1);
       location=0;
       for(j=location;j<n;j++){
	 str1[j] = str1[j+1];
       }///appending char at end
       str1[n-1]=ch;
       str1[n]=NULL;
      }
      getch();
      strcpy(str2,"Made  by: Aditya & Sanjay");
      for(i=0;!kbhit();){
       /********For Clearing Part of Screen by Drawing Lines*/
	 setfillstyle(SOLID_FILL,BLACK);
	 bar(50,200,600,240);
       settextstyle(SMALL_FONT,HORIZ_DIR,6);
       if(flag==0){
	   i++;
	   if(i==200)  flag=1;  //Extreme Right
       }
       else{
	  i--;
	  if(i==0) flag=0;   //Extreme Left
	}
       outtextxy(50+i,200,str2);
       delay(5);
      }

    gotoxy(20,20);
    cout<<"Press any key to continue!!";
    getch();
    cleardevice();
    login();
    return 0;
}
///////////////////WELCOME END/////////////////////////////////
///////////////////LOADING////////////////////
load(char message[])
{
int x=170,i;
settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
outtextxy(170,180,message);

for( i=0;i<300;++i)
{
delay(15);
line(x,200,x,220);
x++;
}
return 0;
}
/////////////////////LOADING END///////////////////
///////////////////MAIN////////////////////////////
void main(){
    int gdriver=DETECT,gmode;
    initgraph(&gdriver,&gmode,"c:\\tc\\bgi");
    setcolor(YELLOW);
    setbkcolor(BLUE);
    load("LOADING,PLEASE WAIT");
    clrscr();
    welcome();
    clrscr();
    getch();
    closegraph();
}

//////////////////END OF CODE///////////////