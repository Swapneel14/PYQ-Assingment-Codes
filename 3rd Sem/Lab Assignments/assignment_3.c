#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

typedef struct queue{
    int front;
    int rear;
    int queuesize;
    int *arr;
}queue;

void createIntegerQueue(queue* q,int size){
    q->queuesize = size+1;
    q->arr = (int*)malloc(q->queuesize*sizeof(int));
    
    if(q->arr == NULL){
        return;
    }
  
    q->front = 0;
    q->rear = 0;
}

int qsize(queue* q){
    if(q->arr == NULL) return -1;
    return (q->queuesize - (q->front - q->rear)) % q->queuesize;
}

int isFull(queue* q){
    if (q->arr==NULL) return 0;
    if(((q->rear+1) % q->queuesize) == q->front) return 1;
    else return 0;
}

int isEmpty(queue* q){
    if (q->arr==NULL) return 1;
    if(q->rear == q->front) return 1;
    else return 0;
}

int enqueueInteger(queue* q, int d){
    if (q->arr==NULL || isFull(q)) return 0;

    q->arr[q->rear] = d;
    q->rear = (q->rear + 1)%(q->queuesize);
    return 1;
}

int dequeueInteger(queue* q, int *ele){
    if (q->arr==NULL || isEmpty(q)) return 0;

    *ele = q->arr[q->front];
    q->front = (q->front + 1)%(q->queuesize);
    return 1;
}

int freeQueue(queue* q){
    if(q->arr == NULL) return 0;
    free(q->arr);
    q->arr = NULL;
    return 1;
}

void printQueue(queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue (capacity %d, size %d): Front -> ", q->queuesize-1, qsize(q));
    int i = q->front;
    while (i != q->rear) {
        printf("%d ", q->arr[i]);
        i = (i + 1) % q->queuesize;
    }
    printf("<- Rear\n");
}

void simulateFixedRValue(queue* q, int rValue) {
   
    while (!isEmpty(q)) {
        int qElement;
        dequeueInteger(q, &qElement);
        printf("Dequeued: %d\n", qElement);

        qElement -= rValue;
        if (qElement > 0) {
            enqueueInteger(q, qElement);
            printf("Re-enqueued: %d\n", qElement);
        } else {
            printf("Dropped: %d\n", qElement);
        }

        printQueue(q);
    }
}

void simulateRandomRValue(queue* q) {
    printf("\n--- Simulation with random rValue (1-9) ---\n");

    srand(time(NULL));

    while (!isEmpty(q)) {
        int qElement;
        dequeueInteger(q, &qElement);
        printf("Dequeued: %d\n", qElement);

        int rValue = (rand() % 9) + 1;
        printf("Generated rValue = %d\n", rValue);

        qElement -= rValue;
        if (qElement > 0) {
            enqueueInteger(q, qElement);
            printf("Re-enqueued: %d\n", qElement);
        } else {
            printf("Dropped: %d\n", qElement);
        }

        printQueue(q);
    }
    printf("Queue is now empty.\n");
}

int main() {
    queue myQueue;
    int size;
    printf("Enter the size :- ");
    scanf("%d",&size);
    
    createIntegerQueue(&myQueue,size);
    int running = 1;

    
    while(running){
        int input;
        printf("Enter 1 for enqueueing elements\n");
        printf("Enter 2 for dequeueing elements\n");
        printf("Enter 3 to print queue\n");
        printf("Enter 0 to exit\n");
        scanf("%d",&input);
        switch (input)
        {
        case 1:
            if(isFull(&myQueue)){
                printf("Queue is already full!!\n");
                break;
            }
            else{
                int val;
                printf("Enter the value :- ");
                scanf("%d",&val);
                if(enqueueInteger(&myQueue,val)){
                    printf("Successfully enqueued %d\n",val);
                    printf("The size of the queue is : %d\n",qsize(&myQueue));
                }
            }
            break;
        case 2:
            if(isEmpty(&myQueue)){
                printf("Queue is empty!!\n");
                break;
            }
            else{
                int ele;
                if(dequeueInteger(&myQueue,&ele)){
                    printf("Successfully dequeued %d\n",ele);
                    printf("The size of the queue is : %d\n",qsize(&myQueue));
                }
            }
            break;
        case 3:
            printQueue(&myQueue);
            break;

        case 0:
            freeQueue(&myQueue);
            printf("Exiting...\n");
            running = 0;
            break;
        default:
            printf("Invalid choice!!\n");
            break;
        }  
    }

    
    queue myQueue2;
    printf("Enter the size :- ");
    scanf("%d",&size);
    
    createIntegerQueue(&myQueue2,size);

    
    while (!isFull(&myQueue2)) {
        int val;
        scanf("%d", &val);
        enqueueInteger(&myQueue2, val);
    }

    
    printQueue(&myQueue2);
    int num;
    printf("Enter the random value: ");
    scanf("%d",&num);
    simulateFixedRValue(&myQueue2, num);

    
    printf("\nRepopulate queue :\n");
    printf("Enter the elements of the queue\n");
    while (!isFull(&myQueue2)) {
        int val;
        scanf("%d", &val);
        enqueueInteger(&myQueue2, val);
    }

    printf("\nInitial Queue for random simulation:\n");
    printQueue(&myQueue2);

    simulateRandomRValue(&myQueue2);

    freeQueue(&myQueue2);
    return 0;
}