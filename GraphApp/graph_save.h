#ifndef GRAPH_SAVE_H_INCLUDED
#define GRAPH_SAVE_H_INCLUDED





void graph_save();//���洰��


const int maxVertexNum = 6;//��󶥵���




int RandomVexnum();        //������ɶ��������ȡֵ��1-6֮��


void initVisited();         //��ʼ������visited


//ͼ���ڽӾ���洢
class basicGraph_Matrix {
	
private:
    typedef struct MatrixCell {
        int weight;         //�����ϵ���͡���Ȩͼ��0/1��ʾ�Ƿ����ڣ���Ȩͼ����ʾȨֵ
    } MatrixCell, Matrix[maxVertexNum][maxVertexNum];
	

    typedef struct {
        char Vexs[maxVertexNum];        //����ı����ĸ
        Matrix matrix;      //�ڽӾ���
        int vertexNum;      //������
        int arcnum;         //����
    } MatrixGraph;

	
    MatrixGraph graph;
	
	
public:
    basicGraph_Matrix() {}       //���캯��


	int getVertexNum();//������

	int getArcnum();//����

	char* getVexs();//����ı����ĸ

    void creatRandomGraph();     //�������ͼ


	
    void DFSTraverse(int v);      //ͼ����ȱ���
	
    void BFSTraverse(int v);      //ͼ�Ĺ�ȱ���

	int random_first_node[maxVertexNum];
	int random_second_node[maxVertexNum];
};


#endif