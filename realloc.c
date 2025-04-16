//Shopping Cart using realloc()
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *cart = NULL;  // Pointer to store item prices
    int size = 0;      // Current size of the cart
    int price;
    char choice;

    printf("🛒 Welcome to the Shopping Cart Program!\n");

    do {
        printf("Enter the price of the item: ");
        scanf("%d", &price);

        // Increase cart size by 1 using realloc
        size++;
        cart = (int*) realloc(cart, size * sizeof(int));

        if (cart == NULL) {
            printf("Memory allocation failed! Exiting.\n");
            return 1;
        }

        cart[size - 1] = price;  // Add the new item to the cart

        printf("Add another item? (y/n): ");
        scanf(" %c", &choice);  // Notice the space before %c to catch newline!

    } while (choice == 'y' || choice == 'Y');

    // Print the final cart summary
    printf("\n🧾 Your Shopping Cart:\n");
    int total = 0;
    for (int i = 0; i < size; i++) {
        printf("Item %d: Rs. %d\n", i + 1, cart[i]);
        total += cart[i];
    }
    printf("Total Bill: Rs. %d\n", total);

    // Free the allocated memory
    free(cart);

    return 0;
}
