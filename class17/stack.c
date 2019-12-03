#include<stdio.h>
#include<malloc.h>
#include<conio.h>

#define ERROR 0
#define TRUE 1
#define FALSE 0
#define OK 1
#define EQUAL 1
#define OVERFLOW -1
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10

typedef int Status ;

struct STU{
  char name[20];
  char stuno[10];
  int age;
  int score;
};
typedef struct STU SElemType;

struct STACK
{
  SElemType *base;
  SElemType *top;
  int stacksize;
};

typedef struct STACK SqStack;
typedef struct STACK *pSqstack;

Status InitStack(SqStack  **S);
Status DestroyStack(SqStack *S);
Status ClearStack(SqStack *S);
Status StackEmpty(SqStack S);
int StackLength(SqStack S);
Status GetTop(SqStack S,SElemType *e);
Status Push(SqStack *S,SElemType e);
Status Pop(SqStack *S,SElemType *e);
Status StackTraverse(SqStack S,Status (*visit)());

Status InitStack(SqStack **S)
{
  (*S)=(SqStack *) malloc(sizeof(SqStack));
  (*S)->base=(SElemType *)malloc(STACK_INIT_SIZE *sizeof(SElemType));
  if(!(*S)->base)exit(OVERFLOW);
  (*S)->top=(*S)->base;
  (*S)->stacksize=STACK_INIT_SIZE;
  return OK;
}

Status DestroyStack(SqStack *S)
{
 free(S->base);
 free(S);
}

Status ClearStack(SqStack *S)
{
  S->top=S->base;
}

Status StackEmpty(SqStack S)
{
  if(S.top==S.base) return TRUE;
  else
    return FALSE;
}

int StackLength(SqStack S)
{
  int i;
  SElemType *p;
  i=0;
  p=S.top;
  while(p!=S.base)
    {p++;
     i++;
    }
}

Status GetTop(SqStack S,SElemType *e)
{
  if(S.top==S.base) return ERROR;
  *e=*(S.top-1);
  return OK;
}

Status Push(SqStack *S,SElemType e)
{
 /*
  if(S->top - S->base>=S->stacksize)
   {

     S->base=(SElemType *) realloc(S->base,
	    (S->stacksize + STACKINCREMENT) * sizeof(SElemType));
     if(!S->base)exit(OVERFLOW);
     S->top=S->base+S->stacksize;
     S->stacksize += STACKINCREMENT;
   }
  */

  *(S->top++)=e;
  return OK;
}

Status Pop(SqStack *S,SElemType *e)
{
  if(S->top==S->base) return ERROR;
  *e=*--S->top;
  return OK;
}

Status StackPrintElem(SElemType * e)
{
  printf("%s  %s  %d  %d\n",e->name,e->stuno,e->age,e->score);
}
Status StackTraverse(SqStack S,Status (*visit)())
{
  while(S.top!=S.base)
     visit(--S.top);
}

main()
{
  SElemType e;
  SqStack *Sa;

  clrscr();

  printf("\n\n-------------------SqStack Demo is running...----------------\n\n");
  printf("First is Push function.\n");

  InitStack(&Sa);

  strcpy(e.name,"stu1");
  strcpy(e.stuno,"100001");
  e.age=80;
  e.score=1000;

  printf("   Now Stack is Empty.\n");
  StackTraverse(*Sa,StackPrintElem);

  Push(Sa,e);

  printf("   Now Stack has one element.\n");
  StackTraverse(*Sa,StackPrintElem);

  strcpy(e.name,"stu3");
  strcpy(e.stuno,"100002");
  e.age=80;
  e.score=1000;
  Push(Sa,e);
  printf("   Now Stack has another element.\n");
  StackTraverse(*Sa,StackPrintElem);

  printf("   Now Pop Stack,the top elem put into variable e.\n");
  Pop(Sa,&e);
  printf("%s\n%s\n%d\n%d\n",e.name,e.stuno,e.age,e.score);

  printf("   Let's see the left of Stack's elem:\n");
  StackTraverse(*Sa,StackPrintElem);

  getch();
  printf("\n\n\nWelcom to visit http://zmofun.topcool.net\n\n");
}
