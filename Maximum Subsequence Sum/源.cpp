/*
 * 这道题表意不明,测试用例也有问题.请测试下面的代码:
 * 
 */

 /*
  *using namespace std;
  *int A[10010];
  *
  *int main()
  *{
  *   int k, i;
  *  cin >> k;
  * for (i = 0; i < k; i++)
  *    cin >> A[i];
  *int left = 0, right = k - 1, maxSum = -1, thisSum = 0, tempLeft; //maxSum赋初值为-1为了解决出现全部序列为负的情况
  *for (i = 0; i < k; i++)
  *  {
  *     thisSum += A[i];
  *
  *        if (thisSum > maxSum) //如果临时序列和大于最大和，则更新最大和
  *       {
  *          maxSum = thisSum;
  *         left = tempLeft; //将临时左端的序号赋值给左端序号
  *        right = i;
  *   }
  *         else if (thisSum < 0) //thisSum小于0时，从此刻下一个开始重新求和
  *        {
  *           thisSum = 0;
  *          tempLeft = i + 1; //把此刻的下一序号赋值给临时左端序号
  *     }
  *  }
  * if (maxSum < 0) //maxSum < 0 说明整个序列全为负数，根据题意，最大和应该为0
  *    maxSum = 0;
  *   cout << maxSum << " " << A[left] << " " << A[right] << endl;
  *
  *  return 0;
  * }
  */
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