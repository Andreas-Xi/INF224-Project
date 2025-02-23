import java.awt.*;
import javax.swing.*;

/**
 * @file GuidePanel.java
 * @brief GuidePanel class for displaying a user guide.
 */
public class GuidePanel extends JPanel {
    private JTextArea guideArea; ///< Text area for displaying the guide.

    /**
     * @brief Constructor for GuidePanel.
     */
    public GuidePanel() {
        // Set layout
        setLayout(new BorderLayout());

        // Create guide text area
        guideArea = new JTextArea();
        guideArea.setEditable(false); // Make it read-only
        guideArea.setLineWrap(true); // Enable line wrapping
        guideArea.setWrapStyleWord(true); // Wrap at word boundaries

        // Set guide content
        String guideText = "User Guide:\n\n" +
                "Enter the name of a multimedia object or a group, then click: \n" +
                "- Search Object: search for a multimedia object\n" +
                "- Search Group: search for a multimedia group.\n" +
                "- Play: play a multimedia object.\n" +
                "- Exit: close the application.\n" + 
                "\n\n" + 
                "Multimedia in the database:\n" + 
                "- photo_ski\n" + 
                "- video_train\n" + 
                "- film_disney\n\n" + 
                "Group in the database:\n" + 
                "- my_group" + 
                "\n\n\nFor ex. \n" + 
                "Enter **video_train** in the text area, then click: \n" + 
                "Search Object\n" + 
                "Enter **film_disney** in the text area, then click: \n" + 
                "Play\n" + 
                "Finally, click Exit to quit the program.\n"; 
        guideArea.setText(guideText);

        // Add guide text area to the panel
        add(new JScrollPane(guideArea), BorderLayout.CENTER);
    }
}