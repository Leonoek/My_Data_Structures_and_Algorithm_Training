#ifndef CursorSpace_H
#define CursorSpace_H

#define SPACESIZE 10

#if defined(WIN32) || defined(_WIN32) || defined(_WIN32_) || defined(WIN64) || defined(_WIN64) || defined(_WIN64_)
#define FatalError printf //Windows平台
#elif defined(ANDROID) || defined(_ANDROID_)
 //Android平台
#elif defined(__linux__)
#define FatalError printf //Linux平台
#elif defined(__APPLE__) || defined(TARGET_OS_IPHONE) || defined(TARGET_IPHONE_SIMULATOR) || defined(TARGET_OS_MAC)
#define FatalError printf //iOS、Mac平台
#else
#define PLATFORM_UNKNOWN 1
#endif



typedef int ElementType;
typedef int PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

void InitializeCursorSpaceSpace(void);
void PrintCursor(void);
List MakeEmpty(List L);
int IsEmpty(const List L);
Position Find(ElementType X, List L);
Position FindPrevious(List L);
void Delete(ElementType X, List L);
void Insert(ElementType X, Position P);
Position Create(ElementType X);
void Add(ElementType X, List L);

struct Node
{
    ElementType element;
    Position    next;
};

extern struct Node CursorSpace[SPACESIZE];

#endif // !CursorSpace