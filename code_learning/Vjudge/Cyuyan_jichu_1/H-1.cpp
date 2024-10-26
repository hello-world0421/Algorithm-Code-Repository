#include <iostream>
#include <string>
#include <cctype>

using namespace std;
int main()
{
    string keyword, text;
    getline(cin, keyword);
    getline(cin, text);

    // 将要查找的字符串和文本都转换为小写，方便比较
    for (int i = 0; i < keyword.length(); i++)
    {
        keyword[i] = tolower(keyword[i]);
    }
    for (int i = 0; i < text.length(); i++)
    {
        text[i] = tolower(text[i]);
    }

    int count = 0;
    size_t pos = -1;
    // size_t 表示无符号整型，通常被用于数组索引和循环计数等地方，因为它的大小足够大
    bool found = false;

    string::size_type start = 0;
    string::size_type end = text.find(' ', start);
    // size_type 的用法与 size_t 类似
    // 当使用函数 find 时，如果未找到通常会返回 string::npos
    while (end != string::npos)
    {
        string word = text.substr(start, end - start);
        if (word == keyword)
        {
            if (!found)
            {
                found = true;
                pos = count;
            }
            count++;
        }
        start = end + 1;
        end = text.find(' ', start);
    }

    // 检查最后一个单词
    string lastWord = text.substr(start);
    if (lastWord == keyword)
    {
        if (!found)
        {
            found = true;
            pos = count;
        }
        count++;
    }

    if (found)
    {
        cout << count << " " << pos << endl;
    }
    else
    {
        cout << "-1" << endl;
    }

    return 0;
}
