#include <stdio.h>
//quantifiers , functions, variables loops//

int swing_high(float candle[], int i , int size){
    if(i<=0 || i >=size-1){
        return 0;
    }

    if (candle[i]>candle[i-1] && candle[i]>candle[i+1] && candle[i] >= candle [i-1]+2 && candle[i] >= candle [i+1]+2 )
    {
        return 1;
    }
    return 0;
}
int swing_low(float candle[], int i , int size){
    if(i<=0 || i >=size-1){
        return 0;
    }

    if (candle[i]<candle[i-1] && candle[i]<candle[i+1])
    {
        return 1;
    }
    return 0;
}
int size_of_the_candle(int size){
printf("cardinality of the data set is %d", size);
return size;

}
int main(){
float candles[] ={13.3, 10.5, 18.4, 15.5, 10.6,};

int size = size_of_the_candle(sizeof(candles)/sizeof(candles[0]));

for(int i = 0; i < size; i++){

   if (swing_high(candles,i,size)){
    printf("\nThe swing high in the data set is %f and it is located at the %d location", candles[i],i);
   }
   if(swing_low(candles,i,size)){
    printf("\nThe swing low in the data set is %f and it is located at the %d location", candles[i],i);


   }
}

return 0;
}    

    