#include "E:\QG训练营第三次培训\代码和头文件\AQueue\AQueue.h"
#include<stdio.h>
#include<stdlib.h>
#include<stddef.h>
int main()
{
	AQueue *Q;
	int length,data,i,order=0;
	void *e;
	Q=(AQueue *)malloc(sizeof(AQueue));
	Q->data[0] = NULL;
	
	printf("----------------------------------------------------------------------------------------------------------------------\n");
    printf("                 ***************************************操作菜单**********************************\n");
    printf("                 *                                   1.初始化队列                     	         *\n");
    printf("                 *                                   2.入队                                      *\n");
    printf("                 *                                   3.出队                                      *\n");
    printf("                 *                                   4.获取队头元素                              *\n");
    printf("                 *                                   5.测量队列长度                              *\n");
    printf("                 *                                   6.判断队列为空                              *\n");
    printf("                 *                                   7.判断队列为满                              *\n");
    printf("                 *                                   8.遍历队列                                  *\n");
	printf("                 *                                   9.清空队列                                  *\n");
    printf("                 *                                   10.销毁队列                                 *\n");
    printf("                 *                                   11.退出程序                                 *\n");
    printf("                 *********************************************************************************\n"); 
    while(order!=11)
	{
	printf("\n请输入正确指令：");//输入指令跳转至对应函数 
    while(!scanf("%d",&order)) {
    	printf("—输入格式错误！\n—请重输：");
		fflush(stdin); 
	}
    switch (order)
	{
	case 1:InitAQueue(Q);break;
	case 2:Choose(Q);break;
	case 3:DeAQueue(Q);break;
	case 4:GetHeadAQueue(Q,e);break;
	case 5:{
		length = LengthAQueue(Q);
		if(Q->data[0]!=NULL)
			printf("—队列长度为:%d\n",length);
		break;} 
	case 6:{
		if(!Q->data[0]){
			printf("—队列未初始化！\n");
			break;
		}
		if(IsEmptyAQueue(Q))
			printf("—队列不为空！\n");
		else
			printf("—队列为空！\n");
		break;
	} 
	case 7:{
		if(!Q->data[0]){
			printf("—队列未初始化！\n");
			break;
		}
		if(IsFullAQueue(Q))
			printf("—队列未满！\n");
		else
			printf("—队列已满！\n");
		break;
	}
	case 8:TraverseAQueue(Q, (*APrint));break;
	case 9:ClearAQueue(Q);break;
	case 10:DestoryAQueue(Q);break;
	case 11:;break;
	default:getchar();printf("未找到该指令！\n");fflush(stdin);break; 
	}
	}	
	printf("\n* 感谢您的使用！ *\n");
	 
}
