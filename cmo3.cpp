#include <iostream>
#include <math.h>
using namespace std;
void doing1(string); // 計算長度
void doing2(string, int, int); // 製造數字
void doing3(int, int); // 相乘
void doing4(int); // 檢查是否為三的倍數

int main() {
    string math;
    cout << "輸入乘法算式, ex:12*34:\n";
    cin >> math;
    doing1(math);
}


void doing1(string math) {
    int length1 = 0, length2 = 0;
    for(int i = 0; math[i] != '*'; i++) {
        length1++;
    }
    for(int i = length1 + 1; math[i] != '\0'; i++) {
        length2++;
    }

    doing2(math, length1, length2);
}


void doing2(string math, int l1, int l2) {
    int making1 = l1 - 1, making2 = l2 - 1, tenpow1 = 0, tenpow2 = 0;
    for(int i = 0; i < l1; i++) {
        math[i] -= '0';
    }
    for(int i = l1 + 1; i < l1 + l2 + 1; i++) {
        math[i] -= '0';
    }

    tenpow1 = pow(10, making1);
    tenpow2 = pow(10, making2);
    for(int i = 0; i < l1; i++) {
        math[i] *= tenpow1;
        tenpow1 /= 10;
    }
    for(int i = l1 + 1; i < l1 + l2 + 1; i++) {
        math[i] *= tenpow2;
        tenpow2 /= 10;
    }


    int firstnum = 0, secondnum = 0;
    for(int i = 0; i < l1; i++) {
        firstnum += math[i];
    }
    for(int i = l1 + 1; i < l1 + l2 + 1; i++) {
        secondnum += math[i];
    }

    doing3(firstnum, secondnum);
}


void doing3(int first, int second) {
    int total = first * second;

    doing4(total);
}


void doing4(int total) {
    string output;
    if(total / 3 * 3 == total) {
        output = "是三的倍數";
    }else {
        output = "不是三的倍數";
    }
    cout << '\n' << total << ' ' << output << '\n';
}