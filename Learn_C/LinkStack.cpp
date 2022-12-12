#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>




//��ջ�߼��ṹ

typedef struct LinkStackNode {
	int elem;
	LinkStackNode* next;

}LinkStackNode,* LinkStack;
void init_linkstack(LinkStack &linkstack) {
	linkstack = NULL;

}
//��ջ����
void push_linkstack(LinkStack &linkstack,int elem) {
	LinkStackNode* newStackNode = (LinkStackNode*)malloc(sizeof(LinkStackNode));
	if (!newStackNode) printf("����ռ�ʧ�ܣ�\n"); return;
	newStackNode->elem = elem;
	newStackNode->next = linkstack;
	linkstack = newStackNode;
	printf("ֵ:%d��ջ�ɹ�����ǰ��ջ�Ķ�����ַΪ��%p\n",elem,newStackNode);


}
//��ջ����
void poplinkstack(LinkStack &linkstack,int &elem) {
	if (linkstack == NULL) printf("��ջΪ�գ���ֹ��ջ����!\n"); return;
	LinkStack p = linkstack;
	elem = linkstack->elem;
	linkstack = linkstack->next;
	free(p);

}

//��ջ��ӡ����
void printf_linkstack(LinkStack  linkstack) {

	while (linkstack)
	{
		printf("%d ",linkstack->elem);
		linkstack = linkstack->next;
	}
	printf("\n");
}


int main() {
	
	LinkStack linkstack;
	init_linkstack(linkstack);
	int i = 0;
	int elem = 0;
	for (i = 0; i <= 3; i++) {
		printf("������ֵ��������:");
		scanf("%d",&elem);
		push_linkstack(linkstack, elem);
	
	}
	printf("��ӡ��ջ���Ӷ����׷ֱ�Ϊ��\n");
	printf_linkstack(linkstack);
	
	return 0;
}