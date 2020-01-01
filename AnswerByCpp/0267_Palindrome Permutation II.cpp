#include <iostream>
#include <vector>
#include <queue>
using namespace std;
/*
267. 回文排列 II

给定一个字符串 s ，返回其通过重新排列组合后所有可能的回文字符串，并去除重复的组合。
如不能形成任何回文排列时，则返回一个空列表。

示例 1：

输入: "aabb"
输出: ["abba", "baab"]
示例 2：

输入: "abc"
输出: []
*/

class Solution {
public:
    int size;
    set<string>re;
    string path;
    void dfs(map<char,int>&table)
    {
        if(path.size()==size)
        {
            re.insert(path);
            return;
        }
        for(auto &i:table)
            if(i.second>0)
            {
                path+=i.first;
                i.second--;
                dfs(table);
                path.pop_back();
                i.second++;
            }
    }
    vector<string> generatePalindromes(string s) {
        map<char,int>table;
        size=s.size()/2;
        for(int i=0;i<s.size();i++)
            table[s[i]]++;
        string mid;
        int cnt=0;
        for(auto& i:table)
           if(i.second%2)
            {
                cnt++;
                mid=i.first;
                i.second=(i.second-1)/2;
            }
            else
                i.second/=2;
        if(cnt>1)
            return {};
        dfs(table);
        vector<string>ret;
        for(auto i:re)
        {
            string tmp=i;
            reverse(i.begin(),i.end());
            tmp+=mid+i;
            ret.push_back(tmp);
        }
        return ret;
    }
};