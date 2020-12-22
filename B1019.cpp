#include <cstdio>
#include <algorithm>
using namespace std;

bool cmp(int a, int b){
    return a > b; //递减排序：从大到小
}

//将num数组转换为数字
int to_number(int num[]){
    int sum = 0;
    for (int i = 1; i <= num[0]; i++){
        sum = sum * 10 + num[i];
    }

    return sum;
}

//将n的每一位存储到数组中，最多四位
void to_array(int n, int num[]){
    //eg: n=1024, 则num[5] = {4, 1, 0, 2, 4}, num[0]表示数组实际长度，此处为4
    for (int i = num[0]; i >= 1; i--){
        num[i] = n % 10; 
        n /= 10;
    }

    /* //eg: n=1024, 则num[5] = {4, 4, 2, 1, 0}, num[0]表示数组实际长度，此处为4
    for (int i = 1; i <= num[0]; i++){
        num[i] = n % 10; 
        n /= 10;
    } */
}

int main(){
    //MIN和MAX分别表示递增排序和递减排序后得到的最大值和最小值
    int n, MIN, MAX;
    scanf("%d", &n);

    int num[5] = {4}, len = num[0]; //num[0]表示数组实际长度，此处为4。

    while (1)
    {
        to_array(n, num);

        //注：sort(首元素地址, 尾元素地址的下一地址, (可选)比较函数);
        sort(num+1, num+len+1); //递增排序：从小到大排序
        MIN = to_number(num);
        //注：sort(首元素地址, 尾元素地址的下一地址, (可选)比较函数);
        sort(num+1, num+len+1, cmp); //递减排序：从大到小排序
        MAX = to_number(num);

        n = MAX - MIN;
        printf("%04d - %04d = %04d\n", MAX, MIN, n);

        if(n == 0 || n == 6174) break; //退出条件
    }
    

    return 0;
}