#include<iostream>

#include"Polynomial.h"
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
}