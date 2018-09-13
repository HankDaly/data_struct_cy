02-线性结构1 两个有序链表序列的合并（15 分）
本题要求实现一个函数，将两个链表表示的递增整数序列合并为一个非递减的整数序列。

函数接口定义：
List Merge( List L1, List L2 );
其中List结构定义如下：

typedef struct Node *PtrToNode;
struct Node {
    ElementType Data; /* 存储结点数据 */
    PtrToNode   Next; /* 指向下一个结点的指针 */
};
typedef PtrToNode List; /* 定义单链表类型 */
L1和L2是给定的带头结点的单链表，其结点存储的数据是递增有序的；函数Merge要将L1和L2合并为一个非递减的整数序列。应直接使用原序列中的结点，返回归并后的带头结点的链表头指针。

裁判测试程序样例：
#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode   Next;
};
typedef PtrToNode List;

List Read(); /* 细节在此不表 */
void Print( List L ); /* 细节在此不表；空链表将输出NULL */

List Merge( List L1, List L2 );

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

/* 你的代码将被嵌在这里 */
输入样例：
3
1 3 5
5
2 4 6 8 10
输出样例：
1 2 3 4 5 6 8 10 
NULL
NULL

/*
总结:
思维有个盲点，注意链表的指针特性，不同指针都可以改变所指处的值。
            s->Next = L1->Next;
            s = s->Next;
            s->Next = L2->Next;
            s = s->Next;
            L1->Next = L1->Next->Next;
            L2->Next = L2->Next->Next;
注意这个写法。原来是想给s附上两个节点。然后将L1与L2分别指向下一处.但是要注意，因为s第一次改变后其实就是指向
L1->Next,再改变s就会改变L1->Next的值，这样就会对后面的L1->Next的操作产生误导。

所以下次就可以注意,链表中易出错的操作在于交接的时候，所以交接的时候尽量一对一，一对交接完后再与另一对交接。
*/
 


List Merge(List L1,List L2){
    List L3 = (List)malloc(sizeof(struct Node));
    L3->Next = NULL;
    List s = L3;
    while(L1->Next != NULL && L2->Next != NULL){
        if(L1->Next->Data == L2->Next->Data){
            s->Next = L1->Next;
            s = s->Next;
            L1->Next = L1->Next->Next;
            s->Next = L2->Next;
            s = s->Next;
            L2->Next = L2->Next->Next;
        }
        else if(L1->Next->Data < L2->Next->Data){
            s->Next = L1->Next;
            s = s->Next;
            L1->Next = L1->Next->Next;
        }
        else{
            s->Next = L2->Next;
            s = s->Next;
            L2->Next = L2->Next->Next;
        }
    }
    if(L1->Next == NULL){
        while(L2->Next != NULL){
            s->Next = L2->Next;
            s = s->Next;
            L2->Next = L2->Next->Next;
        }
    }
    else{
        while(L1->Next != NULL){
            s->Next = L1->Next;
            s = s->Next;
            L1->Next = L1->Next->Next;
        }
    }
    s->Next = NULL;
    return L3;
}