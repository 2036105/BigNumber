#pragma once
#include<iostream>
#include<iomanip>
#include<vector>
#include<string>
//ÿ��int��Χ��214783648,��9λ
using namespace std;
namespace bn {
	class Int;
};
using namespace bn;
class bn:: Int {
public:
	//����
	bool nega;
	std::vector<unsigned int>data;
	friend ostream& operator<<(ostream& o, const Int& a);
	friend istream& operator>>(istream& input, Int& a);
	friend string& operator>>(const string&source,Int&target);
	Int(){
		data.push_back(0);
	};
	//vector������ʾ��std��

	bool operator<( Int& bb);
	bool operator>(Int& bb);
	bool operator==(Int& bb);
	inline bool  operator>=( Int& bb) { return !(*this < bb); }
	inline bool  operator<=(Int& bb) { return !(*this > bb); }
	Int& operator+(Int&bb);
	Int& operator-(Int& bb);
};