#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define forn(i, s, e) for (ll i = (s); i < (e); i++)
#define ln "\n"

int main() {   
  ios::sync_with_stdio(0); cin.tie(0);
  
  string s;
  string s2 = "";
  cin >> s;
  map<char,int> m; 
  set<char> set1;
  
  for (char c : s) {
    m[c]++;
  }
  int times = 0 ; 
  for(pair<char,int> p : m){
    if (m[p.first]>times) {
      set1.erase(set1.begin(),set1.end());
      set1.emplace(p.first) ; 
      times = m[p.first];
    }
    else if (m[p.first]==times) {
      set1.emplace(p.first);
    }
    
  }
  for(char c : s) {
    if (set1.find(c) == set1.end()) {s2+=c;}
  }
  cout << s2 << ln;
}