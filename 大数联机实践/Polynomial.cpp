#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
#include"Polynomial.h"


Polynomial::Polynomial(int in) {
	Polynomial temp;
	temp.degree = 0;
	temp.c.push_back(in);
}
double Polynomial::operator()(double in) {
	if (!degree) { return c[0]; }
	double temp = 0;
	for (int i = degree;i >= 0;--i) {
		temp *= in;
		temp += c[i];
	}
	return temp;
}

Polynomial Polynomial::operator+(const Polynomial& bb) {
	if (bb.degree > degree) {
		Polynomial temp(bb);
		for (int i = degree;i >= 0;--i) {
			temp.c[i] += c[i];
		}
		while (temp.c[temp.degree] == 0 && degree >= 0) {
			temp.c.pop_back();
			--temp.degree;
		}
		return temp;
	}
	else {
		Polynomial temp(*this);
		for (int i = bb.degree;i >= 0;--i) {
			temp.c[i] += bb.c[i];
		}
		while (temp.c[temp.degree] == 0 && degree >= 0) {
			temp.c.pop_back();
			--temp.degree;
		}
		return temp;
	}
}
Polynomial Polynomial::operator+(const double bb) {
	Polynomial temp(*this);
	temp.c[0] += bb;
	return temp;
}
Polynomial Polynomial::operator-(const double bb) {
	Polynomial temp(*this);
	temp.c[0] -= bb;
	return temp;
}
Polynomial& Polynomial::operator+=(const double bb) {
	c[0] += bb;
	return *this;
}
Polynomial& Polynomial::operator-=(const double bb) {
	c[0] -= bb;
	return *this;
}
Polynomial& Polynomial::operator*=(const double bb) {
	for (int i = 0;i <= degree;++i) {
		c[i] += bb;
	}
	return *this;
}
Polynomial& Polynomial::operator/=(const double bb) {
	if (bb == 0) {
		std::cerr << "多项式除法错误,不能除以0\n";
		return *this;
	}
	for (int i = 0;i <= degree;++i) {
		c[i] /= bb;
	}
	return *this;
}
Polynomial Polynomial::operator-(const Polynomial& bb) {
	Polynomial temp(*this);
	if (bb.degree > degree) {
		temp.c.resize(bb.degree + 1, 0);
		temp.degree = bb.degree;
	}
	for (int i = bb.degree;i >= 0;--i) {
		temp.c[i] -= bb.c[i];
	}
	while (temp.c[temp.degree] == 0 && degree >= 0) {
		temp.c.pop_back();
		--temp.degree;
	}
	return temp;
}
Polynomial& Polynomial::operator+=(const Polynomial& bb) {
	if (bb.degree > degree) {
		c.resize(bb.degree + 1, 0);
		degree = bb.degree;
	}
	for (int i = std::min(degree, bb.degree);i >= 0;--i) {
		c[i] += bb.c[i];
	}
	while (c[degree] == 0 && degree > 0) {
		c.pop_back();
		--degree;
	}
	return *this;
}

Polynomial& Polynomial::operator-=(const Polynomial& bb) {
	if (bb.degree > degree) {
		c.resize(bb.degree + 1, 0);
		degree = bb.degree;
	}
	for (int i = std::min(degree, bb.degree);i >= 0;--i) {
		c[i] -= bb.c[i];
	}
	while (c[degree] == 0 && degree > 0) {
		c.pop_back();
		--degree;
	}
	return *this;
}

Polynomial Polynomial::operator*(const Polynomial& bb) {
	Polynomial temp;
	if ((!bb.degree) && bb.c[0] == 0) { return bb; }
	temp.c.resize(degree + bb.degree + 1, 0);
	temp.degree = degree + bb.degree;
	int conv = std::min(degree, bb.degree) + 1;
	int t2;
	for (int i = 0;i <= temp.degree;++i) {
		t2 = std::min(i, conv);
		for (int j = 0;j <= t2;++j) {
			temp.c[i] += i - j <= degree && i - t2 + j <= bb.degree ? c[i = j] * bb.c[i - t2 + j] : 0;
		}
	}
	return temp;
}

Polynomial Polynomial::operator*(const double bb) {
	Polynomial temp;
	if (bb == 0) { temp.c.push_back(0);return temp; }
	temp = *this;
	for (int i = 0;i <= temp.degree;++i) {
		temp.c[i] *= bb;
	}
	return temp;
}

