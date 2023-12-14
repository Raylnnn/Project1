\\输入身份证，按年龄排序

#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
int birthday(char s[]) {
	int i, j,sum=0;
	for (i = 6; i < 14; i++) {
		sum *= 10;
		sum += s[i] - '0';
	}
	return sum;
}
int main() {
	struct pp{
		int b;
		char c[20];
	}p[0x3f],x;
	int  n, j,i = 0,k;
	char *a;
	scanf("%d", &n);
	while (n--) {
		scanf("%s", p[i].c);
		a = p[i].c;
		p[i].b = birthday(a);
		i++;
	}
	for (j = 0; j < i; j++) {
		for (k = 0; k < i - j-1; k++) {
			if (p[k].b > p[k + 1].b) {
				x = p[k];
				p[k] = p[k + 1];
				p[k + 1] = x;
			}
		}
	}
	for (j = 0; j < i; j++) {
		printf("%s\n", p[j].c);
	}
	return 0;
}

//7-9 最长的单词
输入一个字符串，将此字符串中最长的单词输出。要求至少使用一个自定义函数。
输入格式:
测试数据有多组，处理到文件尾。每组测试数据输入一个字符串（长度不超过80）。
输出格式:
对于每组测试，输出字符串中的最长单词，若有多个长度相等的最长单词，输出最早出现的那个。这里规定，单词只能由大小写英文字母构成。
输入样例:
Keywords insert, two way insertion sort,
Abstract This paper discusses three method for two way insertion
words. insert, two way sorted.
You're a boy.
I'am a c.
输出样例:
insertion
discusses
insert
You
am

#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
void f(char* a) {
	int i, j, max = 0, n, cnt[0x3f3f] = { 0 };
	for (i = 0; a[i] != '\n'; i++) {
		if (a[i] >= 'A' && a[i] <= 'Z' || a[i] >= 'a' && a[i] <= 'z') {
			for (j = i; a[j] >= 'A' && a[j] <= 'Z' || a[j] >= 'a' && a[j] <= 'z'; j++);
			cnt[i] = j - i;
			i = j - 1;
		}
	}

	for (i = 0; a[i] != '\n'; i++) {
		if (cnt[i] > cnt[max]) max = i;
	}
	for (i = max; a[i] >= 'A' && a[i] <= 'Z' || a[i] >= 'a' && a[i] <= 'z'; i++) {
		printf("%c", a[i]);
	}
	printf("\n");

}
int main() {
	char a[0x3f3f];

	while (fgets(a, 0x3f3f, stdin)) {
		f(a);

	}
	return 0;
}
