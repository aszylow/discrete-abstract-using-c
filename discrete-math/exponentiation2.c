#include <stdio.h>
#include <stdlib.h>

// Finds the remainder of a very large number by modular exponentiation using a linked list.

struct Node {
    int data;
    struct Node *next;
} *first = NULL;

void insertlast(int value) {

    struct Node *t = (struct Node *) malloc(sizeof(struct Node));
    t->data = value;
    t->next = NULL;

    struct Node *last = last;
    if(first == NULL)
        first = last = t;
    else {
        last->next = t;
        last = t;
    }
}

int getbyindex(struct Node *current, int index) {

    int count = 0;
    while (current != NULL) {
        if (count == index)
            return(current->data);
        count++;
        current = current->next;
    }
    return 0;
}

int exponentiation(int num, int pow, int md) {

    int sqtemp = 2, remtemp = num, ind = 1;
    insertlast(num % md);

    while(sqtemp <= pow) {
        remtemp = (remtemp * remtemp) % md;
        insertlast(remtemp);
        ind++;
        sqtemp *= 2;
    }

    int binhash[ind];
    for(int i = 0; i < ind; i++) {
        binhash[i] = pow % 2;
        pow /= 2;
    }

    int remainder = 1, sum = 0;
    for(int i = 0; i < ind; i++)
        sum += binhash[i];

    if(sum > 0) {
        for(int i = 0; i < ind; i++) {
            if(binhash[i] > 0)
                remainder *= getbyindex(first, i);
        }
    } else
        return 0;

    return remainder %= md;
}

int main() {

    int num = 3, pow = 200, md = 50;
    printf("Remainder is %d ", exponentiation(num, pow, md));

    return 0;
}
