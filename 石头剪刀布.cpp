#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <cstdlib>
#include <ctime>
#include <windows.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

string Huan(int a) {        //"��"��������ת��Ϊ����
	string b;               //����������
	int x;                  //��ѡһ�õ�
	int T;                  //������õ�
	srand((int)time(0));    //���������
	if (a == 1) {
		b = "1.ʯͷ";
	} else if (a == 2) {
		b = "2.����";
	} else if (a == 3) {
		b = "3.��";
	}
	return b;
}

int Sui(int a) {            //"��"������õģ������Ҳ�ã���һ�𷽱�
	int b = 1;              //������
	int T;                  //���������
	srand((int)time(0));    //���������
	if (a == 1) {           //ʯͷ��࣬����
		b = 3;
	} else if (a == 2) {    //������࣬��ʯͷ
		b = 1;
	} else if (a == 3) {    //����࣬������
		b = 2;
	} else if (a == 4) {    //ʯͷ����һ���࣬�Ҷ��Ȳ��࣬��ʯͷ
		b = 1;              //��ʯͷ
	} else if (a == 5) {    //ʯͷ�Ͳ�һ���࣬�Ҷ��ȼ����࣬����
		b = 3;              //����
	} else if (a == 6) {    //�����Ͳ�һ���࣬�Ҷ�����ʯͷ��������
		b = 2;              //������
	} else if (a == 7) {    //���������
		b = rand() % 3 + 1;
	}
	return b;
}

int max(int a, int b, int c) { //�������������
	if (a > b)
		b = a;
	if (b > c)
		c = b;
	return c;
}

