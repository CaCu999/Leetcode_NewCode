/*
定义一个单词的“兄弟单词”为：交换该单词字母顺序（注：可以交换任意次），而不添加、删除、修改原有的字母就能生成的单词。
兄弟单词要求和原来的单词不同。例如： ab 和 ba 是兄弟单词。 ab 和 ab 则不是兄弟单词。
现在给定你 n 个单词，另外再给你一个单词 x ，让你寻找 x 的兄弟单词里，按字典序排列后的第 k 个单词是什么？
注意：字典中可能有重复单词。
数据范围：1≤n≤1000 ，输入的字符串长度满足1≤len(str)≤10，1≤k<n
输入描述：输入只有一行。 先输入字典中单词的个数n，再输入n个单词作为字典单词。 然后输入一个单词x 最后后输入一个整数k
输出描述：
第一行输出查找到x的兄弟单词的个数m 第二行输出查找到的按照字典顺序排序后的第k个兄弟单词，没有符合第k个的话则不用输出。
示例1
输入：
	3 abc bca cab abc 1
输出：
	2
	bca
示例2
输入：
	6 cab ad abcd cba abc bca abc 1
输出：
	3
	bca
说明：
abc的兄弟单词有cab cba bca，所以输出3
经字典序排列后，变为bca cab cba，所以第1个字典序兄弟单词为bca    
*/
#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

void findStr(vector<string> strs, string str, int n) {
    vector<string> bro;
    string tmp1,tmp;
    tmp = str;
    sort(tmp.begin(),tmp.end());
    cout << tmp << endl;
    int len = str.size();
    for(int i = 0; i < strs.size(); i++) {
        tmp1 = strs[i];
        if(tmp1.size() != len)   continue;
        sort(tmp1.begin(),tmp1.end());
        if(tmp.compare(tmp1) == 0 && str.compare(strs[i]) != 0) {
            bro.push_back(strs[i]);
        }
    }
    cout << bro.size() << endl;
    if(bro.size()) cout << bro[n-1] << endl;
}

int main() {
    int n;
    cin >> n;
    vector<string> strs;
    string str;
    for(int i = 0; i < n; i++) {
        cin >> str;
        strs.push_back(str);
    }
    sort(strs.begin(), strs.end());
    cin >> str;
    cin >> n;
    findStr(strs, str, n);
    return 0;
}