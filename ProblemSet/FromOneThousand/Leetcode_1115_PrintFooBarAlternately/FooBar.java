package Leetcode_1115_PrintFooBarAlternately;

import java.util.concurrent.BlockingQueue;
import java.util.concurrent.LinkedBlockingQueue;

/*
	我们提供一个类：	
		class FooBar {
			public void foo() {
			    for (int i = 0; i < n; i++) {
			      print("foo");
			    }
		  	}
		
		 	public void bar() {
		    	for (int i = 0; i < n; i++) {
		     		print("bar");
		    	}
		  	}
		}
	两个不同的线程将会共用一个 FooBar 实例。
	其中一个线程将会调用 foo() 方法，另一个线程将会调用 bar() 方法。
	
	请设计修改程序，以确保 "foobar" 被输出 n 次。
	
	示例 1:
		输入: n = 1
		输出: "foobar"
		解释: 这里有两个线程被异步启动。其中一个调用 foo() 方法, 另一个调用 bar() 方法，"foobar" 将被输出一次。
	示例 2:
		输入: n = 2
		输出: "foobarfoobar"
		解释: "foobar" 将被输出两次。
	
	来源：力扣（LeetCode）
	链接：https://leetcode-cn.com/problems/print-foobar-alternately
	著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

//1115. 交替打印FooBar
public class FooBar {
	private int n;
	// 阻塞队列
	private BlockingQueue<Integer> fooqueue;
	private BlockingQueue<Integer> barqueue;

	public FooBar(int n) {
		this.n = n;
		this.fooqueue = new LinkedBlockingQueue<Integer>(1);
		fooqueue.add(0);
		this.barqueue = new LinkedBlockingQueue<Integer>(1);
	}

	public void foo(Runnable printFoo) throws InterruptedException {
		for (int i = 0; i < n; i++) {
			fooqueue.take();
			printFoo.run();
			barqueue.put(0);
		}

	}

	public void bar(Runnable printBar) throws InterruptedException {

		for (int i = 0; i < n; i++) {
			barqueue.take();
			printBar.run();
			fooqueue.put(0);
		}

	}

	public static void main(String[] args) {
		FooBar fb = new FooBar(4);
		new Thread(new Runnable() {
			@Override
			public void run() {
				try {
					fb.foo(new Runnable() {
						@Override
						public void run() {
							System.out.print("foo");
						}
					});
				} catch (InterruptedException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
			}
		}).start();
		new Thread(new Runnable() {
			@Override
			public void run() {
				try {
					fb.bar(new Runnable() {
						@Override
						public void run() {
							System.out.print("bar");
						}
					});
				} catch (InterruptedException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
			}
		}).start();

	}
}
