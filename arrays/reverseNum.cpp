/************************************************************************
Ryan Kian-Zadeh
10/15
assignment 4-2

This program will input a non negitive number and reverse the digits.
************************************************************************/
#include<iostream>
using namespace std;

int main()
{
  int num;//initialize num
  int reverse;//store reverse
  int reverseDigit;//initialize reverseDigit
  
  //opening input
  cout<<"Enter a non-negative number: ";
  
  //the cin is in the do loop to check input validation so it can loop
  do
    {
     cin>>num;
     if(num < 0)
       cout<<"The number is invalid. Enter a number again: ";
    }
  while(num<0);

  //num is 0 or positive
  do
    {
      //mod 10 takes the far right digit and stores it
      reverseDigit=num%10;
      //num/=10 removes the number that reverseDigit collected from num
      num/=10;
      	
      //output
      cout<<reverseDigit;
    }while(num>0);
  
  //adds blank lines
  cout<<endl<<endl;
  
  return 0;
}
      
      
      
