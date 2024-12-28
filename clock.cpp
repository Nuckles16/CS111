/********************************************************************************************************************
Ryan Kian-Zadeh
cs111
Clock assignment
9/17/2024

This program will take the time and determine the hour and minute hand on the clock
**************************************************************************************************************************/

#include <iostream>
using namespace std;

int main()
{
  int hours; //time in hours
  int minutes; //time in minutes
  double hourAngle; //hour hand
  double minuteAngle; //minute hand

  //input hours
  cout << "Enter hours: ";
  cin >> hours;

  hours=hours%12;

  //input minutes
  cout << "Enter minutes: ";
  cin >> minutes;

  //calculate hour angle. 30 and .5 are degrees
  hourAngle = 30*hours + .5*minutes; 
  //calculate minute angle. 6 is degrees
  minuteAngle = 6*minutes;

  //output
  cout << "The angle of the hour hand is : " <<hourAngle << endl;
  cout << "The angle of the minute hand is : " << minuteAngle <<endl;
  cout << endl;

  return 0;

}  
  
