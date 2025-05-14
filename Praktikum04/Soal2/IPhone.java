public class IPhone extends Device {
    private int batteryLevel;
    
    // Set battery level to 100 on initialization
    public IPhone() {
        super("IPhone");
        this.batteryLevel = 100;
    }
    
    @Override
    // Kalau phonenya connected dan battery level > 0, print "IPhone is nearby! Distance: <battery level> meters away" dan kurangi battery level 10
    // Lalu, kalau phonenya tidak connected, print "IPhone is not connected"
    // Lalu, kalau battery level <= 0, print "IPhone battery is depleted"
    public void locate() {
        if (batteryLevel <= 0){
            System.out.println("IPhone battery is depleted");
        } else if (!isConnected()){
            System.out.println("IPhone is not connected");
        } else {
            System.out.println("IPhone is nearby! Distance: " +  batteryLevel + " meters away");
            batteryLevel -= 10;
        }
    }
    
    @Override
    // Kalau phonenya connected dan battery level > 0, print "IPhone: *LOUD BEEPING*" dan kurangi battery level 20
    // Kalau phonenya tidak connected, print "IPhone is not connected"
    // Kalau battery level <= 0, print "IPhone battery is depleted"
    public void makeSound() {
        if (batteryLevel <= 0){
            System.out.println("IPhone battery is depleted");
        } else if (!isConnected()){
            System.out.println("IPhone is not connected");
        } else {
            System.out.println("IPhone: *LOUD BEEPING*");
            batteryLevel -= 20;
        }
    }
    
    // Set the battery level to 100
    // Print out "IPhone charged to 100%"
    public void charge() {
        batteryLevel = 100;
        System.out.println("IPhone charged to 100%");
    }
}