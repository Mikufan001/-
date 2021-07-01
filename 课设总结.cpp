#include<stdio.h>
#include<stdlib.h>
#define OPNUM 8
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <malloc.h>
#define OK 1
#define ERROR 0
#define MaxSize_SqQueue 50		//���������󳤶� 
#define MAXSIZE 64
#include<stdlib.h>
#define MaxSize 50
#define SIZE 10
#include<iostream>
#include<iomanip>
#include<fstream>
using namespace std;

typedef struct LNode{
	int data;
	struct LNode *next;
}LNode, *LinkList;

//β�巨����������
LinkList List_TailInsert(LinkList &L){
	L = (LinkList)malloc(sizeof(LNode));		//����ͷ��� 
	L->next = NULL;			//��ʼΪ������ 
	int x;
	LNode *s, *r = L;			//rΪ��βָ�� 
	printf("������Ҫ�����Ԫ��ֵ��(ÿ����һ��ֵ���س�������9999ʱֹͣ����)\n");
	scanf("%d", &x);			//������ֵ 
	while(x!=9999){
		s = (LNode*)malloc(sizeof(LNode));			//�����½�� 
		s->data = x;
		r->next = s;
		r = s;
		scanf("%d", &x);
	} 
	r->next = NULL;
	return L;
}

//��ʾ����������Ԫ�� 
LNode *display(LinkList L){
	LNode *temp = L;
	int count = 0;		
	printf("���е�Ԫ��Ϊ:\n");
	while(temp->next)
	{
		temp = temp->next;
		printf("%d\t",temp->data);
		count++;
		if(count%5==0)		
		{
			printf("\n");
		}
	}
	printf("\n");
}

//���ҽ��,�������в��������Ԫ��e�������ڣ��򷵻�Ԫ�� e��λ��
int GetElem(LNode *L){
	printf("������Ҫ���ҵ�Ԫ�أ�\n");
	int e;
	scanf("%d", &e);
	
	LNode *temp = L;
	int num1 = 1;
	int num2 = 0;
	while(temp->next){
		temp = temp->next;
		if(e == temp->data){
			num2 = num1;
			printf("�ҵ�����%d��ͬ��Ԫ�أ�λ��Ϊ��%d\n", e, num2);
			return 1;
		}
		num1++;
	} 
	printf("û���ҵ���Ԫ�ء�");
	return -1;
}

// �޸ĵ�����ĵ�p��λ���ϵĽ�� 
int replace(LNode *L){
	LNode *temp = L;
	temp = temp->next;
	int p;
	printf("��������Ҫ�޸Ľ���λ�ã�\n");
	scanf("%d", &p);
	for(int i=1; i<p; ++i){
		temp = temp->next;
	}
	printf("������Ҫ�޸ĵ�ֵ��\n");
	int e;
	scanf("%d", &e);
	temp->data = e;
} 

//������ĵ�p��λ���ϲ���Ԫ��
void insertElem(LNode *L){
	LNode *temp = L;
	printf("������Ҫ����Ԫ�ص�λ�ã�\n");
	int p;
	scanf("%d", &p);
	int i = 0;
	while(i<p-1){
		temp = temp->next;
		++i;
	}
	LNode *s = (LNode*)malloc(sizeof(LNode));
	printf("������Ҫ�����Ԫ�أ�\n");
	int e;
	scanf("%d", &e);
	s->data = e;
	s->next = temp->next;
	temp->next = s;
} 

//ɾ���������е�p��λ�õĽ��
void deleteElem(LNode *L){
	LNode *temp = L;
	printf("��������Ҫɾ������λ�ã�\n");
	int p;
	scanf("%d", &p);
	int i = 0;
	while(i<p-1){			//�ҵ�ɾ��������һ��㣬����p-1�����
		temp = temp->next;
		++i;
	}
	LNode *q = temp->next;	//����һ��qָ��ָ��ɾ����� 
	int e = NULL;				
	e = q->data;			//����ɾ������������ 
	temp->next = q->next;	//ɾ��������һ������ָ����ָ��ɾ��������һ����� 
	free(q);				//�ͷ�q��ָ���Ŀռ� 
} 
//���������á�������ʽ��� 
#define NUM 2
#define MAX 100

typedef struct PNode{
	int coef;			//ϵ�� 
	int exp;			//ָ�� 
	struct PNode *next; 
}PolyNode;

PolyNode *aL, *bL, *cL;

//��ʾ����ʽ 
void DisPoly(PolyNode *L)  {
	PolyNode *p;
	p = L;
	while (p!=NULL){ 
		if (p->coef>0&&p!=L){
			printf("+");
		}
		if (p->exp==0){
			printf("%d",p->coef);
		}else if(p->exp==1){
			printf("%dx",p->coef);
		}else{
			printf("%dx^%d",p->coef,p->exp);
		}
		p=p->next;
	}
	printf("\n");
}

//���һ������ʽ 
void DestoryPoly(PolyNode *&L){
	PolyNode *p, *s;
	p = L;
	s = L->next;
	while(s!=NULL){
		free(p);
		p = s;
		s = p->next;
	}
	free(p);
}

//��������ʽ 
void createPoly(PolyNode *&L, int arr[][NUM], int xs){			//xsΪ����,�ö�λ���������ϵ����ָ�� 
	PolyNode *p, *s;
	for(int i=0; i<xs; i++){
		p = (PolyNode*)malloc(sizeof(PolyNode));
		p->coef = arr[i][0];
		p->exp = arr[i][1];
		if(L==NULL){
			L = p;
		}else{
			s->next = p;
		}
		s = p;
	}
	s->next = NULL;
}

//����ʽA�Ͷ���ʽB���ӷ�
void Add(PolyNode *&aL, PolyNode *&bL){
	PolyNode *p, *q, *s;
	q = aL;
	while(q!=NULL){
		p = q;
		q = q->next;
	}
	p->next = bL;
	printf("\n\n���ӣ�");
	DisPoly(aL);
	
	q = aL;
	while(q!=NULL){
		p = q;
		s = q;
		p = p->next;
		while(p!=NULL){
			if(p->exp==q->exp){
				q->coef = q->coef + p->coef;
				s->next = p->next;
				free(p);
				p = s;
			}
			s = p;
			p = p->next;
		}
		q = q->next;
	} 
	printf("\n��Ӵ���");
	DisPoly(aL);
	q = aL;//qָ��ص���ʼ
	p = aL;//pָ��ص���ʼ
	q = p;
	while(q != NULL){
		if(q->coef == 0 ){
			if(q == aL){				
				aL = q ->next;
				q = aL;//qָ��ص���ʼ
				p = aL;//pָ��ص���ʼ				
			}else{
				p->next = q->next;
				free(p);
				p = q;		
			}
		}
		p = q;
		q = q->next;
	}
	printf("\nȥ�����");
	DisPoly(aL);	
} 

int LinkList_Apply(){
	int aNUM = 0;
	int bNUM = 0;
	int A[MAX][NUM] = {0};
	int B[MAX][NUM] = {0};
	
	while(1){
		printf("\n���������ʽA��������");
		scanf("%d", &aNUM);
		if(aNUM!=0){
			break;
		}else{
			printf("\n��������ȷ������!"); 
		}
	}
	for(int i=0; i<aNUM; i++){
		printf("\n��%2d��  ϵ����",i+1);
		scanf("%d",&A[i][0]);
		printf("ָ����");
		scanf("%d",&A[i][1]);
	}
	
	while(1){
		printf("\n���������ʽB��������");
		scanf("%d",&bNUM);
		if(bNUM != 0){
			break;
		}else{
			printf("\n���������� 0 ����������룡\n");
		}
	}
	for(int j = 0; j < bNUM; j++){
		printf("\n��%2d��  ϵ����",j+1);
		scanf("%d",&B[j][0]);
		printf("ָ����",j+1);
		scanf("%d",&B[j][1]);
	}
	
	createPoly(aL,A,aNUM); 
	printf("\nԭA����ʽ��");
	DisPoly(aL);

	createPoly(bL,B,bNUM); 
	printf("\nԭB����ʽ��");
	DisPoly(bL);

	printf("\n��ӵõ���C����ʽ");
	Add(aL,bL);
	printf("\n");
	DestoryPoly(aL);
    return 0;
}


