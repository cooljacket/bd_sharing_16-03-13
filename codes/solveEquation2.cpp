#include <stdio.h>


// to find out all positive solutions for equation like: ax + by = c
void solve(int a, int b, int c) {
	int cnt = 0;
	for (int x = 1; x <= c/a; ++x) {
		int y = (c - a*x) / b;
		if (y > 0 && a*x + b*y == c)
			printf("[solu %d] x=%d, y=%d\n", ++cnt, x, y);
	}

	if (cnt == 0)
		printf("No suitable solution for the equation %dx + %dy = %d\n", a, b, c);
}


int main() {
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	solve(a, b, c);

	return 0;
}