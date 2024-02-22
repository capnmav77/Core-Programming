class Solution {
public:
    int brokenCalc(int sv, int target) {
        if(target%sv==0){
            int count = 0;
            while(target>1){
                target = target/sv;
                count++;
            }
            return count -1;
        }
        if(target< = sv){
            return sv-target;
        }
        if(target%(sv-1)==0 && sv-1 > 1 && target/(sv-1)<3){
            if(target/(sv-1)==1){
                return 1;
            }
            cout<<"subbing"<<endl;
            return 1+ brokenCalc(sv-1, target);
        }
        cout<<"multiplying"<<endl;
        return 1+ brokenCalc(sv*2 , target);
        
        // if(start>=target)return start-target;
        // else 
        //     if(target-start==1) return 2;
        //     if((target-start)%2==1)return (target-start)/2 ;
        //     return (target-start)/2;

         }
    
};