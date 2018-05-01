//Брижак Андрей ДЗ по курсу Алгоритмы и структуры данных. Задача 6.

//  6. *Реализовать очередь.
#include <locale.h>
#include <stdio.h>
#include <malloc.h>
#include <limits.h>

typedef struct node    // Узел
{
	int value;           // Само значение
	struct node_t* next; // Указатель на следующий элемент
}   Node;

typedef struct queue   // Очередь
{
	Node* head;         // Вершина очереди
	Node* tail;         // Хвост
}   Queue;

///*const*/ Queue* Myqueue;


// Функция добавления элемента в очередь
/*Queue**/ void Push(Queue* queue, int value)
{
	// Создание нового узла
	Node* node = malloc(sizeof(Node));
	// Присваиваем значение новому узлу
	node->value = value;
	// Т.к. элемент добавляется в хвост, то указатель
	// на следующий элемент ни на что не ссылается
	node->next = NULL;

	// Если очередь  пуста, то ...
	if (queue->head == NULL && queue->tail == NULL)
	{
		// Первый элемент, теперь он и
		// вершина и хвост
		queue->head = node;
		queue->tail = node;
	}
	else
	{
		// Хвостовой элемент теперь ссылается на
		// созданный узел
		queue->tail->next = node;
		// Созданный узел становится хвостом
		queue->tail = node;
	}
	///*
	//	*/return queue;
}

// Извлечение элемента из очереди
int Pop(Queue* queue)
{
	int value = 0;
	Node* node;

	// Пока есть элементы в очереди
	if (queue->head)
	{
		// Сохраняем указатель на удаляемый элемент
		node = queue->head;
		// Сохраняем значение удаляемого элемента
		value = node->value;
		// Вершиной очереди становится следующий за удаляемым элемент
		queue->head = queue->head->next;
		// Окончательно удаляем элемент
		free(node);
	}

	return value;
}

// Вывод всех элементов на дисплей
void Print(const Queue* queue)
{
	const Node* node = queue->head;

	// Перебираем все элементы и выводим их на дисплей
	for (; node; node = node->next)
	{
		printf("%d ", node->value);
	}
	printf("\n");
}





int main() {
	char *locale = setlocale(LC_ALL, "");
	/*Queue* queue;*/
	Queue* Myqueue = malloc(sizeof(Queue));
	Myqueue->head = NULL;
	Myqueue->tail = NULL;
	int a;
	for (int i = 0; i<3; i++)
	{
		printf("Введите элемент очереди : ");
		scanf("%d", &a);
		/*Queue* queue =*/ Push(Myqueue, a);
	}
	printf("\n");
	Print(Myqueue);

	getchar();
	return 0;
}