Polynomial& Polynomial::operator*=(const Polynomial& bb) {
	if ((!bb.degree) && bb.c[0] == 0) { *this = bb; return *this; }
	Polynomial temp(*this);
	c.resize(temp.degree + bb.degree + 1, 0);
	degree = temp.degree + bb.degree;
	int conv = std::min(temp.degree, bb.degree) + 1;
	int t2;
	for (int i = 0;i < degree;++i) {
		t2 = std::min(i, conv);
		for (int j = 0;j <= t2;++j) {
			c[i] += i - j <= temp.degree && i - t2 + j <= bb.degree ? temp.c[i = j] * bb.c[i - t2 + j] : 0;
		}
	}

	return *this;
}


Polynomial& Polynomial::operator<<(int in) {
	reverse(c.begin(), c.end());
	c.insert(c.end(), in, 0);
	reverse(c.begin(), c.end());
	degree += in;
	return*this;
}

Polynomial& Polynomial::operator>>(int in) {
	std::vector<double>temp(c.begin() + in, c.end());
	c.swap(temp);
	degree -= in;
	return *this;
}

Polynomial Polynomial::der(int n) {
	Polynomial temp(*this);
	temp >> n;
	for (int num = 1;num <= n;num++) {
		for (int seq = 0;seq <= temp.degree; ++seq) {
			temp.c[seq] *= num + seq;
		}
	}
	return(temp);
}

Polynomial Polynomial::inte(int n) {
	Polynomial temp(*this);
	temp << n;

	for (int num = 2;num <= n;num++) {
		for (int seq = n, t = 2;seq <= temp.degree; ++seq, ++t) {
			temp.c[seq] /= t;
		}
	}
	return(temp);
}



Polynomial Polynomial::operator/(const Polynomial& bb) {
	if (!bb.degree) {
		if (bb.c[0] == 0) {
			std::cerr << "多项式除法错误,不能除以0\n";
			return *this;
		}
		else {
			Polynomial temp(*this);
			for (int i = 0;i <= temp.degree;++i) {
				temp.c[i] /= bb.c[0];
			}
			return temp;
		}
	}
	if (bb.degree >= degree) {
		if (bb.degree == degree) {
			Polynomial temp(c[degree] / bb.c[degree]);
			return temp;
		}
		else return *this;
	}
	Polynomial temp(*this), bbb(bb);
	double top = bb.c[bb.degree];
	double tdouble;
	std::vector<double>tvector;
	for (int i = degree;i >= bb.degree;--i) {
		tdouble = temp.c[i] / top;
		tvector.push_back(tdouble);
		temp -= (bbb * tdouble) << (i - bb.degree);
	}
	std::reverse(tvector.begin(), tvector.end());
	temp.degree = degree - bb.degree;
	temp.c = tvector;
	return temp;
}


std::ostream& operator<<(std::ostream& out, const Polynomial& bb) {
	if (bb.degree > 1) {
		if (bb.c[bb.degree] == -1) { out << "-x^" << resetiosflags(std::ios::showpos) << bb.degree << "\t";; }
		else if (bb.c[bb.degree] == 1) {
			out << "x^" << resetiosflags(std::ios::showpos) << bb.degree << "\t";
		}
		else {
			out << setiosflags(std::ios::showpos) << bb.c[bb.degree];
			out << "x^" << resetiosflags(std::ios::showpos) << bb.degree << "\t";
		}
	}
	for (int i = bb.degree - 1;i > 1;--i) {
		if (bb.c[i] != 0) {
			if (bb.c[i] == -1) { out << "-x^" << resetiosflags(std::ios::showpos) << i << "\t";; }
			else if (bb.c[i] == 1) {
				out << "+x^" << resetiosflags(std::ios::showpos) << i << "\t";
			}
			else {
				out << setiosflags(std::ios::showpos) << bb.c[i];
				out << "x^" << resetiosflags(std::ios::showpos) << i << "\t";
			}
		}

	}
	if (bb.c[1] != 0) {
		if (bb.c[1] == -1) { out << "-x\t"; }
		else if (bb.c[1] == 1) {
			if (bb.degree == 1) {
				out << "x\t";
			}
			else {
				out << "+x\t";
			}

		}
		else { out << setiosflags(std::ios::showpos) << bb.c[1] << "x\t"; }
	}

	out << setiosflags(std::ios::showpos) << bb.c[0];
	return out;
}


void Polynomial::set(int indegree,std::initializer_list<double>in) {
	auto endflag = in.end();
	c.clear();
	for (auto i=in.begin();i != endflag;++i) {
		c.push_back(*i);
	}
	std::reverse(c.begin(), c.end());
	degree =indegree;
}