public class MoneyInBank implements MoneyTransaction{
    private int amount;
    private int interestRate;
    private int totalLoanAmount;

    /*
     * Inisialisasi amount = 0, interest rate = 10 yang berarti bunga sebesar 10%, totalLoanAmount = 0;
     */
    public MoneyInBank() {
        this.amount = 0;
        this.interestRate = 10;
        this.totalLoanAmount = 0;
    }

    /*
     * Inisialisasi amount sesuai masukan dan interest rate sebesar intereseRate% dan totalLoanAmount sesuai masukan
     */
    public MoneyInBank(int amount, int interestRate, int totalLoanAmount) {
        this.amount = amount;
        this.interestRate = interestRate;
        this.totalLoanAmount = totalLoanAmount;
    }

    /*
     * Mengembalikan nilai amount
     */
    public int getAmount() {
        return this.amount;
    }

    /*
     * Mengembalikan nilai interestRate
     */
    public int getInterestRate() {
        return this.interestRate;
    }

    /*
     * Mengembalikan nilai totalLoanAmount
     */
    public int getTotalLoanAmount() {
        return this.totalLoanAmount;
    }

    /*
     * Menambahkan amount dengan amount dari masukan
     * Kembalikan hasilnya pada objek baru MoneyInBank dengan interestRate dari this.interestRate dan totalLoanAmount dari this.totalLoanAmount
     */
    @Override
    public MoneyTransaction add(MoneyTransaction money) {
        this.amount += money.getAmount();
        return this;
    }

    /*
     * Mengurangkan amount dengan amount dari masukan
     * Kembalikan hasilnya pada objek baru MoneyInBank dengan interestRate dari this.interestRate dan totalLoanAmount dari this.totalLoanAmount
     * Jika amount dari masukan lebih besar dari amount, maka objek yang dikembalikan memiliki amount = 0
     */
    @Override
    public MoneyTransaction subtract(MoneyTransaction money) {
        if (this.amount < money.getAmount()) {
            this.amount = 0;
            return this;
        }
        this.amount -= money.getAmount();
        return this;
    }

    /*
     * Menghitung bunga yang diperoleh dari amount
     * Bunga dihitung dengan rumus (amount * interestRate) / 100
     * Jika bunga bukan bilangan bulat, bulatkan ke bawah
     */
    public int calcInterest() {
        int interest = (int) (this.amount * this.interestRate /100);
        return interest;
    }

    /*
     * Meminjam uang
     * Tambahkan amount dengan loanAmount
     * Tambahkan totalLoanAmount dengan (loanAmount * (100 + interestRate)) / 100)
     * Jika penambahan bukan bilangan bulat, bulatkan ke bawah
     */
    public void borrow(int loanAmount) {
        this.amount += loanAmount;
        this.totalLoanAmount += (int) (loanAmount * (100 + this.interestRate) / 100);
    }

    /*
     * Menggambarkan transaksi setiap bulannya pada uang di bank
     * Pertama tambahkan bunga pada amount
     * Kemudian kurangkan amount dengan totalLoanAmount
     * Jika amount kurang dari 0, set amount menjadi 0
     * Set totalLoanAmount menjadi 0
     */

    public void monthlyTransaction() {
        this.amount += calcInterest();
        this.amount -= this.totalLoanAmount;
        if (this.amount < 0) this.amount = 0;
        this.totalLoanAmount = 0; 
    }
}
