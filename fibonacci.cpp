#include<iostream>
using namespace std;

int main()
{
  int i;//initialize
  int num;//initialize numbers
  int fab;//initialize fibonacci numbers
  int fab1;//initialize first fibbonici variable
  int fab2;//initialize second fibbonici variable 

  //input number
  cout<<"Enter the number of fibonacci numbers you want to see (N >= 3): ";
  cin>>num;
  //set fab variables
  fab1=1;
  fab2=0;
  
  //check input validation
  while(num<=2){
    //if(num<=2){
    //cout<<"rejected"<<endl;
    cout<<"Enter the number of fibonacci numbers you want to see (N >= 3): ";
    cin>>num;
  }
    

  //opening of fibbonici number
  cout<<endl;  
  cout<<"0 1 ";

  //for loop to calculate fibbonaci numbers and how high they go
  for(i=2;i<num;i++){
  fab=fab1+fab2;
  fab2=fab1;
  fab1=fab;
  

  //output fibbonaci numbers
  cout<<fab<<" ";
  
 }
 cout<<endl<<endl;
 
 return 0;
}
      
