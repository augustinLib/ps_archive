#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    int k;
    int temp;
    int sum = 0;
    vector<int> stack;
    cin >> k;
    
    for(int i = 0; i < k; ++i)
    {
        cin >> temp;
        if(temp == 0)
        {
            stack.pop_back();
        }
        else
        {
            stack.push_back(temp);
        }
    }
    
    for (int c : stack)
    {
        sum += c;
    }
    
    cout << sum << endl;
    return 0;
}