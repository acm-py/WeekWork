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

//�ƶ�����λ�ò���Ҫ����,����ͳ������ż���ĸ���
//�൱������ƶ������ڵ�����λ�ã�Ȼ�󽫸����ٵ��ƶ����������
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
