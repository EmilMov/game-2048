#include "mainwindow.h"
#include "boardwidget.h"
#include "game2048.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QKeyEvent>
#include <QMessageBox>

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent),
    m_game(new Game2048())
{
    auto* central = new QWidget(this);
    auto* root = new QVBoxLayout(central);
    auto* top = new QHBoxLayout();
    QLabel* title = new QLabel("2048");
    title->setStyleSheet("font-size:32px; font-weight:900; color:#776e65;");

    m_scoreLabel = new QLabel("Score: 0");
    m_scoreLabel->setStyleSheet(
        "font-size:18px; font-weight:700; padding:6px 12px; "
        "background:#eee4da; border-radius:8px; color:#776e65;"
        );

    m_resetBtn = new QPushButton("New Game");
    m_resetBtn->setStyleSheet(
        "font-size:16px; font-weight:700; padding:6px 12px; "
        "background:#8f7a66; color:white; border-radius:8px;"
        );

    top->addWidget(title);
    top->addStretch();
    top->addWidget(m_scoreLabel);
    top->addWidget(m_resetBtn);
    m_board = new BoardWidget(m_game);

    root->addLayout(top);
    root->addWidget(m_board, 1);

    setCentralWidget(central);
    setWindowTitle("2048 Qt");
    resize(520, 600);

    connect(m_resetBtn, &QPushButton::clicked, this, [this]{
        m_game->reset();
        m_winShown = false;
        refreshUI();
    });

    refreshUI();
}

MainWindow::~MainWindow() {
    delete m_game;
}

void MainWindow::refreshUI() {
    m_scoreLabel->setText("Score: " + QString::number(m_game->score()));
    m_board->update();
    showWinDialogIfNeeded();

    if (m_game->isGameOver()) {
        QMessageBox::information(this, "Game Over", "No more moves!");
    }
}

void MainWindow::showWinDialogIfNeeded() {
    if (!m_winShown && m_game->isWin()) {
        m_winShown = true;
        auto res = QMessageBox::question(
            this, "You win!",
            "🎉 Congratulations! Continue playing?",
            QMessageBox::Yes | QMessageBox::No
            );
        if (res == QMessageBox::No) close();
    }
}

void MainWindow::keyPressEvent(QKeyEvent* e) {
    bool moved = false;
    switch (e->key()) {
    case Qt::Key_Left:
    case Qt::Key_A: moved = m_game->moveLeft(); break;
    case Qt::Key_Right:
    case Qt::Key_D: moved = m_game->moveRight(); break;
    case Qt::Key_Up:
    case Qt::Key_W: moved = m_game->moveUp(); break;
    case Qt::Key_Down:
    case Qt::Key_S: moved = m_game->moveDown(); break;
    default:
        QMainWindow::keyPressEvent(e);
        return;
    }

    if (moved) refreshUI();
}
