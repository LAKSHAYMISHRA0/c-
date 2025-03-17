#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
struct account
{
    int account_number;
    string name;
    string password;
    double balance;
};
class bank
{
private:
    account account[100];
    int starting_account;
    int total_accounts;
public:
    bank():starting_account(1000),total_accounts(0){
        load_account();
    }
    ~bank(){
        save_account();
    }
    
    void create_account()
    {
        if (total_accounts>=100)
        {
            cout<<"there is no more account capacity is full !!"<<endl;
            
        }
        string name;
        string password;
        double initial_deposit;
        cout<<"ENTER YOUR NAME -->";
        cin>>name;
        cout<<"ENTER YOUR INITIAL DEPOSIT(MINIMUM 1000)";
        cin>>initial_deposit;
        if (initial_deposit<1000)
        {
            cout<<"THE MINIMUM INITIAL AMOUNT IS 1000 !!";
            
        }
        cout<<"SET A PASSWORD-->";
        cin>>password;
        account[total_accounts]={starting_account,name,password,initial_deposit};
        cout<<"YOUR ACCOUNT IS SUCCESSFULLY CREATED !!"<<endl<<"YOUR ACCOUNT NO.->"<<starting_account<<endl;
        starting_account++;
        total_accounts++;
    }
    int checking(int account_number,const string& password) 
    {
        for (int i = 0; i < total_accounts; i++)
        {
            if (account[i].account_number==account_number && account[i].password==password)
            {
                return i;
            }  
        }
        return -1;
    }
    void deposit(int account_index,double amount)
    {
        account[account_index].balance+=amount;
        cout<<"DEPOSITED -->"<<amount<<".NEW BALANCE-->"<<account[account_index].balance<<endl;
    }
    void withdraw(int account_index,double amount)
    {
        if (account[account_index].balance>=amount)
        {
           account[account_index].balance-=amount;
           cout<<"WITHDRAW SUCCESSFULL -->"<<amount<<".NEW BALANCE-->"<<account[account_index].balance<<endl;
        }else
        {
            cout<<"INSUFFICIANT BALANCE WITHDRAWAL UNSUCCESSFUL!!";
        }
    }
    void check_balance(int account_index)
    {
        cout<<"YOUR BALANCE IS-->"<<account[account_index].balance<<endl;
    }
    void password_update(int account_index)
    {
        string new_password;
        cout<<"ENTER YOUR NEW PASSWORD-->";
        cin>>new_password;
        account[account_index].password=new_password;
        cout<<"YOUR PASSWORD IS SUCCESSFULLY UPDATED !!"<<endl;
    }
    void account_close(int account_index)
    {
        for (int i = account_index; i < total_accounts-1; i++)
        {
            account[i]=account[i+1];
        }
        total_accounts--;
        cout<<"ACCOUNT CLOSED SUCCESSFULLY !!"<<endl;
    }
    void load_account(){
        ifstream file("accounts.dat", ios::binary); 
        if (file.is_open()) 
        { 
            file.read((char*)&total_accounts, sizeof(total_accounts));
            file.read((char*)&account,sizeof(account));
            file.close(); 
            } 
            else 
            { 
                cout << "No previous account data found. Starting fresh!" << endl; 
            } 
    }
    void save_account(){
        ofstream file("accounts.dat", ios::binary); 
        if (file.is_open())
        { 
            file.write((char*)&total_accounts,sizeof(total_accounts));
            file.write((char*)&account, sizeof(account)); 
            file.close(); 
        } 
        else
        { 
                cout << "Error saving accounts to file!" << endl; 
        }
    }
};
int main()
{
    bank systum;
    int choice;
    while(true)
    {
        cout<<"1.CREATE ACCOUNT "<<endl<<"2.DEPOSIT AMOUNT"<<endl<<"3.WITHDRAW AMOUNT"<<endl<<"4.CHECK BALANCE "<<endl<<"5.UPDATE PASSWORD "<<endl<<"6.CLOSE ACCOUNT"<<endl<<"7.EXIT"<<endl;
        cout<<"ENTER YOUR CHOICE-->";
        cin>>choice;
    
    if(choice==1){
    systum.create_account();
    } else if(choice==2)
        {
        int account_number;
        double amount;
        string password;
        cout<<"ENTER YOUR ACCOUNT NUMBER-->";
        cin>>account_number;
        cout<<"ENTER YOUR ACCOUNT PASSWORD -->";
        cin>>password;
        int account_index=systum.checking(account_number,password);
        if (account_index!=-1)
        {
            cout<<"ENTER YOUR AMOUNT TO DEPOSIT -->";
            cin>>amount;
            systum.deposit(account_index,amount);
        }
        else
        {
            cout<<"ACCOUNT NOT CHECKED SUCCESSFULLY PLS CHECK YOUR ACCOUNT_NUMBER AND PASSWORD AGAIN !! ";
        }
        }
        else if(choice==3){
        int account_number;
        double amount;
        string password;
        cout<<"ENTER YOUR ACCOUNT NUMBER-->";
        cin>>account_number;
        cout<<"ENTER YOUR ACCOUNT PASSWORD -->";
        cin>>password;
        int account_index=systum.checking(account_number,password);
        if (account_index!=-1)
        {
            cout<<"ENTER YOUR AMOUNT TO WITHDRAW -->";
            cin>>amount;
            systum.withdraw(account_index,amount);
        }
        else
        {
            cout<<"ACCOUNT NOT CHECKED SUCCESSFULLY PLS CHECK YOUR ACCOUNT_NUMBER AND PASSWORD AGAIN !! ";
        }
        }
        else if(choice==4){
        int account_number;
        double amount;
        string password;
        cout<<"ENTER YOUR ACCOUNT NUMBER-->";
        cin>>account_number;
        cout<<"ENTER YOUR ACCOUNT PASSWORD -->";
        cin>>password;
        int account_index=systum.checking(account_number,password);
        if (account_index!=-1)
        {
            systum.check_balance(account_index);
        }else
        {
            cout<<"ACCOUNT NOT CHECKED SUCCESSFULLY PLS CHECK YOUR ACCOUNT_NUMBER AND PASSWORD AGAIN !! "<<endl;
        }
        
        }
        else if(choice==5){
        int account_number;
        double amount;
        string password;
        cout<<"ENTER YOUR ACCOUNT NUMBER-->";
        cin>>account_number;
        cout<<"ENTER YOUR ACCOUNT PASSWORD -->";
        cin>>password;
        int account_index=systum.checking(account_number,password);
        if (account_index!=-1)
        {
            systum.password_update(account_index);
        }
        else
        {
            cout<<"ACCOUNT NOT CHECKED SUCCESSFULLY PLS CHECK YOUR ACCOUNT_NUMBER AND PASSWORD AGAIN !! ";
        }
        }
        else if(choice==6){
        int account_number;
        double amount;
        string password;
        cout<<"ENTER YOUR ACCOUNT NUMBER-->";
        cin>>account_number;
        cout<<"ENTER YOUR ACCOUNT PASSWORD -->";
        cin>>password;
        int account_index=systum.checking(account_number,password);
        if (account_index!=-1)
        {
            systum.account_close(account_index);
        }
        else
        {
            cout<<"ACCOUNT NOT CHECKED SUCCESSFULLY PLS CHECK YOUR ACCOUNT_NUMBER AND PASSWORD AGAIN !! ";
        }
        }
        else if(choice==7)
        {
            break;
        }
        else{
            cout<<"INVALID CHOICE PLS TRY AGAIN !!";
        }
    }
    return 0;
}
