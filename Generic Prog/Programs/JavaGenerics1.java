public class Box<T> {
    private T t;

    public void set(T t) {
        this.t = t;
    }

    public T get() {
        return t;
    }
}

Box<Integer> integerBox = new Box<Integer>();
integerBox.set(new Integer(10));
Integer myInteger = integerBox.get();
System.out.println(myInteger);

# Output:
# 10
