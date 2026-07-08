class Solution {
    typedef long long ll;
    int mod=1e9+7;
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n=s.size();
        vector<int> nonzeroDig(n,0);
        vector<ll> digitSum(n,0);
        vector<ll> numberUpto(n,0);
        vector<ll> power(n+1,0);

        power[0]=1;
        for(int i=1;i<n;i++){
            power[i]=(power[i-1]*10)%mod;
        }

        nonzeroDig[0]=(s[0]!='0')?1:0;
        for(int i=1;i<n;i++){
            int digit=s[i]-'0';
            if(s[i]!='0'){
                nonzeroDig[i]=nonzeroDig[i-1]+1;
            }
            else{
                nonzeroDig[i]=nonzeroDig[i-1]+0;
            }
        }

        numberUpto[0]=(s[0]=='0')?0:s[0]-'0';

        for(int i=1;i<n;i++){
            int digit=s[i]-'0';
            if(digit!=0){
                numberUpto[i]=(numberUpto[i-1]*10+digit)%mod;
            }else{
                numberUpto[i]=numberUpto[i-1];
            }
        }

        digitSum[0]=s[0]-'0';
        for(int i=1;i<n;i++){
           int digit=s[i]-'0';
           digitSum[i]=digitSum[i-1]+digit;
        }

        int q=queries.size();
        vector<int> ans(q);
        for(int i=0;i<q;i++){
            int l=queries[i][0];
            int r=queries[i][1];

            ll sum = digitSum[r] - (l==0 ? 0 : digitSum[l-1]);
            ll numbef=((l==0)?0:numberUpto[l-1]);
            int k=nonzeroDig[r]-((l==0)?0:nonzeroDig[l-1]);
           ll x = (numberUpto[r] - numbef*power[k]) % mod;
           if(x < 0) x += mod;
            ans[i] = (int)((x * sum) % mod);
        }
        return ans;
    }
};