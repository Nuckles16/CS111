/*****************************************************************
CS111
Template prepared by Kazumi Slott
11-1-16
Lab on 2D arrays
*****************************************************************/ 
#include <iostream>
#include <iomanip>
using namespace std;

//declare 2 constants for the sizes of the 2 dimensional array
const int NUM_STU  =5;//number of students
const int NUM_TEST =3;//number of tests

void fillArray(int score[][NUM_STU]);
void showTable(const int score[][NUM_STU]);

int main()
{
  //declare the 2 dimensional array and initialize the array using the initialization list
  int score[NUM_TEST][NUM_STU];

  //call functions
  fillArray(score);
  showTable(score);

  return 0;
}
/*************************
score is array name
NUM_STU is is number of student

This function will enter test scores for each students
*******************************************/

void fillArray(int score[][NUM_STU])
{
  for(int test=0;test<NUM_TEST;test++)
    {
      cout<<"Enter scores for Test #"<<test+1<<endl;//allows user to enter number

      for(int stu=0;stu<NUM_STU;stu++)
        {
          cout<<"\tStudent #"<<stu+1<<": ";//prints student number
          cin>>score[test][stu];//enters student number
	}
      cout<<endl;
    }
}

/*************************************
score is array name
NUM_STU is number of students

This function will print the score table
************************************/

void showTable(const int score[][NUM_STU])
{
  //int total=0;
  //print student number and test number
   cout << setw(10) << "Test#" << setw(10) << "Stu 1" << setw(10) << "Stu 2" << setw(10) << "Stu 3"
  << setw(10) << "Stu 4" << setw(10) << "Stu 5" << setw(10) << "Average" << endl;

   for(int test=0;test<NUM_TEST;test++)
     {
       int total=0;//set total
       cout<<setw(10)<<test+1;//label test number
      
     for(int stu=0;stu<NUM_STU;stu++)
      {
	cout<<setw(10)<<score[test][stu];//alligns test scores
	total+=score[test][stu];//adds total
      }
     double avg=(double)total/5;//creates average
     cout<<fixed<<setprecision(1)<<setw(10)<<avg<<endl;//prints average for each test
     }
   
   cout<<setw(10)<<"Average";
   for(int stu=0; stu<NUM_STU;stu++){
     int total=0;//set total to zero

     for(int test=0;test<NUM_TEST;test++)
       {
	 total+=score[test][stu];//adds each students total score
       }
    
     double avg=(double)total/NUM_TEST;//makes average
     cout<<fixed<<setprecision(1)<<setw(10)<<avg;//print student average
   }
   cout<<endl<<endl;
}  
