import java.awt.event.ActionEvent;
import javax.swing.*;

/**
 * @file SearchGroupAction.java
 * @brief Action for searching a multimedia group.
 */
public class SearchGroupAction extends AbstractAction {
    private JTextArea textArea; ///< Text area to display the result.
    private JTextField inputField; ///< Input field for search commands.
    private Client client; ///< Client for communicating with the server.

    /**
     * @brief Constructor for SearchGroupAction.
     */
    public SearchGroupAction(String name, JTextArea textArea, JTextField inputField, Client client) {
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
            textArea.append("Search results:\n");
            String response = client.send("search_grp " + name); // Send request to server
            if (response != null) {
                // Split the response by the separator (e.g., ";")
                String[] lines = response.split(";");
                for (String line : lines) {
                    textArea.append(line + "\n"); // Append each line to the text area
                }
                textArea.append("\n");
            } else {
                textArea.append("Error: Failed to search group.\n");
            }
        } else {
            textArea.append("Error: No name provided for search.\n");
        }
    }
}