import java.util.LinkedList;
import java.util.List;
import java.util.stream.Collectors;

/**
 * Implementasi dari interface SistemMasukSekolahList menggunakan LinkedList
 * PETUNJUK:
 * - Gunakan LinkedList sebagai struktur data utama
 * - Manfaatkan fitur Java Collections
 */
public class SistemMasukSekolahListImpl implements SistemMasukSekolahList {
    
    // Atribut: gunakan LinkedList<Student> untuk menyimpan data siswa
    private LinkedList<Student> students;
    
    /**
     * Constructor: inisialisasi LinkedList students
     */
    public SistemMasukSekolahListImpl() {
        this.students = new LinkedList<>();
    }
    
    @Override
    public void addStudent(Student student) {
        // TODO: Implementasikan method ini
        // Menambahkan siswa ke dalam list
        students.add(student);
    }
    
    @Override
    public void addFirstStudent(Student student) {
        // TODO: Implementasikan method ini
        // Menambahkan siswa di awal list
        students.addFirst(student);
    }
    
    @Override
    public void addLastStudent(Student student) {
        // TODO: Implementasikan method ini
        // Menambahkan siswa di akhir list
        students.addLast(student);
    }
    
    @Override
    public Student getFirstStudent() {
        // TODO: Implementasikan method ini
        // Mengambil siswa pertama di list
        if(students.size() == 0) return null;
        return students.getFirst();
    }
    
    @Override
    public Student getLastStudent() {
        // TODO: Implementasikan method ini
        // Mengambil siswa terakhir di list
        if(students.size() == 0) return null;
        return students.getLast();
    }
    
    @Override
    public Student removeFirstStudent() {
        // TODO: Implementasikan method ini
        // Menghapus dan mengembalikan siswa pertama di list
        if(students.size() == 0) return null;
        return students.removeFirst();
    }
    
    @Override
    public Student removeLastStudent() {
        // TODO: Implementasikan method ini
        // Menghapus dan mengembalikan siswa terakhir di list
        if(students.size() == 0) return null;
        return students.removeLast();
    }
    
    @Override
    public int removeStudentsByGpa(double minGpa) {
        // TODO: Implementasikan method ini
        // Menghapus siswa dengan GPA < minGpa
        // Return jumlah siswa yang dihapus
        if (students.size() == 0) return 0;
        int count = 0;
        for (Student s : students){
            if (s.getGpa() < minGpa){
                count++;
                students.remove(s);
            }
        }
        return count;
    }
    
    @Override
    public List<Student> getStudentsWithHighGpa(double minGpa) {
        // TODO: Implementasikan method ini
        // Mencari siswa dengan GPA >= minGpa
        if (students.size() == 0) return null;
        List<Student> hs = new LinkedList<>();
        for (Student s : students){
            if (s.getGpa() >= minGpa){
                hs.add(s);
            }
        }
        return hs;
    }
    
    @Override
    public List<Student> getStudentsByAge(int age) {
        // TODO: Implementasikan method ini
        // Mencari siswa dengan umur tertentu
        if (students.size() == 0) return null; 
        List<Student> hs = new LinkedList<>();
        for (Student s : students){
            if (s.getAge() == age){
                hs.add(s);
            }
        }
        return hs;
    }
    
    @Override
    public List<String> getYoungHighAchieverNames(int maxAge, double minGpa) {
        // TODO: Implementasikan method ini
        // Mencari nama siswa muda (umur < maxAge) dan berprestasi (GPA >= minGpa)
        if (students.size() == 0) return null;
        List<String> hs = new LinkedList<>();
        for (Student s : students){
            if (s.getAge() < maxAge && s.getGpa() >= minGpa){
                hs.add(s.getName());
            }
        }
        return hs;
    }
    
    @Override
    public List<Student> getAllStudents() {
        // TODO: Implementasikan method ini
        // Mengembalikan seluruh siswa dalam list
        if (students.size() == 0) return null;
        List<Student> hs = new LinkedList<>();
        for (Student s : students){
            hs.add(s);
        }
        return hs;
    }
}
