vector<string> helper(string s, string con[],int n){
    int len = s.length();
    map<string,int> ret;
    for(int i = 0; i < n ; i ++){
    if(con[i].length() >= len and con[i].substr(0,len) == s){
        ret[con[i]]++;
    }
    }
    vector<string> temp;
    for(auto i :ret){
        temp.push_back(i.first);
    }
    if(temp.size() == 0)
        temp.push_back("0");
    return temp;
}
vector<vector<string>> displayContacts(int n, string contact[], string s)
{
// code here
    vector<vector<string>> res;
    for(int i = 1 ; i <= s.length() ; i ++){
        vector<string> temp = helper(s.substr(0,i),contact,n);
        res.push_back(temp);
    }
    return res;
}

