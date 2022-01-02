
#include<graphics.h>
#include <ctype.h>
#include<fstream>
#include<stdlib.h>
#include<time.h>
#include"book_main_interface.h"
#include"main_interface.h"
using namespace std;


tempNode undirected_nodes[MaxSize];
tempNode directed_nodes[MaxSize];
tempNode undirected_prim_nodes[MaxSize];
Point undirected_point[MaxSize][MaxArc];
Point directed_point[MaxSize][MaxArc];
Point undirected_prim_nodes_point[MaxSize][MaxArc];
bool node_visited[MaxSize];
int the_number_of_stack;
int stack_horizontal_increment;
int stack_vertical_increment;
char temp_verchars[MaxSize];

void init_undirected() {
    ifstream cin;
    cin.open("undirected.txt");	
    int a, b;
    int i = 0;
    while(!cin.eof()) {
        cin >> a >> b;
        undirected_nodes[i].vernums = a;
        undirected_nodes[i].arcnums = b;
        for(int j = 0; j < b; j++) {
            cin >> undirected_nodes[i].first[j] >> undirected_nodes[i].second[j];
        }
		//  xyprintf(50, 150 + i * 60, "vernums:%d arcnums:%d", a, b);
        i++;
    }
	
    cin.close();
}
void init_directed() {
    ifstream cin;
    cin.open("directed.txt");
    int a, b;
    int i = 0;
    while(cin >> a >> b) {
        directed_nodes[i].vernums = a;
        directed_nodes[i].arcnums = b;
        for(int j = 0; j < b; j++) {
            cin >> directed_nodes[i].first[j] >> directed_nodes[i].second[j];
        }
        i++;
    }
	
    cin.close();
	
}


void init_undirected_points() {
    ifstream cin;
    cin.open("undirected_point.txt");
	
    for(int k = 0; k < MaxSize; k++) {
        int point_nums = undirected_nodes[k].vernums;
        for(int l = 0; l < point_nums; l++) {
            cin >> undirected_point[k][l].Point_x >> undirected_point[k][l].Point_y;
        }
    }
    cin.close();
}

void init_directed_points() {
    ifstream cin;
    cin.open("directed_point.txt");
    for(int k = 0; k < MaxSize; k++) {
        int point_nums = directed_nodes[k].vernums;
        for(int l = 0; l < point_nums; l++) {
			
            cin >> directed_point[k][l].Point_x >> directed_point[k][l].Point_y;
			
			// xyprintf(350, 150 + (k + l) * 60, "c:%d   d:%d", directed_point[k][l].Point_x, directed_point[k][l].Point_y);
        }
    }
    cin.close();
}
void init_undirected_prim(void){
	ifstream cin;
    cin.open("undirected_prim.txt");
	int a, b;
    int i = 0;
    while(cin >> a >> b) {
        undirected_prim_nodes[i].vernums = a;
        undirected_prim_nodes[i].arcnums = b;
		//	xyprintf(350, 10+i*60, "a:%d,b=%d", undirected_prim_nodes[i].vernums,undirected_prim_nodes[i].vernums);///////////////////////////////////////////////////
        for(int j = 0; j < b; j++) {
            cin >> undirected_prim_nodes[i].first[j] >> undirected_prim_nodes[i].second[j]>>undirected_prim_nodes[i].weight[j];
        }
		
        i++;
    }
	cin.close();
}
void init_undirected_prim_points(void){
	ifstream cin;
    cin.open("undirected_prim_point.txt");
	int point_nums;
    for(int k = 0; k < 3; k++) {
		point_nums = undirected_prim_nodes[k].vernums;
        for(int l = 0; l < point_nums; l++) {
			
            cin >> undirected_prim_nodes_point[k][l].Point_x >> undirected_prim_nodes_point[k][l].Point_y;
			
        }
    }
	
    cin.close();
}
void init_visited(void){
	for(int i=0;i<MaxSize;i++){
		node_visited[i]=false;
	}
}

