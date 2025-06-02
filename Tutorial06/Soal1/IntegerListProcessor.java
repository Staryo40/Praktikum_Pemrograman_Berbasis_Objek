import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class IntegerListProcessor {
    // Gunakan function ini untuk output
    private static void printList(List<Integer> list) {
        for (int i = 0; i < list.size(); i++) {
            System.out.print(list.get(i));
            if (i < list.size() - 1) {
                System.out.print(" ");
            }
        }
        System.out.println();
    }

    // Wajib menggunakan Java Collections API untuk semua operasi pada list
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // 1. Baca N. N adalah jumlah input
        Integer N = Integer.parseInt(sc.nextLine());

        // 2. Baca N bilangan dan simpan ke List<Integer>
        String numberLine = sc.nextLine();

        String[] tokens = numberLine.split(" ");              
        List<Integer> numbers = new ArrayList<>();

        for (Integer i = 0; i < N; i++) {
            numbers.add(Integer.parseInt(tokens[i])); 
        }

        // 3. Hapus semua elemen genap
        numbers.removeIf(num -> num % 2 == 0);

        // 4. Jika panjang list sekarang ganjil, sort ascending; else sort descending
        if (numbers.size() % 2 == 1){
            Collections.sort(numbers);                
        } else {
            Collections.sort(numbers, Collections.reverseOrder()); 
        }
    
        // 5. Untuk setiap elemen, kalikan dengan tiga
        numbers.replaceAll(num -> num * 3);

        // 6. Cetak elemen menggunakan method printList
        printList(numbers);
    }
}