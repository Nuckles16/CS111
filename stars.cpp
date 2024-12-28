/**********************************
Ryan Kian-Zadeh
HMWK 4-1
10/11

This program will enter stars.
**********************************/

#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
  int n;
  int row;
  int col;
  
  cout<<"Enter the number of rows: ";
  cin>>n;

  if(n<=0){
    cout<<"This program works for n>=1 only."<<endl<<endl;
    return 0;
  }

  for(int row=1;row<=n;row++){
    for(int col=1;col<=(n-row);col++)
        cout<<" ";
    
    for (int col=1;col<=row;col++)
	cout<<"*";
    //This goes to next line
    cout<<endl;    
  }
  cout<<endl;
  
  return 0;
}
