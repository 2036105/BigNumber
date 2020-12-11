#pragma once
#include<iostream>
#include<vector>
#include<initializer_list>
//多项式
//函数实现在对应的Cpp中
class Polynomial
{
public:
	//0多项式的系数设为-1;
	long degree = 0;
	std::vector<double> c;
	Polynomial(){}
	//类型转换构造函数
	//in是常数值,不是说多项式有1次
	Polynomial(int in);
	//重载括号,用于多项式赋值
	double operator()(double in);
	//重载加号,两个多项式相加
	Polynomial operator+(const Polynomial& bb);
	inline Polynomial operator+(const double bb);
	Polynomial& operator+=(const Polynomial& bb);
	inline Polynomial& operator+=(const double bb);
	Polynomial operator-(const Polynomial& bb);
	inline Polynomial operator-(const double bb);
	Polynomial& operator-=(const Polynomial& bb);
	inline Polynomial& operator-=(const double bb);
	Polynomial operator*(const Polynomial& bb);
	inline Polynomial operator*(const double bb);
	Polynomial& operator*=(const Polynomial& bb);
	inline Polynomial& operator*=(const double bb);
	//增次
	inline Polynomial& operator<<(int in);
	//降次
	inline Polynomial& operator>>(int in);
	//求导,默认次数为1;
	Polynomial der(int n = 1);
	//不定积分,默认次数为1,返回一个多项式
	Polynomial inte(int n = 1);
	Polynomial operator/(const Polynomial& bb);
	Polynomial& operator/=(const double bb);
	friend std::ostream& operator<<(std::ostream& out, const Polynomial& bb);
	friend std::string& operator<<(std::string&out, const Polynomial& bb);
	//输入每个项,从高到低输入
	//先输度数,把系数放在大括号内
	void set(int indegree,std::initializer_list<double> in);
private:

};
