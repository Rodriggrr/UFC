vector<int> get_men(vector<int> x)
{
    vector<int> men;
    for(auto a : x)
        if(a > 0)
            men.push_back(a);
    return men;
}

vector<int> get_calm_women(vector<int> x)
{
    vector<int> women;
    for(auto a : x)
        if(a < 0 && a > -10)
            women.push_back(a);
    return women;
}