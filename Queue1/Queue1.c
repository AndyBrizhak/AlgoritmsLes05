//������ ������ �� �� ����� ��������� � ��������� ������. ������ 6.

//  6. *����������� �������.
#include <locale.h>
#include <stdio.h>
#include <malloc.h>
#include <limits.h>

typedef struct node    // ����
{
	int value;           // ���� ��������
	struct node_t* next; // ��������� �� ��������� �������
}   Node;

typedef struct queue   // �������
{
	Node* head;         // ������� �������
	Node* tail;         // �����
}   Queue;

///*const*/ Queue* Myqueue;


// ������� ���������� �������� � �������
/*Queue**/ void Push(Queue* queue, int value)
{
	// �������� ������ ����
	Node* node = malloc(sizeof(Node));
	// ����������� �������� ������ ����
	node->value = value;
	// �.�. ������� ����������� � �����, �� ���������
	// �� ��������� ������� �� �� ��� �� ���������
	node->next = NULL;

	// ���� �������  �����, �� ...
	if (queue->head == NULL && queue->tail == NULL)
	{
		// ������ �������, ������ �� �
		// ������� � �����
		queue->head = node;
		queue->tail = node;
	}
	else
	{
		// ��������� ������� ������ ��������� ��
		// ��������� ����
		queue->tail->next = node;
		// ��������� ���� ���������� �������
		queue->tail = node;
	}
	///*
	//	*/return queue;
}

// ���������� �������� �� �������
int Pop(Queue* queue)
{
	int value = 0;
	Node* node;

	// ���� ���� �������� � �������
	if (queue->head)
	{
		// ��������� ��������� �� ��������� �������
		node = queue->head;
		// ��������� �������� ���������� ��������
		value = node->value;
		// �������� ������� ���������� ��������� �� ��������� �������
		queue->head = queue->head->next;
		// ������������ ������� �������
		free(node);
	}

	return value;
}

// ����� ���� ��������� �� �������
void Print(const Queue* queue)
{
	const Node* node = queue->head;

	// ���������� ��� �������� � ������� �� �� �������
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
		printf("������� ������� ������� : ");
		scanf("%d", &a);
		/*Queue* queue =*/ Push(Myqueue, a);
	}
	printf("\n");
	Print(Myqueue);

	getchar();
	return 0;
}
