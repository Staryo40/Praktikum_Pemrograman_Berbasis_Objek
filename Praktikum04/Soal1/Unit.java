abstract class Unit{
    private String name;
    public int health;

    public Unit(String name, int health){
        this.name = name;
        this.health = health;
    }

    public String getName(){
        return name;
    }

    public void setName(String name){
        this.name = name;
    }

    public int getHealth(){
        return health;
    }

    public void setHealth(int health){
        this.health = health;
    }

    public abstract String toString();
}