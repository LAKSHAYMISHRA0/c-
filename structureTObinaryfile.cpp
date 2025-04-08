//Writing the entire structure to a binary file.
// #include<iostream>
// #include<fstream>
// using namespace std;
// struct emp
// {
// char name[40];
// int age; 
// float salary;
// };
// int main() {
// ofstream file;
// struct emp e;
// char ans='y';
// file.open("emp.dat", ios::binary|ios::app);
// if(!file) {
// cout<<"Error in opening file.";
// exit(1);
// }
// while(ans=='y' || ans=='Y'){
// cout<<"Enter name, age and basic salary: ";
// cin>>e.name>>e.age>>e.salary;
// file.write((char*)&e, sizeof(e)); 
// cout<<"Do you want to add another record(Y/N)=";
// cin>>ans;
// }
// file.close();
// return 0;
// }


//Reading entire structure from a binary file
// #include<iostream>
// #include<fstream>
// using namespace std;
// struct emp
// {
// char name[40];
// int age;
// float salary;
// };
// int main(){
// ifstream file;
// struct emp e;
// file.open("emp.dat", ios::binary);
// if(!file) {
// cout<<"Error in opening file.";
// exit(1);
// }
// while(1){
// file.read((char*)&e, sizeof(e));
// if(file.eof())
// break;
// cout<<e.name<<" "<<e.age<<" "<<e.salary<<endl;
// }
// file.close();
// return 0;
// }

//  WAP to store name, roll number, and marks for 10 students in a file and read and display details of students who have obtained more than 70.
// #include<iostream>
// #include<fstream>
// using namespace std;
// struct student
// {
// int rollno;
// char name[20];
// int marks;
// };
// int main()
// {
// fstream file;
// file.open("student.bin",ios::out|ios::trunc|ios::binary);
// int i;
// student s1;
// if(!file.is_open()){
//  cout<<"\nFile Not opened!";
// exit(1);
//  }
// for(i=1;i<=10;i++)
// {
// cout<<"\nEnter details for student "<<i;
// cout<<"\nRoll number : ";
// cin>>s1.rollno;
// cout<<"Name : ";
// cin.ignore(1,'\n');
//  cin.getline(s1.name,20,'\n');
// cout<<"Marks : ";
// cin>>s1.marks;
// file.write((char *)&s1,sizeof(s1));
// }
// file.close();
// file.open("student.bin",ios::in|ios::binary);
// if(!file.is_open()){
//  cout<<"\nFile Not opened!";
// exit(1);
// }
// cout<<"\nStudents above average are: "<<endl;
// for(i=1;i<=10;i++)
// {
// file.read((char*)&s1,sizeof(s1));
// if(s1.marks>70)
// {
// cout<<"\nRoll no:"<<s1.rollno<<"\tName:"<<s1.name<<"\tMarks: "<<s1.marks;
//  }
// }
// file.close();
// }


// To delete a record

// Writing in the file “student.txt”:
#include<iostream>
#include<fstream>
using namespace std;
class student
{
private: 
int rollno;
char name[15];
public:
 void getdata();
void showdata();
 int getrno()
{
return rollno;
}
};
void student::getdata()
	{
cout<<"Enter roll no:";
cin>>rollno;
cout<<"Enter name :";
cin.ignore();
cin.getline(name, 14);
}
void student::showdata()
{
 cout<<"\nRoll no:"<<rollno<<"\t Name:"<<name;
}
int main()
{   
student s1;
ofstream fout("student.txt",ios::out|ios::binary|ios::app);
for(int i=0;i<3;i++){
 cout<<"\nEnter details of student "<<i+1<<endl;
s1.getdata();
fout.write((char*)&s1, sizeof(s1));
}
fout.close();
}