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

int getInt(){

  int search;//initialize search
  //input
  cout<<"Enter a positive integer number that you want to find the square root for: ";

  do
    {
      cin>>search;//input value
      if(search<1||search>9000000){//input validation
	cout<<"Enter a positive integer number between 1 and 9000000: ";//false output
      }
    }while(search<1||search>9000000);//loop value
  return search;
}

int main()
{
  int num;//initialize main number
  int top;//initialize top
  int bottom;//initialize bottom
  double avg;//initialize average
  int root;//initialize root for full square root input answer
  double divide;//initialize step 2
  double divide2;//step 2 repeat
  double ans;//final answer

  num=getInt();//call getInt
  //find top number
  while(top*top<num){
    top++;
  }
  bottom=top-1;//find bottom
  //cout<<top<<endl;
  
  //for loop top
  if(top*top==num){
    root=top;//convert top to root
    cout<<root<<" is the square root of "<<num<<endl<<endl;//answer is num is a full square root
  }
    
  else
    {
      int closer;//initialize the closer number to num
      //check which number is closer
      if(top*top-num>num-bottom*bottom){
	closer=bottom;
      }
      else{
	closer=top;//else statement
      }
      cout<<"Start at "<<closer<<endl;//opening statement
      divide=(double)num/closer;//step 2
      avg=(double)(divide+closer)/2;//step 3


      //step 2 repeat
      divide2=(double)num/avg;
      //step 3 repeat
      ans=(double)(divide2+avg)/2;

      cout<<"The square root of "<<num<<" is "<<ans<<endl;//the square root output
      cout<<"The square of the square root is "<<num<<endl<<endl;//the base value output
    }
 

    return 0;
}


  
  

