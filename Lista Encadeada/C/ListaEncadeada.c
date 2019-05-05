#include <stdlib.h>
#include "ListaEncadeada.h"

struct elemento {
	Aluno aluno;
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

/**
*	Função adicionda - Exercício
* 	Questão 1
*/
int inserir_aluno_lista_inicio(ListaAluno* lista, Aluno aluno){
	
	if(lista == NULL){
		return 0;
	}
	
	ElementoLista* novo_no = (ElementoLista*) malloc(sizeof(ElementoLista));
	
	if(novo_no == NULL){
		return 0;
	}
	
	novo_no->aluno = aluno;
	novo_no->proximo = (ElementoLista*) NULL;
	
	if((*lista) == NULL){
		*lista = novo_no;
	}
	else{
		novo_no->proximo = *lista;
		*lista = novo_no;
	}
	return 1;	
}

/**
*	Função adicionda - Exercício
* 	Questão 2
*/
int inserir_aluno_lista_order(ListaAluno* lista, Aluno aluno){
	
	if(lista == NULL){
		return 0;
	}
	
	ElementoLista* no_anterior, *novo_no = (ElementoLista*) malloc(sizeof(ElementoLista));
	
	if(novo_no== NULL){
		return 0;
	}
	
	novo_no->aluno = aluno;
	novo_no->proximo = (ElementoLista*) NULL;
	
	if((*lista) == NULL){
		*lista = novo_no;
	}
	else{
		ElementoLista* aux = *lista;
		
		while(aux->aluno.matricula <= novo_no->aluno.matricula && aux != NULL){
			no_anterior = aux;
			aux = aux->proximo;
		}
		
		novo_no->proximo = no_anterior->proximo;
		no_anterior->proximo = novo_no;
	}
		
	return 1;
}


int remover_aluno_lista(ListaAluno* lista, int matricula){
	if(lista == NULL){
		return 0;
	}
	ElementoLista *no_anterior, *no = *lista;
	while(no != NULL && no->aluno.matricula != matricula){
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

/**
*	Função adicionda - Exercício
* 	Questão 3
*/
int remover_aluno_lista_inicio(ListaAluno* lista){
	
	if(lista == NULL){
		return 0;
	}
	
	ElementoLista* no = *lista;
	*lista = (*lista)->proximo;
	free(no);
	
	return 1;
}

/**
*	Função adicionda - Exercício
* 	Questão 4
*/
int remover_aluno_lista_final(ListaAluno* lista){
	
	if(lista == NULL){
		return 0;
	}
	
	if(*lista == NULL){
		return 0;
	}
	
	ElementoLista *no_anterior, *no = *lista;
	while(no->proximo != NULL){
		no_anterior = no;
		no = no->proximo;
	}
	no_anterior->proximo = (ElementoLista*) NULL;
	free(no);
	
	return 1;
}

/**
*	Função adicionda - Exercício
* 	Questão 5
*/
int remover_aluno_lista_indice(ListaAluno* lista, int indice){
	if(lista == NULL || (indice < 0 || indice > tamanho_lista_aluno(lista))){
		return 0;
	}
	
	if(*lista == NULL){
		return 0;
	}
	
	ElementoLista *no_anterior, *no = *lista;
	int i = 0;
	while(no->proximo != NULL && i < indice){
		no_anterior = no;
		no = no->proximo;
		i++;
	}
	
	no_anterior->proximo = no->proximo;
	free(no);
	
	return 1;
}

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

/**
*	Função adicionda - Exercício
* 	Questão 6
*	Consulta aluno por matricula
*/
int consultar_aluno_lista_matricula(ListaAluno* lista, int matricula, Aluno* aluno){
	if(lista == NULL){
		return 0;
	}
	
	ElementoLista *no = *lista;
	
	while(no != NULL && no->aluno.matricula != matricula){
		no = no->proximo;
	}
	
	if(no == NULL){
		return 0;
	}
	
	*aluno = no->aluno;
		
	return 1;	
}
