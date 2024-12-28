/********************************************************************
Ryan Kian-Zadeh
cs111
asignment 5-2 phase 2
11/2/2024

This program will create a recipet with help from included files
******************************************************************/
#include<iostream>
#include<iomanip>
using namespace std;
#include "input.h"
#include "/cs/slott/hw/7mailOrderA.h"
#include "/cs/slott/hw/62mailOrderB.h"
#include "/cs/slott/hw/mailOrderC.h"
//set customer info and parameters
void getCustomerInfo(int &acc, int &month, int &day, int &year, char &cc){
  //range for account number and input validation
  cout<<"Enter an account number: ";
  acc=getInt(1000, 9999, "An account number must be 1000 - 9999. Enter again: ");
  //range for month and input validation
  cout<<endl;
  cout<<"Enter a month: ";
  month=getInt(1,12, "A month must be 1 - 12. Enter again: ");
  cout<<endl;
  //range for day and input validation
  cout<<"Enter a day: ";
  day=getInt(1,31, "A day must be 1 - 31. Enter again: ");
  cout<<endl;
  //range for year and input validation
  cout<<"Enter a year: ";
  year=getInt(2000,2100, "A year must be 2000 - 2100. Enter again: ");
  cout<<endl;
  //check county code and input validation. Same for above.
  cout<<"Enter a county code. Enter S, O or L: ";
  while(cc!='S'&&cc!='O'&&cc!='L'){
    cin>>cc;
    if(cc!='S'&&cc!='O'&&cc!='L'){
      cout<<"Invalid county code. Enter uppercase S, O or L: ";
    }
  }
  cout<<endl;
}
//set getItems info and parameters
void getItemsInfo(double &price, double &totalPr, int &weight, int &tw){

  char YN='Y';//internal variable
  //opening input
   cout<<"Do you want to order an item? Enter Y or N: ";
  
  while(YN=='Y')
    {

      //cout<<"Do you want to order another item? Enter Y or N: ";
      YN=getYN("Invalid response. Enter Y or N: ");
      if(YN=='Y'){
	//input pirce and set range and collect total price
	cout<<endl;
	cout<<"\tEnter a price: ";
	price=getDouble(0.00,999.99,"\tA price must be between 0.00 and 999.99. Enter again: ");
	totalPr+=price;
	cout<<endl;

	//input weight and tab, and weight range and collect total weight
	cout<<"\tEnter a weight: ";
	weight=getInt(0,99, "\tA weight must be between 0 and 99. Enter again: ");
	tw+=weight;
	cout<<endl;

	cout<<"Do you want to order another item? Enter Y or N: ";//This loops to top of the loop
      }
    }
}

  
  
int main()
{
  
  int acc;//account number
  int month;//initialize month in customer info
  int day;//initialize day in customer info
  int year;//initialize year in customer info 
  char cc;//initialize country code
  double price;//initialize customer price
  int weight;//initialize item weight
  int tw;//initialize total weight
  double totalPr;//initialize sum of prices
  double total;//final price after discounts
  double disc;//initialize discount
  double tax;//initialize taxes
  double ship;//initialize shipping cost

  getCustomerInfo(acc, month, day, year, cc);//call customerInfo
  getItemsInfo(price,totalPr,weight,tw);//call item info
  disc=calcDiscount(totalPr, month);//call and set discount
  ship=calcShipping(tw);//call and set shipping cost
  tax=calculateSalesTax(totalPr,disc,cc);//call and set sales tax
  outputInvoice1(acc, cc, month, day, year);//call output invoice 1
  outputInvoice2(totalPr, disc, tax, ship);//call output invoice 2

 
  return 0;
}
