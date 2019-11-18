bool isOneBitCharacter(int* bits, int bitsSize)
{
    int x=0;
    if(bitsSize==1)
    {
        return true;
    }
    if(bits[bitsSize-2]==0)
        {
            return true;
        }
    for(int i=bitsSize-2;i>=0&&bits[i]!=0;i--)
    {
    if(bits[i]==1)
        {
        x++;
        }
    
    }
    if(x%2==0)
        return true;
    else
        return false;
        
}
