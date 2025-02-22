/**
 * @file Main.java
 * @brief Main class to start the application.
 */
public class Main {
    /**
     * @brief Main method to start the application.
     * 
     * @param args Command-line arguments (not used).
     */
    public static void main(String[] args) {
        // Set macOS menu bar property
        System.setProperty("apple.laf.useScreenMenuBar", "false");

        // Create and display the main window
        new MainFrame();
    }
}