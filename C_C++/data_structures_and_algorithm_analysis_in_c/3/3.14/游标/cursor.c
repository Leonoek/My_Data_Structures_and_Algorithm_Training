#include <stdio.h>
#include <memory.h>
#include "Cursor.h"

struct Node CursorSpace[SPACESIZE];

static Position CursorAlloc(void){
    Position P;
    P = CursorSpace[0].next;
    CursorSpace[0].next = CursorSpace[P].next;
    return P;
}

static void CursorFree(Position P){
    CursorSpace[P].next = CursorSpace[0].next;
    CursorSpace[0].next = P;
}

void InitializeCursorSpaceSpace(void){
    for (int i = 0; i < SPACESIZE; i++)
    {
        CursorSpace[i].element = -1;
        CursorSpace[i].next = i + 1;
    }
}

void PrintCursor(void){
    for (int i = 0; i < SPACESIZE; i++)
    {
        printf("sit: %d, element: %d, next: %d\n", i, CursorSpace[i].element, CursorSpace[i].next);
    }
}

List MakeEmpty(List L){
    for (int i = 0; i < SPACESIZE; i++)
    {
        memset(&CursorSpace[L], 0, sizeof(struct Node));
    }
    return L;
}

int IsEmpty(const List L){
    return CursorSpace[L].element == 0;
}

int IsLast(Position P){
    return CursorSpace[P].next == 0;
}

Position Find(ElementType X, List L){
    Position P = CursorSpace[L].next;
    while (P && CursorSpace[P].element != X)
    {
        P = CursorSpace[P].next;
    }
    return P;
}

Position FindPrevious(List L){
    for (int i = 1; i < SPACESIZE; i++)
    {
        if (CursorSpace[i].next == L)
        {
            return i;
        }
        
    }
    return 0;
}

void Delete(ElementType X, List L){
    Position F = Find(X, L);
    Position P = FindPrevious(F);
    if (IsLast(F))
    {
        CursorSpace[P].next = 0;
    }else{
        CursorSpace[P].next = CursorSpace[F].next;
    }
    CursorSpace[F].element = -1;
    CursorSpace[F].next = 0;
    CursorFree(F);
}

void Insert(ElementType X, Position P){
    Position TmpCell;
    TmpCell = CursorAlloc();
    if (TmpCell == 0)
    {
        FatalError("out of space!!!");
    }
    
    CursorSpace[TmpCell].element = X;
    CursorSpace[TmpCell].next = P;

    P = FindPrevious(P);
    if (P)
    {
        CursorSpace[P].next = TmpCell;
    }
}

Position Create(ElementType X){
    Position P = CursorAlloc();
    CursorSpace[P].element = X;
    CursorSpace[P].next = 0;
    return P;
}

void Add(ElementType X, List L){
    Position TmpCell;
    while (CursorSpace[L].next)
    {
        L = CursorSpace[L].next;
    }
    
    TmpCell = CursorAlloc();
    CursorSpace[L].next = TmpCell;
    CursorSpace[TmpCell].element = X;
    CursorSpace[TmpCell].next = 0;
}