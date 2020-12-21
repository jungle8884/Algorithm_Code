#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>

//指定A[left]为主元
int Partition(int A[], int left, int right){
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

//快速排序的递归实现
void quickSort(int A[], int left, int right){
    if(left < right){ //当前区间的长度超过1
        //int pos = Partition(A, left, right);
        int pos = randPartition(A, left, right); //采用随即划分

        //对该元素的左侧和右侧分别进行递归调整，直到当前调整区间的长度不超过1。
        quickSort(A, left, pos-1);
        quickSort(A, pos+1, right);
    }
}

int main(){
    int A[] = {11, 35, 18, 16, 72, 24, 65, 12, 88, 46, 28, 55}; //A[0]存放数组长度
    quickSort(A, 1, 11);
    for (int i = 1; i <= A[0]; i++) 
    {
        printf("%d ", A[i]);
    }
    
    return 0;
}