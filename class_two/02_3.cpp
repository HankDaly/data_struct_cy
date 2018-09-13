/*
02-线性结构3 Reversing Linked List（25 分）
Given a constant K and a singly linked list L, you are supposed to reverse the links of every K elements on L. For example, given L being 1→2→3→4→5→6, if K=3, then you must output 3→2→1→6→5→4; if K=4, you must output 4→3→2→1→5→6.

Input Specification:
Each input file contains one test case. For each case, the first line contains the address of the first node, a positive N (≤10
​5
​​ ) which is the total number of nodes, and a positive K (≤N) which is the length of the sublist to be reversed. The address of a node is a 5-digit nonnegative integer, and NULL is represented by -1.

Then N lines follow, each describes a node in the format:

Address Data Next
where Address is the position of the node, Data is an integer, and Next is the position of the next node.

Output Specification:
For each case, output the resulting ordered linked list. Each node occupies a line, and is printed in the same format as in the input.

Sample Input:
00100 6 4
00000 4 99999
00100 1 12309
68237 6 -1
33218 3 00000
99999 5 68237
12309 2 33218
Sample Output:
00000 4 33218
33218 3 12309
12309 2 00100
00100 1 99999
99999 5 68237
68237 6 -1
*/
/*
总结:
乙级里面有做过，主要用的是链表的概念，然后用数组实现。
注意到不是所有的节点都是有效的，其实如果注意到将ve_len提取出来就不会有这个问题。
注意程序的耦合度.
*/


#include<iostream>
#include<cstdio>
#include<unordered_map>
#include<cctype>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;
int ch_data[100005];
int ch_last[100005];
vector<int> ve;

int main(){
#ifdef LOCAL
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
#endif
    int first_node,N,K; cin >> first_node >> N >> K;
    for(int i = 0;i<N;i++){
        int first,data,last; cin >> first >> data >> last;
        ch_data[first] = data;
        ch_last[first] = last;
    }
    int temp = first_node;
    while(temp != -1){
        ve.push_back(temp);
        temp = ch_last[temp];
    }
    int ve_len = ve.size();
    for(int i = 0;i+K<=ve_len;i += K){
        reverse(ve.begin()+i,ve.begin()+i+K);
    }
    for(int i = 0;i<ve_len;i++){
        if(i == 0){printf("%05d %d",ve[i],ch_data[ve[i]]);}
        else{printf(" %05d\n%05d %d",ve[i],ve[i],ch_data[ve[i]]);}
        if(i+1 == ve_len){printf(" -1");}
    }
    return 0;
}