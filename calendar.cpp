 int fahrenheit;
  int iCelsius;
  char temp;
  
  cout<<"Would you like to view the highest temperature in Celsius or Fahrenheit? Enter C or F: ";
  //the getCF function will validate what to do depending on the input
  temp=getCF("Invalid type. Please enter C or F: ");
    
  if(temp=='C')
    for(int i=0;i<SIZE;i++){//runs through the array
      fahrenheit=arr[i];//stores array temp
      celsius =(fahrenheit-32)*5.0/9;//convert fahrenheit to celsius
      iCelsius=(int)(celsius+0.5);//round celsius
      arr[i]=iCelsius;//put celsius in array
    }
}

/****************************************************
Month stores the month year of the data file
days is the days skipped
array is the temperature

This function prints the array
 ****************************************************/
void printCalender(string month, int days, int arr[])
{
  cout<<endl;
  cout << "Highest temperature for " << month << endl;
  for (int i = 0; i < HEADING_SIZE; i++)//prints the header for day names
    {
      cout << " " << HEADING[i];
    }
  cout << endl;
  
  for(int i=0;i<days;i++){//puts lines for the days skiped
    cout<<" ___";
  }

  int newSize=SIZE;
  if(month=="February 2022")
    newSize=TEMP;
  
  for (int i = 0; i < newSize; i++)//prints the array temperature and creates a new line every seven days
    {
      cout<<right<<setw(4)<< arr[i];//prints array left alligned
      
      if ((i+1+days) % 7 == 0)//makes new line after seven numbers
	cout << endl;
    }
  cout<<endl;
}

int main()
{

  int arr[SIZE];//initialize array
  string month;//intialize month
  int days;//intialize days
  char check;//initialize check

  do{
    getData(month, days, arr);//calls get data
    temperature(arr,SIZE);//calls temperature
    printCalender(month, days, arr);//calls print calender

    cout<<endl;
    cout<<"Would you like to see another month?: ";//asks if the user wants the run through the program again
    check=getYN("Invalid response. Enter Y or N: ");//input validation
    
  }while(check=='Y');//does above under these conditions
  cout<<endl;

  return 0;
}
