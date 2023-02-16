#include<iostream>
using namespace std;
//老鼠走迷宫

#define MAZECOUNTI 9
#define MAZECOUNTJ 10
#define STARTI 1 
#define STARTJ 1
#define ENDI 8
#define ENDJ  10
#define MAXSIZE 50
typedef struct local {  //结点坐标
	int x;
	int y;
}LOCAL;
typedef struct ROUTESTACK {
	LOCAL data[MAXSIZE];
	int top;


}ROUTESTACK;

ROUTESTACK* InitStack() {
	ROUTESTACK* stack = (ROUTESTACK*)malloc(sizeof(ROUTESTACK));
	if (stack == NULL)
	{
		printf("栈分配失败！\n");
		return NULL;
	}
	stack->top = -1;
	return stack;
}

int EmptyStack(ROUTESTACK *stack) {
	  
	if (stack->top == -1) return 1;
	return 0;


}

int IsFull(ROUTESTACK* stack) {
	if (stack->top == MAXSIZE - 1) return 1;
	return 0;
}
int PushStack(ROUTESTACK *stack,LOCAL *local) {

	if (stack->top < MAXSIZE - 1) {
		stack->data[++stack->top] = *local;
		return 1;
	
	
	}
	else {
		printf("\033[33;1m 栈空间已满！ 放入失败！\n");
		return 0;
	}
}
int PopStaclk(ROUTESTACK *stack,LOCAL &temp) {
	if (stack->top > -1) {
		temp = stack->data[stack->top];
		stack->top--;
		return 1;
	}
	else {
		printf("栈已空！\n");
		return 0;
	}



}

int VisitMaze(int maze[][MAZECOUNTJ],LOCAL path[][MAZECOUNTJ]) {

	int i, j;
	ROUTESTACK* stack;
	LOCAL temp;
	stack = InitStack();
	temp.x = 0; temp.y = 0;
	if (maze[STARTI][STARTJ] == 0) {
		PushStack(stack, &temp);
	}
	else return 0;
	while (!EmptyStack(stack)) {
		PopStaclk(stack,temp);
		i = temp.x;
		j = temp.y;
		maze[i][j] = 2;
		if (i == ENDI && J == ENDJ) {

			break;
		}
		if (i + 1 <= ENDI && maze[i + 1][j] == 0) {
			maze[i + 1][j] == 2;
		  
		
		}
	
	
	}

}



 



//求最大公约数

/*
void gcd(int a, int b) {
	int t = 0;
	int A = a;
	int B = b;
	t = a % b;
	while (t!=0) {
		a = b;
		b = t;
		t = a % b;


	
	}
	cout << A << "和" << B << "的最大公约数为:" << b << endl;


}


  int main() {
	gcd(3,5);
	gcd(5,3);
	gcd(28,14);
	gcd(4, 56);
	return 0;

}








//合并排序



void MergePart(int a[],int low,int middle,int high) {
	int i = low;
	int j = middle+1;
	int k = 0;
	int* b = NULL;
	b = new(nothrow) int(high - low + 1);
	if (b == NULL) {
		printf("内存分配失败！\n");
		return;
	}
	while (i <= middle && j <= high) {

		if (a[i] <= a[j]) {
			b[k++] = a[i++];
		}
		else {
			b[k++] = a[j++];
		}
	}
	
		while (i <= middle) {
			b[k++] = a[i++];

		}
		while (j <= high) {
			b[k++] = a[j++];
		}

	
		for (int i = low,k=0; i<= high;i++) {
			a[i] = b[k++];
		
		}
		delete[] b;
		
	}
	


void MergeSort(int a[],int low,int high) {

	if (low < high) {
		int middle = (low + high) / 2;
		MergeSort(a,low,middle);
		MergeSort(a,middle+1,high);
		MergePart(a, low, middle, high);
	}
	
}

*/


//快速排序

void swap(int a[], int low,int high)
{
	int temp = a[low];

	a[low] = a[high];
	a[high] = temp;
}


//取partition
int Partition(int a[],int low,int high) {
	int pivot = a[low];
	int i = low,  j = high;
	while (i < j) {
		while (i < j && a[j] >pivot) j--;
		while (i < j && a[i] <= pivot) i++;
		if (i < j) {
			swap(a,i++, j--);
		}
	}
	if (a[i] <= pivot) {
	    
		swap(a,i,low);
		return i;
	}
	
		swap(a,i-1, low);
		return i - 1;
	  
	
	

	
}
void   QuicSort(int a[], int low, int high) {

	if (low < high) {
		int pivot = Partition(a, low, high);
		QuicSort(a, low, pivot - 1);  //规避最后两个数相同的情况，会死循环
		QuicSort(a, pivot + 1, high);



	}


}












int main() {

//	int a[] = { 10,7,4,2,1,4 };

	//QuicSort(a, 0, 5);
//	cout << a[0] << a[1] << a[2] << a[3] << a[4] << a[5];


	return 0;
}




//老鼠走迷宫



