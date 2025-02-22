import java.awt.*;
import javax.swing.*;

/**
 * @file TopPanel.java
 * @brief TopPanel class for creating a panel containing the menu bar and toolbar.
 */
public class TopPanel extends JPanel {
    /**
     * @brief Constructor for TopPanel.
     */
    public TopPanel(Action searchAction, Action searchGroupAction, Action playAction, Action exitAction) {
        // Set layout
        setLayout(new BorderLayout());

        // Create menu bar
        JMenuBar menuBar = new JMenuBar();

        // Create menu
        JMenu menu = new JMenu("Actions");
        menu.add(new JMenuItem(searchAction)); // Add search action as a menu item
        menu.add(new JMenuItem(searchGroupAction)); // Add search group action as a menu item
        menu.add(new JMenuItem(playAction)); // Add play action as a menu item
        menu.addSeparator(); // Add a separator
        menu.add(new JMenuItem(exitAction)); // Add exit action as a menu item

        // Add menu to menu bar
        menuBar.add(menu);

        // Create toolbar
        JToolBar toolBar = new JToolBar();
        toolBar.add(searchAction); // Add search action to toolbar
        toolBar.add(searchGroupAction); // Add search group action to toolbar
        toolBar.add(playAction); // Add play action to toolbar
        toolBar.addSeparator(); // Add a separator
        toolBar.add(exitAction); // Add exit action to toolbar

        // Add menu bar and toolbar to the panel
        add(menuBar, BorderLayout.WEST); // Menu bar on the left
        add(toolBar, BorderLayout.CENTER); // Toolbar on the right
    }
}