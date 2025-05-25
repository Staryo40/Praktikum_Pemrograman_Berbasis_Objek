import java.util.*;

class Main{
    public static void main(String[] args) {
        Inventory inventory2 = new Inventory(new ArrayList<Box<?>>());
        inventory2.openAll();
        Box<String> temp = new Box<>("Hello, World!");
        Box<Double> temp2 = new Box<>(321.32323);
        inventory2.addBox(temp);
        inventory2.addBox(temp2);
        inventory2.openAll();
    }
}