#include"E:\QG训练营第三次培训\代码和头文件\AQueue\AQueue.h"
#include<stdio.h>
#include<stdlib.h>
#include<stddef.h>

/**************************************************************
 *    Prototype Declare Section
 **************************************************************/

/**
 *  @name        : void InitAQueue(AQueue *Q)
 *    @description : 初始化队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void InitAQueue(AQueue *Q)
{
    int i;
	Q->length = MAXQUEUE;
    for(i = 0; i < MAXQUEUE; i++)//不知道用户想放入的数据类型大小，所以给个20
        Q->data[i] = (void *)malloc(21);
	Q->front = Q->rear = 0;
	printf("—初始化成功！\n");
}

/**
 *  @name        : void DestoryAQueue(AQueue *Q)
 *    @description : 销毁队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void DestoryAQueue(AQueue *Q)
{	
	int i;
	if(Q->data[0] == NULL){
		printf("—队列尚未初始化！\n");
		return ; 
	}
	else{
		for(i = 0;i<MAXQUEUE;i++)
		free(Q->data[i]);
		Q->data[0] = NULL;
		printf("—队列销毁成功！\n");
		return;
	}
} 



/**
 *  @name        : Status IsFullAQueue(const AQueue *Q)
 *    @description : 检查队列是否已满
 *    @param         Q 队列指针Q
 *    @return         : 满-TRUE; 未满-FALSE
 *  @notice      : None
 */
Status IsFullAQueue(const AQueue *Q)
{
	if(LengthAQueue(Q)==MAXQUEUE-1)
		return 0;
	else
		return 1; 	
}

/**
 *  @name        : Status IsEmptyAQueue(const AQueue *Q)
 *    @description : 检查队列是否为空
 *    @param         Q 队列指针Q
 *    @return         : 空-TRUE; 未空-FALSE
 *  @notice      : None
 */
Status IsEmptyAQueue(const AQueue *Q){
	if(LengthAQueue(Q)==0)
		return 0;
	else
		return 1;
} 



/**
 *  @name        : Status GetHeadAQueue(AQueue *Q, void *e)
 *    @description : 查看队头元素
 *    @param         Q 队列指针Q，存放元素e
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否空
 */
Status GetHeadAQueue(AQueue *Q, void *e){
	if(Q->data[0]==NULL){
		printf("—队列未初始化！\n");
		return 0;
	}
	
	if(!IsEmptyAQueue(Q)){
		printf("—队列为空，无法获取队头元素！\n");
		return 0;
	}
	printf("—队头元素为："); 
	APrint(Q->data[Q->front],datatype[Q->front]);
	printf("\n");
	return 1;		
}		

/**
 *  @name        : int LengthAQueue(AQueue *Q)
 *    @description : 确定队列长度
 *    @param         Q 队列指针Q
 *    @return         : 队列长度count
 *  @notice      : None
 */
int LengthAQueue(AQueue *Q)
{	
	if(Q->data[0] == NULL){
		printf("—队列尚未初始化！\n");
		return 0;
    }
	int length;
	length=(Q->rear-Q->front+Q->length)%Q->length;
	return length;
}	



/**
 *  @name        : Status EnAQueue(AQueue *Q, void *data)
 *    @description : 入队操作
 *    @param         Q 队列指针Q,入队数据指针data
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否满了或为空
 */
Status EnAQueue(AQueue *Q, void *data){  
	memcpy(Q->data[Q->rear],data,20);
	Q->rear=(Q->rear+1)%Q->length;
	printf("—入队成功！\n");
	return 1; 
} 



