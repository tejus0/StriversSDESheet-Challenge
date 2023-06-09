#include <bits/stdc++.h> // Include all standard libraries.
vector<int> majorityElementII(vector<int> &nums) // Define a function called 'majorityElementII' that takes in a vector of integers called 'nums'.
{
    int sz = nums.size(); // Initialize a variable called 'sz' to the size of 'nums'.
    int num1 = -1, num2 = -1, count1 = 0, count2 = 0, i; // Initialize variables called 'num1', 'num2', 'count1', 'count2', and 'i' to various values.

    for (i = 0; i < sz; i++) // For each element 'i' in 'nums'.
    {
        if (nums[i] == num1) // If the number at index 'i' is equal to 'num1',
            count1++; // Increment 'count1'.
        else if (nums[i] == num2) // Otherwise, if the number at index 'i' is equal to 'num2',
            count2++; // Increment 'count2'.
        else if (count1 == 0) // Otherwise, if 'count1' is zero,
        {
            num1 = nums[i]; // Set 'num1' to the number at index 'i'.
            count1 = 1; // Set 'count1' to one.
        }    
        else if (count2 == 0) // Otherwise, if 'count2' is zero,
        {
            num2 = nums[i]; // Set 'num2' to the number at index 'i'.
            count2 = 1; // Set 'count2' to one.
        }
        else // Otherwise,
        {
            count1--; // Decrement 'count1'.
            count2--; // Decrement 'count2'.
        }
    }

    vector<int> ans; // Initialize a vector called 'ans'.
    count1 = count2 = 0; // Set 'count1' and 'count2' to zero.
    for (i = 0; i < sz; i++) // For each element 'i' in 'nums'.
    {
        if (nums[i] == num1) // If the number at index 'i' is equal to 'num1',
            count1++; // Increment 'count1'.
        else if (nums[i] == num2) // Otherwise, if the number at index 'i' is equal to 'num2',
            count2++; // Increment 'count2'.
    }
    if (count1 > sz/3) // If 'count1' is greater than 'sz' divided by 3,
        ans.push_back(num1); // Add 'num1' to the back of 'ans'.
    if (count2 > sz/3) // If 'count2' is greater than 'sz' divided by 3,
        ans.push_back(num2); // Add 'num2' to the back of 'ans'.
    return ans; // Return 'ans'.
}
