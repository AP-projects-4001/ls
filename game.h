#ifndef GAME_H
#define GAME_H

#include <QMainWindow>
#include <QMovie>
#include <QTimer>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void on_pushButton_clicked();
    void close_this();
    void update();
    void on_verticalSlider_valueChanged(int value);
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();

private:
    Ui::MainWindow *ui;
     QMovie* movie;
     QTimer *timer2;
     QTimer *timer1;
};
#endif // GAME_H
