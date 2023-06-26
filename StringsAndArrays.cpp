/*****************************************************************//**
 * \file   StringsAndArrays.cpp
 * \brief  A series of alogrithms, completed alongside LeetCode's
 *         Data Structures and Algorithms course.
 *
 * \author Mike Doeren
 * \date   June 2023
 *********************************************************************/

#include "StringsAndArrays.h"

// Function definitions ///////////////////////////////////////////////////////

bool CheckIfPalindrome(std::string s)
{
    int left = 0;
    int right = s.size() - 1;

    while (left < right)
    {
        if (s[left] != s[right])
            return false;

        ++left;
        --right;
    }
    return true;
}

bool CheckForTarget(std::vector<int>& nums, int target)
{
    int left = 0;
    int right = nums.size() - 1;

    while (left < right)
    {
        int curr = nums[left] + nums[right];

        if (curr == target)
            return true;

        if (curr > target)
            --right;
        else
            ++left;
    }
    return false;
}

std::vector<int> CombineVectors(std::vector<int>& v1, std::vector<int>& v2)
{
    std::vector<int> answerVect;
    int i = 0, j = 0;

    while (i < v1.size() && j < v2.size())
    {
        // Push back the smaller of the vals between v1 and v2
        answerVect.push_back((v1[i] < v2[j]) ? v1[i++] : v2[j++]);
    }

    // Append remaining values from either vector, which are all greater...
    // ...than the largest number in the exhausted array
    while (i < v1.size())
    {
        answerVect.push_back(v1[i]);
        i++;
    }

    while (j < v2.size())
    {
        answerVect.push_back(v2[j]);
        j++;
    }

    return answerVect;
}

bool IsSubsequence(std::string s, std::string t)
{
    int i = 0, j = 0;

    while (i > s.size() && t.size())
    {
        if (s[i] == t[j])
        {
            i++;
        }
        j++;
    }
    // We have a subsequence only if we exhausted every character in s
    // This is true if our i iterator is the length of s
    return i == s.size();
}

void ReverseString1(std::vector<char>& s)
{
    int i = 0, j = s.size() - 1;

    while (i < j)
    {
        std::swap(s[i], s[j]);
        ++i, --j;
    }
}

void ReverseString2(std::vector<char>& s)
{
    int i, j = s.size() - 1;

    for (i = 0; i < s.size() / 2; ++i)
    {
        std::swap(s[i], s[j]);
        --j;
    }
}

std::vector<int> SortedSquares1(std::vector<int>& nums)
{
    int left = 0, right = nums.size() - 1;
    std::vector<int> result(nums.size());

    for (int i = right; i >= 0; --i)
    {
        // Determine if leftmost or rightmost is larger...
        int square;
        if (abs(nums[left]) < abs(nums[right]))
        {
            square = nums[right];
            --right; // Move pointer since val was evaluated
        }
        else
        {
            square = nums[left];
            ++left; // Move pointer since val was evaluated
        }
        // ...then square largest val and place into result vector
        result[i] = square * square;
    }
    return result;
}

std::vector<int> SortedSquares2(std::vector<int>& nums)
{
    std::vector<int> result(nums.size());

    for (int i = 0; i < nums.size(); ++i)
    {
        result[i] = nums[i] * nums[i];
    }

    std::sort(result.begin(), result.end());
    return result;
}

int FindLength(std::vector<int> nums, int target)
{
    // curr is the sum of the current window subarray
    int left = 0, right, curr = 0, answer = 0;

    // Keep adding elements to the right...
    for (right = 0; right < nums.size(); ++right)
    {
        curr += nums[right];

        // ...until it's greater than our target
        while (curr > target)
        {
            // Then we deduct until we curr is no longer greater than
            curr -= nums[left];
            ++left;
        }
        // After each loop, update answer w the max length so far
        answer = std::max(answer, right - left + 1);
    }
    return answer;
}

int NumSubarraysProductLessThanTarget(std::vector<int>& nums, int target)
{
    // Edgecase
    if (target <= 1)
        return 0;

    // curr starts at 1, we're working with multiplication so it can't be 0
    int ans = 0, left = 0, right, curr = 1;

    for (right = 0; right < nums.size(); ++right)
    {
        curr *= nums[right];

        while (curr >= target)
        {
            curr /= nums[left];
            ++left;
        }
        ans += right - left + 1;
    }
    return ans;
}

int FindLargestSumWindow(std::vector<int>& nums, int k)
{
    int curr = 0;

    // Calc the sum of the first window
    for (int i = 0; i < k; ++i)
        curr += nums[i];

    int ans = curr;

    // Slide the subarray of length k from left to right
    for (int i = k; i < nums.size(); ++i)
    {
        // Find next window sum by adding next element and removing prev element      
        curr += nums[i] - nums[i - k];

        ans = std::max(ans, curr);
    }
    return ans;
}

