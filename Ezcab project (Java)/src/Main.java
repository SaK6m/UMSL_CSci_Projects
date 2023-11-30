/*
---------------------------------------- EZCAB -------------------------------------------------
The prices are set according to the distance from the intial position to the final position.
A set of 2D vector position is set for the locations and the distance are calculated to get the prices for Taxi

For Shuttles, the prices are set according to the number of stops it need to travel further in the loop
*/
import java.util.*;
public class Main {
    static Ezcab xyz = new Ezcab();
    static Scanner scanner = new Scanner(System.in);

    public static void main(String[] args){
        // main menu selection
        boolean exit = false;

        while(!exit) {
            System.out.println("Select from the menu.");
            System.out.println("1. Add Taxis");
            System.out.println("2. Add Shuttles");
            System.out.println("3. Book a vehicle");
            System.out.println("4. Show status of a vehicle");
            System.out.println("5. Exit");

            int selection = scanner.nextInt();
            scanner.nextLine();

            switch (selection) {
                case 1:
                    addTaxis();
                    break;
                case 2:
                    addShuttles();
                    break;
                case 3:
                    bookVehicle();
                    break;
                case 4:
                    getStatus();
                    break;
                case 5:
                    System.out.println("Exiting.........");
                    exit = true;
                    break;
                default:
                    System.out.println("Invalid choice. Please try again.");
            }
            System.out.println("Do you want to return to the main menu (Y/N)");
            String returnToMenu = scanner.nextLine();
            if (returnToMenu.equalsIgnoreCase("N")) {
                break;
            }
        }
    }


    //to add taxi
    public static void addTaxis() {
        System.out.println("Enter your company name: ");
        String companyName = scanner.nextLine();
        System.out.println("Enter how many taxis you want to add:");
        int numT = scanner.nextInt();
        scanner.nextLine();

        for(int i = 0; i < numT; i++) {
            System.out.println("Enter the vehicle plate number of the taxi: ");
            String taxiID = scanner.nextLine();
            String location = "Company Base";
            xyz.addTaxi(new Taxi(taxiID, location, companyName));
        }
    }

    public static void addShuttles(){
        // Pre-defined Shuttle route
        List<String> routeLst = Arrays.asList("North Hanley", "Clayton", "Downtown", "Delmar", "Ferguson");
        ArrayList<String> route = new ArrayList<>(routeLst);

        System.out.println("Enter the number of shuttles you want to add:");
        int numS = scanner.nextInt();
        String shuttleName;

        for(int i = 0; i < numS; i++) {
            System.out.println("Enter the Shuttle names or ID: ");
            shuttleName = scanner.next();

            System.out.println("Enter the initial route of this Shuttle: ");
            String initialLoct = scanner.next();
            xyz.addShuttle(new Shuttle(shuttleName, initialLoct, route));
        }
    }

    public static void bookVehicle(){
        System.out.println("Enter your Name:");
        String custName = scanner.nextLine();

        System.out.println("What is your current location:");
        System.out.println("1. University City");
        System.out.println("2. North Hanley");
        System.out.println("3. Ferguson");
        System.out.println("4. Downtown");
        System.out.println("5. Clayton");
        System.out.println("6. Webster Groves");
        System.out.println("7. Ballwin");
        System.out.println("8. Maryland Heights");
        System.out.println("9. Lambert Airport");

        int locationSelect = scanner.nextInt();
        scanner.nextLine();

        // setting vector position for their initial position
        int[] position1 = xyz.getPosition(locationSelect);
        String source = xyz.getStringDestination(position1);

        System.out.println("Select your destination: ");
        System.out.println("1. University City");
        System.out.println("2. North Hanley");
        System.out.println("3. Ferguson");
        System.out.println("4. Downtown");
        System.out.println("5. Clayton");
        System.out.println("6. Webster Groves");
        System.out.println("7. Ballwin");
        System.out.println("8. Maryland Heights");
        System.out.println("9. Lambert Airport");

        int DestSelect = scanner.nextInt();
        scanner.nextLine();

        // setting vector position for their final position
        int[] position2 = xyz.getPosition(DestSelect);

        // to get the string from the position
        String destination = xyz.getStringDestination(position2);

        // price setting according to the distance
        Vehicle vehicle = xyz.bookVehicle(destination);

        // shuttle is preffered over taxi if the destination is on the route
        if (vehicle != null) {
            System.out.println("Vehicle booked:");
            System.out.println("ID: " + vehicle.getId());
            System.out.println("Type: " + (vehicle instanceof Shuttle ? "Shuttle" : "Taxi"));

            double fare;
            if (vehicle instanceof Shuttle == true){
                fare = vehicle.getShuttleFare(source, destination);
            } else {
                fare = vehicle.getTaxiPrice(position1, position2);
            }
            System.out.println("Fare: $" + fare);
        } else {
            System.out.println("No suitable vehicle available.");
        }
    }

    public static void getStatus(){
        System.out.println("Enter id of the taxi/shuttle");
        String vehicleId = scanner.nextLine();
        Vehicle vehicle = xyz.findVehicle(vehicleId);
        if (vehicle == null) {
            System.out.println("Vehicle not found.");
        } else {
            System.out.printf("This vehicle is currently %s.%n", vehicle.getStatus());
        }
    }
}
