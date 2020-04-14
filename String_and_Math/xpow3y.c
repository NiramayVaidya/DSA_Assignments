#include <stdio.h>

double xpowy(int x, int y); 

int main() {
        int x, y;
        scanf("%d%d", &x, &y);
        printf("%lf\n", xpowy(x, y));
        return 0;
}

double xpowy(int x, int y) {
        long long ans = 1;
        long long term = x;
        int sign = 0;
        if(y < 0) {
                sign = 1;
                y = -y;
        }
        while(y > 0) {
                if(y % 3 == 1) {
                        ans = ans * term;
		}
		else if(y % 3 == 2) {
			ans = ans * term * term;
		}
                term = term * term * term;
                y = y / 3;
        }
        if(sign) {
                return 1.0 / ans;
	}
        return ans;
}
	