/**
 *  @name        : Status DeAQueue(AQueue *Q)
 *    @description : 出队操作
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
Status DeAQueue(AQueue *Q){
	if(Q->data[0] == NULL){
		printf("—队列尚未初始化！\n");
		return 0;
    }
	if(!IsEmptyAQueue(Q)){
		printf("—队列为空，无法出队！\n");
		return 0;
	}
	Q->front=(Q->front+1)%Q->length;
	printf("—出队成功！\n");
	return 1;
}	



/**
 *  @name        : void ClearAQueue(Queue *Q)
 *    @description : 清空队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void ClearAQueue(AQueue *Q){
	if(Q->data[0] == NULL){
		printf("—队列尚未初始化！\n");
		return 0;
    }
    Q->front=Q->rear=0;
	printf("—队列已清空！\n");
	return ;
}	



/**
 *  @name        : Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q))
 *    @description : 遍历函数操作
 *    @param         Q 队列指针Q，操作函数指针foo
 *    @return         : None
 *  @notice      : None
 */
Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q,char datatype)){
	int i=0;
	if(Q->data[0]==NULL){
		printf("—队列未初始化！\n");
		return 0;
	}
	if(!IsEmptyAQueue(Q)){
		printf("队列为空！\n");
		return 0;
	}

	while(i<(Q->length-Q->front+Q->rear)%Q->length){
		foo(Q->data[Q->front+i],datatype[Q->front+i]);
		printf("-->");
		i=(i+1)%Q->length;
	}
	printf("NULL\n");
	return 1;
}



/**
 *  @name        : void APrint(void *q)
 *    @description : 操作函数
 *    @param         q 指针q
 *  @notice      : None
 */
void APrint(void *q,char datatype){
	if(datatype==DOUBLE)
		printf("%.2lf",*(double*)q);
	if(datatype==CHAR)
		printf("%c",*(char*)q);
	if(datatype==INT)
		printf("%d",*(int*)q);
	if(datatype==STRING)
		printf("%s",(char*)q);	
}
void Choose(AQueue *Q){
	int t;
	if(Q->data[0]==NULL){
		printf("—队列未初始化！\n");
		return 0;
	}
	if(!IsFullAQueue(Q)){
    	printf("—队列已满，无法入队！\n");
    	return 0;
	}
	printf("* 你想入队哪种类型？\n");
	printf("1.整型    2.浮点型（精确到小数点后两位）    3.字符型    4.字符串\n");
	printf("* 请选择："); 
	scanf("%d",&t);	
	while(t<1||t>4){
		printf("* 请输入1-4之间的整数！\n");
		printf("* 请重输：");
		fflush(stdin);
		scanf("%d",&t); 
	} 
	fflush(stdin);
	if(t==1||t==2)
	printf("—数据绝对值最大不超过1亿哦！\n");
	printf("* 入队数据：");

	switch(t)
	{
		case INT:{
			int a;
			while((scanf("%d",&a))!=1||a>100000000||a<-100000000)
		 {  
		 	printf("—输入格式错误或超出范围!\n请重输：");
		 	fflush(stdin);
		  } 
			datatype[Q->rear]=t;
			EnAQueue(Q,&a);
			break;
		}
		
		case DOUBLE:{
			double a;
			while(!(scanf("%lf",&a))||a>100000000||a<-100000000){
				printf("—输入格式错误或超出范围!\n请重输："); 
				fflush(stdin); 
			}
			datatype[Q->rear]=t;
			EnAQueue(Q, &a);
			break;
		}
		case CHAR:{
			char a;
			while(!(scanf("%c",&a))){
				printf("输入格式错误！请重输：");
				fflush(stdin);
			}
			datatype[Q->rear]=t;
			EnAQueue(Q, &a);
			break;
		}
		case STRING:{
			char a[20];
			printf("\n—最大长度为20！\n");
			while(!(scanf("%s",&a))){
				printf("—输入格式错误！请重输：");
				fflush(stdin); 
			}
			datatype[Q->rear]=t;
			EnAQueue(Q, &a);
			break;
		}
	}
	fflush(stdin);
	return ;
}

/**************************************************************
 *    End-Multi-Include-Prevent Section
 **************************************************************/



