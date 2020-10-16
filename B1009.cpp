#include <cstdio>
#include <cstring> 

int main(){
	//int num = 0; //单词的个数
	char ans[90][90]; 
	
	char str[90];
	gets(str);
	int len = strlen(str), row = 0, col = 0; //row 为行, col 为列.
	for(int i = 0; i < len; i++){
		if(str[i] != ' '){ //如果不是空格, 则存放至ans[row][col], 并令 col++
			ans[row][col++] = str[i]; 
		}else{ //如果是空格, 则说明一个单词结束, 行 row增加, 列 col恢复至 0.
			ans[row][col] = '\0'; //末尾是结束符\0 
			row++;
			col = 0; 
		}
	} 
	
	/*
	while(scanf("%s", ans[num]) != EOF){ //一直输入到文件末尾
		num++; //单词个数加一 
	} 
	
	
	for(int i = num - 1; i >= 0; i--){ //倒着输出单词 
		printf("%s", ans[i]);
		if(i > 0) printf(" "); 
	} 
	*/
	
	for(int i = row; i >= 0; i--){ //倒着输出单词 
		printf("%s", ans[i]);
		if(i > 0) printf(" "); 
	} 
	
	return 0;
}
