# Condsider a case when you can take several objects of one type in the knapsack problem
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
  
  
  
