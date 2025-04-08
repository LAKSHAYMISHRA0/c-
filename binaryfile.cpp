//The following program writes an array of 5 integers to a text file “array.txt”. The size of the file is 55 bytes

// #include<iostream>
// #include<fstream>
// using namespace std;
// int main() {
// ofstream fout("array.txt",ios::out);
//  if(!fout) {
//  cout<<"Error in opening file!";
// return 0;
//  }
// int a[] = {1000000000, 2000000001, 2000000002, 2000000003, 2000000005};
// for(int i=0;i<5;i++) {
// fout<<a[i]<<" ";
// }
// fout.close();
// return 0;
// }



// The following program writes an array of 5 integers to a binary file “array.dat”. The size of the file is 20 bytes.

// #include<iostream>
// #include<fstream>
// using namespace std;
// int main() {
// ofstream fout("array.dat",ios::out|ios::binary);
// if(!fout) {
// cout<<"Error in opening file!";
// return 0;
// }
// int a[] = {1000000000, 2000000001, 2000000002, 2000000003, 2000000005};
// fout.write((char*)a, sizeof(a));
// fout.close();
// return 0;
// }

// The following program reads an array of 5 integers from binary file “array.dat” created in the previous program

#include<iostream>
#include<fstream>
using namespace std;
int main() {
ifstream fin("array.dat",ios::in|ios::binary);
int a[5];
if(fin) {
fin.read( (char*)a, sizeof(a));
for(int i=0;i<5;i++)
 cout<<a[i]<<' ';
fin.close();
}
else {
 cout<<"File Not Found!";
}
 return 0;
}