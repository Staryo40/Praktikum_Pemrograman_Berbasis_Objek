class Couple<K, V>{
    private K key;
    private V value;

    public Couple(K key, V value){
        this.key = key;
        this.value = value;
    }

    public K getKey(){
        return this.key;
    }

    public V getVal(){
        return this.value;
    }

    public void setKey(K key){
        this.key = key;
    }

    public void setVal(V val){
        this.value = val;
    }

    public boolean isEqual(Couple c){
        return (this.getKey() == c.getKey()) && (this.getVal() == c.getVal());
    }

    public int nearEQ(Couple couple){
        if (this.getKey() != couple.getKey() && this.getVal() != couple.getVal()) {return 0;}
        else if (this.getKey() == couple.getKey() && this.getVal() != couple.getVal()) {return 1;}
        else if (this.getKey() != couple.getKey() && this.getVal() == couple.getVal()) {return 2;}
        else {return 3;}
    }
}