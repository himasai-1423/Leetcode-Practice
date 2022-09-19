class Solution {
public:
    int minimumRecolors(string s, int k)
    {        
        int count=0;
        int i=0,j=0;
        int n = s.length();
        int mini=INT_MAX;
        while(j<n)
        {
            if(s[j]=='W')
                count++;
            
            if(j-i+1==k)
            {
                mini=min(mini,count);
                if(s[i]=='W')
                    count--;
                i++;
            }
            j++;
        }
        return mini;
    }
};