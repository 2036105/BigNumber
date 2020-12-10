#include<iostream>
#include<vector>
using namespace std;
class line;
class protect;
//https://vjudge.net/contest/411104#problem/C

class Mars {
public:
	int numCity;
	int numWay;
	int numProtection;
	vector<line> E;
	vector<protect> P;
	vector<int>rele(int id);
	vector<int>protectrele(int id);
	inline void addProtect(int aa, int bb);
	inline void addWay(int from, int to, int cost);

	bool IsWay(int from, int to);
	int cost(int from, int to);
	void selfline();
};
class line {
public:
	int b;
	int f;
	int cost;
	line(int aa, int bb, int incost) :b(aa), f(bb), cost(incost) {}
};
class protect {
public:
	int b;
	int f;
	bool on;
	protect(int aa, int bb, bool incost) :b(aa), f(bb), on(incost) {}
};
vector<int>Mars::rele(int id) {
	vector<int> temp;
	vector<line>::iterator t = E.begin();
	while (t != E.end()) {
		if (t->f == id) { temp.push_back(t->b); }
		t++;
	}
	return temp;
}
vector<int>Mars::protectrele(int id) {
	vector<int> temp;
	vector<protect>::iterator t = P.begin();
	while (t != P.end()) {
		if (t->f == id) { temp.push_back(t->b); }
		t++;
	}
	return temp;
}
void Mars::addProtect(int aa, int bb) {
	P.push_back(protect(aa, bb, 1));
}
void Mars::addWay(int from, int to, int cost) {
	E.push_back(line(from, to, cost));
}
bool Mars::IsWay(int from, int to) {
	for (vector<line>::iterator iter = E.begin();iter != E.end();iter++) {
		if (iter->b == from && iter->f == to) { return 1; }
	}
	return 0;
}
int Mars::cost(int from, int to) {
	for (vector<line>::iterator iter = E.begin();iter != E.end();iter++) {
		if (iter->b == from && iter->f == to) { return iter->cost; }
	}
	return 0;
}
int& cost(vector<line>& map, int from, int to) {
	for (vector<line>::iterator iter = map.begin();iter != map.end();iter++) {
		if (iter->b == from && iter->f == to) { return iter->cost; }
	}

}
int cost2(vector<line>& map, int from, int to) {
	for (vector<line>::iterator iter = map.begin();iter != map.end();iter++) {
		if (iter->b == from && iter->f == to) { return iter->cost; }
	}
	return 1000000;
}
void Mars::selfline() {
	for (int i = 0;i < numCity;i++) {
		addWay(i, i, 0);
	}
}
int expect(int map[][500], int id, int n) {
	int temp = 9999999;
	for (int i = 0;i < n;i++) {
		if (temp < map[id][i] + temp < map[i][id]) {
			temp = map[id][i] + temp < map[i][id];
		}
	}
	return temp;
}


int InvasionTime(Mars&planet, int id) {
	vector<int> temp;
	vector<int>temp1(planet.rele(id));
	vector<int>temp2(planet.protectrele(id));
	for (vector<int>::iterator i = temp1.begin();i != temp1.end();i++) {
		temp.push_back(InvasionTime(planet, *i)+cost2(planet.E,*i,id));
	}
	for (vector<int>::iterator i = temp2.begin();i != temp2.end();i++) {
		temp.push_back(InvasionTime(planet, *i));
	}
	int tout=9999999;
	for (vector<int>::iterator i = temp.begin();i != temp.end();i++) {
		if (tout > * i) { tout = *i; }
	}
	return tout;
}





//火星
int main() {
	int NumMars;
	cin >> NumMars;
	vector<Mars> F(NumMars);
	int temp1, temp2, temp3;
	vector<line> templine;
	for (int seq = 0;seq < NumMars;seq++) {
		//读数据
		cin >> F[seq].numCity;
		cin >> F[seq].numWay;
		
		for (int i = 0;i < F[seq].numWay;i++) {
			cin >> temp1 >> temp2 >> temp3;
			F[seq].addWay(temp1 - 1, temp2 - 1, temp3);
		}
		for (int i = 0;i < F[seq].numWay;i++) {
			if (cin.peek()) {
				do { cin >> temp1; F[seq].addProtect(i, temp1-1); } while (cin.peek() != '\n');
			}
			else { cin >> temp1; }
			
		}
		//开始侵略
		cout << InvasionTime(F[seq],F[seq].numCity - 1);
	}
	return 0;

}
