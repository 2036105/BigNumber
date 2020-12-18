#pragma once
#include<cmath>
#include<vector>
#include<queue>
#include<set>
#include<list>
using namespace std;
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
//vector<long int>Euler2(long int init, long int fin) {
//	vector<long> Prime = { 2,3,5,7,11,13,17,19 };
//	list<long> remain;
//	long long tempend = min((long)361, fin), temp3 = *(Prime.end() - 1);
//	long temp2, tempinit = min(init, (long)21);
//	auto V_iter = Prime.end();
//	list<long>::iterator iter2, iter3;
//	double endflag = min((long)361, fin);
//	while (endflag < fin) {
//		endflag = temp3;
//		temp3 *= temp3; endflag *= endflag;
//		tempend = endflag = min(endflag, (double)fin);
//		if (!(tempinit % 2)) { ++tempinit; }
//		for (long i = tempinit;i <= tempend;i += 2) {
//			remain.push_back(i);
//		}
//		tempinit = tempend;
//		V_iter = Prime.end();
//		for (auto iter = Prime.begin() + 1;iter != V_iter;++iter) {
//			if (*iter > sqrt(tempend) || remain.empty()) {
//				break;
//			}
//			temp2 = remain.size();
//			iter2 = remain.begin();
//			for (long i = 0;i < temp2;++i) {
//				if (remain.empty()) {
//					break;
//				}
//
//				if (*iter2&&*iter2 % *iter) {
//					++iter2;
//				}
//				else {
//					*iter2 = 0;
//					//if (iter2 == remain.begin()) {
//					//	remain.erase(iter2);
//					//	iter2 = remain.begin();
//					//}
//					//else {
//					//	iter3 = iter2;--iter3;
//					//	remain.erase(iter2);
//					//	iter2 = iter3;
//					//	++iter2;
//					//}
//				}
//			}
//		}
//		remain.remove(0);
//		temp2 = remain.size();
//
//		for (iter2 = remain.begin(), iter3 = remain.end();iter2 != iter3;++iter2) {
//
//			Prime.push_back(*iter2);
//		}
//		remain.clear();
//		temp3 = *(Prime.end() - 1);
//	}
//	V_iter = Prime.begin();
//	while (*V_iter < init) { ++V_iter; }
//	return(vector<long>(V_iter, Prime.end()));
//}