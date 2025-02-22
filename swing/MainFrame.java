import java.awt.*;
import java.io.IOException;
import javax.swing.*;

/**
 * @file MainFrame.java
 * @brief MainFrame class for creating a Java Swing GUI.
 */
public class MainFrame extends JFrame {
    private static final long serialVersionUID = 1L;

    private JTextArea textArea; ///< Multi-line text area for displaying text.
    private JTextField inputField; ///< Input field for search/play commands.
    private Client client; ///< Client for communicating with the C++ server.

    /**
     * @brief Constructor for MainFrame.
     */
    public MainFrame() {
        // Set window title
        setTitle("Main Window");

        // Set default close operation
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        // Create multi-line text area
        textArea = new JTextArea(30, 30);

        JScrollPane scrollPane = new JScrollPane(textArea);

        // Create input field
        inputField = new JTextField(20);

        // Initialize client
        try {
            client = new Client("localhost", 3331);
        } catch (IOException e) {
            textArea.append("Error: Failed to connect to server: " + e.getMessage() + "\n");
            System.exit(1);
        }

        // Create actions for buttons
        Action searchAction = new SearchAction("Search object", textArea, inputField, client);
        Action searchGroupAction = new SearchGroupAction("Search Group", textArea, inputField, client);
        Action playAction = new PlayAction("Play", textArea, inputField, client);
        Action exitAction = new ExitAction("Exit");

        // Create buttons and add actions
        JButton searchButton = new JButton(searchAction);
        JButton searchGroupButton = new JButton(searchGroupAction);

        JButton playButton = new JButton(playAction);
        JButton exitButton = new JButton(exitAction);

        // Create panel for input field and buttons
        JPanel inputPanel = new JPanel();
        inputPanel.add(new JLabel("Enter object / group name:"));
        inputPanel.add(inputField);
        inputPanel.add(searchButton);
        inputPanel.add(searchGroupButton);
        inputPanel.add(playButton);
        inputPanel.add(exitButton);

        TopPanel topPanel = new TopPanel(searchAction, searchGroupAction, playAction, exitAction);
        GuidePanel guidePanel = new GuidePanel();

        JSplitPane splitPane = new JSplitPane(JSplitPane.HORIZONTAL_SPLIT, scrollPane, guidePanel);
        splitPane.setResizeWeight(0.55); // Set initial size ratio

        // Set layout and add components
        setLayout(new BorderLayout());
        add(topPanel, BorderLayout.NORTH); // Top panel in the north
        add(splitPane, BorderLayout.CENTER); // Split pane in the center
        add(inputPanel, BorderLayout.SOUTH); // Input panel in the south

        // Automatically adjust window size and display
        pack();
        setVisible(true);
    }


}