#include<graphics.h>
#include"graph_save_random.h"
#include"graph_save.h"
void graph_random()//���ͼ����
{
	initgraph(640,480);
	mouse_msg msg = {0};
	bool showmain=true;
	while(showmain){
		setcolor(WHITE);
		setfont(20, 0, "����");
		outtextxy(30,68,"����������ͼ");
		outtextxy(38,174,"�ڽӾ���洢");
		outtextxy(38,296,"�ڽӱ�洢");
		setcolor(GREEN);
		rectangle(183,9,623,217);
		rectangle(183,233,624,434);
		setcolor(WHITE);
		setfont(16, 0, "����");
		outtextxy(406,446,"������");
		outtextxy(544,446,"�˳�����");
		
		
		
		/*	
		setfillstyle(SOLID_FILL,WHITE);
		fillellipse(280,50,20,20);
		setcolor(BLACK);
		outtextxy(280,50,"A");
		*/
		
		
		setcolor(WHITE);
		bool isleft=msg.is_left();
		
		if(msg.x>30&&msg.x<168&&msg.y>68&&msg.y<84&&(isleft==true)){
			
		/*	basicGraph_Matrix graph;
		graph.creatRandomGraph(unDirectionGraph);
			graph.reflectScreen();*/
			
			int vernum,arcnum;
			int x,y;
			RandomPoint(x,y);
			vernum=RandomVexnum();
			arcnum=RandomArcnum();
			
			
			
		}
		if(msg.x>543&&msg.x<605&&msg.y>445&&msg.y<460&&(isleft==true)){//�˳�
			showmain=false;
		}
		
		
		closegraph();
		
		
	}
}