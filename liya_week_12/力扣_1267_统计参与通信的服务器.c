//找到二维数组中数字1的同行和同列都为0的个数n
//然后服务器总个数m减去n

int countServers(int** grid, int gridSize, int* gridColSize)
{
    int m=0,n=0,x=0;
    for(int i=0;i<gridSize;i++)
    {
        for(int j=0;j<*gridColSize;j++)
        {
            x=0;
            if(grid[i][j]==1)
            {
                m++;
                //向左右找，看是否有服务器
                for(int a=0;a<*gridColSize;a++)
                {
                    if(a!=j)
                    {
                        if(grid[i][a]==1)
                        {
                            x++;
                            break;
                        }
                    }
                }
                //向上下找，看是否有服务器
                for(int b=0;b<gridSize;b++)
                {
                    if(b!=i)
                    {
                        if(grid[b][j]==1)
                        {
                            x++;
                            break;
                        }    
                    }
                }
            //若都为0
            if(x==0)
            {
                n++;
            }
            }
        }
    }
    return m-n;
}
