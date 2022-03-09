# class Solution:
#     def search(self, nums: List[int], target: int) -> int:
        
#         class Solution:
#     def search(self, nums: List[int], target: int) -> int:
#         low =0
#         high = len(nums)-1
#         while low <= high:
#             mid = int((low + high)/2)
            
#             if nums[mid]==target:
#                 return mid
#             print(nums[mid])
            
#             if nums[mid]>= nums[low]:
#                 if target > nums[mid] or target < nums[low] :
#                     low =  mid +1
#                 else :
#                     high = mid -1
                    
#             elif nums[mid]< nums[low]:
#                 if target > nums[mid] and target <= nums[high]:
#                     low = mid +1
#                 else :
#                     high = mid -1
                    
#             else: break

#         return -1
