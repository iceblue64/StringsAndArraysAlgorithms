/*****************************************************************//**
 * \file   StringsAndArrays.h
 * \brief  A series of alogrithms, completed alongside LeetCode's
 *         Data Structures and Algorithms course.
 * 
 * Functions:
 * + CheckIfPalindrome: Checks if a string is a palindrome.
 * + CheckForTarget: Checks if there are two numbers in a vector that add up to a target.
 * + CombineVectors: Combines two vectors into one.
 * + IsSubsequence: Checks if a string is a subsequence of another string.
 * + ReverseString1: Reverses a string.
 * + ReverseString2: Reverses a string.
 * + SortedSquares1: Returns a new vector with the squares of the numbers in a vector, non-decreasing order.
 * + SortedSquares2: Returns a new vector with the squares of the numbers in a vector, non-decreasing order.
 * + FindLength: finds the length of the longest subarray in a vector whose sum is less than or equal to a given target value.
 * + NumSubarraysProductLessThanTarget: Counts the number of subarrays in a vector whose product is less than a target value.
 * + FindLargestSumWindow: Finds the largest sum of a subarray of length k in a vector via sliding window method.
 * + FindMaxAverage: Finds the max average of a subarray of length k in a vector via sliding window method.
 * + LongestOnes: Finds the length of the longest subarray in a vector containing at most k zeros via sliding window method.
 * + FindLength: Finds the max length of a subarray in a binary string with at most one zero.
 * + AnswerQueries: Answers a series of queries to check if the sum of a subarray is less than a limit.
 * + WaysToSplitArray: Counts the number of ways to split an array into three non-empty subarrays.
 * + RunningSum: Calculates the running sum of the corresponding elements in the input vector.
 * + MinStartValue: Find the min starting value to make the sum of a subarray in a vector always positive.
 * + GetAverages: Calculates the moving averages of a vector for a given window size k.
 * 
 * \author Mike Doeren
 * \date   June 2023
 *********************************************************************/

#pragma once

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

// Function declerations //////////////////////////////////////////////////////

bool CheckIfPalindrome(std::string s);
bool CheckForTarget(std::vector<int>& nums, int target);
std::vector<int> CombineVectors(std::vector<int>& v1, std::vector<int>& v2);
bool IsSubsequence(std::string s, std::string t);
void ReverseString1(std::vector<char>& s);
void ReverseString2(std::vector<char>& s);
std::vector<int> SortedSquares1(std::vector<int>& nums);
std::vector<int> SortedSquares2(std::vector<int>& nums);
int FindLength(std::vector<int> nums, int target);
int NumSubarraysProductLessThanTarget(std::vector<int>& nums, int target);
int FindLargestSumWindow(std::vector<int>& nums, int k);
double FindMaxAverage(std::vector<int>& nums, int k);
int LongestOnes(std::vector<int>& nums, int k);
int FindLength(std::string s);
std::vector<bool> AnswerQueries(std::vector<int>& nums, std::vector<std::vector<int>>& queries, int limit);
int WaysToSplitArray(std::vector<int>& nums);
std::vector<int> RunningSum(std::vector<int>& nums);
int MinStartValue(std::vector<int>& nums);
std::vector<int> GetAverages(std::vector<int>& nums, int k);

///////////////////////////////////////////////////////////////////////////////

int main()
{
    std::cin.get();
}
