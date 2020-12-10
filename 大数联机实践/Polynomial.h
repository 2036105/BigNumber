#pragma once
#include<vector>
class Polynomial
{public:
	//0多项式的系数设为-1;
	int degree = 0;
	std::vector<double> c;
	//重载括号,用于多项式赋值
	double operator()(double in);
	//重载加号,两个多项式相加
	Polynomial operator+(const Polynomial& bb);
private:
};

double Polynomial::operator()(double in) {
	if (!degree) { return 0; }
	double temp=0;
	for (int i = degree;i > 0;--i) {
		temp *= in;
		temp += c[i];
	}
	return temp;
}

Polynomial Polynomial::operator+(const Polynomial& bb) {
	Polynomial temp;
}