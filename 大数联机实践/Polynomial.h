#pragma once
#include<vector>
class Polynomial
{public:
	//0����ʽ��ϵ����Ϊ-1;
	int degree = 0;
	std::vector<double> c;
	//��������,���ڶ���ʽ��ֵ
	double operator()(double in);
	//���ؼӺ�,��������ʽ���
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