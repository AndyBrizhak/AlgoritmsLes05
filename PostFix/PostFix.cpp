#include<stdio.h>
#include<stdlib.h>
#include <locale.h>
//������ ������ �� �� ����� ��������� � ��������� ������. ������ 5.
//5. **����������� �������� �������� �� ��������� ������ ��������������� ��������� � �����������.

struct st                 /* �������� ��p����p�(�������� �����) */
{
	char c; struct st *next;
};
struct st *push(struct st *, char); /* �p������� ������� */
char DEL(struct st **);
int PRIOR(char);

void main(void)
{
	char *locale = setlocale(LC_ALL, "");
	struct st *OPERS = NULL;                     /* ���� ���p���� ���� */
	char a[80], outstring[80];
	int k, point;
	do
	{
		puts("������� ��p������(� ����� '='):");
		fflush(stdin);
		gets(a);                                 /* ���� �p������������� ��p������
												 */
		k = point = 0;
		while (a[k] != '\0'&&a[k] != '=')             /* �����p��� ,���� �� ������ ��
													  '=' */
		{
			if (a[k] == ')')                          /* ���� ���p����� ������ - ')' */
			{                                      /* �� ����������� �� ����� �
												   �������� ��p��� */
				while ((OPERS->c) != '(')               /* ��� ����� ���p���� �� ���������
														*/
					outstring[point++] = DEL(&OPERS);      /* ���p������� ������ */
				DEL(&OPERS);                         /* ������� �� ����� ����
													 ���p������� ������ */
			}
			if (a[k] >= 'a'&&a[k] <= 'z')               /* ���� ���p����� ������ - �����
														,�� */
				outstring[point++] = a[k];           /* ��p��������� � � ��������
													 ��p��� */
			if (a[k] == '(')                          /* ���� ���p����� ������ - '(' ,��
													  */
				OPERS = push(OPERS, '(');             /* ����������� � � ���� */
			if (a[k] == '+' || a[k] == '-' || a[k] == '/' || a[k] == '*')
			{                                      /* ���� ��������� ������ - ����
												   ���p���� ,��: */
				if (OPERS == NULL)                      /* ���� ���� ���� */
					OPERS = push(OPERS, a[k]);          /* ���������� � ���� ���p���� */
				else                                 /* ���� �� ���� */
					if (PRIOR(OPERS->c)<PRIOR(a[k]))      /* ���� �p��p���� �����������
														  ���p���� ������ �p��p����� ���p���� �� ��p���� ����� */
						OPERS = push(OPERS, a[k]);          /* ����������� �����������
															���p���� �� ���� */
					else                                 /* ���� �p��p���� ������ */
					{
						while ((OPERS != NULL) && (PRIOR(OPERS->c) >= PRIOR(a[k])))
							outstring[point++] = DEL(&OPERS); /* ��p��������� � �������� ��p���
															  ��� ���p���� � ������� ��� p����� �p��p������ */
						OPERS = push(OPERS, a[k]);             /* ���������� � ���� �����������
															   */
					}                                     /* ���p���� */
			}
			k++;                                    /* ��p���� � ���������� �������
													������� ��p��� */
		}
		while (OPERS != NULL)                        /* ����� p������p���� �����
													 ��p������ */
			outstring[point++] = DEL(&OPERS);       /* ��p��������� ��� ���p���� ��
													*/
		outstring[point] = '\0';                    /* ����� � �������� ��p��� */
		printf("\n%s\n", outstring);               /* � �������� � */
		fflush(stdin);
		puts("\n�����p���(y/n)?");
	} while (getchar() != 'n');
}

/* ������� push ���������� �� ���� (�� ��p���� ����p��� ��������� HEAD)
������ a . ����p����� ��������� �� ����� ��p���� ����� */
struct st *push(struct st *HEAD, char a)
{
	struct st *PTR;
	if ((PTR = malloc(sizeof(struct st))) == NULL) /* ��������� ������ */
	{
		puts("�� ������"); exit(-1);             /* ���� � ��� - ����� */
	}
	PTR->c = a;                                 /* ������������� ��������� ��p����
												*/
	PTR->next = HEAD;                           /* � ����������� � � ����� */
	return PTR;                               /* PTR -����� ��p���� ����� */
}

/* ������� DEL ������� ������ � ��p���� �����.
����p����� ��������� ������.�������� ��������� �� ��p���� ����� */
char DEL(struct st **HEAD)
{
	struct st *PTR;
	char a;
	if (*HEAD == NULL) return '\0'; /* ���� ���� ����, ����p������� '\0' */
	PTR = *HEAD;                   /* � PTR - ��p�� ��p���� ����� */
	a = PTR->c;
	*HEAD = PTR->next;             /* �������� ��p�� ��p���� ����� */
	free(PTR);                   /* ������������ ������ */
	return a;                    /* ����p�� ������� � ��p���� ����� */
}

/* ������� PRIOR ����p����� �p��p���� �p���. ���p���� */
int PRIOR(char a)
{
	switch (a)
	{
	case '*':
	case '/':
		return 3;

	case '-':
	case '+':
		return 2;

	case '(':
		return 1;
	}
}