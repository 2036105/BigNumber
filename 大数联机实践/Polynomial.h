#pragma once
#include<vector>
//����ʽ
class Polynomial
{public:
	//0����ʽ��ϵ����Ϊ-1;
	long degree = 0;
	std::vector<double> c;
	//��������,���ڶ���ʽ��ֵ
	double operator()(double in);
	//���ؼӺ�,��������ʽ���
	Polynomial operator+(const Polynomial& bb);
	Polynomial&operator+=(const Polynomial& bb);
	Polynomial operator-(const Polynomial& bb);
	Polynomial&operator-=(const Polynomial& bb);
	Polynomial operator*(const Polynomial& bb);
	Polynomial&operator*=(const Polynomial& bb);
	//����
	inline Polynomial& operator<<(int in);
	//����
	inline Polynomial& operator>>(int in);
	//��,Ĭ�ϴ���Ϊ1;
	Polynomial der(int n = 1);
	//��������,Ĭ�ϴ���Ϊ1,����һ������ʽ
	Polynomial inte(int n = 1);
	Polynomial operator/(const Polynomial& bb);
private:

};

double Polynomial::operator()(double in) {
	if (!degree) { return this->c[0]; }
	double temp=0;
	for (int i = degree;i >= 0;--i) {
		temp *= in;
		temp += c[i];
	}
	return temp;
}

Polynomial Polynomial::operator+(const Polynomial& bb) {
	if (bb.degree > this->degree) {
		Polynomial temp(bb);
		for (int i = this->degree;i >= 0;--i) {
			temp.c[i] += this->c[i];
		}
		return temp;
	}
	else{ Polynomial temp(*this); 
		for (int i = bb.degree;i >= 0;--i) {
			temp.c[i] += bb.c[i];
		}
		return temp;
	}
}

Polynomial Polynomial::operator-(const Polynomial& bb) {
	Polynomial temp(*this);
	if (bb.degree > this->degree) {
		temp.c.resize(bb.degree+1,0);
		temp.degree = bb.degree;
	}
	for (int i =std::max(this->degree, bb.degree);i >= 0;--i) {
		temp.c[i] -= bb.c[i];
	}
	return temp;
}
Polynomial&Polynomial::operator+=(const Polynomial& bb) {
	if (bb.degree > this->degree) {
		this->c.resize(bb.degree + 1, 0);
		this->degree = bb.degree;
	}
	for (int i = std::max(this->degree, bb.degree);i >= 0;--i) {
		this->c[i] += bb.c[i];
	}
	return *this;
}

Polynomial& Polynomial::operator-=(const Polynomial& bb) {
	if (bb.degree > this->degree) {
		this->c.resize(bb.degree + 1, 0);
		this->degree = bb.degree;
	}
	for (int i = std::max(this->degree, bb.degree);i >= 0;--i) {
		this->c[i] -= bb.c[i];
	}
	return *this;
}

Polynomial Polynomial::operator*(const Polynomial& bb) {
	Polynomial temp;
	temp.c.resize(this->degree + bb.degree + 1,0);
	temp.degree = this->degree + bb.degree;
	int conv = std::min(this->degree, bb.degree) + 1;
	int t2;
	for (int i = 0;i < temp.degree;++i) {
		t2 = std::min(i, conv);
		for (int j = 0;j <= t2;++j) {
			temp.c[i] += i - j <= this->degree && i - t2 + j <= bb.degree ? this->c[i = j] * bb.c[i - t2 + j] : 0;
		}
	}
	return temp;
}


Polynomial& Polynomial::operator*=(const Polynomial& bb) {
	Polynomial temp(*this);
	this->c.resize(temp.degree + bb.degree + 1, 0);
	this->degree = temp.degree + bb.degree;
	int conv = std::min(temp.degree, bb.degree) + 1;
	int t2;
	for (int i = 0;i < this->degree;++i) {
		t2 = std::min(i, conv);
		for (int j = 0;j <= t2;++j) {
			this->c[i] += i - j <= temp.degree && i - t2 + j <= bb.degree ? temp.c[i = j] * bb.c[i - t2 + j] : 0;
		}
	}
	return *this;
}


Polynomial& Polynomial::operator<<(int in) {
	this->c.insert(this->c.begin(), in, 0);
	this->degree += in;
	return*this;
}
Polynomial& Polynomial::operator>>(int in) {
	std::vector<double>temp(this->c.begin()+in, this->c.end());
	this->c.swap(temp);
	this->degree -= in;
	return *this;
}

Polynomial Polynomial::der(int n ) {
	Polynomial temp(*this);
	temp >> n;
	for (int num = 1;num <= n;num++) {
		for (int seq = 0;seq <= temp.degree; ++seq) {
			temp.c[seq] *= num+seq;
		}
	}
	return(temp);
}

Polynomial Polynomial::inte(int n ) {
	Polynomial temp(*this);
	temp << n;

	for (int num = 2;num <= n;num++) {
		for (int seq = n,t=2;seq <= temp.degree; ++seq,++t) {
			temp.c[seq] /= t;
		}
	}
	return(temp);
}