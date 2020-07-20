
# Basic DP

### Condsider a case when you can take several objects of one type in the knapsack problem,
  
  Building on the classical version of the problem you can solve it by taking dp(i, x) as
  the maximum value after considering the first i objects such that there weight is x.
  
  Now each state can be calculate by iterating over all possible number of objects taken 
  at the i-th position and taking the maximum amongst them,
  
               dp(i, x) = max(dp(i - 1, x - 0*w_i), dp(i - 1, x - 1 * w_i) + v_i, ... (till x > i * w_i)
  
  After looking at the transition of state a observation can be made about the repetetion of
  transitions, 
  
               dp(i, x - 1 * w_i) = max(dp(i - 1, x - 1 * w_i), dp(i - 1, x - 2 * w_i) + v_i, ...till(x > i * w_i)
               
  After making this observation we can see that dp(i, x) can be rewritten as,
      
               dp(i, x) = max(dp(i - 1, x), dp(i, x - w_i) + v_i)
               
  It can also be thought of as, if an optimal path is drawn from dp(0, 0) to dp(i, x) which can take w_i jump vertically
  in the i-th column and one jump horizontal (from i to i + 1), the path will either come from dp(i - 1, x) or dp(i, x - w_i).

### Removing redundant states
   
   This is kind of similar to the first idea, consider the problem : 
   
   *There are n people who want to get to the top of a building which has only one elevator. You know the weight of each person and the maximum allowed weight in the elevator. What is the minimum number of elevator rides?*
   
   Link : https://cses.fi/problemset/task/1653
  
  This is solvable using bitmask dp, dp(mask) represent the optimal answer for *mask* people. Now each state can be calculated trying all possible people who where selected in the last elevator, 
  
              dp[mask] = min(for all subset of mask : dp[mask&~submask]) + 1
  
  This will give the correct answer but is far too slow for the limits n = 20, as its complexity is O(3<sup>n</sup>n) which can be reduced to O(3<sup>n</sup>) by precomputing all subset sums, but is still slow for the final answer. 
  
  There is another way to solve this, let dp(mask, x) denote the answer for *mask* people with last group sum equal to x. For a specific mask we can brute for the last person chosen, let's say i, 
  
                      dp(mask, x) = min(dp(mask, x), dp(mask&~(1<<i), minimum possible x))
                      
   Now immedialtly we can observe the second state is redundant as it is suboptimal to choose anyother state besides the minimum possible x, which we can directly store by making dp a pair
   {min_answer, last} or make two different dp tables, which give as the complexity of O(2<sup>n</sup>n)
  
  
