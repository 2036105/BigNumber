#include<iostream>

#include"Polynomial.h"
#include"Euler.h"
using namespace std;
//HOMODELUNA@outlook.com




int main() {
	Polynomial a;
	a.degree = 2;
	a.c.push_back(0);a.c.push_back(0);a.c.push_back(1);
	a << 2;
	cout << a(2) <<'\n';
	a >> 2;
	cout << a(2) << '\n';
	a = a.der(2);
	cout << a(2) << '\n';
	a = a.inte(2);
	cout << a(2) << '\n';
	Polynomial b;
	b.degree = 2;
	b.c.push_back(1);b.c.push_back(-2);b.c.push_back(1);
	cout << b<<'\n';
	Polynomial c;
	c.degree = 1;
	c.c.push_back(-1);c.c.push_back(1);
	cout << c << '\n';
	Polynomial d = b / c;
	cout << d << '\n';
	d.set(3,{ 1, 3, 3, 1 });
	cout << d << '\n';
}