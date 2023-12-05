#include <stdio.h>
#include <stdlib.h>

#ifndef BOOL
typedef int BOOL;
#endif

#ifndef TRUE
#define TRUE 1
#endif

#ifndef FALSE
#define FALSE 0
#endif

// 노드 구조체

struct Node
{
     int value;
     Node *prev;
     Node *next;
};

Node *head;


// 연결 리스트 초기화 - 머리를 할당한다.
void InitList()
{
     head=(Node *)malloc(sizeof(Node));
     head->prev=NULL;
     head->next=NULL;
}

// 지정한 노드의 오른쪽에 삽입한다.
Node *InsertNodeRight(Node *Target,Node *aNode)
{
     Node *New;
     Node *Right;
     New=(Node *)malloc(sizeof(Node));
     *New=*aNode;
     Right=Target->next;
     New->next=Right;
     New->prev=Target;
     Target->next=New;
     if (Right) {
          Right->prev=New;
     }
     return New;
}

// 지정한 노드의 왼쪽에 삽입한다.
Node *InsertNodeLeft(Node *Target,Node *aNode)
{
     Node *Left;

     Left=Target->prev;
     if (Left) {
          return InsertNodeRight(Left,aNode);
     }
     return NULL;
}

// 제일 끝에 노드를 추가한다.
void AppendNode(Node *aNode)
{
     Node *tail;
     for (tail=head;tail->next;tail=tail->next) {;}
     InsertNodeRight(tail,aNode);
}

// 단순 연결 리스트와는 달리 자기 자신을 지울 수 있다.
BOOL DeleteNode(Node *Target)
{
     Node *Left,*Right;
     // 헤더는 지울 수 없음
     if (Target==NULL || Target==head) {
          return FALSE;
     }
     Left=Target->prev;
     Right=Target->next;
     Left->next=Right;
     if (Right) {                   // 타겟이 끝 노드일 경우
          Right->prev=Left;
     }
     free(Target);
     return TRUE;
}

// idx번째 노드를 찾는다.
Node *FindNodeByIndex(int idx)
{
     Node *Now;
     int Index=0;
     for (Now=head->next;Now;Now=Now->next) {
          if (Index == idx) {
              return Now;
          }
          Index++;
     }
     return NULL;
}

// 노드의 순서값을 구한다.
int GetNodeIndex(Node *Target)
{
     Node *Now;
     int Index=0;

     for (Now=head->next;Now;Now=Now->next) {
          if (Now == Target) {
              return Index;
          }
          Index++;
     }
     return -1;
}

// 노드의 개수를 조사한다.
int GetListCount()
{
     Node *Now;
     int Count=0;
     for (Now=head->next;Now;Now=Now->next) {
          Count++;
     }
     return Count;
}

// 연결 리스트의 모든 노드와 머리를 해제한다.
void UnInitList()
{
     while (DeleteNode(head->next)) {;}
     free(head);
     head=NULL;
}

int main()
{
     int i;
     Node *Now,Temp;
     InitList();
     for (i=1;i<=5;i++) {
          Temp.value=i;
          AppendNode(&Temp);
     }

     // 순회하면서 출력
     for (Now=head->next;Now;Now=Now->next) {
          printf("%d\t",Now->value);
     }
     printf("\n");

     // 개수, 데이터 3을 가진 노드와 앞뒤 노드를 조사한다.
     printf("노드 개수 = %d\n",GetListCount());
     for (Now=head->next;Now;Now=Now->next) {
          if (Now->value == 3) break;
     }

     if (Now) {
          printf("Mid=%d, 앞 노드=%d, 뒷 노드=%d\n",Now->value,
              Now->prev->value,Now->next->value);
     }

     printf("3번 노드 = %d\n", FindNodeByIndex(3)->value);
     UnInitList();
}
