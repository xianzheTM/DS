#include <iostream>
using namespace std;
int main()
{
    int K, num[100000];
    cin >> K;
    for (int i = 0; i < K; i++)
    {
        cin >> num[i];
    }
    int Thissum = 0, Maxsum = 0;
    int x = 0, t = 0, y = K - 1;
    for (int i = 0; i < K; i++)
    {
        Thissum += num[i];
        if (Thissum > Maxsum)
        {
            Maxsum = Thissum;
            x = t;
            y = i;

        }
        else if (Thissum < 0)
        {
            Thissum = 0;
            t = i + 1;
        }
    }
    if (Maxsum < 0)//Maxsum < 0 说明整个序列全为负数，根据题意，最大和应该为0 
        Maxsum = 0;
    cout << Maxsum << " " << num[x] << " " << num[y] << endl;
    system("pause");
    return 0;
}