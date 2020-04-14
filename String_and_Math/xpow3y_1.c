#include<stdio.h>
#include<string.h>

int pow3(int value);

int ctoi(char ch);

int pow_3(int num_1, int num_2);

void d_t(long int num_3);

char itoc(int value_2);

int main() {
        char x_t[256], y_t[256];
        int x_d, y_d, temp, i;
        long int z_d;
        int l_1 = 0, l_2 = 0;
        int count_1 = l_1 - 2;
        int count_2 = l_2 - 2;
        while((count_1 < l_1 - 1) || (count_2 < l_2 - 1)) {
                l_1 = 0;
                l_2 = 0;
                while(!(l_1 && l_2)) {
                        scanf("%s%s", x_t, y_t);
                        l_1 = strlen(x_t);
                        l_2 = strlen(y_t);
                }
                for(i = 0; i < l_1; i++) {
                        count_1 = i;
                        if(x_t[i] != '0' && x_t[i] != '1' && x_t[i] != '2') {
                                break;
                        }
                }
                for(i = 0; i < l_2; i++) {
                        count_2 = i;
                        if(y_t[i] != '0' && y_t[i] != '1' && y_t[i] != '2') {
                                break;
                        }
                }
        }
        x_d = 0;
        temp = 1;
        for(i = 0; i < l_1; i++) {
                if(!i) {
                        x_d = ctoi(x_t[l_1 - 1 - i]);
                }
                else {
                        x_d = x_d + (ctoi(x_t[l_1 - 1 - i]) * (temp = pow3(temp)));
                }
        }
        y_d = 0;
        temp = 1;
        for(i = 0; i < l_2; i++) {
                if(!i) {
                        y_d = ctoi(y_t[l_2 - 1 - i]);
                }
                else {
                        y_d = y_d + (ctoi(y_t[l_2 - 1 - i]) * (temp = pow3(temp)));
                }
        }
        z_d = pow_3(x_d, y_d);
        d_t(z_d);
        return 0;
}

int pow3(int value) {
        int value_1;
        value_1 = value * 3;
        return value_1;
}

int ctoi(char ch) {
        switch(ch) {
                case '0':
                        return 0;
                        break;
                case '1':
                        return 1;
                        break;
                case '2':
                        return 2;
                        break;
                default:
                        return -1;
                        break;
        }
}

int pow_3(int num_1, int num_2) {
        int temp_1, temp_2;
        if(!num_1) {
                return 0;
        }
        else {
                temp_1 = num_2;
                temp_2 = 1;
                while(temp_1) {
                        temp_2 = num_1 * temp_2;
                        temp_1--;
                }
                return temp_2;
        }
}

void d_t(long int num_3) {
        int i = 0, rem, l_3;
        char z_t[1024];
        if(!num_3) {
                printf("0\n");
        }
        else {
                while(num_3) {
                        rem = num_3 % 3;
                        z_t[i] = itoc(rem);
                        num_3 = num_3 / 3;
                        i++;
                }
                z_t[i] = '\0';
                l_3 = strlen(z_t);
                for(i = 0; i < l_3; i++) {
                        printf("%c", z_t[l_3 - 1 - i]);
                }
                printf("\n");
        }
}

char itoc(int value_2) {
        switch(value_2) {
                case 0:
                        return '0';
                        break;
                case 1:
                        return '1';
                        break;
                case 2:
                        return '2';
                        break;
                default:
                        return '#';
                        break;
                }
}

