#include <stdio.h>

// Modular exponentiation using an array.

int exponentiation(int *arr, int num, int pow, int md) {

    int sqtemp = 2, remtemp = num;
    int ind = 1;
    arr[0] = num % md;

    while(sqtemp <= pow) {
        remtemp = (remtemp * remtemp) % md;
        arr[ind++] = remtemp;
        sqtemp *= 2;
    }

    int binhash[ind];
    for(int i = 0; i < ind; i++) {
        binhash[i] = pow % 2;
        pow /= 2;
    }

    int remainder = 1, sum = 0;
    for(int i = 0; i < ind; i++) {
        sum += binhash[i];
    }

    if(sum > 0) {
        for(int i = 0; i < ind; i++) {
            if(binhash[i] > 0)
                remainder *= arr[i];
        }
    } else
        return 0;

    return remainder %= md;
}

int main() {

    int arr[32] = {[0 ... 31] = -1};
    int num = 3, pow = 200, md = 50;

    printf("Remainder is %d ", exponentiation(arr, num, pow, md));

    return 0;
}