void book_main_interface(void) {
	
	
    initgraph(720, 540);
	
    mouse_msg msg = {0};
	
    init_undirected();
    init_undirected_points();
    init_directed();
    init_directed_points();
	init_undirected_prim();
	init_undirected_prim_points();
	
    for(; is_run(); delay_fps(60)) {
        while (mousemsg()) {
            msg = getmouse();
        }
        cleardevice();
     //   xyprintf(0, 0, "x = %10d  y = %10d",
	//		msg.x, msg.y, msg.wheel);
		
		
        bool isleft = msg.is_left();
        if(msg.x > 638 && msg.x < 672 && msg.y > 22 && msg.y < 35 && (isleft == true)) { //exit
            closegraph();
        }
		if(msg.x > 505 && msg.x < 639 && msg.y > 22 && msg.y < 36 && (isleft == true)) { //first version
            closegraph();
			show_main();
        }
        //Undirected Graph
        if(msg.x > 23 && msg.x < 273 && msg.y > 200 && msg.y < 214 && (isleft == true)) { //Adjacency Matrix Representation
            cleardevice();
			//	outtextxy(575, 17, "Exit");
			outtextxy(0,0,"Please press anykey to generate a new graph");
            ALGraph* al = new ALGraph(Undirected);
			al->draw_undirected_matrix();
			getch();
			delete al;
            
        }
        if(msg.x > 23 && msg.x < 256 && msg.y > 260 && msg.y < 274 && (isleft == true)) { //Adjacency List Representation
			cleardevice();
			outtextxy(0,0,"Please press anykey to generate a new graph");
            ALGraph* al = new ALGraph(Undirected);
			al->draw_undirected_link();
			getch();
			delete al;
        }
        if(msg.x > 23 && msg.x < 320 && msg.y > 320 && msg.y < 335 && (isleft == true)) { //Inverse Adjacency List Representation
			cleardevice();
			setcolor(GREEN);
			outtextxy(0,0,"Strictly speaking, an undirected graph has no inverse adjacency list,");
            outtextxy(0,20,"because there is no difference between the degree ");
			outtextxy(0,40,"of exit and the degree of entry");
			setcolor(WHITE);
			ALGraph* al = new ALGraph(Undirected);
			al->draw_undirected_link();
			getch();
			delete al;
        }
        if(msg.x > 23 && msg.x < 240 && msg.y > 380 && msg.y < 395 && (isleft == true)) { //DFS Traverse Representation
			cleardevice();
			outtextxy(0,0,"Starting at node A, and you can press any key to generate a new graph");
			outtextxy(240,70,"Into the stack sequence");
			outtextxy(240,390,"The output sequence");
			init_visited();
			the_number_of_stack=0;
			ALGraph* al = new ALGraph(Undirected);
			int vernums=al->get_vertexNum();
			setcolor(WHITE);
			stack_horizontal_increment=355/(2*vernums-1);
			stack_vertical_increment=300/vernums;
			setfont(((int)stack_vertical_increment*0.5), 0, "宋体");
			for(int i=0;i<vernums;i++){//For multiple connected components
				if(node_visited[i]==false){
					al->draw_undirected_dfs(i);
				}
			}
			
			getch();
			delete al;
        }
        if(msg.x > 23 && msg.x < 240 && msg.y > 440 && msg.y < 454 && (isleft == true)) { //BFS Traverse Representation
			cleardevice();
			outtextxy(0,0,"Starting at node A, and you can press any key to generate a new graph");
			outtextxy(240,70,"Into the stack Queue");
			outtextxy(240,420,"The output sequence");
			init_visited();
			the_number_of_stack=0;
			ALGraph* al = new ALGraph(Undirected);
			int vernums=al->get_vertexNum();
			setcolor(WHITE);
			stack_horizontal_increment=355/(vernums+1);
			stack_vertical_increment=330/(5*vernums);
			for(int i=0;i<vernums;i++){//For multiple connected components
				if(node_visited[i]==false){
					al->draw_undirected_bfs(i);
				}
			}
			
			
			getch();
			delete al;
        }
		
		if(msg.x > 23 && msg.x < 176 && msg.y > 500 && msg.y < 519 && (isleft == true)) { //Prim Representation
			cleardevice();
			setcolor(WHITE);
			outtextxy(0,0,"Shortedge is short for se,Vertex set vs for short,Press any key to enter the judging edge");
			MatrixPrim* prim=new MatrixPrim();
			prim->init(0);
			prim->Prim(0);
			prim->draw_prim();
			getch();
			
			char str[4];
			inputbox_getline("请输入",
				"Enter two endpoints of the edge you want to judge（输入完请回车，大小写均可）",
				str,
				sizeof(str)/sizeof(*str));
			
			char a=str[0];
			char b=str[2];
			char aa=toupper(a);
			char bb=toupper(b);
	//	=============================================================================================================
	//		xyprintf(10,490,"%c,%c",aa,bb);
			int first=aa-65;
			int second=bb-65;
			int weight=999;
			weight=prim->arc[first][second].adjvex;
			prim->bubble_sort();
		
			if(weight!=999)
			{
				prim->Lagrange_binary_search(weight);
				outtextxy(380,550,"The edge is in the minimum spanning tree!");
			}
			else
			{
				outtextxy(380,550,"infinitely great");
			}
			
			getch();
			
			delete prim;
		}
		//Directed Graph
        if(msg.x > 335 && msg.x < 585 && msg.y > 200 && msg.y < 214 && (isleft == true)) { //Adjacency Matrix Representation
			cleardevice();
			outtextxy(0,0,"Please press any key to generate a new graph");
			setcolor(WHITE);
			setfillstyle(SOLID_FILL, WHITE);
			ALGraph* al = new ALGraph(Directed);
			
			al->draw_directed_matrix();//xyprintf(10,490,"di %d tiao ji lu",al->random);
			getch();
			delete al;
        }
        if(msg.x > 335 && msg.x < 566 && msg.y > 260 && msg.y < 274 && (isleft == true)) { //Adjacency List Representation
			cleardevice();
			outtextxy(0,0,"Please press any key to generate a new graph");
            ALGraph* al = new ALGraph(Directed);//xyprintf(10,490,"di %d tiao ji lu",al->random);
			al->draw_directed_link();
			getch();
			delete al;
        }
        if(msg.x > 335 && msg.x < 630 && msg.y > 320 && msg.y < 335 && (isleft == true)) { //Inverse Adjacency List Representation
			cleardevice();
			outtextxy(0,0,"Please press any key to generate a new graph");
            ALGraph* al = new ALGraph(Directed);
			ALGraph  B;
			al->draw_directed_inverse_link(B);
		//	xyprintf(350,350,"b.vertex=%d",B.get_vertexNum());
		//	xyprintf(10,490,"di %d tiao ji lu",al->random);
			getch();
			delete al;
        }
        if(msg.x > 335 && msg.x < 552 && msg.y > 380 && msg.y < 395 && (isleft == true)) { //DFS Traverse Representation
			cleardevice();
			outtextxy(0,0,"Starting at node A, and you can press any key to generate a new graph");
			outtextxy(240,70,"Into the queue sequence");
			outtextxy(240,390,"The output sequence");
			init_visited();
			the_number_of_stack=0;
			ALGraph* al = new ALGraph(Directed);//xyprintf(10,490,"di %d tiao ji lu",al->random);
			int vernums=al->get_vertexNum();
			setcolor(WHITE);
			stack_horizontal_increment=355/(2*vernums-1);
			stack_vertical_increment=300/vernums;
			setfont(((int)stack_vertical_increment*0.5), 0, "宋体");
			for(int i=0;i<vernums;i++){//For multiple connected components
				if(node_visited[i]==false){
					al->draw_directed_dfs(i);
				}
			}
			
			getch();
			delete al;
        }
        if(msg.x > 335 && msg.x < 555 && msg.y > 440 && msg.y < 454 && (isleft == true)) { //BFS Traverse Representation
			cleardevice();
			outtextxy(0,0,"Starting at node A, and you can press any key to generate a new graph");
			outtextxy(240,70,"Into the Queue sequence");
			outtextxy(240,420,"The output sequence");
			init_visited();
			the_number_of_stack=0;
			ALGraph* al = new ALGraph(Directed);//xyprintf(10,490,"di %d tiao ji lu",al->random);
			int vernums=al->get_vertexNum();
			setcolor(WHITE);
			stack_horizontal_increment=355/(vernums+1);
			stack_vertical_increment=330/(5*vernums);
			for(int i=0;i<vernums;i++){//For multiple connected components
				if(node_visited[i]==false){
					al->draw_directed_bfs(i);
				}
			}
			
			
			getch();
			delete al;
        }
		
        setfont(24, 0, "宋体");
		
		
        //设置文字背景填充方式为透明，默认为OPAQUE不透明
        setbkmode(TRANSPARENT);
        outtextxy(190, 50, "图的课堂演示系统");
		
        line(100, 120, 500, 120);
		
        setfont(20, 0, "宋体");
        setcolor(BLUE);
		
        outtextxy(23, 146, "Undirected Graph");
		
        outtextxy(335, 146, "Directed Graph");
		
        setfont(16, 0, "宋体");
        setcolor(GREEN);
		
        outtextxy(23, 200, "Adjacency Matrix Representation");
		
        outtextxy(23, 260, "Adjacency List Representation");
		
        outtextxy(23, 320, "Inverse Adjacency List Representation");
		
        outtextxy(23, 380, "DFS Traverse Representation");
		
        outtextxy(23, 440, "BFS Traverse Representation");
		
		outtextxy(23, 500, "Prim Representation");
		
		
        outtextxy(335, 200, "Adjacency Matrix Representation");
		
        outtextxy(335, 260, "Adjacency List Representation");
		
        outtextxy(335, 320, "Inverse Adjacency List Representation");
		
        outtextxy(335, 380, "DFS Traverse Representation");
		
        outtextxy(335, 440, "BFS Traverse Representation");
		
        setcolor(WHITE);
		
        outtextxy(638, 22, "Exit");

		outtextxy(505, 22, "first version");
		
		
    }
	
	
}

