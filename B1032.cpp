#include <cstdio> 
/*
* 为了用事实说明挖掘机技术到底哪家强, PAT组织了一场挖掘机技能大赛. 
请根据比赛结果统计出技术最强的那个学校. 
--------------- 
输入格式: 在第1行给出不超过10^5的正整数N, 即参赛人数. 随后N行, 
每行给出一位参赛者的信息和成绩, 包括其所代表的学校的编号(从1开始连续编号)及其比赛成绩(百分制),中间以空格分隔. 
例如: 1 100
输出格式: 在一行中给出总得分最高的学校的编号及其总分, 中间以空格分隔. 
--------------- 
输入样例:
6
3 65
2 80
1 100
2 70
3 40
3 0
输出示例"
2 150 
*/
const int maxn = 100010;
int school[maxn] = {0}; //记录每个学校的总分
int main(){
	int n, schID, score;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d%d", &schID, &score); //学校ID, 分数 
		school[schID] += score; //学校schID的总分增加score 
	}
	int k = 1, MAX = -1; //最高总分的学校ID以及其总分
	for(int i = 1; i <= n; i++){ //从所有学校中选出总分最高的一个 
		if(school[i] > MAX){
			MAX = school[i];
			k = i; 
		} 
	} 
	
	printf("%d %d\n", k, MAX); //输出最高总分的学校ID及其总分 
	return 0;
} 
