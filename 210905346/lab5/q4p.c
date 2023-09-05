#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int shelf = 0; // Initialize shelf with 0 items

    while (1) {
        // Check if the shelf is not overstocked (maximum 5 items)
        if (shelf < 5) {
            shelf++; // Add one item to the shelf
            printf("Producer: Added 1 item. Shelf count: %d\n", shelf);
        } else {
            printf("Producer: Shelf is full. Waiting...\n");
        }

        // Sleep to simulate some work
        sleep(1);
    }

    return 0;
}
