#include<stdio.h>
#include<stdlib.h>
#include<stddef.h> 
#include <string.h>
#include"E:\QG训练营第三次培训\代码和头文件\LQueue\LQueue.h"
int main(){
	LQueue *Q;
	int length,order=0;
	void *e;
	e=(void*)malloc(21);
	Q=(LQueue *)malloc(sizeof(LQueue));
	Q->front=Q->rear=NULL;
	printf("----------------------------------------------------------------------------------------------------------------------\n");
    printf("                 ***************************************操作菜单**********************************\n");
    printf("                 *                                   1.初始化队列                     	         *\n");
    printf("                 *                                   2.入队                                      *\n");
    printf("                 *                                   3.出队                                      *\n");
    printf("                 *                                   4.获取队头元素                              *\n");
    printf("                 *                                   5.测量队列长度                              *\n");
    printf("                 *                                   6.判断队列为空                              *\n");
    printf("                 *                                   7.遍历队列                                  *\n");
	printf("                 *                                   8.清空队列                                  *\n");
    printf("                 *                                   9.销毁队列                                  *\n");
    printf("                 *                                   10.退出程序                                 *\n");
    printf("                 *********************************************************************************\n"); 
    while(order!=10)
	{
	printf("\n* 请输入正确指令：");//输入指令跳转至对应函数 
    while(!scanf("%d",&order)){
		printf("—输入格式错误！\n* 请重输：");
		fflush(stdin);	
	}
    switch (order)
	{
	case 1:InitLQueue(Q);break;
	case 2:Choose(Q);break;	
	case 3:DeLQueue(Q);break;
	case 4:GetHeadLQueue(Q,e);break;
	case 5:{
		length = LengthLQueue(Q);
		if(Q->front!=NULL)
			printf("—队列长度为:%d\n",length);
		break;} 
	case 6:{
		if(!Q->front){
			printf("—队列未初始化！\n");
			break;
		}
		if(IsEmptyLQueue(Q))
			printf("—队列不为空！\n");
		else
			printf("—队列为空！\n");
		break;}
	case 7:TraverseLQueue(Q, (*LPrint));break;
	case 8:{
	if(Q->front==NULL){
		printf("—队列未初始化！\n");
		break;	
	}
		if(!IsEmptyLQueue(Q)){
		printf("—队列已清空！\n");
		break;
	}	
	ClearLQueue(Q);
	printf("—队列清空成功！\n");
		break;
	}
	case 9:{
		DestoryLQueue(Q);
		break;
	}
	case 10:;break;
	default:getchar();printf("未找到该指令！\n");fflush(stdin);break; 
	}
	}	
	printf("\n* 感谢您的使用！ *\n");
	return 0;
}
