class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if(find(wordList.begin(),wordList.end(),endWord) == wordList.end() || beginWord == endWord)
        {
            return 0;
        }
        int n = wordList.size();
        int m = wordList[0].size();
        vector<vector<int>> adj(n);
        unordered_map<string,int> mp;

        //Connect string and its index for the lookup

        for(int i=0;i<n;i++)
        {
            mp[wordList[i]]=i;
        }

        //find the words that differ by one character and connect their indexes to eachother
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int cnt = 0;
                for(int k = 0;k < m;k++)
                {
                    if(wordList[i][k] != wordList[j][k])
                    {
                        cnt++;
                    }
                }
                if(cnt == 1)
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
            unordered_set<int> visited;
            queue<int> q;

            //we now try to see beginword connects with what
            for(int i = 0;i<m;i++)
            {
                for(char c ='a'; c<='z';c++)
                {
                    if(c == beginWord[i]) continue;
                    string word = beginWord.substr(0,i) + c + beginWord.substr(i+1);
                    if(mp.find(word) != mp.end() && visited.count(mp[word])==0)
                    {
                        q.push(mp[word]);
                        visited.insert(mp[word]);
                    }
                }
            }
            int res =1;
            while(!q.empty())
            {
                res++;
                int size = q.size();
                while(size--)
                {
                    int node = q.front();
                    q.pop();
                    if(wordList[node] == endWord) {
                        return res;
                    }
                    for(int neigh : adj[node])
                    {
                        if(visited.find(neigh)==visited.end())
                        {
                            visited.insert(neigh);
                            q.push(neigh);
                        }
                    }
                }
            }
             return 0;
        }
       
    
};
