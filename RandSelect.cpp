#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>

const int maxn = 100010;
int A[maxn], n; //A存放所有整数, n为其个数

//生成[left, right]范围内的随机数
int generateRandomNum_Range_fromLeft2Right(int left, int right){
    srand((unsigned)time(NULL)); //生成随机数种子
    
    return (int)(round(1.0 * rand()/RAND_MAX * (right-left) + left));
}

//交换a和b的值
void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

//随机指定主元A[p]
int randPartition(int A[], int left, int right){
    int p = generateRandomNum_Range_fromLeft2Right(left, right);
    swap(&A[p], &A[left]);
    
    int temp = A[left];
    while (left < right) //当left与right相遇时退出
    {
        while (left < right && A[right] > temp) right--;
        A[left] = A[right];
        while (left < right && A[left] <= temp) left++;
        A[right] = A[left];
    }

    A[left] = temp; //将temp放到left与right相遇的地方

    return left; //返回相遇的下标
}

//随机选择算法，从无序的数组---A[left, right]中返回第K大的数
int randSelect(int A[], int left, int right, int K){
    //递归边界
    if(left == right) return A[left]; //边界

    int p = randPartition(A, left, right); //主元的位置为p
    int M = p - left + 1; //A[p]是A[left, right]中第M大的数

    if(K == M) return A[p]; //找到第K大的数
    if (K < M)
    {
        return randSelect(A, left, p-1, K); //往主元左侧找第K大的数
    }else
    {
        return randSelect(A, p+1, right, K-M); //往主元右侧找第K-M大的数
    }  
}


int main(){
     
    //随机选择算法，从无序的数组---A[left, right]中返回第K大的数：
    /*
    int A[100] = {6, 5, 12, 7, 2, 9, 3};
    int n = A[0]; //A[0]存放实际长度
    int K = 3;

    int result = randSelect(A, 1, n, K);
    //最坏时间复杂度为O(n*n); 对任意输入的期望时间复杂度却是O(n).
    printf("%d\n", result); */

    //sum和sumL记录所有整数之和与切分后前n/2个元素之和
    int sum = 0, sumL = 0;
    printf("请输入整数个数:");
    scanf("%d", &n); 
    /* 给定一个由整数组成的集合，集合中的整数各不相同，
    现在要将它分为两个子集合，使得这两个子集合的并为原集合、交为空集，
    同时在两个子集合的元素个数 n1，n2 之差的绝对值|n1-n2|尽可能小的前提下，
    要求它们各自的元素之和 S1，S2差的绝对值|S1-S2|尽可能大 
    求这个|S1-S2|等于多少 
    等效于：求原集合中第n/2大的数
    */
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &A[i]); //输入整数
        sum += A[i]; //累计所有整数之和
    }
    randSelect(A, 0, n-1, n/2); //寻找第n/2大的数，并进行切分
    for (int i = 0; i < n/2; i++)
    {
        sumL += A[i]; //累计较小的子集合中元素之和
    }
    int sumR = (sum - sumL); //较大的子集合中元素之和
    //printf("较小的子集合中元素之和: %d\n", sumL); 
    //printf("较大的子集合中元素之和: %d\n", sumR); 

    printf("两个子集合的元素和之差: %d\n", sumR - sumL); //求两个子集合的元素和之差

    return 0;
} 