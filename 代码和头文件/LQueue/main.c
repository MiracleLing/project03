#include<stdio.h>
#include<stdlib.h>
#include<stddef.h> 
#include <string.h>
#include"E:\QGѵ��Ӫ��������ѵ\�����ͷ�ļ�\LQueue\LQueue.h"
int main(){
	LQueue *Q;
	int length,order=0;
	void *e;
	e=(void*)malloc(21);
	Q=(LQueue *)malloc(sizeof(LQueue));
	Q->front=Q->rear=NULL;
	printf("----------------------------------------------------------------------------------------------------------------------\n");
    printf("                 ***************************************�����˵�**********************************\n");
    printf("                 *                                   1.��ʼ������                     	         *\n");
    printf("                 *                                   2.���                                      *\n");
    printf("                 *                                   3.����                                      *\n");
    printf("                 *                                   4.��ȡ��ͷԪ��                              *\n");
    printf("                 *                                   5.�������г���                              *\n");
    printf("                 *                                   6.�ж϶���Ϊ��                              *\n");
    printf("                 *                                   7.��������                                  *\n");
	printf("                 *                                   8.��ն���                                  *\n");
    printf("                 *                                   9.���ٶ���                                  *\n");
    printf("                 *                                   10.�˳�����                                 *\n");
    printf("                 *********************************************************************************\n"); 
    while(order!=10)
	{
	printf("\n* ��������ȷָ�");//����ָ����ת����Ӧ���� 
    while(!scanf("%d",&order)){
		printf("�������ʽ����\n* �����䣺");
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
			printf("�����г���Ϊ:%d\n",length);
		break;} 
	case 6:{
		if(!Q->front){
			printf("������δ��ʼ����\n");
			break;
		}
		if(IsEmptyLQueue(Q))
			printf("�����в�Ϊ�գ�\n");
		else
			printf("������Ϊ�գ�\n");
		break;}
	case 7:TraverseLQueue(Q, (*LPrint));break;
	case 8:{
	if(Q->front==NULL){
		printf("������δ��ʼ����\n");
		break;	
	}
		if(!IsEmptyLQueue(Q)){
		printf("����������գ�\n");
		break;
	}	
	ClearLQueue(Q);
	printf("��������ճɹ���\n");
		break;
	}
	case 9:{
		DestoryLQueue(Q);
		break;
	}
	case 10:;break;
	default:getchar();printf("δ�ҵ���ָ�\n");fflush(stdin);break; 
	}
	}	
	printf("\n* ��л����ʹ�ã� *\n");
	return 0;
}
