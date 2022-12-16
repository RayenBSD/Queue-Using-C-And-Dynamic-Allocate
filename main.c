#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isEmpty();
bool underflow();
bool isFull();

void enQueue(int*, int);
void deQueue(int*);
void print(int*);

int max = 5;
int front = -1, rear = -1;

void menu(int*);

int main(void) {

  int *arr = (int *) calloc(max, sizeof(int)), choice = 0, value = 0;

  while (true) {
    menu(&choice);
    
    switch (choice) {
      case 0: exit(0);
      case 1:{
        printf("Enter your value: "), scanf("%d", &value);
        enQueue(arr, value);
      } break;
      case 2:
        deQueue(arr);
      break;
      case 3:
        print(arr);
      break;
      case 4: {
        int prevMax = max;
        do {
          printf("Enter your new size: "), scanf("%d", &max);
        } while (max < 5);

        arr = (int *) realloc (arr, max*sizeof(int));

        if (max < prevMax) front = rear = -1;
      }
    }
  }
  
  return 0;
}

void menu(int *choice) {
  do {
    printf("0.Exit\n");
    printf("1.Enqueue\n");
    printf("2.Dequeue\n");
    printf("3.Print elements\n");
    printf("4.Resize\n");

    printf("> "), scanf("%d", choice);
  } while (!(*choice >= 0 && *choice < 5));
}

bool isEmpty() {
  return (front == -1 && rear == -1);
}

bool underflow() {
  return (front == rear+1);
}

bool isFull() {
  return rear == max-1;
}

void enQueue(int *arr, int v) {
  if (isEmpty()) {
    front = rear = 0;
    arr[front] = v;
    return;
  }

  if (isFull()) {
    printf("Your Queue is Full\n");
    return;
  }

  arr[++rear] = v;
}

void deQueue(int *arr) {
  if (isEmpty()) {
    printf("Your queue is empty\n");
    return;
  }

  if (underflow()) {
    printf("You have to enqueue some elements!!!\n");
    return;
  }

  printf("Your element is: %d\n", arr[front++]);
}

void print(int *arr) {
  if (isEmpty()) {
    printf("Your Queue is empty!\n");
    return;
  }

  if (underflow()) {
    printf("You can\'t print the Queue\n");
    return;
  }

  for (int i = front; i <= rear; i++) {
    printf("arr[%d]: %d\n", i, arr[i]);
  }
}