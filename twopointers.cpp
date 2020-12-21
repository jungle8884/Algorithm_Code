# include<cstdio>

//双指针思想
int main(){
    int a[] = {1, 2, 3, 4, 5, 6};
    int M = 8;
    int i = 0, j = 5;     

    //找到数组中两个数之和为M的数并输出，时间复杂度为：O(n)
    while (i < j)
    {
        if (a[i] + a[j] == M)
        {
            printf("%d %d\n", a[i], a[j]);
            i++;
            j--;
        }
        else if (a[i] + a[j] < M)
        {
            i++;
        }else
        {
            j--;
        }             
    }    
    
    return 0;
}