void LinkList_Show(){
	LNode *L;
	int select;
	do{
		printf("\n");
		printf("**************������Ļ���������Ӧ��***************\n");
		printf("* 1  ����                                         *\n");
		printf("* 2  ����                                         *\n");
		printf("* 3  �޸�                                         *\n");
		printf("* 4  ɾ��                                         *\n");
		printf("* 5  ����                                         *\n");
		printf("* 6  Ӧ��                                         *\n");
		printf("* 7  �˳�                                         *\n");
		printf("***************************************************\n");
		printf("��ѡ��");
		scanf("%d",&select);
		switch(select){
		case 1:
			printf("--------����������---------\n");
			List_TailInsert(L);
			display(L);
			break;
		case 2:
			printf("--------����Ԫ��-------\n");
			insertElem(L);
			display(L);
			break;
		case 3:
			printf("--------�޸�Ԫ��-------\n");
			replace(L);
			display(L);
			break;
		case 4:
			printf("--------ɾ��Ԫ��-------\n");
			deleteElem(L);
			display(L);
			break;
		case 5:
			printf("--------����Ԫ��-------\n");
			GetElem(L);
			break;
		case 6:
		    printf("--------Ӧ��---------\n");
		    LinkList_Apply();
			break;
		case 7: 
			break;
		default:
			printf("ERROR!");
			break;		
		}
	}while(select!=7);
}

//�����������������������������������С�������������������������������//
typedef struct{
	int *base;		//�洢�ռ�Ļ���ַ
	int front;		//ͷָ��
	int rear;		//βָ��  
}SqQueue; 

//��ʼ��
bool InitQueue(SqQueue &Q){
	//����һ���ն���
	Q.base = new int[MaxSize_SqQueue];
	if(!Q.base){
		return false;
	} 
	Q.front = Q.rear = 0;
	return true;
} 

//���
bool EnQueue(SqQueue &Q){
	if((Q.rear+1)%MaxSize_SqQueue==Q.front){		//�ж϶����Ƿ����� 
		printf("�����Ѿ����ˣ�\n");
		return false;
	}
	int e;
	printf("��������ӵ�Ԫ�أ�\n");
	scanf("%d", &e);
	Q.base[Q.rear] = e;
	Q.rear = (Q.rear+1)%MaxSize_SqQueue;
	printf("Ԫ��%d�ɹ����", e);
	return true;
} 

//����
bool DeQueue(SqQueue &Q, int &e){		//ɾ��Q�Ķ�ͷԪ�أ���e������ֵ
	if(Q.front==Q.rear){				//�ж϶����Ƿ�Ϊ�� 
		printf("����Ϊ�գ�\n");
		return false;
	}else{
		e = Q.base[Q.front];			//����ͷԪ�ر��浽e	
		Q.front = (Q.front+1)%MaxSize_SqQueue;
		printf("Ԫ��%d�ѳ��ӡ�\n", e);
		return true; 
	}
}

//ȡ��ͷԪ�� 
int GetHead(SqQueue Q){					//����Q�Ķ�ͷԪ�أ����޸�ָ�� 
	if(Q.front==Q.rear){
		printf("����Ϊ�գ�\n");
		return 0;
	}else{
		printf("��ͷԪ��Ϊ��%d\n", Q.base[Q.front]);
		return Q.base[Q.front];
	}
}

//ȡ��βԪ��
int GetEnd(SqQueue Q){
	if(Q.front==Q.rear){
		printf("����Ϊ�գ�\n");
		return 0;
	}else{
		printf("��βԪ��Ϊ��%d\n", Q.rear[Q.base]);
		return 1; 
	}
} 

//Ӧ��
//ͨ����������ӡ�������
#define MaxSize_SqQueue 100

typedef struct{
	int data[MaxSize_SqQueue];		
	int front;			//ͷָ�� 
	int rear;			//βָ�� 
}SqQueue_Apply;

//��ʼ�� 
void InitSqQueue_Apply(SqQueue_Apply *Q){
	Q->front = Q->rear = 0;
}

//���
int EnSqQueue_Apply(SqQueue_Apply *Q, int x){
	if((Q->rear+1)%MaxSize_SqQueue==Q->front){			//�ж϶��� 
		printf("����������\n");
		return 0;
	}else{
		Q->data[Q->rear] = x;
		Q->rear = (Q->rear+1)%MaxSize_SqQueue;
		return 0;
	}
}

//����
int DeSqQueue_Apply(SqQueue_Apply *Q, int *x){
	if(Q->front==Q->rear){			//�ж϶ӿ� 
		printf("����Ϊ�գ�\n");
		return 0; 
	}else{
		*x = Q->data[Q->front];
		Q->front = (Q->front+1)%MaxSize_SqQueue;
		return 0;
	}
} 

//ȡͷԪ��
int GetTop_SqQueue_Apply(SqQueue_Apply *Q, int *x){
	if(Q->front==Q->rear){
		printf("����Ϊ�գ�\n");
		return 0;
	}else{
		*x = Q->data[Q->front];
		return 0;
	}
}

void Queue_Apply(){
	SqQueue_Apply Q_Apply;
	int n, m, i, x, y;
	InitSqQueue_Apply(&Q_Apply);
	printf("������������ǵ�����\n");
	scanf("%d",&m);
	EnSqQueue_Apply(&Q_Apply,1);
	for(n=2; n<=m; n++){
		EnSqQueue_Apply(&Q_Apply, 1);
		for(i=1; i<=n-2; i++){
			DeSqQueue_Apply(&Q_Apply, &x);
			printf("%d", x);
			GetTop_SqQueue_Apply(&Q_Apply, &y);
			y = y+x;
			EnSqQueue_Apply(&Q_Apply, y);
		}
		DeSqQueue_Apply(&Q_Apply, &x);
		printf("%d", x);
		printf("\n");
		EnSqQueue_Apply(&Q_Apply, 1);
	}
	while(Q_Apply.front!=Q_Apply.rear){
		DeSqQueue_Apply(&Q_Apply, &x);
		printf("%d", x);
	}
}

void Queue(){ 
	SqQueue Q;
	InitQueue(Q);
	int select;
	do{
	printf("\n");
	printf("*************���еĻ���������Ӧ��**************\n");
	printf("* 1  ����                                     *\n");
	printf("* 2  ����                                     *\n");
	printf("* 3  ȡ��ͷԪ��                               *\n");
	printf("* 4  ȡ��βԪ��                               *\n");
	printf("* 5  Ӧ��                                     *\n");
	printf("* 6  �˳�                                     *\n");
	printf("***********************************************\n");
	printf("��ѡ��");
	scanf("%d",&select);
	switch(select){
		case 1:
			printf("---------����-------\n");
			EnQueue(Q);
			break;
		case 2:
			printf("---------����-------\n");
			int e;
			DeQueue(Q,e);
			break;
		case 3:
			printf("---------ȡ��ͷԪ��-------\n");
			GetHead(Q);
			break;
		case 4:
			printf("---------ȡ��βԪ��-------\n");
			GetEnd(Q);
			break;
		case 5:
			printf("---------Ӧ��-------\n");
			Queue_Apply();
			break;
		case 6:
			break;
		default:
			printf("ERROR!");break;
	}
	}while(select!=6);
}

 //��������������������������������ջ��������������������������������//
 typedef int datatype;
