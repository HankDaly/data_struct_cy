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
解法一:用vector模拟链表。
坑点:
1.ve3,与ve4为空时输出"0 0"
2.注意两个项相互抵消的时候，考虑应该注意相加的时候不等于0的时候再push_back
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
    int a; //系数
    int n; //指数
};

vector<Node> ve1;
vector<Node> ve2;
vector<Node> ve3; //储存相加的
vector<Node> ve4; //储存相乘的

void add(vector<Node>& ve1,vector<Node>& ve2,vector<Node>* ve3){
    int ve1_len = ve1.size(),ve2_len = ve2.size();
    int ve1_flag = 0,ve2_flag = 0;
    while(ve1_flag != ve1_len && ve2_flag != ve2_len){
        if(ve1[ve1_flag].n == ve2[ve2_flag].n){
            Node node ;
            node.a = ve1[ve1_flag].a+ve2[ve2_flag].a;
            node.n = ve1[ve1_flag].n;
            if(node.a != 0){ve3->push_back(node);}
            ++ve1_flag;
            ++ve2_flag;
        }
        else if(ve1[ve1_flag].n > ve2[ve2_flag].n){
            ve3->push_back(ve1[ve1_flag]);
            ++ve1_flag;
        }
        else{
            ve3->push_back(ve2[ve2_flag]);
            ++ve2_flag;
        }
    }
    if(ve1_flag == ve1_len){
        for(int i = ve2_flag;i<ve2_len;i++){
            ve3->push_back(ve2[i]);
        }
    }
    else{
        for(int i = ve1_flag;i<ve1_len;i++){
            ve3->push_back(ve1[i]);
        }
    }
}

int main(){
#ifdef LOCAL
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
#endif
    int ve1_len; cin >> ve1_len;
    for(int i = 0;i<ve1_len;i++){
        Node node; cin >> node.a >> node.n;
        ve1.push_back(node);
    }
    int ve2_len; cin >> ve2_len;
    for(int i = 0;i<ve2_len;i++){
        Node node; cin >> node.a >> node.n;
        ve2.push_back(node);
    }
    //两个整理完毕
    add(ve1,ve2,&ve3);
    //
    vector<Node> ve1_temp;
    vector<Node> ve2_temp;
    for(int i = 0;i<ve1_len;i++){
        ve1_temp.clear();
        ve2_temp = ve4;
        ve4.clear();
        for(int z = 0;z<ve2_len;z++){
            Node node; node.a = ve2[z].a*ve1[i].a; node.n = ve2[z].n+ve1[i].n;
            ve1_temp.push_back(node);
        }
        add(ve1_temp,ve2_temp,&ve4);
    }
    if(ve4.size() == 0){
        cout << "0 0";
    }
    else{
        for(int i = 0;i<ve4.size();i++){
            if(i!=0){cout << " ";}
            cout << ve4[i].a << " " << ve4[i].n;
        }
    }
    cout << "\n";
    if(ve3.size() == 0){cout << "0 0";}
    else{
        for(int i = 0;i<ve3.size();i++){
            if(i != 0){cout << " ";}
            cout << ve3[i].a << " " << ve3[i].n;
        }
    }

}