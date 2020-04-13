#include<stdio.h>
#include<stdlib.h>
#include<stddef.h> 
#include <string.h>
#include"E:\QGѵ��Ӫ��������ѵ\�����ͷ�ļ�\LQueue\LQueue.h"

/**
 *  @name        : void InitLQueue(LQueue *Q)
 *    @description : ��ʼ������
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void InitLQueue(LQueue *Q){
	Node *q;
	q=(Node*)malloc(sizeof(Node));
	q->next=NULL;
	Q->front=Q->rear=q;
	Q->length=0;
	printf("���ѳ�ʼ�����У�\n");
	return;
}

/**
 *  @name        : void DestoryLQueue(LQueue *Q)
 *    @description : ���ٶ���
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void DestoryLQueue(LQueue *Q){

	if(Q->front==NULL){
		printf("������δ��ʼ����\n");
		return;
	}
	if(Q->length!=0){
		ClearLQueue(Q);
	}	
	
		Q->front=Q->rear=NULL;
		printf("�����������٣�\n");
	return ;
}

/**
 *  @name        : Status IsEmptyLQueue(const LQueue *Q)
 *    @description : �������Ƿ�Ϊ��
 *    @param         Q ����ָ��Q
 *    @return         : ��-TRUE; δ��-FALSE
 *  @notice      : None
 */
Status IsEmptyLQueue(const LQueue *Q){
	if(Q->length==0)
		return 0;
	else
		return 1;
}

/**
 *  @name        : Status GetHeadLQueue(LQueue *Q, void *e)
 *    @description : �鿴��ͷԪ��
 *    @param         Q e ����ָ��Q,��������ָ��e
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ��
 */
Status GetHeadLQueue(LQueue *Q,void *e){
	if (!Q->front){
		printf("������δ��ʼ����\n");
		return 0;
	}
	if (!IsEmptyLQueue(Q)){
		printf("������Ϊ�գ��޷���ȡ��ͷԪ�أ�\n");
		return 0;
	}
	
	memcpy(e,Q->front->next->data,20);
	printf("����ͷԪ��Ϊ��"); 
	LPrint(e,Q->front->next->datatype);
	printf("\n");
	return 1;	
}

/**
 *  @name        : int LengthLQueue(LQueue *Q)
 *    @description : ȷ�����г���
 *    @param         Q ����ָ��Q
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : None
 */
int LengthLQueue(LQueue *Q){
	if(!Q->front){
		printf("������δ��ʼ����\n");
		return 1;
	}
	return (Q->length);
}

/**
 *  @name        : Status EnLQueue(LQueue *Q, void *data)
 *    @description : ��Ӳ���
 *    @param         Q ����ָ��Q,�������ָ��data
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ�Ϊ��
 */
Status EnLQueue(LQueue *Q, void *data){
	Node *q;
	q=(Node*)malloc(sizeof(Node));
	q->data=(void *)malloc(21);
	
	memcpy(q->data,data,20);
	q->next=NULL;
	Q->rear->next=q;
	Q->rear=q;
	Q->length++;
	printf("����ӳɹ���\n");
	return 1; 	
}

/**
 *  @name        : Status DeLQueue(LQueue *Q)
 *    @description : ���Ӳ���
 *    @param         Q ����ָ��Q
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : None
 */
Status DeLQueue(LQueue *Q){
	if(Q->front==Q->rear&&Q->front==NULL){
		printf("������δ��ʼ����\n");
		return 0; 
	}
	if(Q->length==0){
		printf("������Ϊ�գ��޷����ӣ�\n");
		return 0;
	}
	Node *q;
	q=(Node *)malloc(sizeof(Node));
	q=Q->front->next;
	Q->front->next=q->next;
	Q->length--; 
	free(q);
	printf("�����ӳɹ���\n");
	return 1;
}

/**
 *  @name        : void ClearLQueue(AQueue *Q)
 *    @description : ��ն���
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void ClearLQueue(LQueue *Q){
	Node *p,*q;
	Q->rear=Q->front;
	p=Q->front->next;
	while(p!=NULL){
		q=p;
		p=p->next;
		free(q);
	} 
	free(p);
	Q->length=0;
	return;
}

/**
 *  @name        : Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))
 *    @description : ������������
 *    @param         Q ����ָ��Q����������ָ��foo
 *    @return         : None
 *  @notice      : None
 */
Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q,char datatype)){
	if(Q->front==NULL){
		printf("������δ��ʼ����\n");
		return 0;
	}
	int i=Q->length;
	Node *q;
	q=(Node*)malloc(sizeof(Node));
	q=Q->front->next;
	
	if(!IsEmptyLQueue(Q)){
		printf("������Ϊ�գ�\n");
		return 0;
	}
	while(q!=NULL){
		foo(q->data,q->datatype);
		printf("-->");
		q=q->next;	
	}
	printf("NULL\n");
	return 1;
}

/**
 *  @name        : void LPrint(void *q)
 *    @description : ��������
 *    @param         q ָ��q
 
 *  @notice      : None
 */
void LPrint(void *q,char datatype){
	if(datatype==DOUBLE)
		printf("%.2lf",*(double*)q);
	if(datatype==CHAR)
		printf("%c",*(char*)q);
	if(datatype==INT)
		printf("%d",*(int*)q);
	if(datatype==STRING)
		printf("%s",(char*)q);
}
void Choose(LQueue *Q){
	int t;
	if(Q->front==NULL){
		printf("������δ��ʼ����\n");
		return ;
	}
	printf("* ��������ʲô���ͣ�\n");
	printf("1.����    2.�����ͣ���ȷ��С�������λ��    3.�ַ���    4.�ַ���\n");
	printf("* ��ѡ��");
	while(!(scanf("%d",&t))||t<1||t>4){
		printf("������1-4֮���������\n");
		printf("�����䣺");
		fflush(stdin); 
	} 
	if(t==1||t==2)
	printf("�����ݾ���ֵ��󲻳���һ��Ŷ��\n");
	printf("������ݣ�");
	fflush(stdin);
	switch(t)
	{
		case INT:{
			int a;
			while(!(scanf("%d",&a))||a>100000000||a<-100000000){
				printf("�������ʽ����򳬳���Χ��\n�����䣺");
				fflush(stdin); 
			}
			
			EnLQueue(Q,&a);
			Q->rear->datatype=t;
			break;
		}
		case DOUBLE:{
			double a;
			while(!(scanf("%lf",&a))||a>100000000||a<-100000000){
				printf("�������ʽ����򳬳���Χ��\n�����䣺");
				fflush(stdin);
			}
			
			EnLQueue(Q,&a);
			Q->rear->datatype=t;
			break;
		}
		case CHAR:{
			char a;
			//getchar();
			while(!(scanf("%c",&a))){
				printf("�������ʽ����\n�����䣺");
				fflush(stdin);	
			}
			EnLQueue(Q,&a);
			Q->rear->datatype=t;
			break;
		}
		case STRING:{
			char a[20];
			printf("����󳤶Ȳ�Ҫ����20Ŷ��\n");
			while(!(scanf("%s",&a))){
				printf("�������ʽ����\n�����䣺");
				fflush(stdin);
			}
			EnLQueue(Q,&a);
			Q->rear->datatype=t;
			break;
		}
	}	 
}

/**************************************************************
 *    End-Multi-Include-Prevent Section
 **************************************************************/



