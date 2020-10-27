#include <cstdio>

const int maxn = 100010; //n, m 不超过 10的5次方 
int hashTable[maxn] = {0};

int main(){
	// 求M个数中在N个数中是否出现并求其次数 
	int n, m, x;
	printf("请输入n, m:");
	scanf("%d%d", &n, &m);
	// 统计出现的次数 
	printf("\n请输入n个数:"); 
	for(int i = 0; i < n; i++){
		scanf("%d", &x);
		hashTable[x]++; // 以空间换时间 --> 直接定址法 
	}
	printf("\n请输入m个数:");
	for(int i = 0; i < m; i++){
		scanf("%d", &x);
		if(hashTable[x] > 0){
			printf("%d出现过	", x);
			printf("出现次数是:%d\n", hashTable[x]);
		}else{
			printf("%d未出现过", x);
		}
	}
	
	return 0; 
}
