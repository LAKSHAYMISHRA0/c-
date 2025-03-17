#include<iostream>
#include<string.h>
using namespace std;
class money {
    private:
    int rs;        //instance variables
    int paisa;
    public:
    void read();      //member functions
    void show();
    money();    //default constructor
    money(int r, int p);   //parameterized constructor
    money(const money& m);   //copy constructor
    ~money();   //destructor
};
money::money() {
    rs = 0;
    paisa = 0;
}
money::money(int r, int p) {
    rs = r;
    paisa = p;
}
money::money(const money& m) {
    rs = m.rs;
    paisa = m.paisa;
}
void money::read() {
    cout<<"enter the Rupees -->";
    cin >> rs ;
    cout<<"enter the paisa -->";
    cin>>paisa;
}
void money::show() {
    if (paisa < 10) {
        cout << rs << ".0" << paisa;   // for single paisa
    } else {
        cout << rs << "." << paisa;
    }
}
money::~money() {  
}




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
{if (denominator !=0)
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
    return *this;  // it points to n1
}
rationalclass rationalclass::operator--() ///prefix decrement
{
    numerator-=denominator;
    return *this;   // it point to n1
}
rationalclass rationalclass::operator--(int x)  //postfix decrement
{
    rationalclass temp(*this); //in this the n2 is pointed by *this because when we pass the statement  rationalclass n10=n2-- the statement is passed like  
    numerator-=denominator;     // this  n10.operator--(n2);
    return temp;
}
rationalclass rationalclass::operator++(int x)   //postfix  increment 
{
    rationalclass temp(*this);
    numerator+=denominator;
    return temp;
}
bool rationalclass::operator==(const rationalclass& r)
{
   int num=numerator*r.denominator;
   int deno=denominator*r.numerator;
   if(num==deno)
   {
    return true;
   }
   else{
    return false;
   }
 }
bool rationalclass::operator>(const rationalclass& r)
{
   int num=numerator*r.denominator;
   int deno=denominator*r.numerator;
   if (num>deno)
   {
      return true;
   }
   else
   return false;
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



class matrix
{
private:
    int arr[3][3];
public:
    matrix();
    matrix(int arr[3][3]);
    matrix(const matrix& m);
    ~matrix();
    void read();
    void show();
    matrix operator+(const matrix & m);
    matrix operator*(const matrix& m);
    matrix operator++(); /// prefix increment 
    matrix operator++(int x); //postfix increment 
    matrix operator--(int x); //postfix decrement
    matrix operator--(); // prefix decrement 
    bool operator==(const matrix& m);
    bool operator!=(const matrix& m);
};
matrix::matrix()   //default
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
           arr[i][j]=0;
        }
        
    }
    
}
matrix::matrix(const matrix& m) //copy
{
for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
           arr[i][j]=m.arr[i][j];
        }
        
    }
}
matrix::matrix(int temp[3][3])    //parametreized
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
           arr[i][j]=temp[i][j];
        }
        
    }
}
matrix::~matrix()
{

}
void matrix::read()
{
for (int i = 0; i < 3; i++)
{
    for (int j = 0; j < 3; j++)
    {
        cin>>arr[i][j];
    }
    
}
}
void matrix::show()
{
for (int i = 0; i < 3; i++)
{
    for (int j= 0; j < 3; j++)
    {
        cout<<arr[i][j]<<" ";
    }
    cout<<endl;
}
}
matrix matrix::operator+(const matrix& m)
{
    matrix res;
    for (int i = 0; i < 3; i++)
   {
    for (int j= 0; j < 3; j++)
    {
        res.arr[i][j]+=m.arr[i][j];
    }

   }
 return res;
}
matrix matrix::operator*(const matrix& m)
{
    matrix res;
    for (int i = 0; i < 3; i++)
   {
    for (int j= 0; j < 3; j++)
    {
        res.arr[i][j]=0;
    
    for (int k = 0; k < 3; k++)
    {
        res.arr[i][j]=res.arr[i][j]+arr[i][k]*arr[k][j];
    }
    }
   }
   return res;
}
matrix matrix::operator++()
{
   for (int i = 0; i < 3; i++)
 {
    for (int j= 0; j < 3; j++)
    {
        ++arr[i][j];
    }
 }
   return *this;
}
matrix matrix::operator++(int x)
{
    matrix temp(*this);
   for (int i = 0; i < 3; i++)
 {
    for (int j= 0; j < 3; j++)
    {
        arr[i][j]++;
    }
 }
   return temp;
}
matrix matrix::operator--(int x)
{
    matrix temp(*this);
   for (int i = 0; i < 3; i++)
 {
    for (int j= 0; j < 3; j++)
    {
        arr[i][j]--;
    }
 }
   return temp;
}
matrix matrix::operator--()
{
   for (int i = 0; i < 3; i++)
 {
    for (int j = 0; j < 3; j++)
    {
        --arr[i][j];
    }
 }
   return *this;
}
bool matrix::operator==(const matrix& m)
{
     for (int i = 0; i < 3; i++)
    {
    for (int j=0;j<3;j++)
    {
        if (arr[i][j]==m.arr[i][j])
        {
            return true;
        }
    }
    }
    return false;
}
bool matrix::operator!=(const matrix& m)
{
    for (int i = 0; i < 3; i++)
    {
    for (int j= 0;j<3 ; j++)
    { 
    if(arr[i][j]!=m.arr[i][j])
    {
       return true;
    } 
    }
    }
    return false;
}