//������ṹ��
typedef struct{
	char OPname;  //�洢�����
	int inOP;     //�洢ջ�ڼ���
	int outOP;    //�洢ջ�⼶��
}OP;
//����������ջ
typedef struct{
	datatype data[MAXSIZE];
	int top;
}SeqStack;
//���������ջ
typedef struct{
	char data[MAXSIZE];
	int top;
}charStack;
char c[50];  //�洢������ַ���
//--------------------����Ϊջ�Ĳ���-----------------------//
//--------------------������ջ-----------------------//
//��ʼ��ջ
SeqStack *Init_SeqStack(){
	SeqStack *s;
	s = (SeqStack *)malloc(sizeof(SeqStack));
    s->top = -1; 
	return s;
}
//�жϿ�ջ
int Empty_SeqStack(SeqStack *s){
   if (s->top==-1)
   return 1;
   else  return 0;
}  
//��ջ
int Push_SeqStack (SeqStack *s,datatype x){
    if (s->top==MAXSIZE-1){
	 	return 0;
    }else{
		s->top++;
        s->data[s->top]=x;
		return 1;
	}
}
//��ջ
int Pop_SeqStack(SeqStack *s,datatype *x){
    if (Empty_SeqStack(s)){
		return 0;
    }else{
		*x=s->data[s->top];
		s->top--;
		return 1;
	}
}
//ȡջ��Ԫ��
datatype GetSeqTop(SeqStack *s){
    if (Empty_SeqStack(s)){  
		return 0;
    }else{
		return (s->data[s->top]);
	}
}
//--------------------�����ջ-----------------------//
//��ʼ��ջ
charStack *Init_charStack(){
	charStack *s;
	s = (charStack *)malloc(sizeof(charStack));
    s->top = -1; 
	return s;
}
//�жϿ�ջ
int Empty_charStack(charStack *s){
   if (s->top==-1){
   return 1;
   }else{
		return 0;
	}
}
//��ջ
int Push_charStack (charStack *s,char x){
    if (s->top==MAXSIZE-1){
		return 0;
    }else {
		s->top++;
        s->data[s->top]=x;
		return 1;
	}
}
//��ջ
int Pop_charStack(charStack *s,char *x){
    if (Empty_charStack(s)){
		return 0;
    }else{
		*x=s->data[s->top];
		s->top--;
		return 1;
	}
}
//ȡջ��Ԫ��
char GetcharTop(charStack *s){
    if (Empty_charStack(s)){
		return 0;
    }else{
		return (s->data[s->top]);
	}
}

//----------------�������������-----------------//

OP OPPree[OPNUM] = {
	{'+',3,2},
	{'-',3,2},
	{'*',5,4},
	{'/',5,4},
	{'^',7,6},
	{'(',1,8},
	{')',0,1},
	{'#',-1,-1}
};
//-----------------�ж��Ƿ�Ϊ�����-------------------//
int In(char x){
	int i;
	for(i=0;i<=OPNUM;i++){		  	//��������������
		if (x==OPPree[i].OPname){ 
		return 1;  					//�����������1
		}
	}
	return 0;  						//�������������0
}

//-----------------�ж����ȼ�------------------------//
char Precede(char x,char c){
	int i,inlev;
	for(i=0;i<=OPNUM;i++){
		if (x==OPPree[i].OPname){
			break;
		}
	}                                 //���� x ���±�
	inlev = OPPree[i].inOP;
	for(i=0;i<=OPNUM;i++){
		if (c==OPPree[i].OPname){
		break;
		}
	}  //���� c ���±�
	if (inlev < OPPree[i].outOP){
		return '<';  //�Ƚ� x ��ջ�ڼ���� c ��ջ�⼶��
	}else if(inlev > OPPree[i].outOP){
		return '>';
	}else{
		return '=';
	}
}

//-------------------���㺯��-------------------------//
int Operate(int a,char x,int b){
	switch (x){
		case '+' : return (a+b);break;
		case '-' : return (a-b);break;
		case '*' : return (a*b);break;
		case '/' :
				if (b==0) return ERROR;
				return (a/b);
				break;
		case '^' : return ((int)pow(a,b));break;
		default : return ERROR;
	}
}

//-----------------��׺���ʽ����ʵ�ֺ���----------------------//
int EvaluateExpression(){
	int i=0;
	datatype a,b;
	char x,theta;
	charStack *OPTR;
    SeqStack *OPND;
	OPTR = Init_charStack();  	//�����ջ
	Push_charStack(OPTR, '#');
	OPND = Init_SeqStack();  	//������ջ
	while(c[i] != '\0'){
		if (!In(c[i])){			//������������
			Push_SeqStack(OPND,c[i]-'0');  //��������ջ
			i++;
		}else{
			switch(Precede(GetcharTop(OPTR),c[i])){
			//����������,ȡջ��Ԫ�ص�ջ�ڼ����ջ��Ԫ�ص�ջ�⼶��Ƚ�
				case '<' :
					Push_charStack(OPTR,c[i]);  //С���������ջ
					i++;
					break;
				case '=' :
					Pop_charStack(OPTR,&x);  //�������ջ
					i++;
					break;
				case '>' :
					Pop_charStack(OPTR, &theta);
					Pop_SeqStack(OPND,&b);
					Pop_SeqStack(OPND,&a);  //������������һ���������ջ,��������
					Push_SeqStack(OPND,Operate(a,char(theta),b));
					break;
			}
		}
	}
	return GetSeqTop(OPND);
}

//-----------------��׺���ʽת����׺���ʽ----------------------//
void change(char a[],char s[]){
	int i=0,j=0;
	char temp;
	charStack *OPTR;
	OPTR = Init_charStack();
	Push_charStack(OPTR, '#');
	while(a[i]!='\0'){
		if (!In(a[i])){			//������������
			s[j]=a[i];
			j++;
			i++;  				//ֱ�����뵽��׺���ʽ
			continue;
		}else{
			switch(Precede(GetcharTop(OPTR),a[i])){
				case '<' :
					Push_charStack(OPTR,a[i]);  //��ջ�ڼ���С��ջ�⼶���ʱ����ջ
					i++;
					break;
				case '>' :
					while(Precede(GetcharTop(OPTR),a[i])=='>'){		//��ջ��Ԫ�ش���ջ��Ԫ��
						Pop_charStack(OPTR, &temp);  //ջ��Ԫ�س�ջ
						s[j]=temp;
						j++;
						temp=GetcharTop(OPTR);  //ȡջ��Ԫ�ؼ����Ƚ�
					}
					break;
				case '=':
					Pop_charStack(OPTR, &temp); //���ھͳ�ջ
					i++;
			}
		}
	}
	s[j]='\0';
}

//-----------------��׺���ʽ����ʵ�ֺ���----------------------//
int HZcalc(	char s[])  {
	int i=0;
	datatype a,b;
	SeqStack *OPND;
	OPND = Init_SeqStack();  //������ջ
	while(s[i] != '\0'){
		if (!In(s[i])) {
			Push_SeqStack(OPND,s[i]-'0');  //�������������������ջ
			i++;
		}else{
			Pop_SeqStack(OPND,&b);
			Pop_SeqStack(OPND,&a);  //ȡջ������Ԫ��������
			Push_SeqStack(OPND,Operate(a,s[i],b));  //�����ѽ����ջ
			i++;
		}
	}
	return GetSeqTop(OPND);
}
	


