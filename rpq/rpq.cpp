#include <iostream>
#include <fstream>
using std::cout;
using std::cin;
using namespace std;

int* algorythm(int* R, int* P, int* Q, int N) {
    int X[100];
    int U[100];
    for (int i = 0;i < N;i++) {
        U[i] = 0;
    }
    for (int j = 0;j < N / 2;j++) {
        int id = 0;
        int r = 100000;
        for (int i = 0;i < N; i++) {
            if (R[i]+P[i] < r && U[i]==0) {
                r = R[i]+P[i];
                U[i] = 1;
                id = i;
            }
        }
        X[j] = id;
        r = 0;
        if (j != N - 1 - j) {
            for (int i = 0;i < N; i++) {
                if (Q[i] > r && U[i] == 0) {
                    r = Q[i];
                    U[i] = 1;
                    id = i;
                }
            }
            X[N - 1 - j] = id;
        }
    }
    return X;
}

int main()
{
    int sumOfC, m, C, N, R[100], P[100], Q[100], *X;
    ifstream f("data.txt");
    string s;
    string data[4] = {"data.1", "data.2", "data.3", "data.4"};
    sumOfC = 0;
    for (int k = 0;k < 4;k++) {
        cout << data[k] << endl;
        while (s != data[k]) {
            f >> s;
        }
        f >> N;
        for (int i = 0;i < N;i++) {
            f >> R[i] >> P[i] >> Q[i];
        }
        cout << N << endl;
        X = algorythm(R, P, Q, N);
        m = 0;
        C = 0;
        for (int i = 0;i < N;i++) {
            m = max(R[X[i]], m) + P[X[i]];
            C = max(m + Q[X[i]], C);
        }
        sumOfC = sumOfC + C;
        cout << "m = " << m << endl;
        cout << "Cmax = " << C << endl;
    }
    cout << endl << "Sum of C = " << sumOfC << endl;
    f.close();
    return 0;
}
