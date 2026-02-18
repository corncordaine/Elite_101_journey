#include <stdio.h>
/*1. Store the 5 prices somewhere (array)

2. Create a variable to track "are all still true so far?"

3. Look at each price one by one (loop)

4. If any price fails the condition, mark that all is NOT true and stop checking

5. After checking all, output the result*/

int main(){

 float candle[] = {1.0850, 1.0855, 1.0852, 1.0859, 1.0860 };
 printf("please enter the support level\n");

 float support;

 scanf("%f", &support);

 int n = sizeof(candle)/sizeof(candle[0]);
 int valid = 1;

     for (int i = 0; i < n; i++)
     {
        if(candle[i] <= support)
        {
            printf("There exists a price(s) that has validates the rule by %f\n", candle[i]);
            valid = 0;  
            break;
            
        }
        
     }
        if (valid)
        {
            printf("All conditions were satisfied\n");
        }
        else
        {
            printf("conditions were not met");
        }
        
return 0;        

}