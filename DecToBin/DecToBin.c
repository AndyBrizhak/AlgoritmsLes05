#include <stdio.h>
#include <malloc.h>
//#define T char
#define T int

//������ ������ �� �� ����� ��������� � ��������� ������. ������ 1.
//1. ����������� ������� �� ���������� � �������� ������� ��������� � �������������� �����.

// ������ ��������� ���� ������
struct TNode
{
	T value;
	struct TNode * next;
};
typedef struct TNode Node;
struct Stack
{
	Node * head;
	int size;
	int maxSize;
};
struct Stack Stack;

void push(T value)
{
	if (Stack.size >= Stack.maxSize) 
	{
		printf("Error stack size");
		return;
	}

	Node * tmp = (Node *)malloc(sizeof(Node));
	tmp->value = value;
	tmp->next = Stack.head;
	Stack.head = tmp;
	Stack.size++;
}

T pop()
{
	if (Stack.size == 0)
	{
		printf("Stack is empty");
		return;
	}
	// ��������� ���������
	Node * next = NULL;
	// �������� "�������" ������
	T value;
	value = Stack.head->value;
	next = Stack.head;
	Stack.head = Stack.head->next;
	// ������, �� ������� ��������� ������ �������, ���������� ������
	free(next);
	// ���������� ��������, ������� ���� � ������
	Stack.size--;
	return value;
}

void PrintStack()
{
	Node * current = Stack.head;
	while (current != NULL)
	{
		printf("%d ", current->value);
		current = current->next;
	}
}

int main(int argc, char * argv[])
{
	Stack.maxSize = 100;
	Stack.head = NULL;
	//push(1);
	//push(2);
	//push(3);
	//push(4);
	//push(5);
	//push(6);
	//PrintStack();
	//getch();
	//T current = pop();
	//printf("%d \n", current);
	//getch();
	//PrintStack();
	int n, value;

	printf("Input number : \n");
	scanf("%d", &value);
	printf("Input base : \n");
	scanf("%d", &n);
	do
	{
		push(value%n);
		value = value / n;
	} while (value > 0);

	PrintStack();
	getch();
	return 0;
}

