#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void dfs(int u, vector<int> adj[], vector<bool> &vt, string &s)
{

    vt[u] = true;

    for (auto i : adj[u])
    {

        if (!vt[i])
            dfs(i, adj, vt, s);
    }
    char ch = u + 'a';
    s = ch + s;
}
string findOrder(string dict[], int N, int K)
{
    // code here

    vector<int> adj[K];
    vector<bool> vt(K, false);
    string s;
    for (int i = 0; i < N - 1; i++)
    {
        string w1 = dict[i];
        string w2 = dict[i + 1];

        for (int j = 0; j < min(w1.length(), w2.length()); j++)
        {
            if (w1[j] != w2[j])
            {
                adj[w1[j] - 'a'].push_back(w2[j] - 'a');
                break;
            }
        }
    }
    for (int i = 0; i < K; i++)
    {
        if (!vt[i])
        {
            dfs(i, adj, vt, s);
        }
    }
    return s;
}
int main()
{
    string words[] = {
        "caa",
        "aaa",
        "aab"};
    string ans= findOrder(words, 3, 3);

    cout<<ans<<" ";
    

    return 0;
}