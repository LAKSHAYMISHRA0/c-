#include<iostream>
#include<string.h>
using namespace std;
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
    friend ostream& operator<<(ostream &os,matrix m);
    friend istream& operator>>(istream &is,matrix & m);
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
matrix matrix::operator*(const matrix& m) {
    matrix res;
    for(int i=0;i<3;i++) {
        for(int j=0;j<3;j++){
        res.arr[i][j]=0;          //it make the array index at 0 arr[0][0]
        for(int k=0;k<3;k++) {
        res.arr[i][j]=res.arr[i][j]+arr[i][k]*m.arr[k][j];
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
matrix matrix::operator++(int x)//post increment
{
    matrix temp=*this;    // it makes a copy of the object called and initialize the values of it in the temp 
   for (int i = 0; i < 3; i++)
 {
    for (int j= 0; j < 3; j++)
    {
        arr[i][j]++;
    }
 }
   return temp;
}
matrix matrix::operator--(int x)// post decrement
{
    matrix temp=*this;  // it makes a copy of the object called and initialize the values of it in the temp 
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
    bool result=true;
     for (int i = 0; i < 3; i++)
    {
    for (int j=0;j<3;j++)
    {
        if (arr[i][j]!=m.arr[i][j])
        {
            result=false;
            return result;
        }
        
    }
    }
    return result;
}
bool matrix::operator!=(const matrix& m)
{
    bool result=false;
    for (int i = 0; i < 3; i++)
   {
    for (int j= 0;j<3; j++)
     { 
    if(arr[i][j]!=m.arr[i][j])
      {
        result=true;
       return result;
      } 
     }
   }
    return result;
}
ostream& operator<<(ostream& os,matrix t)
{
    for (int i = 0; i < 3; i++)
{
    for (int j= 0; j < 3; j++)
    {
        os<<t.arr[i][j]<<" ";
    }
    os<<endl;
}
return os;
}
istream& operator>>(istream& is,matrix &t)
{
    for (int i = 0; i < 3; i++)
{
    for (int j= 0; j < 3; j++)
    {
        is>>t.arr[i][j];
    }
}
return is;
}
int main(){
matrix mat1;
    cout<<"enter 9 values -->"<<endl;
    mat1.read();
    cout<<"enter 9 more values -->"<<endl<<endl;
    int temp[3][3]={{1,2,3},{4,5,6},{7,8,9}};
    matrix mat2(temp);
    mat2.read();
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
    matrix mat10;
    cout<<"enter the new  elements for mat 10-->";
    cin>>mat10;
    cout<<"the new matrix for mat 10 -->"<<endl;
    cout<<mat10;
}