#include <iostream>
#include <map>
#include <queue>

using namespace std;
string FirstNonRepeating(string A)
{
    // Code here
    map<char, int> m;
    string ans = "";
    queue<char> q;
    for (char i : A)
    {

        q.push(i);
        m[i]++;

        while (!q.empty())
        {

            if (m[q.front()] > 1)
            {
                q.pop();
            }
            else
            {
                ans.push_back(q.front());
                break;
            }
        }
        if (q.empty())
            ans.push_back('#');
    }
    return ans;
}
int main()
{

    cout<<FirstNonRepeating("aabc")<<endl;
    return 0;
}