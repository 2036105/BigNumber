#pragma once
#include<cmath>
#include<vector>
#include<queue>
#include<set>
#include<list>
using namespace std;
typedef long long LL;
//欧拉筛是埃拉托斯特尼筛法的增强版
//每个合数只需要被筛一遍,因而不需要太多计算
//占的空间会多一些

//欧拉筛
//找出一定范围的素数
//包含init,不包含fin
//跑1000000用了8秒
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

//用链表做的效果并不好
//跑1000000用了23秒

//质因数分解
//重复的因数会占多个位
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
//快速幂
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
//扩展欧几里得算法
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
	//比较两个数的大小，值大的数为a，值小的数为b
	if (a < b) {
		temp = a;
		a = b;
		b = temp;
	}
	//求余
	while (b != 0) {
		temp = a % b;
		a = b;
		b = temp;
	}
	return a;
}
//欧拉函数
inline long long Phi(int N) {
	long long ti=0;
	for (long long i = 1;i < N;++i) {
		if (GCD(i, N) == 1) { ++ti;}
	}
	return ti;
}
//数论倒数
inline long long NTinv(long long a, long long mod) {
	return Fastmod(a, Phi(mod) - 1, mod);
}
//排列
//long long很容易撑爆,小心
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