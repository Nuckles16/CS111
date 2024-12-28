/****************************************************
Ryan Kian-Zadeh
cs111
11/4/2024
lab 6-1

This program will read unknown number of positive and negitive numbers and outpu "even" or "odd"
*******************************************************************/

#include<iostream>
using namespace std;

//bring functions to main
void fillArray(int ar[], int s);
void printArray(const int ar[], int s);
void reverseArray(int ar[], int s);
double findAvg(const int ar[], int s);
int findHighest(const int ar[], int s);
int sequentialSearch(int ar[], int s,int key);
void selectionSortAscend(int array[], int N);
void selectionSortDescend(int array[], int N);
void doubleArray(int ar[], int s);
void showBarGraph(int ar[], int s);


int main()
{
  const int SIZE=5;//set size
  int array[SIZE];//initialize array
  int key;//initialize key for 
  int B;
  double avg;
  int max;
  int choice;
  
  do
    {//print opening
      cout<<"----------------------------------------------------------------------" << endl;
      cout<<"1) fill 2) print 3) reverse 4) average 5) highest 6) double 7) bar graph 8) selection sort ascending 9) selection sort descending 10) sequential search 13) quit"<<endl;
      cout<<"----------------------------------------------------------------------" << endl;
      //chose which choice in switch
      cout<< "Enter your choice: ";
      cin>>choice;
      cout<<endl;

      switch(choice)
	{
	case 1: fillArray(array, SIZE);
	  break;
	case 2: printArray(array, SIZE);
	  break;
	case 3: reverseArray(array, SIZE);//reverse index numbers
	  break;
	  //cout<<"Enter the key: ";
	case 4:
	  avg=findAvg(array, SIZE);//show average
	  cout<<"The average number is "<<avg<<endl<<endl;
	  break;
	case 5:
	  max=findHighest(array, SIZE);//show highest index number
	  cout<<"The highest number is "<<max<<endl<<endl;
	  break;
	case 6: doubleArray(array, SIZE);//double array
	  break;
	case 7: showBarGraph(array, SIZE);//show stars on graph
	  break;
	case 8: selectionSortAscend(array, SIZE);//arrange lowest to highest
	  break;
	case 9: selectionSortDescend(array, SIZE);//arrange highest to lowest
	  break;
	case 10: //find which key has index
	  cout<<"Enter the key: ";
	  cin>>key;
	  cout<<endl;

	  B=sequentialSearch(array, SIZE, key);
	  if(B==-1){
	    cout<<key<<" was not found.";
	    cout<<endl<<endl;
	  }
	  else{
	    cout<<key<<" was found at index "<<B<<"."<<endl<<endl;
	  }
	  break;
	case 13: cout<<"Thank you for using our system."<<endl<<endl;//terminate loop
	  break;  
	default:cout<<"Invalid choice"<<endl<<endl;  
	}
    }while(choice!=13);

  return 0;
}

/*******************
ar is the array
s is the size

This function will allow user to input numbers into the array
****************************/
void fillArray(int ar[], int s)
{
  int num;//initiailze num
 
  for(int i=0;i<s;i++)
    {
      cout<<"Enter a number: ";//allows user to enter number
      cin>>num;

      ar[i]=num;//these numbers will be the array
    }
  cout<<endl;
}

/**********************************
ar is the array
s is the size

This function will print the array
***********************************/
void printArray(const int ar[], int s)
{
  // cout<<endl;
  cout<<"The numbers in the array are ";
  for(int i=0;i<s;i++)//shows five numbers
    cout<<ar[i]<<" ";//puts array after the above cout

  cout<<endl<<endl;
}

/************************
ar is the array
s is the size

This function will reverse the array
*************************/
void reverseArray(int ar[], int s)
{
  for(int L=0, R=s-1;L<R;L++, R--){//take the last array number and put it in front
    int temp=ar[L];//store L
    ar[L]=ar[R];//put right number on the left
    ar[R]=temp;//put right number in temp
  }  
}

/************************
ar is the array
s is the size

This function will find the average of the array
***************************/

double findAvg(const int ar[], int s)
{
  int total = 0;// set total
  double avg;//initialize avg
  for(int i = 0; i < s; i++)
    total += ar[i];//add array to total
  avg=(double)total/s;//calculate average

  return avg;
}

/************************
ar is the array
s is the size

This function will find the highest number in the array
*************************/

int findHighest(const int ar[], int s)
{
  int highestIndex = 0; //Assume the first index(slot) has the highest score at the beginning
  //check each score to the highest so far
  for(int i = 1; i < s; i++){
    if(ar[i] > ar[highestIndex]) //the current score is highest so far (among the scores checked)
      highestIndex = i; //keeps track of the index that contains the highest score so far
  }
  return ar[highestIndex];
}

/************************
ar is the array
s is the size

This function will double each number in the array
************************/

void doubleArray(int ar[], int s)
{

  for(int i=0;i<s;i++){//create the array
  
    ar[i]=ar[i]*2;//double every index number
  }
}

/************************
ar is the array
s is the size

This function will print a star for every ten in each array number
**************************/

void showBarGraph(int ar[], int s)
{
  for(int i=0; i<s;i++)//create slots
    {
      cout<<"Slot "<<i<<": ";
      
    
      int stars=ar[i]/10;//every ten in an index number is added to stars
      for(int j=0;j<stars;j++){//create stars equal to stars variable
	cout<<"*";
      }
      
      cout<<endl;
    }
  cout<<endl;
}

/************************
ar is the array
s is the size

This function will find the index number that's equal to the key
*************************/

int sequentialSearch(int ar[], int s,int key)
{
  int B=-1;// set b
  for(int k=0;k<s;k++){//check index for key
    if(ar[k]==key){//what to do when key is found
      B=k;
    
    }
  }
  return B;
}

/************************
ar is the array
s is the size

This function will arrange the index from lowest to highest
************************/

void selectionSortAscend(int array[], int N)
{
  int lrgIndx; //the index of the largest value
  int temp; //temporary variable that holds the largest value

  //last is the last index in unsorted portion
  for(int last = N-1; last >= 1; last--)
    {
      lrgIndx = 0; //assume the first item is the largest
      //find the largest in unsorted portion ([0..last])
      for(int i = 1; i <= last; i++)
        {
          if(array[i] > array[lrgIndx]) //The current item is larger
            lrgIndx = i;
        }

      //swap the largest with the last item in the unsorted portion
      temp = array[lrgIndx];
      array[lrgIndx] = array[last];
      array[last] = temp;
    }
}

/************************
ar is the array
s is the size

This function will rearange the index from highest to lowest
**************************/

void selectionSortDescend(int array[], int N)
{
  int smIndx; //the index of the smallest value
  int temp; //temporary variable that holds the smallest value

  //last is the last index in unsorted portion
  for(int last = N-1; last >= 1; last--)
    {
      smIndx = 0; //assume the first item is the smallest 
      //find the smallest in unsorted portion ([0..last])
      for(int i = 1; i <= last; i++)
        {
          if(array[i] < array[smIndx]) //The current item is smallest
            smIndx = i;
        }

      //swap the smallest with the last item in the unsorted portion
      temp = array[smIndx];
      array[smIndx] = array[last];
      array[last] = temp;
    }
}

