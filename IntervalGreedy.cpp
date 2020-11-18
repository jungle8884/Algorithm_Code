#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 110;

struct Interval{
	int x, y; //开区间左右端点
}I[maxn];

bool cmp(Interval a, Interval b){
	if(a.x != b.x)
		return a.x > b.x; //先按左端点从大到小排序
	else
		return a.y < b.y; //左端点相同的按右端点从小到大排序
}

int main () {
	int n;
	while (scanf("%d", &n), n != 0)
	{
		for (int i = 0; i < n; i++)
		{
			scanf("%d%d", &I[i].x, &I[i].y);
		}
		sort(I, I+n, cmp); //区间排序		

		int ans = 1, lastX = I[0].x; //ans记录不相交的区间个数，lastX记录上一个被选中区间的左端点
		printf("(%d, %d) ", I[0].x, I[0].y);
		for (int i = 1; i < n; i++)
		{
			if (I[i].y <= lastX) //如果该区间右端点在lastX左边
			{
				lastX = I[i].x; //以I[i]作为新选中的区间
				printf("(%d, %d) ", I[i].x, I[i].y);
				ans++; //不相交的区间个数加1	
			}			
		}
		printf("\n不相交的区间个数:%d\n", ans);		
	}
	
	return 0;
}