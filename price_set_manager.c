#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main(){


    float support[] = {1.0840, 1.0820, 1.0800,};
    float resistance[] ={1.0860, 1.0880, 1.0900};
    float threshhold = 0.0005;
    float prices;
    printf("enter price\n");
    
    scanf("%f",&prices);
   
    int s = sizeof(support)/sizeof(support[0]); 
    int r = sizeof(resistance)/sizeof(resistance[0]);

  
  
    int Insupport = 0;
    int Inresistance =0;

    for(int i = 0; i < s; i++)
    {
        if(fabs(prices - support[i]) <= threshhold)
        {
            Insupport = 1;
            break;
        }

    } 


    for(int i = 0; i < r; i++)
    {
        if(fabs(prices - resistance[i]) <= threshhold)
        {
            Inresistance = 1;
            break;
        }
        
    }    
if(Inresistance && Insupport)
{
    printf("ALERT! PRICE IS IN RESISTANCE AND SUPPLY ZONE(CONFLUENCE)\n");
}

else if(Inresistance)
{
    printf("PRICE IS IN RESISTANCE ZONE\n");
}

else if(Insupport)
{
    printf("PRICE IS IN SUPPORT\n");
}

else{
    printf("PRICE IS IN AN INIDENTIFIABLE ZONE");
}



return 0;
}