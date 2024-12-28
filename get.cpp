#include <iostream>
using namespace std;

//int getSum(int num1, int num2)
//{
    //int sum;

    //sum = num1 + num2;

    //return sum;
//}

const int SIZE=5;
int array[SIZE];

void fillArray(int ar[],int s){
    int num;

    for(int i=0;i<SIZE;i++){
        cout<<"Enter the number: ";
        cin>>num;

        ar[i]=num;
    }
}

void printArray(int ar[],const int s){
for(int i=0;i<SIZE;i++){
cout<<ar[i]<<" ";
//cout<<endl<<endl;
}
cout<<endl<<endl;
}

double getAvg(int ar[],int s){
    int total=0;
    double avg;

    for(int i=0;i<SIZE;i++)
        total+=ar[i];
        avg=(double)total/s;
    return avg;
}

void getLowHigh(int ar[],int s, int& low, int& high)
{
    for(int i=0;i<SIZE;i++){
        if(ar[i]>ar[high]){
            high=i;
        }
        if(ar[i]<ar[low]){
            low=i;
        }
    }
}


int main()
{
const int SIZE=5;
int array[SIZE];
//double avg;

int num;
int total;
double avg;
int fill;
int high,low;

fillArray(array,SIZE);   
avg=getAvg(array,SIZE);
getLowHigh(array,SIZE,high,low);

cout<<"The average is "<<avg<<":"<<endl;
cout<<"The highest number is "<<high<<" and the lowest number is "<<low<<": "<<endl;

    return 0;
}