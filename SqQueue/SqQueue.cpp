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


//��ʼ��ѭ������

void InitSqQueue(SqQueue &sqQueue) {
	sqQueue.base = (int *)malloc(sizeof(int)* MAXSIZE);
	if (!sqQueue.base) {
		printf("�����ڴ�ʧ�� ��");
		return;
	}
	sqQueue.front = sqQueue.rear = 0;

}

//����г���
int getLength(SqQueue sqQueue) {
	
  	return (sqQueue.rear-sqQueue.front+ MAXSIZE)%MAXSIZE;         


}

//
//����в���

void EnQueue(SqQueue& sqQueue, int elem) {
	if ((sqQueue.rear + 1) % MAXSIZE == sqQueue.front) {

		printf("ѭ���������ˣ��˳�����");
		return;

	}

	sqQueue.base[(sqQueue.rear++) % MAXSIZE] = elem;



}
//�����в���

void DeQueue(SqQueue &sqQueue,int &elem) {
   
	if (getLength(sqQueue) == 0) {

		printf("ѭ�����п��ˣ�");
		return;

	}
	elem = sqQueue.base[(sqQueue.front++) % MAXSIZE];

}
void PrintSqQueue(SqQueue sqQueue) {
	printf("��ʼ��ͷ��ӡ���У�\n");
	int flag = sqQueue.front;
	if (getLength(sqQueue) ==0) {
		printf("�����ǿյģ�");
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
	printf("��ʼ����в���!");
	int i = 0;
	int elem = 0;
	while (i<=2) {
		printf("�������%d��ֵ��",i+1);
		scanf("%d",&elem);
		EnQueue(sqQueue, elem);
		i++;
	
	}
	PrintSqQueue(sqQueue);
	printf("��ʼ�����в���!");
	int del;
	DeQueue(sqQueue, del);
	printf("��ɾ���������ǣ�%d\n", del);
	PrintSqQueue(sqQueue);
	DeQueue(sqQueue, del);
	printf("��ɾ���������ǣ�%d\n", del);
	PrintSqQueue(sqQueue);
	DeQueue(sqQueue, del);
	printf("��ɾ���������ǣ�%d\n", del);
	PrintSqQueue(sqQueue);
	DeQueue(sqQueue, del);
	printf("��ɾ���������ǣ�%d\n", del);
	PrintSqQueue(sqQueue);
	return 0;
}