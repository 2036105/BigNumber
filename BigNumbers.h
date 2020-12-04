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
string& operator>>(const string&source,Int& target) {
	
}

Int& Int::operator+(const Int& bb) {
	Int Temp(*this);
}

