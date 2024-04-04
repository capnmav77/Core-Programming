class Stats<T>
{
    T[] nums;
    Stats(T[] o){
        nums = o;
    }

    double average(){   
        double sum = 0.0;
        for(int i=0 ; i<nums.length ; i++){
            sum += nums[i].doubleValue(); // Error: cannot find symbol - method doubleValue() - because T is not bounded to Number
        }
        return sum/nums.length;
    }
}