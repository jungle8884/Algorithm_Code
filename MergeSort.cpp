# include<cstdio>
# include<cmath>

const int maxn = 100;

//合并两个递增数组，并返回合并后的长度
int merge(int A[], int B[], int C[], int n, int m){
    int i = 0, j = 0, index = 0;
    while (i < n && j < m)
    {
        if(A[i] <= B[j]){
            C[index++] = A[i++];
        }else
        {
            C[index++] = B[j++];
        }
        
    }
    while (i < n) C[index++] = A[i++];
    while (j < m) C[index++] = B[j++];   

    return index; //返回序列C的长度
}


/*
2-路归并排序的递归写法(参考上面的代码)
将数组A的[L1, R1]与[L2, R2]区间合并为有序区间(此处L2即为R1+1)
时间复杂度为：O(nlogn)
*/
void merge(int A[], int L1, int R1, int L2, int R2){    
    int i = L1, j = L2;
    int temp[maxn], index = 0; //temp临时存放合并后的数组，index为其下标
    while (i <= R1 && j <= R2)
    {
        if (A[i] <= A[j])
        {
            temp[index++] = A[i++];
        }else
        {
            temp[index++] = A[j++];
        }       
    }
    while (i <= R1) temp[index++] = A[i++];
    while (j <= R2) temp[index++] = A[j++];
    for (int i = 0; i < index; i++)
    {
        A[L1+i] = temp[i]; //将合并后的序列赋值回数组A
    }
    
}

//将数组当前区间[left, right]进行归并排序
void mergeSort(int A[], int left, int right){
    if (left < right)
    {
        int mid = (left + right) / 2;
        mergeSort(A, left, mid); //将左子区间归并排序
        mergeSort(A, mid+1, right); //将右子区间归并排序

        //将左子区间和右子区间合并
        merge(A, left, mid, mid+1, right);
    }    
}

//非递归-归并排序
void mergeSort_NonRecursion(int A[], int n){
    //step为组内元素个数，step/2 为左子区间元素个数
    for (int step = 2; step/2 < n; step *= 2)
    {
        //每step个元素一组，组内前step/2和后step/2个元素进行合并
        for (int i = 1; i <= n; i += step) //下标从1开始
        {
            int mid = i + step/2 - 1;
            if (mid + 1 <= n)
            {
                //左子区间为：[i, mid]；右子区间为：[mid+1, __min(i+step-1, n)]
                merge(A, i, mid, mid+1, __min(i+step-1, n));
            }            
        }        
    }    
}

int main(){    
    //merge函数测试
    int A[5] = {1, 3, 5, 7, 9};
    int B[5] = {2, 4, 6, 8, 10};
    int C[10] = {0};
    int c = merge(A, B, C, 5, 5);   
    for (int k = 0; k < c; k++)
    {
        printf("%d ", C[k]);
    }
    printf("\n");    
    
    //递归-归并排序测试
    int D[10] = {2, 4, 1, 3, 5, 7, 9, 6, 8, 10};
    mergeSort(D, 0, 9);
    for (int k = 0; k < 10; k++)
    {
        printf("%d ", C[k]);
    }
    printf("\n");

    //非递归-归并排序测试
    int E[] = {10, 2, 4, 1, 3, 5, 7, 9, 6, 8, 10}; //E[0]表示当前数组实际长度
    mergeSort_NonRecursion(E, E[0]);
    for (int k = 1; k <= E[0]; k++)
    {
        printf("%d ", E[k]);
    }
    printf("\n");

    return 0;
}

