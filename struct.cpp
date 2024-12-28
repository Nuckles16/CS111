#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;

//stores structure data
struct emp
{
  string fName;
  string lName;
  char gender;
  double hrRate;
  int id;
  int age;
};
//stores prototypes
const int SIZE = 100;
void readDate(emp mAr[], emp fAr[],int& mi,int& fi);
void printEmployee(const emp temp);
void printAllEmp(const emp temp[], int size);
void outfileArray(const emp temp[],int mAr);
int findOldest(const emp temp[], int mAr);
void giveRaise(emp (&temp)[],double raise,int size);
void giveRaiseToOneEmployee(double incRate,emp& temp);
void combineArray(emp allEmp[],emp mAr[], emp fAr[],int mi,int fi);
void findEmp(emp ar[],int size);
void sort(emp empArr[],int size);

int main()
{
  //const int SIZE = 100;
  emp mAr[SIZE];//sets range for male array
  emp fAr[SIZE];//sets range for female array
  int mi=0;//sets male
  int fi=0;//sets female
  int oldest;//intiailze oldest
  emp allEmp[SIZE*2];//combined array
  //calls completed array and number of male and female employees
  readDate(mAr,fAr,mi,fi);
  combineArray(allEmp,mAr,fAr,mi,fi);

  cout<<"------------------------------ readData() ------------------------------"<<endl;
  cout<<"There are "<<mi<<" male and "<<fi<<" female employees."<<endl;
  cout<<endl;
  cout<<"------------------------------ printEmployee() ------------------------------"<<endl;
  printEmployee(fAr[0]);

  cout<<endl;
  cout<<"------------------------------ printEmployee() ------------------------------"<<endl;

  printEmployee(mAr[0]);
  cout<<endl;
  cout<<"------------------------------ printAllEmp() ------------------------------"<<endl;
  printAllEmp(mAr,mi);
  cout<<endl;
  cout<<"------------------------------ printAllEmp() ------------------------------"<<endl;
  printAllEmp(fAr,fi);
  cout<<endl;
  cout<<"------------------------------ outfileArray() ------------------------------"<<endl;
  outfileArray(mAr,mi);
  cout<<endl;
  cout<<"------------------------------ outfileArray() ------------------------------"<<endl;
  outfileArray(fAr,fi);
  cout<<endl;
  cout<<"------------------------------ findOldest() ------------------------------"<<endl;
  //sets oldest to oldest function. This checks male array
  oldest=findOldest(mAr,mi);
  //prints oldest
  cout<<mAr[oldest].fName<<endl;

  cout<<endl;
  cout<<"------------------------------ giveRaise() ------------------------------"<<endl;
  //gives raise percent for female array and prints that array
  giveRaise(fAr,5.5,SIZE);
  printAllEmp(fAr,fi);
  cout<<endl;
  cout<<"------------------------------ giveRaise() ------------------------------"<<endl;
  //gives raise percent for male array and prints that array
  giveRaise(mAr,5.0,SIZE);
  printAllEmp(mAr,mi);
  cout<<endl;
  cout<<"------------------------------ giveRaiseToOneEmployee() ------------------------------"<<endl;
  giveRaiseToOneEmployee(2.0,fAr[1]);//raise percent of specific employee
  printEmployee(fAr[1]);//prints that person

  cout<<endl;
  cout<<"------------------------------ giveRaiseToOneEmployee() ------------------------------"<<endl;
  giveRaiseToOneEmployee(50.0,mAr[0]);//raise percent for specific employee
  printEmployee(mAr[0]);//prints first employee
  cout<<endl;

  cout<<" ------------------------------ combineArray() ------------------------------"<<endl;
  
  combineArray(allEmp,mAr,fAr,mi,fi);//combines male and female arrays into one
  printAllEmp(allEmp,mi+fi);
  cout<<endl;

  cout<<"------------------------------ findEmp() ------------------------------"<<endl;
  findEmp(allEmp, mi+fi);//checks male and female
  //cout<<endl;

  cout<<"------------------------------ findEmp() ------------------------------"<<endl;
  findEmp(allEmp, mi+fi);//checks male and female
  

  cout<<"------------------------------ sortEmployees() ------------------------------"<<endl;
  sort(allEmp,mi+fi);//call sort
  printAllEmp(allEmp,mi+fi);//prints male and female
  cout<<endl;
  
  return 0;
}

/****************************
empArr has the arrays of files
size is the range 
This program will sort people on the list in alphabetic order
****************************/

void sort(emp empArr[],int size){
 
  int lrgIndx; //the index of the largest value
  emp temp; //temporary variable that holds the largest value
    //last is the last index in unsorted area
  for(int last = size-1; last >= 1; last-- )
    {
      lrgIndx = 0; //assume the first item is the largest
      //find the largest in unsorted area ([0..last])
      for(int i = 1; i <= last; i++)
	{
	  if(empArr[i].fName > empArr[lrgIndx].fName) //The current item is larger, then keep the current index
	    lrgIndx = i;
	}
      //swap the largest with the last item in the unsorted area
      temp = empArr[lrgIndx];
      empArr[lrgIndx] = empArr[last];
      empArr[last] = temp;
    }
}

