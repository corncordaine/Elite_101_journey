#include <stdio.h>
#include <math.h>
#include <stdlib.h>

float calculate_profit(float entry_price ,float exit_price, int const switcher)// switcher is read only since its used to calculate the conversion of the price difference
{
    return(fabs(entry_price - exit_price)* switcher);
}

float calculate_tax(float profit)
{
    return profit * (1 - 0.15);

}
//functions used in the swtch 2 //

//calculate balance based on market voatility//
float adjusted_balance(float const balance, float market_condition)// balance is constant since it is user defined and it will be used in calculation of the next position size function 
{
    if (market_condition ==1)
    {
        return balance * 0.6;
    }
    return balance;
}
// position size function//
void position_size_function(float const balance, float const percentage_risk,float const stop_loss_size,float *position_size, float *risk_amount,float *pip_value)//both percentage risk and stop loss are user defined and are not subjected to any logic or arithmetiic process furthermore its user defined,
{                                                                                                                                                   //changing percentage risk || stop loss will result to wring estimation and misinformation// 
    *risk_amount = balance * (percentage_risk/100);
    *pip_value = *risk_amount / stop_loss_size;
    *position_size = *pip_value/10;
}






int main()
{
int choice;
 while (1)
 {
    printf("\n===================================================\n");
    printf("                   TERMINAL MENU                      ");
    printf("\n===================================================\n");
    printf("    1. Run Composition Demo\n");
    printf("    2. Run Position sizing engine\n");
    printf("    3. Exit\n");
    printf("-----------------------------------------------------\n");
    printf(".................Enter your choice.....................\n");
    printf(">>>");
    if(scanf("%d",&choice) != 1 || choice < 1 || choice >3 )
    {
        printf("invalid choice\n");
        int c;
        while((c = getchar()) != '\n' && c != EOF);
        continue;

    }

 

        switch (choice)
        {
        case 1:
            printf("Running Composition Logic.....\n");

           float entry_price;
           float exit_price;
           int switcher = 1000;
           printf("Enter entry price\n");

            while(scanf("%f",&entry_price) != 1)
            {  
                printf("please enter a valid numerical price value\n");
                int c;
                while((c= getchar()) != '\n' && c != EOF);
            }

              printf("Enter exit price\n");

             while(scanf("%f",&exit_price)!= 1)
             {
               printf("please enter a valid numerical price value\n");
               int c;
              while((c= getchar()) !='\n' && c != EOF);
             }

   //calculate_tax(calculate_profit(x,y)) or   (calculate_tax ₀ calculate_profit(x,y))
              float value = calculate_tax(calculate_profit(entry_price,exit_price,switcher));

              printf("The profit-following the function logic (calculate_tax ₀ calculate_profit(x,y))-guideline is  %f", value);


            break;

            case 2:
            printf("initializing Position sizing engine.....................\n");

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

            break;
            
            case 3:
            {
            int assurance;
            printf("....................................................\n");
            printf("   Are you sure you want to Quit the program?\n");
            printf("             .......................\n");
            printf("  >>Yes - 1\n  >>No  - 2\n");
            printf(">>");
              while(scanf("%d", &assurance)!=1 || assurance !=1 && assurance != 2)
             {
                printf("Please enter an option in the menu");
                while(getchar() != '\n');
             }
             if (assurance == 2)
             {
              printf("returning to r=terminal menu........\n");
              break ;
             }

              printf("Exiting Program......");
              printf(".......     .....\n");
              printf("Program has been exited succesfully");
              exit(0);
        
            }
             
              
              

        default:
               printf("\n[!] Error: %d is not a valid option.\n", choice);
            
        }
 } 
 
 return 0;
}