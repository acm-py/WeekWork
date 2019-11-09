void reverseString(char* s, int sSize)
{
      int i;
      char a;
    for(i=0;i<sSize/2;i++)
    {
        a=s[i];
         s[i]=s[sSize-i-1];
        s[sSize-i-1]=a;
    }
}
