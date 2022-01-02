#include<graphics.h>

#include"graph_save.h"

#include"main_interface.h"
#include"graph_save_random.h"
#include<stdlib.h>
#include<time.h>


bool visited[maxVertexNum];     //访问标识

void graph_save(){
	
	initgraph(640,480);
	mouse_msg msg = {0};
				for(; is_run(); delay_fps(1000))
				{
					
					
					while (mousemsg())
					{
						msg = getmouse();
					}
					cleardevice();
					setcolor(WHITE);
					xyprintf(0, 0, "x = %10d  y = %10d",
						msg.x, msg.y);
					setfont(24, 0, "宋体");
					
					setbkmode(TRANSPARENT);
					setcolor(WHITE);
					setfont(20, 0, "宋体");
					outtextxy(30,68,"点击随机生成图");
					outtextxy(38,174,"邻接矩阵存储");
					outtextxy(38,296,"邻接表存储");
					setcolor(GREEN);
					rectangle(183,9,623,217);
					rectangle(183,233,624,434);
					setcolor(WHITE);
					setfont(16, 0, "宋体");
					outtextxy(406,446,"主界面");
					outtextxy(544,446,"退出程序");
					
					bool isleft=msg.is_left();
					
					if(msg.x>543&&msg.x<605&&msg.y>445&&msg.y<460&&(isleft==true)){//退出
						
						closegraph();
					}
					else if(msg.x>406&&msg.x<470&&msg.y>445&&msg.y<461&&(isleft==true)){//主界面
						
						closegraph();
						show_main();
					}
					else if(msg.x>30&&msg.x<168&&msg.y>68&&msg.y<84&&(isleft==true)){//随机生成图
						
						bool isPaint=true;
						basicGraph_Matrix Graph;Graph.creatRandomGraph();
						int vernums=Graph.getVertexNum();
						int arcnums=Graph.getArcnum();
						char* vers=Graph.getVexs();
						int *point_x=new int[vernums];
						int *point_y=new int[vernums];
						
						for(int i=0;i<vernums;i++){
							point_x[i]=203;
							point_y[i]=30;
						}
						int x,y;
						setcolor(WHITE);
						srand((unsigned)time(NULL));
						for( i=0;i<vernums;){
							x=203+(rand()%398);
							y=30+(rand()%166);
							for(int j=0;j<vernums;j++){
								if((x>=point_x[j]-40&&x<=point_x[j]+40)&&(y>=point_y[j]-40&&y<=point_y[j]+40)){
									isPaint=false;
									break;
								}
							}
							if(isPaint==true){
								point_x[i]=x;
								point_y[i]=y;
								setcolor(WHITE);
								setfillstyle(SOLID_FILL,WHITE);
								fillellipse(x,y,20,20);
								setcolor(BLACK);
								outtextxy(x,y,vers[i]);
								i++;
								
							}
							
						}//for
						setcolor(WHITE);
						
						for(i=0;i<arcnums;i++){
							line(point_x[Graph.random_first_node[i]],point_y[Graph.random_first_node[i]],point_x[Graph.random_second_node[i]],point_y[Graph.random_second_node[i]]);
						}
						
							
						char str[4];
						//调用对话框函数
						inputbox_getline("请输入", "if you select Matrix，please input 'a',else if you select Link please input 'b'（回车确认）,else please input anykey to reselect", str, 4);
						if(str[0]=='a'){//Matrix
							int horizontal_increment=361/(vernums+1);
							int vertical_increment=174/(vernums+1);
							setcolor(GREEN);
							rectangle(31,168,163,201);
							
							setcolor(WHITE);
						
							setfont(((int)vertical_increment*0.7), 0, "宋体");
							for(int j=1;j<vernums+1;j++){
								outtextxy(232+horizontal_increment*j,252,vers[j-1]);
								outtextxy(232,252+vertical_increment*j,vers[j-1]);
							}
							for(int i=0;i<vernums+2;i++){
								line(227,247+vertical_increment*i,588,247+vertical_increment*i);
								line(227+horizontal_increment*i,247,227+horizontal_increment*i,421);
							}
							bool flag=false;
							for(i=0;i<vernums;i++){
								for(j=0;j<vernums;j++){
									
									for(int k=0;k<arcnums;k++){
										if(i==Graph.random_first_node[k]&&j==Graph.random_second_node[k]){
											outtextxy(232+horizontal_increment*(j+1),252+vertical_increment*(i+1),"1");
											flag=true;break;
										}
										
									}
									
									for( k=0;k<arcnums;k++){
										if(i==Graph.random_second_node[k]&&j==Graph.random_first_node[k]){
											outtextxy(232+horizontal_increment*(j+1),252+vertical_increment*(i+1),"1");
											flag=true;break;
										}
										
									}
									
									if(!flag){
										outtextxy(232+horizontal_increment*(j+1),252+vertical_increment*(i+1),"0");
									}
									flag=false;
								}
								
							}
						}//if a
						if(str[0]=='b'){//Link
							int horizontal_increment=388/vernums;
							int vertical_increment=165/vernums;
							setcolor(GREEN);
							rectangle(34,290,140,314);//item selected
							setcolor(WHITE);
							setfont(((int)vertical_increment*0.5), 0, "宋体");
								int which_one_first=0;
								int which_one_second=0;
							for(int i=0;i<vernums;i++){
								rectangle(209+0.2*horizontal_increment,245+(i+0.2)*vertical_increment,209+0.7*horizontal_increment,245+(i+0.7)*vertical_increment);
								outtextxy(209+0.3*horizontal_increment,245+(i+0.2)*vertical_increment,vers[i]);
								which_one_first=0;
								which_one_second=0;
								for(int j=0;j<arcnums;j++){
									int first=Graph.random_first_node[j];
									int second=Graph.random_second_node[j];
							//		xyprintf(300, 250+i*20, "x = %d  y = %d",i, j);
								//	xyprintf(300,50+i*20,"first=%d,second=%d",first,second);
									if(i==first){
										which_one_first++;
										rectangle(209+(0.2+which_one_first)*horizontal_increment,245+(0.2+i)*vertical_increment,209+(0.7+which_one_first)*horizontal_increment,245+(0.7+i)*vertical_increment);
										line(209+(which_one_first-0.3)*horizontal_increment,245+(0.5+i)*vertical_increment,209+(0.2+which_one_first)*horizontal_increment,245+(0.5+i)*vertical_increment);
										outtextxy(209+(0.3+which_one_first)*horizontal_increment,245+(0.2+i)*vertical_increment,vers[second]);
									}else if(i==second){
									which_one_second++;
									rectangle(209+(0.2+which_one_second)*horizontal_increment,245+(0.+i)*vertical_increment,209+(0.7+which_one_second)*horizontal_increment,245+(0.7+i)*vertical_increment);
														line(209+(which_one_second-0.3)*horizontal_increment,245+(0.5+i)*vertical_increment,209+(0.2+which_one_second)*horizontal_increment,245+(0.5+i)*vertical_increment);		
									outtextxy(209+(0.3+which_one_second)*horizontal_increment,245+(0.2+i)*vertical_increment,vers[first]);
							
									}
								}
							}
						}
						getch();
						delete point_x;
						delete point_y;
						}//if click
						
	}//for
	
	
	
	
}//graph_save



