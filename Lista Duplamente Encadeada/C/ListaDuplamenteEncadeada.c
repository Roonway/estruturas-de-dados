#include <stdlib.h>
#include <string.h>
#include "ListaDuplamenteEncadeada.h"

struct elemento {
	Aluno aluno;
	struct elemento *anterior;
	struct elemento *proximo;
};

typedef struct elemento ElementoLista;

ListaAluno* criar_lista_aluno(){
	ListaAluno* lista = (ListaAluno*) malloc(sizeof(ListaAluno));
	if(lista != NULL){
		*lista = NULL;
	}
	return lista;
}

void destruir_lista_aluno(ListaAluno* lista){
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

int tamanho_lista_aluno(ListaAluno* lista){
	if(lista == NULL){
		return 0;
	}
	int tamanho = 0;
	ElementoLista *no = *lista;
	while(no != NULL){
		tamanho++;
		no = no->proximo;
	}
	return tamanho;
}

int lista_aluno_vazia(ListaAluno* lista){
	if(lista == NULL){
		return 1;
	}
	if(*lista == NULL){
		return 1;
	}
	return 0;
}

 /*
int inserir_aluno_lista(ListaAluno* lista, Aluno aluno){
	if(lista == NULL){
		return 0;
	}
	ElementoLista* no = (ElementoLista*) malloc(sizeof(ElementoLista));
	if(no == NULL){
		return 0;
	}
	no->aluno = aluno;
	no->proximo = NULL;
	if((*lista) == NULL){
		no->anterior = NULL;
		*lista = no;
	}else{
		ElementoLista* aux = *lista;
		while(aux->proximo != NULL){
			aux = aux->proximo;
		}
		aux->proximo = no;
		no->anterior = aux;
	}
	return 1;
}
*/

/**
*	Insersão de elementos em ordem alfabética 
*/
int insertAlphabetcalOrder(ListaAluno* lista, Aluno aluno){
	if(lista == NULL){
		return 0;
	}
	
	ElementoLista* new_no = (ElementoLista*) malloc(sizeof(ElementoLista));
	if(new_no == NULL){
		return 0;
	}
	
	new_no->aluno = aluno;
	new_no->proximo = NULL;
	
	if((*lista) == NULL){
		new_no->anterior = NULL;
		*lista = new_no;
	}
	else{
		ElementoLista* aux = *lista;
		
		while(aux->proximo != NULL){
			
			if(strcmp(new_no->aluno.nome, aux->aluno.nome)>0){
				new_no->anterior = aux;
				new_no->proximo = aux->proximo;
				
				aux->proximo->anterior = new_no;
				aux->proximo = new_no;
				
				return 1;
			}
			aux = aux->proximo;
		}
	
		new_no->anterior = NULL;
		new_no->proximo = *lista;
		
		(*lista)->anterior = new_no;
		*lista = new_no;	
	}	
	
	return 1;
}


/*
int remover_aluno_lista(ListaAluno* lista, int indice){
	if(lista == NULL || indice < 0){
		return 0;
	}
	ElementoLista* no = *lista;
	int i = 0;
	while(no != NULL && i < indice){
		no = no->proximo;
		i++;
	}
	if(no == NULL){
		return 0;
	}
	if(no->anterior == NULL){
		*lista = no->proximo;
	}else{
		no->anterior->proximo = no->proximo;
	}
	if(no->proximo != NULL){
		no->proximo->anterior = no->anterior;
	}
	free(no);
	return 1;
}
*/


/**
*
*/
int removeElement(ListaAluno* lista, int matricula){
	if ( lista_aluno_vazia(lista) == 1){
		return 0;
	}
	
	ElementoLista* no = *lista;
	
	while (no != NULL && no->aluno.matricula != matricula){
		no = no->proximo;
	}
	
	if(no == NULL){
		return 0;
	}
	
	if (no->anterior == NULL) {
		*lista = no->proximo;
	} else{
		no->anterior->proximo = no->proximo;
	} 
	
	if(no->proximo != NULL){
		no->proximo->anterior = no->anterior;
	}
	
	free(no);
	return 1;
}

/*
int consultar_aluno_lista(ListaAluno* lista, int indice, Aluno* aluno){
	if(lista == NULL || indice < 0){
		return 0;
	}
	ElementoLista* no = *lista;
	int i = 0;
	while(no != NULL && i < indice){
		no = no->proximo;
		i++;
	}
	if(no == NULL){
		return 0;
	}
	*aluno = no->aluno;
	return 1;
}
*/

/**
*	Consulta um elementos na lista através do nome
*/
int getElementeByName(ListaAluno*  lista, char* str,  Aluno* aluno){
	if ( lista_aluno_vazia(lista) == 1){
		return 0;
	}
	
	ElementoLista* aux = *lista;
	
	while(aux != NULL && strcmp(str, aux->aluno.nome) != 0){
		aux = aux->proximo;
	}
	
	if(aux == NULL){
		return 0;
	}
	
	*aluno = aux->aluno;
	return 1;
}

/**
*	Consulta um elementos na lista através da matricula
*/
int getElementeByMatricula(ListaAluno* lista, int matricula,  Aluno* aluno){
	if ( lista_aluno_vazia(lista) == 1){
		return 0;
	}
	
	ElementoLista* aux = *lista;
	
	while(aux != NULL && aux->aluno.matricula != matricula){
		aux = aux->proximo;
	}
	
	if(aux == NULL){
		return 0;
	}
	
	*aluno = aux->aluno;
	return 1;
}
