/*****************************************************************************
This template was written by Kazumi Slott for CS111
10-17-2018

This main tests getInt(), getDouble() and getYN() in input.h
*****************************************************************************/
#include <iostream>
#include<iomanip>
using namespace std;
#include "input.h"  //include input.h

int main()
{
  int n;//initialize n getInt age
  int t;//initialize t getInt test score
  double gpa;//initialize get GPA
  char YN;//initialize YN character

  
  cout << "Enter an age: ";//input age
  n = getInt(0, 200, "An age must be between 0 and 200. Enter again: ");//show age range and message
  cout << "age = " << n << endl<<endl;//output age

  cout<< "Enter a test score: ";//input score
  t= getInt(0, 100, "A test score must be between 0 and 100. Enter again: ");//show test range and false message
  cout<<"score = "<<t<<endl<<endl;//output score
  //Test getInt()
  //get a test score. It should be between 0 and 100.

  cout<<"Enter your gpa: ";//input gpa
  gpa=getDouble(0.00, 4.00, "A GPA must be between 0.00 and 4.00. Enter again: ");//show GPA range and false message
  cout<<"gpa = "<<fixed<<setprecision(2)<<gpa<<endl<<endl;
		
  //Test getDouble()
  //get a gpa. It should be between 0.00 and 4.00.

  cout<< "Are you a college student? Enter Y or N: ";//input
  YN=getYN("Your response must be Y or N. Enter again: ");//false message
  cout<<"ans = "<<YN<<endl<<endl;//output

  //Test getYN()
  //Ask if the user is a college student. It should only accept Y, y, N or n.
  //getYN() returns Y or N only.


  return 0;
}
