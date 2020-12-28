/*
题目描述：输入两个正整数，求其最大公约数。
输入：测试数据有多组，每组输入两个正整数。
输出：对于每组输入,请输出其最大公约数。
样例输入：49 14
样例输出：7
*/
#include <cstdio>
#include <algorithm>
#include <cmath>

//求最大公约数的辗转相除法递归写法
int gcd(int a, int b) {
    if(b == 0){
        return a;
    }else{
        return gcd(b, a % b);
    }
}

//在gcd的基础上求最小公倍数
int lcm(int a, int b) {
    int d = gcd(a, b);

    //return (a * b) / d;
    return a / d * b; //为防止溢出
}

/* 
分数的表示：
1. 使down为非负数。如果分数为负，那么令分子up为负即可。
2. 如果该分数恰好为0，那么规定其分子为0，分母为1。
3. 分子和分母没有除了1以外的公约数。
*/
struct Fraction { 
    long long up; //分子
    long long down; //分母
}; //结构体要有分号

/*
分数的化简：
1. 如果分母down为负数，那么令分子up和down都变为相反数。
2. 如果分子up为0，那么令分母down为1。
3. 约分：求出分子绝对值与分母绝对值的最大公约数d，然后令分子分母同时除以d。
*/
Fraction reduction(Fraction result) {
    //如果分母down为负数，那么令分子up和down都变为相反数。
    if (result.down < 0) 
    {
        result.up = (-result.up);
        result.down = (-result.down);
    }

    //如果分子up为0，那么令分母down为1。
    if (result.up == 0)
    {
        result.down = 1;
    } else //如果分子不为0，进行约分
    {
        //求出分子绝对值与分母绝对值的最大公约数d，然后令分子分母同时除以d。
        int d = gcd(abs(result.up), abs(result.down));
        result.up /= d;
        result.down /= d;
    }    

    return result;
}

//分数的加法
Fraction add(Fraction f1, Fraction f2) {
    Fraction result;
    result.up = f1.up * f2.down + f2.up * f1.down;
    result.down = f1.down * f2.down;

    return reduction(result);
}

//分数的减法
Fraction minu(Fraction f1, Fraction f2) {
    Fraction result;
    result.up = f1.up * f2.down - f2.up * f1.down;
    result.down = f1.down * f2.down;

    return reduction(result);
}

//分数的乘法
Fraction multi(Fraction f1, Fraction f2) {
    Fraction result;
    result.up = f1.up * f2.up;
    result.down = f1.down * f2.down;

    return reduction(result);
}

//分数的除法
Fraction devide(Fraction f1, Fraction f2) {
    Fraction result;
    result.up = f1.up * f2.down;
    result.down = f1.down * f2.up;

    return reduction(result);
}

//分数的输出
void showResult(Fraction r) {
    r = reduction(r);

    if(r.down == 1) {
        printf("%lld", r.up); //整数
    }else if (abs(r.up) > r.down) { //假分数
        printf("%d %d/%d", r.up/r.down, abs(r.up)%r.down, r.down);
    }else //真分数
    {
        printf("%d/%d", r.up, r.down);
    }
    
}

//素数的判断：除了1和本身之外，不能被其他整数整除的一类数。
bool isPrime(int n) {
    //1既不是素数也不是合数
    if (n <= 1) return false;
    int sqr = sqrt(1.0 * n);
    for (int i = 2; i <= sqr; i++)
    {
        if (n % i == 0) return false;
    }
    
    return true;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             
}

const int maxn = 101; //表长
int prime[maxn], pNum = 0; //prime数组存放所有素数，pNum为素数个数
bool p[maxn] = {0}; //如果i为素数，则p[i]为false；否则，p[i]为true。
//求解100以内的所有素数，maxn <= 10的5次方。
void Find_Prime() {
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
}



int main() {
    /* int m, n;
    while (scanf("%d%d", &m, &n) != EOF) //最普遍地说，它是ASCII码中的替换字符（Control-Z，代码26）
    {
        printf("%d\n", gcd(m, n));
        printf("%d\n", lcm(m, n));
    } */

    /* Fraction f1, f2;
    f1.up = 8, f1.down = 9;
    f2.up = 9, f2.down = 8;
    Fraction f3 = multi(f1, f2); 
    showResult(f3); */
    
    Find_Prime();
    for (int i = 0; i < pNum; i++)
    {
        printf("%d ", prime[i]);
    }
    printf("\n");   

    return 0;
}