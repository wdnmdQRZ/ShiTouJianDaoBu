#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <cstdlib>
#include <ctime>
#include <windows.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

string Huan(int a) {        //"换"：把数字转换为汉字
	string b;               //最后输出文字
	int x;                  //多选一用的
	int T;                  //随机数用的
	srand((int)time(0));    //随机数种子
	if (a == 1) {
		b = "1.石头";
	} else if (a == 2) {
		b = "2.剪刀";
	} else if (a == 3) {
		b = "3.布";
	}
	return b;
}

int Sui(int a) {            //"随"：随机用的，不随机也用，放一起方便
	int b = 1;              //最后输出
	int T;                  //用于随机数
	srand((int)time(0));    //随机数种子
	if (a == 1) {           //石头最多，出布
		b = 3;
	} else if (a == 2) {    //剪刀最多，出石头
		b = 1;
	} else if (a == 3) {    //布最多，出剪刀
		b = 2;
	} else if (a == 4) {    //石头剪刀一样多，且都比布多，出石头
		b = 1;              //出石头
	} else if (a == 5) {    //石头和布一样多，且都比剪刀多，出布
		b = 3;              //出布
	} else if (a == 6) {    //剪刀和布一样多，且都大于石头，出剪刀
		b = 2;              //出剪刀
	} else if (a == 7) {    //三个随机出
		b = rand() % 3 + 1;
	}
	return b;
}

int max(int a, int b, int c) { //三个数字找最大
	if (a > b)
		b = a;
	if (b > c)
		c = b;
	return c;
}

