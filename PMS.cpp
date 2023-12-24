#include<iostream>
#include<iomanip>
#include<Windows.h>
#include<dos.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
using namespace std;
class employee
{
	private:
		char name[20];
		char code[5];
		int age;
		int sal;
		int exp,rate,day;
		char des[10];
	public:
	
		void menu();
		void insert();
		void compute_payment();
		void edit();
		void del();
		void list();
		void enquiry();
};
void employee::menu()
{
	system("COLOR 1F");
	employee e;
	while(1)
	{
	system("cls");
	
	cout<<"\n		1 	 To add an employee details";
	cout<<"\n		2	 To compute payment of a employee";
	cout<<"\n		3	 To see list of employee details";
	cout<<"\n		4	 To edit an employee details";
	cout<<"\n		5	 To remove an employee details from list";
	cout<<"\n		6	 To see details of a employee";
	cout<<"\n		0	 To exit	";
	cout<<"\n\n\n\n		Choose your optiion 	:	";
	int ab;
	cin>>ab;

		switch(ab)
		{
			case 1:
				e.insert();
				break;
			case 2:
				e.compute_payment();
				break;
			case 3:
				e.list();
				break;
			case 4:
				e.edit();
				break;
			case 5:
				e.del();
				break;
			case 6:
				e.enquiry();
				break;
			case 0:
				return ;
			default:
				cout<<"Invalid Option";
				break;
		}
	}
}
void employee::insert()
{
	system("cls");
	FILE *fa;
	char ch;
	employee e;
	system("cls");
	system("COLOR 2F");
	cout<<"\n	Enter name of employee			:	";
	cin>>e.name;
	cout<<"\n	Enter id of employee			:	";
	cin>>e.code;
	cout<<"\n	Enter designation of employee		:	";
	cin>>e.des;
	cout<<"\n	Enter age of employee			:	";
	cin>>e.age;
	cout<<"\n	Enter salary of employee		:	";
	cin>>e.sal;	
	cout<<"\n	Enter experience of employee		:	";
	cin>>e.exp;
cout<<"\n	Do you wish to save the above details(y/n)	:	";
	cin>>ch;
	if(ch=='y')
	{
		fa=fopen("details.txt","a");
		fprintf(fa,"%s %s %s %d %d %d \n",e.name,e.code,e.des,e.age,e.exp,e.sal);
		fclose(fa);
	}
	else
		insert();

}
void employee::compute_payment()
{
	system("cls");
	FILE *fa;
	char ch;
	employee e;
	int sss;
	cout<<"\n	Enter id of employee			:	";
	cin>>e.code;
	cout<<"\n\nEnter employee names\t           :   ";
	cin>>e.name;
	cout<<"\n\nEnter employee rate/day\t        :   ";
	cin>>e.rate;
	cout<<"\n\nEnter number of days worked\t    :   ";
	cin>>e.day;
	cout<<"\n\n\n\t-------Deductions----------  ";
	cout<<"\nSSS Contribution\t                 :    ";
	cin>>sss;
	
	cout<<"Employee name : "<< e.name;
	cout<<"\nMonthly net income : " <<(e.rate*e.day)-sss;
	cout<<"\n	Do you wish to save the above details(y/n)	:	";
	cin>>ch;
	if(ch=='y')
	{
		fa=fopen("details.txt","a");
		fprintf(fa,"%s %s %s %d %d %d \n",e.name,e.code,e.des,e.age,e.exp,e.sal);
		fclose(fa);
	}
	else
		insert();

}	
	
void employee::list()
{
	system("cls");
	system("COLOR 3F");
	FILE *fb;
	fb=fopen("details.txt","r");
	employee e;
	cout<<"\nname		code		designation		age		expierenice		salary\n";
	while(fscanf(fb,"%s %s %s %d %d %d \n",e.name,e.code,e.des,&e.age,&e.exp,&e.sal)!=EOF)
	{	
		cout<<"\n"<<e.name<<"\t\t"<<e.code<<"\t\t"<<e.des<<"\t\t\t"<<e.age<<" \t\t"<<e.exp<<"\t\t\t"<<e.sal;
	}
	fclose(fb);
			getch();
}

void employee::edit()
{
		system("COLOR 4F");
	system("cls");
	FILE *fc,*fd;

	employee e;
	char ccode[5];
	cout<<"Enter code 	:	";
	cin>>ccode;
	char id[5],desg[10];
	cout<<"Enter new id 	:	";
	cin>>id;
	cout<<"Enter new designation 	:	";
	cin>>desg;
	fc=fopen("details.txt","r");
	fd=fopen("temp.txt","w");
	while(fscanf(fc,"%s %s %s %d %d %d \n",e.name,e.code,e.des,&e.age,&e.exp,&e.sal)!=EOF)
	{
		if(strcmp(ccode,e.code)==0)
		{
			fprintf(fd,"%s %s %s %d %d %d \n",e.name,id,desg,e.age,e.exp,e.sal);
		}
		else
		{
			fprintf(fd,"%s %s %s %d %d %d \n",e.name,e.code,e.des,e.age,e.exp,e.sal);
		}
	}
	char s[]="details.txt";
	char t[]="temp.txt";
	
	fclose(fc);
	fclose(fd);	
	
	int a = remove(s);
	int b = rename(t,s);
			getch();

}
void employee::enquiry()
{
	
	system("cls");
	system("COLOR 6F");
	FILE *fe;

	employee e;
	char ccode[5];
	cout<<"Enter code ";
	cin>>ccode;
	fe=fopen("details.txt","r");
	while(fscanf(fe,"%s %s %s %d %d %d \n",e.name,e.code,e.des,&e.age,&e.exp,&e.sal)!=EOF)
	{
		if(strcmp(ccode,e.code)==0)
		{
			cout<<"\n name	        id  	designation	       age	    experience	    	      salary";
			cout<<"\n"<<e.name<<"\t\t"<<e.code<<"\t"<<e.des<<"\t\t"<<e.age<<"\t\t"<<e.exp<<"\t\t\t"<<e.sal;
		}
	}
	fclose(fe);
			getch();
}
void employee::del()
{
	system("cls");
	FILE *ff,*fg;

	employee e;
	char ccode[5];
	cout<<"Enter id ";
	cin>>ccode;
	ff=fopen("details.txt","r");
	fg=fopen("temp.txt","w");
	while(fscanf(ff,"%s %s %s %d %d %d \n",e.name,e.code,e.des,&e.age,&e.exp,&e.sal)!=EOF)
	{
		if(strcmp(ccode,e.code)!=0)
		{
			fprintf(fg,"%s %s %s %d %d %d \n",e.name,e.code,e.des,e.age,e.exp,e.sal);
		}
	}
	char s[]="details.txt";
	char t[]="temp.txt";
	
	fclose(ff);
	fclose(fg);	
	
	int a = remove(s);
	int b = rename(t,s);
			getch();
}


int main()
{
	int a;
	employee e;
	e.menu();
			
	return 0;
}
  
