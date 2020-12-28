#include <cstdio>

const int maxn = 1000001; //表长
int prime[maxn], num = 0; //prime数组存放所有素数，pNum为素数个数
bool p[maxn] = {0}; //如果i为素数，则p[i]为false；否则，p[i]为true。
//找n个素数
void Find_Prime(int n) {
    for (int i = 2; i < maxn; i++)
    {
        if (p[i] == false) //如果i为素数
        {
            prime[num++] = i; //是素数则把i存入prime数组
            if (num >= n) break; //只需要n个素数
            for (int j = i + i; j < maxn; j += i)
            {
                //筛去所有i的倍数
                p[j] = true;
            }
            
        }        
    }    
}

//输出第M~N个素数（M <= N <= 10的4次方）
int main() {
    int m, n, count = 0;
    scanf("%d%d", &m, &n);
    Find_Prime(n);
    for (int i = m; i <= n; i++)
    {
        //输出第m个素数至第n个素数
        printf("%d", prime[i-1]); //下标从0开始
        count++;
        //每 10 个数字占 1 行，其间以空格分隔，但行末不得有多余空格。
        if (count % 10 != 0 && i < n) 
            printf(" ");
        else
            printf("\n");
    }    

    return 0;
}