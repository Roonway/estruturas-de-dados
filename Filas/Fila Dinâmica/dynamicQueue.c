#include "dynamicQueue.h"
#include <stdlib.h>

struct list_no{
	List* next;
	Element content;
};

struct queue{
	List* first;
	List* last;
};

Queue* queue_create(){
	Queue* pointer = (Queue*) malloc(sizeof(Queue));
	if(pointer){
		pointer->first = pointer->last = NULL;
	}
	return pointer;
}

int queue_insert(Queue* pointer, Element element){
	
	if(!pointer){
		return 0;
	}
	
	List* no = (List*) malloc(sizeof(List));
	
	if(!no){
		return 0;
	}
	
	no->content = element;
	no->next = NULL;
		
	if(queue_isEmpty(pointer)){
		pointer->first = n;
	} else {
		pointer->last->next = no;
	}
	
	pointer->last = no;
	
	return 1;
}

int queue_remove(Queue* pointer){
	
	if(!pointer){
		return 0;
	}
	
	if(queue_isEmpty(pointer)){
		return 0;
	}
	
	List* no = pointer->first;
	pointer->first = no->next;;
	
	if(queue_isEmpty(pointer)){
		pointer->last = NULL;
	}
	free(no);
	
	return 1;
}

int queue_select(Queue* pointer, Element* element){
	if(!pointer){
		return 0;
	}
	
	if (!stack_isEmpty(pointer)){
		return 0;
	}
	
	*element = pointer->first->content;
	
	return 1;
}

int queue_isEmpty(Queue* pointer){
	
	if(!pointer){
		return 0;
	}
	
	return (pointer->first == NULL);
}

void queue_delete(Queue* pointer){
		List* aux = pointer->first;
	
	while (aux!=NULL){
		List* no = aux->next;
		free(aux);
		aux = no;
	}
	
	free(pointer);
}
