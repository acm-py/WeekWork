//�ҵ���ά����������1��ͬ�к�ͬ�ж�Ϊ0�ĸ���n
//Ȼ��������ܸ���m��ȥn

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
                //�������ң����Ƿ��з�����
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
                //�������ң����Ƿ��з�����
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
            //����Ϊ0
            if(x==0)
            {
                n++;
            }
            }
        }
    }
    return m-n;
}
