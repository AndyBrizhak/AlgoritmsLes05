#include <stdio.h>
#include <malloc.h>
#define T char

//������ ������ �� �� ����� ��������� � ��������� ������. ������ 3.
//3. �������� ���������, ������� ����������, �������� �� ��������� ��������� ������������������ ����������.
//������� ���������� ��������� ��������� : (), ([])(), {}(), ([{}]), ������������ � )(, ())({ ), (, ]) }), ([(]) ��� ������[, (, { .
//�� ���� �� ������ ������.������ ���, ����� ���������� ����������� ������ - ������ � � ����.������ ���, ����� ���������� ����������� - �������� �� ����� ����� ���������� ������.
//
//���� ����� ������ ������ �� �����, � �� ��� ������ �� �������� - ������������������ ������������.
//���� ����� ������� ������ � ����� �������� ������ ������ - ������������������ ������������.�� ���� ��������� ������� - ����������.
//
//��� �� ����� ��������� ������������������, � ������� ���� ������ ������ - �������, ����������, �������� � �.�.
//������ � ��� ���������, ������� � ������ ����, ����������� ��� �������� �� ��, ��� ���������� �� ����� ����������� ������ 
//�� ����� ������ ��������� � ��� �����������, ������� � ��� ������ ����������� � ������.

// ������ ��������� ���� ������
struct TNode
{
	T value;
	struct TNode * next;
};
typedef struct TNode Node;

char in_string[100];

struct Stack
{
	Node * head;
	int size;
	int maxSize;
};
struct Stack Stack;
void push(T value)
{
	if (Stack.size >= Stack.maxSize) {
		printf("Error stack size");
		return;
	}
	Node * tmp = (Node *)malloc(sizeof(Node));
	tmp->value = value;
	tmp->next = Stack.head;
	Stack.head = tmp;
	Stack.size++;
}

T pop() {
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
		printf("%c ", current->value);
		current = current->next;
	}
}

int main(int argc, char * argv[])
{
	Stack.maxSize = 100;
	Stack.head = NULL;
	
	printf("Input  : \n");
	gets(in_string); // ������� gets() ��������� ��� �������� ������� � ��������� �� ��� ���, 
						//���� �� ����� ������ ������� Enter { [2 / {5 * (4 + 7)}] }
	int i = 0;
	for ( i = 0; i < 100-1; i++)
	{
		switch (in_string[i])
		{
			case '(':
				push(in_string[i]);
				break;
			case ')':
				if (pop() == '(')
				{
					push('(');
					pop();
				}
				break;

			case '{':
				push(in_string[i]);
				break;
			case '}':
				if (pop() == '{')
				{
					push('{');
					pop();
				}
				break;

			case '[':
				push(in_string[i]);
				break;
			case ']':
				if (pop() == '[')
				{
					push('[');
					pop();
				}
				break;
			default:
				break;
		}
	}
	if (Stack.size != 0)
	{
		printf("Error char :");
		PrintStack();
	}
	else
	{
		printf("It`s all right");
	}
	getch();
	return 0;
}