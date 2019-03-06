#include <iostream>

using namespace std;

int DivideAndConquer(int List[], int Left, int Right);
int Max(int a, int b, int c);

auto main() -> int
{
    int K;
    int num[100000];
    cin >> K;
    for (int i = 0; i < K; i++)
    {
        cin >> num[i];
    }
    cout << DivideAndConquer(num, 0, K - 1);
    return 0;
}
int DivideAndConquer(int List[], int Left, int Right)
{
    int MaxLeftSum, MaxRightSum;             //存放左右两边各自的最大子列和
    int MaxLeftBorderSum, MaxRightBorderSum; //跨界的最大子列和

    int LeftBorderSum, RightBorderSum;
    int center, i;

    if (Left == Right) //递归的终止条件，当子列只有一个数字时
    {
        if (List[Left] > 0)
        {
            return List[Left];
        }
        else
        {
            return 0;
        }
    }
    center = (Left + Right) / 2;
    /*递归求两边的子列和*/
    MaxLeftSum = DivideAndConquer(List, Left, center);
    MaxRightSum = DivideAndConquer(List, center + 1, Right);

    /*求跨界的最大子列和*/
    MaxLeftBorderSum = 0;
    LeftBorderSum = 0;
    for (i = center; i >= Left; i--) //从中间向左扫描跨界部分的左边
    {
        LeftBorderSum += List[i];
        if (LeftBorderSum > MaxLeftBorderSum)
        {
            MaxLeftBorderSum = LeftBorderSum;
        }
    }
    MaxRightBorderSum = 0;
    RightBorderSum = 0;
    for (i = center + 1; i <= Right; ++i)
    {
        RightBorderSum += List[i];
        if (RightBorderSum > MaxRightBorderSum)
        {
            MaxRightBorderSum = RightBorderSum;
        }
    }

    return Max(MaxLeftSum, MaxRightSum, MaxLeftBorderSum + MaxRightBorderSum);
}
int Max(int a, int b, int c)
{
    return a > b ? a > c ? a : c : b > c ? b : c;
}