#pragma once
#include<cmath>
#include<vector>
#include<queue>
#include<set>
#include<list>
using namespace std;
typedef long long LL;
//ŷ��ɸ�ǰ�����˹����ɸ������ǿ��
//ÿ������ֻ��Ҫ��ɸһ��,�������Ҫ̫�����
//ռ�Ŀռ���һЩ

//ŷ��ɸ
//�ҳ�һ����Χ������
//����init,������fin
//��1000000����8��
vector<long int>Euler(long int init, long int fin) {
	vector<long> Prime = { 2,3,5,7,11,13,17,19 };
	set<long> remain;
	long long tempend = min((long)361, fin), temp3 = *(Prime.end() - 1);
	long temp2, tempinit = min(init, (long)21);
	auto V_iter = Prime.end();
	set<long>::iterator iter2, iter3;
	double endflag= min((long)361, fin);
	while (endflag<fin) {
		endflag = temp3;
		temp3 *= temp3; endflag *= endflag;
		tempend =endflag= min(endflag, (double)fin);
		if (!(tempinit % 2)) { ++tempinit; }
		for (long i = tempinit;i <= tempend;i += 2) {
			remain.insert(i);
		}
		tempinit = tempend;
		V_iter = Prime.end();
		for (auto iter = Prime.begin() + 1;iter != V_iter ;++iter) {
			if (*iter > sqrt(tempend) || remain.empty()) {
				break;
			}
			temp2 = remain.size();
			iter2 = remain.begin();
			for (long i = 0;i < temp2;++i) {
				if (remain.empty()) {
					break;
				}

				if (*iter2 % *iter) {
					++iter2;
				}
				else {
					if (iter2 == remain.begin()) {
						remain.erase(iter2);
						iter2 = remain.begin();
					}
					else {
						iter3 = iter2;--iter3;
						remain.erase(iter2);
						iter2 = iter3;
						++iter2;
					}
				}
			}
		}
		temp2 = remain.size();

		for (iter2 = remain.begin(), iter3 = remain.end();iter2 != iter3;++iter2) {
			Prime.push_back(*iter2);
		}
		remain.clear();
		temp3 = *(Prime.end() - 1);
	}
	V_iter = Prime.begin();
	while (*V_iter < init) { ++V_iter ; }
	return(vector<long>(V_iter , Prime.end()));
}

//����������Ч��������
//��1000000����23��

//�������ֽ�
//�ظ���������ռ���λ
vector<long> PrimeFactorize(long in) {
	vector<long>Prime(Euler(2,in+1)),Vout;
	for (auto iter = Prime.begin(), fin = Prime.end();iter != fin;++iter) {
		while (!(in % *iter)) {
			Vout.push_back(*iter);
			in /= *iter;
		}
	}
	return Vout;
}
//������
long long  Fastmod(long long  a, long long  n, long long b) {
	if (n <= 2) {
		if (n == 2) { return a*a % b; }
		else if (n == 1) { return a% b; }
		else { return 1 % b; }
	}
	if (n % 2) {
		return Fastmod(a, n / 2, b) * Fastmod(a, n / 2 + 1, b) % b;
	}
	else {
		return Fastmod(a, n / 2, b) * Fastmod(a, n / 2 , b) % b;
	}
}
//��չŷ������㷨
inline long long extGCD(long long a, long long b, long long& x, long long& y) {
	long long d = a;
	if (b != 0) {
		d = extGCD(b, a & b, y, x);
		y -= a / b * x;
	}
	else { x = 1;y = 0; }
	return d;
}
long long GCD(long long a, long long b) {
	long long temp;
	//�Ƚ��������Ĵ�С��ֵ�����Ϊa��ֵС����Ϊb
	if (a < b) {
		temp = a;
		a = b;
		b = temp;
	}
	//����
	while (b != 0) {
		temp = a % b;
		a = b;
		b = temp;
	}
	return a;
}
//ŷ������
inline long long Phi(int N) {
	long long ti=0;
	for (long long i = 1;i < N;++i) {
		if (GCD(i, N) == 1) { ++ti;}
	}
	return ti;
}
//���۵���
inline long long NTinv(long long a, long long mod) {
	return Fastmod(a, Phi(mod) - 1, mod);
}
//����
//long long�����׳ű�,С��
long long Permutation(long long all, long long some) {
	long long temp=1;
	for(LL i=all-some+1;i<=all;++i){
		temp *= i;
	}
}
long long Conbination(long long all, long long some) {
	long long temp = 1;
	for (LL i = all - some + 1;i <= all;++i) {
		temp *= i;
	}
	for (LL i = 1;i <= some;++i) {
		temp /= i;
	}
	return temp;
}