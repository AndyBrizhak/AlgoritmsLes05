#include <stdio.h>
#include <malloc.h>
#define T char

//Брижак Андрей ДЗ по курсу Алгоритмы и структуры данных. Задача 3.
//3. Написать программу, которая определяет, является ли введенная скобочная последовательность правильной.
//Примеры правильных скобочных выражений : (), ([])(), {}(), ([{}]), неправильных — )(, ())({ ), (, ]) }), ([(]) для скобок[, (, { .
//Вы идёте от начала строки.Каждый раз, когда встречаете открывающую скобку - кладёте её в стек.Каждый раз, когда встречаете закрывающую - убираете из стека ранее положенную скобку.
//
//Если нужно убрать скобку из стека, а их там больше не осталось - последовательность неправильная.
//Если после разбора строки в стеке остались лишние скобки - последовательность неправильная.Во всех остальных случаях - правильная.
//
//Так же можно проверять последовательность, в которой есть разные скобки - круглые, квадратные, фигурные и т.п.
//Просто к тем проверкам, которые я описал выше, добавляется ещё проверка на то, что забираемая из стека открывающая скобка 
//по форме должна совпадать с той закрывающей, которая у вас сейчас встретилась в строке.

// Опишем структуру узла списка
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
	// Временный указатель
	Node * next = NULL;
	// Значение "наверху" списка
	T value;
	value = Stack.head->value;
	next = Stack.head;
	Stack.head = Stack.head->next;
	// Запись, на которую указывала голова удаляем, освобождая память
	free(next);
	// Возвращаем значение, которое было в голове
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
	gets(in_string); // функция gets() считывает все введённые символы с пробелами до тех пор, 
						//пока не будет нажата клавиша Enter { [2 / {5 * (4 + 7)}] }
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