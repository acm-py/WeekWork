### **leetcode_18_四数之和**

```html
给定一个包含 n 个整数的数组 nums 和一个目标值 target，判断 nums 中是否存在四个元素 a，b，c 和 d ，使得 a + b + c + d 的值与 target 相等？找出所有满足条件且不重复的四元组。

注意：

答案中不可以包含重复的四元组。

示例：

给定数组 nums = [1, 0, -1, 0, -2, 2]，和 target = 0。

满足要求的四元组集合为：
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]
```



#### 同样这和前两道题类似，难点在于去重。

#### 算法流程：

- 1. 特判

	2. 数组排序

	3. 遍历排序过的数组

		1. 第一次遍历：重复元素的去重

		2. 二次遍历：判断重复元素从i 后第二个元素开始，所以要满足条件：  j  - i > 1 and nums[j] == nums[j-1]

		3. 左指针 =  j + 1，右指针 = n - 1 

		4. 循环条件是L < R

		5. nums[i] + nums[j] + nums[L] + nums[R] - target之间的关系来确定:(每次比较的结果都保存在res里面。移动后再和res比较，更接近就更新res)

			1. 大于0，nums[R]太大，R左移
			2. 小于0，nums[L]太小，L右移

			#### 代码如下：

	```python
	class Solution:
	    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
	        n = len(nums)
	        if(not nums or n < 4):
	            return []
	        nums.sort()
	        res = []
	        end_nums = []
	        pre_nums = []
	        # 这里循环条件不能写成 n
	        for i in range(n-3):
	            # 因为这里会越界
	            # 判断指针移动方向
	            if(nums[i] + nums[i+1] + nums[i+2] + nums[i+3] > target):
	                break
	            if(nums[i] + nums[-1] + nums[-2] + nums[-3] < target):
	                continue
	                # 第一层比那里去重
	            if(i>0 and nums[i] == nums[i-1]):
	                continue
	            for j in range(i+1, n-2):
	                if(nums[i] + nums[j] + nums[j+1] + nums[j+2] > target):
	                    break
	                if(nums[i] + nums[j] + nums[-1] + nums[-2] < target):
	                    continue
	                if(j-i >1  and nums[j] == nums[j-1]):
	                    continue
	                L = j + 1
	                R = n - 1
	                while(L < R):
	                    if(nums[i] + nums[j] + nums[L] + nums[R] == target):
	                        res.append([nums[i], nums[j], nums[L], nums[R]])
	                        # 第二层去重
	                        while(L < R and nums[L] == nums[L+1]):
	                            L += 1
	                        while(L < R and nums[R] == nums[R-1]):
	                            R -= 1
	                        L += 1
	                        R -= 1
	                    elif(nums[i] + nums[j] + nums[L] + nums[R] > target):
	                        R -= 1
	                    else:
	                        L += 1
	        return res
	
	```

	

##### 好像可以直接取四个指针操作(leetcode 的题解，java，算法优化的十分好)

```java
public List<List<Integer>> fourSum(int[] nums,int target){
        /*定义一个返回值*/
        List<List<Integer>> result=new ArrayList<>();
        /*当数组为null或元素小于4个时，直接返回*/
        if(nums==null||nums.length<4){
            return result;
        }
        /*对数组进行从小到大排序*/
        Arrays.sort(nums);
        /*数组长度*/
        int length=nums.length;
        /*定义4个指针k，i，j，h  k从0开始遍历，i从k+1开始遍历，留下j和h，j指向i+1，h指向数组最大值*/
        for(int k=0;k<length-3;k++){
            /*当k的值与前面的值相等时忽略*/
            if(k>0&&nums[k]==nums[k-1]){
                continue;
            }
            /*获取当前最小值，如果最小值比目标值大，说明后面越来越大的值根本没戏*/
            int min1=nums[k]+nums[k+1]+nums[k+2]+nums[k+3];
            if(min1>target){
                break;
            }
            /*获取当前最大值，如果最大值比目标值小，说明后面越来越小的值根本没戏，忽略*/
            int max1=nums[k]+nums[length-1]+nums[length-2]+nums[length-3];
            if(max1<target){
                continue;
            }
            /*第二层循环i，初始值指向k+1*/
            for(int i=k+1;i<length-2;i++){
                /*当i的值与前面的值相等时忽略*/
                if(i>k+1&&nums[i]==nums[i-1]){
                    continue;
                }
                /*定义指针j指向i+1*/
                int j=i+1;
                /*定义指针h指向数组末尾*/
                int h=length-1;
                /*获取当前最小值，如果最小值比目标值大，说明后面越来越大的值根本没戏，忽略*/
                int min=nums[k]+nums[i]+nums[j]+nums[j+1];
                if(min>target){
                    continue;
                }
                /*获取当前最大值，如果最大值比目标值小，说明后面越来越小的值根本没戏，忽略*/
                int max=nums[k]+nums[i]+nums[h]+nums[h-1];
                if(max<target){
                    continue;
                }
                /*开始j指针和h指针的表演，计算当前和，如果等于目标值，j++并去重，h--并去重，当当前和大于目标值时h--，当当前和小于目标值时j++*/
                while (j<h){
                    int curr=nums[k]+nums[i]+nums[j]+nums[h];
                    if(curr==target){
                        result.add(Arrays.asList(nums[k],nums[i],nums[j],nums[h]));
                        j++;
                        while(j<h&&nums[j]==nums[j-1]){
                            j++;
                        }
                        h--;
                        while(j<h&&i<h&&nums[h]==nums[h+1]){
                            h--;
                        }
                    }else if(curr>target){
                        h--;
                    }else {
                       j++;
                    }
                }
            }
        }
        return result;
    }
```

##### 总结： 

##### 做好去重的工作，指针移动的考虑。