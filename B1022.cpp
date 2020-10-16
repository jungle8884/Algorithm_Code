#include <cstdio>
#include <cstdlib>

int index = 0; //p进制数x 用十进制数组表示的数位数. 

// 将 p进制数x 转换为 十进制数y. 
int P2DEC(int x, int p){ //x 代表 p(1 <= p <= 10)进制数, 用十进制的数字来表示. 
	int y = 0, product = 1;
	while(x != 0){
		y += (x % 10) * product; //X % 10 是为了每次获取x的个位数 
		x /= 10; //去掉x的个位
		product *= p; 
	}
	
	return y;
}

// 将 十进制数y 转化为 p(1 <= p <= 10)进制数x, x用十进制的数字来表示.
void DEC2P(int y, int p, int* x){
	//数组x 存放 p进制数y 的每一位, index为位数.
	do{ //除基取余 
		x[index++] = y % p;
		y /= p; 
	} while(y != 0);	
	
	return;
}

int main(){
	int a, b, d;
	scanf("%d%d%d", &a, &b, &d);
	
	int x_dec, x = 0;
	
	int sum = a + b; 
	int ans[31], num = 0; //ans存放D进制的每一位
	
	DEC2P(sum, d, ans); //进制转换 
	
	for(int i = index - 1; i >= 0; i--){ //从高位到低位进行输出 
		printf("%d", ans[i]);
		
	/*
		//将其从数组形式转换为数字形式 
		x_dec = 1;
		for(int j = 0; j < i; j++){ //先获取当前位数的权值 
			x_dec *= 10;
		}	
		x += ans[i] * x_dec;
	*/
	}
/*
	printf("\n%d", x); //x 表示 ans 的数字形式 
	printf("\n%d", P2DEC(x, d)); //将x从d进制转换为十进制并输出 
*/
	
	return 0;
} 


