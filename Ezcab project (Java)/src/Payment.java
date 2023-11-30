public interface Payment {
    double getTaxiPrice(int[] position1, int[] position2);
    double getShuttleFare(String initial, String destination);
}
