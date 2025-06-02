import java.util.Objects;

class Redis<K, V>{
    private K key;
    private V value;
    private long ttl;

    public Redis(K k, V v, long ttl){
        if (ttl <= 0){
            throw new InvalidTtlException("TTL must be positive");
        }
        this.key = k;
        this.value = v;
        this.ttl = ttl;
    }

    public K getKey(){ return this.key; }
    public V getVal(long elapsedSeconds){ 
        if (this.ttl - elapsedSeconds <= 0){
            throw new TtlExpiredException(this.getKey() + " expired");
        }
        return this.value; 
    }

    public void setKey(K k){ this.key = k; }
    public void setVal(V v){ this.value = v; }

    public long getRemainingTtl(long elapsedSeconds){
        if (this.ttl - elapsedSeconds <= 0){
            return 0;
        } else {
            return this.ttl - elapsedSeconds;
        }
    }

    public void refresh(long newTtl){
        if (newTtl <= 0){
            throw new InvalidTtlException("TTL must be positive");
        } else {
            this.ttl = newTtl;
        }
    }

    public boolean isEqual(Redis<?, ?> c){
        return Objects.equals(this.key, c.key) && Objects.equals(this.value, c.value);
    }

    public int nearEQ(Redis<?, ?> c){
        if (this.isEqual(c)){
            return 3;
        } else if (this.value.equals(c.value)){
            return 2;
        } else if (this.getKey().equals(c.getKey())){
            return 1;
        } else {
            return 0;
        }
    }
}