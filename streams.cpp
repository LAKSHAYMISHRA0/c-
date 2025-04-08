#include<bits/stdc++.h>
using namespace std;
int main()
{
ifstream fin("Letter.txt");
if(!fin.is_open())
{
cout<<"\nFile not opened!";
exit(1); 
}
char ch;
fin.get(ch);
cout<<ch<<endl;
fin.seekg(4);
fin.get(ch);
cout<<ch<<endl;
fin.seekg(13);
fin.get(ch);
cout<<ch<<endl;
cout<<fin.tellg()<<endl;
fin.close();
}
