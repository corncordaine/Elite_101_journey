#include <stdio.h>
#include <locale.h>
#include <windows.h>


int main()
{   
     SetConsoleOutputCP(65001);

printf("logical proof of ¬P V ¬Q ↔ ¬(P ∧ Q)\n");
     printf("P\tQ\t¬P\t¬Q\t¬P V¬Q)\t¬(P∧ Q)\n");
        printf("-------------------------------------------------\n");

    
    
    
for (int P = 1; P >= 0; P--) {     
    for (int Q = 1; Q >= 0; Q--) {
        
        int notP = !P;
        int notQ = !Q;
        int pAndQ = !P || !Q;
        int notPAndQ = !(P && Q);
        
        
        printf("%-7d %-8d %-7d %-7d %-7d %-8d\n", P, Q, notP, notQ, pAndQ, notPAndQ);
    }
}



        
    






}