void SqStack_Apply(){
	int i;
	printf("\n");
	printf("��������ʽ���ԡ�#��������\n");
	printf("\n");
	printf(" ");
	gets(c);
	printf("\n");
    i=EvaluateExpression();
	char s[50];
    change(c,s);
	printf("��׺���ʽ��ֵ���Ϊ��%d\n",i);
    printf("��׺���ʽΪ��");
    puts(s);
	i = HZcalc(s);
	printf("��׺���ʽ��ֵ���Ϊ��%d\n",i);
	printf("\n");
	printf(" �������������");
	getchar();
}

typedef struct{
	int *base;
	int *top;
	int stacksize;
}SqStack;

//����һ��ջ
int Create_SqStack(SqStack &S){
	S.base = (int*)malloc(MaxSize*sizeof(int));
	if(!S.base){
		printf("�洢����ʧ��!\n");
		return 0;
	}
	S.top = S.base;
	S.stacksize = MaxSize;
	printf("������ջԪ�ظ�����\n");
	int n;
	scanf("%d", &n);
	printf("������ջԪ��:\n");
	for(int i=1; i<=n; i++){
		scanf("%d", &*S.top);
		S.top++;
	}
}

//��ʾջ������Ԫ��
int Display_SqStack(SqStack &S){
	if(S.top==S.base){
		printf("ջΪ�գ�");
		return 0;
	}
	int *p;
	p = S.top;
	printf("ջ��Ԫ��Ϊ��\n");
	while(p>S.base){
		p--;
		printf("%d\t", *p);
	}
	printf("\n");
} 
	
//��ջ
int Push(SqStack &S){
	int e;
	printf("������Ҫ��ջ��Ԫ��:\n");
	scanf("%d", &e);
	if(S.top-S.base>=S.stacksize){
		S.base = (int*)realloc(S.base,(S.stacksize+SIZE)*sizeof(int));
		if(!S.base){
			printf("�洢����ʧ�ܣ�");
			return 0;
		}
		S.top = S.base + S.stacksize;
		S.stacksize+=SIZE;
	}
	*S.top++=e;
} 
	
//��ջ
int Pop(SqStack &S){
	int e;
	if(S.top==S.base){
		printf("ջΪ�գ�\n");
		return 0;
	}else{
		e=*--S.top;
		printf("��ջ��Ԫ��Ϊ��%d", e);
		return 0;
	}
} 
	
//ȡջ��Ԫ��
int GetTop(SqStack S, int& e)
{
	if (S.top == S.base)
	{
		printf("ջΪ�գ�\n");
		exit(1);
	}
	e = *(S.top - 1);
	return 0;
}


void Stack(){ 
	SqStack S;
	int select;
	do{
		printf("\n");
		printf("****************ջ�Ļ���������Ӧ��*****************\n");
		printf("* 1  ����ջ                                       *\n");
		printf("* 2  ��ջ                                         *\n");
		printf("* 3  ��ջ                                         *\n");
		printf("* 4  ȡջ��Ԫ��                                   *\n");
		printf("* 5  Ӧ��                                         *\n");
		printf("* 6  �˳�                                         *\n");
		printf("***************************************************\n");
		printf("��ѡ��");
		scanf("%d",&select);
		switch(select){
			case 1:
				printf("--------����ջ-------\n");
				Create_SqStack(S);
				printf("\n");
				Display_SqStack(S);
				break;
			case 2:
				printf("--------��ջ-------\n"); 
				Push(S);
				printf("\n");
				Display_SqStack(S);
				break;
			case 3:
				printf("--------��ջ-------\n");
				Pop(S);
				printf("\n");
				Display_SqStack(S);
				break;
			case 4:
				printf("--------ȡջ��Ԫ��-------\n");
				int e;
				GetTop(S, e);
				printf("ջ��Ԫ��Ϊ��%d", e);
				break;
			case 5:
				printf("--------Ӧ��-------\n");
				SqStack_Apply();
				break;
			case 6:
				break;
			default:
				printf("ERROR!");
				break;
		}
	}while(select!=6);
}
 
 //����������ṹ��
typedef struct BiTNode{
	char data;
	struct BiTNode *lchild;
	struct BiTNode *rchild;
}BiTNode, *BiTree;

//����������
int CreateBiTree(BiTree &T){
	char e;
	cin>>e;
	if(e=='$'){
		T=NULL;
	}else{
		T = new BiTNode;
		T->data = e;
		CreateBiTree(T->lchild);
		CreateBiTree(T->rchild);
	}
	return 0;
} 

//�������
int PreOrder(BiTree T, int(*Visit)(char e)){
	if(T==0){
		return 0;
	}
	cout<<(T->data);
	PreOrder(T->lchild, Visit);
	PreOrder(T->rchild, Visit);
	return 1;
}
//�������
int InOrder(BiTree T, int(*Visit)(char e)){
	if(T==0){
		return 0;
	}
	InOrder(T->lchild, Visit);
	cout<<(T->data);
	InOrder(T->rchild, Visit);
	return 1;
} 
//�������
int PostOrder(BiTree T, int (*Visit)(char e)){
	if(T==0){
		return 0;
	}
	PostOrder(T->lchild, Visit);
	PostOrder(T->rchild, Visit);
	cout<<(T->data);
	return 1;
} 

//��� 
int Print_Element(char e){
	cout<<e;
	return 1;
}

//������������
int Height(BiTree T){
	int LD, RD;
	if(T==NULL){
		return 0;
	}else{
		LD = Height(T->lchild);
		RD = Height(T->rchild);
		return (LD>RD?LD:RD)+1;
	}
} 

//���������Ҷ�ӽ����
int Leave(BiTree T){
	if(T==NULL){
		return 0;
	}else{
		if(T->lchild==NULL&&T->rchild==NULL){
			return 1;
		}else{
			return (Leave(T->lchild)+Leave(T->rchild));
		}
	}
} 

//���ҽ���˫�� 
int Parent(BiTree T, char e){
	int m;
	if(T==NULL){
		return 0;
	}
	if((T->lchild&&T->lchild->data==e)||(T->rchild&&T->rchild->data==e)){
		return T->data;
	}
	m = Parent(T->lchild, e);
	if(m==0){
		m = Parent(T->rchild, e);
		return m;
	}
}

//���ҽ����ֵ�
int Brother(BiTree T, char e){
	int m;
	if(T==NULL){
		return 0;
	}
	if(T->lchild&&T->lchild->data==e){
		return T->rchild->data;
	}
	if(T->rchild&&T->rchild->data==e){
		return T->lchild->data;
	}
	m = Brother(T->lchild, e);
	if(m==0){
		m = Brother(T->rchild, e);
	}
	return m;
} 


