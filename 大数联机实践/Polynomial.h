#pragma once
#include<iostream>
#include<vector>
#include<initializer_list>
//����ʽ
//����ʵ���ڶ�Ӧ��Cpp��
class Polynomial
{
public:
	//0����ʽ��ϵ����Ϊ-1;
	long degree = 0;
	std::vector<double> c;
	Polynomial(){}
	//����ת�����캯��
	//in�ǳ���ֵ,����˵����ʽ��1��
	Polynomial(int in);
	//��������,���ڶ���ʽ��ֵ
	double operator()(double in);
	//���ؼӺ�,��������ʽ���
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
	//����
	inline Polynomial& operator<<(int in);
	//����
	inline Polynomial& operator>>(int in);
	//��,Ĭ�ϴ���Ϊ1;
	Polynomial der(int n = 1);
	//��������,Ĭ�ϴ���Ϊ1,����һ������ʽ
	Polynomial inte(int n = 1);
	Polynomial operator/(const Polynomial& bb);
	Polynomial& operator/=(const double bb);
	friend std::ostream& operator<<(std::ostream& out, const Polynomial& bb);
	friend std::string& operator<<(std::string&out, const Polynomial& bb);
	//����ÿ����,�Ӹߵ�������
	//�������,��ϵ�����ڴ�������
	void set(int indegree,std::initializer_list<double> in);
private:

};
