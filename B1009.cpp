#include <cstdio>
#include <cstring> 

int main(){
	//int num = 0; //���ʵĸ���
	char ans[90][90]; 
	
	char str[90];
	gets(str);
	int len = strlen(str), row = 0, col = 0; //row Ϊ��, col Ϊ��.
	for(int i = 0; i < len; i++){
		if(str[i] != ' '){ //������ǿո�, ������ans[row][col], ���� col++
			ans[row][col++] = str[i]; 
		}else{ //����ǿո�, ��˵��һ�����ʽ���, �� row����, �� col�ָ��� 0.
			ans[row][col] = '\0'; //ĩβ�ǽ�����\0 
			row++;
			col = 0; 
		}
	} 
	
	/*
	while(scanf("%s", ans[num]) != EOF){ //һֱ���뵽�ļ�ĩβ
		num++; //���ʸ�����һ 
	} 
	
	
	for(int i = num - 1; i >= 0; i--){ //����������� 
		printf("%s", ans[i]);
		if(i > 0) printf(" "); 
	} 
	*/
	
	for(int i = row; i >= 0; i--){ //����������� 
		printf("%s", ans[i]);
		if(i > 0) printf(" "); 
	} 
	
	return 0;
}
