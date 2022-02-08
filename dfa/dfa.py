reg exp: To check if binary string multiple of 3
  def solve(nums): 
   dfa_state = 0
   for i in range(len(nums)): 
      digit = nums[i] 
      if dfa_state == 0: 
         if digit == 1: 
            dfa_state = 1 
      elif dfa_state == 1: 
         if digit == 0: 
            dfa_state = 2 
         else: 
            dfa_state = 0 
      elif dfa_state == 2: 
         if digit == 0: 
            dfa_state = 1 
   if dfa_state == 0: 
      return True 
   return False 
n = [1, 1, 0, 0] 
print(solve(n))
