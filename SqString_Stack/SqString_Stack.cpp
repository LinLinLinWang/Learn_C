#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXSIZE 100

/// <summary>
//静态存储串
/// </summary>
typedef struct SqString_Stack {
	char data[MAXSIZE];
	int length;//当前长度



}SqString_Stack;
void Printf_String(SqString_Stack sqstring);

//初始化
void InitString(SqString_Stack& sqString) {
	
	memset(sqString.data, '\0', sizeof(char) * 100);
	sqString.length = 0;
}

//串赋值

void InsertString(SqString_Stack& sqstring) {
	int i = 0;
	char elem;
	printf("请输入值,回车将会强制退出！\n");
	scanf("%c",&elem);
	printf("值为%c\n",elem);
	while (elem != '\n') {
	   
		
		if (i > MAXSIZE - 2) {
		
			printf("禁止插入！串满\n");
			return;
		
		}
		
		sqstring.data[i] = elem;
		sqstring.length++;
		i++;
		scanf("%c", &elem);
		printf("值为%d\n", elem);
	}
	sqstring.data[i] = '\0';
	printf("录入串完毕！\n");







}


//串插入 将一个串插入主串pos前

void StrInsert(SqString_Stack& sqString, int pos, SqString_Stack s) {
	if (pos<0 || pos>sqString.length) {
		printf("位置不合法！\n");
		return;
	
	}
	if (s.length + sqString.length > MAXSIZE - 1) {
		printf("主串内存将溢出！！将舍弃部分字符\n");


		//插入串的length-(主串的MAXSIZE-主串length-1)  = X
		//x为主串pos位置（含pos）从尾部需要舍弃的个数
		//如果x<主串length-pos， 则需将主串（length-1-x)至pos位置往后移动x位

		int x = s.length - (MAXSIZE - sqString.length - 1);
		if (x < sqString.length - pos) {
		
			for (int i = sqString.length - 1; i <= pos;i--) {
			
				sqString.data[i + x] = sqString.data[i];

			}

			for (int i = 0; i < s.length; i++) {
			
				sqString.data[pos + i] = s.data[i];
			    
			  
			}

			sqString.length = MAXSIZE-1;
			sqString.data[MAXSIZE] = '\0';
		
		}


		//如果x>主串length-pos
		//直接将插入串覆盖掉pos（含pos）之后的位置



		else {
			for (int i = pos; i < sqString.length; i++) {

				sqString.data[pos + i] = s.data[i];

			}

			sqString.length = MAXSIZE - 1;
			sqString.data[MAXSIZE] = '\0';
		
		
		
		
		
		}
  		









	
	}
	else {
	//将主串中pos之后字符向后移动s.length个 位置
	for (int i = sqString.length; i >= pos ; i--) {
	   	  
		sqString.data[i + s.length] = sqString.data[i];
	
	
	}
	printf("调整顺序后！");
	Printf_String(sqString);
	for (int i = 0; i < s.length;i++) { 
	 
		sqString.data[pos  + i] = s.data[i];
	
	}

	sqString.length = sqString.length + s.length;



	}



}


//打印串
void Printf_String(SqString_Stack sqstring) {
int 	i = 0;
while (sqstring.data[i] != '\0') {

	printf("%c",sqstring.data[i]);
	i++;
}
printf("\n");

}
int main() {

	SqString_Stack sqstring;
	SqString_Stack  sstring;
	printf("初始化串中。。。。\n");
	InitString(sqstring);
	InitString(sstring);
	printf("初始化完毕。。。。\n");

	printf("请给主串赋值！按回车结束！\n");
	InsertString(sqstring);
	printf("打印主串。共有%d个值 。。。\n",sqstring.length);
	Printf_String(sqstring);
	printf("请给子串赋值！按回车结束！\n");
	InsertString(sstring);
	printf("打印主子串。共有%d个值。。。\n",sstring.length);
	Printf_String(sstring);
	printf("执行插入操作！\n");
	StrInsert(sqstring, -1, sstring);
	printf("打印主串。共有%d个值 。。。\n", sqstring.length);
	Printf_String(sqstring);
	return 0;

}