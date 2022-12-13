#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>


//����洢�ṹ
typedef struct LinkNode{
	int elem;
	LinkNode* next;

}LinkNode,*LinkList;

//�����ʼ��
void InitLinkList(LinkList &linklist) {
	LinkNode  *headnode =(LinkNode*)malloc(sizeof(LinkNode));
	headnode->elem = -99999;
	headnode->next = NULL;
	linklist = headnode;
}

//��ͷ���ǰ�巨
void addLinkNode_head(LinkList& linklist, int elem) {
	LinkNode* newnode = (LinkNode*)malloc(sizeof(LinkNode));
	if (newnode == NULL) {
		printf("�ڴ����ʧ�ܣ�");
		return;
	}
	newnode->elem = elem;
	newnode->next = linklist->next;
	linklist->next = newnode;
	
}
//��ͷ���β�巨

void   addLinkNode_tail(LinkList& linklist, int nums) {
	int elem;
	LinkNode* tail = linklist;
	
	for (int i = 0; i < nums;i++) {
		printf("ʹ��β�巨������,�������%d�����ֵ��",i+1);
		scanf("%d",&elem);
		LinkNode* newnode = (LinkNode*)malloc(sizeof(LinkNode));
		if (newnode == NULL) {
			printf("�ڴ����ʧ�ܣ�\n");
			return;
		}
		newnode->elem = elem;
		newnode->next = NULL;
		tail->next = newnode;
		tail = newnode;

	}




};


//��ӡ����

void  Printf_LinkList(LinkList linklist) {
	linklist = linklist->next;
	printf("��ʼ��ӡ����!\n");
	while (linklist) {
		printf("%d ",linklist->elem);
		linklist = linklist->next;
	}
	printf("\n");
}

//��ͷ��������ָ��λ�ò������
void InsertLinkListByIndex(LinkList &linklist,int elem, int index) {
	int j = 1;
	LinkList p = linklist;//�ƶ�ָ��
	while (p&&j<index) {
		p = p->next;
		j++;
	
	}
	if (!p||j>index) { //����λ�ò��Ϸ���
		printf("����λ�ò��Ϸ���\n");
		return;
	
	
	}

	LinkNode* newnode = (LinkNode*)malloc(sizeof(LinkNode));
	newnode->elem = elem;
	newnode->next = p->next;
	p->next = newnode;
}

// ��ͷ��������ָ��λ��ɾ������
void DeleteLinkListByIndex(LinkList & linklist, int &elem, int index) {
	int j = 1;
	LinkList p;//�ƶ�ָ��
	p = linklist;
	while ((p->next) && j < index) {
		p = p->next;
		j++;

	}
	if (!(p->next) || j > index) { //����λ�ò��Ϸ���
		printf("ɾ��λ�ò��Ϸ���\n");
		return;


	}

	LinkNode* s = p->next;

}





int main() {

	LinkList linklist;
	InitLinkList(linklist);
	int nums = 0;
	printf("����Ҫ����������������\n");
	scanf("%d",&nums);

	addLinkNode_tail(linklist, nums);
	return 0;
}