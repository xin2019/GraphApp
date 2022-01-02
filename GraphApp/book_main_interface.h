#ifndef BOOK_MAIN_INTERFACE_H_INCLUDED
#define BOOK_MAIN_INTERFACE_H_INCLUDED
#define MaxSize 6
#define MaxArc 10
#define Undirected 1
#define Directed 0


struct tempNode{
	int vernums;
	int arcnums;
	int first[MaxArc];
	int second[MaxArc];
	int weight[MaxArc];
};

struct Point{
	int Point_x;;
	int Point_y;
};

void init_undirected_points(void);
void init_directed_points(void);
void init_undirected(void);
void init_directed(void);
void init_undirected_prim(void);
void init_undirected_prim_points(void);
void init_visited(void);
void book_main_interface(void);

struct ArcNode{
	int adjvex;
	int weight;
	ArcNode* next;
};
struct VertexNode{
	char vertex;
	ArcNode* firstedge;
};
class ALGraph{
public:
	ALGraph(int kind);
	ALGraph(){}
	~ALGraph();
	
	void draw_undirected_matrix();
	void draw_directed_matrix();
	void draw_undirected_link();
	void draw_directed_link();
	void draw_undirected_inverse_link();
	void draw_directed_inverse_link(ALGraph &B);
	void draw_undirected_dfs(int v);
	void draw_undirected_bfs(int v);
	void draw_directed_dfs(int v);
	void draw_directed_bfs(int v);
	int get_vertexNum();
	int get_arcNum();
	int random;
	VertexNode adjlist[MaxSize];
private:

	
	int vertexNum,arcNum;
	
}; 
//prim
typedef  struct {
    int adjvex;
} ArcNode1,MatrixArcNode[MaxSize][MaxSize];

typedef struct {
    int adjvex;
    int lowcost;
} ShortEdge[MaxArc];

class MatrixPrim{
public:
	MatrixPrim();
	void init(int v) ;
	int MinEdge();
	void Prim(int v) ;
	void draw_prim();
	void bubble_sort();
	void Lagrange_binary_search(int num);
	int Matrixrandom;
		int vertexnum;
	int arcnum;
	MatrixArcNode arc;
private:

	ShortEdge shortEdge;
	char vexs[MaxSize];
	
	
	int horizontal;
	int vertical;
	int shortedges[MaxArc];
};
#endif