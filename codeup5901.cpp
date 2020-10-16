#include <cstdio>
#include <cstring>

const int maxn = 256;

//判断字符串str是否是 "回文串".
bool judge(char str[]){
	int len = strlen(str);
	for(int i = 0; i < len / 2; i++){ //i 枚举字符串的前一半 
		if(str[i] != str[len-1-i]){ //如果对称位置不同 
			return false; 
		} 
	}
	
	return true;
} 

int main(){
	char str[maxn];
	/*
	gets()函数从STDIN(标准输入)读取字符并把它们加载到str(字符串)里,	直到遇到新行(\n)或到达EOF. 
	新行字符翻译为一个null中断符. 
	gets()的返回值是读入的字符串,如果错误返回NULL. 
	*/
	while(gets(str)){ //输入字符串 
		bool flag = judge(str); //判断字符串 str 是否是 "回文串".
		if(flag == true){ //"回文串"
			printf("YES\n");
		} else{ //不是 "回文串" 
			printf("NO\n"); 
		} 
	}
	
	return 0;
}
