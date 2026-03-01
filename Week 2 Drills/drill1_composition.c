#include <stdio.h>
#include <math.h>
#include <windows.h>

float calculate_profit(float entry_price ,float exit_price)
{
    return(fabs(entry_price - exit_price)*1000);
}

float calculate_tax(float profit)
{
    return profit * (1 - 0.15);

}

int main()
{
 SetConsoleOutputCP(65001);
 float entry_price;
 float exit_price;
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
 float value = calculate_tax(calculate_profit(entry_price,exit_price));

 printf("The profit-following the (calculate_tax ₀ calculate_profit(x,y))-guideline is  %f", value);

return 0;
}
