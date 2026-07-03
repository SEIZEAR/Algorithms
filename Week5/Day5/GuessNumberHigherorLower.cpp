class Solution {
public:
    int guessNumber(int n) {

        int left=1,right=n;

        while(left<=right){

            int mid=left+(right-left)/2;

            int g=guess(mid);

            if(g==0)
                return mid;

            if(g<0)
                right=mid-1;
            else
                left=mid+1;
        }

        return -1;
    }
};