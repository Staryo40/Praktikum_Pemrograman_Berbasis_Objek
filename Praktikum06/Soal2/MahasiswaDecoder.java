import java.lang.reflect.*;

public class MahasiswaDecoder {
    private Mahasiswa mahasiswa;

    MahasiswaDecoder(Mahasiswa mahasiswa) {
        this.mahasiswa = mahasiswa;
    }

    public void addMatkul(String name) throws Exception {
        Method m = mahasiswa.getClass().getDeclaredMethod("addMatkul", String.class);
        m.setAccessible(true);
        m.invoke(mahasiswa, name);
    }

    public int getNIM() throws Exception {
        int nim = 0;
        Field field = mahasiswa.getClass().getDeclaredField("NIM");
        field.setAccessible(true);
        nim = (int) field.get(mahasiswa);
        return nim;
    }

    public double getIPK() throws Exception {
        double ipk = 0;
        Field field = mahasiswa.getClass().getDeclaredField("IPK");
        field.setAccessible(true);
        if (field.get(mahasiswa) instanceof Double){
            ipk = (double) field.get(mahasiswa);
        }
        return ipk;
    }
}