ALGraph::ALGraph(int kind) {
	
    srand((unsigned)time(NULL));
	
    //	xyprintf(200,200,"randomNode:%d",random);
    if(kind == Undirected) {
		random = rand() % MaxSize;
        vertexNum = undirected_nodes[random].vernums;
        arcNum = undirected_nodes[random].arcnums;
    } else {
		random = rand() %( MaxSize-1);
        vertexNum = directed_nodes[random].vernums;
        arcNum = directed_nodes[random].arcnums;
    }
	
    for(int i = 0; i < vertexNum; i++) {
        adjlist[i].vertex = char(65 + i);
        adjlist[i].firstedge = NULL;
    }
	
    for(i = 0; i < arcNum; i++) {
		
        if(kind == Directed) {
            int a = directed_nodes[random].first[i];
            int b = directed_nodes[random].second[i];
            ArcNode* s = new ArcNode;
            s->adjvex = b;
            s->next = adjlist[a].firstedge;
            adjlist[a].firstedge = s;
        } else {
            int a = undirected_nodes[random].first[i];
            int b = undirected_nodes[random].second[i];
            ArcNode* s = new ArcNode;
            s->adjvex = b;
            s->next = adjlist[a].firstedge;
            adjlist[a].firstedge = s;
            ArcNode* n = new ArcNode;
            n->adjvex = a;
            n->next = adjlist[b].firstedge;
            adjlist[b].firstedge = n;
        }
    }
	
    if(kind == Undirected) {
        setcolor(WHITE);
        setfillstyle(SOLID_FILL, WHITE);
		
        for(int loop = 0; loop < vertexNum; loop++) {
            int x = undirected_point[random][loop].Point_x;
            int y = undirected_point[random][loop].Point_y;
            fillellipse(x, y, 20, 20);
            setcolor(BLACK);
            outtextxy(x, y, adjlist[loop].vertex);
			
        }
        setcolor(WHITE);
        for(int arc = 0; arc < arcNum; arc++) {
			int tempx=undirected_nodes[random].first[arc];
			int tempy=undirected_nodes[random].second[arc];
			line(undirected_point[random][tempx].Point_x,undirected_point[random][tempx].Point_y,undirected_point[random][tempy].Point_x,undirected_point[random][tempy].Point_y);
		}
		
    } else {
		setcolor(WHITE);
        setfillstyle(SOLID_FILL, WHITE);
		
        for(int loop = 0; loop < vertexNum; loop++) {
            int x = directed_point[random][loop].Point_x;
            int y = directed_point[random][loop].Point_y;
            fillellipse(x, y, 20, 20);
            setcolor(BLACK);
            outtextxy(x, y, adjlist[loop].vertex);
        }
		
        for(int arc = 0; arc < arcNum; arc++) {
			setcolor(WHITE);
			int tempx=directed_nodes[random].first[arc];
			int tempy=directed_nodes[random].second[arc];
			int x1=directed_point[random][tempx].Point_x;
			int y1=directed_point[random][tempx].Point_y;
			int x2=directed_point[random][tempy].Point_x;
			int y2=directed_point[random][tempy].Point_y;
			line(x1,y1,x2,y2);
			//	setfillstyle(SOLID_FILL, BLUE);
			//	fillellipse(0.6*(x2+x1),0.6*(y1+y2),5,5);
		}
	}
	
}

