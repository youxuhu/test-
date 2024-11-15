#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node* PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode   Next;
};
typedef PtrToNode List;

List Read(); /* 细节在此不表 */
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

    List Merge(List L1, List L2) {
        List L, P, k1, k2;
        L = (List)malloc(sizeof(struct Node));
        k1 = L1->Next;
        k2 = L2->Next;
        P = L;
        L->Next = NULL;
        while (k1 && k2) 
        {
            if (k1->Data <= k2->Data) 
            {
                P->Next = k1;
                P = k1;
                k1 = k1->Next;
            }
            else 
            {
                P->Next = k2;
                P = k2;
                k2 = k2->Next;
            }
        }
        P->Next = k1 ? k1 : k2;
        L1->Next = NULL;
        L2->Next = NULL;//k1,k2头指针置空
        return L;
    }
