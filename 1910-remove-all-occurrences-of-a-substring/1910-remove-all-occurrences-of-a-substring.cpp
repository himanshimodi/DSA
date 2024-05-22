class Solution {
public:
    //not much dimag used
    string removeOccurrences(string s, string part) {
        int pos= s.find(part);
        while(pos!=string::npos){
            // staring index se leke 'part' ke length tak
            s.erase(pos,part.length()); 
            //update while loop ka vriable
            pos=s.find(part);
        }
        return s;
    }
};