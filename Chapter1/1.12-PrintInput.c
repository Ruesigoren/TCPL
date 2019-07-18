#include <stdio.h>

#define IN	1
#define OUT	0

/* 以每行一个单词的形式打印输入*/
main()
{
	int c, state;

	//nw = 0;
	state = OUT;
	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\n' || c == '\t') {	//空格状态
			if (state == IN) {		//变化3
				putchar('\n');
				state = OUT;
			}
			//变化1 不做任何操作
		}
		else if (state == OUT) {	//非空格状态，变化4
			state = IN;
			putchar(c);
			//++nw;
			//if (nw != 1)
			//	putchar('\n');
		}
		else  //非空格状态，变化2
			putchar(c);
	}
}

//由每行以一个单词形式打印输入得出的思考
//1.判断何时开始打印单词
//2.判断何时打印换行符
//
//2种状态，空格和非空格
//4种变化：1，连续空格	2，连续字符	3，由单词转变为空格	4，由空格转变为单词
//变化1，不需要打印单词和换行符
//变化2，打印单词，但不打印换行符
//变化3，打印换行符
//变化4，打印单词