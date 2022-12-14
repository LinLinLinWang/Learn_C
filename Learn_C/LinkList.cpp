#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>


//链表存储结构
typedef struct LinkNode{
	int elem;
	LinkNode* next;

}LinkNode,*LinkList;

//链表初始化
void InitLinkList(LinkList &linklist) {
	LinkNode  *headnode =(LinkNode*)malloc(sizeof(LinkNode));
	headnode->elem = -99999;
	headnode->next = NULL;
	linklist = headnode;
}

//带头结点前插法
void addLinkNode_head(LinkList& linklist, int elem) {
	LinkNode* newnode = (LinkNode*)malloc(sizeof(LinkNode));
	if (newnode == NULL) {
		printf("内存分配失败！");
		return;
	}
	newnode->elem = elem;
	newnode->next = linklist->next;
	linklist->next = newnode;
	
}
//带头结点尾插法

void   addLinkNode_tail(LinkList& linklist, int nums) {
	int elem;
	LinkNode* tail = linklist;
	
	for (int i = 0; i < nums;i++) {
		printf("使用尾插法插入结点,请输入第%d个结点值：",i+1);
		scanf("%d",&elem);
		LinkNode* newnode = (LinkNode*)malloc(sizeof(LinkNode));
		if (newnode == NULL) {
			printf("内存分配失败！\n");
			return;
		}
		newnode->elem = elem;
		newnode->next = NULL;
		tail->next = newnode;
		tail = newnode;

	}




};


//打印链表

void  Printf_LinkList(LinkList linklist) {
	linklist = linklist->next;
	printf("开始打印链表!\n");
	while (linklist) {
		printf("%d ",linklist->elem);
		linklist = linklist->next;
	}
	printf("\n");
}

//带头结点的链表指定位置插入操作
void InsertLinkListByIndex(LinkList &linklist,int elem, int index) {
	int j = 1;
	LinkList p = linklist;//移动指针
	while (p&&j<index) {
		p = p->next;
		j++;
	
	}
	if (!p||j>index) { //插入位置不合法。
		printf("插入位置不合法！\n");
		return;
	
	
	}

	LinkNode* newnode = (LinkNode*)malloc(sizeof(LinkNode));
	newnode->elem = elem;
	newnode->next = p->next;
	p->next = newnode;
}

// 带头结点的链表指定位置删除操作
void DeleteLinkListByIndex(LinkList & linklist, int &elem, int index) {
	int j = 1;
	LinkList p;//移动指针
	p = linklist;
	while ((p->next) && j < index) {
		p = p->next;
		j++;

	}
	if (!(p->next) || j > index) { //插入位置不合法。
		printf("删除位置不合法！\n");
		return;


	}
	LinkNode* del = p->next;
	elem = del->elem;
	p->next = del->next;
	free(del);



}





int main() {

	LinkList linklist;
	InitLinkList(linklist);
	int nums = 0;
	printf("您想要创建几个结点的链表？\n");
	scanf("%d",&nums);

	addLinkNode_tail(linklist, nums);
	Printf_LinkList(linklist);

	printf("您要删除第几个节点？");
	int elem;
	int index;
	scanf("%d",&index);
	DeleteLinkListByIndex(linklist,elem,index);
	printf("删除的结点是%d\n",elem);
	Printf_LinkList(linklist);
	printf("您要增加节点的位置？节点值呢？");
	int insertelem;
	int insertindex;
	scanf("%d %d",&insertindex,&insertelem);
	InsertLinkListByIndex(linklist, insertelem,  insertindex);
	Printf_LinkList(linklist);
	return 0;
}