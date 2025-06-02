public class Main {

    public static void main(String[] args) {

        /* ---------- 1. Konstruktor & akses dasar ---------- */
        Redis<String, Integer> r1 = new Redis<>("token#A", 111, 5);
        System.out.println("r1 key   : " + r1.getKey());
        System.out.println("r1 value : " + r1.getVal(0));          // elapsed = 0
        System.out.println("r1 TTL   : " + r1.getRemainingTtl(2)); // elapsed = 2  -> 5 - 2 = 3
        System.out.println();

        /* ---------- 2. Exception: TTL habis ---------- */
        try {
            System.out.println("Access r1 after expired:");
            r1.getVal(6); // elapsed = 6 > 5  -> harus throw
        } catch (TtlExpiredException e) {
            System.out.println("[Expired] " + e.getMessage());
        }
        System.out.println();

        /* ---------- 3. refresh & akses lagi ---------- */
        r1.refresh(4); // ttl baru 4 s, anggap elapsed di-reset
        System.out.println("r1 TTL after refresh (elapsed 0): " + r1.getRemainingTtl(0));
        System.out.println("r1 value after refresh (elapsed 3): " + r1.getVal(3));
        System.out.println();

        /* ---------- 4. setKey & setVal ---------- */
        r1.setKey("token#A-updated");
        r1.setVal(222);
        System.out.println("r1 key setelah setKey : " + r1.getKey());
        System.out.println("r1 val (elapsed 1)     : " + r1.getVal(1));
        System.out.println();

        /* ---------- 5. Membuat r2, uji isEqual & nearEQ ---------- */
        Redis<String, Integer> r2 = new Redis<>("token#B", 222, 10);

        System.out.println("isEqual(r1,r2) : " + r1.isEqual(r2));      // false
        System.out.println("nearEQ(r1,r2)  : " + r1.nearEQ(r2));       // 2 (value sama)
        System.out.println();

        /* ---------- 6. Exception: TTL negatif saat konstruktor ---------- */
        try {
            Redis<String, String> bad = new Redis<>("x", "oops", 0);
        } catch (InvalidTtlException e) {
            System.out.println("[Invalid TTL] " + e.getMessage());
        }
    }
}
