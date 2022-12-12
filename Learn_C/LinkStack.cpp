#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>




//链栈逻辑结构

typedef struct LinkStackNode {
	int elem;
	LinkStackNode* next;

}LinkStackNode,* LinkStack;
void init_linkstack(LinkStack &linkstack) {
	linkstack = NULL;

}
//入栈操作
void push_linkstack(LinkStack &linkstack,int elem) {
	LinkStackNode* newStackNode = (LinkStackNode*)malloc(sizeof(LinkStackNode));
	if (!newStackNode) printf("分配空间失败！\n"); return;
	newStackNode->elem = elem;
	newStackNode->next = linkstack;
	linkstack = newStackNode;
	printf("值:%d入栈成功，当前链栈的顶部地址为：%p\n",elem,newStackNode);


}
//出栈操作
void poplinkstack(LinkStack &linkstack,int &elem) {
	if (linkstack == NULL) printf("链栈为空，禁止出栈操作!\n"); return;
	LinkStack p = linkstack;
	elem = linkstack->elem;
	linkstack = linkstack->next;
	free(p);

}

//链栈打印操作
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
		printf("待插入值，请输入:");
		scanf("%d",&elem);
		push_linkstack(linkstack, elem);
	
	}
	printf("打印链栈，从顶到底分别为：\n");
	printf_linkstack(linkstack);
	
	return 0;
}