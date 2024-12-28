/****************************************************************************************
Ryan Kian-Zadeh
CS111
time
9/17/24

Enter a time in seconds and convert it into hours, minutes and seconds.
*****************************************************************************************/

#include <iostream> //for cin, cout
using namespace std;

int main()
{
  //declare variables
  int seconds; //seconds in time
  int hours;//hours in time
  int minutes;//minutes in time
  int iSeconds;//remaining seconds
  const int CM_hours= 3600;//number of seconds in a hour
  const int CM_minutes=60;//number of seconds in a minute
  const int CM_seconds=1;//value of seconds

  //input time
  cout << "Enter the time in seconds: ";
  cin >> seconds;

  //calculate hours minutes and seconds
  hours=seconds/CM_hours;
  seconds=seconds%CM_hours;
  minutes=seconds/CM_minutes;
  seconds=seconds%CM_minutes;
  iSeconds=seconds/CM_seconds;

  //output variables
  cout << endl;
  cout << hours << " hours " << minutes << " minutes " << iSeconds << " seconds "<< endl;
  cout << endl;

  return 0;
}
  
