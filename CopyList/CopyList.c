//Брижак Андрей ДЗ по курсу Алгоритмы и структуры данных. Задача 4.

// *Создать функцию, копирующую односвязный список(то есть создает в памяти копию односвязного списка, не удаляя первый список).

// Опишем структуру узла списка
#include <stdio.h>
#include <malloc.h>


typedef struct Node {
	int value;
	struct Node *next;
} Node;

const Node *head1;
const Node *head2;


void push(Node **head, int data)
{
	Node *tmp = (Node*)malloc(sizeof(Node));
	tmp->value = data;
	tmp->next = (*head);
	(*head) = tmp;
}

Node* getLast(Node *head) {
	if (head == NULL) {
		return NULL;
	}
	while (head->next) {
		head = head->next;
	}
	return head;
}

void fromArray(Node **head, int *arr, size_t size) {
	size_t i = size - 1;
	if (arr == NULL || size == 0) {
		return;
	}
	do {
		push(head, arr[i]);
	} while (i-- != 0);
}

int* toArray(const Node *head, int leng) {
	/*int leng = length(head);*/
	int *values = (int*)malloc(leng * sizeof(int));
	int i = 0;
	//while (head) {
	//	values[--leng] = head->value;
	//	head = head->next;
	//}
	while (i<leng) {
			values[i++] = head->value;
			head = head->next;
		}
	return values;
}

void printLinkedList( Node *head) {
	while (head) {
		printf("%d ", head->value);
		head = head->next;
	}
	printf("\n");
}

void pushBack(Node *head, int value) {				//добавляет новый элемент в конец списка
	Node *last = getLast(head);
	Node *tmp = (Node*)malloc(sizeof(Node));
	tmp->value = value;
	tmp->next = NULL;
	last->next = tmp;
}

int main(int argc, char * argv[])
{
	Node *head1 = NULL;
	Node *head2 = NULL;
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	//Создаём список из массива
	fromArray(&head1, arr, 10);
	printLinkedList(head1);
	getch();
	int*CopyAr = toArray(head1, 10);
	fromArray(&head2, CopyAr, 10);
	printLinkedList(head2);
		
	getch();
	return 0;
}
