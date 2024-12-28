#include<iostream>
using namespace std;
void showprogInfo();

void getInfo(string &name, char &gender, int &age);

bool verifyEligibility(char gender, int age, string name);

void showEligibility(string name, bool check);

int main()
{
  string name;
  char gender;
  int age;

  showprogInfo();
  getInfo(name,gender,age);
  bool check=verifyEligibility(gender,age,name);
  showEligibility(name, check);
  return 0;
}

void showprogInfo()
{
  cout<<"***************************"<<endl;
  cout<<"This program will tell you if you're eligible to join the military."<<endl;
  cout<<"****************************"<<endl;
}

void getInfo(string &inName, char &gender, int &age){

cout<<"Enter first name: ";

cout<<"Enter gender: ";
cin>>gender;

cout<<"Enter age: ";
cin>>age;
}

bool verifyEligibility(char gender, int age, string name)
{
  if(gender=='m'&&age>=18)
  return true;
    else
  return false;
  }

void showEligibility(string name, bool check)
{
  // cout<<"Dear " <<name<<endl;
  if(check==true)
    cout <<"Dear "<<name<< " Please consider joining the military" << endl;
  else
    cout << "Thank you for applying." << endl;
}

