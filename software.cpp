/******************************************************
Ryan Kian-Zadeh
CS111
HMWK 3-1
10-4-2024

This program will determine how much it takes to buy company stocks
*********************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
  string date;//the date of purchase
  string company;//the company name
  int quantity;//how much is being bought
  double discountPercent;//percent discounted
  double discount;//price discounted
  double priceBeforeDiscount; //cost of item before discount
  double itemPrice; //cost of item
  double totalDue;//total cost
  
  //input todays date
  cout << "Enter today's date (mm/dd/yy): ";
  cin >> date;

  //input the company you want to make purchases in
  cin.ignore(100, '\n');
  cout << "Enter your company name: ";
  getline(cin, company);

  //input how much of the company are you purchasing
  cout << "Enter the quantity you would like to purchase: ";
  cin >> quantity;
  cout<<endl;

  //check 0 quantity
  if(quantity==0){
    cout << "Hope you decide to buy our software in the future"<<endl<<endl;
    return 0;
  }
  //check negitive quantity
  if(quantity<0){
    cout << "Invalid quantity"<<endl<<endl;
    return 0;
  }  
  
  //set itemPrice 
  itemPrice=99;
  
  //calculate discount between 10 and 19
  if(quantity>=10 && quantity<=19)
    discountPercent=20;
  //calculate discount between 20 and 49
  else if(quantity>=20 && quantity<=49)
    discountPercent=30;
  //calculate discount between 50 and 99
  else if(quantity>=50 && quantity<=99)
    discountPercent=40;
  //calculate discount equal and above 100
  else if(quantity>=100)
    discountPercent=50;

  //calculate price
  priceBeforeDiscount = quantity*itemPrice;

  //calculate discount
  discount = priceBeforeDiscount*discountPercent/100;

  //calculate total amount
  totalDue=priceBeforeDiscount-discount;

  //print invoice title
  cout << "Invoice for "<<company<<endl;
  
  //print formated date location
  cout << setw(41)<<right<<date<<endl<<endl;
  
  //first line of invoice
  cout<<left<<setw(30)<< "Price before discount"<<left<<setw(1)<<'$'<<right<<setw(10)<<fixed<<setprecision(2)<<priceBeforeDiscount<<endl;

  //Secound line of invoice
  cout<<left<<setw(30) <<"Discount"<<left<<setw(1)<<'$'<<right<<setw(10)<<fixed<<setprecision(2)<<discount<<endl;

  //Third line of invoice
  cout<<left<<setw(30) <<"Total Due"<<left<<setw(1)<<'$'<<right<<setw(10)<<fixed<<setprecision(2)<<totalDue<<endl<<endl;
  
  return 0;
}
    
  
  
  
  
