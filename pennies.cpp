/*****************************************************
Ryan Kian-Zadeh
10/7/2024
labs HMWK 4-2

This program will show how many pennies you have over time
*****************************************************/

#include<iostream>
#include<iomanip>
using namespace std;

int main()
{

  int days;//days working
  //double pay;//amount payed
  double pennie;//the cost
  double sum;//the total amount of money

  //input days
  cout<<"How many days do you plan to work? ";
  cin>>days;
  //input validation
  if(days<0||days>31){
    cout<<"Invalid number of days"<<endl;
  }

  //output if days = 0
  else if(days==0){
    cout<<"You will not recieve any funds"<<endl;
  }

  
  else{

    pennie=.01;
    sum=0;
    
    //opening output
    cout<<"  DAY             PAY     ";
    cout<<endl;
    cout<<"========================="<<endl;
    //create left row
    for(int i=1;i<=days;i++){

      //add pennie amount for each day to get sum
      sum+=pennie;

      //create rows for days and pennies
      cout<<left<<setw(3)<<i<<right<<setw(18)<<pennie<<endl;
      pennie*=2;//double the pennie for each day
    }
    //output
    cout<<"========================="<<endl;
    //output
    cout<<"You would have earned $"<<sum<<" after "<<days<<" days."<<endl;
  }
  return 0;
}  
