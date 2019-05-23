#include "dynamicStack.h"
#include <stdlib.h>

struct list_no{
	Element content;
	List* prox;
};

struct stack {
	List* prim;	
};

Stack* stack_create(){
	Stack* pointer = (Stack*) malloc(sizeof(Stack));
	
	if(pointer){
		pointer->prim = NULL;
	}

	return pointer;
}

int stack_push(Stack* pointer, Element element){
	
	if(!pointer){
		return 0;
	}
	
	List* no = (List*) malloc(sizeof(List));
	
	if(!no){
		return 0;
	}
	
	no->content = element;
	no->prox = pointer->prim;
	pointer->prim = no; 
	
	return 1;
}


int stack_pop(Stack* pointer){
	
	if(!pointer){
		return 0;
	}
	
	if (!stack_isEmpty(pointer)){
		 return 0;
	}
		
	List* aux = pointer->prim; 
	pointer->prim = aux->prox;

	free(aux);	

	return 1;
}

int stack_isEmpty(Stack* pointer){
	
	if(!pointer){
		return 0;
	}
	
	return (pointer->prim == NULL);
}

void stack_delete(Stack* pointer){
	List* aux = pointer->prim;
	
	while (aux!=NULL){
		List* no = aux->prox;
		free(aux);
		aux = no;
	}
	
	free(pointer);
}

int stack_select(Stack* pointer, Element* element){

	if(!pointer){
		return 0;
	}
	
	if (!stack_isEmpty(pointer)){
		return 0;
	}
	
	*element = pointer->prim->content;
	
	return 1;
}
