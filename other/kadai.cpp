#include<iostream>
using namespace std;

class pOINT {
public:
	long x;
	long y;
	void operator ++(int n) {
		printf("abc%d\n",n);
		x++; y++;
	}
	pOINT operator ++() {
		printf("now%d\n", x);
		++x; ++y;
		return *this;
	}
} obj1 , obj2 ;

int main() {
	obj1.x = 10; obj2.y = 5;
	cout << "x = " << obj1.x << "\ty = " << obj1.y << '\n';
	cout << "x = " << obj2.x << "\ty = " << obj2.y << '\n';
	obj2 = ++obj1;//operator ++()  obj1
	cout << "x = " << obj1.x << "\ty = " << obj1.y << '\n';
	cout << "x = " << obj2.x << "\ty = " << obj2.y << '\n';
	printf("change\n");
	obj2++;//operator ++(int n)  obj2

	cout << "x = " << obj1.x << "\ty = " << obj1.y << '\n';
	cout << "x = " << obj2.x << "\ty = " << obj2.y << '\n';
	return 0;
}