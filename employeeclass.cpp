#include<iostream>
#include<string.h>
using namespace std;
class employeeclass
{
private:
    int age;
    char fname[20];
    char lname[20];
    float salary;
public:
    employeeclass();
    employeeclass(int a,const char f[20],const char l[20],float s);
    employeeclass(const employeeclass& e);
    ~employeeclass();
    void read();
    void show();
    friend ostream& operator<<(ostream& os,const employeeclass &e);
    friend istream& operator>>(istream& is,employeeclass& e);


};

employeeclass::employeeclass()
{ 
    age=0;
    strcpy(fname,"unknown");
    strcpy(lname,"unknown"); 
    salary=0;
}
employeeclass::employeeclass(int a,const char f[20],const char l[20],float s)
{
   age=a;
   strcpy(fname,f);
   strcpy(lname,l);
   salary=s;
}
employeeclass::employeeclass(const employeeclass& e)
{
    age=e.age;
    strcpy(fname,e.fname);
    strcpy(lname,e.lname);
    salary=e.salary;

}
employeeclass::~employeeclass()
{

}
void employeeclass::read()
{
    cout<<"enter the age of employee --->";
    cin>>age;
    cout<<"enter the first name -->";
    cin>>fname;
    cout<<"enter the last name -->";
    cin>>lname;
    cout<<"enter the salary -->";
    cin>>salary;
}
void employeeclass::show()
{
    cout<<"age:-"<<age<<endl;
    cout<<"Name:-"<<fname<<" "<<lname<<endl;
    cout<<"salary:-"<<salary<<endl;
}
ostream& operator<<(ostream& os,const employeeclass& e)
{
    os<<"age:-"<<e.age<<endl;
    os<<"Name:-"<<e.fname<<" "<<e.lname<<endl;
    os<<"salary:-"<<e.salary<<endl;
}
istream& operator>>(istream&is,employeeclass& e)
{
    cout<<"enter the age of employee --->";
    is>>e.age;
    cout<<"enter the first name -->";
    is>>e.fname;
    cout<<"enter the last name -->";
    is>>e.lname;
    cout<<"enter the salary -->";
    is>>e.salary;
}
int main()
{
    employeeclass e1;
    e1.read();
    cout<<endl;
    cout<<"the details of the employee e1 -->"<<endl;
    e1.show();
    cout<<endl;
    employeeclass e2(28,"lakshay","mishra",28000);
    e2.read();
    cout<<"The details of the employee e2 -->"<<endl;
    e2.show();
    cout<<endl;
    employeeclass e3(e2);
    e3.show();
    cout<<endl;
    employeeclass e4;
    cin>>e4;
    cout<<endl;
    cout<<e4;

}