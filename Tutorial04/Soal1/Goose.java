class Goose{
    private String name;
    private int honk;
    
    public Goose(){
        this.name = "Horrible";
        this.honk = 1;
    }

    public Goose(String n, int h){
        this.name = n;
        this.honk = h;
    }

    public void steal(String thing){
        System.out.println(this.name + " steals " + thing);
    }

    public String toString(){
        String base = this.name + " goose says";
        for (int i = 0; i < this.honk; i++){
            base += " honk";
        }
        return base;
    }
}

