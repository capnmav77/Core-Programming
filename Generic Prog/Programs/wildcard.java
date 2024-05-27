package Practice;

import java.lang.reflect.Array;

public class wildcard {
    public static void main(String[] args) {
        System.out.println("Hello World");
        wldc<Integer> iob = new wldc<Integer>(new Integer[]{1, 2, 3, 4, 5});
        wldc<Double> dob = new wldc<Double>(new Double[]{1.1, 2.2, 3.3, 4.4, 5.5});
        System.out.println(iob.average(iob));
    }

//     5.c. Explain the purpose and usage of wildcards in Java generics. Write a simple
// Java program that demonstrates the use of wildcards to create a method that can
// accept a list of any type of number (e.g., integers, floats, or doubles) and calculate
// the sum of its elements.

}


class wldc<T extends Number>
{
    T[] nums;

    wldc(T[] o)
    {
        nums = o;
    }

    double sum()
    {
        double sum = 0.0;
        for (int i = 0; i < nums.length; i++)
        {
            sum += nums[i].doubleValue();
        }
        return sum;
    }

    int average(wldc<? extends Comparable<?>> ob)
    {
        if (this.sum() == ob.sum())
        {
            return 1;
        }
        return 0;
    }


}
