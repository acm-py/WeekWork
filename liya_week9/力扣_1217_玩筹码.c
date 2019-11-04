int min(int x,int y)
{
    if(x>=y)
    {
        return y;
    }
    else
    {
        return x;
    }
}

//移动两个位置不需要代价,所以统计奇数偶数的个数
//相当于最后都移动到相邻的两个位置，然后将个数少的移动到个数多的
int minCostToMoveChips(int* chips, int chipsSize)
{
     int odd = 0, even = 0;
	for (int i = 0; i < chipsSize; i++) {
		if (chips[i] % 2 == 0) {
			even++;
		} else if (chips[i] % 2 != 0) {
			odd++;
		}
	}
	return min(even, odd);

}
