#include<iostream>
#include<vector>
using namespace std;
class line;
class Farm {
public:
	int numField;
	int numPath;
	int numHole;
	vector<line> E;
	vector<int>avai(int id);
	void addPath(int aa, int bb, int cost);
	void addHole(int from, int to, int cost);
	bool IsWay(int from, int to);
	int cost(int from, int to);
	void selfline();
};
class line{
public:
	int b;
	int f;
	int cost;
	line(int aa,int bb,int incost):b(aa),f(bb),cost(incost){}
};
vector<int>Farm::avai(int id) {
	vector<int> temp;
	vector<line>::iterator t = E.begin();
	while (t != E.end()) {
		if (t->b == id) { temp.push_back(t->f); }
		t++;
	}
	return temp;
}
void Farm::addPath(int aa, int bb, int cost) {
	E.push_back(line(aa, bb, cost));
	E.push_back(line(bb, aa, cost));
}
void Farm::addHole(int from, int to, int cost) {
	E.push_back(line(from, to, -cost));
}
bool Farm::IsWay(int from, int to) {
	for (vector<line>::iterator iter = E.begin();iter != E.end();iter++) {
		if (iter->b == from && iter->f == to) { return 1; }
	}
	return 0;
}
int Farm::cost(int from, int to) {
	for (vector<line>::iterator iter = E.begin();iter != E.end();iter++) {
		if (iter->b == from && iter->f == to) { return iter->cost; }
	}
	return 0;
}
int& cost(vector<line>&map,int from, int to) {
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
void Farm::selfline() {
	for (int i = 0;i < numField;i++) {
		addHole(i, i, 0);
	}
}
int expect(int map[][500], int id,int n) {
	int temp=9999999;
	for (int i = 0;i < n;i++) {
		if (temp <map[ id][ i] + temp < map[i][id]) {
			temp = map[id][i] + temp < map[i][id];
		}
	}
	return temp;
}





//虫洞农场
int main() {
	int NumFarm;
	cin >> NumFarm;
	vector<Farm> F(NumFarm);
	int temp1, temp2, temp3;
	vector<line> templine;
	for (int seq = 0;seq < NumFarm;seq++) {
		//读数据
		cin >> F[seq].numField;
		cin >> F[seq].numPath;
		cin >> F[seq].numHole;
		for (int i = 0;i < F[seq].numPath;i++) {
			cin >> temp1 >> temp2 >> temp3;
			F[seq].addPath(temp1-1, temp2-1, temp3);
		}
		for (int i = 0;i < F[seq].numHole;i++) {
			cin >> temp1 >> temp2 >> temp3;
			F[seq].addHole(temp1-1, temp2-1, temp3);
		}
		F[seq].selfline();
		
		//做最低路径
		templine = F[seq].E;
		int tempmat[500][500];
		for (int i = 0;i < F[seq].numField;i++) {
			for (int j = 0;j < F[seq].numField;j++) {
				tempmat[i][j] = F[seq].IsWay(i, j) ? cost(F[seq].E, i, j) : 99999999;
			}
		}
		for (int k = 0;k < F[seq].numField;k++) {
			for (int i = 0;i < F[seq].numField;i++){
				for (int j = 0;j < F[seq].numField;j++) {
					if (tempmat[ i][j] > tempmat[i][k] + tempmat[k][j]) {
					tempmat[i][j] = tempmat[i][k] + tempmat[k][j];
					}
				}
			}
		}
		for (temp1=0;temp1 < F[seq].numField;temp1++) {
			if (tempmat[temp1][temp1] < 0) {
				cout << "YES\n";
				break;
			}
		}
		if (temp1 >= F[seq].numField) { cout << "NO\n"; }
	}
	return 0;

}
