#include<iostream>
#include<string.h>
using namespace std;
class stack{
    private:
    int arr[20];
    int top;
    public:
    stack();
    ~stack();
    void push(int x);
    int pop();
    int isempty();
    int isfull();
    int postfix(const char* s);
    bool isoperator(char c);
    
};
stack::stack()  //default constructor
{
    top=-1;
}
stack::~stack() //destructor
{

}
void stack::push(int x)  //member function that insert the element to the top of the stack
{
    if (isfull())
    {
        cout<<"overflow !!";
        exit(1);
    }
    top++;
    arr[top]=x;
}
int stack::pop()    //member function that remove the element from the top of the stack
{
    if(isempty())
    {
        cout<<"underflow !!";
        exit(1);
    }
    int data;
    data=arr[top];
    top--;
    return data;
}
int stack::isempty()
{
    if(top==-1){
        return 1;
    }else{
        return 0;
    }
}
int stack::isfull()
{
    if (top==19)
    {
       return 1;
    }else{
        return 0;
    }
    
}
bool stack::isoperator(char c)
{
    bool result=false;
    if(c=='+'||c=='-'||c=='*'||c=='/')
    {
       result=true;
    }
    return result;

}
int stack::postfix(const char* s)
{
   stack a;
   for(int i=0;i<strlen(s);i++)
   {
    char c=s[i];
    if(isoperator(c))//in this we are checking that the element is a charactor or not  by calling the isoperator member function
    {
    int operand2=a.pop();
    int operand1=a.pop();
    switch(c)
    {
    case '+':
    a.push(operand1+operand2);
    break;
    case '-':
    a.push(operand1-operand2);
    break;
    case '*':
    a.push(operand1*operand2);
    break;
    case '/':
    a.push(operand1/operand2);
    break;
    default:
    cout<<"invalid charcter !!";
    break;
    }
    }
    else
    a.push(c-48);
   }
   return a.pop();
}
int main(){
    // int i,value;
    stack x;
    // cout<<"\nEnter the values :";
    // for (int i = 0; i < 10; i++)
    // {
    // cin>>value;
    // s.push(value);
    // }
    // while (!s.isempty())
    // {
    // value=s.pop();
    // cout<<"\nPopped value is :"<<value;
    // }
    const char* s="56*5/";
    cout<<"The expression-->"<<s<<endl;
    int result=x.postfix(s);
    cout<<"Result-->"<<result;
    x.push(result);
}