#include "staticStack.h"
#include <stdlib.h>

struct stack_struct {
	int index;
	int dimension;
	Element* vector;
};


Stack* stack_create(int dimension){
	Stack* p = (Stack*) malloc(sizeof(Stack));
	p->dimension = dimension;
	p->vector = (Element*) malloc(p->dimension*sizeof(Element));
	
	if(p->vector != NULL){
		p->index = 0;
	}
	
	return p;
}

int stack_isEmpty(Stack* pointer){
	
	return (pointer->index == 0);
}

int stack_isFull(Stack* pointer){
	
	return (pointer->index == pointer->dimension);
}

int stack_actionReallocate(Stack* pointer, int amount){
	
	pointer->dimension += amount;
	pointer->vector = (Element*) realloc(pointer->vector, pointer->dimension*sizeof(Element));
	
	if(pointer->vector){
		return 1;
	} else {
		return 0;
	}
	
}

int stack_push(Stack* pointer, Element element) {
	
	if(stack_isEmpty(pointer)){
		return 0;
	}
	
	if(stack_isFull(pointer)){
		return 0;
	}
	
	pointer->vector[pointer->index++] = element;
	
	return 1;
}

Element stack_pop(Stack* pointer){
	
	Element element = {0, NULL};
	
	if(!stack_isEmpty(pointer)){	
		element = pointer->vector[--pointer->index];	
	}
	
	return element;

}


void stack_delete(Stack* pointer){
	
	free(pointer->vector);
	free(pointer);

}
