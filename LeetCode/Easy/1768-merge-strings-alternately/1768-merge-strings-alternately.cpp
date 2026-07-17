class Solution {
public:
    string mergeAlternately(string w1, string w2) {
        string hm = "";
        int i = 0, j = 0;
        int n1 = w1.size();
        int n2 = w2.size();

        while (i < n1 && j < n2) {
            hm.push_back(w1[i++]);
            hm.push_back(w2[j++]);
        }
        while (i < n1) {
            hm.push_back(w1[i++]);
        }
        while (j < n2) {

            hm.push_back(w2[j++]);
        }

        return hm;
    }
};