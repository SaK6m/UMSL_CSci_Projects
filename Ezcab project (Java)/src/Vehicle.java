import java.util.ArrayList;
import java.util.Scanner;
import java.util.Vector;

public abstract class Vehicle implements Payment{
    ArrayList<String> route;
    String id;
    String location;
    String destination;

    public Vehicle(String id, String location){
        this.id = id;
        this.location = "Company Base";
        this.destination = null;
    }

    public String getId(){
        return id;
    }

    public String getDestination() {
        return destination;
    }

    public String getStatus() {
        if (destination != null) {
            return "Booked";
        } else {
            return "Available";
        }
    }

    public void setDestination(String dest) {
        destination = dest;
    }

    // Price set according to distance for taxi
    public double getTaxiPrice(int[] position1, int[] position2){
        double price;
        int xDifference = position2[0] - position1[0];
        int yDifference = position2[1] - position1[1];

        int dist;
        dist = (int)Math.sqrt(Math.pow(xDifference, 2) + Math.pow(yDifference, 2));
        if (dist <=5){
            price = 10;
        } else if (dist <= 10) {
            price = 12;
        }else if (dist <= 15) {
            price = 15;
        } else if (dist <= 20) {
            price = 20;
        }else {
            price = 25;
        }

        return price;
    }

    // Price set for Shuttle route
    public double getShuttleFare(String initialPosition,String destination) {
        int initialIndex = route.indexOf(initialPosition);
        int destinationIndex = route.indexOf(destination);

        if (initialIndex < 0 || destinationIndex < 0) {
            return -1; // Invalid input
        }

        int difference = destinationIndex - initialIndex;
        if (difference < 0) {
            difference += route.size(); // Account for looping
        }

        double fare = difference * 2;
        return fare;
    }

}
