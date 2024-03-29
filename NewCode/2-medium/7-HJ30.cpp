/*
按照指定规则对输入的字符串进行处理。
详细描述：
第一步：将输入的两个字符串str1和str2进行前后合并。如给定字符串 "dec" 和字符串 "fab" ， 合并后生成的字符串为 "decfab"

第二步：对合并后的字符串进行排序，要求为：下标为奇数的字符和下标为偶数的字符分别从小到大排序。这里的下标的意思是字符在字符串中的位置。注意排序后在新串中仍需要保持原来的奇偶性。例如刚刚得到的字符串“decfab”，分别对下标为偶数的字符'd'、'c'、'a'和下标为奇数的字符'e'、'f'、'b'进行排序（生成 'a'、'c'、'd' 和 'b' 、'e' 、'f'），再依次分别放回原串中的偶数位和奇数位，新字符串变为“abcedf”

第三步：对排序后的字符串中的'0'~'9'、'A'~'F'和'a'~'f'字符，需要进行转换操作。
转换规则如下：
对以上需要进行转换的字符所代表的十六进制用二进制表示并倒序，然后再转换成对应的十六进制大写字符（注：字符 a~f 的十六进制对应十进制的10~15，大写同理）。
如字符 '4'，其二进制为 0100 ，则翻转后为 0010 ，也就是 2 。转换后的字符为 '2'。
如字符 ‘7’，其二进制为 0111 ，则翻转后为 1110 ，对应的十进制是14，转换为十六进制的大写字母为 'E'。
如字符 'C'，代表的十进制是 12 ，其二进制为 1100 ，则翻转后为 0011，也就是3。转换后的字符是 '3'。
根据这个转换规则，由第二步生成的字符串 “abcedf” 转换后会生成字符串 "5D37BF"。

数据范围：输入的字符串长度满足 1≤n≤100 

输入描述：
样例输入两个字符串，用空格隔开。

输出描述：输出转化后的结果。

示例1
输入：
	dec fab
输出：
	5D37BF

示例2
输入：
	ab CD
输出：
	3B5D
说明：
合并后为abCD，按奇数位和偶数位排序后是CDab（请注意要按ascii码进行排序，所以C在a前面，D在b前面），转换后为3B5D          
示例3
输入：
	123 15
输出：
	88C4A
*/

#include <iostream>
using namespace std;
#include <algorithm>
#include <map>

void sortStr(string &str) {
    //要求为：下标为奇数的字符和下标为偶数的字符分别从小到大排序。
    //这里的下标的意思是字符在字符串中的位置。注意排序后在新串中仍需要保持原来的奇偶性。
    //例如刚刚得到的字符串“decfab”，分别对下标为偶数的字符'd'、'c'、'a'和下标为奇数的字符'e'、'f'、'b'
    string odd,even;
    for (int i = 0; i < str.size(); i++) {
        if(i % 2)
            odd.push_back(str[i]);
        else
            even.push_back(str[i]);
    }

    //进行排序（生成 'a'、'c'、'd' 和 'b' 、'e' 、'f'）
    sort(odd.begin(), odd.end());
    sort(even.begin(), even.end());
    cout <<"  偶数：" << even << endl;
    cout <<"  奇数：" << odd << endl;

    //再依次分别放回原串中的偶数位和奇数位，新字符串变为“abcedf”
    for (int i = 0; i < str.size(); i++) {
        if (i % 2)
            str[i] = odd[i/2];
        else
            str[i] = even[i/2];
    }
}

map<char, int> hexChar = {
    {'a', 10}, {'b', 11}, {'c', 12}, {'d', 13}, {'e', 14}, {'f', 15},
    {'A', 10}, {'B', 11}, {'B', 12}, {'D', 13}, {'E', 14}, {'F', 15}
};

void transStr(string &str) {
    // 转换规则如下：
    // 对以上需要进行转换的字符所代表的十六进制用二进制表示并倒序，然后再转换成对应的十六进制大写字符（注：字符 a~f 的十六进制对应十进制的10~15，大写同理）。
    // 如字符 '4'，其二进制为 0100 ，则翻转后为 0010 ，也就是 2 。转换后的字符为 '2'。
    // 如字符 ‘7’，其二进制为 0111 ，则翻转后为 1110 ，对应的十进制是14，转换为十六进制的大写字母为 'E'。
    // 如字符 'C'，代表的十进制是 12 ，其二进制为 1100 ，则翻转后为 0011，也就是3。转换后的字符是 '3'。
    cout << str << endl;
    for(int i = 0; i < str.size(); i++) {
        int n = 0;
        char ch = str[i];
        if (ch > 'F' && ch <= 'Z') continue;
        if (ch > 'f' && ch >= 'z') continue;
        if (ch >= '0' && ch <= '9') n = ch - '0';
        else if (ch >= 'A' && ch <= 'F') n = ch - 'A' + 10;
        else if (ch >= 'a' && ch <= 'f') n = ch - 'a' + 10;
        if(ch != '0' && n == 0) continue;
        // cout << "this is not hex char:  " << ch << endl;
        string res(4, '0');
        int index = 0;
        cout << ch << "  " << n;
        while (n) {
            res[index++] = n % 2 + '0';
            // res.append(to_string(n%2));
            n = n / 2;
        }
        cout << "  " << res;
        for(int j = 0; j < res.size(); j++) {
            n = n * 2 + (res[j] - '0');
        }
        cout << " -> " << n << endl;
        // 根据这个转换规则，由第二步生成的字符串 “abcedf” 转换后会生成字符串 "5D37BF"。
        if (n >= 10) {
            str[i] = n - 10 + 'A';
        } else {
            str[i] = n + '0';
        }
    }
    cout << str << endl;        
}

void processStr(string &str , string str2) {
    //第一步：将输入的两个字符串str1和str2进行前后合并。如给定字符串 "dec" 和字符串 "fab" ， 合并后生成的字符串为 "decfab"
    str = str.append(str2);
    cout << str << endl;
    //第二步：对合并后的字符串进行排序,ascii码排序
    sortStr(str);
    // 第三步：对排序后的字符串中的'0'~'9'、'A'~'F'和'a'~'f'字符，需要进行转换操作。
    transStr(str);
}

int main() {
    string str1,str2;
    cin >> str1 >> str2;
    processStr(str1, str2);
    cout << str1 << endl;
    return 0;
}