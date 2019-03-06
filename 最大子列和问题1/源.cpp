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
        for (int j = i; j < K; j++)
        {
            Thissum = 0;
            for (int m = i; m < j; m++)
            {
                Thissum += num[m];
            }
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
    system("pause");
    return 0;
}