ALGraph::~ALGraph() {
	
}
void ALGraph::draw_undirected_matrix() {
	int horizontal_increment=375/(vertexNum+1);
	int vertical_increment=355/(vertexNum+1);
	setcolor(WHITE);
	for(int i=0;i<vertexNum+2;i++){
		line(260,70+i*vertical_increment,260+(vertexNum+1)*horizontal_increment,70+i*vertical_increment);
		line(260+i*horizontal_increment,70,260+i*horizontal_increment,70+vertical_increment*(vertexNum+1));
	}
	setfont(((int)vertical_increment*0.7), 0, "宋体");
	for(i=0;i<vertexNum;i++){
		outtextxy(263+horizontal_increment*(i+1),73,adjlist[i].vertex);
		outtextxy(263,73+vertical_increment*(i+1),adjlist[i].vertex);
	}
	bool flag=false;
	for(i=0;i<vertexNum;i++){
		for(int j=0;j<vertexNum;j++){
			
			for(int k=0;k<arcNum;k++){
				if(i==undirected_nodes[random].first[k]&&j==undirected_nodes[random].second[k]){
					outtextxy(263+horizontal_increment*(j+1),73+vertical_increment*(i+1),"1");
					flag=true;break;
				}
			}
			for( k=0;k<arcNum;k++){
				if(i==undirected_nodes[random].second[k]&&j==undirected_nodes[random].first[k]){
					outtextxy(263+horizontal_increment*(j+1),73+vertical_increment*(i+1),"1");
					flag=true;break;
				}
			}
			if(!flag){
				outtextxy(263+horizontal_increment*(j+1),73+vertical_increment*(i+1),"0");
			}
			flag=false;
		}
		
	}	
}
void ALGraph::draw_directed_matrix() {
	//	xyprintf(0,60,"random=%d",random);
	int horizontal_increment=375/(vertexNum+1);
	int vertical_increment=355/(vertexNum+1);
	setcolor(WHITE);
	for(int i=0;i<vertexNum+2;i++){
		line(260,70+i*vertical_increment,260+(vertexNum+1)*horizontal_increment,70+i*vertical_increment);
		line(260+i*horizontal_increment,70,260+i*horizontal_increment,70+vertical_increment*(vertexNum+1));
	}/////
	setfont(((int)vertical_increment*0.7), 0, "宋体");
	for(i=0;i<vertexNum;i++){
		outtextxy(263+horizontal_increment*(i+1),73,adjlist[i].vertex);
		outtextxy(263,73+vertical_increment*(i+1),adjlist[i].vertex);
	}
	bool flag=false;
	for(i=0;i<vertexNum;i++){
		for(int j=0;j<vertexNum;j++){
			
			for(int k=0;k<arcNum;k++){
				if(i==directed_nodes[random].first[k]&&j==directed_nodes[random].second[k]){
					outtextxy(263+horizontal_increment*(j+1),73+vertical_increment*(i+1),"1");
					flag=true;break;
				}
			}
			
			if(!flag){
				outtextxy(263+horizontal_increment*(j+1),73+vertical_increment*(i+1),"0");
			}
			flag=false;
		}
		
	}
}
void ALGraph::draw_undirected_link() {
	int horizontal_increment=375/(vertexNum*3);
	int vertical_increment=355/(vertexNum+1);
	outtextxy(260,35,"vertex");
	outtextxy(260+horizontal_increment,50,"firstedge");
	setfont(((int)vertical_increment*0.7), 0, "宋体");
	setcolor(WHITE);
	for(int i=0;i<vertexNum+1;i++){
		line(260,70+i*vertical_increment,260+2*horizontal_increment,70+i*vertical_increment);
	}
	line(260,70,260,70+vertexNum*vertical_increment);
	line(260+horizontal_increment,70,260+horizontal_increment,70+vertexNum*vertical_increment);
	line(260+2*horizontal_increment,70,260+2*horizontal_increment,70+vertexNum*vertical_increment);
	
	for(i=0;i<vertexNum;i++){
		outtextxy(263,73+i*vertical_increment,adjlist[i].vertex);
		ArcNode *node=adjlist[i].firstedge;
		int j=0;
		while(node!=NULL){
			outtextxy(263+3*(j+1)*horizontal_increment,73+i*vertical_increment,adjlist[node->adjvex].vertex);
			rectangle(263+3*(j+1)*horizontal_increment,73+i*vertical_increment,263+(3*j+5)*horizontal_increment,73+(i+1)*vertical_increment-5);
			line(263+(3*j+4)*horizontal_increment,73+i*vertical_increment,263+(3*j+4)*horizontal_increment,73+(i+1)*vertical_increment-5);
			node=node->next;
			j++;
		}
		for(int k=0;k<j;k++){
			line(263+(3*k+1.5)*horizontal_increment,73+i*vertical_increment+0.5*vertical_increment,263+3*(k+1)*horizontal_increment,73+i*vertical_increment+0.5*vertical_increment);
		}
	}
	
	
}
void ALGraph::draw_directed_link() {
	int horizontal_increment=375/(vertexNum*3);
	int vertical_increment=355/(vertexNum+1);
	outtextxy(260,35,"vertex");
	outtextxy(260+horizontal_increment,50,"firstedge");
	setfont(((int)vertical_increment*0.7), 0, "宋体");
	setcolor(WHITE);
	for(int i=0;i<vertexNum+1;i++){
		line(260,70+i*vertical_increment,260+2*horizontal_increment,70+i*vertical_increment);
	}
	line(260,70,260,70+vertexNum*vertical_increment);
	line(260+horizontal_increment,70,260+horizontal_increment,70+vertexNum*vertical_increment);
	line(260+2*horizontal_increment,70,260+2*horizontal_increment,70+vertexNum*vertical_increment);
	
	for(i=0;i<vertexNum;i++){
		outtextxy(263,73+i*vertical_increment,adjlist[i].vertex);
		ArcNode *node=adjlist[i].firstedge;
		int j=0;
		while(node!=NULL){
			outtextxy(263+3*(j+1)*horizontal_increment,73+i*vertical_increment,adjlist[node->adjvex].vertex);
			rectangle(263+3*(j+1)*horizontal_increment,73+i*vertical_increment,263+(3*j+5)*horizontal_increment,73+(i+1)*vertical_increment-5);
			line(263+(3*j+4)*horizontal_increment,73+i*vertical_increment,263+(3*j+4)*horizontal_increment,73+(i+1)*vertical_increment-5);
			node=node->next;
			j++;
		}
		for(int k=0;k<j;k++){
			line(263+(3*k+1.5)*horizontal_increment,73+i*vertical_increment+0.5*vertical_increment,263+3*(k+1)*horizontal_increment,73+i*vertical_increment+0.5*vertical_increment);
		}
	}
}
void ALGraph::draw_undirected_inverse_link() {
	//The same to draw_undirected_link,Because an undirected graph has no distinction between an in - degree and an out - degree
}
void ALGraph::draw_directed_inverse_link(ALGraph &B) {
	B.vertexNum=vertexNum;
	B.arcNum=arcNum;
	for(int i = 0; i < vertexNum; i++) {
        B.adjlist[i].vertex = char(65 + i);
        B.adjlist[i].firstedge = NULL;
    }
	
    for(i = 0; i < arcNum; i++) {
		
		int a = directed_nodes[random].first[i];
		int b = directed_nodes[random].second[i];
		ArcNode* s = new ArcNode;
		s->adjvex = a;
		s->next = B.adjlist[b].firstedge;
		B.adjlist[b].firstedge = s;
		
    }
	B.draw_directed_link();
	/*	int i,k;
	ArcNode *p1,*p2;
	B.vertexNum=A.vertexNum;
	B.arcNum=A.arcNum;
	for(i=0;i<A.vertexNum;i++){
	//	scanf("%c",&B.vertices[i].data);
	B.adjlist[i].vertex = char(65 + i);
	B.adjlist[i].firstedge=NULL;
	} 
	for(i=0;i<A.arcNum;i++){
	p1=A.adjlist[i].firstedge;
	xyprintf(150,200+60*i,"%d",p1->adjvex);
	while(p1){
	k=p1->adjvex;
	p2=new ArcNode;
	p2->adjvex=i;
	p2->next=B.adjlist[k].firstedge;
	B.adjlist[k].firstedge=p2;
	p1=p1->next;
	}
	}
	*/
	
}
void ALGraph::draw_undirected_dfs(int v){
	setcolor(WHITE);
	the_number_of_stack++;
	outtextxy(260+(the_number_of_stack-1)*stack_horizontal_increment,440,adjlist[v].vertex);
	int copy_value=the_number_of_stack-1;
	temp_verchars[copy_value]=adjlist[v].vertex;
	for(int i=0;i<the_number_of_stack;i++){
		rectangle(260+2*(the_number_of_stack-1)*stack_horizontal_increment,370-stack_vertical_increment*(1+i),260+(2*the_number_of_stack-1)*stack_horizontal_increment,370-stack_vertical_increment*i);
		outtextxy(265+2*(the_number_of_stack-1)*stack_horizontal_increment,375-stack_vertical_increment*(1+i),temp_verchars[i]);
	}
	ArcNode* p=adjlist[v].firstedge;
	node_visited[v]=true;
	while(p!=NULL){
		if(node_visited[p->adjvex]==false)
			draw_undirected_dfs(p->adjvex);
		p=p->next;
	}
}
void ALGraph::draw_undirected_bfs(int v){
	setcolor(WHITE);
	int front=-1;
	int rear=-1;
	the_number_of_stack++;
	setfont((int)stack_vertical_increment*1.5, 0, "宋体");
	outtextxy(260+(the_number_of_stack-1)*stack_horizontal_increment,440,adjlist[v].vertex);
	node_visited[v]=true;
	int Q[MaxSize];
	Q[++rear]=v;
	ArcNode* p;
	int lines=0;
	while(rear!=front){
		v=Q[++front];
		p=adjlist[v].firstedge;
		while(p!=NULL){
			int j=p->adjvex;
			if(node_visited[j]==false){
				the_number_of_stack++;
				outtextxy(260+(the_number_of_stack-1)*stack_horizontal_increment,440,adjlist[j].vertex);
				node_visited[j]=true;
				Q[++rear]=j;
			}
			p=p->next;
		}
		lines++;
	}
	for(int j=0;j<vertexNum;j++){
		setcolor(WHITE);
		for(int i=0;i<vertexNum+1;i++){
			setfont((int)stack_vertical_increment, 0, "宋体");
			xyprintf(260+i*stack_horizontal_increment+0.5*stack_horizontal_increment,90+j*5*stack_vertical_increment,"%d",i-1);
			setfont(((int)stack_vertical_increment*0.5), 0, "宋体");
			rectangle(260+i*stack_horizontal_increment,90+j*5*stack_vertical_increment+stack_vertical_increment,260+i*stack_horizontal_increment+stack_horizontal_increment,90+j*5*stack_vertical_increment+stack_vertical_increment+2*stack_vertical_increment);
			
		}
		setfont((int)stack_vertical_increment, 0, "宋体");
		for(int k=0;k<j+1;k++){
			outtextxy(260+1.5*stack_horizontal_increment+k*stack_horizontal_increment,93+stack_vertical_increment+5*j*stack_vertical_increment,adjlist[k].vertex);
		}
		setcolor(GREEN);
		//front
		line(260+(j+0.5)*stack_horizontal_increment,90+1.5*stack_vertical_increment+5*j*stack_vertical_increment,260+(j+0.5)*stack_horizontal_increment,90+4*stack_vertical_increment+5*j*stack_vertical_increment);
		outtextxy(260+(j+0.5)*stack_horizontal_increment,90+4*stack_vertical_increment+5*j*stack_vertical_increment,"front");
		//rear
		line(260+(j+1.5)*stack_horizontal_increment,90+1.5*stack_vertical_increment+5*j*stack_vertical_increment,260+(j+1.5)*stack_horizontal_increment,90+4*stack_vertical_increment+5*j*stack_vertical_increment);
		outtextxy(260+(j+1.5)*stack_horizontal_increment,90+4*stack_vertical_increment+5*j*stack_vertical_increment,"rear");
	}
	
}
void ALGraph::draw_directed_dfs(int v){
	the_number_of_stack++;
	outtextxy(260+(the_number_of_stack-1)*stack_horizontal_increment,440,adjlist[v].vertex);
	int copy_value=the_number_of_stack-1;
	temp_verchars[copy_value]=adjlist[v].vertex;
	for(int i=0;i<the_number_of_stack;i++){
		rectangle(260+2*(the_number_of_stack-1)*stack_horizontal_increment,370-stack_vertical_increment*(1+i),260+(2*the_number_of_stack-1)*stack_horizontal_increment,370-stack_vertical_increment*i);
		outtextxy(265+2*(the_number_of_stack-1)*stack_horizontal_increment,375-stack_vertical_increment*(1+i),temp_verchars[i]);
	}
	ArcNode* p=adjlist[v].firstedge;
	node_visited[v]=true;
	while(p!=NULL){
		if(node_visited[p->adjvex]==false)
			draw_directed_dfs(p->adjvex);
		p=p->next;
	}
}
void ALGraph::draw_directed_bfs(int v){
	int front=-1;
	int rear=-1;
	the_number_of_stack++;
	setfont((int)stack_vertical_increment*1.5, 0, "宋体");
	setcolor(WHITE);
	outtextxy(260+(the_number_of_stack-1)*stack_horizontal_increment,440,adjlist[v].vertex);
	node_visited[v]=true;
	int Q[MaxSize];
	Q[++rear]=v;
	ArcNode* p;
	int lines=0;
	while(rear!=front){
		v=Q[++front];
		p=adjlist[v].firstedge;
		while(p!=NULL){
			int j=p->adjvex;
			if(node_visited[j]==false){
				the_number_of_stack++;
				outtextxy(260+(the_number_of_stack-1)*stack_horizontal_increment,440,adjlist[j].vertex);
				node_visited[j]=true;
				Q[++rear]=j;
			}
			p=p->next;
		}
		lines++;
	}
	for(int j=0;j<vertexNum;j++){
		setcolor(WHITE);
		for(int i=0;i<vertexNum+1;i++){
			setfont((int)stack_vertical_increment, 0, "宋体");
			xyprintf(260+i*stack_horizontal_increment+0.5*stack_horizontal_increment,90+j*5*stack_vertical_increment,"%d",i-1);
			setfont(((int)stack_vertical_increment*0.5), 0, "宋体");
			rectangle(260+i*stack_horizontal_increment,90+j*5*stack_vertical_increment+stack_vertical_increment,260+i*stack_horizontal_increment+stack_horizontal_increment,90+j*5*stack_vertical_increment+stack_vertical_increment+2*stack_vertical_increment);
			
		}
		setfont((int)stack_vertical_increment, 0, "宋体");
		for(int k=0;k<j+1;k++){
			outtextxy(260+1.5*stack_horizontal_increment+k*stack_horizontal_increment,93+stack_vertical_increment+5*j*stack_vertical_increment,adjlist[k].vertex);
		}
		setcolor(GREEN);
		//front
		line(260+(j+0.5)*stack_horizontal_increment,90+1.5*stack_vertical_increment+5*j*stack_vertical_increment,260+(j+0.5)*stack_horizontal_increment,90+4*stack_vertical_increment+5*j*stack_vertical_increment);
		outtextxy(260+(j+0.5)*stack_horizontal_increment,90+4*stack_vertical_increment+5*j*stack_vertical_increment,"front");
		//rear
		line(260+(j+1.5)*stack_horizontal_increment,90+1.5*stack_vertical_increment+5*j*stack_vertical_increment,260+(j+1.5)*stack_horizontal_increment,90+4*stack_vertical_increment+5*j*stack_vertical_increment);
		outtextxy(260+(j+1.5)*stack_horizontal_increment,90+4*stack_vertical_increment+5*j*stack_vertical_increment,"rear");
	}
}


