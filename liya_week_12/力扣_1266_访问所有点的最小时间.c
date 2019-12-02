int max(int x,int y)
{
    return x>y?x:y;
}
int abs(int x)
{
    if(x<0) return -1*x;
    return x;
}

//时间为两点之间的横纵坐标的最大值
int minTimeToVisitAllPoints(int** points, int pointsSize, int* pointsColSize)
{
    int sum = 0;
		for (int i = 0; i <pointsSize- 1; i++)
        {
			sum += max(abs(points[i + 1][0] - points[i][0]), abs(points[i + 1][1] - points[i][1]));
		}
		return sum;
}
