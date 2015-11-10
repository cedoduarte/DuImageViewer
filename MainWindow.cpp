#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QFileDialog>

#define ERROR_MSG "<center><b>No hay imagen</b></center>"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->label->setText(ERROR_MSG);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionAbrir_triggered()
{
    auto filename = QFileDialog::getOpenFileName(this,
        "Abrir", QDir::rootPath(), "Any file (*.*)");
    if (filename.isEmpty()) {
        return;
    }
    QPixmap pixmap;
    if (!loadImage(filename, &pixmap)) {
        return;
    }
    ui->listWidget->addItem(new QListWidgetItem(QIcon(pixmap), filename));
}

void MainWindow::on_actionQuitar_triggered()
{
    close();
}

void MainWindow::on_listWidget_clicked(const QModelIndex &index)
{
    const auto filename = index.data().toString();
    loadImage(filename);
}

bool MainWindow::loadImage(const QString &filename, QPixmap *pixmap)
{
    QPixmap pixmapImage;
    if (!pixmapImage.load(filename)) {
        ui->label->setText(ERROR_MSG);
        return false;
    }
    ui->label->setPixmap(pixmapImage);
    if (pixmap) {
        *pixmap = pixmapImage;
    }
    return true;
}

