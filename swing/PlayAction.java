import java.awt.event.ActionEvent;
import javax.swing.*;

/**
 * @file PlayAction.java
 * @brief Action for playing a multimedia object.
 */
public class PlayAction extends AbstractAction {
    private JTextArea textArea; ///< Text area to display the result.
    private JTextField inputField; ///< Input field for play commands.
    private Client client; ///< Client for communicating with the server.

    /**
     * @brief Constructor for PlayAction.
     */
    public PlayAction(String name, JTextArea textArea, JTextField inputField, Client client) {
        super(name);
        this.textArea = textArea;
        this.inputField = inputField;
        this.client = client;
    }

    /**
     * @brief Action performed when the button is clicked.
     */
    @Override
    public void actionPerformed(ActionEvent e) {
        String name = inputField.getText().trim(); // Get input from the text field
        if (!name.isEmpty()) {
            String response = client.send("play " + name); // Send request to server
            if (response != null) {
                textArea.append("Play Result: " + response + "\n");
            } else {
                textArea.append("Error: Failed to play object.\n");
            }
        } else {
            textArea.append("Error: No name provided for play.\n");
        }
    }
}