int ALGraph::get_vertexNum(){
	
	return vertexNum;
}
int ALGraph::get_arcNum(){
	return arcNum;
}

//prim

MatrixPrim::MatrixPrim(){
	srand((unsigned)time(NULL));
	Matrixrandom = rand() % 3;
	//	xyprintf(150,50,"random=%d",Matrixrandom);
	vertexnum=undirected_prim_nodes[Matrixrandom].vernums;
    arcnum=undirected_prim_nodes[Matrixrandom].arcnums;
    for(int i=0; i<vertexnum; i++) {
		vexs[i]=char(65 + i);
        for(int j=0; j<vertexnum; j++) {
            arc[i][j].adjvex=999;
        }
    }
	setcolor(WHITE);
    for( i=0; i<arcnum; i++) {
        int a,b,w;
        a=undirected_prim_nodes[Matrixrandom].first[i];
		b=undirected_prim_nodes[Matrixrandom].second[i];
		w=undirected_prim_nodes[Matrixrandom].weight[i];
        arc[a][b].adjvex=w;
        arc[b][a].adjvex=w;
		int tempx=undirected_prim_nodes[Matrixrandom].first[i];
		int tempy=undirected_prim_nodes[Matrixrandom].second[i];
		line(undirected_prim_nodes_point[Matrixrandom][tempx].Point_x,undirected_prim_nodes_point[Matrixrandom][tempx].Point_y,undirected_prim_nodes_point[Matrixrandom][tempy].Point_x,undirected_prim_nodes_point[Matrixrandom][tempy].Point_y);
		int x=0.5*(undirected_prim_nodes_point[Matrixrandom][tempx].Point_x+undirected_prim_nodes_point[Matrixrandom][tempy].Point_x);
		int y=0.5*(undirected_prim_nodes_point[Matrixrandom][tempx].Point_y+undirected_prim_nodes_point[Matrixrandom][tempy].Point_y);
		xyprintf(x,y,"%d",w);
    }
	
	setcolor(WHITE);
	setfillstyle(SOLID_FILL, WHITE);
	
	
	for(int loop = 0; loop < vertexnum; loop++) {
		int x = undirected_prim_nodes_point[Matrixrandom][loop].Point_x;
		int y = undirected_prim_nodes_point[Matrixrandom][loop].Point_y;
		fillellipse(x, y, 20, 20);
		setcolor(BLACK);
		outtextxy(x, y, vexs[loop]);
		
	}
	
}
void MatrixPrim::init(int v){
	for(int i=0; i<vertexnum; i++) {
        if(i!=v) {
            shortEdge[i].adjvex=v;
            shortEdge[i].lowcost=arc[v][i].adjvex;
        }
    }
}
int MatrixPrim::MinEdge(){
	int min=999;
    int min_i=-1;
    for(int i=0; i<vertexnum; i++) {
        if(shortEdge[i].lowcost>0&&shortEdge[i].lowcost<min) {
            min=shortEdge[i].lowcost;
            min_i=i;
        }
		
    }
    return min_i;
}
void MatrixPrim::Prim(int v){
	
	horizontal=406/(vertexnum+1);
	vertical=395/(2*vertexnum);
	shortEdge[v].lowcost=0;
    for(int i=0; i<vertexnum-1; i++) {
        int k=MinEdge();
		int tempx1=280+1.4*horizontal+k*horizontal;
		int tempx2=280+1.4*horizontal+k*horizontal;
		int tempy1=60+2*vertical+i*2*vertical+2;
		int tempy2=60+3*vertical+i*2*vertical;
		//	setcolor(GREEN);
		setcolor(WHITE);
		xyprintf(tempx1,tempy1,"%d",shortEdge[k].adjvex);
		xyprintf(tempx2,tempy2,"%d",shortEdge[k].lowcost);
		shortedges[i]=shortEdge[k].lowcost;
        shortEdge[k].lowcost=0;
        for(int j=0; j<vertexnum; j++) {
            if(i!=k) {
                if(shortEdge[j].lowcost>arc[k][j].adjvex) {
                    shortEdge[j].lowcost=arc[k][j].adjvex;
                    shortEdge[j].adjvex=k;
                }
            }
        }
    }
}

