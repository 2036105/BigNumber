#pragma once
#include<utility>
#include<map>
#include<vector>
//ͼ�йص�һЩ����

class Graph;
//�ڵ�
class node {
	int id;
	Graph* owner;
	node(Graph*inG,int idin):owner(inG),id(idin){}
};
//����ͼ
class Graph {
	int numV=0;
	int numE = 0;
	std::map<int,node>V;
	std::map<int,int> E;
	void addV(node& in);
	void del(int id);
};
void Graph::del(int id) {
	V.find(id)->second;
	E.erase(id);
	V.erase(id);
}
void Graph::addV(node& in) {

}
