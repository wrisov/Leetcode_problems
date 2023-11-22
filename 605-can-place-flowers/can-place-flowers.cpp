class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int c =0;
                int s = flowerbed.size();

                if(s==1){
                    if(flowerbed[0]==0 && n==1)
                    return true;
                    else if(n==0)
                    return true;
                    else
                    return false;
                }
        if(flowerbed[0]==0 && flowerbed[1]==0){
            c++;
            flowerbed[0]=1;
        }
        for(int i=1;i<flowerbed.size()-1;i++){
            if(flowerbed[i]==0){
                if(flowerbed[i-1]==0 && flowerbed[i+1]==0){
                    flowerbed[i]=1;
                    c++;
                }
            }
        }
        if(flowerbed[s-1]==0 && flowerbed[s-2]==0)
        {
            flowerbed[s-1]=1;
            c++;
        }
        if(c>=n)
        return true;
        return false;
    }
};