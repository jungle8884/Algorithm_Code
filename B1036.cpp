# include<cstdio>

int main(){
	int row, col; //��, �� 
	char c;
	
	scanf("%d %c", &col, &c); //��������, ��ʹ�õ��ַ� 
	
	if(col % 2 == 1){ //������������������ 
		row = col / 2 + 1;
	}else{
		row = col / 2;
	}
	
	// �� 1 ��
	for(int i = 0; i < col; i++){
		printf("%c", c); //��� col ���ַ� 
	} 
	printf("\n");
	
	// �� 2 ~ row-1 ��
	for(int i = 1; i < row-1; i++){
		printf("%c", c); //ÿ�еĵ�һ���ַ� c 
		for(int j = 0; j < col-2; j++){
			printf(" "); //��� col-2 ���ո� 
		}
		printf("%c\n", c); //ÿ�е����һ���ַ� c 
	}
	
	// �� row-1 ��
	for(int i = 0; i < col; i++){
		printf("%c", c);
	} 
	
	return 0;
}
