
#include<graphics.h>

#include"main_interface.h"
#include"graph_save.h"

void show_main(void){
	
	initgraph(720,540);
	
    mouse_msg msg = {0};
	
	
	for(; is_run(); delay_fps(60))
	{
		
		while (mousemsg())
		{
			msg = getmouse();
		}
		cleardevice();
	//	xyprintf(0, 0, "x = %10d  y = %10d",
	//		msg.x, msg.y, msg.wheel);
		
		bool isleft=msg.is_left();
		bool showmain=true;
		if(msg.x>550&&msg.x<584&&msg.y>400&&msg.y<411&&(isleft==true)){
		closegraph();
		}
		else if(msg.x>30&&msg.x<147&&msg.y>168&&msg.y<185&&(isleft==true)){
		
			closegraph();
		graph_save();
		}
		
		if(showmain){
		//设置字体，第一个参数是字体的高度（像素），第二个参数是字体的宽度，第二个参数如果为0，就使用默认比例值
		//如果高度为12，即相当于小五号字，或者9磅字
		setfont(24, 0, "宋体");
		
		
		//设置文字背景填充方式为透明，默认为OPAQUE不透明
		setbkmode(TRANSPARENT);
		outtextxy(190, 50, "图的课堂演示系统");
		
		line(100,120,500,120);
		
		setfont(20, 0, "宋体");
		
		outtextxy(30, 170, "图的存储演示");
		
		
		
		
		//
		outtextxy(180, 170, "图的遍历演示");
		//
		outtextxy(330, 170, "最小生成树演示");
		//
		outtextxy(500, 170, "最短路径演示");
		
		
		setcolor(GREEN);
		
		setfont(18, 0, "宋体");
		
		outtextxy(30, 250, "邻接矩阵存储");
		
		outtextxy(30, 330, "邻接链表存储");
		
		outtextxy(180, 250, "图的深度遍历");
		
		outtextxy(180, 330, "图的广度遍历");
		
		outtextxy(330, 250, "克鲁斯卡尔");
		
		outtextxy(330, 330, "普里姆");
		
		outtextxy(500, 250, "地杰斯特拉");
		
		setcolor(WHITE);
		
		outtextxy(550, 400, "退出");
		}

		
	}
	
	

	
	//	getch();
	//	closegraph();
	
}

