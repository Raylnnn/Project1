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

\*7-9 最长的单词
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
am *\

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

\\舍入问题完整版（函数）
double power(double a, int p) {
    double ret = 1.0,  j = 0;

    if (p < 0) { p *= -1; j = 1; }
    do {
        if (p & 1) ret *= a * 1.0;
        p /= 2;
        a *= a;

    } while (p > 0);

    if (j == 0) return ret;
    else return 1.0 / ret;
}

double Round(double x, int d) {
    double i = power(10, d);
    int j;
    if (x < 0) j = x * i - 0.5;
    else j = x * i + 0.5;
    return j * 1.0 / i;
}

\\螺旋方阵
#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>

int main() {
	int a[0x3f][0x3f], b, c[0x3f], i=0, j=0, f = 0, sum = 0, m, n, max[0x3f], t, k[0x3f];
	scanf("%d", &n);
	m = 1;
	t = n;
	do {
		for (; j < n && m <= t * t; j++) {
			a[i][j] = m;
			m++;
		}
		j--;
		i++;
		for (; i < n && m <= t * t; i++) {
			a[i][j] = m;
			m++;
		}
		i--;
		j--;
		for (; j >= t - n && m <= t * t; j--) {
			a[i][j] = m;
			m++;
		}
		j++;
		i--;
		for (; i > t - n && m <= t * t; i--) {
			a[i][j] = m;
			m++;
		}
		i++;
		j++;
	} while (--n);
	for (i = 0; i < t; i++) {
		for (j = 0; j < t; j++) {
			printf("%3d", a[i][j]);
		}
		printf("\n");
	}

	return 0;
}

\\问题在哪？（school OJ）
#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
char* insert(char* str, char c) {
	char* strr = str;
	char* p = strr;
	int f = 0,i=0;
	while (*str) {
		if (c <= *str&&f==0) {
			f = 1;
			*strr = c;
			strr++;
			continue;
		}else{
			*strr = *str;
			str++;
			strr++;
		}
	}
	if (f == 0) { *strr = c; strr++; }
	*strr = '\0';
	return p;
}
int main() {
	char str[55], c;
	scanf("%s", str);
	getchar();
	scanf("%c", &c);
	printf("%s", insert(str, c));
	return 0;
}

\\加密文件 eg.feather->a:f,b:e,c:a,...h:z,i:y,...
#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
int main() {
	FILE* p1, * p2;
	char* pas, * a,t,*str;
	a = (char*)malloc(100);
	pas = (char*)malloc(100);
	str = (char*)malloc(10000);
	int i, j, k=0,f;
	scanf("%s", a);
	for (i = 0; i < strlen(a); i++) {
		f = 0;
		for (j = i-1; j >=0; j--) {
			if (a[i] == a[j]) {
				f = 1; break;
			}
		}
		if (!f) {
			pas[k] = a[i]; k++;
		}
	}
	pas[k] = '\0'; t = 'z';
	int l = strlen(pas);
	for (; t>='a'; t--) {
		f = 0;
		for (j = 0; j <l; j++) {
			if (pas[j] == t) {
				f = 1; break;
			}
		}
		if (!f) {
			pas[k] = t;  k++;
		}
	}
	pas[k] = '\0';
	if ((p1 = fopen("encrypt.txt", "r")) == NULL) {
		printf("Error\n");
		exit(0);
	}
	if ((p2 = fopen("output.txt", "w")) == NULL) {
		printf("Error\n");
		exit(0);
	}
	fgets(str, 10000, p1);
	for (i = 0; i < strlen(str); i++) {
		if (str[i] >= 'a' && str[i] <= 'z') {
			str[i] = pas[str[i] - 'a'];
		}
	}
	fputs(str, p2);
	fclose(p1);
	fclose(p2);
	free(a);
	free(pas);
	free(str);
	return 0;
}

\\整数的N进制转化
#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
void itob(int n, char* s, int b) {
	int i = 0,j,N,a;
	N = n;
	if (n < 0) n *= -1;
	do{
		j = n % b;
		if (j <= 9) s[i] = j + '0';
		else s[i] = j - 10 + 'a';
		i++;
		n /= b;
	} while (n > 0);
	if (N < 0) {
		s[i] = '-'; i++;
	}
	s[i] = '\0';
	for (j = 0; j < strlen(s) / 2; j++) {
		a = s[j];
		s[j] = s[--i];
		s[i] = a;

	}
}
int main() {
	int n, b;
	char s[0x3f];
	scanf("%d%d", &n, &b);
	itob(n, s, b);
	int i = 0;
	for (; i < strlen(s); i++) {
		printf("%c", s[i]);
	}
	return 0;
}
