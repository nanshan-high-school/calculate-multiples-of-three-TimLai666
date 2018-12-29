#include <iostream>
#include <math.h>
using namespace std;
int main() {
  string math = "12*34";
  int x = 0;  /* 計數1 */
  int y = 0;  /* 計數2 */
  int a = 0;
  int b = 0;
  int c = 0; /* 計數３ */
  int d = 0;
  int e = 0; /* 計數４ */
  int num1 = 0;
  int num2 = 0;
  int ans = 0;

  /* 計算長度 */
  for(int i = 0; math[i] != '*'; i++) {
    x++;
  }
  for(int i = x + 2/* 略過運算符號 */;math[i] != '\0'; i++) {
    y++;
  }
  d = x + 1;
  string num;

  /* 轉換成數字 */
  for(int i = 0; math[i] != '*'; i++) {
    num[i] = math[i] - '0';
  }
  for(int i = d/* 略過運算符號 */; math[i] != '\0'; i++) {
    num[i] = math[i] - '0';
  }
  
  a = pow(10, x - 1);
  b = pow(10, y - 1);

  for(int i = 0; i < x; i++) {
    num[i] *= a;
    a /= 10;
    c++;
  }
  for(int i = 0; i < y; i++) {
    num[d + i] *= b;
    b /= 10;
    e++;
  }

  

  if(x / 2 * 2 == x) {
    for(int i = 0; i < c; i ++) {
      num1 += num[i] + num[i + 1];
    }
  }else {
    for(int i = 1; i < c; i += 2) {
      num1 += num[i] + num[i + 1];
    }
    num1 += num[0];
  }
  if(y / 2 * 2 == y) {
    for(int i = d; i < e; i ++) {
      num2 += num[i] + num[i + 1];
    }
  }else {
    for(int i = d + 1; i < e; i += 2) {
      num2 += num[i] + num[i + 1];
    }
    num2 += num[d];
  }
  ans = num1 * num2;
  cout<<num1<<'\n';
  cout<<ans;
}
