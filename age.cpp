/*********************************************************************************
Ryan Kian-Zadeh
HMWK 4-2
10/15/2024

This program will determine the oldest person in a group and find the average age
**********************************************************************************/
#include<iostream>
using namespace std;

int main()
{
  int age;//initialize age
  double sum;//allow decimal places to the sum total
  double avg;//allow average to have decimal points
  int minors;//initialize the number of minors in the program
  int adult;//initialize the number of adults in the program
  int oldest;//intiailize the location of the oldest person in the program
  int youngest=1000;//set the youngest period for youngest
  int count;//initialze the count variable to add 1 for minors and adults
  
  while(age>=0)//break out when user enters negitive
    {
      //input
      cout<<"Enter an age: ";
      cin>>age;

      //input validation
      if(age>=0){
	
	//set sum and count
	sum+=age;
	count++;
      
	//determine oldest person
	if(age>oldest)
	  oldest=age;
	//determine youngest person
	if(youngest>age)
	  youngest=age;
	//check for minors and adults
	if(age<18)
	  minors++;
	else
	  adult++;
      }
    }

  //check if the first input is a negitive number for validation
  if(count==0){
    cout<<endl;
    cout<<"No ages were entered"<<endl<<endl;
  }

  else{
    //calculate average
    avg=sum/count;
    //output the variables
    cout<<endl;
    cout<<avg<<" (average)"<<endl;
    cout<<minors<<" (minors)"<<endl;
    cout<<adult<<" (adults)"<<endl;
    cout<<oldest<<" (oldest)"<<endl;
    cout<<youngest<<" (youngest)"<<endl;
    cout<<endl;
  }

  return 0;
}
      
	
