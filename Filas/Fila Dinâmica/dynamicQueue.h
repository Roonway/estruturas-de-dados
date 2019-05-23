typedef struct{
	int cod;
	char* name;
	float salary;
} Element;

typedef struct list_no List;

typedef struct queue Queue;

Queue* queue_create();

int queue_insert(Queue* pointer, Element element);

int queue_remove(Queue* pointer);

int queue_select(Queue* pointer, Element* element);

int queue_isEmpty(Queue* pointer);

void queue_delete(Queue* pointer);
