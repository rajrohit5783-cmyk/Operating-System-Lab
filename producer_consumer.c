
#include <stdio.h>

int main() {
    int buffer[10];
    int bufsize = 10;
    int in = 0;
    int out = 0;
    int produce, consume;
    int choice = 0;

    while (choice != 3) {
        printf("\n1. Produce \t 2. Consume \t 3. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if ((in + 1) % bufsize == out) {
                    printf("\nBuffer is Full");
                } else {
                    printf("\nEnter the value: ");
                    scanf("%d", &produce);
                    buffer[in] = produce;
                    in = (in + 1) % bufsize;
                }
                break;

            case 2:
                if (in == out) {
                    printf("\nBuffer is Empty");
                } else {
                    consume = buffer[out];
                    printf("\nThe consumed value is %d", consume);
                    out = (out + 1) % bufsize;
                }
                break;

            case 3:
                break;

            default:
                printf("\nInvalid choice. Please choose 1, 2, or 3.");
        }
    }

    return 0;
}
