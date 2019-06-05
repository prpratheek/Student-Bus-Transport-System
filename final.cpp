#include<fstream>
#include<iomanip>
#include<windows.h>
#include<conio.h>
#include <ctype.h>
#include<stdlib.h>
#include<iostream>
#include<cstring>
#include<stdio.h>
using namespace std;
void WaitKey();
void gotoXY(int x, int y); 
HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;
static int a;  
static int z;
string user1,user2,user3;      
class staff_login;
class student_login;
class register_now
{
	string name[10];
	public:
		int notice();
		int instructionsform();
		int registration_form();
		int confirmform();
		friend student_login;
		friend staff_login;
};
class student_login 
{

	public:
		string ID,NA,FN,PH,AD,BN,FE,Buf;
		char buf[100];
		int login();
		void modify_details();
		int allotmentform();
		int contactdetails();
		int complaints();
		void pack();
		void unpack();
		void read(fstream &);
		void write(fstream &);
		friend register_now;
};
class staff_login 
{
	public:
		int login();
		int complaintbox();
		int notice();
};
int staff_login::login()
{
	register_now r1;
	staff_login s1;
	student_login s2;

	int u;
	string a[100],user11,user12,user13;
	char line[80];
	system("cls");
	cout<<"\n\n\n\n\n\n\n\n\n                  STAFF LOGIN";
	cout<<"\n\n                  USERNAME:";
	cin>>user11;
	int i=0;
	char pwd[5];
	cout<<"                  PASSWORD:";
	while(i<6)	
	{
		pwd[i]=getch();
		if(pwd[i]!='\r')
			putchar('*');
		if(pwd[i]=='\b')
		{
			cout<<"\b\b  \b\b";
			i--;
			i--;
		}
		if(pwd[i]=='\r')
			pwd[i--];
		++i;
	}
	int j=0;
	user12=pwd;
	user13=user11+user12;
	ifstream fil5;
	fil5.open("login.txt",ios::out);
	while(fil5)
	{
		fil5.getline(line,80);
		a[j]=line;
		j++;
	}
	for(int k=0;k<50;k++)
	{
		if(a[k]==user13)
		{
			while(1)
			{
				system("cls");
				cout<<"\n\n WELCOME TO "<<user11;
				cout<<"\n\n\n\n\n\n                     1.Complaint Box"<<"\n                     2.Edit Updates";
				cout<<"\n                     3.Logout";
				cout<<"\n\n\n Select your option";
				cin>>u;
				switch(u)
				{
					case 1:system("COLOR 5F");
							s1.complaintbox();
							break;
					case 2:system("COLOR 5F");
							s1.notice();
							break;
					case 3:system("COLOR 5F");
							system("cls");
							cout<<"\n\n\n\n\n\n\n           LOADING PLEASE WAIT ... ";
							Sleep(500);
							return 0;
				default:return 0;
			}
		}
	}
}
	system("cls");
		cout<<"\n\n\n      SORRY,"
			<<"\n      invalid username or password";
		Sleep(300);
	return 1;
}
int staff_login::notice()
{
	system("cls");
	fstream fin;
	fin.open("program.txt",ios::out | ios::app );
	fin<<endl;
	string mystr;
   	getline (cin, mystr);
  	cout << "Enter the Update : ";
  	getline (cin, mystr);
  	fin<<mystr;
  	cout<<"\n\n\n\nEnter any key to return main menu :";
  	getch();
  	return 1;
}

