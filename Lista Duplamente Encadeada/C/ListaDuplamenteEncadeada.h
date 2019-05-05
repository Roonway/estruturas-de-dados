struct aluno {
	int matricula;
	char nome[60];
	float nota1, nota2;
};

typedef struct aluno Aluno;

typedef struct elemento* ListaAluno;

ListaAluno* criar_lista_aluno();

void destruir_lista_aluno(ListaAluno* );

int tamanho_lista_aluno(ListaAluno* );

int lista_aluno_vazia(ListaAluno* );

//int inserir_aluno_lista(ListaAluno* lista, Aluno aluno);

/**
*	Insersão de elementos em ordem alfabética 
*/
int insertElement(ListaAluno* , Aluno );

//int remover_aluno_lista(ListaAluno* lista, int indice);

/**
*	Remoção de elementos através da matricula
*/
int removeElement(ListaAluno* , int);

//int consultar_aluno_lista(ListaAluno* lista, int indice, Aluno* aluno);

/**
*	Consulta um elementos na lista através do nome
*/
int getElementeByName(ListaAluno* , char* ,  Aluno* );

/**
*	Consulta um elementos na lista através da matricula
*/
int getElementeByMatricula(ListaAluno* , int ,  Aluno* );
