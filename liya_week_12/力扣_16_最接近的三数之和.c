/*���ȶ������������
֮��ʹ�������±�i�������������飬��right=i+1 left=numsSize-1��ģ����������i��ʼΪ0
������result = nums[0] + nums[1] + nums[2]
��result������ӽ��ĺͣ���res<tar��right++,��res>tar��left--
�𽥸���res
Ȼ��right==leftʱ��������꣬������һ��ѭ��
������result
*/
int cmp(const void *a, const void *b)
{
    return *(int*)a - *(int*)b; //��С��������
}

int threeSumClosest(int* nums, int numsSize, int target)
{
    qsort(nums, numsSize, sizeof(int), cmp);
    int result = nums[0] + nums[1] + nums[2];
    for(int i=0;i<numsSize-2;i++)
    {
        int left = i+1;
        int right = numsSize - 1;
        while(left != right)
        {
            // �ж���Сֵ
            int min = nums[i] + nums[left] + nums[left + 1];
            if(target < min)
            {
                if(abs(result - target) > abs(min - target))
                    result = min;
                break;
            }
            //�ж����ֵ
            int max = nums[i] + nums[right] + nums[right - 1];
            if(target > max)
            {
                if(abs(result - target) > abs(max - target))
                    result = max;
                break;  
                }
            int sum = nums[i] + nums[left] + nums[right];
            if(abs(sum - target) < abs(result - target))
                result = sum;
            if(sum > target)
            {
                right--;
                while(left != right && nums[right] == nums[right+1])
                    right--;
            }
            else
            {
                left++;
                while(left != right && nums[left] == nums[left-1])
                    left++;
            }
        }
        while(i<numsSize-2 && nums[i] == nums[i+1])
            i++;
    }
    return result;
}