int staff_login::complaintbox()
{
	char ch;
	system("cls");
	ifstream fin6;
	fin6.open("complaintbox.txt",ios::in);
	while(fin6)
	{
		fin6.get(ch);
		cout<<ch;
	} 
	cout<<"\n\n\n\n\n\n   Enter the any key to return to main menu";
	getch();
	return 1;
}
int student_login::login()
{
	register_now r1;
	staff_login s1;
	student_login s2;

	int u;
	string a[100];
	char line[80];
	system("cls");
	cout<<"\n\n\n\n\n\n\n\n\n                  STUDENT LOGIN";
	cout<<"\n\n                  USERNAME:";
	cin>>user1;
	int i=0;char ch;
	char pwd[5];
	cout<<"                  PASSWORD:";
	while(i<6)	
	{
		pwd[i]=getch();
		if(pwd[i]!='\r')
			putchar('*');
		if(pwd[i]=='\b')
		{
			cout<<"\b\b  \b\b";
			i--;
			i--;
		}
		if(pwd[i]=='\r')
			pwd[i--];
		++i;
	}
	int j=0;
	user2=pwd;
	user3=user1+user2;
	ifstream fil5;
	fil5.open("login.txt",ios::out);
	while(fil5)
	{
		fil5.getline(line,80);
		a[j]=line;
		j++;
	}
		for(int k=0;k<50;k++)
		{
		if(a[k]==user3)
		{
		while(1)
		{
			system("cls");
			cout<<"\n\n WELCOME TO "<<user1;
			cout<<"\n\n\n\n\n                  1.Allotment form";
			cout<<"\n                  2.Complaint"<<"\n                  3.Staff contact details";
			cout<<"\n                  4.To modify detials";
			cout<<"\n                  5.Logout";
			cout<<"\n\n\n\n\n\n Select your option";
			cin>>u;
			switch(u)
				{
				case 1:s2.allotmentform();
						break;
				case 2:s2.complaints();
						break;
				case 3:s2.contactdetails();
						break;
				case 4:s2.modify_details();
						break;
				case 5:system("cls");
						cout<<"\n\n\n\n\n\n\n            PLEASE WAIT ... LOADING";
						Sleep(500);
						return 0;
				default:exit;
				}
			}
    	}
    }
		system("cls");
		cout<<"\n\n\n      SORRY,"
			<<"\n      invalid username and password";
		Sleep(500);
	return 1;
}

void student_login::unpack()
{
	char stg[100];
	int pos=0,cnt=0,k,i;
	while(cnt<7)
	{
		k=0;
		for(i=pos;i<strlen(buf);i++,k++)
		{
			stg[k]=buf[i];
			pos++;
			if(buf[i]=='|')
				break;
		}
		stg[k]='\0';
		cnt++;
		if(cnt==1)
		{
			ID=stg;
		}
		if(cnt==2)
		{
			NA=stg;
		}
		if(cnt==3)
		{
			FN=stg;	
		}
		if(cnt==4)
		{
			PH=stg;
		}
		if(cnt==5)
		{
			AD=stg;
		}
		if(cnt==6)
		{
			BN=stg;
		}	
		if(cnt==7)
		{
			FE=stg;
		}
	}
}

void student_login::pack()
{
	Buf=ID+"|"+NA+"|"+FN+"|"+PH+"|"+AD+"|"+BN+"|"+FE;
}

void student_login::read(fstream &fp)
{
	fp.getline(buf,100,'\n');
}

void student_login::write(fstream &fp)
{
	fp.flush();
	fp<<Buf<<"\n";
	fp.flush();
}

