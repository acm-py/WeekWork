//�ֱ��s��g���򣬳��������У�̫��.ʵ����qsort����.�ȶ��������4ms
//Ȼ��Ƚϣ��ó�����s��С����θ��g��С�ĸ��������
int cmp(const void* a, const void* b)
{
    return *(int*)a > *(int*)b;
}
int findContentChildren(int* g, int gSize, int* s, int sSize)
{
    qsort(g, gSize, sizeof(int), cmp);
    qsort(s, sSize, sizeof(int), cmp);
    int che=0;
    int i=0,j=0;
    for(i=0,j=0; i<gSize&& j<sSize;){
            if(g[i]<=s[j]){
                i++;
                j++;
                che++;
            }else{
                j++;
            }
        }
        return che;


}
