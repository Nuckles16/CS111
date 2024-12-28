/************************************
Ryan Kian-Zadeh
HMWK 4-2
10/15

This program will produce a random number and the user will have the guess it
***************************************/

#include<iostream>
#include<iomanip>
#include<cstdlib>
using namespace std;
int main()
{
  int guess;//initialize guess
  int num;//initialize number

  
  //this cout will connect with the next cout to creat input
  cout<<"Guess a number between 1 and 100. ";
  

  //this activiates the random variable
  srand(time(0));

  //this calculates the random number
  num = rand()%100+1;
  
  
  //while the input is valid, use the output
  while(true)
    {
     cout<<"Enter your guess: ";
     cin>>guess;

     //input validation
     if(guess>num){
       cout<<setw(9)<<" "<<"Too high, try again."<<endl;
     }

     else if(guess<num){
       cout<<setw(9)<<" "<<"Too low, try again."<<endl;
     }
     else{

       //This is the output if the right input is entered
       if(num==guess){
	 cout<<"You guessed it right!"<<endl<<endl;
	 break;
       }
     }
   }

  return 0;
}

