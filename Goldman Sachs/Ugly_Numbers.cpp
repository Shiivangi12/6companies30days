#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long

class Solution{
public:
	ull getNthUglyNo(int n) {
	    set<ull> s;
	    s.insert(1);
	    while(--n) {
	        auto i = s.begin();
	        s.insert(*i * 2);
	        s.insert(*i * 3);
	        s.insert(*i * 5);
	        s.erase(i);
	    }
	    return *s.begin();
	}
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.getNthUglyNo(n);
        cout << ans << "\n";
    }
    return 0;
}
