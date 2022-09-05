namespace sort{
    vector<int> sort(vector<int> x)
    {
        std::sort(x.begin(), x.end());
        return x;
    }
}
//3, 4, 3, 5, -2, -4

vector<int> sort_stress(vector<int> x)
{
    std::sort(x.begin(), x.end(), [](int a, int b) { return abs(a) < abs(b); });
    return x;
}
