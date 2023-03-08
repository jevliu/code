/*
归并排序算法中合并两个已经排序好的序列的辅助算法MERGE
2023/3/7
*/
#include <iostream>
using namespace std;
// 不使用哨兵的实现
void Merge1(int *A, int p, int q, int r)
{
    // 构建左半部分和右半部分的辅助数组
    int n1 = q - p + 1;
    int n2 = r - q;
    int *L = new int[n1];
    int *R = new int[n2];

    // 将原数组中的变量复制到两个辅助数组中
    for (int i = 0; i < n1; i++)
    {
        L[i] = A[p + i - 1];
    }
    for (int j = 0; j < n2; j++)
    {
        R[j] = A[q + j];
    }
    int i = 0;
    int j = 0;
    int k = p - 1;

    // 使用一个while循环保证当数量较小的一堆被拿出后，循环停止
    while ((i <= n1 - 1) && (j <= n2 - 1))
    {
        if (L[i] <= R[j])
        {
            A[k] = L[i];
            i++;
        }
        else
        {
            A[k] = R[j];
            j++;
        }
        k++;
    }

    while (i <= n1 - 1)
    {
        A[k] = L[j];
        i++;
        k++;
    }

    while (j <= n2 - 1)
    {
        A[k] = R[j];
        j++;
        k++;
    }
    delete[] L;
    delete[] R;
}

// 使用哨兵的方法
void Merge2(int *A, int p, int q, int r)
{
    // 创建两个辅助数组并分配长度
    int n1 = q - p + 1;
    int n2 = r - p;
    // 多增加一位用于确定标志位
    int *L = new int[n1 + 1];
    int *R = new int[n2 + 1];

    // 将原数组中的值分别分别分配到这两个辅助数组中
    for (int i = 0; i < n1; i++)
    {
        L[i] = A[p + i];
    }
    for (int j = 0; j < n2; j++)
    {
        R[j] = A[q + j + 1];
    }
    // 添加哨兵
    L[n1] = R[n2] = INT_MAX;
    // 依次按位比较两组数对应数的大小并取出较小的值
    int i = 0;
    int j = 0;
    for (int k = p; k <= r; k++)
    {
        if (L[i] < R[j])
        {
            A[k] = L[i];
            i++;
        }
        else
        {
            A[k] = R[j];
            j++;
        }
    }

    delete[] L;
    delete[] R;
}

// 创建使用归并算法的排序函数
void MergeSort(int *A, int p, int r)
{
    if (p < r)
    {
        int q = (p + r) / 2;
        // 递归调用函数
        MergeSort(A, p, q);
        MergeSort(A, q + 1, r);
        // 合并已经排序好的两个序列
        Merge2(A, p, q, r);
    }
}

int main()
{
    int A[] = {2,
               4,
               5,
               7,
               1,
               2,
               3,
               6};
    int size = sizeof(A) / sizeof(A[0]);
    MergeSort(A, 0, size - 1);
    for (int i = 0; i < size; i++)
    {
        cout << A[i] << " ";
    }
    return 0;
}