public class BoxType<T> {
    private T t;          
    public void set(T t) {
        this.t = t;
    }
    public T get() {
        return t;
    }

    public <U extends Number> void inspect(U u){
        System.out.println("T: " + t.getClass().getName());
        System.out.println("U: " + u.getClass().getName());
    }

    public static void main(String[] args) {
        BoxType<Integer> integerBox = new BoxType<Integer>();
        integerBox.set(new Integer(10));
        integerBox.inspect("some text"); // error: this is still String!
	integerBox.inspect (100);
    }
}
