class Solution {
public:

	int ans=INT_MAX;

	// function to check no. of different characters of two strings
	int changes(string s, string ss){
		int change=0;
		for(int i=0;i<s.length();i++){
			if(s[i]!=ss[i]) change++;
		}
		return change;
	}

	// function to traverse through the graph
	void dfs(int i, string &start, string &end, vector<vector<int>> &g, vector<bool> &visited, int count, vector<string> &bank){
		visited[i]=true;
		count++;
		// traversing through the strings which have a difference of one character for the current string
		for(int j=0;j<g[i].size();j++){
			if(bank[g[i][j]] == end) {
				// if we have found the end mutation then check the current count and assign it to ans
				ans = min(ans, count);
				return;
			}
			// if the mutation is not visited call the recursive function
			if(visited[g[i][j]] == false){
				dfs(g[i][j], start, end, g, visited, count, bank);
				// once we visit the mutation we need to assign it as not visited so that we can traverse through it once again for desired parent mutation
				visited[g[i][j]]=false;
			} 
		}

	}

	int minMutation(string start, string end, vector<string>& bank) {
		if(count(bank.begin(), bank.end(), end)<1) return -1;
		int c=0;
		vector<vector<int>> g;
		set<string> st(bank.begin(), bank.end());
		bank = vector<string>(st.begin(), st.end());
		vector<bool> visited(bank.size(), false);

		// creating a graph where the child nodes of an element consist of strings which differ with parent by one character
		for(int i=0;i<bank.size();i++){
			g.push_back({});
			for(int j=0;j<bank.size();j++){
				if(changes(bank[i], bank[j]) == 1){
					g[i].push_back(j);
				}
			}
		}

		// checking for the mutations in bank whose difference of charcters is one, to call recursive function on it
		for(int i=0;i<bank.size();i++){
			if(changes(start, bank[i]) == 1){
				if(end == bank[i]) return 1;
				else {
					dfs(i, start, end, g, visited, 1, bank);
					visited = vector<bool> (bank.size());
				}
			}
		}
		return ans==INT_MAX ? -1:ans;
	}
};