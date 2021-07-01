#include<stdio.h>
#include<stdlib.h>
#define OPNUM 8
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <malloc.h>
#define OK 1
#define ERROR 0
#define MaxSize_SqQueue 50		//定义队列最大长度 
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

//尾插法建立单链表
LinkList List_TailInsert(LinkList &L){
	L = (LinkList)malloc(sizeof(LNode));		//创建头结点 
	L->next = NULL;			//初始为空链表 
	int x;
	LNode *s, *r = L;			//r为表尾指针 
	printf("请输入要插入的元素值：(每输入一个值按回车，输入9999时停止输入)\n");
	scanf("%d", &x);			//输入结点值 
	while(x!=9999){
		s = (LNode*)malloc(sizeof(LNode));			//创建新结点 
		s->data = x;
		r->next = s;
		r = s;
		scanf("%d", &x);
	} 
	r->next = NULL;
	return L;
}

//显示链表中所有元素 
LNode *display(LinkList L){
	LNode *temp = L;
	int count = 0;		
	printf("表中的元素为:\n");
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

//查找结点,在链表中查找输入的元素e，若存在，则返回元素 e的位置
int GetElem(LNode *L){
	printf("请输入要查找的元素：\n");
	int e;
	scanf("%d", &e);
	
	LNode *temp = L;
	int num1 = 1;
	int num2 = 0;
	while(temp->next){
		temp = temp->next;
		if(e == temp->data){
			num2 = num1;
			printf("找到了与%d相同的元素，位置为：%d\n", e, num2);
			return 1;
		}
		num1++;
	} 
	printf("没有找到该元素。");
	return -1;
}

// 修改单链表的第p个位置上的结点 
int replace(LNode *L){
	LNode *temp = L;
	temp = temp->next;
	int p;
	printf("请输入想要修改结点的位置：\n");
	scanf("%d", &p);
	for(int i=1; i<p; ++i){
		temp = temp->next;
	}
	printf("请输入要修改的值：\n");
	int e;
	scanf("%d", &e);
	temp->data = e;
} 

//在链表的第p个位置上插入元素
void insertElem(LNode *L){
	LNode *temp = L;
	printf("请输入要插入元素的位置：\n");
	int p;
	scanf("%d", &p);
	int i = 0;
	while(i<p-1){
		temp = temp->next;
		++i;
	}
	LNode *s = (LNode*)malloc(sizeof(LNode));
	printf("请输入要插入的元素：\n");
	int e;
	scanf("%d", &e);
	s->data = e;
	s->next = temp->next;
	temp->next = s;
} 

//删除单链表中第p个位置的结点
void deleteElem(LNode *L){
	LNode *temp = L;
	printf("请输入想要删除结点的位置：\n");
	int p;
	scanf("%d", &p);
	int i = 0;
	while(i<p-1){			//找到删除结点的上一结点，即第p-1个结点
		temp = temp->next;
		++i;
	}
	LNode *q = temp->next;	//定义一个q指针指向被删除结点 
	int e = NULL;				
	e = q->data;			//保存删除结点的数据域 
	temp->next = q->next;	//删除结点的上一个结点的指针域指向删除结点的下一个结点 
	free(q);				//释放q所指结点的空间 
} 
//单链表运用——多项式相加 
#define NUM 2
#define MAX 100

typedef struct PNode{
	int coef;			//系数 
	int exp;			//指数 
	struct PNode *next; 
}PolyNode;

PolyNode *aL, *bL, *cL;

//显示多项式 
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

//清除一个多项式 
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

//创建多项式 
void createPoly(PolyNode *&L, int arr[][NUM], int xs){			//xs为项数,用二位数组来存放系数和指数 
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

//多项式A和多项式B做加法
void Add(PolyNode *&aL, PolyNode *&bL){
	PolyNode *p, *q, *s;
	q = aL;
	while(q!=NULL){
		p = q;
		q = q->next;
	}
	p->next = bL;
	printf("\n\n连接：");
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
	printf("\n相加处理：");
	DisPoly(aL);
	q = aL;//q指针回到开始
	p = aL;//p指针回到开始
	q = p;
	while(q != NULL){
		if(q->coef == 0 ){
			if(q == aL){				
				aL = q ->next;
				q = aL;//q指针回到开始
				p = aL;//p指针回到开始				
			}else{
				p->next = q->next;
				free(p);
				p = q;		
			}
		}
		p = q;
		q = q->next;
	}
	printf("\n去除零项：");
	DisPoly(aL);	
} 

int LinkList_Apply(){
	int aNUM = 0;
	int bNUM = 0;
	int A[MAX][NUM] = {0};
	int B[MAX][NUM] = {0};
	
	while(1){
		printf("\n请输入多项式A的项数：");
		scanf("%d", &aNUM);
		if(aNUM!=0){
			break;
		}else{
			printf("\n请输入正确的项数!"); 
		}
	}
	for(int i=0; i<aNUM; i++){
		printf("\n第%2d项  系数：",i+1);
		scanf("%d",&A[i][0]);
		printf("指数：");
		scanf("%d",&A[i][1]);
	}
	
	while(1){
		printf("\n请输入多项式B的项数：");
		scanf("%d",&bNUM);
		if(bNUM != 0){
			break;
		}else{
			printf("\n不允许输入 0 项！请重新输入！\n");
		}
	}
	for(int j = 0; j < bNUM; j++){
		printf("\n第%2d项  系数：",j+1);
		scanf("%d",&B[j][0]);
		printf("指数：",j+1);
		scanf("%d",&B[j][1]);
	}
	
	createPoly(aL,A,aNUM); 
	printf("\n原A多项式：");
	DisPoly(aL);

	createPoly(bL,B,bNUM); 
	printf("\n原B多项式：");
	DisPoly(bL);

	printf("\n相加得到的C多项式");
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
		printf("**************单链表的基本操作及应用***************\n");
		printf("* 1  创建                                         *\n");
		printf("* 2  插入                                         *\n");
		printf("* 3  修改                                         *\n");
		printf("* 4  删除                                         *\n");
		printf("* 5  查找                                         *\n");
		printf("* 6  应用                                         *\n");
		printf("* 7  退出                                         *\n");
		printf("***************************************************\n");
		printf("请选择：");
		scanf("%d",&select);
		switch(select){
		case 1:
			printf("--------创建单链表---------\n");
			List_TailInsert(L);
			display(L);
			break;
		case 2:
			printf("--------插入元素-------\n");
			insertElem(L);
			display(L);
			break;
		case 3:
			printf("--------修改元素-------\n");
			replace(L);
			display(L);
			break;
		case 4:
			printf("--------删除元素-------\n");
			deleteElem(L);
			display(L);
			break;
		case 5:
			printf("--------查找元素-------\n");
			GetElem(L);
			break;
		case 6:
		    printf("--------应用---------\n");
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

//————————————————队列————————————————//
typedef struct{
	int *base;		//存储空间的基地址
	int front;		//头指针
	int rear;		//尾指针  
}SqQueue; 

//初始化
bool InitQueue(SqQueue &Q){
	//构造一个空队列
	Q.base = new int[MaxSize_SqQueue];
	if(!Q.base){
		return false;
	} 
	Q.front = Q.rear = 0;
	return true;
} 

//入队
bool EnQueue(SqQueue &Q){
	if((Q.rear+1)%MaxSize_SqQueue==Q.front){		//判断队列是否满了 
		printf("队列已经满了！\n");
		return false;
	}
	int e;
	printf("请输入入队的元素：\n");
	scanf("%d", &e);
	Q.base[Q.rear] = e;
	Q.rear = (Q.rear+1)%MaxSize_SqQueue;
	printf("元素%d成功入队", e);
	return true;
} 

//出队
bool DeQueue(SqQueue &Q, int &e){		//删除Q的队头元素，用e返回其值
	if(Q.front==Q.rear){				//判断队列是否为空 
		printf("队列为空！\n");
		return false;
	}else{
		e = Q.base[Q.front];			//将队头元素保存到e	
		Q.front = (Q.front+1)%MaxSize_SqQueue;
		printf("元素%d已出队。\n", e);
		return true; 
	}
}

//取队头元素 
int GetHead(SqQueue Q){					//返回Q的队头元素，不修改指针 
	if(Q.front==Q.rear){
		printf("队列为空！\n");
		return 0;
	}else{
		printf("队头元素为：%d\n", Q.base[Q.front]);
		return Q.base[Q.front];
	}
}

//取队尾元素
int GetEnd(SqQueue Q){
	if(Q.front==Q.rear){
		printf("队列为空！\n");
		return 0;
	}else{
		printf("队尾元素为：%d\n", Q.rear[Q.base]);
		return 1; 
	}
} 

//应用
//通过队列来打印杨辉三角
#define MaxSize_SqQueue 100

typedef struct{
	int data[MaxSize_SqQueue];		
	int front;			//头指针 
	int rear;			//尾指针 
}SqQueue_Apply;

//初始化 
void InitSqQueue_Apply(SqQueue_Apply *Q){
	Q->front = Q->rear = 0;
}

//入队
int EnSqQueue_Apply(SqQueue_Apply *Q, int x){
	if((Q->rear+1)%MaxSize_SqQueue==Q->front){			//判断队满 
		printf("队列已满！\n");
		return 0;
	}else{
		Q->data[Q->rear] = x;
		Q->rear = (Q->rear+1)%MaxSize_SqQueue;
		return 0;
	}
}

//出队
int DeSqQueue_Apply(SqQueue_Apply *Q, int *x){
	if(Q->front==Q->rear){			//判断队空 
		printf("队列为空！\n");
		return 0; 
	}else{
		*x = Q->data[Q->front];
		Q->front = (Q->front+1)%MaxSize_SqQueue;
		return 0;
	}
} 

//取头元素
int GetTop_SqQueue_Apply(SqQueue_Apply *Q, int *x){
	if(Q->front==Q->rear){
		printf("队列为空！\n");
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
	printf("请输入杨辉三角的行数\n");
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
	printf("*************队列的基本操作及应用**************\n");
	printf("* 1  入列                                     *\n");
	printf("* 2  出列                                     *\n");
	printf("* 3  取队头元素                               *\n");
	printf("* 4  取队尾元素                               *\n");
	printf("* 5  应用                                     *\n");
	printf("* 6  退出                                     *\n");
	printf("***********************************************\n");
	printf("请选择：");
	scanf("%d",&select);
	switch(select){
		case 1:
			printf("---------入列-------\n");
			EnQueue(Q);
			break;
		case 2:
			printf("---------出列-------\n");
			int e;
			DeQueue(Q,e);
			break;
		case 3:
			printf("---------取队头元素-------\n");
			GetHead(Q);
			break;
		case 4:
			printf("---------取队尾元素-------\n");
			GetEnd(Q);
			break;
		case 5:
			printf("---------应用-------\n");
			Queue_Apply();
			break;
		case 6:
			break;
		default:
			printf("ERROR!");break;
	}
	}while(select!=6);
}

 //————————————————栈————————————————//
 typedef int datatype;
//运算符结构体
typedef struct{
	char OPname;  //存储运算符
	int inOP;     //存储栈内级别
	int outOP;    //存储栈外级别
}OP;
//定义运算数栈
typedef struct{
	datatype data[MAXSIZE];
	int top;
}SeqStack;
//定义运算符栈
typedef struct{
	char data[MAXSIZE];
	int top;
}charStack;
char c[50];  //存储输入的字符串
//--------------------以下为栈的操作-----------------------//
//--------------------运算数栈-----------------------//
//初始化栈
SeqStack *Init_SeqStack(){
	SeqStack *s;
	s = (SeqStack *)malloc(sizeof(SeqStack));
    s->top = -1; 
	return s;
}
//判断空栈
int Empty_SeqStack(SeqStack *s){
   if (s->top==-1)
   return 1;
   else  return 0;
}  
//入栈
int Push_SeqStack (SeqStack *s,datatype x){
    if (s->top==MAXSIZE-1){
	 	return 0;
    }else{
		s->top++;
        s->data[s->top]=x;
		return 1;
	}
}
//出栈
int Pop_SeqStack(SeqStack *s,datatype *x){
    if (Empty_SeqStack(s)){
		return 0;
    }else{
		*x=s->data[s->top];
		s->top--;
		return 1;
	}
}
//取栈顶元素
datatype GetSeqTop(SeqStack *s){
    if (Empty_SeqStack(s)){  
		return 0;
    }else{
		return (s->data[s->top]);
	}
}
//--------------------运算符栈-----------------------//
//初始化栈
charStack *Init_charStack(){
	charStack *s;
	s = (charStack *)malloc(sizeof(charStack));
    s->top = -1; 
	return s;
}
//判断空栈
int Empty_charStack(charStack *s){
   if (s->top==-1){
   return 1;
   }else{
		return 0;
	}
}
//入栈
int Push_charStack (charStack *s,char x){
    if (s->top==MAXSIZE-1){
		return 0;
    }else {
		s->top++;
        s->data[s->top]=x;
		return 1;
	}
}
//出栈
int Pop_charStack(charStack *s,char *x){
    if (Empty_charStack(s)){
		return 0;
    }else{
		*x=s->data[s->top];
		s->top--;
		return 1;
	}
}
//取栈顶元素
char GetcharTop(charStack *s){
    if (Empty_charStack(s)){
		return 0;
    }else{
		return (s->data[s->top]);
	}
}

//----------------定义运算符数组-----------------//

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
//-----------------判断是否为运算符-------------------//
int In(char x){
	int i;
	for(i=0;i<=OPNUM;i++){		  	//搜索数组中内容
		if (x==OPPree[i].OPname){ 
		return 1;  					//是运算符返回1
		}
	}
	return 0;  						//不是运算符返回0
}

//-----------------判断优先级------------------------//
char Precede(char x,char c){
	int i,inlev;
	for(i=0;i<=OPNUM;i++){
		if (x==OPPree[i].OPname){
			break;
		}
	}                                 //搜索 x 的下标
	inlev = OPPree[i].inOP;
	for(i=0;i<=OPNUM;i++){
		if (c==OPPree[i].OPname){
		break;
		}
	}  //搜索 c 的下标
	if (inlev < OPPree[i].outOP){
		return '<';  //比较 x 的栈内级别和 c 的栈外级别
	}else if(inlev > OPPree[i].outOP){
		return '>';
	}else{
		return '=';
	}
}

//-------------------计算函数-------------------------//
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

//-----------------中缀表达式运算实现函数----------------------//
int EvaluateExpression(){
	int i=0;
	datatype a,b;
	char x,theta;
	charStack *OPTR;
    SeqStack *OPND;
	OPTR = Init_charStack();  	//运算符栈
	Push_charStack(OPTR, '#');
	OPND = Init_SeqStack();  	//运算数栈
	while(c[i] != '\0'){
		if (!In(c[i])){			//如果不是运算符
			Push_SeqStack(OPND,c[i]-'0');  //入运算数栈
			i++;
		}else{
			switch(Precede(GetcharTop(OPTR),c[i])){
			//如果是运算符,取栈顶元素的栈内级别跟栈外元素的栈外级别比较
				case '<' :
					Push_charStack(OPTR,c[i]);  //小于则入符号栈
					i++;
					break;
				case '=' :
					Pop_charStack(OPTR,&x);  //等于则出栈
					i++;
					break;
				case '>' :
					Pop_charStack(OPTR, &theta);
					Pop_SeqStack(OPND,&b);
					Pop_SeqStack(OPND,&a);  //两个运算数跟一个运算符出栈,进行运算
					Push_SeqStack(OPND,Operate(a,char(theta),b));
					break;
			}
		}
	}
	return GetSeqTop(OPND);
}

//-----------------中缀表达式转换后缀表达式----------------------//
void change(char a[],char s[]){
	int i=0,j=0;
	char temp;
	charStack *OPTR;
	OPTR = Init_charStack();
	Push_charStack(OPTR, '#');
	while(a[i]!='\0'){
		if (!In(a[i])){			//如果不是运算符
			s[j]=a[i];
			j++;
			i++;  				//直接输入到后缀表达式
			continue;
		}else{
			switch(Precede(GetcharTop(OPTR),a[i])){
				case '<' :
					Push_charStack(OPTR,a[i]);  //当栈内级别小于栈外级别的时候入栈
					i++;
					break;
				case '>' :
					while(Precede(GetcharTop(OPTR),a[i])=='>'){		//当栈顶元素大于栈外元素
						Pop_charStack(OPTR, &temp);  //栈顶元素出栈
						s[j]=temp;
						j++;
						temp=GetcharTop(OPTR);  //取栈顶元素继续比较
					}
					break;
				case '=':
					Pop_charStack(OPTR, &temp); //等于就出栈
					i++;
			}
		}
	}
	s[j]='\0';
}

//-----------------后缀表达式运算实现函数----------------------//
int HZcalc(	char s[])  {
	int i=0;
	datatype a,b;
	SeqStack *OPND;
	OPND = Init_SeqStack();  //运算数栈
	while(s[i] != '\0'){
		if (!In(s[i])) {
			Push_SeqStack(OPND,s[i]-'0');  //不是运算符就入运算数栈
			i++;
		}else{
			Pop_SeqStack(OPND,&b);
			Pop_SeqStack(OPND,&a);  //取栈顶两个元素做运算
			Push_SeqStack(OPND,Operate(a,s[i],b));  //运算后把结果入栈
			i++;
		}
	}
	return GetSeqTop(OPND);
}
	


void SqStack_Apply(){
	int i;
	printf("\n");
	printf("请输入表达式，以“#”结束！\n");
	printf("\n");
	printf(" ");
	gets(c);
	printf("\n");
    i=EvaluateExpression();
	char s[50];
    change(c,s);
	printf("中缀表达式求值结果为：%d\n",i);
    printf("后缀表达式为：");
    puts(s);
	i = HZcalc(s);
	printf("后缀表达式求值结果为：%d\n",i);
	printf("\n");
	printf(" 按任意键结束！");
	getchar();
}

typedef struct{
	int *base;
	int *top;
	int stacksize;
}SqStack;

//创建一个栈
int Create_SqStack(SqStack &S){
	S.base = (int*)malloc(MaxSize*sizeof(int));
	if(!S.base){
		printf("存储分配失败!\n");
		return 0;
	}
	S.top = S.base;
	S.stacksize = MaxSize;
	printf("请输入栈元素个数：\n");
	int n;
	scanf("%d", &n);
	printf("输入入栈元素:\n");
	for(int i=1; i<=n; i++){
		scanf("%d", &*S.top);
		S.top++;
	}
}

//显示栈中所有元素
int Display_SqStack(SqStack &S){
	if(S.top==S.base){
		printf("栈为空！");
		return 0;
	}
	int *p;
	p = S.top;
	printf("栈中元素为：\n");
	while(p>S.base){
		p--;
		printf("%d\t", *p);
	}
	printf("\n");
} 
	
//入栈
int Push(SqStack &S){
	int e;
	printf("请输入要入栈的元素:\n");
	scanf("%d", &e);
	if(S.top-S.base>=S.stacksize){
		S.base = (int*)realloc(S.base,(S.stacksize+SIZE)*sizeof(int));
		if(!S.base){
			printf("存储分配失败！");
			return 0;
		}
		S.top = S.base + S.stacksize;
		S.stacksize+=SIZE;
	}
	*S.top++=e;
} 
	
//出栈
int Pop(SqStack &S){
	int e;
	if(S.top==S.base){
		printf("栈为空！\n");
		return 0;
	}else{
		e=*--S.top;
		printf("出栈的元素为：%d", e);
		return 0;
	}
} 
	
//取栈顶元素
int GetTop(SqStack S, int& e)
{
	if (S.top == S.base)
	{
		printf("栈为空！\n");
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
		printf("****************栈的基本操作及应用*****************\n");
		printf("* 1  创建栈                                       *\n");
		printf("* 2  进栈                                         *\n");
		printf("* 3  出栈                                         *\n");
		printf("* 4  取栈顶元素                                   *\n");
		printf("* 5  应用                                         *\n");
		printf("* 6  退出                                         *\n");
		printf("***************************************************\n");
		printf("请选择：");
		scanf("%d",&select);
		switch(select){
			case 1:
				printf("--------创建栈-------\n");
				Create_SqStack(S);
				printf("\n");
				Display_SqStack(S);
				break;
			case 2:
				printf("--------进栈-------\n"); 
				Push(S);
				printf("\n");
				Display_SqStack(S);
				break;
			case 3:
				printf("--------出栈-------\n");
				Pop(S);
				printf("\n");
				Display_SqStack(S);
				break;
			case 4:
				printf("--------取栈顶元素-------\n");
				int e;
				GetTop(S, e);
				printf("栈顶元素为：%d", e);
				break;
			case 5:
				printf("--------应用-------\n");
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
 
 //定义二叉树结构体
typedef struct BiTNode{
	char data;
	struct BiTNode *lchild;
	struct BiTNode *rchild;
}BiTNode, *BiTree;

//创建二叉树
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

//先序遍历
int PreOrder(BiTree T, int(*Visit)(char e)){
	if(T==0){
		return 0;
	}
	cout<<(T->data);
	PreOrder(T->lchild, Visit);
	PreOrder(T->rchild, Visit);
	return 1;
}
//中序遍历
int InOrder(BiTree T, int(*Visit)(char e)){
	if(T==0){
		return 0;
	}
	InOrder(T->lchild, Visit);
	cout<<(T->data);
	InOrder(T->rchild, Visit);
	return 1;
} 
//后序遍历
int PostOrder(BiTree T, int (*Visit)(char e)){
	if(T==0){
		return 0;
	}
	PostOrder(T->lchild, Visit);
	PostOrder(T->rchild, Visit);
	cout<<(T->data);
	return 1;
} 

//输出 
int Print_Element(char e){
	cout<<e;
	return 1;
}

//求二叉树的深度
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

//求二叉树的叶子结点数
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

//查找结点的双亲 
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

//查找结点的兄弟
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
	printf("**************二叉树的基本操作及应用***************\n");
	printf("* 1  创建                                         *\n");
	printf("* 2  遍历（先/中/后）                             *\n");
	printf("* 3  求结点个数                                   *\n");
	printf("* 4  求树的深度                                   *\n");
	printf("* 5  查找双亲                                     *\n");
	printf("* 6  查找兄弟（左/右）                            *\n");
	printf("* 7  退出                                         *\n");
	printf("***************************************************\n");
	printf("请选择：");
	scanf("%d",&select);
	switch(select){
		case 1:
			printf("---------创建--------\n");
			T=NULL;
			printf("请输入二叉树元素：(用$表示空)\n");
			CreateBiTree(T);
			break;
		case 2:
			printf("---------遍历（先/中/后）-------\n");
			printf("\n按先序遍历法输出该二叉树的元素为："); PreOrder(T, Print_Element);
			printf("\n按中序遍历法输出该二叉树的元素为："); InOrder(T, Print_Element);
			printf("\n按后序遍历法输出该二叉树的元素为："); PostOrder(T, Print_Element);
			break;
		case 3:
			printf("---------求结点个数-------\n");
			num = Leave(T);
			printf("二叉树叶子结点个数为：");
			cout<<num;
			break;
		case 4:
			printf("---------求树的深度-------\n");
			height = Height(T);
			printf("二叉树的深度为：");cout<<height;
			break;
		case 5:
			printf("---------查找双亲-------\n");
			printf("请输入要查找的结点：");
			cin>>e;
			m = Parent(T,e);
			printf("该结点 的双亲为：");
			cout<<m;
			break;
		case 6:
			printf("---------查找兄弟（左/右）-------\n");
			printf("请输入要查找的结点：");
			cin>>e;
			m = Brother(T, e);
			printf("该结点的兄弟为：");
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
	printf("*******************算法与数据结构******************\n");
	printf("* 1  单链表的基本操作及应用                       *\n");
	printf("* 2  栈的基本操作及应用                           *\n");
	printf("* 3  队列的基本操作及应用                         *\n");
	printf("* 4  二叉树的基本操作及应用                       *\n");
	printf("* 5  图的基本操作及应用                           *\n");
	printf("* 6  退出                                         *\n");
	printf("***************************************************\n");
}


//图的操作 
using namespace std;
enum returninfo {success,fail,overflow,underflow,nolchild,norchild,nofather,havesonl,havesonr,
                 haveason,havetwosons,range_error,quit
                };	//定义返回信息清单
int build;//用于控制是否是重建图，为0时表示第一次建立图，为1时表示重建图
/************************************************************/
//顺序表类 把图中结点用顺序表来存储解决图中结点的动态插删问题
const int MaxListSize=26;//约定本顺序表最多只存26个字母
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
SeqList::SeqList() { //顺序表的构造函数
	size=0;
}
SeqList::~SeqList() {} //顺序表的析构函数
int SeqList::ListSize()const { //求顺序表的结点个数的函数
	return size;
}
int SeqList::ListEmpty()const { //判断顺序表是否为空的函数
	if(size==0)
		return 1;
	else
		return 0;
}
int SeqList::Find(char &item)const { //查找某个结点的函数
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
char SeqList::Getdata(int pos)const { //读取某个位置结点的函数
	if(pos<0||pos>size-1) {
		cout<<"对不起!位置参数越界出错!"<<endl;
		return(false);
	}
	return node[pos];
}
void SeqList::Insert(const char &item,int pos) { //插入一个结点到顺序表中
	int i;
	if(size==MaxListSize) {
		cout<<"顺序表已满无法插入!"<<endl;
		return;
	} else if(pos<0||pos>size) { //插入在最后一个元素右边是合法的
		cout<<"对不起!位置参数越界出错!"<<endl;
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
//从顺序表中删除一个结点
int SeqList::Delete(const int pos) {
	if(size==0) {
		cout<<"顺序表已空无法删除!"<<endl;
		return 0;
	} else if(pos<0||pos>size-1) {
		cout<<"对不起!位置参数越界出错!"<<endl;
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
void SeqList::ClearList() { //销毁整个顺序表
	size=0;
}
/***************************************************************************/
//队列类：解决图的广度优先遍历
const int maxsize=100;
//定义了循环队列的类
class SeqQueue {
	private:
		char queuedata[maxsize];//限制最多的元素个数
		int  front;//定义一个队首指针
		int  rear;//定义一个队尾指针
		int  count;//元素个数计数器
	public:
		SeqQueue(void);//构造函数
		~SeqQueue() {}; //析构函数
		int  isempty()const {
			return front==rear;
		}
		void enqueue(const char&item);//元素入队函数
		char dequeue();//出队函数
		void showseq();//遍历函数
		void getfront();//返回头结点的函数
};
SeqQueue::SeqQueue() {
	front=0;//头尾指针各占一个空间，那么总的可以储存的元素的个数为maxsize-1
	rear =0;
	count=0;//计数器开始为0
}
void SeqQueue::enqueue(const char&item) {
	if(front==(rear+1)%maxsize) { //队列满的条件
		cout<<"对不起!队列已满!无法添加!"<<endl;
	} else {
		queuedata[rear]=item;//否则元素从队尾入队
		rear=(rear+1)%maxsize;//队尾先加一后取模
		count++;//计数器加一
	}
}
char SeqQueue::dequeue() {
	if(count==0) { //队列为空的条件
		cout<<"对不起!队列已空!无法删除!"<<endl;
		return false;
	} else {
		char datatemp=queuedata[front];//否则元素从队头出队
		front=(front+1)%maxsize;//队头后移
		count--;//元素个数减一
		return datatemp;
	}
}
void SeqQueue::showseq() {
	cout<<"队列全部元素如下:"<<endl;
	for(int i=front; i!=rear;) { //队首并未存储元素故要从front开始遍历
		cout<<" "<<queuedata[i];
		i=(i+1)%maxsize;
	}
	cout<<endl;
	cout<<"当前元素个数为: "<<count<<endl;
	cout<<endl;
}
void SeqQueue::getfront() {
	if(count==0) { //队列为空的条件
		cout<<"对不起!队列已空!"<<endl;
		return;
	} else {
		cout<<"队头的元素的值为 :"<<queuedata[front]<<endl;
	}
}
/////////////
//图类
const int maxvertices=26;//定义结点个数最大值为26
const int maxweight=10000;//当两个结点之间不存在边时距离无穷大用10000来模拟
class graph {
	private://图的数据结构，细节可以参见教材
		int i,j;
		int flag;
		int inputnodenum,inputedgenum;
		int numofedges;
		char *nodearray;
		SeqList Vertices;
		int Edge[maxvertices][maxvertices];
	public:
		graph(const int size=maxvertices);					//图的构造函数
		~graph() {};											//图的析构函数
		void initializationofEdge(int size);				//边的邻接矩阵初始化
		void inputdata();									//手工输入数据
		void defaultdata();									//启用默认数据
		void showgraph();									//显示图的邻接矩阵
		void showVertex();									//显示图的结点
		int  graphempty()const {
			return Vertices.ListEmpty();   //判断图是否为空
		}
		int  numofVertices() {
			return Vertices.ListSize();   //求图的结点个数
		}
		int  numofEdges(void) {
			return numofedges;   //求图的边数
		}
		char getvalue(const int i);							//求取图某个结点的值
		int  getweight(const int nodestart,const int nodeend);//求两个结点之间的边的权值
		void insertVertices(const char& vertices);			//向图中添加一个结点
		int  deleteVertex(const int v);						//删除一个结点
		int  insertEdge(const int nodestart,const int nodeend,int weight);//添加一条边
		int  deleteEdge(const int nodestart,const int nodeend);//删除一条边
		int  getfirstneighbor(const int v);//为实现图的遍历而必须定义的求取其第一个相邻结点的函数
		int  getnextneighbor(const int nodestart,const int nodeend);//求取其下一个相邻结点的函数
		void depthfirstsearch(const int v,int visited[],void visit(char item));//深的优先遍历
		void breadthfirstsearch(const int v,int visited[],void visit(char item));//广度优先遍历
};
graph::graph(const int size) { //图的构造函数
	initializationofEdge(maxvertices);
}
void graph::initializationofEdge(int size) { //边的邻接矩阵初始化
	for(int i=0; i<size; i++) { //邻接矩阵的初始化
		for(int j=0; j<size; j++)
			if(i==j) {
				Edge[i][j]=0;//两个相同结点之间的边的权值为0
			} else
				Edge[i][j]=maxweight;//初始状态不同结点之间不存在边，权值无穷大用10000来表示
	}
	numofedges=0;//初始状态边的条数为0
}
void graph::inputdata(void) {
	int nodestart,nodeend,weight;//起始点、终止点、权值
	Vertices.ClearList();//结点数组清空
	initializationofEdge(maxvertices);
//	cout<<"本程序兼容有向图和无向图。"<<endl;
	cout<<"如果希望构建无向图，每条边需要输入两次，即(a,b)和(b.a)"<<endl;
	cout<<"下面添加结点信息!"<<endl;
	cout<<"----------------"<<endl;
	cout<<"请输入结点个数(小于 "<<maxvertices<<"):";
	cin>>inputnodenum;
	nodearray=new char[inputnodenum];//建立字符数组
	cout<<"请输入"<<inputnodenum<<"个结点(单个Ascii码字符)，空格隔开，输入完毕后回车:"<<endl;
	for(i=0; i<inputnodenum; i++) {
		cin>>nodearray[i];
		insertVertices(nodearray[i]);
	}
	cout<<inputnodenum<<"个结点已经添加成功了!字符的的默认编号是:"<<endl;
	for(i=0; i<inputnodenum; i++) //显示对应坐标
		cout<<setw(5)<<i;
	cout<<endl;
	for(i=0; i<inputnodenum; i++) //显示数组中字符
		cout<<setw(5)<<nodearray[i];
	cout<<endl<<endl;
	cout<<"下面添加边信息!"<<endl;
	cout<<"---------------"<<endl;
	cout<<"请输入边数: ";
	cin>>inputedgenum;
	cout<<"例如:1 2 10 表示添加了一条边(从1号结点到2号结点，权值为10)!:"<<endl;
	for(i=0; i<inputedgenum; i++) {
		cout<<"下面添加第"<<i+1<<"条边的信息: "<<endl;
		cin>>nodestart>>nodeend>>weight;
		flag=insertEdge(nodestart,nodeend,weight);
		if(flag==1)
			cout<<"从"<<nodestart<<"号结点"<<"到"<<nodeend<<"号结点之间已经添加了权值为"
			    <<weight<<"的一条边!"<<endl<<endl;
	}
	cout<<"图已经建立!"<<endl;
	delete[] nodearray;
	build=1;
}
void graph::showgraph() { //图的显示函数
	for(i=0; i<Vertices.ListSize(); i++) { //用邻接矩阵来模拟图的边的相关信息
		for(j=0; j<Vertices.ListSize(); j++) {
			if(getweight(i,j)==maxweight)
				cout<<setw(5)<<"∞";
			else
				cout<<setw(5)<<getweight(i,j);
		}
		cout<<endl;
	}
}
void graph::showVertex() { //显示图的结点
	for(i=0; i<Vertices.ListSize(); i++) //显示坐标
		cout<<setw(5)<<i;
	cout<<endl;
	for(i=0; i<Vertices.ListSize(); i++) //显示数据
		cout<<setw(5)<<Vertices.Getdata(i);
	cout<<endl;
}
char graph::getvalue(const int i) { //求取图的某个结点的值
	if(i<0||i>Vertices.ListSize()) {
		cout<<"对不起参数越界出错!"<<endl;
		return false;
	} else
		return Vertices.Getdata(i);//采用顺序表的操作达成目标
}
int graph::getweight(const int nodestart,const int nodeend) { //求两个结点之间的边的权值
	if(nodestart<0||nodestart>Vertices.ListSize()||nodeend<0||nodeend>Vertices.ListSize()) {
		cout<<"对不起参数越界出错!"<<endl;
		return false;
	} else
		return Edge[nodestart][nodeend];
}
void graph::insertVertices(const char& vertices) { //添加一个结点
	Vertices.Insert(vertices,Vertices.ListSize());//为了简单把添加结点放在顺序表的最后位置
}
int graph::deleteVertex(const int v) { //删除一个结点
	for(int i=0; i<Vertices.ListSize(); i++) //删除结点必须把与这个结点相关联的全部的边首先删除
		for(int j=0; j<Vertices.ListSize(); j++) {
			if(i==v||j==v && Edge[i][j]>0 && Edge[i][j]<maxweight) {
				Edge[i][j]=maxweight;
				numofedges--;
			}
		}
	int flag=Vertices.Delete(v);
	if(flag==1)//提供一个标志位为后面的调用方便
		return 1;
	else
		return 0;
}
int graph::insertEdge(const int nodestart,const int nodeend,int weight) { //添加一条边
	if(nodestart<0||nodestart>Vertices.ListSize()||nodeend<0||nodeend>Vertices.ListSize()) {
		cout<<"对不起参数越界出错!"<<endl;
		return 0;
	} else {
		Edge[nodestart][nodeend]=weight;
		numofedges++;
		return 1;
	}
}
int graph::deleteEdge(const int nodestart,const int nodeend) { //删除一条边
	if(nodestart<0||nodestart>Vertices.ListSize()||nodeend<0||nodeend>Vertices.ListSize()) {
		cout<<"对不起参数越界出错!"<<endl;
		return 0;
	} else {
		Edge[nodestart][nodeend]=maxweight;
		numofedges--;
		return 1;
	}
}
int graph::getfirstneighbor(const int v) { //求取其第一个相邻结边
	if(v<0||v>Vertices.ListSize()) {
		cout<<"对不起参数越界出错!"<<endl;
		return false;
	} else {
		for(int col=0; col<=Vertices.ListSize(); col++) {
			if(Edge[v][col]>0 && Edge[v][col]<maxsize)
				return col;//若存在相邻的结点返回其下标
		}
		return -1;//否则返回-1
	}
}
int graph::getnextneighbor(const int nodestart,const int nodeend) { //求取其下一条邻接边
	//找结点nodestart的<nodestart,nodeend>邻接边的下一条邻接边
	if(nodestart<0||nodestart>Vertices.ListSize()||nodeend<0||nodeend>Vertices.ListSize()) {
		cout<<"对不起参数越界出错!"<<endl;
		return false;
	} else {
		//使col为nodeend+1因此寻找的边是nodestart的<nodestart,nodeend>邻接边的下一条邻接边
		for(int col=nodeend+1; col<=Vertices.ListSize(); col++) {
			if(Edge[nodestart][col]>0&&Edge[nodestart][col]<maxsize)
				return col;
		}
		return -1;
	}
}
void graph::depthfirstsearch(const int startpoint,int visited[],void visit(char item)) { //深度优先遍历
	int neighborpoint;
	visit(getvalue(startpoint));
	visited[startpoint]=1;
	neighborpoint=getfirstneighbor(startpoint);
	while(neighborpoint!=-1) {
		if(!visited[neighborpoint])
			depthfirstsearch(neighborpoint,visited,visit);
		neighborpoint=getnextneighbor(startpoint,neighborpoint);
	}
//深度优先遍历实现代码
}
void graph::breadthfirstsearch(const int startpoint,int visited[],void visit(char item)) { //广度优先遍历
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
//广度优先遍历实现代码
}
void printchar(char item) {
	cout<<setw(5)<<item;
}
////////////////
//界面处理对象：界面库
class interfacebase {
	private:
		int i;							//循环变量
		int nodestart,nodeend,weight;	//起始点、终止点、权值
		int flag;						//标志位
		graph graphnow;					//图对象的实例化
	public:
		void showmenu(void);
		void processmenu(void);
};
void interfacebase::showmenu(void) {
	cout<<"****************图的基本操作及应用*****************"<<endl;
	cout<<"1.手工建立（有向）图				 "<<endl;
	cout<<"2.用邻接矩阵形式显示图			 "<<endl;
	cout<<"3.求图的结点数和边数 			 "<<endl;
	cout<<"4.求某条边的权值 				 "<<endl;
	cout<<"5.添加结点                        "<<endl;
	cout<<"6.删除结点   			         "<<endl;
	cout<<"7.添加边  						 "<<endl;
	cout<<"8.删除边 						 "<<endl;
	cout<<"9.深度优先遍历图					 "<<endl;
	cout<<"s.广度优先遍历图					 "<<endl;
	cout<<"0.退出							 "<<endl;
	cout<<"***************************************************"<<endl;
}
void interfacebase::processmenu() {
	char choice,yesno;			//用于用户选择菜单选项
	char newnode;
	int *visited;
	cout<<"请输入选项：";
	cin>>choice;
	switch(choice) {
		case '1':
			cout<<"================"<<endl;
			if(build==1) {
				cout<<"危险操作，原有数据将被删除!你确定吗?确定按(Y||y)键!否则按任意键!"<<endl;
				cin>>yesno;
				if(yesno!='y' && yesno!='Y') {
					cout<<"已经取消建立图!"<<endl;
					break;
				}
			}
			graphnow.inputdata();
			cout<<"================"<<endl;
			break;
		case '2':
			if(build==0) {
				cout<<"================"<<endl;
				cout<<"图未建立，本次操作失败!!!"<<endl;
				cout<<"================"<<endl;
				break;
			}
			cout<<"================"<<endl;
			cout<<"当前图的坐标和结点如下:"<<endl;
			graphnow.showVertex();
			cout<<"当前图的邻接矩阵如下:"<<endl;
			graphnow.showgraph();
			cout<<"================"<<endl;
			break;
		case '3':
			if(build==0) {
				cout<<"================"<<endl;
				cout<<"图未建立，本次操作失败!!!"<<endl;
				cout<<"================"<<endl;
				break;
			}
			cout<<"================"<<endl;
			cout<<"当前图的坐标和结点如下:"<<endl;
			graphnow.showVertex();
			cout<<"当前图的邻接矩阵如下:"<<endl;
			graphnow.showgraph();
			cout<<"当前结点个数为 :";
			cout<<graphnow.numofVertices();
			cout<<endl;
			cout<<"当前图的边数为 :";
			cout<<graphnow.numofEdges();
			cout<<endl;
			cout<<"================"<<endl;
			break;
		case '4':
			if(build==0) {
				cout<<"================"<<endl;
				cout<<"图未建立，本次操作失败!!!"<<endl;
				cout<<"================"<<endl;
				break;
			}
			cout<<"================"<<endl;
			cout<<"当前图的坐标和结点如下:"<<endl;
			graphnow.showVertex();
			cout<<"当前图的邻接矩阵如下:"<<endl;
			graphnow.showgraph();
			cout<<"请输入你要读取从哪个结点到哪个结点之间的边的权值:"<<endl;
			cout<<"注意：最小下标从0开始。"<<endl;
			cout<<"例如:输入0 1表示读取(从0号结点到1号结点)的边的权值!:"<<endl;
			cin>>nodestart>>nodeend;
			weight=graphnow.getweight(nodestart,nodeend);
			if(weight==maxweight) {
				cout<<"结点"<<nodestart<<"与"<<nodeend<<"即代表下面的结点!!!"<<endl;
				cout<<"结点"<<graphnow.getvalue(nodestart)
				    <<"与"<<graphnow.getvalue(nodeend)<<"之间的边的权值为: ∞"<<endl;
			} else {
				cout<<"结点"<<nodestart<<"与"<<nodeend<<"即代表下面的结点!!!"<<endl;
				cout<<"结点"<<graphnow.getvalue(nodestart)
				    <<"与"<<graphnow.getvalue(nodeend)<<"之间的边的权值为: "<<weight<<endl;
			}
			cout<<"================"<<endl;
			break;
		case '5':
			if(build==0) {
				cout<<"================"<<endl;
				cout<<"图未建立，本次操作失败!!!"<<endl;
				cout<<"================"<<endl;
				break;
			}
			cout<<"================"<<endl;
			cout<<"当前图的坐标和结点如下:"<<endl;
			graphnow.showVertex();
			cout<<"当前图的邻接矩阵如下:"<<endl;
			graphnow.showgraph();
			cout<<"请输入添加的结点的值(char)型:"<<endl;
			cin>>newnode;
			graphnow.insertVertices(newnode);
			cout<<"结点"<<newnode<<"已经添加!"<<endl;
			cout<<"当前图的坐标和结点如下:"<<endl;
			graphnow.showVertex();
			cout<<"当前图的邻接矩阵如下:"<<endl;
			graphnow.showgraph();
			cout<<"================"<<endl;
			break;
		case '6':
			if(build==0) {
				cout<<"================"<<endl;
				cout<<"图未建立，本次操作失败!!!"<<endl;
				cout<<"================"<<endl;
				break;
			}
			cout<<"================"<<endl;
			cout<<"当前图的坐标和结点如下:"<<endl;
			graphnow.showVertex();
			cout<<"当前图的邻接矩阵如下:"<<endl;
			graphnow.showgraph();
			cout<<"请输入删除第几个结点:"<<0<<"到"<<graphnow.numofVertices()-1<<"之间 "<<endl;
			cin>>nodestart;
			cout<<"危险操作!你确定吗?确定按(Y||y)键!否则按任意键!"<<endl;
			cin>>yesno;
			if(yesno=='y'||yesno=='Y') {
				flag=graphnow.deleteVertex(nodestart);
				if(flag==1)
					cout<<"结点"<<nodestart<<"已经被删除!"<<endl;
				cout<<"================"<<endl;
				cout<<"当前图的坐标和结点如下:"<<endl;
				graphnow.showVertex();
				cout<<"当前图的邻接矩阵如下:"<<endl;
				graphnow.showgraph();
			} else
				cout<<"本次操作已经放弃!!!";
			break;
		case '7':
			if(build==0) {
				cout<<"================"<<endl;
				cout<<"图未建立，本次操作失败!!!"<<endl;
				cout<<"================"<<endl;
				break;
			}
			cout<<"================"<<endl;
			cout<<"当前图的坐标和结点如下:"<<endl;
			graphnow.showVertex();
			cout<<"当前图的邻接矩阵如下:"<<endl;
			graphnow.showgraph();
			cout<<"请输入要添加从哪个结点nodestart到哪个结点nodeend的权值为(weight)的一条边:"<<endl;
			cout<<"例如:输入0 1 10 表示添加了一条边(从0号结点到1号结点，权值为10)!:"<<endl;
			cin>>nodestart>>nodeend>>weight;
			flag=graphnow.insertEdge(nodestart,nodeend,weight);
			if(flag==1)
				cout<<"从"<<nodestart<<"号结点"<<"到"<<nodeend<<
				    "号结点之间已经添加了权值为"<<weight<<"的一条边!"<<endl<<endl;
			cout<<"当前图的坐标和结点如下:"<<endl;
			graphnow.showVertex();
			cout<<"当前图的邻接矩阵如下:"<<endl;
			graphnow.showgraph();
			cout<<"================"<<endl;
			break;
		case '8':
			if(build==0) {
				cout<<"================"<<endl;
				cout<<"图未建立，本次操作失败!!!"<<endl;
				cout<<"================"<<endl;
				break;
			}
			cout<<"================"<<endl;
			cout<<"当前图的坐标和结点如下:"<<endl;
			graphnow.showVertex();
			cout<<"当前图的邻接矩阵如下:"<<endl;
			graphnow.showgraph();
			cout<<"请输入你要删除从哪到哪个结点的边:"<<endl;
			cout<<"例如:输入0 1表示删除了一条(从0号结点到1号结点)的一条边!:"<<endl;
			cin>>nodestart>>nodeend;
			cout<<"危险操作!你确定吗?确定按(Y||y)键!否则按任意键!"<<endl;
			cin>>yesno;
			if(yesno=='y'||yesno=='Y') {
				flag=graphnow.deleteEdge(nodestart,nodeend);
				if(flag==1)
					cout<<"从结点"<<nodestart<<"到"<<"结点"<<nodeend<<"的边已被删除!"<<endl;
				cout<<"当前图的坐标和结点如下:"<<endl;
				graphnow.showVertex();
				cout<<"当前图的邻接矩阵如下:"<<endl;
				graphnow.showgraph();
				cout<<"================"<<endl;
			} else
				cout<<"本次操作已经放弃!!!";
			break;
		case '9':
			if(build==0) {
				cout<<"================"<<endl;
				cout<<"图未建立，本次操作失败!!!"<<endl;
				cout<<"================"<<endl;
				break;
			}
			cout<<"================"<<endl;
			cout<<"当前图的坐标和结点如下:"<<endl;
			graphnow.showVertex();
			cout<<"当前图的邻接矩阵如下:"<<endl;
			graphnow.showgraph();
			cout<<"此处约定从第一个结点开始遍历。"<<endl;
			cout<<"深度优先遍历序列为 :"<<endl;
			visited=new int[graphnow.numofVertices()];
			for(i=0; i<graphnow.numofVertices(); i++) {
				visited[i]=0;
			}
			graphnow.depthfirstsearch(0,visited,printchar);//这里把第一个结点默认为深度优先遍历的初始结点
			cout<<endl;
			cout<<"================"<<endl;
			break;
		case 's':
			if(build==0) {
				cout<<"================"<<endl;
				cout<<"图未建立，本次操作失败!!!"<<endl;
				cout<<"================"<<endl;
				break;
			}
			cout<<"================"<<endl;
			cout<<"当前图的坐标和结点如下:"<<endl;
			graphnow.showVertex();
			cout<<"当前图的邻接矩阵如下:"<<endl;
			graphnow.showgraph();
			cout<<"此处约定从第一个结点开始遍历。"<<endl;
			cout<<"广度优先遍历序列为 :"<<endl;
			visited=new int[graphnow.numofVertices()];
			for(i=0; i<graphnow.numofVertices(); i++)
				visited[i]=0;
			graphnow.breadthfirstsearch(0,visited,printchar);//这里把第一个结点默认为广度优先遍历的初始结点
			cout<<endl;
			cout<<"================"<<endl;
			break;
		case '0':
			cout<<"您选择了退出，谢谢使用..."<<endl;
			system("pause");
			exit(1);
		default:
			cout<<"输入有错，请重新输入..."<<endl;
	}
}
void Graph() { //程序主入口
	interfacebase interfacenow;
	build=0;
	while (1) {
		interfacenow.showmenu();
		interfacenow.processmenu();
		system("pause");
		system("cls");
	}
}//主函数结束
int main(){
	int n;
	do{
		ShowMainMenu();
		printf("请选择：");
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

