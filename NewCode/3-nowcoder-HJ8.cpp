/*数据表记录包含表索引index和数值value（int范围的正整数），请对表索引相同的记录进行合并，即将相同索引的数值进行求和运算，输出按照index值升序进行输出。

提示:
0 <= index <= 11111111
1 <= value <= 100000

输入描述：
先输入键值对的个数n（1 <= n <= 500）
接下来n行每行输入成对的index和value值，以空格隔开
输出描述：
输出合并后的键值对（多行）
示例1
输入：
	4
	0 1
	0 2
	1 2
	3 4
输出：
	0 3
	1 2
	3 4
示例2
输入：
	3
	0 1
	0 2
	8 9
输出：
	0 3
	8 9
*/
#include <iostream>
using namespace std;
#include <map>
int main() {
    map<int,int> nums;
    int n;
    cin >> n;
    int index,num;
    for(int i = 0; i < n; i++) {
        cin >> index >> num;
        nums[index] += num;
    }
    for(auto iter = nums.begin(); iter != nums.end(); iter++) {
        printf("%d %d\n",iter->first,iter->second);
    }
    return 0;
}