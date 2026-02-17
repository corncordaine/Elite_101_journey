#include <stdio.h>
//quantifiers , functions, variables loops//

//SWING HIGH//
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
//SWING LOW//
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
//PRINT//
int size_of_the_candle(int size){
printf("cardinality of the data set is %d", size);
return size;

}

//CHOCH// advanced function

int locate_high_bos(float candlesticks[],int currentcandle ,int size ){
    for (int P = currentcandle - 1; P > 0; P --){
        if(swing_high(candlesticks,P,size)){
          return P;
        }
    }
     return -1;  
}




int main(){
float candles[] ={13.3, 10.5, 18.4, 15.5, 20.6, 17.8, 16.4};

int size = size_of_the_candle(sizeof(candles)/sizeof(candles[0]));

for(int i = 0; i < size; i++){

   if (swing_high(candles,i,size)){
    printf("\nThe swing high in the data set is %f and it is located at the %d location", candles[i],i);
   }
   if(swing_low(candles,i,size)){
    printf("\nThe swing low in the data set is %f and it is located at the %d location", candles[i],i);
   }
}


//CHOCH BREAK OF STRUCTURE//
for (int  i = 0; i < size; i++)
{
    int lastswinghigh = locate_high_bos(candles, i, size);
    if(lastswinghigh != -1){
        float last_candle_price = candles[lastswinghigh];
    
    if (candles[i] > last_candle_price) {
            printf("\nBOS ALERT the current price %.2f has been broken to %.2f ", last_candle_price , candles[i]);
    }
}
}

}