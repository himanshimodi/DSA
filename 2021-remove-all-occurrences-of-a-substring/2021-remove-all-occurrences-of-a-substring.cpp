class Solution {
public:
    void removeOcc(string &s, string &part){

        int found = s.find(part); //found returns index of part[0]
        
        //ek case solve krdo
        if(found != string::npos){ //double negative
            //part string has been located so remove it
            string left_part = s.substr(0, found);
            string right_part = s.substr(found + part.size() , s.size());

            s = left_part + right_part;

            //baki resursion sambhal lega
            removeOcc(s, part);
        }

        else{
            //base case
            //all occurrences have been removed
            return;
        }
    }

    string removeOccurrences(string s, string part){
        removeOcc(s,part);
        return s;
    }
};


    // iterative and the easy way
    // string removeOccurrences(string s, string part) {
    //     int pos= s.find(part);
    //     while(pos!=string::npos){
    //         // staring index se leke 'part' ke length tak
    //         s.erase(pos,part.length()); 
    //         //update while loop ka vriable
    //         pos=s.find(part);
    //     }
    //     return s;
    // }
