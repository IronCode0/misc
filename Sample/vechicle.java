
public class vechicle {
    
    String name,type,fuel;
    boolean used,imported;
    
    public vechicle(String name,String type,String fuel,boolean used,boolean imported) {
        this.name=name;
        this.type=type;
        this.fuel=fuel;
        this.used=used;
        this.imported=imported;
    }
    public void info() {
        System.out.println("Name: " + this.name);
        System.out.println("type: " + this.type);
        System.out.println("fuel: " + this.fuel);
        System.out.print(this.name);

        if (used==true)
            System.out.print(" is used and ");
        else
            System.out.print(" new and ");

        if (imported)
            System.out.print(" imported vechicle ");
        else
            System.out.print(" made in India ");
        
        System.out.println();       //new line
    }
    public static void main(String[] args) {
        vechicle a = new vechicle("Honda accord","car","diesel",false,false);
        vechicle b = new vechicle("Ducati","Bike","petrol",true,true);
        a.info();
        b.info();
    }
};


