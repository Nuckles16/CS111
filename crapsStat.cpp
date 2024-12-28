/*****************************************
Ryan Kian-Zadeh
labs 5-1
10/25/24

This program will simulate the game of craps
********************************************/
#include<iostream>
#include<cstdlib>
#include<iomanip>
using namespace std;

int rollDice()
{
  
  int first=rand()%6+1;//first dice
  int second=rand()%6+1;//second dice
  int sum=first+second;//total dice

  return sum;//return value
}


bool playGame()
{
  
  int roll;//initialize roll
  bool result;//store result
  int froll=rollDice();//roll after invalid

  if(froll==7||froll==11)//input validation
    result=true;//store true

  else if(froll==2||froll==3||froll==12)//input validation
    result=false;//store false

  else
    {
    do
      {
	roll=rollDice();//call rollDice
    
      }while(roll!=7&&froll!=roll);//check value validaty if something else

    //at this point, user is either winner or loser
  
    if(roll==7)//input validation
      result=false;
   
    else//input validation
      result=true;

    }
  return result;
}

int getInt(){

  int num;//initialize num

  cout<<"How many games do you want to play? ";//input
  
  do
    {
      cin>>num;//use same loop twice to make sure the loop continues under these conditions
      if(num<1||num>100000000){
	cout<<"You need to input a number between 1 and 100000000: ";
      }
    }while(num<1||num>100000000);

  return num;
}

int main(){

  int games;//initiailze input games
  int win=0;//set win to zero
  int lose=0;//set lose to 0
  double correct=0;//set correct storage to zero
  double lost=0;//set lost storage to zero
  
  srand(time(0));//randomization

  games=getInt();//call getInt

  for(int i=1;i<=games;i++){
    bool result= playGame();//store and check true and false
    if(result)//store win and lose
      win++;
    else
      lose++;
  }
  
  lost=(double)lose/games*100;//calculate lost percent
  correct=(double)win/games*100;//calculate win percent
  

  cout<<setw(10)<<"win %"<<setw(10)<<"lose %"<<endl;//output win and lose
  cout<<setw(10)<<fixed<<setprecision(3)<<correct<<setw(10)<<fixed<<setprecision(3)<<lost<<endl<<endl;//output win lose percent
  
  return 0;
}

