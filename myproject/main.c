//
//  main.c
//  myproject
//
//  Created by Xin Liao on 2021/8/10.
//

#include <stdio.h>
int Sum(int N);
long int Factorical(int N);
int MaxSubsequenceSum(const int A[], int N);
int MaxSubsequenceSum2(const int A[], int N);

int main(int argc, const char * argv[]) {
  // insert code here...
  int a = Sum(10);
  printf("a:%d\n", a);
  int b[5] = {1,2,3,4,5};
  int maxSum = MaxSubsequenceSum2(&b, 5);
  printf("b:%d\n", maxSum);
  printf("Hello, World!\n");
  return 0;
}

int Sum(int N) {
  int i, PartialSum;
  PartialSum = 0;
  for (i = 1; i <= N; i++) {
    PartialSum += i * i * i;
  }
  return PartialSum;
}

long int Factorial(int N) {
  if (N <= 1) return 1;
  else
    return N * Factorial(N - 1);
}

int MaxSubsequenceSum(const int A[], int N) {
  int ThisSum, MaxSum, i, j, k;
  MaxSum = 0;
  for (i = 0; i < N; i++) {
    for (j = i; j < N; j++) {
      ThisSum = 0;
      for (k = i; k <= j; k++) {
        ThisSum += A[k];
      }
      if (ThisSum > MaxSum) {
        MaxSum = ThisSum;
      }
    }
  }
  return MaxSum;
}

int MaxSubsequenceSum2(const int A[], int N) {
  int ThisSum, MaxSum, i, j;
  MaxSum = 0;
  
  for (i = 0; i < N; i++) {
    
    ThisSum = 0 ;
    for (j = i; j < N; j++) {
      ThisSum += A[j];
      if (ThisSum > MaxSum) MaxSum = ThisSum;
    }
  }
  return MaxSum;
}
