package LCP;

import java.util.Arrays;
import java.util.Comparator;
import java.util.HashMap;
import java.util.HashSet;

/*
	力扣团队买了一个可编程机器人，机器人初始位置在原点(0, 0)。
	小伙伴事先给机器人输入一串指令command，机器人就会无限循环这条指令的步骤进行移动。指令有两种：
	
	U: 向y轴正方向移动一格
	R: 向x轴正方向移动一格。
	不幸的是，在 xy 平面上还有一些障碍物，他们的坐标用obstacles表示。机器人一旦碰到障碍物就会被损毁。
	
	给定终点坐标(x, y)，返回机器人能否完好地到达终点。如果能，返回true；否则返回false。	 
	
	示例 1：	
		输入：command = "URR", obstacles = [], x = 3, y = 2
		输出：true
		解释：U(0, 1) -> R(1, 1) -> R(2, 1) -> U(2, 2) -> R(3, 2)。
	示例 2：	
		输入：command = "URR", obstacles = [[2, 2]], x = 3, y = 2
		输出：false
		解释：机器人在到达终点前会碰到(2, 2)的障碍物。
	示例 3：	
		输入：command = "URR", obstacles = [[4, 2]], x = 3, y = 2
		输出：true
		解释：到达终点后，再碰到障碍物也不影响返回结果。 
	
	限制：	
		2 <= command的长度 <= 1000
		command由U，R构成，且至少有一个U，至少有一个R
		0 <= x <= 1e9, 0 <= y <= 1e9
		0 <= obstacles的长度 <= 1000
		obstacles[i]不为原点或者终点
	
	来源：力扣（LeetCode）
	链接：https://leetcode-cn.com/problems/programmable-robot
	著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
//LCP 3. 机器人大冒险
public class LCP_003_ProgrammableRobot {
	public static void main(String[] args) {
		String command = "URR";

		int[][] obstacles = { { 2, 2 } };

		int x = 3;
		int y = 2;
		System.out.println(new LCP_003_ProgrammableRobot().robot2(command, obstacles, x, y));
	}

	// 暴力计算
	public boolean robot(String command, int[][] obstacles, int x, int y) {
		HashMap<Integer, HashSet<Integer>> map = new HashMap<>();
		int m = obstacles.length;
		for (int i = 0; i < m; i++) {
			if (map.containsKey(obstacles[i][0])) {
				map.get(obstacles[i][0]).add(obstacles[i][1]);
			} else {
				HashSet<Integer> set = new HashSet<>();
				set.add(obstacles[i][1]);
				map.put(obstacles[i][0], set);
			}
		}

		int x0 = 0;
		int y0 = 0;
		int i = 0;
		while (x0 <= x && y0 <= y) {
			if (command.charAt(i % command.length()) == 'U') {
				y0++;
			} else {
				x0++;
			}
			if (map.containsKey(x0) && map.get(x0).contains(y0)) {
				return false;
			}
			if (x0 == x && y == y0) {
				return true;
			}
			i++;
		}
		return false;
	}

	// 哈希映射
	public boolean robot2(String command, int[][] obstacles, int x, int y) {
		char[] chars = command.toCharArray();

		HashSet<Long> set = new HashSet<>();
		set.add(0L);
		int xx = 0;
		int yy = 0;
		for (int i = 0; i < chars.length; i++) {
			if (chars[i] == 'U') {
				yy++;
			} else {
				xx++;
			}
			set.add(((long) xx << 30) | +yy);
		}
		int max = Math.min(x / xx, y / yy);
		for (int i = 0; i < obstacles.length; i++) {
			int curx = obstacles[i][0];
			int cury = obstacles[i][1];
			int cur = Math.min(curx / xx, cury / yy);
			if (curx <= x && cury <= y) {
				if (set.contains((((long) curx - cur * xx) << 30) | (cury - cur * yy))) {
					return false;
				}
			} else {
				continue;
			}
		}
		if (set.contains((((long) x - max * xx) << 30) | (y - max * yy))) {
			return true;
		}
		return false;
	}
}
