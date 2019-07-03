package Leetcode_1106_ParsingABooleanExpression;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Stack;

/*
	����һ�����ַ�����ʽ������ ��������ʽ��boolean�� expression�����ظ�ʽ����������
	
	��Ч�ı���ʽ����ѭ����Լ����	
		"t"��������Ϊ True
		"f"��������Ϊ False
		"!(expr)"���������Ϊ���ڲ�����ʽ expr �����߼� �ǵ����㣨NOT��
		"&(expr1,expr2,...)"���������Ϊ�� 2 ���������ڲ�����ʽ expr1, expr2, ... �����߼� ������㣨AND��
		"|(expr1,expr2,...)"���������Ϊ�� 2 ���������ڲ�����ʽ expr1, expr2, ... �����߼� ������㣨OR��	 
	
	ʾ�� 1��	
		���룺expression = "!(f)"
		�����true
	ʾ�� 2��	
		���룺expression = "|(f,t)"
		�����true
	ʾ�� 3��	
		���룺expression = "&(t,f)"
		�����false
	ʾ�� 4��
		���룺expression = "|(&(t,f,t),!(t))"
		�����false	 
	
	��ʾ��	
		1 <= expression.length <= 20000
		expression[i] �� {'(', ')', '&', '|', '!', 't', 'f', ','} �е��ַ���ɡ�
		expression ����������ʽ��������Ч����ʽ����ʾһ������ֵ��
 */

//1106. ������������ʽ
public class ParsingABooleanExpression {
	public boolean parseBoolExpr(String expression) {
		Stack<Character> stack = new Stack<>();
		List<List<Boolean>> list = new ArrayList<>();

		char[] exp = expression.toCharArray();
		for (int i = 0; i < exp.length; i++) {
			if (exp[i] == '!' || exp[i] == '|' || exp[i] == '&') {
				stack.push(exp[i]);
			} else if (exp[i] == '(') {
				list.add(new ArrayList<Boolean>());
			} else if (exp[i] == 't') {
				list.get(list.size() - 1).add(true);
			} else if (exp[i] == 'f') {
				list.get(list.size() - 1).add(false);
			} else if (exp[i] == ')') {
				List<Boolean> temp = list.remove(list.size() - 1);
				if (list.size() == 0) {
					list.add(new ArrayList<Boolean>());
				}
				char flag = stack.pop();
				boolean res = temp.get(0);
				if (flag == '!') {
					res = !res;
				} else if (flag == '&') {
					for (int j = 1; j < temp.size(); j++) {
						res &= temp.get(j);
					}
				} else if (flag == '|') {
					for (int j = 1; j < temp.size(); j++) {
						res |= temp.get(j);
					}
				}

				list.get(list.size() - 1).add(res);

			}
		}
		return list.get(0).get(0);
	}
}