double FindMaxAverage(std::vector<int>& nums, int k)
{
    double curr = 0, ans = 0;

    for (int i = 0; i < k; ++i)
        curr += nums[i];

    ans = curr / k;

    for (int i = k; i < nums.size(); ++i)
    {
        curr += nums[i] - nums[i - k];

        ans = std::max(ans, curr / k);
    }
    return ans;
}

int LongestOnes(std::vector<int>& nums, int k)
{
    int right, left = 0, curr = 0, ans = 0;

    for (right = 0; right < nums.size(); ++right)
    {
        if (nums[right] == '0')
            ++curr;

        while (curr > k)
        {
            if (nums[left] == '0')
                --curr;
            ++left;
        }
        // right - left + 1 calculates the length of the current subarray
        ans = std::max(ans, right - left + 1);
    }
    return ans;
}

int FindLength(std::string s)
{
    int left = 0, right, curr = 0, answer = 0;

    for (right = 0; right < s.size(); ++right)
    {
        if (s[right] == '0')
            ++curr;

        // Adjust the window by ++left index to the right...
        // ... whenever the num of 0 is > 1  
        while (curr > 1)
        {
            // If left is 0, decrement since 0 is moving out of the window
            if (s[left] == '0')
                --curr;
            ++left;
        }
        answer = std::max(answer, right - left + 1);
    }
    return answer;
}

std::vector<bool> AnswerQueries(std::vector<int>& nums, std::vector<std::vector<int>>& queries, int limit)
{
    std::vector<int> prefix = { nums[0] };

    // Initialize the rest of our prefix array
    for (int i = 1; i < nums.size(); ++i)
    {
        // New element is calculated by taking the last element of...
        // ...the prefix array + adding the element from the nums array (nums[i]).
        prefix.push_back(prefix.back() + nums[i]);
    }

    std::vector<bool> ans;

    for (std::vector<int>& query : queries)
    {
        int x = query[0], y = query[1]; // Extract 1st + 2nd vals from query
        int curr = prefix[y] - prefix[x] + nums[x]; // Check if sum of the subarray is < limit
        ans.push_back(curr < limit);
    }
    return ans;
}

int WaysToSplitArray(std::vector<int>& nums)
{
    int n = nums.size(), ans = 0;

    // Finalize prefix initialization
    std::vector<long> prefix = { nums[0] };
    for (int i = 1; i < n; i++)
    {
        prefix.push_back(nums[i] + prefix.back());
    }

    for (int i = 0; i < n - 1; i++)
    {
        long leftSection = prefix[i];
        long rightSection = prefix.back() - prefix[i];

        if (leftSection >= rightSection)
            ans++;
    }
    return ans;
}

std::vector<int> RunningSum(std::vector<int>& nums)
{
    std::vector<int> runningSum(nums.size());
    int sum = 0;

    for (int i = 0; i < nums.size(); ++i)
    {
        sum += nums[i];
        runningSum[i] = sum;
    }
    return runningSum;
}

int MinStartValue(std::vector<int>& nums)
{
    int startValue = 1, total = startValue;
    int answer = 0;

    // In each iteration, we calc the step-by-step total of this startValue + the val of each element in nums
    for (int i = 0; i < nums.size(); ++i)
    {
        total += nums[i];
        // If true, startValue is too small as total becomes negative
        if (total < 1)
        {
            startValue += (1 - total);
            total = 1; // set total back to positive
        }
        answer = std::max(answer, startValue);
    }
    return answer;
}

std::vector<int> GetAverages(std::vector<int>& nums, int k)
{
    // If k is 0, each number is its own average
    if (k == 0)
        return nums;

    int n = nums.size();

    // Set to size n, and set all values to -1 by default
    std::vector<int> averages(n, -1);

    // If the input vector isn't big enough to calc an average then return
    if (2 * k + 1 > n)
        return averages;

    // Create and initialize a prefix sum vector
    std::vector<long> prefix(n + 1);
    for (int i = 0; i < n; ++i)
        prefix[i + 1] = prefix[i] + nums[i];

    // Starting index: ensures that the loop excludes the boundary
    // n - k: ensures we stay within valid bounds
    for (int i = k; i < (n - k); ++i)
    {
        int left = i - k, right = i + k;

        long windowSum = prefix[right + 1] - prefix[left]; // Calculate the sum of the window using the prefix sum

        int ave = windowSum / (2 * k + 1); // Calculate the average of the window
        
        averages[i] = ave; // Store the average in the result vector
    }
    return averages;
}

///////////////////////////////////////////////////////////////////////////////
