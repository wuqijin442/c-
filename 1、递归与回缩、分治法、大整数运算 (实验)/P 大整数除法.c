#include <stdio.h>
#include <string.h>
#include <math.h>

char s1[1005], s2[1005];
int n1[1005], n2[1005], ans[1005];

int get_len(int n) {
	if (n == 0) return 1;
    int len = 0;
    while(n) {
    	n /= 10;
    	len++;
    }
    return len;
}

void swap_arr(int *n1, int *n2) {
	int max_len = n1[0] > n2[0] ? n1[0] : n2[0];
	int temp;
	for (int i = 0; i <= max_len; i++) {
		temp = n2[i];
		n2[i] = n1[i];
		n1[i] = temp;
	}
	return ;
}

int get_big(int *a, int *b) {

	if (a[0] < b[0]) return 0;
	if (a[0] == b[0]) {
		for (int i = a[0]; i > 0; i--) {
			if (a[i] == b[i]) continue;
			if (a[i] > b[i]) return 1;
			if (a[i] < b[i]) return 0;
		}
		return 2;
	}
	return 1;
}

int big_sub(int *a, int *b, int *ans_ab) {

	if (get_big(a, b) == 2) return 0;
	ans_ab[0] = a[0];
	for (int i = 1; i <= a[0]; i++) {
		if (a[i] < b[i]) {
			a[i] += 10;
			a[i + 1] -= 1;
		}
		ans_ab[i] = a[i] - b[i];
	}
	int ans_len = ans_ab[0];
	for (int i = ans_ab[0]; i > 0; i--) {
		if (ans_ab[i] == 0) ans_len--;
		if (ans_ab[i] != 0) break;
	}
	ans_ab[0] = ans_len;
	return 1;
}

int big_mul(int *a, int *b, int *ans_ab) {
	ans_ab[0] = a[0] + b[0] - 1;
	for (int i = 1; i <= a[0]; i++) {
		for (int j = 1; j <= b[0]; j++) {
			ans_ab[i + j - 1] += a[i] * b[j];
		}
	}
	for(int i = 1; i <= ans_ab[0]; i++) {
		if (ans_ab[i] > 9) {
			ans_ab[i + 1] += ans_ab[i] / 10;
			ans_ab[i] %= 10;
			if (i == ans_ab[0]) ans_ab[0]++;
		}
	}
	return 1;
}

void big_move_right(int *a, int num) {
	if (a[0] == 0) {
		a[0] = 1;
		a[1] = num;
		return ;
	}
	for(int i = a[0] + 1; i > 1; i--) {
		a[i] = a[i - 1];
	}
	a[1] = num;
	a[0]++;
	return ;
}


int big_div_big(int *a, int *b, int *res, int *res_mod) {

	int _div[1005] = {0};
	int _res[1005] = {0};

	int _res_mul[1005] = {0};
	int _res_sub[1005] = {0};
	int flag = 0;
	for (int i = a[0], j = 1; i > 0; i--, j++) {
		big_move_right(_div, a[i]);
		if (get_big(_div, b) == 0) {
			if (flag) res[0]++;
			continue;
		}
		for (int k = 9; k >= 1; k--) {
			_res[0] = 1;
			_res[1] = k;
			big_mul(_res, b, _res_mul);
			if (get_big(_res_mul, _div) == 1) {
				memset(_res_mul, 0, sizeof(_res_mul));
				continue;
			}

			if (get_big(_res_mul, _div) == 2) {
				res[i] = k;
				flag = 1;
				res[0]++;
				memset(_div, 0, sizeof(_div));
				memset(_res_mul, 0, sizeof(_res_mul));
				break;
			}

			big_sub(_div, _res_mul, _res_sub);
			res[i] = k;
			flag = 1;
			res[0]++;
			memcpy(_div, _res_sub, sizeof(_res_sub));
			memset(_res_mul, 0, sizeof(_res_mul));
			memset(_res_sub, 0, sizeof(_res_sub));
			break;
		}
	}
	memcpy(res_mod, _div, sizeof(_div));
	return 1;
}

int main() {
	int res[1005] = {0}, res_mod[1005] = {0};
	while (~scanf("%s %s", s1, s2)) {
		int n1_len = strlen(s1);
		int n2_len = strlen(s2);
		n1[0] = n1_len;
		n2[0] = n2_len;
		for (int i = 1, j = n1[0] - 1; i <= n1[0]; i++, j--) {
			n1[i] = s1[j] - '0';
		}
		for (int i = 1, j = n2[0] - 1; i <= n2[0]; i++, j--) {
			n2[i] = s2[j] - '0';
		}


		/*int x = 0, y = 0;
		for (int i = n1[0]; i > 0; i--) {
			x = x * 10 + n1[i];
		}
		for (int i = n2[0]; i > 0; i--) {
			y = y * 10 + n2[i];
		}
		printf("%d %d\n", x/y, x%y);

		int n1_n2_flag = get_big(n1, n2);
		if (n1_n2_flag == 2) {
			/*printf("%d %d\n", 1, 0);
			continue;
		}
		if (n1_n2_flag == 0) {
			printf("%d ", 0);
			for(int i = n1[0]; i > 0; i--) {
				printf("%d", n1[i]);
			}
			continue;
		}*/
		big_div_big(n1, n2, res, res_mod);
		for(int i = res[0]; i > 0; i--) {
			printf("%d", res[i]);
		}
		printf("\n");
		for(int i = res_mod[0]; i > 0; i--) {
			printf("%d", res_mod[i]);
		}
		printf("\n");
		memset(res, 0, sizeof(res));
		memset(res_mod, 0, sizeof(res_mod));
		printf("\n");
	}
	return 0;
}
