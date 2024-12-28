//program #30

#include <iostream> //outputInvoice1 uses cout                                            
#include <iomanip>  //for setw                       
using namespace std;


double calcShipping(int tw)//you may not change parameters  
{
  double cost;//store cost

  double fixed=5.0;
  double first=.1;//price if weight is above 25
  double second=.07;//price if weight is above 50
  double extra=2.5;//2.5 dollars added to the fixed price. With 25 pounds between 25 and 50, the extra price would be 2.5 dollars. This would help calculate price above 50

  if(tw<=25){
    cost=fixed;//price equal or below 25
  } else if(tw>=26&&tw<=50){//price between 50 and 25
    cost=fixed+(tw-25)*first;
  } else if(tw>50){
    cost=fixed+extra+(tw-50)*second;//extra accounts for cost between 25 and 50 pounds
  }

  return cost;//returns the cost for shipping cost

}
 
void outputInvoice2(double total, double disc, double tax, double ship)//you may not change parameters  
{
  double finalDue=total-disc+tax+ship;//calculate the final price with the inputs
  
  cout<<endl;//This is the outputs. Right makes sure the dollar sign is right alligned.
  cout<<left<<setw(20)<<"TOTAL SALE AMOUNT: "<<right<<"$"<<right<<setw(10)<<fixed<<setprecision(2)<<total<<endl;
  cout<<left<<setw(20)<<"DISCOUNT: "<<right<<"$"<<right<<setw(10)<<fixed<<setprecision(2)<<disc<<endl;
  cout<<left<<setw(20)<<"SALES TAX: "<<right<<"$"<<right<<setw(10)<<fixed<<setprecision(2)<<tax<<endl;
  cout<<left<<setw(20)<<"SHIPPING: "<<"$"<<right<<setw(10)<<fixed<<setprecision(2)<<ship<<endl;
  cout<<left<<setw(20)<<"TOTAL DUE: "<<"$"<<right<<setw(10)<<fixed<<setprecision(2)<<finalDue<<endl;
  cout<<endl;

}



