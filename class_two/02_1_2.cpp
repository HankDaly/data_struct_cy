/*02-线性结构2 一元多项式的乘法与加法运算（20 分）
设计函数分别求两个一元多项式的乘积与和。

输入格式:
输入分2行，每行分别先给出多项式非零项的个数，再以指数递降方式输入一个多项式非零项系数和指数（绝对值均为不超过1000的整数）。数字间以空格分隔。

输出格式:
输出分2行，分别以指数递降方式输出乘积多项式以及和多项式非零项的系数和指数。数字间以空格分隔，但结尾不能有多余空格。零多项式应输出0 0。

输入样例:
4 3 4 -5 2  6 1  -2 0
3 5 20  -7 4  3 1
输出样例:
15 24 -25 22 30 21 -10 20 -21 8 35 6 -33 5 14 4 -15 3 18 2 -6 1
5 20 -4 4 -5 2 9 1 -2 0
*/
/*
总结:
链表的做法，注意链表表头指针未定义时，传入函数中在找空间定义会导致两个指针所指不同。
*/
#include<iostream>
#include<cstdio>
#include<unordered_map>
#include<cctype>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

struct Node{
    int a;
    int n;
    struct Node* Next;
};
typedef struct Node* Link;

Link bottominsert(int N){
    Link L = (Link)malloc(sizeof(struct Node));
    Link temp;
    Link s = L;
    for(int i = 0;i<N;i++){
        temp = (Link)malloc(sizeof(struct Node));
        int a,n;
        cin >> a >> n;
        temp->a = a; temp->n = n;
        s->Next = temp;
        s = temp;
    }
    s->Next = NULL;
    return L;
}

Link add(Link L1,Link L2){
    Link L1_temp = L1->Next,L2_temp = L2->Next;
    Link L3 = (Link)malloc(sizeof(struct Node)); L3->Next = NULL;
    Link s = L3;
    while(L1_temp != NULL && L2_temp != NULL){
        Link temp;
        if(L1_temp->n == L2_temp->n){
            temp = (Link)malloc(sizeof(struct Node));
            temp->n = L1_temp->n;
            temp->a = L1_temp->a + L2_temp->a;
            L1_temp = L1_temp->Next;
            L2_temp = L2_temp->Next;
        }
        else if(L1_temp->n > L2_temp->n){
            temp = (Link)malloc(sizeof(struct Node));
            temp->n = L1_temp->n;
            temp->a = L1_temp->a;
            L1_temp = L1_temp->Next;
        }
        else{
            temp = (Link)malloc(sizeof(struct Node));
            temp->n = L2_temp->n;
            temp->a = L2_temp->a;
            L2_temp = L2_temp->Next;
        }
        if(temp->a != 0){
            temp->Next = s->Next;
            s->Next = temp;
            s = temp;
        }
    }
    if(L1_temp == NULL){
        while(L2_temp != NULL){
            Link temp;
            temp = (Link)malloc(sizeof(struct Node));
            temp->a = L2_temp->a;
            temp->n = L2_temp->n;
            L2_temp = L2_temp->Next;
            temp->Next = s->Next;
            s->Next = temp;
            s = temp;
        }
    }
    if(L2_temp == NULL){
        while(L1_temp != NULL){
            Link temp;
            temp = (Link)malloc(sizeof(struct Node));
            temp->a = L1_temp->a;
            temp->n = L1_temp->n;
            L1_temp = L1_temp->Next;
            temp->Next = s->Next;
            s->Next = temp;
            s = temp;
        }
    }
    return L3;
}

Link mult(Link L1,Link L2){
    Link L1_temp = L1->Next;
    Link L3 = (Link)malloc(sizeof(struct Node));
    L3->Next = NULL;
    while(L1_temp != NULL){
        Link L_temp = (Link)malloc(sizeof(struct Node));
        Link s = L_temp;
        for(Link L2_temp = L2->Next;L2_temp != NULL;L2_temp = L2_temp->Next){
            Link temp = (Link)malloc(sizeof(struct Node));
            temp->a = L1_temp->a * L2_temp->a; temp->n = L1_temp->n + L2_temp->n;
            s->Next = temp;
            s = temp;
        }
        s->Next = NULL;
        L3 = add(L_temp,L3);
        L1_temp = L1_temp->Next;
    }
    return L3;
}
void PrintPoly(Link L){
    Link L_temp = L->Next;
    int flag = 0;
    while(L_temp != NULL){
        if(flag != 0){cout << " ";}
        cout << L_temp->a << " " << L_temp->n;
        ++flag;
        L_temp = L_temp->Next;
    }
}


int main(){
#ifdef LOCAL
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
#endif
    Link L1,L2,L3,L4; 
    int N_1; cin >> N_1;
    L1 = bottominsert(N_1);
    int N_2; cin >> N_2;
    L2 = bottominsert(N_2);
    L3 = add(L1,L2);
    L4 = mult(L1,L2);
    if(L4->Next == NULL){cout << "0 0";}
    else{PrintPoly(L4);}
    cout << "\n";
    if(L3->Next == NULL){cout << "0 0";}
    else{PrintPoly(L3);}
}