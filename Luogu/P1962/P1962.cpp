#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

constexpr int N = 5;
constexpr int L = 2;
constexpr i64 MOD = 1e9 + 7;

i64 n;

struct Matrix {
	i64 M[N][N];
	void clear() {
		memset(M, 0, sizeof(M));
	}
	void reset() {
		clear();
		for (int i = 0; i < L; i++)
			M[i][i] = 1;
	}
	Matrix friend operator * (const Matrix &X, const Matrix &Y) {
		Matrix Res;
		Res.clear();
		for (int i = 0; i < L; i++)
			for (int j = 0; j < L; j++)
				for (int k = 0; k < L; k++)
					Res.M[i][j] = (Res.M[i][j] + X.M[i][k] * Y.M[k][j]) % MOD;
		return Res;
	}
} A;

Matrix expow(Matrix T, i64 P) {
	Matrix Res;
	Res.reset();
	while (P) {
		if (P & 1)
			Res = Res * T;
		T = T * T;
		P >>= 1;
	}
	return Res;
}

int main() {
	scanf("%lld", &n);
	if (n <= 2) {
		printf("1\n");
		return 0;
	}
	
	A.M[0][0] = 1, A.M[0][1] = 1;
	A.M[1][0] = 1, A.M[1][1] = 0;
	
	A = expow(A, n - 2);
	printf("%lld\n", (A.M[0][0] + A.M[0][1]) % MOD);
	return 0;
}
