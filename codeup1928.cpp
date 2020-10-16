#include <cstdio>

int month[13][2] = { 
	//平年和闰年每个月的天数 
	{0, 0},
	{31, 31}, //一月大 
	{28, 29}, //二月小
	{31, 31}, //三月大 
	{30, 30}, //四月小 
	{31, 31}, //五月大
	{30, 30}, //六月小
	{31, 31}, 
	{31, 31}, //七月大, 八月大
	{30, 30}, //九月小
	{31, 31}, //十月大
	{30, 30}, //十一月小
	{31, 31}  //十二月大 
};

//判断是否是闰年 
bool isLeap(int year){
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0); 
} 

int main(){
	int time1, y1, m1, d1;
	int time2, y2, m2, d2;
	
	while(scanf("%d%d", &time1, &time2) != EOF){
		if(time1 > time2){
			int temp = time1;
			time1 = time2;
			time2 = temp;
		}
		
		y1 = time1 / 10000, m1 = time1 % 10000 / 100, d1 = time1 % 100;
		y2 = time2 / 10000, m2 = time2 % 10000 / 100, d2 = time2 % 100;
		
		int ans = 1; //记录结果---日期差值 
		//第一个日期没有达到第二个日期时进行循环
		//即 !((y1 == y2) && (m1 == m2) && (d1 == d2)) 
		while(y1 < y2 || m1 < m2 || d1 < d2){
			d1++; //天数加1 
			if(d1 == month[m1][isLeap(y1)]+1){ //是否满当月的天数 
				m1++; //日期变为下个月的1号.
				d1 = 1; 
			}
			if(m1 == 13){ //月份是否满十二个月 
				y1++; // 日期变为下一年的一月 
				m1 = 1; 
			}
			ans++; //累计 
		}
		printf("%d\n", ans); //输出结果 
	}
	
	return 0;
}

