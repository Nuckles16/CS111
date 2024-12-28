/************************************************************"
Ryan Kian-Zadeh
CS111
assignment 1
9-16-24

This program will convert lowercase letter to uppercase letter*/

#include <iostream> //for cin, cout
using namespace std;

int main()
{
  //declare variables
char lowercase; //lowercase letter
 char uppercase;//uppercase letter
 //input variable
cout << "Enter a lowercase letter: ";  
 cin >> lowercase;
 //use ascii table to convert
 int offset = 'a'-'A';
 uppercase= (char)(lowercase - offset);
 //output
 cout << "The uppercase is " << uppercase<<"."<<endl;
 cout<<endl;

 return 0;
}
   

