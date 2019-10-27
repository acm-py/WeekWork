 /*
        ����˼·��
            �ⶼ������������(����������������±��˰��⿴����)
            �����Ȱ���Ŀ����˼�����װɣ����˺ü����˵����Ÿ㶮���⵽����ɶ��˼��ֱ�Ӱѱ��˵Ľ��͸��ƹ����ˣ�
                
                1�����ҳ��������� k ���� nums[k] < nums[k+1]����������ڣ��ͷ�ת�������飻
                2�����ҳ���һ��������� l ���� nums[l] > nums[k]��
                3������ nums[l] �� nums[k]��
                4�����ת nums[k+1:]��
                
                �ٸ����ӣ�

                ���� nums = [1,2,7,4,3,1]����һ��������ʲô��

                �����ҵ���һ����������� nums[1] = 2

                ���ҵ��ڶ������������ nums[4] = 3

                ������nums = [1,3,7,4,2,1];

                ��ת��nums = [1,3,1,2,4,7]

                ���!
        
        ʵ�ֲ��裺
            Ū�������������˼·�ͺ������
            *�ȵ���������� nums[k] < nums[k+1] ������k
            *������k��ʼ����������� nums[l] > nums[k]������l
                *�ҵ���������������l���򽻻�nums[k] �� nums[l] ��ֵ
                    *������������飬��k��ʼ����������
                *�����������鰴������������
    */

// �ӵ����б����ҳ��� target ��ĵ�һ��Ԫ��
int findIndex(int * nums, int start, int end, int target) {
    // ���ַ��е�
    int mid = start;
    while (end > start) {
        mid = (start + end) >> 1;
        // start == mid ʱֻʣ 1 ��Ԫ��
        if (start == mid)
            return target < nums[end]? end: mid;
        else if (nums[mid] > target)
            start = mid;
        else
            end = mid;
    }
    return mid;
}

// �� nums ����� start �� end ����������
void reverse(int * nums, int start, int end) {
    nums += start;
    end -= start;
    int tmp;
    for (int i = 0; i < (end >> 1); i++) {
        tmp = nums[i];
        nums[i] = nums[end - i - 1];
        nums[end - i - 1] = tmp;
    }
}

void nextPermutation(int* nums, int numsSize){
    int index = -1;    // ��¼��һ���½��������
    // �Ӻ���ǰ������ֱ������ nums[i - 1] < nums[i]����¼ index
    for (int i = numsSize - 1; i > 0; i--) {
        if (nums[i - 1] < nums[i]) {
            index = i - 1;
            break;
        }
    }
    // �� index == -1��˵��û���½��㣬ֱ�Ӷ�ȫ��������ת
    if (index == -1) {
        reverse(nums, 0, numsSize);
        return;
    }
    // ��ȡ������������
    int swap = findIndex(nums, index + 1, numsSize - 1, nums[index]);
    int tmp = nums[index];
    nums[index] = nums[swap];
    nums[swap] = tmp;
    reverse(nums, index + 1, numsSize);
}