void MatrixPrim::draw_prim(){
	
	setcolor(WHITE);
	line(280,60,280+horizontal,60+2*vertical);
	outtextxy(280+0.3*horizontal,60,"vs");
	outtextxy(280,60+vertical,"se");
	for(int i=0;i<vertexnum+1;i++){
		line(280,60+2*i*vertical,686,60+2*i*vertical);
		
	}
	for( i=0;i<vertexnum+2;i++){
		line(280+i*horizontal,60,280+i*horizontal,443);
		
	}
	for(i=0;i<vertexnum;i++){
		outtextxy(280+(1.5+i)*horizontal,60+vertical,vexs[i]);
	}
	for(i=0;i<vertexnum-1;i++){
		outtextxy(280,60+2*vertical+2*i*vertical,"adjvex");
		outtextxy(280,60+3*vertical+2*i*vertical,"lowcost");
	}
}

void MatrixPrim::bubble_sort(){
	
	int temp;
	for(int i=0;i<vertexnum-2;i++){
		for(int j=0;j<vertexnum-2-i;j++){
			if(shortedges[j]>shortedges[j+1]){
				temp=shortedges[j+1];
				shortedges[j+1]=shortedges[j];
				shortedges[j]=temp;
			}
		}
	}
	setcolor(WHITE);
	/*	for(i=0;i<vertexnum-1;i++){
	xyprintf(400+i*20,520,"%d",shortedges[i]);
}*/
	
}

