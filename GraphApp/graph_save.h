#ifndef GRAPH_SAVE_H_INCLUDED
#define GRAPH_SAVE_H_INCLUDED





void graph_save();//界面窗口


const int maxVertexNum = 6;//最大顶点数




int RandomVexnum();        //随机生成顶点个数，取值在1-6之间


void initVisited();         //初始化数组visited


//图的邻接矩阵存储
class basicGraph_Matrix {
	
private:
    typedef struct MatrixCell {
        int weight;         //顶点关系类型。无权图：0/1表示是否相邻；有权图：表示权值
    } MatrixCell, Matrix[maxVertexNum][maxVertexNum];
	

    typedef struct {
        char Vexs[maxVertexNum];        //顶点的编号字母
        Matrix matrix;      //邻接矩阵
        int vertexNum;      //顶点数
        int arcnum;         //边数
    } MatrixGraph;

	
    MatrixGraph graph;
	
	
public:
    basicGraph_Matrix() {}       //构造函数


	int getVertexNum();//顶点数

	int getArcnum();//边数

	char* getVexs();//顶点的编号字母

    void creatRandomGraph();     //随机生成图


	
    void DFSTraverse(int v);      //图的深度遍历
	
    void BFSTraverse(int v);      //图的广度遍历

	int random_first_node[maxVertexNum];
	int random_second_node[maxVertexNum];
};


#endif