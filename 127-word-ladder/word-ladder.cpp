class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>words(wordList.begin(),wordList.end());
        unordered_set<string>vis;
        if(words.find(endWord)==words.end()){
            return 0;
        }
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        vis.insert(beginWord);
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            string s=it.first; 
            if(s==endWord)return it.second;
             for(int i=0;i<s.size();i++){
               char temp=s[i];
                 for(int j=0;j<26;j++){
                    s[i]='a'+j;
                    if(vis.find(s)==vis.end()){
                           if(words.find(s)!=words.end()){
                              q.push({s,it.second+1});
                              vis.insert(s);
                           }
                    }
                 }
               s[i]=temp;    
             }
        }
        return 0;
    }
};