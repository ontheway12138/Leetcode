#include <iostream>
#include <vector>
#include <queue>
using namespace std;
/*
186. 翻转字符串里的单词 II
 
给定一个字符串，逐个翻转字符串中的每个单词。

示例：

输入: ["t","h","e"," ","s","k","y"," ","i","s"," ","b","l","u","e"]
输出: ["b","l","u","e"," ","i","s"," ","s","k","y"," ","t","h","e"]
注意： 单词的定义是不包含空格的一系列字符
输入字符串中不会包含前置或尾随的空格
单词与单词之间永远是以单个空格隔开的
进阶：使用 O(1) 额外空间复杂度的原地解法。
*/

class Solution {
public:
    void reverseWords(vector<char>& s) {
        int n = s.size();
        int left = 0,right = -1;
        while(left < n && right < n){
            if(right < left) right = left;
            
            while(right < n && s[right] != ' ') right++;
            
            reverse(s, left, right);
            left = right+1;   
        }
        reverse(s,0,n);
        return;
    }
    
    void reverse(vector<char>& s, int left, int right){
        right--;
        while(left < right){
            swap(s[left], s[right]);
            left++;
            right--;
        }
        return;
    }
};