int student_login::allotmentform()
{
	system("cls");
	string j,tem[10];
	int i,d,cnt;
	student_login st[100];
	//cout<<"Enter your Username :";
	//cin>>j;
	fstream f8;
	f8.open("list_of_students.txt",ios::in);
	while(f8)
    {
		st[i].read (f8);
		st[i].unpack();   	
        i++;
	}
	f8.close();
	cnt=i-1;
	for(i=0;i<cnt;i++)
	{
		if(st[i].ID==user3)
		{
				system("cls");
				cout.setf(ios::left,ios::adjustfield);
				cout<<endl<<endl<<endl<<" NAME :"<<st[i].NA;
				cout<<endl<<endl<<endl<<" FATHER NAME :"<<st[i].FN;
				cout<<endl<<endl<<endl<<" Ph_no:"<<st[i].PH;
				cout<<endl<<endl<<endl<<" ADDRESS:"<<st[i].AD;
				cout<<endl<<endl<<" Alloted Bus Number:"<<st[i].AD;
				cout<<endl<<endl<<endl<<"\n            Total amount DUE : Rs "<<st[i].FE<<"|-"<<endl<<endl;
//	<<"                                                             student sign";
   				cout<<"Enter any key to retun back to menu :";

		}
		
	}
	getch();
	return 1;
}
int student_login::complaints()
{
	char ch;
	system("cls");
	ofstream fin9;
	fin9.open("complaintbox.txt",ios::app);
	fin9<<endl;
	string mystr;
   	getline (cin, mystr);
  	cout << "Enter the Complaint :";
  	getline (cin, mystr);
  	fin9<<mystr;
  	cout<<"\n\n\nEnter any key to retun back to menu :";
	getch();
	return 1;
}
int student_login::contactdetails()
{
	system("cls");
	cout<<"\n\n\n   Dr. B.Sreenivasa Reddy,\n   Transport Officer,\n   Dept. of Transportation,"
	<<"\n   Room no:K-201,"<<"\n   MVIT,Bangalore,Karnataka";
	cout<<"\n   Phone no: 9832333393";
	cout<<"\n\n\n\nEnter any key to retun back to menu :";
	getch();
	return 1;
}
void student_login::modify_details()
{
	system("cls");
	student_login st[100];
	string user10;
	int i,cnt,ch;
	int flag=1;
	fstream f;
	f.open("list_of_students.txt",ios::in);
	//f8.seekg(0,ios::beg);
	i=0;
	while(f)
    {
		st[i].read (f);
		st[i].unpack();   	
        i++;
	}
	f.close();
	cnt=i-1;
	for(i=0;i<cnt;i++)
	{
		if(st[i].ID==user3)
		{
			do
			{
				cout<<"\n\nEnter the field you wish to change";
				cout<<"\n1.NAME :"<<st[i].NA;
				cout<<"\n2.FATHER NAME :"<<st[i].FN;
				cout<<"\n3.Ph_no:"<<st[i].PH;
				cout<<"\n4.ADDRESS:"<<st[i].AD;
				cout<<"\n5.Locality";
				cout<<"\n6.Exit\n";
				h:cin>>ch;
				switch(ch)
				{
					case 1:cout<<"\n Enter Name ";
						cin>>st[i].NA;
						break;
					case 2:cout<<"\n Enter Father Name ";
						cin>>st[i].FN;
						break;
					case 3:cout<<"\n Enter new Phone Number ";
							cin>>st[i].PH;
							break;
					case 4:cout<<"\n enter new Address ";
							cin>>st[i].AD;
							break;
					case 5:
							cout<<"Select Locality\n";
							cout<<"AnnapoorneshwarNagar                Allalsandra                   AshokNagar\n\n";
							cout<<"BTMLayout                           Bagaluru                      Bhoopsandra                   Bellandur                     Banashankri\n\n";
							cout<<"ChikkaBommasandra                   Chikkamaranahalli             CubbonPark                    Chikkajalahalli\n\n";
							cout<<"DoddaBommasandra                    Dommasandra\n\n";
							cout<<"ElectronicCity                      GangaNagar                    GandhiNagar\n\n";
							cout<<"Hebbal                              HSRLayout                     Hennur                        IndraNagar\n\n";
							cout<<"JayaNagar                           JPNagar                       Jakkur                        KRPuram\n\n";
							cout<<"KankaNagar                          KamalaNagar                   Kormangala                    KempegowdaNagar               Kattgenahalli\n\n";
							cout<<"Malleshwaram                        Nagwara                       NandiniLayout                 Neelsandra\n\n";
							cout<<"Peenya                              RTNagar                       RajajiNagar                   RajarajeshwariNagar\n\n";
							cout<<"SanjayNagar                         SakarNagar                    SadashivNagar                 ShivajiNagar                  Srirampura\n\n";
							cout<<"Teacher'sColony                     Timmasandra                   Tirumanahalli\n\n";
							cout<<"Ulsoor                              VivekNagar                    Yeshwanthpura                 Yelahanka                     Whitefield\n\n";
							cin>>user10;
							if(user10=="Chikkamaranahalli"||user10=="ShivajiNagar"||user10=="Ulsoor"||user10=="VivekNagar")
								st[i].BN="1";
							else if(user10=="CubbonPark"||user10=="Whitefield"||user10=="KRPuram"||user10=="Yelahanka"||user10=="Jakkur"||user10=="Bagaluru")
								st[i].BN="2";
							else if(user10=="Bellandur"||user10=="IndraNagar"||user10=="AshokNagar"||user10=="Teacher'sColony"||user10=="Chikkamaranahalli")
								st[i].BN="3";
							else if(user10=="ElectronicCity"||user10=="HSRLayout"||user10=="Kormangala"||user10=="Neelsandra"||user10=="BTMLayout"||user10=="IndraNagar")
								st[i].BN="4";
							else if(user10=="KankaNagar"||user10=="JPNagar"||user10=="Banashankri"||user10=="KempegowdaNagar"||user10=="RajajiNagar")
								st[i].BN="5";
							else if(user10=="Malleshwaram"||user10=="SanjayNagar"||user10=="GandhiNagar"||user10=="RajarajeshwariNagar"||user10=="Bhoopsandra")
								st[i].BN="6";
							else if(user10=="SadashivNagar"||user10=="Srirampura"||user10=="RTNagar"||user10=="Hebbal"||user10=="SakarNagar"||user10=="GangaNagar")
								st[i].BN="7";
							else if(user10=="Kattgenahalli"||user10=="KankaNagar"||user10=="Nagwara"||user10=="Hennur"||user10=="Tirumanahalli"||user10=="Chikkajalahalli")
								st[i].BN="8";
							else if(user10=="AnnapoorneshwarNagar"||user10=="KamalaNagar"||user10=="NandiniLayout"||user10=="Peenya"||user10=="Yeshwanthpura")
								st[i].BN="9";
							else if(user10=="Dommasandra"||user10=="DoddaBommasandra"||user10=="ChikkaBommasandra"||user10=="Allalsandra"||user10=="Timmasandra")
								st[i].BN="10";
							else if(user10=="JayaNagar"||user10=="KempegowdaNagar"||user10=="Neelsandra"||user10=="Ulsoor")
								st[i].BN="11";
							break;
						case 6:break;
						default:cout<<"Enter the correct choice ";goto h;
				}
			}while(ch!=6);
		}
		
	}
	f.open("list_of_students.txt",ios::out);
	for(i=0;i<cnt;i++)
	{
		st[i].pack();
		st[i].write(f);
	}	
	f.close();
	//Sleep(5000);
}

