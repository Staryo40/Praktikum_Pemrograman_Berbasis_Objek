class Character extends Unit implements Damageable{
    private int score = 0;
    public Character(){
        super("Player1", 100);
        this.score = 0;
    }
    public Character(String name, int health, int score){
        super(name, health);
        this.score = score;
    }
    public int getScore(){
        return score;
    }
    public void setScore(int score){
        this.score = score;
    }
    public void takeDamage(int damage){
        this.health -= damage;
        if (this.health <= 0){
            System.out.printf("%s has been defeated\n", this.getName());
        }
    }
    public void increaseScore(int points){
        this.score += points;
    }
    @Override
    public String toString() {
        return String.format("%s [Health: %d, Score: %d]", this.getName(), this.getHealth(), this.score);
    }
}