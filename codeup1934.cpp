/*
输入一个数 n (1 <= n <= 200), 
然后输入 n 个数值不相同的数, 
再输入一个值 X, 
输出这个值在这个数组中的下标 (从 0 开始, 若不在数组中则输出 -1) 
*/ 
#include <cstdio>

const int maxn = 210;
int a[maxn]; //存放n个数

int main(){
	int n, x;
	
	/*
	EOF，为End Of File的缩写，通常在文本的最后存在此字符表示资料结束。
    	在微软的DOS和Windows中，读取数据时终端不会产生EOF。
		此时，应用程序知道数据源是一个终端（或者其它“字符设备”），
		并将一个已知的保留的字符或序列解释为文件结束的指明；最
		普遍地说，它是ASCII码中的替换字符（Control-Z，代码26）。
	在终端(黑框)中手动输入时，
		系统并不知道什么时候到达了所谓的“文件末尾”，
		因此需要用<Ctrl + z>组合键然后按 Enter 键的方式来告诉系统已经到了EOF，
	这样系统才会结束while.
	while(scanf("%d", &n) != EOF){
		for(int i = 0; i < n; i++){
			scanf("%d", &a[i]); //输入n个数 
		}
	}
	*/
	scanf("%d", &n);
	for(int i = 0; i < n; i++){ //输入n个数
		scanf("%d", &a[i]);  
	}

	
	scanf("%d", &x); //输入欲查询的数
	int k; //下标 
	
	for(int k = 0; k < n; k++){ //遍历数组 
		if(a[k] == x){ //如果找到了x 
			printf("%d\n", k); //输出对应的下标 
			break; //退出查找 
		}
	} 
	
	if(k == n){ //如果没有找到 
		printf("-1\n"); //输出 -1 
	} 
	
	return 0; 
} 

