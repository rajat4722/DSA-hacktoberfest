#include <bits/stdc++.h>
using namespace std;

void vector_print(vector<pair<int,int>> v)
{
    cout<<"Given weights and values are:";
    cout<<"("<<v[0].first<<","<<v[0].second<<")";
    for (int i = 1; i < v.size(); i++)
    {
        cout<<",("<<v[i].first<<","<<v[i].second<<")";
    }
    cout<<"\n\n";
}

bool sortby_val_Per_weight_r(const pair<int, int> &a, const pair<int, int> &b)
{
    double r1 = (double)a.first / a.second;
    double r2 = (double)b.first / b.second;
    return (r1 > r2);
}

double FknapS(int w, vector<pair<int, int>> &v, int n)
{
     cout <<"Maximum value we can obtain: {";
    sort(v.begin(), v.end(), sortby_val_Per_weight_r);
    double res = 0.0;
    for (int i = 0; i < n; i++)
    {
        if (w >= v[i].second)
        {
            res += v[i].first;
            w = w - v[i].second;
            // cout<<"res: "<<res<<" w: "<<w<<"\n";
            cout<<"("<<v[i].second<<"*"<<(double)v[i].first / v[i].second<<")+";
        }
        else
        {
            res += v[i].first * (double)w / v[i].second;
             cout<<"("<<w<<"*"<<(double)v[i].first / v[i].second<<")";
            break;
        }
    }
    cout<<"}="<<res<<"\n";
}

int main()
{
    vector<pair<int, int>> v;
    int n;
    cin >> n;
    int w;
    cin >> w;
    for (int i = 0; i < n; i++)
    {
        double x, y;
        cin >> x >> y;
        v.push_back({x, y});
    }
    cout<<"Number of objects: "<<n<<"\n";
    cout<<"Knapsack Capacity: "<<w<<"\n";
    vector_print(v);
    FknapS(w, v, n);
    return 0;
}