// member functions definitions of reistor_now class
int register_now::instructionsform() 
{
	system("cls");
	cout<<"\n          ";
	char b[]="Read the following Instructions\n";
	int x=strlen(b);
	for(int i=0;i<x;i++)
	{
		Sleep(25);
		cout<<b[i];
	}
	char ch;
	char a;
	ifstream f1;
	f1.open("instructions.txt",ios::in);
	while(f1) 
	{
		f1.get(ch);
		cout<<ch;
	}
	cout<<"To accept the above instructions press Y : ";
	cin>>a;
	if(a == 'y' || a == 'Y')
	{
		registration_form();
	}
	else 
	{
		system("cls");
		cout<<"\n\n\n\n\n               sorry,YOU ENTERED A WRONG CHOICE.....";
		Sleep(1000);
		system("cls");
	}
}
int register_now::registration_form()
{
	string password;
	char pwd[5];
	int i=0;
	system("cls");
	fstream fil5;
	fil5.open("login.txt",ios::out|ios::app);
	cout<<"              \n";
	char b[]="REGISTRATION FORM\n";
	int x=strlen(b);
	for(int i=0;i<x;i++)
	{
		Sleep(25);
		cout<<b[i];
	}
	cout<<endl<<endl<<setw(5)<<"NAME :";
	cin>>name[0];
	cout<<setw(40)<<"FATHER NAME :";
	cin>>name[1];
	hh:cout<<endl<<setw(5)<<"Ph_no:";
	cin>>name[2];
	boolean invalid=false;
	if(name[2].length()!=10)
		invalid=true;
	if(invalid)
	{
		cout<<"Invalid Phone Number\n Please enter again"<<endl;
		goto hh;
	}
	cout<<setw(35)<<"ADDRESS:";
	cin>>name[3];
	string user4;
	string user10;
	cout<<"Select Locality\n";
	cout<<"AnnapoorneshwarNagar                Allalsandra                   AshokNagar\n\n";
	cout<<"BTMLayout                           Bagaluru                      Bhoopsandra                   Bellandur                     Banashankri\n\n";
	cout<<"ChikkaBommasandra                   Chikkamaranahalli             CubbonPark                    Chikkajalahalli\n\n";
	cout<<"DoddaBommasandra                    Dommasandra\n\n";
	cout<<"ElectronicCity                      GangaNagar                    GandhiNagar\n\n";
	cout<<"Hebbal                              HSRLayout                     Hennur                        IndraNagar\n\n";
	cout<<"JayaNagar                           JPNagar                       Jakkur                        KRPuram\n\n";
	cout<<"KankaNagar                          KamalaNagar                   Kormangala                    KempegowdaNagar               Kattgenahalli\n\n";
	cout<<"Malleshwaram                        Nagwara                       NandiniLayout                 Neelsandra\n\n";
	cout<<"Peenya                              RTNagar                       RajajiNagar                   RajarajeshwariNagar\n\n";
	cout<<"SanjayNagar                         SakarNagar                    SadashivNagar                 ShivajiNagar                  Srirampura\n\n";
	cout<<"Teacher'sColony                     Timmasandra                   Tirumanahalli\n\n";
	cout<<"Ulsoor                              VivekNagar                    Yeshwanthpura                 Yelahanka                     Whitefield\n\n";
	cin>>user10;
	if(user10=="Chikkamaranahalli"||user10=="ShivajiNagar"||user10=="Ulsoor"||user10=="VivekNagar")
		name[4]="1";
	else if(user10=="CubbonPark"||user10=="Whitefield"||user10=="KRPuram"||user10=="Yelahanka"||user10=="Jakkur"||user10=="Bagaluru")
		name[4]="2";
	else if(user10=="Bellandur"||user10=="IndraNagar"||user10=="AshokNagar"||user10=="Teacher'sColony"||user10=="Chikkamaranahalli")
		name[4]="3";
	else if(user10=="ElectronicCity"||user10=="HSRLayout"||user10=="Kormangala"||user10=="Neelsandra"||user10=="BTMLayout"||user10=="IndraNagar")
		name[4]="4";
	else if(user10=="KankaNagar"||user10=="JPNagar"||user10=="Banashankri"||user10=="KempegowdaNagar"||user10=="RajajiNagar")
		name[4]="5";
	else if(user10=="Malleshwaram"||user10=="SanjayNagar"||user10=="GandhiNagar"||user10=="RajarajeshwariNagar"||user10=="Bhoopsandra")
		name[4]="6";
	else if(user10=="SadashivNagar"||user10=="Srirampura"||user10=="RTNagar"||user10=="Hebbal"||user10=="SakarNagar"||user10=="GangaNagar")
		name[4]="7";
	else if(user10=="Kattgenahalli"||user10=="KankaNagar"||user10=="Nagwara"||user10=="Hennur"||user10=="Tirumanahalli"||user10=="Chikkajalahalli")
		name[4]="8";
	else if(user10=="AnnapoorneshwarNagar"||user10=="KamalaNagar"||user10=="NandiniLayout"||user10=="Peenya"||user10=="Yeshwanthpura")
		name[4]="9";
	else if(user10=="Dommasandra"||user10=="DoddaBommasandra"||user10=="ChikkaBommasandra"||user10=="Allalsandra"||user10=="Timmasandra")
		name[4]="10";
	else if(user10=="JayaNagar"||user10=="KempegowdaNagar"||user10=="Neelsandra"||user10=="Ulsoor")
		name[4]="11";
	cout<<"\nstaff or student\n";
	cin>>user4;
	if(user4=="student"||user4=="STUDENT")
	{
		a++;
		cout<<endl<<endl<<"Your username :";
		cout<<"STUD"<<a;
		cout<<endl<<"PASSWORD :";
		while(i<6)	
		{
			pwd[i]=getch();
			if(pwd[i]!='\r')
				putchar('*');
			if(pwd[i]=='\b')
			{
				cout<<"\b\b  \b\b";
				i--;
				i--;
			}
			if(pwd[i]=='\r')
				pwd[i--];
			++i;
		}
		password=pwd;
		fil5<<"STUD"<<a;
		fil5<<password<<"\n";
		name[5]="17000";
		//cout<<name[5];
		fil5.close();
		fstream fil2;
		fil2.open("list_of_students.txt",ios::in | ios::out | ios::app);
		fil2.seekg(74);
		fil2<<"STUD"<<a<<password<<"|";
		for(int i=0;i<6;i++)
		{
			fil2.setf(ios::left,ios::adjustfield);
			//fil2<<setw(20)<<name[i];
			fil2<<name[i]<<"|";
		}
		fil2<<endl;
		Sleep(500);
	}
	else if(user4=="staff"||user4=="STAFF")
	{
		z++;
		cout<<endl<<endl<<"Your username :";
		cout<<"STAF"<<z;
		cout<<endl<<"PASSWORD :";
		while(i<6)	
		{
			pwd[i]=getch();
			putchar('*');
			++i;
		}
		password=pwd;
		fil5<<"STAF"<<z;
		fil5<<password<<"\n";
		name[5]="17000";
		fil5.close();
		fstream fil2;
		fil2.open("list_of_students.txt",ios::in | ios::out | ios::app);
		fil2.seekg(74);
		fil2<<"STAF"<<z<<"          ";
		for(int i=0;i<6;i++)
		{
			fil2.setf(ios::left,ios::adjustfield);
			fil2<<setw(20)<<name[i];
		}
		fil2<<endl;
		Sleep(500);			
	}
	confirmform();
}
int register_now::confirmform()
{
	char ch;
	system("cls");
	char sentzz[]="          ***************CONFIRM FORM*****************";
	int x;              //special dialogue
	int size; 
	size=strlen(sentzz);
    for(x=0;x<size;x++)
    {   
        Sleep(50); 
        cout<<sentzz[x];
    }
    cout.setf(ios::left,ios::adjustfield);
	cout<<endl<<endl<<" NAME :"<<name[0];
	cout<<endl<<endl<<"                             FATHER NAME :"<<name[1];
	cout<<endl<<endl<<" Ph_no:"<<name[2];
	cout<<endl<<endl<<"                             ADDRESS:"<<name[3];
	cout<<endl<<endl<<" Alloted Bus Number:"<<name[4];
	//cout<<endl<<endl<<"Your username :"<<"STUD"<<a;
	cout<<endl<<endl<<endl<<"                               Total amount to be paid : Rs 17,000|- on or before 5th july"<<endl;
    	int a;
    	Sleep(400);
    	cout<<endl<<endl<<"    Enter any key to return back to main menu :";
    	getch();
    	return 1;
}
int register_now::notice()
{
	system("cls");
	char ch;
	ifstream f2;
	f2.open("program.txt",ios::in );
		while(f2) 
		{
			f2.get(ch);
			cout<<ch;
		}
	cout<<"\n\n\n Enter any to return back to menu :";
	getch();
	return 1;
}

