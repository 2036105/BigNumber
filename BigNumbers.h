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
	std::vector<unsigned int>data;
	friend ostream& operator<<(ostream& o, const Int& a);
	friend istream& operator>>(istream& input, Int& a);
	friend string& operator>>(const string&source,Int&target);
	Int(){
		data.push_back(0);
	};
	//vector必须显示在std中

	bool operator<( Int& bb);
	bool operator>(Int& bb);
	bool operator==(Int& bb);
	inline bool  operator>=( Int& bb) { return !(*this < bb); }
	inline bool  operator<=(Int& bb) { return !(*this > bb); }
	Int& operator+(Int&bb);
	Int& operator-(Int& bb);
};