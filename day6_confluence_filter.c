#include <stdio.h>
#include <math.h>

struct CountResults
{
    int count;
    int count_ob;
};




//SUPPLY ZONE FILTER//
struct CountResults fits_criteria1(float current_price, float supply[],float new_supply[], int nsp,float order_block[], float new_order_block_supply[], int nob)
{
float ob_threshold = 0.05;
float threshold = 0.005;
int count = 0;
int MAX_LEVEL = 50;
int MAX_LEVEL_ob = 90;
int count_ob =0;
 for(int i =0; i < nsp; i++ )
 {
    if(fabs(current_price - supply[i]) <= threshold && count < MAX_LEVEL )
    {
        new_supply[count] = supply[i];

        count++;
    }
}

    for(int b = 0 ;b < nob ; b++)
     {
        for(int s= 0; s < count ; s++)
        {
         if(fabs(new_supply[s] - order_block[b])<= ob_threshold && count_ob < MAX_LEVEL_ob )
         {
            new_order_block_supply[count_ob] = order_block[b];

            count_ob++;
         }
         break;
        }
     }
        
struct CountResults results_supply;
results_supply.count = count;
results_supply.count_ob= count_ob;
return results_supply;

}


struct CountResults_demand
{
    int count_demand;
    int count_ob_demand;
};

//DEMAND ZONE FILTER//
struct CountResults_demand fits_criteria2(float current_price, float demand[], float new_demand[], int ndm,float order_block[], float new_order_block_demand[], int nob)
{

float threshold = 0.005;
float ob_threshold = 0.05;
int count_demand = 0;
int MAX_LEVEL = 50;
int MAX_LEVEL_ob = 90;
int count_ob_demand =0;
 for(int i =0; i < ndm; i++ )
 {
    if(fabs(current_price - demand[i]) <= threshold && count_demand < MAX_LEVEL )
    {
        new_demand[count_demand]= demand[i];
        count_demand++;
    }

 }

    for(int b = 0 ;b < nob ; b++)
     {
        for(int s= 0; s < count_demand ; s++)
        {
         if(fabs(new_demand[s] - order_block[b])<= ob_threshold && count_ob_demand < MAX_LEVEL_ob )
         {
            new_order_block_demand[count_ob_demand] = order_block[b];

            count_ob_demand++;
            
         }
         break;
        }
     }
struct CountResults_demand result_demand;
result_demand.count_demand = count_demand;
result_demand.count_ob_demand = count_ob_demand;
return result_demand;

}

// ORDER BLOCK FILTER//
float fits_criteria3(float order_block[],float  current_price,float criteria[], int size)
{

float threshold = 0.005;
int count = 0;
int MAX_LEVEL = 90;
 for(int i =0; i < size; i++ )
 {
    if(fabs(current_price - order_block[i]) <= threshold && count < MAX_LEVEL )
    {
        criteria[size] = order_block[i];
        count++;
    }

 }
return count;

}




int main()
{

/*∀d[
    ( Bullish(d) → (∃dm∃ob(Inside(ob,dm) ∧ Mitigated(ob) ∧ ∃rsi(rsi<30)) → BuySignal(d) )
    ∨
    ( Bearish(d) → (∃sp∃ob(Inside(ob,sp) ∧ Mitigated(ob) ∧ ∃rsi(rsi>70)) → SellSignal(d) )
]
*/

float supply[]={1.0840, 1.0820, 1.0800};
float demand[] ={1.0860, 1.0880, 1.0900};
float order_block[]= {1.0850, 1.0855, 1.0852, 1.0859, 1.0860}; //within 0.005 of either support or resistance
int rsi_value;
float current_price;
int trend;
printf("please enter numerical value of rsi value in the range 1 - 100 (whole numbers)\n") ;


while(scanf("%d",&rsi_value)!= -1)
{
    if(rsi_value >100 || rsi_value <0)
    {
    printf("please enter value within the set range\n"); 
    }
    else
    {
        break;
    }
    int c;
    while((c = getchar())!='\n' && c!= EOF);

}



printf("Enter the current price level\n");
scanf("%f",&current_price);

printf("Enter current market trend\n Bullish - 1\n Bearish - 2\n");

while((scanf("%d", &trend) !=1) || (trend !=1 && trend !=2))
{
    printf("please enter value within the set range\n"); 
    int c;
    while((c=getchar()!='\n' && c != EOF));
    
}


int nsp = sizeof(supply)/sizeof(supply[0]);
int ndm = sizeof(demand)/sizeof(demand[0]);
int nob = sizeof(order_block)/sizeof(order_block[0]);
float new_supply[nsp];
float new_demand[ndm];
float new_order_block_demand[nob];
float new_order_block_supply[nob];


struct CountResults results_supply = fits_criteria1(current_price, supply, new_supply, nsp, order_block, new_order_block_supply, nob);
/*printf(" count:%d\n count_ob:%d\n", results_supply.count, results_supply.count_ob);

printf("%f\n" ,new_supply[0]);
for(int i = 0; i<nob ; i++)
{
printf("%.5f\n",new_order_block_supply[i]);
}


printf("----------------------------------------------------------------------------------------------------------\n");*/

struct CountResults_demand results_demand = fits_criteria2(current_price, demand, new_demand, ndm, order_block, new_order_block_demand, nob);


/*printf(" count:%d\n count_ob:%d\n", results_demand.count_demand, results_demand.count_ob_demand);
printf("%f\n" ,new_demand[0]);
for(int i = 0; i<nob ; i++)
{
printf("%.4f\n",new_order_block_demand[i]);
}
int size = sizeof(new_demand)/sizeof(new_demand[0]);*/


int mitigaion = 0.001;// within 0.001 of supply
if(trend == 2)
{
 
 for(int i = 0; i < results_supply.count;i++)
 {
     for(int p = 0;p < results_supply.count; p++)
     {
         if((fabs(new_supply[i] - new_order_block_supply[p]) <= mitigaion) && rsi_value > 70 )
         {
             printf(" SELL ALERT!!!\n The current price %.5f has mitigated the order block %.5f in the supply zone %.5f\n" , current_price, new_order_block_supply[p], new_supply[i] );
         }
     }
    
 }
             printf("-------------------------------------------------------\n");
}
    
else
{
 for(int i = 0; i < results_demand.count_demand;i++)
 {
     for(int p = 0;p < results_demand.count_ob_demand; p++)
     {
         if((fabs(new_demand[i] - new_order_block_demand[p]) <= mitigaion) && rsi_value <30 )
         {
             printf(" BUY ALERT!!!\n The current price %.5f has mitigated the order block %.5f in the supply zone %.5f\n" , current_price, new_order_block_demand[p], new_demand[i] );
         }
     }
    
 }
}


/*negation ∃d[
              ( Bulish(d) ∧ (∃dm∃ob(Inside(ob,dm) ∧ Mitigated(ob) ∧ ∃rsi(rsi<30)) ∧¬Buysignal(d) )
               ∨                         //the reason for not following the  de morgans low during negation of or symbol is due to the logical coding scheme since a day cant be bulish and bearish at same time on a single timeframe therefore no negation of "∨"  symbol
 
               ( Bearish(d) ∧ ∃sp∃ob(Inside(ob,sp) ∧ Mitigated(ob) ∧ ∃rsi(rsi>70)) ∧ ¬SellSignal(d) )}
*/ 


//the reason for negation is to prove the system wrong and come up with a counter part of it inside the code for efficiency  but for this code the logical thinking the negated statement is vacuously true since the system is deterministic therefore looking for an anomaly the negated on is an empty set therefore the logic and the code is sound









return 0;
}