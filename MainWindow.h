#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPixmap>

namespace Ui
{
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void on_actionAbrir_triggered();

    void on_actionQuitar_triggered();

    void on_listWidget_clicked(const QModelIndex &index);

private:
    bool loadImage(const QString &filename, QPixmap *pixmap = nullptr);

    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
