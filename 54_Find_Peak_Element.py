# python solution

# class Solution(object):
#     def findPeakElement(self, nums):
        
#         low =0 
#         high = len(nums)-1
#         while high - low > 1:
#             mid = (low+high)/2
#             if nums[mid] >nums[mid-1] and nums[mid]> nums[mid+1]:
#                 return mid
#             elif  nums[mid] <= nums[mid-1]:
#                 high = mid -1
                
#             elif  nums[mid] < nums[mid+1] :
#                 low= mid+1
            
#         if nums[high] >= nums[low]:
#             return high 
#         else:
#             return low