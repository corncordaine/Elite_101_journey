#include <stdio.h>
//Multi_Tier_Filter_Day_2_Final//

int main(){

int daily_bias;
int rsi_value;


printf("please enter the daily bias\n  *Legend*\n Bulish  = 1\n Bearish = 2\n Sideway = 3\n");
scanf("%d",&daily_bias);
printf("please enter the current rsi value in whole number strictly from 0 to 100\n");
scanf("%d",&rsi_value );

while ((rsi_value<0 || rsi_value>100 || daily_bias<1 || daily_bias>3 ))
{
    if(daily_bias<1 || daily_bias>3){
        printf("please enter one of the specified bias in the legend\n");
        scanf("%d",&daily_bias);
    }
    if(rsi_value<0 || rsi_value>100){
         printf("please enter a value that is within the set range 0 - 100\n");
         scanf("%d", &rsi_value);
    }
   
   
}

printf("is( %d )your intended value?\n" , rsi_value);

printf("please re-enter the rsi value for validation\n");
scanf("%d",&rsi_value );

printf("%d is the validated value\n" , rsi_value);


if(daily_bias==1 && rsi_value<30){
    printf("STRONG BUY - Bulish trend + oversold");
}
else if(daily_bias == 1 && rsi_value > 70){
    printf("WATCH FOR POSSIBLE REVERSAL - Bulish trend but overbought");
}
else if(daily_bias==2 && rsi_value>70){
    printf("STRONG SELL - Bearish trend + overbought");
}
else if(daily_bias == 2 && rsi_value<30){
    printf("WATCH FOR REVERSAL — Bearish trend but oversold");
}
else if(daily_bias ==3){
    printf("SIDEWAYS - No clear bias");
}
else{
    printf("NO CLEAR SIGNAL - Conditions not met");
}


return 0;

}

