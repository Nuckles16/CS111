/*************************************************************************************************************
Ryan Kian-Zadeh
CS111
problem 2
9/17/24

This program will convert celcius to fahrenheit
******************************************************************************************************************/

#include <iostream> //for cin, cout
using namespace std;

int main()
{
  //declare variables
  int Celsius; //temprature in celsius
  double Fahrenheit; //temprature in fahranheight
  int iFahrenheit; //fahranheight rounded

  //input variables
  cout << "Enter a temperature in Celsius: ";
  cin >> Celsius;
  //formula to convert celcius to fahrenheit
  Fahrenheit = (Celsius*(9.0/5))+32;
  //round fahrenheit
  iFahrenheit = (int)(Fahrenheit+0.5);
  //output
  cout<<endl;
  cout << Celsius << " C = " << iFahrenheit << " F"<<endl;
  cout<<endl;

  return 0;
}

  
    
