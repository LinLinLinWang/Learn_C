#include<iostream>
using namespace std;

//�����Լ��

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
	cout << A << "��" << B << "�����Լ��Ϊ:" << b << endl;


}


/*int main() {
	gcd(3,5);
	gcd(5,3);
	gcd(28,14);
	gcd(4, 56);
	return 0;

}*/






//�ϲ�����
void mergePart(int *a, int low, int middle, int n) {
	int i = low, j = middle;
	int k = 0;
	int* b = new int[n];
	while (i<=middle&&j<=n-1) {
		if (a[i] <= a[j]) {
			b[k] = a[i];
			i++;
			k++;
		  
		}
		else {
			b[k] = a[j];
			k++;
			j++;
		}
	
	
	
	}
	while (j<=n-1) {

		
			b[k] = a[j];
			j++;
			k++;
		
	
	}
	while(i<=middle)
	
	{
			b[k] = a[i];
			k++;
			i++;
		
	}

	for (int t = 0; t <= n - 1;t++) {
		a[t] = b[t];
	
	}

}


int main() {
	int a[] = { 10,9,8,5,2 };
	mergePart(a,0,2,5);


	return 0;
}






