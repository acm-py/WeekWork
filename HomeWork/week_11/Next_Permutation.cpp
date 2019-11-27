#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
/*
ʵ�ֻ�ȡ��һ�����еĺ������㷨��Ҫ���������������������г��ֵ�������һ����������С�

�����������һ����������У��������������г���С�����У����������У���

����ԭ���޸ģ�ֻ����ʹ�ö��ⳣ���ռ䡣

������һЩ���ӣ�����λ������У�����Ӧ���λ���Ҳ��С�
1,2,3 �� 1,3,2
3,2,1 �� 1,2,3
1,1,5 �� 1,5,1

*/
void nextPermutation(vector<int>& nums);//��Ҫ���ܴ���,����˼·��ʵ�ִ��벿���ϲ��� 
void swap(int &num_a,int &num_b);//����������a,b 
void reverse(vector<int>& nums,int first,int last);//����nums�нǱ���������[first,last)�ڵ���ȫ����ת 
void p_V(vector<int> v);//��ӡvector���飬д�ɺ���������� 
int main()
{
	vector<int> v;
	int n;
	while(cin>>a)//����ΪEOFֹͣ(windows��cmd�������Ϊcrtl+Z��)
		v.push_back(a);
	nextPermutation(v);
	p_V(v);
}

/*
��������Ҫ�������ҵ��ֵ�����һ������������뵱ǰ���еĹ�ϵ��
��������:��������{6,5,4,3,2,1}��������������б���������ģ���Ϊ
���������������İ��մ����ִ�С������ͬʱ�پ���,��������{2,3,6,5,4,1}
��һ��������ӦΪ{2,4,1,3,6,5},���Է��ֽ�3��4֮�以��Ȼ���������{6,5,3,1}
��ת������С����ʵ��ɷ��ֹ���:Ѱ����nums���һ����Ϊ��β������ӵݼ�����Sn��
��Sn��һ������ǰһ����Ϊk(��nums[k+1]==sn[0]),ͬʱ��Sn��Ѱ��һ����l,ʹ��nums[l]ǡ��
�մ���nums[k],��nums[k]��nums[l]������Sn��ת���ϵ�ԭ�����к������һ�������С� 
 
  
//˼·��ȷ����벻��д 
*/
 void nextPermutation(vector<int>& nums) {
        if(nums.size()<=1)//ֻ��һ��Ԫ��ֱ�ӷ��� 
          return;
        int k=nums.size()-2,l=nums.size()-1;    
        while(k!=-1)
        {
           if(nums[k]<nums[k+1])//Ѱ��kֵ����nums[k]>nums[k+1] 
             break;
           k--;
        }
        if(k==-1)
        {   
            reverse(nums,0,nums.size()-1);
            return;
        }
        while(l)
        {
            if(nums[l]>nums[k])//Ѱ��l���ҽ���nums[k],nums[l]��Ȼ��תnums�ڽǱ�����Ϊ[k+1,nums.size())�������� 
            { 
            // p_V(nums);
               swap(nums[l],nums[k]);               
            //   p_V(nums);
            //   printf("%d %d\n",k,l);
			   reverse(nums,k+1,nums.size()-1);
               break;
            }
            l--;
        }
    }
 
void swap(int &num_a,int &num_b)
    {
        int temp=num_a;
        num_a=num_b;
        num_b=temp;
    }
void reverse(vector<int>& nums,int first,int last){
	   while(first!=last&&first<last)
       {
	         swap(nums[first],nums[last]);
             first++;
             last--;
       }
    }

void p_V(vector<int> v)
{
	for(int i=0;i<v.size();i++)
	  cout<<v[i]<<" ";
	cout<<endl;
} 
