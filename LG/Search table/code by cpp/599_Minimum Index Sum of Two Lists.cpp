#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
/*
599. 两个列表的最小索引总和

假设Andy和Doris想在晚餐时选择一家餐厅，并且他们都有一个表示最喜爱餐厅的列表，每个餐厅的名字用字符串表示。

你需要帮助他们用最少的索引和找出他们共同喜爱的餐厅。 如果答案不止一个，则输出所有答案并且不考虑顺序。 你可以假设总是存在一个答案。

示例 1:

输入:
["Shogun", "Tapioca Express", "Burger King", "KFC"]
["Piatti", "The Grill at Torrey Pines", "Hungry Hunter Steakhouse", "Shogun"]
输出: ["Shogun"]
解释: 他们唯一共同喜爱的餐厅是“Shogun”。
示例 2:

输入:
["Shogun", "Tapioca Express", "Burger King", "KFC"]
["KFC", "Shogun", "Burger King"]
输出: ["Shogun"]
解释: 他们共同喜爱且具有最小索引和的餐厅是“Shogun”，它有最小的索引和1(0+1)。
提示:

两个列表的长度范围都在 [1, 1000]内。
两个列表中的字符串的长度将在[1，30]的范围内。
下标从0开始，到列表的长度减1。
两个列表都没有重复的元素。
*/

vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
    int i=0,j=0;
    unordered_set<string> hash;
    vector<string> arr;
    bool flag = false;
    while(i<list1.size()||j<list2.size()){
        if(i<list1.size()){
            if(hash.find(list1[i]) != hash.end()){
                flag = true;
                arr.push_back(list1[i]);
            }
            else hash.insert(list1[i]);
        }

        if(j<list2.size()){
            if(hash.find(list2[j]) != hash.end()){
                flag = true;
                arr.push_back(list2[j]);
            }
            else hash.insert(list2[j]);
        }
        if(flag)return arr;
        i++;
        j++;
    }
    return arr;
}

int main(){
    string a[] = {"Shogun", "KFCd", "Burger King", "KFC"};
    vector<string> arr(a,a+4);

    string b[] = {"KFC", "Shogun", "Burger King", "Hungry Hunter Steakhouse"};
    vector<string> brr(b,b+4);

    vector<string> str = findRestaurant(arr,brr);
    for(int i = 0;i<str.size();i++){
        cout<<str[i]<<' ';
    }
    cout<<endl;

	return 0;
}
