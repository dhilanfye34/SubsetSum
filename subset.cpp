#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <cctype>
#include <cmath>
#include <cassert>
#include <ctime>

using namespace std;

bool ** create_table(int nums, int sum)
{
    bool ** table = new bool * [nums + 1];

    for (int i = 0; i <= nums; i++) 
    {
        table[i] = new bool[sum + 1];
    }

    for (int i = 0; i <= nums; i++)
    {
        table[i][0] = true; //can always = 0 if u take no numbers
    }

    for (int i = 1; i <= nums; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            table[i][j] = false;
        }    
    }
    return table;
}

void dp(vector<int>& nums, int sum) 
{
    int n = nums.size();
    
    bool ** table = create_table(n, sum);
    
    for (int i = 1; i <= n; ++i) 
    {
        for (int j = 1; j <= sum; ++j) 
        {
            if (nums[i - 1] <= j) 
            {
                table[i][j] = table[i - 1][j] || table[i - 1][j - nums[i - 1]];
            }   
            else 
            {
                table[i][j] = table[i - 1][j];
            }
        }
    }   

    int closest_sum = sum;
    while(!table[n][closest_sum] && closest_sum > 0)
    {
        closest_sum--;
    }

    vector<int> set;
    int current_sum = closest_sum;
    
    for (int i = n; i > 0 && current_sum > 0; i--)
    {
        if (current_sum >= nums[i - 1] && table[i - 1][current_sum - nums[i - 1]])
        {
            set.push_back(nums[i - 1]);
            current_sum -= nums[i - 1];
        }
    }
    
    for (int i = 0; i <= n; ++i) 
    {
        delete[] table[i];
    }

    delete[] table;

    cout<<"Dynamic Programming: "<<endl<<endl;

    int test_combo;

    if (closest_sum != sum)
    {
        cout<<"The best possible sum is: "<<closest_sum<<endl;
    }
    else if (closest_sum == sum)
    {
        cout<<"The desired sum of "<<closest_sum<<" is achievable."<<endl;
    }

    cout<<"These are the values to add together: "<<endl;

    for (int i = 0; i < set.size(); i++)
    {
        cout<<i + 1<<": "<<set[i]<<endl;
        test_combo += set[i];
    }
    
    if (test_combo != closest_sum)
    {
        cout<<"Incorrect Combination of Set."<<endl;
    }    
    cout<<endl;   
}

void find_brute_subset(vector<int>& nums, int sum, int index, int current_sum, int& closest_sum, vector<int>& current_subset, vector<int>& best_subset)
{
    if (current_sum <= sum && abs(sum - current_sum) < abs(sum - closest_sum))
    {
        closest_sum = current_sum;
        best_subset = current_subset;
    }

    if (index == nums.size() || current_sum > sum) 
    {
        return; 
    }

    current_subset.push_back(nums[index]);
    find_brute_subset(nums, sum, index + 1, current_sum + nums[index], closest_sum, current_subset, best_subset);

    current_subset.pop_back();
    find_brute_subset(nums, sum, index + 1, current_sum, closest_sum, current_subset, best_subset);
}   

void bf(vector<int>& nums, int sum)
{
    vector<int> current_subset, best_subset;

    int closest_sum = 0;
    find_brute_subset(nums, sum, 0, 0, closest_sum, current_subset, best_subset);

    cout<<"Brute Force: "<<endl<<endl;

    int test_combo2 = 0; 
    
    if(closest_sum != sum)
    {
       cout<<"The best possible sum is: "<<closest_sum<<endl;
    }   
    
    else if(closest_sum == sum)
    {
        cout<<"The desired sum of "<<closest_sum<<" is achievable."<<endl;
    }
    
    cout<<"These are the values to add together: "<<endl;
    
    for (int i = 0; i < best_subset.size(); i++)
    {
        cout<<i + 1<<": "<<best_subset[i]<<endl;    
        test_combo2 += best_subset[i];
    }

    if (test_combo2 != closest_sum)
    {
        cout<<"Incorrect Combination of Set."<<endl;
    }
    cout<<endl;
}        

int main (int argc, char* argv[]) 
{
    if (argc < 3) 
    {
        cout<<"Invalid Input."<<endl;
        return 1;
    }

    vector<int> nums;
    for (int i = 1; i < argc - 1; i++) 
    {
        string arg = argv[i];
        bool is_num = true;
        for (int j = 0; j < arg.length(); j++)
        {
            if (!isdigit(arg[j])) 
            {
                is_num = false;
                break;
            }
        }
        
        if (is_num) 
        {
            int num = stoi(arg);
            nums.push_back(num);
        } 
        else 
        {
            cout << "Invalid input: " << arg << " is not a non-negative integer." << endl;
            return 1;
        }        
        
    }
    
    int sum = stoi(argv[argc - 1]);
    
    cout<<endl;
    dp(nums, sum);
    bf(nums, sum);     
}   