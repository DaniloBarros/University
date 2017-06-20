#include <stdio.h>

int main(int argc, const char * argv[]) {
    
    int m[5][5];
    int *p;

    m[0][0] = 3;
    
    printf("%p ", p);
    p = *m;
    printf("%p ", p);
    m[0][1] = 5;
    printf("%d ", m[0][1]);
    printf("%d ", *p);
    
    *p = 6;
    printf("%d ", m[0][0]);
    p[1] = 1;
    printf("%d ", m[0][0]);
    
    printf("%d ", m[0][1]);
    
    return 0;
}
