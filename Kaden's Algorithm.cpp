//Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

//A subarray is a contiguous part of an array.

//Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
//Output: 6
//Explanation: [4,-1,2,1] has the largest sum = 6.

 //Code in CPP

int main(){
  int n;
  cin>>n;
  int arr[n];
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  int sum=0;
  int maxi=INT_MIN;

        for(int i=0;i<nums.size();i++){
            sum+=nums[i];

            maxi=max(maxi,sum);
                
            if(sum<0)sum=0;

            
        }
  cout<<sum<<endl;
}
