//import jdk.incubator.vector.ShortVector;
import java.util.*;

public class Ezcab {
    ArrayList<Taxi> taxis;
    ArrayList<Shuttle> shuttles;
    String location;

    public Ezcab(){
        this.taxis = new ArrayList<>();
        this.shuttles = new ArrayList<>();
    }

    public void addTaxi(Taxi taxi){
        taxis.add(taxi);
    }

    public void addShuttle(Shuttle shuttle){
        shuttles.add(shuttle);
    }

    // booking vehicle according to position
    public Vehicle bookVehicle(String destination){
        for (Shuttle shuttle : shuttles) {
            if (shuttle.isOnRoute(destination)) {
                return shuttle;
            }
        }

        for (Taxi taxi : taxis) {
            if (taxi.getDestination() == null) {
                taxi.setDestination(destination);
                return taxi;
            }
        }

        return null;
    }

    // convert the vector to string name
    public String getStringDestination(int[] position2){
        if (Arrays.equals(position2, new int[]{0, 0})) {
            location = "University City";
        } else if (Arrays.equals(position2, new int[]{0, 5})) {
            location = "North Hanley";
        } else if (Arrays.equals(position2, new int[]{5, 5})) {
            location = "Ferguson";
        } else if (Arrays.equals(position2, new int[]{8, 0})){
            location = "Downtown";
        } else if (Arrays.equals(position2, new int[]{1, -3})) {
            location = "Clayton";
        } else if (Arrays.equals(position2, new int[]{-1, -10})) {
            location = "Webster Grover";
        } else if (Arrays.equals(position2, new int[]{-3, -10})){
            location = "Ballwin";
        } else if (Arrays.equals(position2, new int[]{-11, 0})) {
            location = "Maryland Heights";
        } else if (Arrays.equals(position2, new int[]{-6, -8})){
            location = "Lambert Airport";
        } else {
            return null;
        }

        return location;
    }

    // get 2D position vector from this method
    public int[] getPosition(int value){
        int[] position = null;
        if (value == 1) {
            position = new int[]{0, 0};
        } else if (value == 2) {
            position = new int[]{0, 5};
        } else if (value == 3) {
            position = new int[]{5, 5};
        } else if (value == 4){
            position = new int[]{8, 0};
        } else if (value == 5) {
            position = new int[]{1, -3};
        } else if (value == 6) {
            position = new int[]{-1, -10};
        } else if (value == 7){
            position = new int[]{-3, -10};
        } else if (value == 8) {
            position = new int[]{-11, 0};
        } else if (value == 9){
            position = new int[]{-6, -8};
        } else {
            return null;
        }
        return position;
    }

    // Method to find vehicle using the id number itself
    public Vehicle findVehicle(String id) {
        for (Taxi taxi : taxis) {
            if (taxi.getId().equals(id)) {
                return taxi;
            }
        }
        for (Shuttle shuttle : shuttles) {
            if (shuttle.getId().equals(id)) {
                return shuttle;
            }
        }
        return null;
    }
}
