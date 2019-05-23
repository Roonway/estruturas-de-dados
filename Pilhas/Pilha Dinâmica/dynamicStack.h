typedef struct {
	int cod;
	char* name;
	float salary;
}Element;

typedef struct list_no List;

typedef struct stack Stack;

Stack* stack_create();

int stack_push(Stack* pointer, Element element);

int stack_pop(Stack* pointer);

int stack_select(Stack* pointer, Element* element);

int stack_isEmpty(Stack* pointer);

void stack_delete(Stack* pointer);
