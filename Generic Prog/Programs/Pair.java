class Pair<T, U> {
    private T first;
    private U second;

    // Constructor
    public Pair(T first, U second) {
        this.first = first;
        this.second = second;
    }

    // Getter and setter methods for first value
    public T getFirst() {
        return first;
    }

    public void setFirst(T first) {
        this.first = first;
    }

    // Getter and setter methods for second value
    public U getSecond() {
        return second;
    }

    public void setSecond(U second) {
        this.second = second;
    }

    // Main method for demonstration
    public static void main(String[] args) {
        // Creating two objects of different data types
        Pair<Integer, String> pair1 = new Pair<>(10, "Hello");
        Pair<Double, Character> pair2 = new Pair<>(3.14, 'A');

        // Setting and retrieving values
        pair1.setFirst(20);
        pair1.setSecond("World");
        System.out.println("Pair 1: (" + pair1.getFirst() + ", " + pair1.getSecond() + ")");

        System.out.println("Pair 2: (" + pair2.getFirst() + ", " + pair2.getSecond() + ")");
    }
}
