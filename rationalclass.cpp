#include<iostream>
#include<string.h>
using namespace std;
class rationalclass
{
private:
    int numerator;
    int denominator;
public:
    rationalclass();
    rationalclass(int n,int d);
    rationalclass(const rationalclass& r);
    ~rationalclass();
    void read();
    void show();
    rationalclass operator+(const rationalclass& r);
    rationalclass operator-(const rationalclass& r);
    rationalclass operator*(const rationalclass& r);
    rationalclass operator/(const rationalclass& r);
    rationalclass operator++();
    rationalclass operator --();
    rationalclass operator--(int x);
    rationalclass operator++(int x);
   bool operator==(const rationalclass& r);
   bool operator>(const rationalclass& r);
   operator int();
   operator float();
   friend ostream& operator<<(ostream &os,rationalclass r);
   friend istream& operator>>(istream &is,rationalclass & r);

};
rationalclass::rationalclass()
{
    numerator=1;
    denominator=1;
}
rationalclass::rationalclass(int n,int d)
{
  numerator=n;
  denominator=d;
}
rationalclass::rationalclass(const rationalclass& r)
{
  numerator=r.numerator;
  denominator=r.denominator;
}
rationalclass::~rationalclass()
{
}
void rationalclass::read()
{
cout<<"enter the numerator-->";
 cin>>numerator;
 cout<<"enter the denominator-->";
 cin>>denominator;
 if(denominator==0)
 {
   cout<<"the denominator is invalid"<<endl;
 }
}
void rationalclass::show()
{
    if(denominator !=0)
{
 cout<<numerator<<"/"<<denominator<<endl;
}else{
    cout<<"please check your denominator !!!"<<endl;
}
}
rationalclass rationalclass::operator+(const rationalclass& r){
   int num=numerator*r.denominator+denominator*r.numerator;
   int deno=denominator*r.denominator;
   return rationalclass(num,deno);
}
rationalclass rationalclass::operator-(const rationalclass& r)
{
   int num=numerator*r.denominator-denominator*r.numerator;
   int deno=denominator*r.denominator;
   return rationalclass(num,deno);
}
rationalclass rationalclass::operator*(const rationalclass& r)
{
  int num=numerator*r.numerator;
  int deno=denominator*r.denominator;
  return rationalclass(num,deno);
}
rationalclass rationalclass::operator/(const rationalclass& r)
{
  int num=numerator*r.denominator;
   int deno=denominator*r.numerator;
   return rationalclass(num,deno);   
}
rationalclass rationalclass::operator++()   //prefix increment
{
    numerator+=denominator;
    return *this;  // it points to n8
}
rationalclass rationalclass::operator--() ///prefix decrement
{
    numerator-=denominator;
    return *this;   // it point to n10
}
rationalclass rationalclass::operator--(int x)  //postfix decrement
{
    rationalclass temp=*this; //it make a copy  of the object and initialize the values that are in the object to temp
    numerator-=denominator; 
    return temp;
}
rationalclass rationalclass::operator++(int x)   //postfix  increment 
{
    rationalclass temp=*this; //it make a copy  of the object and initialize the values that are in the object to temp
    numerator+=denominator;
    return temp;
}
bool rationalclass::operator==(const rationalclass& r)
{
    bool result=false;
   int num=numerator*r.denominator;
   int deno=denominator*r.numerator;
   if(num==deno)
   {
    result=true;
    return result;
   }
   return result;
 }
bool rationalclass::operator>(const rationalclass& r)
{ 

return (numerator*r.denominator/r.numerator*denominator);
   
}
rationalclass::operator int()
{
    int result;
    result=numerator/denominator;
    return result;
}
rationalclass::operator float()
{
    float result;
    result=(float)numerator/(float)denominator;
    return result;
}
ostream& operator<<(ostream& os,rationalclass r)
{
if(r.denominator!=0)
{
    os<<r.numerator<<"/"<<r.denominator<<endl;
}else{
    os<<"please check your denominator !!!"<<endl;
}
return os;
}
istream& operator>>(istream& is,rationalclass & r)
{
    is>>r.numerator>>r.denominator;
    if (r.denominator==0)
    {
        cout<<"pls check it again !!@#";
    }
    return is;
}
int main()
{   
    rationalclass n1;
    n1.read();
    n1.show();
    rationalclass n2(2,2);
    n2.read();
    cout<<"Parameterized constructor value--> "; 
    n2.show();
    rationalclass n3(n2);
    cout<<"Copy constructor value --> ";
    n3.show();
    cout<<endl<<endl;
    rationalclass n4=n1+n2;
    rationalclass n5=n1-n2;
    rationalclass n6=n1*n2;
    rationalclass n7=n1/n2;
    cout<<"the value of n4 =>";
    n4.show();
    cout<<"\nthe value of n5 =>";
    n5.show(); 
    cout<<"\nthe value of n6 =>";
    n6.show();
    cout<<"\nthe value of n7 =>";
    n7.show();
    if(n1==n2)
    cout<<"heloo !!"<<endl;
    rationalclass n8=++n1;
    rationalclass n9=n1++;
    rationalclass n10=--n2;
    rationalclass n11=n2--;
    cout<<"the value of the n1 after prefix increment --> ";
    n8.show();
    cout<<"the value of n1 after postfix increment --> ";
    n9.show();
    cout<<"the value of the n2 after prefix decrement --> ";
    n10.show();
    cout<<"the value of the n2 after postfix decrement --> ";
    n11.show();
    if(n1>n2)
    cout<<"world !!"<<endl;
    else
    cout<<"the n1 is not greater then n2 "<<endl;
    int a;
    a=n1;
    cout<<"the value of a -->"<<a<<endl;
    float b;
    b=n1;
    cout<<"the value of b -->"<<b<<endl;
    rationalclass n12;
    cout<<"enter the new values in n12 -->";
    cin>>n12;
    cout<<"the new values of n12-->";
    cout<<n12;
}