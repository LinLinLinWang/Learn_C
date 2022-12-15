#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include<malloc.h>
#define MAXSIZE 4
typedef struct SqQueue {
	int* base;
	int rear;
	int front;
}SqQueue;


//初始化循环队列

void InitSqQueue(SqQueue &sqQueue) {
	sqQueue.base = (int *)malloc(sizeof(int)* MAXSIZE);
	if (!sqQueue.base) {
		printf("分配内存失败 ！");
		return;
	}
	sqQueue.front = sqQueue.rear = 0;

}

//求队列长度
int getLength(SqQueue sqQueue) {
	
  	return (sqQueue.rear-sqQueue.front+ MAXSIZE)%MAXSIZE;         


}

//
//入队列操作

void EnQueue(SqQueue& sqQueue, int elem) {
	if ((sqQueue.rear + 1) % MAXSIZE == sqQueue.front) {

		printf("循环队列满了！退出操作");
		return;

	}

	sqQueue.base[(sqQueue.rear++) % MAXSIZE] = elem;



}
//出队列操作

void DeQueue(SqQueue &sqQueue,int &elem) {
   
	if (getLength(sqQueue) == 0) {

		printf("循环队列空了！");
		return;

	}
	elem = sqQueue.base[(sqQueue.front++) % MAXSIZE];

}
void PrintSqQueue(SqQueue sqQueue) {
	printf("开始从头打印队列！\n");
	int flag = sqQueue.front;
	if (getLength(sqQueue) ==0) {
		printf("队列是空的！");
		return;

	}

	do {
		printf("%d ",sqQueue.base[(sqQueue.front++)%MAXSIZE]);

	
	}while(sqQueue.front<sqQueue.rear);
	printf("\n");
}

int main() {
	SqQueue sqQueue;
	InitSqQueue(sqQueue);
	printf("开始入队列操作!");
	int i = 0;
	int elem = 0;
	while (i<=2) {
		printf("请输入第%d个值：",i+1);
		scanf("%d",&elem);
		EnQueue(sqQueue, elem);
		i++;
	
	}
	PrintSqQueue(sqQueue);
	printf("开始出队列操作!");
	int del;
	DeQueue(sqQueue, del);
	printf("被删除的数字是：%d\n", del);
	PrintSqQueue(sqQueue);
	DeQueue(sqQueue, del);
	printf("被删除的数字是：%d\n", del);
	PrintSqQueue(sqQueue);
	DeQueue(sqQueue, del);
	printf("被删除的数字是：%d\n", del);
	PrintSqQueue(sqQueue);
	DeQueue(sqQueue, del);
	printf("被删除的数字是：%d\n", del);
	PrintSqQueue(sqQueue);
	return 0;
}