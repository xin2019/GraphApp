
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
		//�������壬��һ������������ĸ߶ȣ����أ����ڶ�������������Ŀ�ȣ��ڶ����������Ϊ0����ʹ��Ĭ�ϱ���ֵ
		//����߶�Ϊ12�����൱��С����֣�����9����
		setfont(24, 0, "����");
		
		
		//�������ֱ�����䷽ʽΪ͸����Ĭ��ΪOPAQUE��͸��
		setbkmode(TRANSPARENT);
		outtextxy(190, 50, "ͼ�Ŀ�����ʾϵͳ");
		
		line(100,120,500,120);
		
		setfont(20, 0, "����");
		
		outtextxy(30, 170, "ͼ�Ĵ洢��ʾ");
		
		
		
		
		//
		outtextxy(180, 170, "ͼ�ı�����ʾ");
		//
		outtextxy(330, 170, "��С��������ʾ");
		//
		outtextxy(500, 170, "���·����ʾ");
		
		
		setcolor(GREEN);
		
		setfont(18, 0, "����");
		
		outtextxy(30, 250, "�ڽӾ���洢");
		
		outtextxy(30, 330, "�ڽ�����洢");
		
		outtextxy(180, 250, "ͼ����ȱ���");
		
		outtextxy(180, 330, "ͼ�Ĺ�ȱ���");
		
		outtextxy(330, 250, "��³˹����");
		
		outtextxy(330, 330, "����ķ");
		
		outtextxy(500, 250, "�ؽ�˹����");
		
		setcolor(WHITE);
		
		outtextxy(550, 400, "�˳�");
		}

		
	}
	
	

	
	//	getch();
	//	closegraph();
	
}

