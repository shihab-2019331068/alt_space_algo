#include<bits/stdc++.h>
#include<conio.h>

using namespace std;

#define fastio            ios_base::sync_with_stdio(false); cin.tie(NULL);
#define aa                auto
#define cn                const
#define ll                long long
#define ld                long double
#define fr                first
#define sc                second
#define pll               pair<ll,ll>
#define tll               tuple<ll,ll,ll>
#define vll               vector<ll>
#define bp(x)             __builtin_popcountll(x)
#define all(a)            a.begin(),a.end()
#define arr(a)            a.rbegin(),a.rend()
#define cb(a,i)           (a>>i&1)
#define mp(a,b)           make_pair(a,b)
#define pb(a)             push_back(a)
#define ve                vector


#define db(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); cerr<<"\n";}
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
   cerr << *it << "=" << a << " ! ";
   err(++it, args...);
}

cn ll N=5e5+7,N1=25,inf=2e18;
cn ld eps=1e-8;
cn ll M=1e9+7;
//cn ll M=998244353;

vll ma[3];

void prin(){
   cout<<"\n";
   ll i,j;
   getch();
   for(i=3; i>=0; i--){
      for(j=0; j<3; j++){
         if(ma[j].size()<=i) cout<<'.';
         else cout<<ma[j][i];
         cout<<"    ";
      }
      cout<<"\n";
   }
   cout<<"\n";
}

void hanoi(ll n=4,ll f=0,ll a=1,ll t=2){
   if(!n) return;
   hanoi(n-1,f,t,a);
   ma[f].pop_back(); ma[t].push_back(n);
   prin();
   hanoi(n-1,a,f,t);
}

int main(){
   for(ll i=4; i; i--) ma[0].push_back(i);
   prin();
   hanoi();
}




















