#include <stdio.h>
#include <stdlib.h>
//#include <stdbool.h>

#ifndef BOOL
typedef int BOOL;
#endif

#ifndef TRUE
#define TRUE 1
#endif

#ifndef FALSE
#define FALSE 0
#endif

struct Node
{
    int value;
    struct Node *next;
};
Node  *head;

// 연결 리트 초기화 - 머리를 할당한다. 
void InitList()
{
    head=(Node *)malloc(sizeof(Node));
    head->next=NULL;
}

// Target 다음에 노드를 삽입한다. 
Node *InsertNode(Node *Target, Node *aNode)
{
    Node *New;

    New=(Node *)malloc(sizeof(Node));
    *New=*aNode;

    New->next=Target->next;
    Target->next=New;

    return New;
}

// Target 다음 노드를 삭제한다.
BOOL DeleteNode(Node *Target)
{
     Node *Del;

     Del=Target->next;
     if (Del==NULL) {
          return FALSE;
     }
     Target->next=Del->next;
     free(Del);
     return TRUE;
}

// 연결 리스트의 모든 노드와 머리를 해제한다. 
void UnInitList()
{
    while (DeleteNode(head)){;}

    free(head);
    head=NULL;
}

int main()
{
    int i;
    Node *Now, Temp;

    InitList();

    // 다섯 개의 노드 삽입
    Now=head;
    for (i=1;i<=5;i++) {
        Temp.value=i;
        Now=InsertNode(Now,&Temp);
    }

    // 두 번째 노드 삭제
    DeleteNode(head->next);

    // 순회하면서 출력
    for (Now=head->next;Now;Now=Now->next){
        printf("%d\t", Now->value);
    }
    printf("\n");

    UnInitList();

    return 0;
}