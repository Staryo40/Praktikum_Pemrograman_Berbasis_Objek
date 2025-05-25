import java.util.ArrayList;
import java.util.List;

/**
 * Pastikan kalian menggunakan type parameter yang benar
 */
public class Inventory {
    private List<Box<?>> boxes;

    // Constructor, inisiasi dengan list of boxes
    public Inventory(List<Box<?>> boxes) {
        this.boxes = boxes;
    }

    // Method untuk membuka semua box
    public void openAll() {
        for (int i = 0; i < boxes.size(); i++){
            boxes.get(i).open();
        }
    }

    // Method untuk menambahkan box
    public void addBox(Box<?> box) {
        boxes.add(box);
    }

    // Method untuk menghapus box
    public void removeBox(Box<?> box) {
        boxes.remove(box);
    }

    // Getter dan setter
    public List<Box<?>> getBoxes() {
        return boxes;
    }
    
    public void setBoxes(List<Box<?>> boxes) {
        this.boxes = boxes;
    }
    
}