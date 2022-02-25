#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
  	int n;
  	cin >> n;
  	string s;
  	cin >> s;
  	// if the length of the string is odd, then it is impossible because
  	// the middle character (s[n / 2]) is always equal to itself
  	if (n & 1) {
  		cout << "NO" << '\n';
  		continue;
  	}
  	// maintain a frequency table for each letter
  	vector<int> counter(26, 0);
  	for (int i = 0; i < n; i++) {
  		counter[s[i] - 'a']++;
  	}
  	// if the largest frequency of a letter is greater than N / 2, then it is
  	// also impossible because placing x letters in an N / 2 container, where x > N / 2
  	// would mean that the remaining characters (x - N / 2) will be present in the 2nd half of the string
  	int mx = *max_element(counter.begin(), counter.end());
  	if (mx > n / 2) {
  		cout << "NO" << '\n';
  		continue;
  	}
  	// otherwise, the answer will be YES
  	cout << "YES" << '\n';
 		string ans = "";
 		// to form an anti-palindromic string, sort the string in lexicographic order
 		// and reverse half of the string (either first or second because it doesn't matter)
 		// so that the last letter of the first half (s[N / 2]) will not be equal to the
 		// first letter in second half of the string (s[N / 2 + 1])
 		for (int i = 0; i < 26; i++) {
 			ans += string(counter[i], (i + 'a'));
 		}
 		reverse(ans.begin(), ans.begin() + n / 2);
 		cout << ans << '\n';
  }	
	return 0;
}
