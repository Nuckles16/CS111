/*****************************************
Ryan Kian-Zadeh
CS111
11/8/2024
HMWK 6-2

This program program will determine triangle type.
******************************************/
#include<iostream>
#include<iomanip>
#include "myMath.h"
using namespace std;

void showProg();//print showProg
void askPoint(int &x,int &y);//ask for user input
double calcDistance(int x1,int y1, int x2, int y2);//calculate distance between points
string checkTriangle(double distance1, double distance2, double distance3);//determines types of triangles

int main()
{
  int x1;//initialize x cordinate 1
  int y1;//initialize y cordinate 1
  int x2;//initialize x cordinate 2
  int y2;//initialize y cordinate 2
  int x3;//initialize x cordinate 3
  int y3;//initialize y cordinate 3
  double distance1;//initialize side length 1 
  double distance2;//initialize side length 2
  double distance3;//initialize side length 3
  string triangle;//contain triangle type

  showProg();//call showProg
  //asks and calls cordinates for each  point
  cout<<"Point 1"<<endl;
  askPoint(x1,y1);
  cout<<endl;
  cout<<"Point 2"<<endl;
  askPoint(x2,y2);
  cout<<endl;
  cout<<"Point 3"<<endl;
  askPoint(x3,y3);
  cout<<endl;

  //calls distances
  distance1=calcDistance(x1,y1,x2,y2);//different variables means different values entered into the equation
  distance2=calcDistance(x3,y3,x2,y2);
  distance3=calcDistance(x3,y3,x1,y1);
 
  //calse triangle type
  triangle=checkTriangle(distance1,distance2,distance3);
  //prints triangle type
  // cout<<endl;
  cout<<triangle;
  cout<<endl<<endl;
  
  return 0;
}
/*****************************************************
Prints opening statement
*******************************************************/
void showProg()
{
  cout<<endl;
  cout<<"***************************************************************"<<endl;
  cout<<"This program will ask you to enter 3 points of a triangle and"<<endl;
  cout<<"tell what kind of triangle it is. Please hit ENTER to continue."<<endl;
  cout<<"***************************************************************"<<endl;

  cin.ignore(1000,'\n');//will create a blank line under the print until user hits enter.
}
/*****************************************************
x is cordinate 
y is cordinate

Enters point cordinates
*****************************************************/
void askPoint(int &x,int &y)
{
  //asks for cordinates
  cout<<"\tEnter the x-cordinate: ";
  cin>>x;
  cout<<"\tEnter the y-cordinate: ";
  cin>>y;
  //cout<<endl;
}
  
/***************************************************
xFrom is x1 cordinate
yFrom is y1 cordinate
xTo is x2 cordinate
yTo is y2 cordinate

calculates distance between pointes
***************************************************/
double calcDistance(int xFrom,int yFrom, int xTo, int yTo)
{
  double length;//initialize side length
  int a=pow((xFrom-xTo),2);//uses power function in h file to calculate a from x cordinates
  int b=pow((yFrom-yTo),2);//uses power function to calculate b from y cordinates
  //cout<<a<<endl;
  //cout<<b<<endl;
  
  length=sqrtb(a+b);//adds a and b and uses the sqrt function in h file to find hypotnuse length
  
  return length;
}
/*************************************************
length 1 is side 1 length
length 2 is side 2 lenght
length 2 is side 2 lenght

determines triangle type from number of equal sides
************************************************/
string checkTriangle(double length1, double length2, double length3)
{
  int same=0;//same is initialize and set for zero. This id the number of equal sides
  string triangle;//initializes triangle
  // cout<<"Length 1:"<<length1<<"  length 2:"<<length2<<"  length 3:"<<length3<<endl;
  if(fabs(length3-length1)<0.00001)//checks sides 3 and 1 if there equal
    same+=1;
      
  if(fabs(length3-length2)<0.00001)//cheks if sides 3 and 2 are equal
    same+=1;
       
  if(fabs(length1-length2)<0.00001)//check if sides 2 and 1 are equal
    same+=1;
  //switch checks what number of sames equal what type of triangle  
  switch(same){
    case 0:
      triangle="This triangle is scalene";
      break;
    case 1:
      triangle="This triangle is isosceles";
      break;
    case 3:
      triangle="This triangle is equilateral";
      break;
   }
  return triangle;
}


