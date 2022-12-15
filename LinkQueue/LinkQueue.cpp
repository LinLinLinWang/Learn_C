#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<stdlib.h>

//队列的链式存储
typedef struct QueueNode {
	int elem;
	QueueNode *next;


}QueueNode,* NodePtr;

typedef struct LinkQueue {

	NodePtr front;
	NodePtr rear;

}LinkQueue,*LinkQueuePtr;


//初始化链式队列
void InitQueue(LinkQueue &linkqueue){

	linkqueue.front = linkqueue.rear = (NodePtr)malloc(sizeof(QueueNode));
	if (!linkqueue.front) {

		printf("内存分配失败！");
		return;
	}
	linkqueue.front->next = NULL;
	linkqueue.front->elem = -99999;

}




void EnLinkQueue(LinkQueue &linkqueue,int elem) {
	QueueNode* newqueue = (NodePtr)malloc(sizeof(QueueNode));
	if (!newqueue) {
	
		printf("分配空间失败！\n");
		return;
	}
	newqueue->elem = elem;
	newqueue->next = NULL;
	linkqueue.rear->next= newqueue;
	linkqueue.rear = newqueue;


}
void DeLinkQueue(LinkQueue& linkqueue, int elem) {
	
	if (linkqueue.front= linkqueue.rear) {
	
		printf("禁止出队！");
		return;
	}
	NodePtr del = linkqueue.front->next;
	linkqueue.front = linkqueue.front->next;
	elem = del->elem;
	if (linkqueue.rear = del)
	{
		linkqueue.rear = linkqueue.front; //着重注意！！！
	}
	free(del);
}


void PrintfLinkQueue(LinkQueue &linkqueue) {
	NodePtr p = linkqueue.front->next;
	while (p!=NULL) {
		printf("从头到尾打印队列！");
		printf("%d ",p->elem);

		p = p->next;
	}
	printf("\n");

}

int main() {
	printf("创建链式存储！\n");
	LinkQueue linkqueue;
	InitQueue(linkqueue);
	int elem = -1;
	while (elem!=-9999) {
		printf("请输入值:");
		scanf("%d",&elem);
		EnLinkQueue(linkqueue, elem);
	
	
	}
	PrintfLinkQueue(linkqueue);
	int del = 0;
	DeLinkQueue(linkqueue,del);
	printf("被删除元素值为：%d\n",del);
	printf();
	return 0;

}
