#include <iostream>

using namespace std;
int main()
{
    int K;
    int num[100000];
    cin >> K;
    for (int i = 0; i < K; i++)
    {
        cin >> num[i];
    }
    int Thissum, Maxsum = 0;
    for (int i = 0; i < K; i++)
    {
        Thissum = 0;
        for (int j = i; j < K; j++)
        {
            Thissum += num[j];
            if (Thissum > Maxsum)
            {
                Maxsum = Thissum;
            }
        }
    }
    if (Maxsum >= 0)
    {
        cout << Maxsum;
    }
    else
    {
        cout << 0;
    }
    return 0;
}