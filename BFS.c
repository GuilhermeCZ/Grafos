#include <stdio.h>
#include <stdlib.h>
#define SIZE 40

struct queue {
    int items[SIZE];
    int front;
    int rear;
};

int roadtoZ[20];

struct queue* createQueue();
void enqueue(struct queue* q, int);
int dequeue(struct queue* q);
void display(struct queue* q);
int isEmpty(struct queue* q);
void printQueue(struct queue* q);

struct node
{
    int vertex;
    struct node* next;
};

struct node* createNode(int);

struct Graph
{
    int numVertices;
    struct node** adjLists;
    int* visited;
};

struct Graph* createGraph(int vertices);
void addEdge(struct Graph* graph, int src, int dest);
void printGraph(struct Graph* graph);
void bfs(struct Graph* graph, int startVertex);
void sortpath(struct Graph* graph);

int main()
{
    struct Graph* graph = createGraph(20);
    addEdge(graph, 0, 1); //A
    addEdge(graph, 0, 2); //A
    addEdge(graph, 1, 3); //B
    addEdge(graph, 1, 4); //B
    addEdge(graph, 2, 5); //K
    addEdge(graph, 2, 6); //K
    addEdge(graph, 2, 7); //K
    addEdge(graph, 3, 8); //C
    addEdge(graph, 4, 8); //D
    addEdge(graph, 4, 5); //D
    addEdge(graph, 5, 9); //L
    addEdge(graph, 6, 9); //M
    addEdge(graph, 7, 9); //N
    addEdge(graph, 8, 10); //E
    addEdge(graph, 8, 11); //E
    addEdge(graph, 9, 12); //O
    addEdge(graph, 9, 13); //O
    addEdge(graph, 10, 14); //F
    addEdge(graph, 11, 15); //G
    addEdge(graph, 12, 16);
    addEdge(graph, 13, 16);
    addEdge(graph, 14, 15);
    addEdge(graph, 14, 17);
    addEdge(graph, 15, 17);
    addEdge(graph, 16, 18);
    addEdge(graph, 16, 19);
    addEdge(graph, 17, 20);
    addEdge(graph, 18, 19);
    addEdge(graph, 18, 20);
    addEdge(graph, 19, 20);

    bfs(graph, 0);

    return 0;
}

void bfs(struct Graph* graph, int startVertex) {

    struct queue* q = createQueue();

    graph->visited[startVertex] = 1;
    enqueue(q, startVertex);

    while(!isEmpty(q)){
        printQueue(q);
        int currentVertex = dequeue(q);
        printf("Visited actual: %d\n", currentVertex);

       struct node* temp = graph->adjLists[currentVertex];

       while(temp) {
            int adjVertex = temp->vertex;

            if(graph->visited[adjVertex] == 0){
                graph->visited[adjVertex] = 1;
                enqueue(q, adjVertex);
            }
            temp = temp->next;
       }
    }
}


struct node* createNode(int v)
{
    struct node* newNode = malloc(sizeof(struct node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}


struct Graph* createGraph(int vertices)
{
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->numVertices = vertices;

    graph->adjLists = malloc(vertices * sizeof(struct node*));
    graph->visited = malloc(vertices * sizeof(int));


    int i;
    for (i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
    }

    return graph;
}

void addEdge(struct Graph* graph, int src, int dest)
{
    // Add edge from src to dest
    struct node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // Add edge from dest to src
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

struct queue* createQueue() {
    struct queue* q = malloc(sizeof(struct queue));
    q->front = -1;
    q->rear = -1;
    return q;
}


int isEmpty(struct queue* q) {
    if(q->rear == -1)
        return 1;
    else
        return 0;
}

void enqueue(struct queue* q, int value){
    if(q->rear == SIZE-1)
        printf("\nQueue is Full!!");
    else {
        if(q->front == -1)
            q->front = 0;
        q->rear++;
        q->items[q->rear] = value;
    }
}

int dequeue(struct queue* q){
    int item;
    if(isEmpty(q)){
        printf("Queue is empty");
        item = -1;
    }
    else{
        item = q->items[q->front];
        q->front++;
        if(q->front > q->rear){
            printf("Resetting queue");
            q->front = q->rear = -1;
        }
    }
    return item;
}

void printQueue(struct queue *q) {
    int i = q->front;

    if(isEmpty(q)) {
        printf("Queue is empty");
    } else {
        printf("\nQueue contains \n");
        for(i = q->front; i < q->rear + 1; i++) {
                printf("%d ", q->items[i]);
        }
    }
}