int main() 
{
	char ch;
	system("COLOR 2C");
	while(1)
	{
		system("cls");
	/**
		}	cout<<endl<<endl;
		fstream f2;
		f2.open("sysmbol.txt",ios::in);
		while(f2) 
		{
			f2.get(ch);
			cout<<ch;
		}
	**/
		cout<<endl<<endl;
		Sleep(1000);
		system("COLOR 8F");
		char a[]="                 $$$$$$$$$$$ MVIT CTMS WELCOMES YOU $$$$$$$$$$$";
		int size;
		size=strlen(a);
		for(int i=0;i<size;i++)
		{
			Sleep(15);
			cout<<a[i];
		}
		int c=1;
		cout<<endl<<endl;
		Sleep(0);
		cout<<"\n                    1.REGISTER NOW \n                    2.STAFF LOGIN \n                    3.STUDENT LOGIN \n"
		<<"                    4.UPDATES";
		for(int i=0;i<1;i++)
    	{
    		int x = 16;
    		int y = 10;
    		for (y=10;y<19;y++)  
   			{
    	  		gotoXY(x,y);
    	  		cout << "*";
    	  		Sleep(100);
    	 // gotoXY(x,y); 
		 // cout << "                                                     "; 
  			}
  			y=19;
  			for (x=16;x<63;x++)  
   			{
    	  		gotoXY(x,y);
    	  		cout << "*";
    	  		Sleep(20);
    	 // gotoXY(x,y); 
		 // cout << "                                                     "; 
  			}
  			for (y=10;y<20;y++)  
   			{
    	  		gotoXY(x,y);
    	  		cout << "*";
    	  		Sleep(100);
    	 // gotoXY(x,y); 
		 // cout << "                                                     "; 
  			}
		}
   		register_now r1;
   		staff_login s1;
   		student_login s2;
   		int ch;	
		cout<<"\nSelect your option :";
		cin>>ch;
		fstream f1;
		switch(ch)
		{
			case 1:system("COLOR 1F");
					r1.instructionsform();
					break;
			case 2:system("COLOR 1F");
					s1.login();
					break;
			case 3:system("COLOR 1F");
					s2.login();
					break;
			case 4:system("COLOR 1F");
					r1.notice();
					break;
			default:cout<<"ssssss";
					break;
		}
	}
	getch();
	return 0;	
}

void gotoXY(int x, int y) 
{ 
CursorPosition.X = x; // Locates column
CursorPosition.Y = y; // Locates Row
SetConsoleCursorPosition(console,CursorPosition); // Sets position for next thing to be printed 
}
/*void WaitKey()
{
   while (_kbhit()) _getch(); // Empty the input buffer
   _getch(); // Wait for a key
   while (_kbhit()) _getch(); // Empty the input buffer (some keys sends two messages)
}*/
