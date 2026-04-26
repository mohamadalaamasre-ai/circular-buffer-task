#include <stdio.h>
#include <string.h>

// 1. Define Buffer Size
#define SIZE 10 

// 2. Circular Buffer Structure
typedef struct {
    char buffer[SIZE];
    int head;
    int tail;
    int count;
} CircularBuffer;

// 3. Initialization Function
void init(CircularBuffer *cb) {
    cb->head = 0;
    cb->tail = 0;
    cb->count = 0;
}

// 4. Check functions
int isFull(CircularBuffer *cb) {
    return cb->count == SIZE;
}

int isEmpty(CircularBuffer *cb) {
    return cb->count == 0;
}

// 5. Write Function (Enqueue)
void writeBuffer(CircularBuffer *cb, char data) {
    if (isFull(cb)) {
        printf("\n[Error] Buffer Overflow! Cannot add: %c", data);
        return;
    }
    cb->buffer[cb->head] = data;
    cb->head = (cb->head + 1) % SIZE;
    cb->count++;
}

// 6. Read Function (Dequeue)
char readBuffer(CircularBuffer *cb) {
    if (isEmpty(cb)) {
        printf("\n[Error] Buffer Underflow!");
        return '\0';
    }
    char data = cb->buffer[cb->tail];
    cb->tail = (cb->tail + 1) % SIZE;
    cb->count--;
    return data;
}

// 7. Main Function
int main() {
    CircularBuffer cb;
    init(&cb);

    char name[50];
    printf("Please enter your name: ");
    scanf("%s", name);

    // Add suffix
    strcat(name, "-CE-ESY");

    printf("\nString to store: %s\n", name);
    printf("--- Writing to Buffer ---\n");

    for (int i = 0; i < strlen(name); i++) {
        writeBuffer(&cb, name[i]);
    }

    printf("\n\n--- Reading from Buffer ---\n");
    while (!isEmpty(&cb)) {
        printf("%c", readBuffer(&cb));
    }

    printf("\n\nOperation completed. Buffer is now empty.\n");

    return 0;
}
