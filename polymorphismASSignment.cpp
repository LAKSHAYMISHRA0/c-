#include<iostream>
using namespace std;
class item
{
public:
    virtual void read()=0; ///pure virtual function
    virtual void show()=0;  //pure virtual function
};

class dvd:public item   //class DVD publicly inherit abstract item class
{
    char directer[20];
    char category[20];
    char name[20];
public:
   void read()
   {
    cout<<"Enter the Director-->";
    cin.getline(directer,20);
    cout<<"Enter the Category of DVD-->";
    cin.getline(category,20);
    cout<<"Enter the Name-->";
    cin.getline(name,20);
   }
   void show()
   {
    cout<<"DVD DIRECTOR :--> "<<directer<<endl;
    cout<<"CATEGORY OF DVD :--> "<<category<<endl;
    cout<<"DVD NAME :--> "<<name<<endl;
   }
};
class book:public item
{
    char author[20];
    char publication[20];
    char name[20];
public:
    void read()
    {
        cout<<"Enter the Author -->";
        cin.getline(author,20);
        cout<<"Enter the Publications -->";
        cin.getline(publication,20);
        cout<<"Enter the Name of the BOOK -->";
        cin.getline(name,20);
    }
    void show()
    {
        cout<<"AUTHOR :--> "<<author<<endl;
        cout<<"PUBLICATIONS :--> "<<publication<<endl;
        cout<<"BOOK NAME :--> "<<name<<endl;
    }
};
int main()
{ 
    //creating the 3 objects 
    item*ap[2];
    char choice;//because (item) is an abstract class.so we are cannot be able to create object for item class directly.
    //so that we can use the overridden read() and show() functions.
    // ap[0]=new dvd();
    // ap[1]=new book();
    for (int  i = 0; i < 2; i++)
    {
        cout<<"Enter type of item(d for DVD, b for Book):"; 
        cin >> choice; 
        cin.ignore();
        if (choice == 'd')
        { 
            ap[i] = new dvd();
        } 
        else if(choice == 'b') 
        { 
            ap[i] = new book(); 
        }else{ 
        cout << "Invalid choice. Defaulting to DVD."<<endl; 
        ap[i] = new dvd();
    }
      ap[i]->read();
    }
    for (int i = 0; i < 2; i++)
    {
       ap[i]->show();
       delete ap[i];
    }
    
    
    
    
}