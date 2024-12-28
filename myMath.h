/******************************
b is the base
e is the exponent
This function will calculate b^e and return the power
*******************************/

int pow(int b, int e)
{
  int ans = 1;

  for(int i=1; i<=e; i++)
    ans*=b;

  return ans;
}
/***********************************************************
pos is positive
This function will convert negitive inputs to positive
***********************************************************/

double fabs(double pos)
{
  if(pos<0)
    pos=pos+(-1*(pos*2));

  return pos;
}
/***************************************************
solve is what the number rounds to.
This function rounds the input to the nearest integer
****************************************************/
int round(double solve) 
{
  int total = (int)(solve+0.5);

    return total;  
}
/******************************************************
n is number
This function will check if numbers are even or odd
********************************************************/
bool isPrime(int n)
 {
    for(int d=2;d<=n/2;d++)
      {
        
        if(n%d==0){
          return false;
        }
      }
    return true;
 }

double sqrt(int num)
{
  int Mnum;//initialize main number
  int top=1;//initialize top
  int bottom;//initialize bottom
  double avg;//initialize average
  int root;//initialize root for full square root input answer
  double divide;//initialize step 2
  double divide2;//step 2 repeat
  double ans=0;//final answer
  int closer;
  
  //find top number
  while(top*top<num){
    top++;
  }
  bottom=top-1;//find bottom
  //cout<<top<<endl;

  //for loop top
  if(top*top==num){
    root=top;//convert top to root
  }

  else
    {
      //initialize the closer number to num
      //check which number is closer
      if(top*top-num>num-bottom*bottom){
        closer=bottom;
      }
      else{
        closer=top;//else statement
      }
      //cout<<"Start at "<<closer<<endl;//opening statement
      divide=(double)num/closer;//step 2
      avg=(double)(divide+closer)/2;//step 3


      //step 2 repeat
      divide2=(double)num/avg;
      //step 3 repeat
      ans=(double)(divide2+avg)/2;

      


    }
  return ans;
}


