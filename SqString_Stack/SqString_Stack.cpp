#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXSIZE 100

/// <summary>
//��̬�洢��
/// </summary>
typedef struct SqString_Stack {
	char data[MAXSIZE];
	int length;//��ǰ����



}SqString_Stack;
void Printf_String(SqString_Stack sqstring);

//��ʼ��
void InitString(SqString_Stack& sqString) {
	
	memset(sqString.data, '\0', sizeof(char) * 100);
	sqString.length = 0;
}

//����ֵ

void InsertString(SqString_Stack& sqstring) {
	int i = 0;
	char elem;
	printf("������ֵ,�س�����ǿ���˳���\n");
	scanf("%c",&elem);
	printf("ֵΪ%c\n",elem);
	while (elem != '\n') {
	   
		
		if (i > MAXSIZE - 2) {
		
			printf("��ֹ���룡����\n");
			return;
		
		}
		
		sqstring.data[i] = elem;
		sqstring.length++;
		i++;
		scanf("%c", &elem);
		printf("ֵΪ%d\n", elem);
	}
	sqstring.data[i] = '\0';
	printf("¼�봮��ϣ�\n");







}


//������ ��һ������������posǰ

void StrInsert(SqString_Stack& sqString, int pos, SqString_Stack s) {
	if (pos<0 || pos>sqString.length) {
		printf("λ�ò��Ϸ���\n");
		return;
	
	}
	if (s.length + sqString.length > MAXSIZE - 1) {
		printf("�����ڴ潫������������������ַ�\n");


		//���봮��length-(������MAXSIZE-����length-1)  = X
		//xΪ����posλ�ã���pos����β����Ҫ�����ĸ���
		//���x<����length-pos�� ���轫������length-1-x)��posλ�������ƶ�xλ

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


		//���x>����length-pos
		//ֱ�ӽ����봮���ǵ�pos����pos��֮���λ��



		else {
			for (int i = pos; i < sqString.length; i++) {

				sqString.data[pos + i] = s.data[i];

			}

			sqString.length = MAXSIZE - 1;
			sqString.data[MAXSIZE] = '\0';
		
		
		
		
		
		}
  		









	
	}
	else {
	//��������pos֮���ַ�����ƶ�s.length�� λ��
	for (int i = sqString.length; i >= pos ; i--) {
	   	  
		sqString.data[i + s.length] = sqString.data[i];
	
	
	}
	printf("����˳���");
	Printf_String(sqString);
	for (int i = 0; i < s.length;i++) { 
	 
		sqString.data[pos  + i] = s.data[i];
	
	}

	sqString.length = sqString.length + s.length;



	}



}


//��ӡ��
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
	printf("��ʼ�����С�������\n");
	InitString(sqstring);
	InitString(sstring);
	printf("��ʼ����ϡ�������\n");

	printf("���������ֵ�����س�������\n");
	InsertString(sqstring);
	printf("��ӡ����������%d��ֵ ������\n",sqstring.length);
	Printf_String(sqstring);
	printf("����Ӵ���ֵ�����س�������\n");
	InsertString(sstring);
	printf("��ӡ���Ӵ�������%d��ֵ������\n",sstring.length);
	Printf_String(sstring);
	printf("ִ�в��������\n");
	StrInsert(sqstring, -1, sstring);
	printf("��ӡ����������%d��ֵ ������\n", sqstring.length);
	Printf_String(sqstring);
	return 0;

}