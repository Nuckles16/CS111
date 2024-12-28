/*****************************
Ryan Kian-Zadeh
10/12/2024
cs111
HMWK 4-1

This program will find the top and bottom number of a squared number
******************************/

#include<iostream>
#include<iomanip>

using namespace std;

int main()
{
  int num;//initialize main number
  int i;
  int top;//initialize top number
  int bottom;//initialize bottom number
  //int topDistance;initialize top number distance from number
  // int bottomDistance;//initialize bottom number distance from number

  //input number
  cout<<"Enter a positive number: ";
  cin>>num;
  //for loop top
  for(i=1;i<=num;i++){
    if(i*i>=num){
      top=i;
      break;
	}
  }
  bottom=top-1;

  cout<<"Top is "<<top<<endl;
  cout<<"Bottom is "<<bottom<<endl;

  int topDistance=(top*top)-num;
  int bottomDistance=num-(bottom*bottom);

  if(topDistance>bottomDistance)
    cout<<"Between "<<top<<" and "<<bottom<<", "<<bottom<<" is closer."<<endl<<endl;
  else if(bottomDistance>topDistance)
    cout<<"Between "<<top<<" and "<<bottom<<", "<<top<<" is closer."<<endl<<endl;
  return 0;
}
  
  