void MatrixPrim::Lagrange_binary_search(int num){	//after bubble_sort
	//拉格朗日排序算法
	setcolor(WHITE);
	int tou = 0;
	int wei = vertexnum - 2;
	int zhong;
	int flag = -1;//一开始找不到
	int  ci = 0;
	zhong = tou + (wei - tou) *1.0*(num - shortedges[tou]) / (shortedges[wei] - shortedges[tou]);
	if(zhong<0||zhong>(vertexnum-1))
	{
		xyprintf(30,510,"This edge is not in the minimum spanning tree.Total number of searches:%d",ci);
	}
	else{
		while (tou <= wei)
		{
			ci++;
			
			if (num == shortedges[zhong])
			{
				xyprintf(30,510,"This edge is in the minimum spanning tree.Total number of searches:%d",ci);
				flag = 1;//找到
				break;
			}
			else if (num > shortedges[zhong])
			{
				tou = zhong + 1;
			}
			else
			{
				wei = zhong - 1;
			}
			zhong = tou + (wei - tou) *1.0*(num - shortedges[tou]) / (shortedges[wei] - shortedges[tou]);
			
		}
		
		if (-1 == flag)
		{
			xyprintf(30,510,"This edge is not in the minimum spanning tree.Total number of searches:%d",ci);
		}
	}
}