#pragma once
#include <QMainWindow>

class QLabel;
class QPushButton;
class BoardWidget;
class Game2048;

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget* parent=nullptr);
    ~MainWindow();

protected:
    void keyPressEvent(QKeyEvent* e) override;

private:
    void refreshUI();
    void showWinDialogIfNeeded();

    Game2048* m_game;
    BoardWidget* m_board;
    QLabel* m_scoreLabel;
    QPushButton* m_resetBtn;
    bool m_winShown = false;
};