/****************************
empArr has the arrays of files
size is the range
This program will find a specific employe first and last name from character id
********************************/
void findEmp(emp ar[],int size){
  int id;//initialize id
  cout<<"Enter the employee id: ";//search for id
  cin>>id;

  bool found=false;//store false

  //checks if found is false
  for(int i=0;!found&&i<size;i++){
    if(id==ar[i].id){//checks if id exists
      found=true;
      cout<<endl;
      cout<<setw(10)<<ar[i].fName<<setw(10)<<ar[i].lName<<endl<<endl;
    }
  }
  //input validation
  if(!found){
    cout<<endl;
    cout<<"There is no employee with ID "<<id<<"."<<endl<<endl;
  }
      
}

/***************************************
empArr has the arrays of files
mAr is array with males
fAr is array with females
mi stores males
fi stores females

This program will combine male and female array to create an array to print both.
******************************************/

void combineArray(emp allEmp[],emp mAr[], emp fAr[],int mi, int fi)
{
  for(int i=0;i<mi;i++){
    allEmp[i]=mAr[i];
  }

  for(int i=0;i<fi;i++){
    allEmp[mi+i]=fAr[i];
  }
}

/***************************************
empArr has the arrays of files
mAr is array with males
fAr is array with females
mi stores males
fi stores females

This program will run through the program and store parts of the file into variables
******************************************/
void readDate(emp mAr[], emp fAr[],int& mi,int& fi)
{
 
  ifstream fin;//opens file
  fin.open("employees.dat");
  //file validation
  if(!fin)
    {
      cout << "file not found" << endl;
      exit(1);
    }
  emp temp;//stores data of employes
  //reads file data parts
  fin>>temp.fName;
  fin>>temp.lName;
  fin>>temp.gender;
  fin>>temp.hrRate;
  fin>>temp.id;
  fin>>temp.age;

  
  //counts number of males and females
  while(fin && fi<SIZE&&mi<SIZE)
    {
      if(temp.gender=='F'){
	fAr[fi]=temp;
	fi++;
	
      }
      
      else if(temp.gender=='M'){
	mAr[mi]=temp;
	mi++;
	
      }
      //checks data through to the if statements
      fin>>temp.fName;
      fin>>temp.lName;
      fin>>temp.gender;
      fin>>temp.hrRate;
      fin>>temp.id;
      fin>>temp.age;	
    }

  //closes file
  
  fin.close();
}

/****************************************
const emp temp stores the data file so it cant be changed

this function prints the information of a specific employee
*******************************************/
void printEmployee(const emp temp)
{
  //setw sets format
  cout<<left<<setw(10)<<temp.fName
      <<setw(10)<<temp.lName
      <<setw(10)<<temp.gender
      <<setw(10)<<fixed<<setprecision(2)<<temp.hrRate
      <<setw(10)<<temp.id
      <<setw(10)<<temp.age<<endl;
}
/*********************************
const emp temp stores the data file
size is the range of the file

this function prints all employees
**************************************/
void printAllEmp(const emp temp[],int size)
{
  //goes through all employees
  for(int i=0;i<size;i++)
    printEmployee(temp[i]);
}

/****************************
consts emp temp stores the data file to be accessed
mAr stores male information

This function asks the user what name to store an arrays first and last name characters
*************************************/
void outfileArray(const emp temp[],int mAr)
{
  ofstream fout;//brings in the file
  string name;//initializes name
  cout<<"Enter the output file name: ";//asks file name
  cin>>name;
  //opens file
  fout.open(name);
  //runs through array
    for(int i=0;i<mAr;i++)
      {
	//puts first and last name in file
	fout<<temp[i].fName<<", "<<temp[i].lName<<endl;
      }
    fout.close();//close file
}

/*********************************
const emp temp stores data file so it cant change
mAr stores male information

This function will find the oldest person in male array
 *********************************/

int findOldest(const emp temp[], int mAr)
{
  int high=0;//initiailze and set high
  //runs through male array
  for(int i=0;i<mAr;i++)
    {
      if(temp[i].age>temp[high].age)//compares current and new highest age
	high=i;//makes new highest age current
    }
  
  return high;
}

/*********************************
emp temp reference allows for the new data information to be stored
raise brings the amount of raise change to function
size is range

This program will calculate the new hr rate of the employees
**********************************/

void giveRaise(emp (&temp)[],double raise, int size)
{
  //runs through file
  for(int i=0;i<size;i++)
    temp[i].hrRate+=temp[i].hrRate*(raise/100);
}

/*******************************
emp temp brings new data information to variable
incRate stores the amount of change

This function determines how much a raise a specific employee gets
 ******************************/

void giveRaiseToOneEmployee(double incRate,emp& temp)
{
  temp.hrRate*=(incRate/100 +1);
}
