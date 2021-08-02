#include <stdio.h>

void absolute(int x, int y) {
    // Completar aqui
    if(x > -1) y = 0;
    else y = -x;
}

int main(void) {
    // Completar aqui
    int a = -98;
    int res = 0;

    absolute(a, res);
    printf("A: %d \n", a);
    printf("Res: %d \n", res);
    return 0;
}

