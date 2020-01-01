#include <iostream>
#include <vector>
#include <queue>
using namespace std;
/*
353. 贪吃蛇

请你设计一个 贪吃蛇游戏，该游戏将会在一个 屏幕尺寸 = 宽度 x 高度 的屏幕上运行。
如果你不熟悉这个游戏，可以 点击这里 在线试玩。
起初时，蛇在左上角的 (0, 0) 位置，身体长度为 1 个单位。
你将会被给出一个 (行, 列) 形式的食物位置序列。当蛇吃到食物时，身子的长度会增加 1 个单位，得分也会 +1。
食物不会同时出现，会按列表的顺序逐一显示在屏幕上。比方讲，第一个食物被蛇吃掉后，第二个食物才会出现。
当一个食物在屏幕上出现时，它被保证不能出现在被蛇身体占据的格子里。
对于每个 move() 操作，你需要返回当前得分或 -1（表示蛇与自己身体或墙相撞，意味游戏结束）。
示例：
给定 width = 3, height = 2, 食物序列为 food = [[1,2],[0,1]]。
Snake snake = new Snake(width, height, food);
初始时，蛇的位置在 (0,0) 且第一个食物在 (1,2)。

|S| | |
| | |F|

snake.move("R"); -> 函数返回 0

| |S| |
| | |F|

snake.move("D"); -> 函数返回 0

| | | |
| |S|F|

snake.move("R"); -> 函数返回 1 (蛇吃掉了第一个食物，同时第二个食物出现在位置 (0,1))

| |F| |
| |S|S|

snake.move("U"); -> 函数返回 1

| |F|S|
| | |S|

snake.move("L"); -> 函数返回 2 (蛇吃掉了第二个食物)

| |S|S|
| | |S|

snake.move("U"); -> 函数返回 -1 (蛇与边界相撞，游戏结束)
*/

class SnakeGame {
public:
	struct HashFunc {
		size_t operator()(const pair<int, int>& key) const {
			return (hash<unsigned long long>()(((unsigned long long)key.first << 32) + key.second));
		}
	};

	struct EqualKey {
		bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs) const {
			return lhs.first == rhs.first && lhs.second == rhs.second;
		}
	};

	int width = 0;
	int height = 0;
	pair<int, int> curPos = pair<int, int>(0, 0);
	queue<pair<int, int>> myQueue;
	queue<pair<int, int>> foodQueue;
	unordered_set<pair<int, int>, HashFunc, EqualKey> mySet;

	/** Initialize your data structure here.
		@param width - screen width
		@param height - screen height
		@param food - A list of food positions
		E.g food = [[1,1], [1,0]] means the first food is positioned at [1,1], the second is at [1,0]. */
	SnakeGame(int width, int height, vector<vector<int>>& food) {
		for (vector<int> vec : food)
			foodQueue.push(pair<int, int>(vec[0], vec[1]));
		this->width = width;
		this->height = height;
		myQueue.push(curPos);
		mySet.insert(curPos);
	}

	/** Moves the snake.
		@param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down
		@return The game's score after the move. Return -1 if game over.
		Game over when snake crosses the screen boundary or bites its body. */
	int move(string direction) {
		for (char c : direction) {
			switch (c)
			{
			case 'U':
				curPos.first--;
				break;
			case 'L':
				curPos.second--;
				break;
			case 'R':
				curPos.second++;
				break;
			case 'D':
				curPos.first++;
				break;
			}

			if (curPos.first < 0 || curPos.first >= height || curPos.second < 0 || curPos.second >= width)
				return -1;
			myQueue.push(curPos);
			if (curPos == foodQueue.front())
				foodQueue.pop();
			else {
				mySet.erase(myQueue.front());
				myQueue.pop();
			}
			if (mySet.count(curPos))
				return -1;
			mySet.insert(curPos);
		}
		return myQueue.size() - 1;
	}
};

/**
 * Your SnakeGame object will be instantiated and called as such:
 * SnakeGame* obj = new SnakeGame(width, height, food);
 * int param_1 = obj->move(direction);
 */



class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        vector<bool> mp(64, false);
        for (auto &it : queens) mp[it[0] * 8 + it[1]] = true;
        vector<int> dxy{-1, 0, 1, 0, -1, -1, 1, 1, -1};
        vector<vector<int>> res;
        for (int i=0; i<8; i++) {
            int x = king[0] + dxy[i], y = king[1] + dxy[i+1];
            while (x >= 0 && x < 8 && y >= 0 && y < 8) {
                if (mp[x * 8 + y]) {
                    res.push_back({x, y});
                    break;
                }
                x += dxy[i], y += dxy[i+1];
            }
        }
        return res;
    }
};