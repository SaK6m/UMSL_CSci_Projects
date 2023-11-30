import java.util.*;
public class Shuttle extends Vehicle {

    int stopNum;
    public Shuttle(String id, String location, ArrayList<String> route){
        super(id, location);
        this.route = route;
        this.stopNum = 0;
    }

    public boolean isOnRoute(String destination){
        return route.contains(destination);
    }
}
