#pragma once
#include<iostream>
#include<iomanip>
#include<vector>
#include<string>
//每个int范围是214783648,存9位
using namespace std;
namespace bn {
	class Int;
};
using namespace bn;
class bn:: Int {
public:
	//符号
	bool nega;
	std::vector<int>data;
	friend ostream& operator<<(ostream& o, const Int& a);
	friend istream& operator>>(istream& input, Int& a);
	friend string& operator>>(const string&source,Int&target);
	Int(){
		data.push_back(0);
	};
	//vector必须显示在std中
	Int& operator+(const Int&bb);
	
};


ostream& operator<<(ostream& o,const Int&a) {
	if (a.nega) { o << '-'; }
	size_t len = a.data.size();
	for (size_t i = len-1; i !=4294967295; i++) {
		cout << a.data[i];
	}
	return o;
}

istream& operator>>(istream& input, Int& a) {
	if (input.peek() == '-') { a.nega = 0;input.get(); }
	int i = 0;int temp;char temp2;
	while (input.peek() >= '0' && input.peek() <= '9') {
		cin.get() >> temp2;
		if(temp2>='0'&&temp2<='9'){}
	}


	int temp = 0;
	for(int j=0;j<i;j++,i--){
		a.data[i] ^= a.data[j];
		a.data[j] ^= a.data[i];
		a.data[i] ^= a.data[j];
	}
	return input;
}
string& operator>>(const string source,Int& target) {
	target.data.clear();
	string::const_iterator init = source.begin();
	if (*init == '-') { target.nega = 1;
	init++;
	}
	string::const_iterator fin = source.end() ;
	fin--;
	string::iterator temp;
	int i;
	if (fin == init) {
		target.data.push_back(*fin - '0');
	}
	else {
		int TempSect = 0;
		while (fin >= init) {
			for (i = 0;i < 31&&fin!=init;i++) {
				for (temp = init;temp != fin;temp++) {
					*(temp + 1) += CarryOver(*temp);
				}
				TempSect += CarryOver(*temp)<<i;
				while (*init == '0') { init++; }
			}
			target.data.push_back(TempSect);
			
		}
	}
		
}

Int& Int::operator+(const Int& bb) {
	Int Temp(*this);
}

inline bool CarryOver(char&in) {
	if ((in - '0') % 2) {
		in = (in - '0') / 2 + '0';
		return 1;
	}
	else {
		in = (in - '0') / 2 + '0';
		return 0;
	}
}