int main(int argc, char **argv) {
	printf("ǰʮ��Ϊ����׶Σ�ʮ�κ��㷨����\n");
	printf("ǰʮ��Ϊ����׶Σ�ʮ�κ��㷨����\n");
	printf("ǰʮ��Ϊ����׶Σ�ʮ�κ��㷨����\n\n");
	int acre = 0;
	int My[2000];                       //My���Լ��ĳ�����¼
	int win = 0, lose = 0, middle = 0, all = 0; //win��ʤ���Σ�loseʧ�ܳ��Σ�middle�м䳡�Σ�all���г���
	double winLF, loseLF, middleLF;     //winLF��ʤ���ʣ�loseLFʧ�ܸ��ʣ�middleLFƽ�ָ���

	printf("��������ѡ��ĳ�����1.ʯͷ 2.���� 3.�����������֣�\n");

	for (; all < 10;) {
line1:
		scanf("%d", &acre);          	//�����Լ��ĳ���
		if (acre >= 1 && acre <= 3) {
			My[all] = acre;
		} else {
			printf("���벻�Ϸ�\n");
			goto line1;
		}
		srand((int)time(0));            //���������
		int x = rand() % 3 + 1;         //���������
		printf("��������Ϊ��%s\n", Huan(x).c_str()); //������ɵ����֣��ɺ���תΪ����

		if (My[all] == x) {             //����ƽ�ֶ���
			middle = middle + 1;
		} else if ((My[all] == 1 && x == 2) || (My[all] == 2 && x == 3) || (My[all] == 3 && x == 1)) { //����ʤ����
			win = win + 1;
		} else if ((My[all] == 1 && x == 3) || (My[all] == 2 && x == 1) || (My[all] == 3 && x == 2)) { //���������
			lose = lose + 1;
		}
		all++;

		winLF = win * 100 / all;        //�����ʤ����
		loseLF = lose * 100 / all;      //����ʧ�ܸ���
		middleLF = middle * 100 / all;  //����ƽ�ָ���
		printf("��ʤ��%d�֣�ʧ�ܣ�%d�֣�ƽ�֣�%d��\n", win, lose, middle);
		printf("��ʤ���ʣ�%.0lf%��ʧ�ܸ��ʣ�%.0lf%��ƽ�ָ��ʣ�%.0lf%\n", winLF, loseLF, middleLF);
	}
	printf("������,���Ժ�");;
	printf("��");
	Sleep(700);
	printf("��");
	Sleep(700);
	printf("��");
	Sleep(700);
	printf("��\n");;

	for (int i = 0; i < 30; i++) {
		printf("-");
		Sleep(25);
	}
	printf("\n");
	printf("��������ѡ��ĳ�����1.ʯͷ 2.���� 3.��\n");
	//���¿�ʼ�㷨

	int Stop = 1;                   //����while��ֹͣ����
	int last = 0;                   //�����

	while (Stop) {
		int A1 = 0, A2 = 0, A3 = 0; //A1ʯͷ������A2����������A3������

		scanf("%d", &acre);
		if (acre >= 1 && acre <= 3) {
			My[all] = acre;
		} else {
			printf("���벻�Ϸ�\n");
			continue;
		}

		for (int i = 0; i < all - 5; i++) { //��ʼ����
			//��ǰ����������
			if (My[i] == My[all - 3] && My[i + 1] == My[all - 2] && My[i + 2] == My[all - 1]) {
				if (My[i + 3] == 1) {
					A1++;           //��ʯͷ+1
				} else if (My[i + 3] == 2) {
					A2++;           //������+1
				} else if (My[i + 3] == 3) {
					A3++;           //����+1
				}
			}
			//��ǰ���ĸ�����
			else if (My[i] == My[all - 4] && My[i + 1] == My[all - 3] && My[i + 2] == My[all - 2] && My[i + 3] == My[all - 1]) {
				if (My[i + 4] == 1) {
					A1++;           //��ʯͷ+1
				} else if (My[i + 4] == 2) {
					A2++;           //������+1
				} else if (My[i + 4] == 3) {
					A3++;           //����+1
				}
			}
			//��ǰ���������
			else if (My[i] == My[all - 5] && My[i + 1] == My[all - 4] && My[i + 2] == My[all - 3] && My[i + 3] == My[all - 2]
			         && My[i + 4] == My[all - 1]) {
				if (My[i + 5] == 1) {
					A1++;           //��ʯͷ+1
				} else if (My[i + 5] == 2) {
					A2++;           //������+1
				} else if (My[i + 5] == 3) {
					A3++;           //����+1
				}
			}

		}
		if (A1 > A2 && A1 > A3) {   //ʯͷ��࣬����
			last = 1;
		} else if (A2 > A1 && A2 > A3) { //������࣬��ʯͷ
			last = 2;
		} else if (A3 > A1 && A3 > A2) { //����࣬������
			last = 3;
		} else if (A1 == A2 && A1 > A3) { //ʯͷ�ͼ���һ���࣬�Ҷ����ڲ�����ʯͷ��ѡһ
			last = 4;
		} else if (A1 == A3 && A1 > A2) { //ʯͷ�Ͳ�һ���࣬�Ҷ����ڼ�������������ѡһ
			last = 5;
		} else if (A2 == A3 && A2 > A1) { //�����Ͳ�һ���࣬�Ҷ�����ʯͷ��ʯͷ������ѡһ
			last = 6;
		} else if (A1 == A2 && A2 == A3) { //��һ���࣬����
			last = 7;
		}

		last = Sui(last);
		printf("��ĳ���Ϊ��%s\n", Huan(My[all]).c_str());
		printf("��������Ϊ��%s", Huan(last).c_str()); //������ɵ����֣��ɺ���תΪ����
		printf("�������ζ�ս���Ϊ��");
		if (My[all] == last) {      //����ƽ�ֶ��پ�
			middle = middle + 1;
			printf("��ƽ�֡�\n");
		} else if ((My[all] == 1 && last == 2) || (My[all] == 2 && last == 3) || (My[all] == 3 && last == 1)) { //����ʤ���پ�
			win = win + 1;
			printf("����ʤ��\n");
		} else if ((My[all] == 1 && last == 3) || (My[all] == 2 && last == 1) || (My[all] == 3 && last == 2)) { //��������پ�
			lose = lose + 1;
			printf("��ʧ�ܡ�\n");
		}
		all++;
		winLF = win * 100 / all; //�����ʤ����
		loseLF = lose * 100 / all; //����ʧ�ܸ���
		middleLF = middle * 100 / all; //����ƽ�ָ���
		printf("��ʤ��%d�֣�ʧ�ܣ�%d�֣�ƽ�֣�%d��\n", win, lose, middle);
		printf("��ʤ���ʣ�%.0lf%��ʧ�ܸ��ʣ�%.0lf%��ƽ�ָ��ʣ�%.0lf%\n", winLF, loseLF, middleLF);
		printf("\n");
	}
	return 0;
}
