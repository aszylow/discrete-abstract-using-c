#include <stdio.h>

// Outputs a multiplication group table.

void multtable(int *arr, int len, int modulo) {

    for(int i = 0; i < len; i++) {
        for(int j = 0; j < len; j++)
            printf("%d\t", (arr[j] * arr[i]) % modulo);
        printf("\n");
    }
}

int gcd(int num1, int num2) {

   while(num2 != 0) {
        int temp = num2;
        num2 = num1 % num2;
        num1 = temp;
    }
    return num1;
}

int main() {

    int modulo = 10, count = 0;
    for(int i = 0; i < modulo; i++)
        if(gcd(modulo, i) == 1)
            count++;

    int arr[count], index = 0;
    for(int i = 0; i < modulo; i++)
        if(gcd(modulo, i) == 1)
            arr[index++] = i;

    multtable(arr, count, modulo);

    return 0;
}