//共用类的实现
void initVisited() {
    for(int i = 0; i < maxVertexNum; i++) {
        visited[i] = false;
    }
}
int RandomVexnum() {
    srand((unsigned)time(NULL));
    int random = 1 + (rand() % maxVertexNum); //产生[1,6]的整数
											  /*	setcolor(WHITE);
											  xyprintf(0, 150, "RandomVexnum:%10d",
	random);*/
    return random;
}


//邻接矩阵实现


int basicGraph_Matrix::getVertexNum()//顶点数
{
	return graph.vertexNum;
}

int basicGraph_Matrix::getArcnum()//边数
{
	return graph.arcnum;
}

char* basicGraph_Matrix::getVexs()//顶点的编号字母
{
	return graph.Vexs;
}



void basicGraph_Matrix::creatRandomGraph() {
    graph.vertexNum = RandomVexnum();       //随机生成顶点数
	int vernums=graph.vertexNum;
	srand((unsigned)time(NULL));
    graph.arcnum =rand()%(vernums+1);      //  随机生成边数
	
    for(int i = 0; i < graph.vertexNum; i++) {
        graph.Vexs[i] = char(65 + i);
        for(int j = 0; j < graph.vertexNum; j++) {
            graph.matrix[i][j].weight= 0;
        }
    }
	
	
	srand((unsigned)time(NULL));
    for( i = 0; i < graph.arcnum; ) {
		//随机生成顶点编号
		
		int a=rand()%vernums;
		int b=rand()%vernums;
		if(a==b){
			continue;
		}
		random_first_node[i]=a;
		random_second_node[i]=b;
		
        graph.matrix[a][b].weight = 1;
		//为无向图
		graph.matrix[b][a].weight = 1;
        
		i++;
		
    }
	
}




void basicGraph_Matrix::DFSTraverse(int v) {    //图的深度遍历
	
	//  cout << graph.Vexs[v];
    visited[v] = true;
    for(int j = 0; j < graph.vertexNum; j++) {
        if(graph.matrix[v][j].weight == 1 && visited[j] == false) {
            basicGraph_Matrix::DFSTraverse(j);
        }
    }
}

void basicGraph_Matrix::BFSTraverse(int v) {   //图的广度遍历
    int front = -1;
    int rear = -1;
	//  cout << graph.Vexs[v];
    visited[v] = true;
    int Queue[maxVertexNum];
    Queue[++rear] = v;
    while(front != rear) {
        v = Queue[++front];
        for(int j = 0; j < graph.vertexNum; j++) {
            if(graph.matrix[v][j].weight == 1 && visited[j] == false) {
				//  cout << graph.Vexs[j];
                visited[j] = true;
                Queue[++rear] = j;
            }
        }
    }
}
