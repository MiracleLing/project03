#include"E:\QGѵ��Ӫ��������ѵ\�����ͷ�ļ�\AQueue\AQueue.h"
#include<stdio.h>
#include<stdlib.h>
#include<stddef.h>

/**************************************************************
 *    Prototype Declare Section
 **************************************************************/

/**
 *  @name        : void InitAQueue(AQueue *Q)
 *    @description : ��ʼ������
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void InitAQueue(AQueue *Q)
{
    int i;
	Q->length = MAXQUEUE;
    for(i = 0; i < MAXQUEUE; i++)//��֪���û��������������ʹ�С�����Ը���20
        Q->data[i] = (void *)malloc(21);
	Q->front = Q->rear = 0;
	printf("����ʼ���ɹ���\n");
}

/**
 *  @name        : void DestoryAQueue(AQueue *Q)
 *    @description : ���ٶ���
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void DestoryAQueue(AQueue *Q)
{	
	int i;
	if(Q->data[0] == NULL){
		printf("��������δ��ʼ����\n");
		return ; 
	}
	else{
		for(i = 0;i<MAXQUEUE;i++)
		free(Q->data[i]);
		Q->data[0] = NULL;
		printf("���������ٳɹ���\n");
		return;
	}
} 



/**
 *  @name        : Status IsFullAQueue(const AQueue *Q)
 *    @description : �������Ƿ�����
 *    @param         Q ����ָ��Q
 *    @return         : ��-TRUE; δ��-FALSE
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
 *    @description : �������Ƿ�Ϊ��
 *    @param         Q ����ָ��Q
 *    @return         : ��-TRUE; δ��-FALSE
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
 *    @description : �鿴��ͷԪ��
 *    @param         Q ����ָ��Q�����Ԫ��e
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ��
 */
Status GetHeadAQueue(AQueue *Q, void *e){
	if(Q->data[0]==NULL){
		printf("������δ��ʼ����\n");
		return 0;
	}
	
	if(!IsEmptyAQueue(Q)){
		printf("������Ϊ�գ��޷���ȡ��ͷԪ�أ�\n");
		return 0;
	}
	printf("����ͷԪ��Ϊ��"); 
	APrint(Q->data[Q->front],datatype[Q->front]);
	printf("\n");
	return 1;		
}		

/**
 *  @name        : int LengthAQueue(AQueue *Q)
 *    @description : ȷ�����г���
 *    @param         Q ����ָ��Q
 *    @return         : ���г���count
 *  @notice      : None
 */
int LengthAQueue(AQueue *Q)
{	
	if(Q->data[0] == NULL){
		printf("��������δ��ʼ����\n");
		return 0;
    }
	int length;
	length=(Q->rear-Q->front+Q->length)%Q->length;
	return length;
}	



/**
 *  @name        : Status EnAQueue(AQueue *Q, void *data)
 *    @description : ��Ӳ���
 *    @param         Q ����ָ��Q,�������ָ��data
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ����˻�Ϊ��
 */
Status EnAQueue(AQueue *Q, void *data){  
	memcpy(Q->data[Q->rear],data,20);
	Q->rear=(Q->rear+1)%Q->length;
	printf("����ӳɹ���\n");
	return 1; 
} 



/**
 *  @name        : Status DeAQueue(AQueue *Q)
 *    @description : ���Ӳ���
 *    @param         Q ����ָ��Q
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : None
 */
Status DeAQueue(AQueue *Q){
	if(Q->data[0] == NULL){
		printf("��������δ��ʼ����\n");
		return 0;
    }
	if(!IsEmptyAQueue(Q)){
		printf("������Ϊ�գ��޷����ӣ�\n");
		return 0;
	}
	Q->front=(Q->front+1)%Q->length;
	printf("�����ӳɹ���\n");
	return 1;
}	



/**
 *  @name        : void ClearAQueue(Queue *Q)
 *    @description : ��ն���
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void ClearAQueue(AQueue *Q){
	if(Q->data[0] == NULL){
		printf("��������δ��ʼ����\n");
		return 0;
    }
    Q->front=Q->rear=0;
	printf("����������գ�\n");
	return ;
}	



/**
 *  @name        : Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q))
 *    @description : ������������
 *    @param         Q ����ָ��Q����������ָ��foo
 *    @return         : None
 *  @notice      : None
 */
Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q,char datatype)){
	int i=0;
	if(Q->data[0]==NULL){
		printf("������δ��ʼ����\n");
		return 0;
	}
	if(!IsEmptyAQueue(Q)){
		printf("����Ϊ�գ�\n");
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
 *    @description : ��������
 *    @param         q ָ��q
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
		printf("������δ��ʼ����\n");
		return 0;
	}
	if(!IsFullAQueue(Q)){
    	printf("�������������޷���ӣ�\n");
    	return 0;
	}
	printf("* ��������������ͣ�\n");
	printf("1.����    2.�����ͣ���ȷ��С�������λ��    3.�ַ���    4.�ַ���\n");
	printf("* ��ѡ��"); 
	scanf("%d",&t);	
	while(t<1||t>4){
		printf("* ������1-4֮���������\n");
		printf("* �����䣺");
		fflush(stdin);
		scanf("%d",&t); 
	} 
	fflush(stdin);
	if(t==1||t==2)
	printf("�����ݾ���ֵ��󲻳���1��Ŷ��\n");
	printf("* ������ݣ�");

	switch(t)
	{
		case INT:{
			int a;
			while((scanf("%d",&a))!=1||a>100000000||a<-100000000)
		 {  
		 	printf("�������ʽ����򳬳���Χ!\n�����䣺");
		 	fflush(stdin);
		  } 
			datatype[Q->rear]=t;
			EnAQueue(Q,&a);
			break;
		}
		
		case DOUBLE:{
			double a;
			while(!(scanf("%lf",&a))||a>100000000||a<-100000000){
				printf("�������ʽ����򳬳���Χ!\n�����䣺"); 
				fflush(stdin); 
			}
			datatype[Q->rear]=t;
			EnAQueue(Q, &a);
			break;
		}
		case CHAR:{
			char a;
			while(!(scanf("%c",&a))){
				printf("�����ʽ���������䣺");
				fflush(stdin);
			}
			datatype[Q->rear]=t;
			EnAQueue(Q, &a);
			break;
		}
		case STRING:{
			char a[20];
			printf("\n����󳤶�Ϊ20��\n");
			while(!(scanf("%s",&a))){
				printf("�������ʽ���������䣺");
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



