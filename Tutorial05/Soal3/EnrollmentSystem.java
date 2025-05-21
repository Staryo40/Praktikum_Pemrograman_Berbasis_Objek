import java.util.HashMap;

public class EnrollmentSystem {
    private HashMap<String, Student> students; // <studentID, Student>
    private HashMap<String, Course> courses; // <courseID, Course>

    // Ctor untuk membuat objek EnrollmentSystem
    // Inisialisasi students dan courses
    public EnrollmentSystem() {
        students = new HashMap<String, Student>();
        courses = new HashMap<String, Course>(); 
    }

    // Method untuk menambahkan student ke dalam sistem
    public void addStudent(String studentID, String name) {
        students.put(studentID, new Student(studentID, name));
    }

    // Method untuk menambahkan course ke dalam sistem
    public void addCourse(String courseID, String courseName) {
        Course c = new Course(courseID, courseName);
        courses.put(courseID, c); 
    }

    // Method untuk mendaftar student ke dalam course
    // Jika student atau course tidak ditemukan, tampilkan pesan error
    // "Student atau course tidak ditemukan!" (tanpa tanda kutip)
    public void enrollStudentInCourse(String studentID, String courseID) {
        if (students.containsKey(studentID) && courses.containsKey(courseID)){
            students.get(studentID).enrollCourse(courseID);
            courses.get(courseID).addStudent(studentID);
        } else {
            System.out.println("Student atau course tidak ditemukan!");
        }
    }

    // Method untuk menampilkan daftar course yang diambil oleh student
    // 
    // Student <studentName> terdaftar di <jumlah course> course:
    // <courseID1> <courseName1>
    // <courseID2> <courseName2>
    // ...
    //
    // Jika student tidak ditemukan, tampilkan pesan error
    // "Student tidak ditemukan!" (tanpa tanda kutip)
    public void displayCoursesForStudent(String studentID) {
        if (!students.containsKey(studentID)){
            System.out.println("Student tidak ditemukan!");
            return;
        }
        System.out.printf("Student %s terdaftar di %d course:\n", students.get(studentID).getName(), students.get(studentID).getEnrolledCourses().size());
        for (String el : students.get(studentID).getEnrolledCourses()){
            System.out.println(el + " " + courses.get(el).getCourseName());
        }
    }

    // Method untuk menampilkan daftar student yang terdaftar di course
    // 
    // Course <courseName> memiliki <jumlah student> student:
    // <studentID1> <studentName1>
    // <studentID2> <studentName2>
    // ...
    //
    // Jika course tidak ditemukan, tampilkan pesan error
    // "Course tidak ditemukan!" (tanpa tanda kutip)
    public void displayStudentsInCourse(String courseID) {
       if (!courses.containsKey(courseID)){
            System.out.println("Course tidak ditemukan!");
            return;
        }
        System.out.printf("Course %s memiliki %d student:\n", courses.get(courseID).getCourseName(), courses.get(courseID).getEnrolledStudents().size());
        for (String el : courses.get(courseID).getEnrolledStudents()){
            System.out.println(el + " " + students.get(el).getName());
        }
    }
}
