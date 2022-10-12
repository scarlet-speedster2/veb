#include<stdio.h>
#include<stdlib.h>
#include"queue.h"

void init(queue* q){
	*q = NULL;
	return;
}

void enqueue(queue* q,int d){

	queue t = (*q);
	queue f = NULL;
	queue n;
	n = (queue) malloc (sizeof(node));
	if(!n)
		return;
	n ->ip = d;
	n ->next = NULL;
	if(!t){
		*q = n;
		return;
	}
	while(t != NULL){
		f = t;
		t = t -> next;
	}
	f -> next = n;
}


int dequeue(queue* q){

	int d;

	if(!(*q))
		return -1;
	d = (*q)-> ip;
	queue t = (*q);
	(*q) = (*q) -> next;
	free(t);
	return d;
}

int isEmpty(queue q){

	if(!q)
		return 1;
	return 0;
}



	       	
		

	
