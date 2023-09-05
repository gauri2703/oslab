#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int shelf = 0; // Initialize shelf with 0 items

    while (1) {
        // Check if there are items on the shelf
        if (shelf > 0) {
            shelf--; // Remove one item from the shelf
            printf("Consumer: Removed 1 item. Shelf count: %d\n", shelf);
        } else {
            printf("Consumer: Shelf is empty. Waiting...\n");
        }

        // Sleep to simulate some work
        sleep(1);
    }

    return 0;
}