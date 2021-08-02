#include <stdio.h>

void absolute(int x, int *y) {
    // Completar aqui
    if(x >= 0) *y = x;
    else *y = -x;
}

int main(void) {
    // Completar aqui
    int a = -98;
    int res = 0;
    //int* p = &res;
    absolute(a, &res);
    printf("Res: %d\n", res);
    return 0;
}

