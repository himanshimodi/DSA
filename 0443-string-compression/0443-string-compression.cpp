class Solution {
public:
    int compress(vector<char>& s) {
        int index = 0, c = 1;
        char prev = s[0];
        for(int i=1; i<s.size();i++){
            if(s[i] == prev){
                c++;
            }
            else{
                s[index++] = prev;
                if(c > 1){
                    int start = index;
                    while(c){
                        s[index++] = (c % 10) + '0';
                        c/=10;
                    }
                    reverse(s.begin() + start, s.begin()+index);
                }
                prev = s[i];
                c=1;
            }
        }

        s[index++] = prev;
        if(c > 1){
            int start = index;
            while(c){
                s[index++] = (c % 10) + '0';
                c/=10;
            }
            reverse(s.begin() + start, s.begin() + index);
        }
        return index;
    }   
};

// class Solution {
// public:
//     int compress(vector<char>& s) {
//         int n = s.size();
//         if (n == 0) return 0;

//         int index = 0, count = 1;
//         char prev = s[0];
//         for (int i = 1; i < n; ++i) {
//             if (s[i] == prev) {
//                 ++count;
//             } else {
//                 s[index++] = prev;
//                 if (count > 1) {
//                     string countStr = to_string(count);
//                     for (char c : countStr) {
//                         s[index++] = c;
//                     }
//                 }
//                 prev = s[i];
//                 count = 1;
//             }
//         }

//.        s[index++] = prev;  
//         if (count > 1) {
//             string countStr = to_string(count);
//             for (char c : countStr) {
//                 s[index++] = c;
//             }
//         }

//         return index;
//     }
// };
