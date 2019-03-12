#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node
{
    ElementType Data;
    PtrToNode Next;
};
typedef PtrToNode List;

List Read();        /* 细节在此不表 */
void Print(List L); /* 细节在此不表；空链表将输出NULL */

List Merge(List L1, List L2);

int main()
{
    List L1, L2, L;
    L1 = Read();
    L2 = Read();
    L = Merge(L1, L2);
    Print(L);
    Print(L1);
    Print(L2);
    return 0;
}

List Merge(List L1, List L2)
{
    if (!L1 && !L2)
    {
        return NULL;
    }
    auto L = (List)malloc(sizeof(PtrToNode));//注意List是"Node* "型的指针,不是Node
    List p1 = L1->Next, p2 = L2->Next, p = L;//L1和L2是头指针,注意,头指针是有Data的那个节点的前一个,仅用于找到链表
    while (p1 && p2)
    {//到两个较短的那个停止
        int t = p1->Data - p2->Data;
        if (t >= 0)
        {
            p->Next = p2;
            p2 = p2->Next;
        }
        else
        {
            p->Next = p1;
            p1 = p1->Next;
        }
        p = p->Next;
    }
    if (p1) p->Next = p1;
    else if (p2) p->Next = p2;
    L1->Next = NULL;
    L2->Next = NULL;
    return L;
}