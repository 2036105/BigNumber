#pragma once
#include<utility>
#include<map>
#include<vector>
//图有关的一些工具

class Graph;
//节点
class node {
	int id;
	Graph* owner;
	node(Graph*inG,int idin):owner(inG),id(idin){}
};
//无向图
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
