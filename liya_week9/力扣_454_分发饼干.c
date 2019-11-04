//分别对s和g排序，常规排序不行，太慢.实验下qsort函数.比堆排序快乐4ms
//然后比较，得出饼干s大小大于胃口g大小的个数并输出
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
