//��bills[i]==5ʱֱ����ȡ
//��bills[i]==10ʱ5�ĸ���-1��10�ĸ���+1
//��bills[i]==20ʱ5�ĸ���-1��10�ĸ���-1��
bool lemonadeChange(int* bills, int billsSize)
{
int money5=0,money10=0;
    //��ͷ�й���
    if(bills[0]!=5 || bills[1]==20)
    {
        return false;
    }
    for(int i=0;i<billsSize;i++)
    {
        if(bills[i]==5)
        {
            money5++;
        }
        if(bills[i]==10)
        {
            money5--;
            money10++;
        }
        if(bills[i]==20)
        {
           if(money10!=0)
           {
               money5--;
               money10--;
           }
            else
            {
                money5-=3;
            }
        }
        if(money5<0)
        {
            return false;
        }
    }
    return true;
}
