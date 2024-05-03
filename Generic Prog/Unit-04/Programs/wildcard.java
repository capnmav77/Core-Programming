public class wildcard {
    public static void main(String[] args) {
        Integer[] inums = {1, 2, 3, 4, 5};
        Integer[] iob = new Stats<Integer>(inums);
        double v  = iob.average();
        System.out.println("Average of iob is " + v); 
    }
}


public Stats<