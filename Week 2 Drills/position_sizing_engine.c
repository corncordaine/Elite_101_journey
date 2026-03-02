#include <stdio.h>
float adjusted_balance(float balance, float market_condition)
{
    if (market_condition ==1)
    {
        return balance * 0.6;
    }
    return balance;
}

void position_size_function(float balance, float percentage_risk,float stop_loss_size,float *position_size, float *risk_amount,float *pip_value)
{
    *risk_amount = balance * (percentage_risk/100);
    *pip_value = *risk_amount / stop_loss_size;
    *position_size = *pip_value/10;
}


int main()
{
    float balance;
    float percentage_risk;
    int market_condition;
    float stop_loss_size;
    float risk_amount = 0;
    float pip_value = 0;
    float position_size = 0;
    printf("Enter balance\n");

    while(scanf("%f",&balance) != 1)
    {
     printf("Please Enter a Valid balance\n");
     int c;
     while((c = getchar())!= '\n' && c != EOF);
    }
    printf("enter risk in percentage\n");

    while(scanf("%f",&percentage_risk) != 1)
    {
     printf("Please Enter a Valid risk value\n");
     int c;
     while((c = getchar())!= '\n' && c != EOF);
    }

    printf("  Enter market contition\n     Volatile - 1\n     Normal/Stable -2\n");
    while(scanf("%d",&market_condition) != 1 ||( market_condition != 1 && market_condition !=2))
    {
     printf("Please Enter a Valid market condition\n");
     int c;
     while((c = getchar())!= '\n' && c != EOF);
    }

     printf("enter stop loss zise\n");

    while(scanf("%f",&stop_loss_size) != 1)
    {
     printf("Please Enter a Valid stop loss size\n");
     int c;
     while((c = getchar())!= '\n' && c != EOF);
     
    }

     position_size_function((adjusted_balance(balance, market_condition)), percentage_risk, stop_loss_size, &position_size, &risk_amount, &pip_value);
  printf("Calculating .........\n");
  printf(" Your risk amount will be %f\n",risk_amount);  
  printf("loss or gain per pip will be %f\n",pip_value);
  printf("The recommended position size(lot_size) will be %f\n", position_size);

    
return 0;    

}