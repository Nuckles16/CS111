#include<iostream>
#include<iomanip>
#include "input.h"
using namespace std;

/************************
sales is array for number of salsa sales
SIZE is constant for array size
salsa is the names of the salsa types

This function will input the amount of salsas sold and reject bad inputs
*************************/

void fillJarsSoldArray(int sales[],int SIZE, const string salsa[])
{  
  int num;//initiailize num
  //runs through the array
  for(int i=0;i<SIZE;i++){
    
    cout<<"Enter the number of jars sold for "<<salsa[i]<<": ";//add input to salsa array
    num=getInt(0, 1000000, "\tInvalid. Enter a number betweeen 0 and 1000000: ");//use getInt for invalid input

    sales[i]=num;//put num into sales array
    cout<<endl;
  }
}

/*******************************
sales is array for number of salsa sales
SIZE is constant for array size
salsa is the names of the salsa types

This function will print array for sales and salsa
*************************************/

void printSales(int sales[], int SIZE, const string salsa[])
{
  //runs through the array
  for(int i=0; i<SIZE;i++){
    cout<<left<<setw(7)<<salsa[i]<<right<<setw(8)<<sales[i]<<endl;//salsa on left and sales on right
  }
}

/*******************************
sales is array for number of salsa sales
SIZE is constant for array size

This function will add the total number of sales and return it
********************************/

int getTotal(int sales[],int SIZE)
{
  int total=0;//set total to zero
  //runs through the array
   for(int i=0;i<SIZE;i++){
     
     total+=sales[i];//adds sales to total
   }
   
   return total;
}

/***************************
sales is array for number of salsa sales
SIZE is constant for array size
highest index is the highest number in index
lowest index is lowest number in index

This program function will determine the biggest and lowest numbers in index
***********************/
void getHighestLowestSelling(int sales[], int SIZE, int &highestIndex, int &lowestIndex)
{
  //runs through array
  for(int i=0;i<SIZE;i++){
    if(sales[i]>sales[highestIndex]){//checks if sales array is great than the biggest index
      highestIndex=i;//new highest index
    }
    if(sales[i]<sales[lowestIndex]){//check if sales array is smalles than the smallest index
      lowestIndex=i;//new lowest index
    }
  }
}
    
  

int main()
{
  const int SIZE=5;//const array size
  int sales[SIZE];//initiailze sales array
  string salsa[SIZE]={"mild","medium","sweet","hot","zesty"};//initialize salsa array
  
  fillJarsSoldArray(sales,SIZE,salsa);//call function
  printSales(sales,SIZE,salsa);//call function
  int total=getTotal(sales,SIZE);//initiailze function
  
  int highestIndex,lowestIndex;//initialize variables
  getHighestLowestSelling(sales, SIZE, highestIndex,lowestIndex);//call get highest lowest

  //prints total, lowest and highest
  cout<<endl;
  cout<<"The total number of jars sold is "<<total<<endl;
  cout<<"The highest selling type is "<<salsa[highestIndex]<<endl;
  cout<<"The lowest selling type is "<<salsa[lowestIndex]<<endl;
  cout<<endl;
  
  return 0;
}

