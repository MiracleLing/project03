#include "E:\QGѵ��Ӫ��������ѵ\�����ͷ�ļ�\AQueue\AQueue.h"
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
    printf("                 ***************************************�����˵�**********************************\n");
    printf("                 *                                   1.��ʼ������                     	         *\n");
    printf("                 *                                   2.���                                      *\n");
    printf("                 *                                   3.����                                      *\n");
    printf("                 *                                   4.��ȡ��ͷԪ��                              *\n");
    printf("                 *                                   5.�������г���                              *\n");
    printf("                 *                                   6.�ж϶���Ϊ��                              *\n");
    printf("                 *                                   7.�ж϶���Ϊ��                              *\n");
    printf("                 *                                   8.��������                                  *\n");
	printf("                 *                                   9.��ն���                                  *\n");
    printf("                 *                                   10.���ٶ���                                 *\n");
    printf("                 *                                   11.�˳�����                                 *\n");
    printf("                 *********************************************************************************\n"); 
    while(order!=11)
	{
	printf("\n��������ȷָ�");//����ָ����ת����Ӧ���� 
    while(!scanf("%d",&order)) {
    	printf("�������ʽ����\n�������䣺");
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
			printf("�����г���Ϊ:%d\n",length);
		break;} 
	case 6:{
		if(!Q->data[0]){
			printf("������δ��ʼ����\n");
			break;
		}
		if(IsEmptyAQueue(Q))
			printf("�����в�Ϊ�գ�\n");
		else
			printf("������Ϊ�գ�\n");
		break;
	} 
	case 7:{
		if(!Q->data[0]){
			printf("������δ��ʼ����\n");
			break;
		}
		if(IsFullAQueue(Q))
			printf("������δ����\n");
		else
			printf("������������\n");
		break;
	}
	case 8:TraverseAQueue(Q, (*APrint));break;
	case 9:ClearAQueue(Q);break;
	case 10:DestoryAQueue(Q);break;
	case 11:;break;
	default:getchar();printf("δ�ҵ���ָ�\n");fflush(stdin);break; 
	}
	}	
	printf("\n* ��л����ʹ�ã� *\n");
	 
}
