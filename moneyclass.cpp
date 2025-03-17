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
money::~money() 
{ 
     
}
int main() 
{
    money m1;   // object for class 
    money m2(100, 20);
    m1.read();
    cout << "\nFirst amount is: ";
    m1.show();   //default constructor values wiill be displayed
    cout<<endl;
    m2.read();
    cout << "\nSecond amount is: ";
    m2.show();   //parameterized constructor values will be displayed
    money m3(m2);
    cout <<"\nThird amount is: ";
    m3.show();   //copy of parameterized constructor values will be displayed
    cout<<endl<<endl;
}