#include <stdio.h>
/*1. Store the 5 prices somewhere (array)

2. Create a variable to track "are all still true so far?"

3. Look at each price one by one (loop)

4. If any price fails the condition, mark that all is NOT true and stop checking

5. After checking all, output the result*/

//use of function
float checking_for_support(float candles[],int n, float support)
{
     for (int i = 0; i < n; i++)
    {
        if(candles[i] <= support)
        {
            return candles[i];
        }
    }
return -1;
}

            
int main(){

 float candle[] = {1.0850, 1.0855, 1.0852, 1.0859, 1.0860 };
 printf("please enter the support level\n");

 float support;

 scanf("%f", &support);

 int n = sizeof(candle)/sizeof(candle[0]);


 float result = checking_for_support(candle, n, support);
 
 if (result != -1)
 {
    printf("There exists a price that has violated the rule: %f\n", result);
 }
 else{
    printf("all price satisfied the rule");
 }
        
        
return 0;        

}