void BiTrees(){ 
	BiTree T =NULL;
	char e, m, r, l;
	int height, num;
	int select;
	do{
	printf("\n");
	printf("**************�������Ļ���������Ӧ��***************\n");
	printf("* 1  ����                                         *\n");
	printf("* 2  ��������/��/��                             *\n");
	printf("* 3  �������                                   *\n");
	printf("* 4  ���������                                   *\n");
	printf("* 5  ����˫��                                     *\n");
	printf("* 6  �����ֵܣ���/�ң�                            *\n");
	printf("* 7  �˳�                                         *\n");
	printf("***************************************************\n");
	printf("��ѡ��");
	scanf("%d",&select);
	switch(select){
		case 1:
			printf("---------����--------\n");
			T=NULL;
			printf("�����������Ԫ�أ�(��$��ʾ��)\n");
			CreateBiTree(T);
			break;
		case 2:
			printf("---------��������/��/��-------\n");
			printf("\n���������������ö�������Ԫ��Ϊ��"); PreOrder(T, Print_Element);
			printf("\n���������������ö�������Ԫ��Ϊ��"); InOrder(T, Print_Element);
			printf("\n���������������ö�������Ԫ��Ϊ��"); PostOrder(T, Print_Element);
			break;
		case 3:
			printf("---------�������-------\n");
			num = Leave(T);
			printf("������Ҷ�ӽ�����Ϊ��");
			cout<<num;
			break;
		case 4:
			printf("---------���������-------\n");
			height = Height(T);
			printf("�����������Ϊ��");cout<<height;
			break;
		case 5:
			printf("---------����˫��-------\n");
			printf("������Ҫ���ҵĽ�㣺");
			cin>>e;
			m = Parent(T,e);
			printf("�ý�� ��˫��Ϊ��");
			cout<<m;
			break;
		case 6:
			printf("---------�����ֵܣ���/�ң�-------\n");
			printf("������Ҫ���ҵĽ�㣺");
			cin>>e;
			m = Brother(T, e);
			printf("�ý����ֵ�Ϊ��");
			cout<<m;
			break;	
		case 7:
			break;
		default:
			printf("ERROR!");
			break;
	}
	}while(select!=7);
}

void ShowMainMenu(){
	printf("\n");
	printf("*******************�㷨�����ݽṹ******************\n");
	printf("* 1  ������Ļ���������Ӧ��                       *\n");
	printf("* 2  ջ�Ļ���������Ӧ��                           *\n");
	printf("* 3  ���еĻ���������Ӧ��                         *\n");
	printf("* 4  �������Ļ���������Ӧ��                       *\n");
	printf("* 5  ͼ�Ļ���������Ӧ��                           *\n");
	printf("* 6  �˳�                                         *\n");
	printf("***************************************************\n");
}


//ͼ�Ĳ��� 
using namespace std;
enum returninfo {success,fail,overflow,underflow,nolchild,norchild,nofather,havesonl,havesonr,
                 haveason,havetwosons,range_error,quit
                };	//���巵����Ϣ�嵥
