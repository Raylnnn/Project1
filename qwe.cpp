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
