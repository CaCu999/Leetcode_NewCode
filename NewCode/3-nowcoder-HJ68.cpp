/*
给定一些同学的信息（名字，成绩）序列，请你将他们的信息按照成绩从高到低或从低到高的排列,相同成绩
都按先录入排列在前的规则处理。
例示：
jack      70
peter     96
Tom       70
smith     67
从高到低  成绩 
peter     96 
jack      70 
Tom       70 
smith     67
从低到高
smith     67
jack      70
Tom       70 
peter     96

注：0代表从高到低，1代表从低到高

数据范围：人数：1≤n≤200 
进阶：时间复杂度：O(nlogn) ，空间复杂度：O(n)

输入描述：
第一行输入要排序的人的个数n，第二行输入一个整数表示排序的方式，之后n行分别输入他们的名字和成绩，以一个空格隔开
输出描述：
按照指定方式输出名字和成绩，名字和成绩之间以一个空格隔开

示例1
输入：
	3
	0
	fang 90
	yang 50
	ning 70
输出：
	fang 90
	ning 70
	yang 50

示例2
输入：
	3
	1
	fang 90
	yang 50
	ning 70
输出：
	yang 50
	ning 70
	fang 90
*/
#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

class Person
{
public:
    string name;
    int score;
    int index;
    Person(string s, int num, int i): name(s), score(num), index(i) {}
};


void sortScore(vector<Person> nums, int increase) {
    cout << endl;
    if(increase)
        sort(nums.begin(),nums.end(),[](Person a, Person b){
            if(a.score == b.score)  return  a.index < b.index;
            return a.score < b.score;
        });
    else
        sort(nums.begin(),nums.end(),[](Person a, Person b){
            // printf(">>>>>>>>>>>>>>>>>>>>\nsort-decrease\n");
            // cout << a.first << "  " << a.second << endl;
            // cout << b.first << "  " << b.second << endl;
            // printf(">>>>>>>>>>>>>>>>>>>>\n\n");
            if(a.score == b.score)  return  a.index < b.index;
            return a.score > b.score;
        });
    for(auto iter = nums.begin(); iter != nums.end(); iter++) {
        cout << iter->name;
        printf(" %d\n",iter->score);
    }
}

int main() {
    int n;
    int increase;
    cin >> n;
    cin >> increase;
    vector<Person> nums;
    string name;
    int score;
    for(int i = 0; i < n; i++) {
        cin >> name >> score;
        nums.push_back(Person(name, score, i));
    }
    sortScore(nums,increase);
    return 0;
}