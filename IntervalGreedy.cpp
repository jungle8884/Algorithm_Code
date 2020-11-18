#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 110;

struct Interval{
	int x, y; //���������Ҷ˵�
}I[maxn];

bool cmp(Interval a, Interval b){
	if(a.x != b.x)
		return a.x > b.x; //�Ȱ���˵�Ӵ�С����
	else
		return a.y < b.y; //��˵���ͬ�İ��Ҷ˵��С��������
}

int main () {
	int n;
	while (scanf("%d", &n), n != 0)
	{
		for (int i = 0; i < n; i++)
		{
			scanf("%d%d", &I[i].x, &I[i].y);
		}
		sort(I, I+n, cmp); //��������		

		int ans = 1, lastX = I[0].x; //ans��¼���ཻ�����������lastX��¼��һ����ѡ���������˵�
		printf("(%d, %d) ", I[0].x, I[0].y);
		for (int i = 1; i < n; i++)
		{
			if (I[i].y <= lastX) //����������Ҷ˵���lastX���
			{
				lastX = I[i].x; //��I[i]��Ϊ��ѡ�е�����
				printf("(%d, %d) ", I[i].x, I[i].y);
				ans++; //���ཻ�����������1	
			}			
		}
		printf("\n���ཻ���������:%d\n", ans);		
	}
	
	return 0;
}