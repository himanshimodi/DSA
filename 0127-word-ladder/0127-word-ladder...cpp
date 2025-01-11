class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>>q;
        q.push({beginWord,1});

        unordered_set<string>st(wordList.begin(),wordList.end());

        st.erase(beginWord);

        while(!q.empty()){
            pair<string,int> frontPair = q.front();
            q.pop();
            string frontString = frontPair.first;
            int frontDist = frontPair.second;

            if(frontString == endWord){
                return frontDist;
            }
            else{
                for(int i=0;i<frontString.length();i++){
                    char originalChar = frontString[i];
                    for(char ch = 'a';ch<='z';ch++){
                        frontString[i]= ch;
                        if(st.find(frontString)!=st.end()){
                            //word found in set
                            q.push({frontString,frontDist+1});
                            st.erase(frontString);
                        }
                    }
                    //backtrack
                    frontString[i] = originalChar;
                }
            }
        }
        return 0;
    }
};