#include <stdlib.h>
#include "ListaCircular.h"

struct elemento {
	Aluno aluno;
	struct elemento *proximo;
};

typedef struct elemento ElementoLista;

ListaAluno* listaCircular_create(){
	ListaAluno* lista = (ListaAluno*) malloc(sizeof(ListaAluno));
	if(lista != NULL){
		*lista = NULL;
	}
	return lista;
}

void listaCircular_destruir(ListaAluno* lista){
	if(lista != NULL){
		ElementoLista *no;
		while((*lista) != NULL){
			no = *lista;
			*lista = (*lista)->proximo;
			free(no);
		}
		free(lista);
	}
}


int listaCircular_isEmpty(ListaAluno* lista){
	if(lista == NULL){
		return 2;
	}
	if(*lista == NULL){
		return 1;
	}
	return 0;
}


int listaCircular_insert(ListaAluno* lista, Aluno aluno){
	if(lista == NULL){
		return 2;
	}
	ElementoLista* no = (ElementoLista*) malloc(sizeof(ElementoLista));
	if(no == NULL){
		return 0;
	}
	
	no->aluno = aluno;
	no->proximo = *lista
	
	if((*lista) == NULL){
		*lista = no;
		
	}else{
		ElementoLista* aux = *lista;
		while(aux->proximo != NULL){
			aux = aux->proximo;
		}
		aux->proximo = no;
	}
	return 1;
}


int listaCircular_remove(ListaAluno* lista, int matricula){
	if(lista == NULL){
		return 2;
	}
	ElementoLista *no_anterior, *no = *lista;
	while(no != *lista && no->aluno.matricula != matricula){
		no_anterior = no;
		no = no->proximo;
	}
	if(no == NULL){
		return 0;
	}
	if(no == *lista){
		*lista = no->proximo;
	}else{
		no_anterior->proximo = no->proximo;
	}
	free(no);
	return 1;
}


int listaCircular_cadastro(ListaAluno* lista, int indice, Aluno* aluno){
	if(lista == NULL || indice < 0){
		return 2;
	}
	
	ElementoLista* no = *lista;
	int i = 0;
	
	while(no != *lista && i < indice){
		no = no->proximo;
		i++;
	}
	
	if(no == NULL){
		return 0;
	}
	*aluno = no->aluno;
	return 1;
}


