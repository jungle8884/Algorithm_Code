#include <cstdio>
#include <cstring> 

int main(){
	//int num = 0; 
	char ans[90][90]; 
	
	char str[90];
	//gets(str);	
    int i=0;
    fgets(str, 90, stdin);
    while (str[i] != '\n')
        i++;
    str[i] = '\0';

	int len = strlen(str), row = 0, col = 0; 
	for(int i = 0; i < len; i++){
		if(str[i] != ' '){ 
			ans[row][col++] = str[i]; 
		}else{ 
			ans[row][col] = '\0'; 
			row++;
			col = 0; 
		}
	} 
	
	/*
	while(scanf("%s", ans[num]) != EOF){ 
		num++; 
	} 
	
	
	for(int i = num - 1; i >= 0; i--){ 
		printf("%s", ans[i]);
		if(i > 0) printf(" "); 
	} 
	*/
	
	for(int i = row; i >= 0; i--){ 
		printf("%s", ans[i]);
		if(i > 0) printf(" "); 
	} 
	
	return 0;
}
