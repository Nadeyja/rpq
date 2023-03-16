#include <iostream>
#include <fstream>
#include <iomanip>
#include <chrono>
using std::cout;
using std::cin;
using namespace std;

int* algorythm(int* R, int* P, int* Q, int N) {
    int X[100];
    int Used[100];
    int time = 0;
    int f;
    int t;
    int q;
    int q2;
    int id = 0;
    for (int i = 0;i < N;i++) {
        Used[i] = 0;
    }
    for (int i = 0;i < N;i++) {
        f = 0;
        t = 100000;
        q = -1;
        q2 = -1;
        for (int j = 0;j < N;j++) {
            if (R[j] <= time && Used[j] == 0 && Q[j]>q) {
                id = j;
                q = Q[j];
                t = P[j];
                f = 1;

            }
            else if (Used[j] == 0 && f == 0 && R[j]<=t && Q[j]>q2) {
                id = j;
                q2 = Q[j];
                t = R[j];
            }
        }
        if (f == 1) {
            time += t;
        }
        else {
            time = t;
        }
        X[i] = id;
        Used[id] = 1;
        cout << id+1 << " ";
    }
    return X;
}

int main()
{
    auto start = chrono::high_resolution_clock::now();
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
        cout << endl;
        cout << "C = " << C << endl;
    }
    cout << endl << "Sum of C = " << sumOfC << endl;
    f.close();
    auto end = chrono::high_resolution_clock::now();
    double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();

    time_taken *= 1e-9;
    cout << fixed << time_taken << setprecision(9) << " seconds";
    return 0;
}
