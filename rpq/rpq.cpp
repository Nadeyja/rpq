#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    int N, R[100], P[100], Q[100], X[100];
    ifstream f("data.txt");
    string s; 
    while (s != "data.1") {
        f >> s;
    }
    f>>N; 
    for (int i = 0;i < N;i++) {
        f >> R[i] >> P[i] >> Q[i];
    }
    f.close();

    cout << N << endl;

    return 0;
}
