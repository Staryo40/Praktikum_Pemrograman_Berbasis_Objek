import java.lang.reflect.Method;
import java.util.ArrayList;
import java.util.List;
import java.util.Map;
import java.lang.reflect.*;

public class Reflection{
    //TIDAK BOLEH MENGUBAH NAMA METHOD YANG SUDAH ADA DAN PARAMS SERTA INPUT TYPENYA
    //BOLEH MENAMBAHKAN PRIVATE / PROTECTED METHOD SESUAI DENGAN KEBUTUHAN
    //DI LUAR SANA ADA KELAS YANG NAMANYA Ghost DAN Secret.

    public ArrayList<String> ghostMethods(){
        ArrayList<String> result = new ArrayList<>();
        try {
            Class<?> ghostClass = Class.forName("Ghost");
            Method[] methods = ghostClass.getDeclaredMethods();

            for (Method method : methods) {
                result.add(method.getName());
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
        return result;
    }   

    public Integer sumGhost() throws Exception{
        Class<?> ghostClass = Class.forName("Ghost");
        Object ghostInstance = ghostClass.getDeclaredConstructor().newInstance();
        Method[] methods = ghostClass.getDeclaredMethods();

        int sum = 0;
        for (Method method : methods) {
            method.setAccessible(true);
            Object result = method.invoke(ghostInstance);
            if (result instanceof Integer) {
                sum += (Integer) result;
            }
        }
        return sum;
    }

    public String letterGhost() throws Exception{
        Class<?> ghostClass = Class.forName("Ghost");
        Object ghostInstance = ghostClass.getDeclaredConstructor().newInstance();
        Method[] methods = ghostClass.getDeclaredMethods();

        StringBuilder res = new StringBuilder();
        for (Method method : methods) {
            method.setAccessible(true);
            Object element = method.invoke(ghostInstance);
            if (element instanceof String) {
                res.append((String) element);
            }
        }
        return res.toString();
    }

    public String findSecretId(List<Secret> sl, String email) throws Exception{
        for (Secret s : sl) {
            Method isThisMethod = s.getClass().getMethod("isThis", String.class);
            boolean match = (boolean) isThisMethod.invoke(s, email);

            if (match) {
                Field uniqueIdField = s.getClass().getDeclaredField("uniqueId");
                uniqueIdField.setAccessible(true);
                return (String) uniqueIdField.get(s);
            }
        }
        return "NaN";
    }
}