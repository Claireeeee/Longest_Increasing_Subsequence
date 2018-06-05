# Longest_Increasing_Subsequence
最长递增子序列 O(NlogN)算法

求一个序列的最长递增数列的长度
用了贪心+二分，遍历元素

每次寻找插入位置的时候，用logi的时间，对i从1到n求和，是log（n！），大概是nlogn

用动态分配也可以，但是觉得有点牵强。复杂度是n方
