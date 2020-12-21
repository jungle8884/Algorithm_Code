#include <cstdio>
#include <cstring>
#include <algorithm>

const int MAXN = 100010;
const int MOD = 1000000007;
char str[MAXN]; 
int leftNumP[MAXN] = {0}; //每一位左边（含）p的个数

int main(){
	//读入字符串：gets(str)的替代方法。
    int i=0;
    fgets(str, MAXN, stdin);
    while (str[i] != '\n')
        i++;
    str[i] = '\0';

    int len = strlen(str); //长度
    //printf("%d", len);

    for (int i = 0; i < len; i++) //从左至右遍历字符串
    {
        if (i > 0) //如果不是0号位
        {
            leftNumP[i] = leftNumP[i-1];
        }
        if (str[i] == 'P') //当前位是P
        {
            leftNumP[i]++;
        }     
    }
    //printf("%d\n", leftNumP[len-1]); //输出P的个数
    

    int ans = 0, rightNumT = 0; //ans为答案，rightNumT记录右边T的个数
    for (int i = len-1; i >= 0; i--) //从右至左遍历字符串
    {
        if (str[i] == 'T')
        {
            rightNumT++;
        }else if (str[i] == 'A')
        {
            ans = (ans + leftNumP[i] * rightNumT) % MOD; //累计乘积
        }        
    }
    //printf("%d\n", rightNumT); //输出T的个数
    
    printf("%d\n", ans); //输出结果

    return 0;
}