//Брижак Андрей ДЗ по курсу Алгоритмы и структуры данных. Задача 6.

//  6. *Реализовать очередь.
#include <locale.h>
#include <stdio.h>
#include <malloc.h>


struct list {
	int field;
	struct list *ptr;
};

struct queue {
	struct list *frnt, *rear;
};

void init(struct queue *q) {
	q->frnt = 0;
	q->rear = 0;
}

int isempty(struct queue *q) {
	if (q->frnt == 0)
		return(1);
	else
		return(0);
}

void insert(struct queue *q, int x) {
	/*if ((q->rear == 0) && (q->frnt == 0)) {*/
		q->rear = x;
		q->frnt = q->rear;
	/*}*/
	/*else
		q->rear = addelem(q->rear, x);*/
}

void print(struct queue *q) {
	struct list *h;
	if (isempty(q) == 1) {
		printf("Очередь пуста!\n");
		return;
	}
	else 
	{
		/*h = q->frnt; h <= q->rear; h++*/
		h = q->frnt;
		while (h != NULL)
		{
			printf("%d ", h->field);
		}
		h = h->ptr;
	}
	
	return;
}

int test(struct queue *q) {
	int x;
	x = q->frnt->field;
	return(x);
}

int main() {
	char *locale = setlocale(LC_ALL, "");
	struct queue *q;
	int a;
	
	q = (struct queue*)malloc(sizeof(struct queue*));
	init(q);
	print(q);
	for (int i = 0; i<8; i++) {
		printf("Введите элемент очереди : ");
		scanf("%d", &a);
		insert(q, a);
	}
	printf("\n");
	print(q);
	while (q->frnt != NULL) {
		a = remove(q);
		printf(" \n Удален элемент %d \n", a);
		print(q);
	}
	getchar(); getchar();
	return 0;
}

