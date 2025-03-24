#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Chức năng 1: Đếm số phần tử chia hết cho 3 trong mảng (đệ quy)
int CountDivisibleBy3(int A[], int n) {
    if (n == 0) return 0; 
    int count = (A[n - 1] % 3 == 0) ? 1 : 0; 
    return count + CountDivisibleBy3(A, n - 1); 
}

// Chức năng 2: Chuẩn hóa chuỗi (loại bỏ khoảng trắng thừa)
void normalizeString(char *s) {
    if (s == NULL || s[0] == '\0') return; 

    int len = strlen(s);
    int start = 0, end = len - 1;

    while (s[start] == ' ') start++; 
    while (end > start && s[end] == ' ') end--; 

    if (start > end) {
        s[0] = '\0';
        return;
    }

    int j = 0, space_flag = 0;
    for (int i = start; i <= end; i++) {
        if (s[i] != ' ') {
            s[j++] = s[i];
            space_flag = 0;
        } else if (!space_flag) {
            s[j++] = ' ';
            space_flag = 1;
        }
    }
    s[j] = '\0';
}

// Chức năng 3: Kiểm tra số hoàn hảo
int isPerfectNumber(int x) {
    if (x < 2) return 0; 

    int sum = 1; 
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            sum += i;
            if (i != x / i) sum += x / i;
        }
    }
    return sum == x;
}

// Chức năng 4: Tìm địa chỉ số hoàn hảo đầu tiên trong mảng
int* AddressOfPerfectEle(int A[], int n) {
    for (int i = 0; i < n; i++) {
        if (isPerfectNumber(A[i])) {
            return &A[i]; 
        }
    }
    return NULL; 
}

// Chức năng 5: Kiểm tra số hoàn hảo bằng cách khác (trùng logic nhưng giữ nguyên theo yêu cầu)
int isPerfectNumber2(int x) {
    if (x < 2) return 0; 

    int sum = 1; 
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            sum += i;
            if (i != x / i) sum += x / i;
        }
    }
    return sum == x;
}

int main() {
    printf("Chuong trinh da gop 5 chuc nang vao mot file.\n");
    printf("Vui long goi tung ham theo yeu cau cua ban.\n");

    return 0;
}
