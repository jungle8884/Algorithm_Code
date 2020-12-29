#include <cstdio>
#include <cmath>

const int maxn = 100010;

//判断n是否是素数
bool is_Prime(int n) {
    //1既不是素数也不是合数
    if (n <= 1) return false;
    int sqr = sqrt(1.0 * n);
    for (int i = 2; i <= sqr; i++)
    {
        if (n % i == 0) return false;
    }
    
    return true;                                                                                          
}

int prime[maxn], pNum = 0; 
bool p[maxn] = {0}; //如果i为素数，则p[i]为false；否则，p[i]为true。
//求素数表
void Find_Prime() {
    for (int i = 1; i < maxn; i++)
    {
        if (is_Prime(i) == true)
        {
            prime[pNum++] = i;
        }
        
    }    
    /*
    //改进版
    for (int i = 2; i < maxn; i++)
    {
        if (p[i] == false) //如果i为素数
        {
            prime[pNum++] = i; //是素数则把i存入prime数组
            for (int j = i + i; j < maxn; j += i)
            {
                //筛去所有i的倍数
                p[j] = true;
            }
            
        }        
    }    
    */
}

//存放质因子
struct fractor {
    int x, cnt; //x为质因子，cnt为其个数
}fac[10];

//给出一个int范围的整数，按照从小到大的顺序输出其分解为质因数的乘法算式
int main() {
    
    Find_Prime();
    int n, num = 0; //num为n的不同质因子的个数
    scanf("%d", &n);
    if(n == 1) printf("1 == 1"); //特判1的情况
    else
    {
        printf("%d=", n);
        int sqr = (int)sqrt(1.0 * n); //根号n
        //枚举根号n以内的质因子
        for (int i = 0; i < pNum && prime[i] <= sqr; i++)
        {
            //如果prime[i]是n的因子
            if (n % prime[i] == 0)
            {
                fac[num].x = prime[i]; //记录该因子
                fac[num].cnt = 0;

                //计算出质因子prime[i]的个数
                while (n % prime[i] == 0) 
                {
                    fac[num].cnt++;
                    n /= prime[i];
                }

                num++; //不同质因子个数加1
            }

            if (n == 1) break; //及时退出循环，节省点时间
        }

        //如果在上面的操作结束后n仍然大于1，说明有且仅有一个大于sqrt(n)的质因子（有可能是n本身）
        if (n != 1)
        {
            fac[num].x = n;
            fac[num++].cnt = 1;
        }

        //按格式输出结果
        for (int i = 0; i < num; i++)
        {
            if (i > 0) printf("*");
            printf("%d", fac[i].x);
            if (fac[i].cnt > 1)
            {
                printf("^%d", fac[i].cnt);
            }            
        }        
    }    

    return 0;
}