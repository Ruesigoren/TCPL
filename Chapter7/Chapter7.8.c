#include <stdio.h>
#include <stdlib.h>

#define frand()     ((double)rand() / (RAND_MAX + 1.0))

int main()
{
    system("date");
    
    int *ip;
    int n = 10;
    
    ip = (int *)calloc(n, sizeof(int));
    
    /* WRONG! */
    // for (p = head; p != NULL; p = p->next) {
        // free(p);
    // }
    
    
    for (p = head; p != NULL; p = q) {
        q = p->next;
        free(p);
    }
}