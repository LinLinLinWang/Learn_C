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


int main() {
	gcd(3,5);
	gcd(5,3);
	gcd(28,14);
	gcd(4, 56);
	return 0;

}