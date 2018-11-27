package Leetcode_929_UniqueEmailAddresses;

import java.util.HashSet;
import java.util.Set;

/*
	每封电子邮件都由一个本地名称和一个域名组成，以 @ 符号分隔。	
	例如，在 alice@leetcode.com中， alice 是本地名称，而 leetcode.com 是域名。
	除了小写字母，这些电子邮件还可能包含 ',' 或 '+'。	
	如果在电子邮件地址的本地名称部分中的某些字符之间添加句点（'.'），则发往那里的邮件将会转发到本地名称中没有点的同一地址。
	例如，"alice.z@leetcode.com” 和 “alicez@leetcode.com” 会转发到同一电子邮件地址。 （请注意，此规则不适用于域名。）
	如果在本地名称中添加加号（'+'），则会忽略第一个加号后面的所有内容。这允许过滤某些电子邮件，
	例如 m.y+name@email.com 将转发到 my@email.com。 （同样，此规则不适用于域名。）	
	可以同时使用这两个规则。	
	给定电子邮件列表 emails，我们会向列表中的每个地址发送一封电子邮件。实际收到邮件的不同地址有多少？
	
	示例：
		输入：
		["test.email+alex@leetcode.com","test.e.mail+bob.cathy@leetcode.com","testemail+david@lee.tcode.com"]
		输出：2
		解释：实际收到邮件的是 "testemail@leetcode.com" 和 "testemail@lee.tcode.com"。	 
		
	提示：		
		1 <= emails[i].length <= 100
		1 <= emails.length <= 100
		每封 emails[i] 都包含有且仅有一个 '@' 字符。
 */
public class UniqueEmailAddresses {
	public static void main(String[] args) {
		UniqueEmailAddresses uea = new UniqueEmailAddresses();
		String[] emails = { "test.email+alex@leetcode.com", "test.e.mail+bob.cathy@leetcode.com",
				"testemail+david@lee.tcode.com" };
		uea.numUniqueEmails2(emails);
	}

	// 929. 独特的电子邮件地址
	public int numUniqueEmails(String[] emails) {
		String[][] emailsArray = new String[emails.length][2];
		HashSet<String> emailset = new HashSet();
		StringBuilder temp;
		//
		for (int i = 0; i < emails.length; i++) {

			// int atindex = temp.lastIndexOf("@");
			emailsArray[i] = emails[i].split("@");
			temp = new StringBuilder(emailsArray[i][0]);
			if (temp.indexOf("+") != -1) {
				temp.delete(temp.indexOf("+"), temp.length());
				// emailsArray[i][0]=emailsArray[i][0].substring(0,
				// emailsArray[i][0].indexOf("+"));
			}
			while (temp.indexOf(".") != -1) {
				temp.deleteCharAt(temp.indexOf("."));
				// emailsArray[i][0]=emailsArray[i][0].replaceAll(".", "");
			}
			emailset.add(temp.append("@").append(emailsArray[i][1]).toString());

		}

		return emailset.size();
	}

	// 9ms（为什么不需要添加本地名称）
	public int numUniqueEmails2(String[] emails) {
		Set<String> set = new HashSet<>();
		for (String email : emails) {
			// 本地名称
			// String name=email.substring(0,email.indexOf("@"));
			// 域名
			String domain = email.substring(email.indexOf("@"));
			// 根据指定规则解析后的本地名称，先按加号切割字符串，然后替换'.'
			// String newName=name.substring(0,name.indexOf("+")).replace(".","");
			// 使用HashSet去重
			set.add(domain);
			// set.add(newName+domain);
		}
		return set.size();
	}
}
