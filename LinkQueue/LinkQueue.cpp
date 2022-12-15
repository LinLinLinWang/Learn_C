#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<stdlib.h>

//���е���ʽ�洢
typedef struct QueueNode {
	int elem;
	QueueNode *next;


}QueueNode,* NodePtr;

typedef struct LinkQueue {

	NodePtr front;
	NodePtr rear;

}LinkQueue,*LinkQueuePtr;


//��ʼ����ʽ����
void InitQueue(LinkQueue &linkqueue){

	linkqueue.front = linkqueue.rear = (NodePtr)malloc(sizeof(QueueNode));
	if (!linkqueue.front) {

		printf("�ڴ����ʧ�ܣ�");
		return;
	}
	linkqueue.front->next = NULL;
	linkqueue.front->elem = -99999;

}




void EnLinkQueue(LinkQueue &linkqueue,int elem) {
	QueueNode* newqueue = (NodePtr)malloc(sizeof(QueueNode));
	if (!newqueue) {
	
		printf("����ռ�ʧ�ܣ�\n");
		return;
	}
	newqueue->elem = elem;
	newqueue->next = NULL;
	linkqueue.rear->next= newqueue;
	linkqueue.rear = newqueue;


}
void DeLinkQueue(LinkQueue& linkqueue, int elem) {
	
	if (linkqueue.front= linkqueue.rear) {
	
		printf("��ֹ���ӣ�");
		return;
	}
	NodePtr del = linkqueue.front->next;
	linkqueue.front = linkqueue.front->next;
	elem = del->elem;
	if (linkqueue.rear = del)
	{
		linkqueue.rear = linkqueue.front; //����ע�⣡����
	}
	free(del);
}


void PrintfLinkQueue(LinkQueue &linkqueue) {
	NodePtr p = linkqueue.front->next;
	while (p!=NULL) {
		printf("��ͷ��β��ӡ���У�");
		printf("%d ",p->elem);

		p = p->next;
	}
	printf("\n");

}

int main() {
	printf("������ʽ�洢��\n");
	LinkQueue linkqueue;
	InitQueue(linkqueue);
	int elem = -1;
	while (elem!=-9999) {
		printf("������ֵ:");
		scanf("%d",&elem);
		EnLinkQueue(linkqueue, elem);
	
	
	}
	PrintfLinkQueue(linkqueue);
	int del = 0;
	DeLinkQueue(linkqueue,del);
	printf("��ɾ��Ԫ��ֵΪ��%d\n",del);
	printf();
	return 0;

}
