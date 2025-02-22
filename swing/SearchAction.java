import java.awt.event.ActionEvent;
import javax.swing.*;

/**
 * @file SearchAction.java
 * @brief Action for searching a multimedia object.
 */
public class SearchAction extends AbstractAction {
    private JTextArea textArea; ///< Text area to display the result.
    private JTextField inputField; ///< Input field for search commands.
    private Client client; ///< Client for communicating with the server.

    /**
     * @brief Constructor for SearchAction.
     */
    public SearchAction(String name, JTextArea textArea, JTextField inputField, Client client) {
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
            String response = client.send("search_obj " + name); // Send request to server
            if (response != null) {
                // Split the response by the separator (e.g., ";")
                textArea.append("Search results:\n");
                String[] lines = response.split(";");
                for (String line : lines) {
                    textArea.append(line + "\n"); // Append each line to the text area
                }
                textArea.append("\n");
            } else {
                textArea.append("Error: Failed to search object.\n");
            }
        } else {
            textArea.append("Error: No name provided for search.\n");
        }
    }
}