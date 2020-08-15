#include <stdio.h>

//multiplication modulo table

void multtable(int *arr, int modulo) {

    for(int i = 0; i < modulo; i++) {
        for(int j = 0; j < modulo; j++)
            printf("%d\t", (arr[j] * i) % modulo);
        printf("\n");
    }
}

int main() {

    int modulo = 8;
    int arr[modulo];
    for(int i = 0; i < modulo; i++)
        arr[i] = i;

    multtable(arr, modulo);

    return 0;
}
