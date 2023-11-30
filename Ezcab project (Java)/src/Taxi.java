public class Taxi extends Vehicle {
    String companyName;
    public Taxi(String id, String location, String companyName){
        super(id, location);
        this.companyName = companyName;
    }

    public String getCompany() {
        return companyName;
    }
}
