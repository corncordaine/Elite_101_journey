/*Problem Statement:

You are building the decision core of a trading bot.

Inputs (all binary 1/0):

1. p - Price is above the 200-day moving average

2. Q - Volume is above its 20-day average

3. R - RSI is below 30 (oversold)

Trading Rule:
Execute a trade if:
(Volume is high AND (Price above MA OR RSI oversold)) OR (Price above MA AND RSI oversold)

Your task:
Write a C program that:

1. Takes P, Q, R as input (each 0 or 1)
2. Implements the above rule using logical operators

3. Prints "TRADE" if rule is satisfied, else "NO TRADE"
1
No further hints. No logic derivation.
Just implementation from the given rule.
*/

#include <stdio.h>
int main()
{
    int q ,p ,r;

    printf("\nif Q is is above 20 day high enter (1/0)\n");
    scanf("%d", &q );
    printf("if price is above moving average enter (1/0)\n");
    scanf("%d", &p);
    printf("if Rsi is below 30 enter (1/0\n");
    scanf("%d", &r);
    printf("%d %d %d", q, p, r);
        
    int buy = (q && (p || r) );
    if (buy) {
        printf("\n TRADE\n");
    }else{
        printf("\n NO TRADE");
    }
return 0;
}
