#include<stdio.h>

int main() {
	int n, m, p;
	int i, j, x, y, a, b, c;
	scanf("%d%d%d", &n, &m, &p);
	int matrix_1[n][m], matrix_2[m][p], matrix_3[n][p];
	int sum = 0;
	for(i = 0; i < n; i++) {
		for(j = 0; j < m; j++) {
			scanf("%d", &matrix_1[i][j]);
//			printf("%d", matrix_1[i][j]);
		}
	}
	for(x = 0; x < m; x++) {
		for(y = 0; y < p; y++) {
			scanf("%d", &matrix_2[x][y]);
//			printf("%d", matrix_2[x][y]);
		}
	}
	for(a = 0; a < n; a++) {
		for(b = 0; b < p; b++) {
			for(c = 0; c < m; c++) {
				sum = sum + matrix_1[a][c] * matrix_2[c][b];
			}
			matrix_3[a][b] = sum;
			sum = 0;
			printf("%d\n", matrix_3[a][b]);
		}
	}
}
				

