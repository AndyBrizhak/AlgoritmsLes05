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

void printLinkedList( Node *head) {
	while (head) {
		printf("%d ", head->value);
		head = head->next;
	}
	printf("\n");
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
	return 0;
}
