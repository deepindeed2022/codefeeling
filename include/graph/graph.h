#ifndef ALGORITHM_INCLUDE_ADJLIST_GRAPH_H_
#define ALGORITHM_INCLUDE_ADJLIST_GRAPH_H_
// 邻接矩阵和邻接表的方式
#include <vector>
#include <memory>
#include <stdint.h>
#include <fstream>
#include <iostream>

#define MAX_VERTEX_NUM  50
// 邻接表的表节点
class ArcNode {
public:
	ArcNode() = default;
	ArcNode(uint32_t _adjv, ArcNode* _nextarc) {
		adjvex = _adjv;
		nextarc = std::make_shared<ArcNode>(_nextarc);
	}
	ArcNode(const ArcNode& arc) {
		adjvex = arc.adjvex;
		nextarc = arc.nextarc;
	}
	ArcNode(const ArcNode* arc) {
		if(arc!=nullptr) {
			adjvex = arc->adjvex;
			nextarc = arc->nextarc;
		}
	}
	uint32_t  adjvex;
	std::shared_ptr<ArcNode> nextarc;
};

// 图节点
template <typename T>
class Vnode {
typedef T data_type;
public:
	Vnode() = default;
	Vnode(const T& t)
		: data(t), 
		in_cnt(0), 
		out_cnt(0), 
		firstarc(nullptr) {}
	data_type data;
	uint32_t in_cnt, out_cnt;
	std::shared_ptr<ArcNode> firstarc;
};

template <typename T>
class ALGraph {
	typedef std::vector< Vnode<T> > AdjList;
public:
	ALGraph() = default;
	ALGraph(uint32_t _vexnum, uint32_t _arcnum)
		: vexnum(_vexnum), arcnum(_arcnum) {
		vertices.resize(arcnum);
	}
	ALGraph(const std::string& infile) {
		std::ifstream fin(infile);
		if(!fin) {
			std::cerr << "fail to open the file " << infile << std::endl;
		} else {
			bool result = this->create_(fin);
		}
	}
	std::vector<T> get_arcNodes(const uint32_t i) {
		std::vector<T> vec;
		std::shared_ptr<ArcNode> arcnode = vertices[i].firstarc;
		while(arcnode.get() != nullptr) {
			vec.push_back(arcnode->adjvex + 'A');
			arcnode = arcnode->nextarc;
		}
		return vec;
	}
	~ALGraph() {
	}
	void print_Graph(std::ostream& out) {
		 out << "V\tin\tout\tsum\n";
		for(uint32_t i = 0; i < this->vexnum; i++) {
			uint32_t sum = this->vertices[i].in_cnt + this->vertices[i].out_cnt;
			out << this->vertices[i].data << "\t"
				<< this->vertices[i].in_cnt << "\t"
				<< this->vertices[i].out_cnt << "\t"
				<< sum << std::endl;
		}
	}
private:
	bool create_(std::istream& in) {
		in >> vexnum >> arcnum;
		if(vexnum <= 0) {
			fprintf(stderr, "Input Error Graph!\n");
			return false;
		}
		vertices.resize(vexnum);
		T tmp;
		for(size_t i = 0; i < this->vexnum; i++) {
			in >> tmp;
			vertices[i] = Vnode<T>(tmp);
		}
		char p, q;
		int s, e;
		for(size_t i = 0; i < this->arcnum; i++){
			in >> p >> q;
			s = p - 'A';
			e = q - 'A';
			vertices[s].out_cnt++;
			vertices[e].in_cnt++;
			ArcNode* anode = new ArcNode();
			anode->adjvex = e;
			anode->nextarc = std::make_shared<ArcNode>(vertices[s].firstarc.get());
			vertices[s].firstarc = std::make_shared<ArcNode>(anode);
		}
		return true;
	}
	uint32_t vexnum; // 图节点的个数
	uint32_t arcnum; // 邻接表中邻接点的个数，相当于边的个数
	AdjList vertices;
};

#endif