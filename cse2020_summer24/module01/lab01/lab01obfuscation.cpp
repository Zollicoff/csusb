#include <cstdio>
#include <fstream>

#define A 100
#define B {}
#define C 0
#define D "search.txt"
#define E "The array: "
#define F "\nEnter the key: "
#define G "\nInvalid input. Please enter an integer: "
#define H "\nThe key "
#define I " is at the index "
#define J "."
#define K "\nThe key is not in the array."

int Z(int a[], int s, int k) {for (int i = 0; i < s; i++) {if (a[i] == k) {return i;}} return -1;}

int main() {int l[A] = B, n = C, s = C, i = C, k = C, x = C;std::ifstream in(D);while (in >> n) {l[i] = n;i++;}in.close();s = i;puts(E);for (int j = 0; j < s; j++) {printf("%d ", l[j]);}puts("");puts(F);while(scanf("%d", &k) != 1) {puts(G);while(getchar() != '\n');}x = Z(l, s, k);if (x != -1) {printf(H "%d" I "%d" J "\n", k, x);} else {puts(K);}return 0;}