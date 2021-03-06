/*hdu 5229 ZCC loves strings
  题意：
  CC有N个字符串，他正在和Miss G.用这N个字符串玩一个小游戏。ZCC会从这N个串中等概率随机选两个字符串（不可以是同一个）。然后，ZCC和Miss G.轮流操作。Miss G.总是先操作的。在每轮中，操作者可以选择操作A或操作B。
  操作A：在两个串中选择一个当前非空的串，然后在这个串的末尾删去一个字符。
  操作B: 若当前两个串完全相同且非空，则可以使用这个操作。此时两个串都被清空。
  不能操作的玩家输掉了这个游戏。
  ZCC想要知道他输掉游戏的概率是多少(也就是Miss G.获胜的概率)。
  限制：
  2 <= N <= 20000; 字符串总长度不超过200000
  思路：
  其实博弈很简单，先特判两个字符串是否相同，如果相同则Miss G.赢，否则看两个字符串长度和的奇偶，奇则Miss G.赢，偶则Miss G.输。
  因为，对于操作B，除了第一步，在后续的博弈里面根本没有机会执行。
 */
#include<iostream>
#include<cstdio>
#include<map>
#include<algorithm>
using namespace std;
#define LL __int64
const int N=20000;
string s[N];
map<string,int> mp;
int main(){
	ios_base::sync_with_stdio(false);
	int T;
	cin>>T;
	int n;
	while(T--){
		LL ji=0;
		LL ou=0;
		mp.clear();
		cin>>n;
		for(int i=0;i<n;++i){
			cin>>s[i];
			++mp[s[i]];
			if(s[i].length()%2==0) ++ou;
			else ++ji;
		}
		sort(s,s+n);
		int cnt=unique(s,s+n)-s;
		LL fz=0,fm;
		for(int i=0;i<cnt;++i){
			LL tmp=mp[s[i]];
			fz+=tmp*(tmp-1)/2;
		}
		fz+=ji*ou;
		//cout<<fz<<endl;
		fm=(LL)n*(n-1)/2;
		LL d=__gcd(fz,fm);
		fz/=d;
		fm/=d;
		cout<<fz<<"/"<<fm<<endl;
	}
	return 0;
}
