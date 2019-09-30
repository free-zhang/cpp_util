/* Created by freezhang on 2019/9/29.
 * @初衷：封装一些c++ string常用函数
 */

#ifndef CLION_TEST_STRING_UTIL_H
#define CLION_TEST_STRING_UTIL_H

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 转换成大写
void to_upper(string& s);

// 转换成小写
void to_lower(string& s);

// 反转字符串
void reverse(string& s);

// 判断特定字符开头
bool start_with(const string& s, const string& sStart);

// 判断特定字符结尾
bool end_with(const string& s, const string& sEnd);

// 字符大小写转换
int switch_letter(int c);

// 字符串元素大小写转换
void switch_case(string& s);

/*@分割字符串
 *@sSrc： 源字符串
 *@sSep： 分隔符，默认值会将字符串中的任意空白字符视为分割字符串
 *@bRmEmpty：是否删除分割结果中的空字符串
 *@bMatchAny: true-匹配sSep中的任何一个字符， false-匹配sSep整个字符
 */
vector<string> split(const string& sSrc, const string& sSep=" \t\n\v\f\r", bool bRmEmpty = true, bool bMatchAny = false);

// 分割行
vector<string> split_lines(const string& sSrc);

// 拼接字符串
string join(const vector<string>& v, const string& sSep="|");

// 字符串替换
string replace(const string& sSrc, const string& sOld, const string& sNew);

// 字符计数
int count(const string& sSrc, const string& sTgt);

// 去除左边指定的任意字符
void lstrip(string& sSrc, const string& sRm=" \t\n\v\f\r");

// 去除右边指定的任意字符
void rstrip(string& sSrc, const string& sRm=" \t\n\v\f\r");

// 去除左右两边指定的任意字符
void strip(string& sSrc, const string& sRm=" \t\n\v\f\r");

#endif //CLION_TEST_STRING_UTIL_H
