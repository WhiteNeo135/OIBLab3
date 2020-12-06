#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "ctime"
#include"cmath"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    srand(time(nullptr));
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

int i=0;


void MainWindow::on_pushButton_clicked()
{
    ui->CreatedPassword_label->setText("");
    i++;
    std::string randomChars="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";
    int durability;
    int speed;
    int time;
    int powerAlph=62;
    double probability;

    probability=ui->chanceLine->text().toInt();
    speed= ui->speedLine->text().toInt();
    time=ui->termLine->text().toInt();

    durability=(speed*time)*1000000;

    ui->LowerCasePassword_text->setText(QString::number(durability));
    ui->Alphabet->setText(QString::number(powerAlph));
    ui->LengthPassword_label->setText(QString::number(5));

    for (int i=0; i<5; ++i)
        ui->CreatedPassword_label->setText(ui->CreatedPassword_label->text() +randomChars[rand()%62]);
}
