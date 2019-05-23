typedef struct {
	int matricula;
	char nome[60];
	float nota1, nota2;
}Aluno;

typedef struct elemento* ListaAluno;

ListaAluno* listaCircular_create();

void listaCircular_delete(ListaAluno* lista);

int listaCircular_isEmpty(ListaAluno* lista);

int listaCircular_insert(ListaAluno* lista, Aluno aluno);

int listaCircular_remove(ListaAluno* lista, int matricula);

int listaCircular_select(ListaAluno* lista, int indice, Aluno* aluno);

