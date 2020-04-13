#include<stdio.h>
#include<stdlib.h>
#include<stddef.h> 
#include <string.h>
#include"E:\QG训练营第三次培训\代码和头文件\LQueue\LQueue.h"

/**
 *  @name        : void InitLQueue(LQueue *Q)
 *    @description : 初始化队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void InitLQueue(LQueue *Q){
	Node *q;
	q=(Node*)malloc(sizeof(Node));
	q->next=NULL;
	Q->front=Q->rear=q;
	Q->length=0;
	printf("—已初始化队列！\n");
	return;
}

/**
 *  @name        : void DestoryLQueue(LQueue *Q)
 *    @description : 销毁队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void DestoryLQueue(LQueue *Q){

	if(Q->front==NULL){
		printf("—队列未初始化！\n");
		return;
	}
	if(Q->length!=0){
		ClearLQueue(Q);
	}	
	
		Q->front=Q->rear=NULL;
		printf("—队列已销毁！\n");
	return ;
}

/**
 *  @name        : Status IsEmptyLQueue(const LQueue *Q)
 *    @description : 检查队列是否为空
 *    @param         Q 队列指针Q
 *    @return         : 空-TRUE; 未空-FALSE
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
 *    @description : 查看队头元素
 *    @param         Q e 队列指针Q,返回数据指针e
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否空
 */
Status GetHeadLQueue(LQueue *Q,void *e){
	if (!Q->front){
		printf("—队列未初始化！\n");
		return 0;
	}
	if (!IsEmptyLQueue(Q)){
		printf("—队列为空，无法获取队头元素！\n");
		return 0;
	}
	
	memcpy(e,Q->front->next->data,20);
	printf("—队头元素为："); 
	LPrint(e,Q->front->next->datatype);
	printf("\n");
	return 1;	
}

/**
 *  @name        : int LengthLQueue(LQueue *Q)
 *    @description : 确定队列长度
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
int LengthLQueue(LQueue *Q){
	if(!Q->front){
		printf("—队列未初始化！\n");
		return 1;
	}
	return (Q->length);
}

/**
 *  @name        : Status EnLQueue(LQueue *Q, void *data)
 *    @description : 入队操作
 *    @param         Q 队列指针Q,入队数据指针data
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否为空
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
	printf("—入队成功！\n");
	return 1; 	
}

/**
 *  @name        : Status DeLQueue(LQueue *Q)
 *    @description : 出队操作
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
Status DeLQueue(LQueue *Q){
	if(Q->front==Q->rear&&Q->front==NULL){
		printf("—队列未初始化！\n");
		return 0; 
	}
	if(Q->length==0){
		printf("—队列为空，无法出队！\n");
		return 0;
	}
	Node *q;
	q=(Node *)malloc(sizeof(Node));
	q=Q->front->next;
	Q->front->next=q->next;
	Q->length--; 
	free(q);
	printf("—出队成功！\n");
	return 1;
}

/**
 *  @name        : void ClearLQueue(AQueue *Q)
 *    @description : 清空队列
 *    @param         Q 队列指针Q
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
 *    @description : 遍历函数操作
 *    @param         Q 队列指针Q，操作函数指针foo
 *    @return         : None
 *  @notice      : None
 */
Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q,char datatype)){
	if(Q->front==NULL){
		printf("—队列未初始化！\n");
		return 0;
	}
	int i=Q->length;
	Node *q;
	q=(Node*)malloc(sizeof(Node));
	q=Q->front->next;
	
	if(!IsEmptyLQueue(Q)){
		printf("—队列为空！\n");
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
 *    @description : 操作函数
 *    @param         q 指针q
 
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
		printf("—队列未初始化！\n");
		return ;
	}
	printf("* 你想输入什么类型？\n");
	printf("1.整型    2.浮点型（精确到小数点后两位）    3.字符型    4.字符串\n");
	printf("* 请选择：");
	while(!(scanf("%d",&t))||t<1||t>4){
		printf("请输入1-4之间的整数！\n");
		printf("请重输：");
		fflush(stdin); 
	} 
	if(t==1||t==2)
	printf("—数据绝对值最大不超过一亿哦！\n");
	printf("入队数据：");
	fflush(stdin);
	switch(t)
	{
		case INT:{
			int a;
			while(!(scanf("%d",&a))||a>100000000||a<-100000000){
				printf("—输入格式错误或超出范围！\n请重输：");
				fflush(stdin); 
			}
			
			EnLQueue(Q,&a);
			Q->rear->datatype=t;
			break;
		}
		case DOUBLE:{
			double a;
			while(!(scanf("%lf",&a))||a>100000000||a<-100000000){
				printf("—输入格式错误或超出范围！\n请重输：");
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
				printf("—输入格式错误！\n请重输：");
				fflush(stdin);	
			}
			EnLQueue(Q,&a);
			Q->rear->datatype=t;
			break;
		}
		case STRING:{
			char a[20];
			printf("—最大长度不要超过20哦！\n");
			while(!(scanf("%s",&a))){
				printf("—输入格式错误！\n请重输：");
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



