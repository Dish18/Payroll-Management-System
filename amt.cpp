#include<iostream>
using namespace std;
int main()
{
	string name;
	int rate,day,sss,phil;
	double gross;
	
	cout<<"Simple payroll System";
	cout<<"\n\nEnter employee names\t       :   ";
	cin>>name;
	cout<<"\n\nEnter employee rate/day\t       :   ";
	cin>>rate;
	cout<<"\n\nEnter number of days worked\t       :   ";
	cin>>day;
	cout<<"\n\n\n\t==Deductions == ";
	cout<<"\nSSS Contribution\t: ";
	cin>>sss;
	cout<<"philHealth Contribution\t: ";
	cout<<"\n\n\n Total Deductions = php"<<sss+phil;
	cout<<"\nMonthly gross income : php "<<rate*day;
	
	
	cout<<"Employee name : "<< name;
	cout<<"\nMonthly net income : " <<((rate*day)-(sss+phil));
	return 0;
}
