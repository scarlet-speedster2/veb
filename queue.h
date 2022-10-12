typedef struct node{
	int ip;
	struct node* next;

}node;

typedef node* queue;

void init_queue(queue* q);

void enqueue(queue* q,int d);

int dequeue(queue* q);

int isEmpty(queue q);

