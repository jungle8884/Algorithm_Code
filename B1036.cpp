# include<cstdio>

int main(){
	int row, col; //行, 列 
	char c;
	
	scanf("%d %c", &col, &c); //输入列数, 欲使用的字符 
	
	if(col % 2 == 1){ //对行数进行四舍五入 
		row = col / 2 + 1;
	}else{
		row = col / 2;
	}
	
	// 第 1 行
	for(int i = 0; i < col; i++){
		printf("%c", c); //输出 col 个字符 
	} 
	printf("\n");
	
	// 第 2 ~ row-1 行
	for(int i = 1; i < row-1; i++){
		printf("%c", c); //每行的第一个字符 c 
		for(int j = 0; j < col-2; j++){
			printf(" "); //输出 col-2 个空格 
		}
		printf("%c\n", c); //每行的最后一个字符 c 
	}
	
	// 第 row-1 行
	for(int i = 0; i < col; i++){
		printf("%c", c);
	} 
	
	return 0;
}
