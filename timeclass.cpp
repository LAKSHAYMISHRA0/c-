#include<iostream>
using namespace std;
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
    bool operator>(const time& t);
    bool operator<(const time& t);
    operator int();
    friend ostream& operator<<(ostream &os,time t);
    friend istream& operator>>(istream &is,time &t);
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
    cout<<"enter the minutes-->";
    cin>>mm;
    cout<<"enter the seconds-->";
    cin>>ss;
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
int total_seconds=hh*3600+mm*60+ss;      /// converting the time in seconds 
int total_seconds2=t.hh*3600+t.mm*60+t.ss; 
int total_seconds_result=total_seconds+total_seconds2;
  if(total_seconds_result>=24){
    total_seconds_result=total_seconds_result%(24*3600); 
    } 
    result.hh=total_seconds_result/3600;   //for example 3671/3600=1 hour
    result.mm=(total_seconds_result%3600)/60;   //(3671 % 3600)/60=(71/60) seconds, which is 1 minute
    result.ss=total_seconds_result%60;  //3671%60 = 11 seconds.
    return result; 
}
time time::operator-(const time& t){ 
time result;
int total_seconds=hh*3600+mm*60+ss;      /// converting the time in seconds 
int total_seconds2=t.hh*3600+t.mm*60+t.ss; 
int total_seconds_result=total_seconds-total_seconds2;
  if(total_seconds_result<0){
    total_seconds_result=24*3600+total_seconds_result; 
    } 
    result.hh=total_seconds_result/3600;   //for example 3671/3600=1 hour
    result.mm=(total_seconds_result%3600)/60;   //(3671 % 3600)/60=71 seconds, which is 1 minute
    result.ss=total_seconds_result%60;  //3671 % 60 = 11 seconds.
    return result; 
}
bool time::operator==(const time& t)
{
    bool result=false;
    if (hh==t.hh && mm==t.mm && ss==t.ss)
    {
        result=true;
       return result;
    }
    return result; 
}
bool time::operator!=(const time& t)
{
    bool result=true;
    if (hh==t.hh && mm==t.mm && ss==t.ss)
    {
       result=false;
    }
    return result; 
}
bool time::operator>(const time& t)
{
   if (hh>t.hh || mm>t.mm || ss>t.ss)
   {
    return true;
   }
   else
   return false;
   
}
bool time::operator<(const time& t)
{
   if (hh<t.hh || mm<t.mm || ss<t.ss)
   {
    return true;
   }
   else
   return false;
   
}
time::operator int()
{
    int result;
    result=hh*3600+mm*60+ss;
    return result;
}
ostream& operator<<(ostream& os,time t)
{
    os<<t.hh<<":"<<t.mm<<":"<<t.ss;
    return os;
}
istream& operator>>(istream& is,time &t)
{
    is>>t.hh>>t.mm>>t.ss;
    return is;
}
int main()
{
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
    if(t1==t2)
    {
        cout<<"hello !!!"<<endl;
    }
    else
    cout<<"time is not equal !!"<<endl;
    if (t1!=t2)
    cout<<"world !!!"<<endl;
    else
    cout<<"time is equal !!"<<endl;
    if (t1>t3)
    {
        cout<<"t1 time is greater than t3 time !!! "<<endl;
    }
    if (t1<t2)
    {
        cout<<"t1 time is smaller then t2 time !!!"<<endl;
    }
    int result;
    result=t1;
    cout<<"the time of t1 in integer value --> "<<result<<endl;
    time t6;
    cout<<"enter the new time -->";
    cin>>t6;
    cout<<"entered new time is -->";
    cout<<t6;
    return 0;
}