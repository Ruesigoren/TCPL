#include <stdio.h>
#include <stdlib.h>

int *f();
int (*pf)();
char **argv;		//ָ���ַ���ָ���ָ��,�൱��ָ������
int (*daytab1)[13];	//ָ�������ָ��
int *daytab2[13];
void *comp1();
void (*comp2)();
char (*(*x())[])();
char (*(*y[3])())[5];


int fun();
char fun2();

int main()
{
	//int *test_1;

	//test_1 = f();
	//printf("%d", test_1[0]);

	//int test_2;

	//pf = fun;
	//test_2 = (*pf)();
	//printf("%d", test_2);

	//char *test_3[] = { "Hello", "World!" };

	//argv = test_3;
	//puts(argv[0]);
	//putchar(argv[0][1]);
	//puts(*argv);
	//puts(*++argv);
	//puts(*argv++);
	//putchar(*(argv[0] + 1));
	//putchar(*(++argv[0]));
	//putchar(**argv);
	//putchar(*(*argv + 1));

	//int test_4[2] = { 1, 2 };	//����±겻ͬ,�������ᾯ��
	//int test_4[13] = { 1, 2 };

	//daytab1 = &test_4;
	//printf("%d", (*daytab1)[0]);

	char(*(**test_5))() = (*(*x())[3])();

	getchar();
}

int *f()
{
	int s[] = { 1,2,3,4,5 };

	/* ��Ӧ�÷��ؾֲ������ĵ�ַ */
	return s;	//����Ϊ������
}

int fun()
{
	int s[] = { 1,2,3,4,5 };

	return s[1];
}

void *comp1()
{
	return NULL;
}

char fun2()
{
	return 'a';
}

char(*t1)() = fun2;
char(*t2)() = fun2;
char(*t3)() = fun2;
char(*a[3])();

char(*(*x())[])()
{
	char(*a[3])() = { t1,t2,t3 };

	//char(*(*b)[3])() = &a;
	return &a;
}