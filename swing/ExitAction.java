import java.awt.event.ActionEvent;
import javax.swing.*;

/**
 * @file ExitAction.java
 * @brief Action for the exit button.
 */
public class ExitAction extends AbstractAction {
    /**
     * @brief Constructor for ExitAction.
     */
    public ExitAction(String name) {
        super(name);
    }

    /**
     * @brief Action performed when the exit button is clicked.
     */
    @Override
    public void actionPerformed(ActionEvent e) {
        System.exit(0);
    }
}