class time
{
private:
    int hh;
    int mm;
    int ss;
public:
    time();
    time(int h,int m,int s);
    time(const time& t);
    ~time();
    void read();
    void show();
    time operator+(const time& t);
    time operator-(const time& t);
    bool operator==(const time& t);
    bool operator!=(const time& t);
};

time::time()
{
    hh=0;
    mm=0;
    ss=0;
}
time::time(int h,int m,int s)
{
  if (h>=0 && h<24)
  {
    hh=h;
  }else{
    hh=0;
  }
  if (m>=0 && m<60)
  {
    mm=m;
  }
  else{
    mm=0;
  }
  if (s>=0 && s<60)
  {
    ss=s;
  }else{
    ss=0;
  }
}
time::time(const time& t){
    hh=t.hh;
    mm=t.mm;
    ss=t.ss;
}
time::~time()
{

}
void time::read(){
    cout<<"enter the hours-->";
    cin>>hh;
    if (hh>=24)
    {
        hh=0;
    }
    cout<<"enter the minutes-->";
    cin>>mm;
    if(mm<0 || mm>=60)
    {
        mm=0;
    }
    cout<<"enter the seconds-->";
    cin>>ss;
    if (ss<0 || ss>=60)
    {
        ss=0;
    }
}
void time::show()
{
 if (hh<10 && mm<10 && ss<10)
{
    cout<<"0"<<hh<<":"<<"0"<<mm<<":"<<"0"<<ss<<endl;
}
 else{
    cout<<hh<<":"<<mm<<":"<<ss<<endl;
}
}
time time::operator+(const time& t)
{
     time result; 
     result.ss = ss + t.ss; 
     result.mm = mm + t.mm + result.ss / 60; 
     result.hh = hh + t.hh + result.mm / 60; 
     result.ss %= 60; 
     result.mm %= 60; // if mm is 60 it become 0.
     result.hh %= 24; /// if the hh is 24 it become 0.
     return result;
}
time time::operator-(const time& t){ 
time result;
int total_seconds = hh * 3600 + mm* 60 + ss;      /// converting the time in seconds 
int total_seconds2 = t.hh * 3600 + t.mm * 60 + t.ss; 
int total_seconds_result = total_seconds - total_seconds2;
  if(total_seconds_result < 0){
    total_seconds_result = 24 * 3600 + total_seconds_result; 
    } 
    result.hh = total_seconds_result / 3600; 
    result.mm = (total_seconds_result % 3600) / 60; 
    result.ss = total_seconds_result % 60; 
    return result; 
}
bool time::operator==(const time& t)
{
    
    
}
int main() 
{
    // money m1;   // object for class 
    // money m2(100, 20);
    // m1.read();
    // cout << "\nFirst amount is: ";
    // m1.show();   //default constructor values wiill be displayed
    // cout<<endl;
    // m2.read();
    // cout << "\nSecond amount is: ";
    // m2.show();   //parameterized constructor values will be displayed
    // money m3(m2);
    // cout <<"\nThird amount is: ";
    // m3.show();   //copy of parameterized constructor values will be displayed
    // cout<<endl<<endl;



    // rationalclass n1;
    // n1.read();
    // n1.show();
    // rationalclass n2(2,2);
    // n2.read();
    // cout<<"Parameterized constructor value--> "; 
    // n2.show();
    // rationalclass n3(n2);
    // cout<<"Copy constructor value --> ";
    // n3.show();
    // cout<<endl<<endl;
    // rationalclass n4=n1+n2;
    // rationalclass n5=n1-n2;
    // rationalclass n6=n1*n2;
    // rationalclass n7=n1/n2;
    // cout<<"the value of n4 =>";
    // n4.show();
    // cout<<"\nthe value of n5 =>";
    // n5.show(); 
    // cout<<"\nthe value of n6 =>";
    // n6.show();
    // cout<<"\nthe value of n7 =>";
    // n7.show();
    // rationalclass n8=++n1;
    // rationalclass n9=n1++;
    // rationalclass n10=--n2;
    // rationalclass n11=n2--;
    // cout<<"the value of the n1 after prefix increment --> ";
    // n8.show();
    // cout<<"the value of n1 after postfix increment --> ";
    // n9.show();
    // cout<<"the value of the n2 after prefix decrement --> ";
    // n10.show();
    // cout<<"the value of the n2 after postfix decrement --> ";
    // n11.show();
    // if(n1==n2)
    // {
    //     cout<<"heloo !!"<<endl;
    // }
    // if(n1>n2)
    // {
    //     cout<<"world !!"<<endl;
    // }
    // int a;
    // a=n1;
    // cout<<"the value of a -->"<<a<<endl;
    // float b;
    // b=n1;
    // cout<<"the value of b -->"<<b<<endl;

    


    matrix mat1;
    cout<<"enter 9 values -->"<<endl;
    mat1.read();
    cout<<"enter 9 more values -->"<<endl<<endl;
    int temp[3][3]={{1,2,3},{4,5,6},{7,8,9}};
    matrix mat2(temp);
    // mat2.read();
    matrix mat3(mat2);
    cout<<"first matrix -->"<<endl;
    mat1.show();
    cout<<endl;
    cout<<"second matrix -->"<<endl;
    mat2.show();
    cout<<"third matrix -->"<<endl;
    mat3.show();
    matrix mat4=mat1+mat2;
    cout<<"mat4 => "<<endl;
    mat4.show();
    matrix mat5=mat1*mat2;
    cout<<"mat5 => "<<endl;
    mat5.show();
    matrix mat6=++mat1;
    cout<<"showing the mat 1 after pre-increment-->"<<endl;
    mat6.show();
    matrix mat7=mat1++;   // in this statement mat1 is calling the operator++(int x) so mat1 go with the reference argument
    cout<<"showing the mat1 after post-increment -->"<<endl;
    mat7.show();
    matrix mat8=mat1--;
    cout<<"showing the mat1 after post decrement -->"<<endl;
    mat8.show();
    matrix mat9=--mat1;
    cout<<"showing the mat1 after pre decrement -->"<<endl;
    mat9.show();
    if(mat1==mat2)
    {
        cout<<"lakshay !!"<<endl;
    }
    else{
        cout<<"it is not equal !!"<<endl;
    }
    if(mat1!=mat2)
    {
       cout<<"mishra !!"<<endl;
    }
    
    
 


    time t1;
    t1.read();
    cout<<"time of default constructor after reading input-->";
    t1.show();
    time t2(12,0,0);
    t2.read();
    cout<<"time in the parameterized constructor -->";
    t2.show();
    time t3(t2);
    cout<<"time in copy constructor -->";
    t3.show();
    time t4=t1+t2;
    cout<<"the time in t4 after addition of t1 and t2 -->";
    t4.show();
    time t5=t1-t2;
    cout<<"the time in t5 after the subtraction of t1 and t2 -->";
    t5.show();
    return 0;
}