int build;//���ڿ����Ƿ����ؽ�ͼ��Ϊ0ʱ��ʾ��һ�ν���ͼ��Ϊ1ʱ��ʾ�ؽ�ͼ
/************************************************************/
//˳����� ��ͼ�н����˳������洢���ͼ�н��Ķ�̬��ɾ����
const int MaxListSize=26;//Լ����˳������ֻ��26����ĸ
class SeqList {
	private:
		int	size;
		int node[MaxListSize];
	public:
		SeqList();
		~SeqList();
		int ListSize()const;
		int ListEmpty()const;
		int Find(char &item)const;
		char Getdata(int pos)const;
		void Insert(const char&item,int pos);
		int Delete(const int pos);
		void ClearList();
};
SeqList::SeqList() { //˳���Ĺ��캯��
	size=0;
}
SeqList::~SeqList() {} //˳������������
int SeqList::ListSize()const { //��˳���Ľ������ĺ���
	return size;
}
int SeqList::ListEmpty()const { //�ж�˳����Ƿ�Ϊ�յĺ���
	if(size==0)
		return 1;
	else
		return 0;
}
int SeqList::Find(char &item)const { //����ĳ�����ĺ���
	if(size==0) {
		return -1;
	}
	int i=0;
	while(i<size && item!=node[i]) {
		i++;
	}
	if(i<size) {
		return i;
	} else return -1;
}
char SeqList::Getdata(int pos)const { //��ȡĳ��λ�ý��ĺ���
	if(pos<0||pos>size-1) {
		cout<<"�Բ���!λ�ò���Խ�����!"<<endl;
		return(false);
	}
	return node[pos];
}
void SeqList::Insert(const char &item,int pos) { //����һ����㵽˳�����
	int i;
	if(size==MaxListSize) {
		cout<<"˳��������޷�����!"<<endl;
		return;
	} else if(pos<0||pos>size) { //���������һ��Ԫ���ұ��ǺϷ���
		cout<<"�Բ���!λ�ò���Խ�����!"<<endl;
		return;
	} else {
		for(i=size; i>pos; i--) {
			node[i]=node[i-1];
			cout<<node[i]<<"//////////////////"<<endl;
		}
		node[pos]=item;
		size++;
	}
}
//��˳�����ɾ��һ�����
int SeqList::Delete(const int pos) {
	if(size==0) {
		cout<<"˳����ѿ��޷�ɾ��!"<<endl;
		return 0;
	} else if(pos<0||pos>size-1) {
		cout<<"�Բ���!λ�ò���Խ�����!"<<endl;
		return 0;
	} else {
		char temp=node[pos];
		for(int i=pos; i<size-1; i++) {
			node[i]=node[i+1];
		}
		size--;
		return 1;
	}
}
void SeqList::ClearList() { //��������˳���
	size=0;
}
/***************************************************************************/
//�����ࣺ���ͼ�Ĺ�����ȱ���
const int maxsize=100;
//������ѭ�����е���
class SeqQueue {
	private:
		char queuedata[maxsize];//��������Ԫ�ظ���
		int  front;//����һ������ָ��
		int  rear;//����һ����βָ��
		int  count;//Ԫ�ظ���������
	public:
		SeqQueue(void);//���캯��
		~SeqQueue() {}; //��������
		int  isempty()const {
			return front==rear;
		}
		void enqueue(const char&item);//Ԫ����Ӻ���
		char dequeue();//���Ӻ���
		void showseq();//��������
		void getfront();//����ͷ���ĺ���
};
SeqQueue::SeqQueue() {
	front=0;//ͷβָ���ռһ���ռ䣬��ô�ܵĿ��Դ����Ԫ�صĸ���Ϊmaxsize-1
	rear =0;
	count=0;//��������ʼΪ0
}
void SeqQueue::enqueue(const char&item) {
	if(front==(rear+1)%maxsize) { //������������
		cout<<"�Բ���!��������!�޷����!"<<endl;
	} else {
		queuedata[rear]=item;//����Ԫ�شӶ�β���
		rear=(rear+1)%maxsize;//��β�ȼ�һ��ȡģ
		count++;//��������һ
	}
}
char SeqQueue::dequeue() {
	if(count==0) { //����Ϊ�յ�����
		cout<<"�Բ���!�����ѿ�!�޷�ɾ��!"<<endl;
		return false;
	} else {
		char datatemp=queuedata[front];//����Ԫ�شӶ�ͷ����
		front=(front+1)%maxsize;//��ͷ����
		count--;//Ԫ�ظ�����һ
		return datatemp;
	}
}
void SeqQueue::showseq() {
	cout<<"����ȫ��Ԫ������:"<<endl;
	for(int i=front; i!=rear;) { //���ײ�δ�洢Ԫ�ع�Ҫ��front��ʼ����
		cout<<" "<<queuedata[i];
		i=(i+1)%maxsize;
	}
	cout<<endl;
	cout<<"��ǰԪ�ظ���Ϊ: "<<count<<endl;
	cout<<endl;
}
void SeqQueue::getfront() {
	if(count==0) { //����Ϊ�յ�����
		cout<<"�Բ���!�����ѿ�!"<<endl;
		return;
	} else {
		cout<<"��ͷ��Ԫ�ص�ֵΪ :"<<queuedata[front]<<endl;
	}
}
/////////////
//ͼ��
const int maxvertices=26;//������������ֵΪ26
const int maxweight=10000;//���������֮�䲻���ڱ�ʱ�����������10000��ģ��
class graph {
	private://ͼ�����ݽṹ��ϸ�ڿ��Բμ��̲�
		int i,j;
		int flag;
		int inputnodenum,inputedgenum;
		int numofedges;
		char *nodearray;
		SeqList Vertices;
		int Edge[maxvertices][maxvertices];
	public:
		graph(const int size=maxvertices);					//ͼ�Ĺ��캯��
		~graph() {};											//ͼ����������
		void initializationofEdge(int size);				//�ߵ��ڽӾ����ʼ��
		void inputdata();									//�ֹ���������
		void defaultdata();									//����Ĭ������
		void showgraph();									//��ʾͼ���ڽӾ���
		void showVertex();									//��ʾͼ�Ľ��
		int  graphempty()const {
			return Vertices.ListEmpty();   //�ж�ͼ�Ƿ�Ϊ��
		}
		int  numofVertices() {
			return Vertices.ListSize();   //��ͼ�Ľ�����
		}
		int  numofEdges(void) {
			return numofedges;   //��ͼ�ı���
		}
		char getvalue(const int i);							//��ȡͼĳ������ֵ
		int  getweight(const int nodestart,const int nodeend);//���������֮��ıߵ�Ȩֵ
		void insertVertices(const char& vertices);			//��ͼ�����һ�����
		int  deleteVertex(const int v);						//ɾ��һ�����
		int  insertEdge(const int nodestart,const int nodeend,int weight);//���һ����
		int  deleteEdge(const int nodestart,const int nodeend);//ɾ��һ����
		int  getfirstneighbor(const int v);//Ϊʵ��ͼ�ı��������붨�����ȡ���һ�����ڽ��ĺ���
		int  getnextneighbor(const int nodestart,const int nodeend);//��ȡ����һ�����ڽ��ĺ���
		void depthfirstsearch(const int v,int visited[],void visit(char item));//������ȱ���
		void breadthfirstsearch(const int v,int visited[],void visit(char item));//������ȱ���
};
graph::graph(const int size) { //ͼ�Ĺ��캯��
	initializationofEdge(maxvertices);
}
void graph::initializationofEdge(int size) { //�ߵ��ڽӾ����ʼ��
	for(int i=0; i<size; i++) { //�ڽӾ���ĳ�ʼ��
		for(int j=0; j<size; j++)
			if(i==j) {
				Edge[i][j]=0;//������ͬ���֮��ıߵ�ȨֵΪ0
			} else
				Edge[i][j]=maxweight;//��ʼ״̬��ͬ���֮�䲻���ڱߣ�Ȩֵ�������10000����ʾ
	}
	numofedges=0;//��ʼ״̬�ߵ�����Ϊ0
}
void graph::inputdata(void) {
	int nodestart,nodeend,weight;//��ʼ�㡢��ֹ�㡢Ȩֵ
	Vertices.ClearList();//����������
	initializationofEdge(maxvertices);
//	cout<<"�������������ͼ������ͼ��"<<endl;
	cout<<"���ϣ����������ͼ��ÿ������Ҫ�������Σ���(a,b)��(b.a)"<<endl;
	cout<<"������ӽ����Ϣ!"<<endl;
	cout<<"----------------"<<endl;
	cout<<"�����������(С�� "<<maxvertices<<"):";
	cin>>inputnodenum;
	nodearray=new char[inputnodenum];//�����ַ�����
	cout<<"������"<<inputnodenum<<"�����(����Ascii���ַ�)���ո������������Ϻ�س�:"<<endl;
	for(i=0; i<inputnodenum; i++) {
		cin>>nodearray[i];
		insertVertices(nodearray[i]);
	}
	cout<<inputnodenum<<"������Ѿ���ӳɹ���!�ַ��ĵ�Ĭ�ϱ����:"<<endl;
	for(i=0; i<inputnodenum; i++) //��ʾ��Ӧ����
		cout<<setw(5)<<i;
	cout<<endl;
	for(i=0; i<inputnodenum; i++) //��ʾ�������ַ�
		cout<<setw(5)<<nodearray[i];
	cout<<endl<<endl;
	cout<<"������ӱ���Ϣ!"<<endl;
	cout<<"---------------"<<endl;
	cout<<"���������: ";
	cin>>inputedgenum;
	cout<<"����:1 2 10 ��ʾ�����һ����(��1�Ž�㵽2�Ž�㣬ȨֵΪ10)!:"<<endl;
	for(i=0; i<inputedgenum; i++) {
		cout<<"������ӵ�"<<i+1<<"���ߵ���Ϣ: "<<endl;
		cin>>nodestart>>nodeend>>weight;
		flag=insertEdge(nodestart,nodeend,weight);
		if(flag==1)
			cout<<"��"<<nodestart<<"�Ž��"<<"��"<<nodeend<<"�Ž��֮���Ѿ������ȨֵΪ"
			    <<weight<<"��һ����!"<<endl<<endl;
	}
	cout<<"ͼ�Ѿ�����!"<<endl;
	delete[] nodearray;
	build=1;
}
void graph::showgraph() { //ͼ����ʾ����
	for(i=0; i<Vertices.ListSize(); i++) { //���ڽӾ�����ģ��ͼ�ıߵ������Ϣ
		for(j=0; j<Vertices.ListSize(); j++) {
			if(getweight(i,j)==maxweight)
				cout<<setw(5)<<"��";
			else
				cout<<setw(5)<<getweight(i,j);
		}
		cout<<endl;
	}
}
void graph::showVertex() { //��ʾͼ�Ľ��
	for(i=0; i<Vertices.ListSize(); i++) //��ʾ����
		cout<<setw(5)<<i;
	cout<<endl;
	for(i=0; i<Vertices.ListSize(); i++) //��ʾ����
		cout<<setw(5)<<Vertices.Getdata(i);
	cout<<endl;
}
char graph::getvalue(const int i) { //��ȡͼ��ĳ������ֵ
	if(i<0||i>Vertices.ListSize()) {
		cout<<"�Բ������Խ�����!"<<endl;
		return false;
	} else
		return Vertices.Getdata(i);//����˳���Ĳ������Ŀ��
}
int graph::getweight(const int nodestart,const int nodeend) { //���������֮��ıߵ�Ȩֵ
	if(nodestart<0||nodestart>Vertices.ListSize()||nodeend<0||nodeend>Vertices.ListSize()) {
		cout<<"�Բ������Խ�����!"<<endl;
		return false;
	} else
		return Edge[nodestart][nodeend];
}
void graph::insertVertices(const char& vertices) { //���һ�����
	Vertices.Insert(vertices,Vertices.ListSize());//Ϊ�˼򵥰���ӽ�����˳�������λ��
}
int graph::deleteVertex(const int v) { //ɾ��һ�����
	for(int i=0; i<Vertices.ListSize(); i++) //ɾ������������������������ȫ���ı�����ɾ��
		for(int j=0; j<Vertices.ListSize(); j++) {
			if(i==v||j==v && Edge[i][j]>0 && Edge[i][j]<maxweight) {
				Edge[i][j]=maxweight;
				numofedges--;
			}
		}
	int flag=Vertices.Delete(v);
	if(flag==1)//�ṩһ����־λΪ����ĵ��÷���
		return 1;
	else
		return 0;
}
int graph::insertEdge(const int nodestart,const int nodeend,int weight) { //���һ����
	if(nodestart<0||nodestart>Vertices.ListSize()||nodeend<0||nodeend>Vertices.ListSize()) {
		cout<<"�Բ������Խ�����!"<<endl;
		return 0;
	} else {
		Edge[nodestart][nodeend]=weight;
		numofedges++;
		return 1;
	}
}
int graph::deleteEdge(const int nodestart,const int nodeend) { //ɾ��һ����
	if(nodestart<0||nodestart>Vertices.ListSize()||nodeend<0||nodeend>Vertices.ListSize()) {
		cout<<"�Բ������Խ�����!"<<endl;
		return 0;
	} else {
		Edge[nodestart][nodeend]=maxweight;
		numofedges--;
		return 1;
	}
}
int graph::getfirstneighbor(const int v) { //��ȡ���һ�����ڽ��
	if(v<0||v>Vertices.ListSize()) {
		cout<<"�Բ������Խ�����!"<<endl;
		return false;
	} else {
		for(int col=0; col<=Vertices.ListSize(); col++) {
			if(Edge[v][col]>0 && Edge[v][col]<maxsize)
				return col;//���������ڵĽ�㷵�����±�
		}
		return -1;//���򷵻�-1
	}
}
int graph::getnextneighbor(const int nodestart,const int nodeend) { //��ȡ����һ���ڽӱ�
	//�ҽ��nodestart��<nodestart,nodeend>�ڽӱߵ���һ���ڽӱ�
	if(nodestart<0||nodestart>Vertices.ListSize()||nodeend<0||nodeend>Vertices.ListSize()) {
		cout<<"�Բ������Խ�����!"<<endl;
		return false;
	} else {
		//ʹcolΪnodeend+1���Ѱ�ҵı���nodestart��<nodestart,nodeend>�ڽӱߵ���һ���ڽӱ�
		for(int col=nodeend+1; col<=Vertices.ListSize(); col++) {
			if(Edge[nodestart][col]>0&&Edge[nodestart][col]<maxsize)
				return col;
		}
		return -1;
	}
}
void graph::depthfirstsearch(const int startpoint,int visited[],void visit(char item)) { //������ȱ���
	int neighborpoint;
	visit(getvalue(startpoint));
	visited[startpoint]=1;
	neighborpoint=getfirstneighbor(startpoint);
	while(neighborpoint!=-1) {
		if(!visited[neighborpoint])
			depthfirstsearch(neighborpoint,visited,visit);
		neighborpoint=getnextneighbor(startpoint,neighborpoint);
	}
//������ȱ���ʵ�ִ���
}
void graph::breadthfirstsearch(const int startpoint,int visited[],void visit(char item)) { //������ȱ���
	char getqueuehead,neighborpoint;
	SeqQueue queue;
	visit(getvalue(startpoint));
	visited[startpoint]=1;
	queue.enqueue(startpoint);
	while(!queue.isempty()) {
		getqueuehead=queue.dequeue();
		neighborpoint=getfirstneighbor(getqueuehead);
		while(neighborpoint!=-1) {
			if(!visited[neighborpoint]) {
				visit(getvalue(neighborpoint));
				visited[neighborpoint]=1;
				queue.enqueue(neighborpoint);
			}
			neighborpoint=getnextneighbor(getqueuehead,neighborpoint);
		}
	}
//������ȱ���ʵ�ִ���
}
void printchar(char item) {
	cout<<setw(5)<<item;
}
////////////////
//���洦����󣺽����
class interfacebase {
	private:
		int i;							//ѭ������
		int nodestart,nodeend,weight;	//��ʼ�㡢��ֹ�㡢Ȩֵ
		int flag;						//��־λ
		graph graphnow;					//ͼ�����ʵ����
	public:
		void showmenu(void);
		void processmenu(void);
};
void interfacebase::showmenu(void) {
	cout<<"****************ͼ�Ļ���������Ӧ��*****************"<<endl;
	cout<<"1.�ֹ�����������ͼ				 "<<endl;
	cout<<"2.���ڽӾ�����ʽ��ʾͼ			 "<<endl;
	cout<<"3.��ͼ�Ľ�����ͱ��� 			 "<<endl;
	cout<<"4.��ĳ���ߵ�Ȩֵ 				 "<<endl;
	cout<<"5.��ӽ��                        "<<endl;
	cout<<"6.ɾ�����   			         "<<endl;
	cout<<"7.��ӱ�  						 "<<endl;
	cout<<"8.ɾ���� 						 "<<endl;
	cout<<"9.������ȱ���ͼ					 "<<endl;
	cout<<"s.������ȱ���ͼ					 "<<endl;
	cout<<"0.�˳�							 "<<endl;
	cout<<"***************************************************"<<endl;
}
void interfacebase::processmenu() {
	char choice,yesno;			//�����û�ѡ��˵�ѡ��
	char newnode;
	int *visited;
	cout<<"������ѡ�";
	cin>>choice;
	switch(choice) {
		case '1':
			cout<<"================"<<endl;
			if(build==1) {
				cout<<"Σ�ղ�����ԭ�����ݽ���ɾ��!��ȷ����?ȷ����(Y||y)��!���������!"<<endl;
				cin>>yesno;
				if(yesno!='y' && yesno!='Y') {
					cout<<"�Ѿ�ȡ������ͼ!"<<endl;
					break;
				}
			}
			graphnow.inputdata();
			cout<<"================"<<endl;
			break;
		case '2':
			if(build==0) {
				cout<<"================"<<endl;
				cout<<"ͼδ���������β���ʧ��!!!"<<endl;
				cout<<"================"<<endl;
				break;
			}
			cout<<"================"<<endl;
			cout<<"��ǰͼ������ͽ������:"<<endl;
			graphnow.showVertex();
			cout<<"��ǰͼ���ڽӾ�������:"<<endl;
			graphnow.showgraph();
			cout<<"================"<<endl;
			break;
		case '3':
			if(build==0) {
				cout<<"================"<<endl;
				cout<<"ͼδ���������β���ʧ��!!!"<<endl;
				cout<<"================"<<endl;
				break;
			}
			cout<<"================"<<endl;
			cout<<"��ǰͼ������ͽ������:"<<endl;
			graphnow.showVertex();
			cout<<"��ǰͼ���ڽӾ�������:"<<endl;
			graphnow.showgraph();
			cout<<"��ǰ������Ϊ :";
			cout<<graphnow.numofVertices();
			cout<<endl;
			cout<<"��ǰͼ�ı���Ϊ :";
			cout<<graphnow.numofEdges();
			cout<<endl;
			cout<<"================"<<endl;
			break;
		case '4':
			if(build==0) {
				cout<<"================"<<endl;
				cout<<"ͼδ���������β���ʧ��!!!"<<endl;
				cout<<"================"<<endl;
				break;
			}
			cout<<"================"<<endl;
			cout<<"��ǰͼ������ͽ������:"<<endl;
			graphnow.showVertex();
			cout<<"��ǰͼ���ڽӾ�������:"<<endl;
			graphnow.showgraph();
			cout<<"��������Ҫ��ȡ���ĸ���㵽�ĸ����֮��ıߵ�Ȩֵ:"<<endl;
			cout<<"ע�⣺��С�±��0��ʼ��"<<endl;
			cout<<"����:����0 1��ʾ��ȡ(��0�Ž�㵽1�Ž��)�ıߵ�Ȩֵ!:"<<endl;
			cin>>nodestart>>nodeend;
			weight=graphnow.getweight(nodestart,nodeend);
			if(weight==maxweight) {
				cout<<"���"<<nodestart<<"��"<<nodeend<<"����������Ľ��!!!"<<endl;
				cout<<"���"<<graphnow.getvalue(nodestart)
				    <<"��"<<graphnow.getvalue(nodeend)<<"֮��ıߵ�ȨֵΪ: ��"<<endl;
			} else {
				cout<<"���"<<nodestart<<"��"<<nodeend<<"����������Ľ��!!!"<<endl;
				cout<<"���"<<graphnow.getvalue(nodestart)
				    <<"��"<<graphnow.getvalue(nodeend)<<"֮��ıߵ�ȨֵΪ: "<<weight<<endl;
			}
			cout<<"================"<<endl;
			break;
		case '5':
			if(build==0) {
				cout<<"================"<<endl;
				cout<<"ͼδ���������β���ʧ��!!!"<<endl;
				cout<<"================"<<endl;
				break;
			}
			cout<<"================"<<endl;
			cout<<"��ǰͼ������ͽ������:"<<endl;
			graphnow.showVertex();
			cout<<"��ǰͼ���ڽӾ�������:"<<endl;
			graphnow.showgraph();
			cout<<"��������ӵĽ���ֵ(char)��:"<<endl;
			cin>>newnode;
			graphnow.insertVertices(newnode);
			cout<<"���"<<newnode<<"�Ѿ����!"<<endl;
			cout<<"��ǰͼ������ͽ������:"<<endl;
			graphnow.showVertex();
			cout<<"��ǰͼ���ڽӾ�������:"<<endl;
			graphnow.showgraph();
			cout<<"================"<<endl;
			break;
		case '6':
			if(build==0) {
				cout<<"================"<<endl;
				cout<<"ͼδ���������β���ʧ��!!!"<<endl;
				cout<<"================"<<endl;
				break;
			}
			cout<<"================"<<endl;
			cout<<"��ǰͼ������ͽ������:"<<endl;
			graphnow.showVertex();
			cout<<"��ǰͼ���ڽӾ�������:"<<endl;
			graphnow.showgraph();
			cout<<"������ɾ���ڼ������:"<<0<<"��"<<graphnow.numofVertices()-1<<"֮�� "<<endl;
			cin>>nodestart;
			cout<<"Σ�ղ���!��ȷ����?ȷ����(Y||y)��!���������!"<<endl;
			cin>>yesno;
			if(yesno=='y'||yesno=='Y') {
				flag=graphnow.deleteVertex(nodestart);
				if(flag==1)
					cout<<"���"<<nodestart<<"�Ѿ���ɾ��!"<<endl;
				cout<<"================"<<endl;
				cout<<"��ǰͼ������ͽ������:"<<endl;
				graphnow.showVertex();
				cout<<"��ǰͼ���ڽӾ�������:"<<endl;
				graphnow.showgraph();
			} else
				cout<<"���β����Ѿ�����!!!";
			break;
		case '7':
			if(build==0) {
				cout<<"================"<<endl;
				cout<<"ͼδ���������β���ʧ��!!!"<<endl;
				cout<<"================"<<endl;
				break;
			}
			cout<<"================"<<endl;
			cout<<"��ǰͼ������ͽ������:"<<endl;
			graphnow.showVertex();
			cout<<"��ǰͼ���ڽӾ�������:"<<endl;
			graphnow.showgraph();
			cout<<"������Ҫ��Ӵ��ĸ����nodestart���ĸ����nodeend��ȨֵΪ(weight)��һ����:"<<endl;
			cout<<"����:����0 1 10 ��ʾ�����һ����(��0�Ž�㵽1�Ž�㣬ȨֵΪ10)!:"<<endl;
			cin>>nodestart>>nodeend>>weight;
			flag=graphnow.insertEdge(nodestart,nodeend,weight);
			if(flag==1)
				cout<<"��"<<nodestart<<"�Ž��"<<"��"<<nodeend<<
				    "�Ž��֮���Ѿ������ȨֵΪ"<<weight<<"��һ����!"<<endl<<endl;
			cout<<"��ǰͼ������ͽ������:"<<endl;
			graphnow.showVertex();
			cout<<"��ǰͼ���ڽӾ�������:"<<endl;
			graphnow.showgraph();
			cout<<"================"<<endl;
			break;
		case '8':
			if(build==0) {
				cout<<"================"<<endl;
				cout<<"ͼδ���������β���ʧ��!!!"<<endl;
				cout<<"================"<<endl;
				break;
			}
			cout<<"================"<<endl;
			cout<<"��ǰͼ������ͽ������:"<<endl;
			graphnow.showVertex();
			cout<<"��ǰͼ���ڽӾ�������:"<<endl;
			graphnow.showgraph();
			cout<<"��������Ҫɾ�����ĵ��ĸ����ı�:"<<endl;
			cout<<"����:����0 1��ʾɾ����һ��(��0�Ž�㵽1�Ž��)��һ����!:"<<endl;
			cin>>nodestart>>nodeend;
			cout<<"Σ�ղ���!��ȷ����?ȷ����(Y||y)��!���������!"<<endl;
			cin>>yesno;
			if(yesno=='y'||yesno=='Y') {
				flag=graphnow.deleteEdge(nodestart,nodeend);
				if(flag==1)
					cout<<"�ӽ��"<<nodestart<<"��"<<"���"<<nodeend<<"�ı��ѱ�ɾ��!"<<endl;
				cout<<"��ǰͼ������ͽ������:"<<endl;
				graphnow.showVertex();
				cout<<"��ǰͼ���ڽӾ�������:"<<endl;
				graphnow.showgraph();
				cout<<"================"<<endl;
			} else
				cout<<"���β����Ѿ�����!!!";
			break;
		case '9':
			if(build==0) {
				cout<<"================"<<endl;
				cout<<"ͼδ���������β���ʧ��!!!"<<endl;
				cout<<"================"<<endl;
				break;
			}
			cout<<"================"<<endl;
			cout<<"��ǰͼ������ͽ������:"<<endl;
			graphnow.showVertex();
			cout<<"��ǰͼ���ڽӾ�������:"<<endl;
			graphnow.showgraph();
			cout<<"�˴�Լ���ӵ�һ����㿪ʼ������"<<endl;
			cout<<"������ȱ�������Ϊ :"<<endl;
			visited=new int[graphnow.numofVertices()];
			for(i=0; i<graphnow.numofVertices(); i++) {
				visited[i]=0;
			}
			graphnow.depthfirstsearch(0,visited,printchar);//����ѵ�һ�����Ĭ��Ϊ������ȱ����ĳ�ʼ���
			cout<<endl;
			cout<<"================"<<endl;
			break;
		case 's':
			if(build==0) {
				cout<<"================"<<endl;
				cout<<"ͼδ���������β���ʧ��!!!"<<endl;
				cout<<"================"<<endl;
				break;
			}
			cout<<"================"<<endl;
			cout<<"��ǰͼ������ͽ������:"<<endl;
			graphnow.showVertex();
			cout<<"��ǰͼ���ڽӾ�������:"<<endl;
			graphnow.showgraph();
			cout<<"�˴�Լ���ӵ�һ����㿪ʼ������"<<endl;
			cout<<"������ȱ�������Ϊ :"<<endl;
			visited=new int[graphnow.numofVertices()];
			for(i=0; i<graphnow.numofVertices(); i++)
				visited[i]=0;
			graphnow.breadthfirstsearch(0,visited,printchar);//����ѵ�һ�����Ĭ��Ϊ������ȱ����ĳ�ʼ���
			cout<<endl;
			cout<<"================"<<endl;
			break;
		case '0':
			cout<<"��ѡ�����˳���ллʹ��..."<<endl;
			system("pause");
			exit(1);
		default:
			cout<<"�����д�����������..."<<endl;
	}
}
void Graph() { //���������
	interfacebase interfacenow;
	build=0;
	while (1) {
		interfacenow.showmenu();
		interfacenow.processmenu();
		system("pause");
		system("cls");
	}
}//����������
int main(){
	int n;
	do{
		ShowMainMenu();
		printf("��ѡ��");
		scanf("%d",&n);
		switch(n){
			case 1:LinkList_Show();break;
			case 2:Stack();break;
			case 3:Queue();break;
			case 4:BiTrees();break;
			case 5:Graph();break;
			case 6:break;
			default:printf("ERROR!");break;
		}
	}while(n!=6);
	return 0;
}

