typedef struct stack_struct Stack;

typedef struct {
	int cod;
	char* livro;
} Element;

Stack* stack_create(int dimension);

int stack_push(Stack* pointer, Element number);

Element stack_pop(Stack* pointer);

int stack_isEmpty(Stack* pointer);

int stack_isFull(Stack* pointer);

int stack_actionReallocate(Stack* pointer, int amount);

void stack_delete(Stack* pointer);
