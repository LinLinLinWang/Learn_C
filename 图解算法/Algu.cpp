#include<iostream>
using namespace std;

//求最大公约数

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


/*int main() {
	gcd(3,5);
	gcd(5,3);
	gcd(28,14);
	gcd(4, 56);
	return 0;

}*/






//合并排序



void MergePart(int a[],int low,int middle,int high) {
	int i = low;
	int j = middle+1;
	int k = 0;
	int *b = new(nothrow) int [high - low + 1];
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




	//


int main() {

	int a[] = { 1 };

	MergeSort(a, 0, 0);
	cout << a;
	return 0;
}






