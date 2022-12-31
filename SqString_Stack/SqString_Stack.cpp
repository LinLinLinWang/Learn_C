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
//��ɾ��(��posλ��)
void DeleteString(SqString_Stack &sq,int pos,int len) {
	if (len<1 || pos>(sq.length-len+1))
	{
		printf("ɾ��ʧ�ܣ�ɾ��λ�ò�����\n");

		return;
	}
	else {
	
		for (int i = pos+len; i <=sq.length; i++) {
			sq.data[i-len] = sq.data[i];
		
		
		}

		sq.length = sq.length - len;

	
	}
       



}
//����ģʽƥ�䣨���رȽϣ�

int Pattern_String(SqString_Stack &sq,SqString_Stack &patten,int &pos) {
	int flag;
	//λ�ó�ʼ��������ͷ��
	int j = 0;//�������Ƚ�λ��
	int k = 0;//ģʽ�����Ƚ�λ��

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
	
		if (k == patten.length) return pos;//ƥ��ɹ�
	
		return -1;
	


}




//��next����  kmp��δ�Ż�
int* getNext(SqString_Stack pattern) {
	int len = pattern.length;
	int* next = (int*)malloc(sizeof(int) * pattern.length);
	next[0] = -1;
	if (pattern.length == 0)return NULL;
	if (pattern.length==1) {
		return next;
	}

	
	int i = -1;//��ǰj��ָ��λ�ã��� ����ǰԪ�أ��������ǰ׺���ȣ�Ҳ��j-1Ԫ�ػ��˵�λ��
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

//�Ż����kmp  ԭ����kmp�㷨�ڱȽ��ַ���ʱ Ҳ���и�������Ƚϡ�

int* getNext_After(SqString_Stack pattern) {
	int len = pattern.length;
	int* next = (int*)malloc(sizeof(int) * pattern.length);
	next[0] = -1;
	if (pattern.length == 0)return NULL;
	if (pattern.length == 1) {
		return next;
	}


	int i = -1;//��ǰj��ָ��λ�ã��� ����ǰԪ�أ��������ǰ׺���ȣ�Ҳ��j-1Ԫ�ػ��˵�λ��
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




//��ӡ��
void Printf_String(SqString_Stack sqstring) {
int 	i = 0;
while (sqstring.data[i] != '\0') {

	printf("%c",sqstring.data[i]);
	i++;
}
printf("\n");

}

//�����Ӵ��Ƿ����


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
	/*printf("ִ�в��������\n");
	StrInsert(sqstring, -1, sstring);
	printf("��ӡ����������%d��ֵ ������\n", sqstring.length);
	Printf_String(sqstring);
	
	printf("��ʼ����ɾ��������\n");
	DeleteString(sqstring,0,5);
	printf("��ӡ����������%d��ֵ������\n", sqstring.length);
	Printf_String(sqstring);
	
	Printf_String(sqstring);
	
	printf("����Ӵ���ֵ�����س�������\n");
	InsertString(sstring);
	printf("��ӡ���Ӵ�������%d��ֵ������\n", sstring.length);
	Printf_String(sstring);
	*/
	printf("��ʼģʽƥ�䣡����\n");
	reslult=Pattern_String(sqstring, sstring, pos);
	if (reslult!= -1) {
		printf("ģʽƥ��ɹ���������pos=%d�������ִ�����\n",pos);
		

	
	}
	else {
		printf("ģʽƥ��ʧ�ܣ�\n");
	
	}
	printf("ʹ��kmpƥ����%d\n",IsExistPattern(sqstring, sstring));

	return 0;

}