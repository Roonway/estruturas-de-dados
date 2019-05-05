typedef struct {
	int matricula;
	char nome[60];
	float nota1, nota2;
}Aluno;

typedef struct elemento* ListaAluno;

ListaAluno* criar_lista_aluno();

void destruir_lista_aluno(ListaAluno* lista);

int tamanho_lista_aluno(ListaAluno* lista);

int lista_aluno_vazia(ListaAluno* lista);

int inserir_aluno_lista(ListaAluno* lista, Aluno aluno);

/**
*	Função adicionda - Exercício
* 	Questão 1
*	Inseri aluno no início da lista
*/
int inserir_aluno_lista_inicio(ListaAluno* lista, Aluno aluno);

/**
*	Função adicionda - Exercício
* 	Questão 2
*	Inserir aluno de forma ordenada na lista por matricula
*/
int inserir_aluno_lista_order(ListaAluno* lista, Aluno aluno);

int remover_aluno_lista(ListaAluno* lista, int matricula);

/**
*	Função adicionda - Exercício
* 	Questão 3
*	Remove aluno do início da lista
*/
int remover_aluno_lista_inicio(ListaAluno* lista);

/**
*	Função adicionda - Exercício
* 	Questão 4
*	Remove aluno do final da lista
*/
int remover_aluno_lista_final(ListaAluno* lista);

/**
*	Função adicionda - Exercício
* 	Questão 5
*	Remove aluno do final da lista por meio de índice
*/
int remover_aluno_lista_indice(ListaAluno* lista, int indice);

int consultar_aluno_lista(ListaAluno* lista, int indice, Aluno* aluno);

/**
*	Função adicionda - Exercício
* 	Questão 6
*	Consulta aluno por matricula
*/
int consultar_aluno_lista_matricula(ListaAluno* lista, int indice, Aluno* aluno);
