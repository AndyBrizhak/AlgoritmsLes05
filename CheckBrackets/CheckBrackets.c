#include <stdio.h>
#include <malloc.h>
#define T char

//Брижак Андрей ДЗ по курсу Алгоритмы и структуры данных. Задача 3.
//3. Написать программу, которая определяет, является ли введенная скобочная последовательность правильной.
//Примеры правильных скобочных выражений : (), ([])(), {}(), ([{}]), неправильных — )(, ())({ ), (, ]) }), ([(]) для скобок[, (, { .
//На самом деле, всё очень просто.
//
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
	push('a');
	push('b');
	push('c');
	push('d');
	push('e');
	push('f');
	PrintStack();
	getch();
	return 0;
}