/*
对字符串中的所有单词进行倒排。

说明：
1、构成单词的字符只有26个大写或小写英文字母；
2、非构成单词的字符均视为单词间隔符；
3、要求倒排后的单词间隔符以一个空格表示；如果原字符串中相邻单词间有多个间隔符时，倒排转换后也只允许出现一个空格间隔符；
4、每个单词最长20个字母；

数据范围：字符串长度满足 1≤n≤10000 

输入描述：输入一行，表示用来倒排的句子
输出描述：输出句子的倒排结果

示例1
输入：
	I am a student
输出：
	student a am I
示例2
输入：
	$bo*y gi!r#l
输出：
	l r gi y bo
*/
#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

bool isLetter(char ch) {
    if(ch >= 'A' && ch <= 'Z') return true;
    if(ch >= 'a' && ch <= 'z') return true;
    return false;
}

int main() {
    string str;
    string tmp;
    while (cin >> tmp) {
        for(int i = 0; i < tmp.size(); i++)
            if(!isLetter(tmp[i]))   tmp[i] = ' ';
        str += tmp + " ";
        if (getchar() == '\n')  break;
    }
    cout << str  << "pppp" << endl;
    vector<string> res;
    int start = 0;
    for (int i = 0; i < str.size(); i++) {
        if(str[i] == ' ') {
            if(i != start)  res.push_back(str.substr(start, i - start));
            cout << "start: " << start << "  i: "<< i << "  " << str.substr(start, i - start) << endl;
            start = i + 1;
        }
    }
    cout << res.size() << endl;
    str = "";
    auto iter = res.end() - 1;
    while(iter != res.begin()) {
        str.append(*iter--);
        str.push_back(' ');
    }
    str.append(*iter);
    cout << str << endl;
    return 0;
}