int main(int argc, char **argv) {
	printf("前十次为热身阶段，十次后算法启动\n");
	printf("前十次为热身阶段，十次后算法启动\n");
	printf("前十次为热身阶段，十次后算法启动\n\n");
	int acre = 0;
	int My[2000];                       //My是自己的出法记录
	int win = 0, lose = 0, middle = 0, all = 0; //win获胜场次，lose失败场次，middle中间场次，all所有场次
	double winLF, loseLF, middleLF;     //winLF获胜概率，loseLF失败概率，middleLF平局概率

	printf("请输入您选择的出法：1.石头 2.剪刀 3.布（输入数字）\n");

	for (; all < 10;) {
line1:
		scanf("%d", &acre);          	//输入自己的出法
		if (acre >= 1 && acre <= 3) {
			My[all] = acre;
		} else {
			printf("输入不合法\n");
			goto line1;
		}
		srand((int)time(0));            //随机数种子
		int x = rand() % 3 + 1;         //随机数生成
		printf("机器出法为：%s\n", Huan(x).c_str()); //表达生成的数字，由函数转为汉字

		if (My[all] == x) {             //计算平局多少
			middle = middle + 1;
		} else if ((My[all] == 1 && x == 2) || (My[all] == 2 && x == 3) || (My[all] == 3 && x == 1)) { //计算胜多少
			win = win + 1;
		} else if ((My[all] == 1 && x == 3) || (My[all] == 2 && x == 1) || (My[all] == 3 && x == 2)) { //计算输多少
			lose = lose + 1;
		}
		all++;

		winLF = win * 100 / all;        //计算获胜概率
		loseLF = lose * 100 / all;      //计算失败概率
		middleLF = middle * 100 / all;  //计算平局概率
		printf("获胜：%d局，失败：%d局，平局：%d局\n", win, lose, middle);
		printf("获胜概率：%.0lf%，失败概率：%.0lf%，平局概率：%.0lf%\n", winLF, loseLF, middleLF);
	}
	printf("计算中,请稍后");;
	printf("。");
	Sleep(700);
	printf("。");
	Sleep(700);
	printf("。");
	Sleep(700);
	printf("。\n");;

	for (int i = 0; i < 30; i++) {
		printf("-");
		Sleep(25);
	}
	printf("\n");
	printf("请输入您选择的出法：1.石头 2.剪刀 3.布\n");
	//以下开始算法

	int Stop = 1;                   //用做while的停止变量
	int last = 0;                   //最后结果

	while (Stop) {
		int A1 = 0, A2 = 0, A3 = 0; //A1石头数量，A2剪刀数量，A3布数量

		scanf("%d", &acre);
		if (acre >= 1 && acre <= 3) {
			My[all] = acre;
		} else {
			printf("输入不合法\n");
			continue;
		}

		for (int i = 0; i < all - 5; i++) { //开始计算
			//往前走三个计算
			if (My[i] == My[all - 3] && My[i + 1] == My[all - 2] && My[i + 2] == My[all - 1]) {
				if (My[i + 3] == 1) {
					A1++;           //给石头+1
				} else if (My[i + 3] == 2) {
					A2++;           //给剪刀+1
				} else if (My[i + 3] == 3) {
					A3++;           //给布+1
				}
			}
			//往前走四个计算
			else if (My[i] == My[all - 4] && My[i + 1] == My[all - 3] && My[i + 2] == My[all - 2] && My[i + 3] == My[all - 1]) {
				if (My[i + 4] == 1) {
					A1++;           //给石头+1
				} else if (My[i + 4] == 2) {
					A2++;           //给剪刀+1
				} else if (My[i + 4] == 3) {
					A3++;           //给布+1
				}
			}
			//往前走五个计算
			else if (My[i] == My[all - 5] && My[i + 1] == My[all - 4] && My[i + 2] == My[all - 3] && My[i + 3] == My[all - 2]
			         && My[i + 4] == My[all - 1]) {
				if (My[i + 5] == 1) {
					A1++;           //给石头+1
				} else if (My[i + 5] == 2) {
					A2++;           //给剪刀+1
				} else if (My[i + 5] == 3) {
					A3++;           //给布+1
				}
			}

		}
		if (A1 > A2 && A1 > A3) {   //石头最多，出布
			last = 1;
		} else if (A2 > A1 && A2 > A3) { //剪刀最多，出石头
			last = 2;
		} else if (A3 > A1 && A3 > A2) { //布最多，出剪刀
			last = 3;
		} else if (A1 == A2 && A1 > A3) { //石头和剪刀一样多，且都大于布，布石头二选一
			last = 4;
		} else if (A1 == A3 && A1 > A2) { //石头和布一样多，且都大于剪刀，布剪刀二选一
			last = 5;
		} else if (A2 == A3 && A2 > A1) { //剪刀和布一样多，且都大于石头，石头剪刀二选一
			last = 6;
		} else if (A1 == A2 && A2 == A3) { //仨都一样多，随便出
			last = 7;
		}

		last = Sui(last);
		printf("你的出法为：%s\n", Huan(My[all]).c_str());
		printf("机器出法为：%s", Huan(last).c_str()); //表达生成的数字，由函数转为汉字
		printf("——本次对战结果为：");
		if (My[all] == last) {      //计算平局多少局
			middle = middle + 1;
			printf("【平局】\n");
		} else if ((My[all] == 1 && last == 2) || (My[all] == 2 && last == 3) || (My[all] == 3 && last == 1)) { //计算胜多少局
			win = win + 1;
			printf("【获胜】\n");
		} else if ((My[all] == 1 && last == 3) || (My[all] == 2 && last == 1) || (My[all] == 3 && last == 2)) { //计算输多少局
			lose = lose + 1;
			printf("【失败】\n");
		}
		all++;
		winLF = win * 100 / all; //计算获胜概率
		loseLF = lose * 100 / all; //计算失败概率
		middleLF = middle * 100 / all; //计算平局概率
		printf("获胜：%d局，失败：%d局，平局：%d局\n", win, lose, middle);
		printf("获胜概率：%.0lf%，失败概率：%.0lf%，平局概率：%.0lf%\n", winLF, loseLF, middleLF);
		printf("\n");
	}
	return 0;
}
