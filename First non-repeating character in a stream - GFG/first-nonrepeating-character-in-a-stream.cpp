//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string a){
		    // Code here
		    unordered_map<char,int> m;
		    
		    int n = a.size();
		    
		    queue<char> q;
		    
		    string ans = "";
		    
		    for(int i = 0 ; i < n ; i++){
	            q.push(a[i]);
	            m[a[i]]++;
	            
	            while(q.size()!=0 && m[q.front()]!=1  ) q.pop();
	            
	            if(q.size()==0){
	                ans+="#";
	            }
	            else{
	                ans+=q.front();
	            }
	            
		    }    
		    
		    return ans;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends