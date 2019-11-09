int trap(int* height, int heightSize){
    int max1=-1;
		int index=0;
		for (int i = 0; i < heightSize; i++)
		{
			if (height[i] > max1)
			{
				max1 = height[i];
				index = i;
			}
		}
		int num = 0;
		for (int i = 1; i < index; i++)
		{
			if (height[i] < height[i - 1])
			{
				num += height[i - 1] - height[i];
				height[i] = height[i - 1];
			}
		}
		for (int i =heightSize-1; i >index; i--)
		{
			if (height[i] > height[i - 1])
			{
				num += height[i] - height[i - 1];
				height[i - 1] = height[i];
			}
		}
		return num;
}
