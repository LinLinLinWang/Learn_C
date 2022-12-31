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
//串删除(含pos位置)
void DeleteString(SqString_Stack &sq,int pos,int len) {
	if (len<1 || pos>(sq.length-len+1))
	{
		printf("删除失败，删除位置不合理\n");

		return;
	}
	else {
	
		for (int i = pos+len; i <=sq.length; i++) {
			sq.data[i-len] = sq.data[i];
		
		
		}

		sq.length = sq.length - len;

	
	}
       



}
//串的模式匹配（朴素比较）

int Pattern_String(SqString_Stack &sq,SqString_Stack &patten,int &pos) {
	int flag;
	//位置初始定于主串头部
	int j = 0;//主串待比较位置
	int k = 0;//模式串待比较位置

		j = pos;
		
		k = 0;
		while (j<sq.length&&k<patten.length) {
		          
			if (sq.data[j] == patten.data[k]) {
				j++;
				k++;
			   
			}
			else {
				k = 0;
				j = ++pos;
				
			
			}
		
		
		}
	
		if (k == patten.length) return pos;//匹配成功
	
		return -1;
	


}




//求next数组  kmp尚未优化
int* getNext(SqString_Stack pattern) {
	int len = pattern.length;
	int* next = (int*)malloc(sizeof(int) * pattern.length);
	next[0] = -1;
	if (pattern.length == 0)return NULL;
	if (pattern.length==1) {
		return next;
	}

	
	int i = -1;//当前j所指向位置（不 含当前元素）的最长公共前缀长度，也是j-1元素回退的位置
	int j = 1;//
	while (j<pattern.length) {
		if (i == -1 || pattern.data[i] == pattern.data[j]) {
			i++;
			next[j] = i;
			j++;
		           
		
		
		}
		else {
		
			i = next[i];

		}
	
	}
	
 	return next;
}

//优化后的kmp  原因是kmp算法在比较字符串时 也会有个别冗余比较。

int* getNext_After(SqString_Stack pattern) {
	int len = pattern.length;
	int* next = (int*)malloc(sizeof(int) * pattern.length);
	next[0] = -1;
	if (pattern.length == 0)return NULL;
	if (pattern.length == 1) {
		return next;
	}


	int i = -1;//当前j所指向位置（不 含当前元素）的最长公共前缀长度，也是j-1元素回退的位置
	int j = 1;//

	while (j < pattern.length) {
		if (i == -1 || pattern.data[i] == pattern.data[j]) {
			
			if (pattern.data[i+1] == pattern.data[j]) {
				i++;
				next[j++] = next[i];
			    
			
			
			}
			else {
				next[j++] = ++i;
			
			
			}


		}
		else {

			i = next[i];

		}
		

	}
	return next;




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

//查找子串是否存在


int IsExistPattern(SqString_Stack major,SqString_Stack pattern) {

	
	int i = 0;
	int j = 0;
	int* getnext = getNext_After(pattern);
	while (i<major.length&&j<pattern.length) {
		if (j==-1||major.data[i] == pattern.data[j]) {
			i++;
			j++;
		
		}
		else {
		
			j = getnext[j];


		
		}
		
	
	
	}
	if (j == pattern.length) {
		return i - j;


	}



	return -1;

}




int main() {
	int reslult=0;
	int pos = 0;
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
	/*printf("执行插入操作！\n");
	StrInsert(sqstring, -1, sstring);
	printf("打印主串。共有%d个值 。。。\n", sqstring.length);
	Printf_String(sqstring);
	
	printf("开始进行删除操作！\n");
	DeleteString(sqstring,0,5);
	printf("打印主串。共有%d个值。。。\n", sqstring.length);
	Printf_String(sqstring);
	
	Printf_String(sqstring);
	
	printf("请给子串赋值！按回车结束！\n");
	InsertString(sstring);
	printf("打印主子串。共有%d个值。。。\n", sstring.length);
	Printf_String(sstring);
	*/
	printf("开始模式匹配！。。\n");
	reslult=Pattern_String(sqstring, sstring, pos);
	if (reslult!= -1) {
		printf("模式匹配成功！在主串pos=%d处发现字串。。\n",pos);
		

	
	}
	else {
		printf("模式匹配失败！\n");
	
	}
	printf("使用kmp匹配结果%d\n",IsExistPattern(sqstring, sstring));

	return 0;

}