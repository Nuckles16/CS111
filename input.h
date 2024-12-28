/*****************************************************************************
This template was written by Kazumi Slott for CS111
10-18-19

getInt asks for an integer and rejects bad inputs outside the range.
getDouble asks for a decimal number and rejects bad inputs outside the range.
getYN asks for Y or N and reject bad inputs other than Y, y, N or n.
*****************************************************************************/
#include <iostream>
using namespace std;

int getInt(int min, int max, string msg)
{
  int n; //user's input
  cin >> n;

  while(n < min || n > max) // the user's input was outside the range
    {
      cout << msg;  //show the message to the user
      cin >> n;     //read a new input
    }

  return n; //return a good value that is within the range (between min and max enclusive)
}

int getTest(int min, int max, string msg)//user input outside of range
{
  int t;//user input
  cin>>t;

  while(t>=min&&t<=max)//check if input was outside of range
    {
      cout<<msg;//show false message
      cin>>t;//read new input
    }
  return t;//return value in range
}

double getDouble(int min, int max, string msg)//input out of range                                                                                                          
{                                                                                                                                              

  double gpa;//user input
  cin>>gpa;
  
  while(gpa<min||gpa>max)//user input outside of range
    {
      cout<<msg;//show user message
      cin>>gpa;//read new input
    }

  return gpa;//return value in range
}

char getYN(string msg)//input out of range
{

  char YN;
  bool validInput=false;//false input processer

  while(!validInput)//check validity
    {     
      cin >> YN;//read new input
      if(YN=='Y'||YN=='N'||YN=='y'||YN=='n'){//check if correct
	validInput=true;//valid input
      }else
	{
	  cout<<msg;//show message
      }
 
    }
	
  if(YN=='y'||YN=='n')//convert lower to upper
    YN-=32;
  
  return YN;//return value stated in if

}

char getCF(string msg)//input out of range
{

  char CF;
  bool validInput=false;//false input processer

  while(!validInput)//check validity
    {
      cin >> CF;//read new input
      if(CF=='C'||CF=='F'||CF=='c'||CF=='f'){//check if correct
        validInput=true;//valid input
      }else
        {
          cout<<msg;//show message
      }

    }

  if(CF=='c'||CF=='f')//convert lower to upper
    CF-=32;

  return CF;//return value stated in if

}



