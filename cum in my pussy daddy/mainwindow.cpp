#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

                                                                                                QString haslo = ""; // HASLO JEST GLOBALNE JAKBY NIE BYLO WIDAC KURWA

void MainWindow::on_pushButton_clicked()
{
    srand(time(0));
    int liczba_zn = ui->znaki->toPlainText().toInt();

    QString alf = "abcdefghijklmnoprstuwxyz";
    QString Big_alf = "ABCDEFGHIJKLMNOPRSTUWXYZ";
    QString spec = "!@#$%^&*()_+-=";
    QString cyfr = "0123456789";

    haslo = "";

    int random_i_duze;
    int random_spec;
    int random_cyfra;


    for(int i = 0; i < liczba_zn;i++) {
        int random = qrand() % alf.size();
            haslo += alf[random];


    }

    if(ui->male_wielkie->isChecked()) {
        random_i_duze = qrand() % Big_alf.size();
        haslo[0] = Big_alf[random_i_duze];
    }
    if(ui->z_specj->isChecked()) {
        random_spec = qrand() % spec.size();
        haslo[1] = spec[random_spec];
    }
    if(ui->cyfry->isChecked()) {
        random_cyfra = qrand() % cyfr.size();
        haslo[2] = cyfr[random_cyfra];
    }


    QMessageBox msgBox;
    msgBox.setText(haslo);
    msgBox.exec();

}


void MainWindow::on_pushButton_2_clicked()
{
    QString imie = ui->imie->toPlainText();
    QString nazwisko = ui->nazwisko->toPlainText();
    int zawod = /* dla rodziny */ ui->stanowisko->currentIndex();
    QString stanowisko;
    switch(zawod) {
    case 0:
        stanowisko = "Kierownik";
        break;
    case 1:
        stanowisko = "Starszy programista";
        break;
    case 2:
        stanowisko = "Młodszy programista";
        break;
    case 3:
        stanowisko = "Tester";
        break;
    default:
        stanowisko = "You stupid";
    }

    QMessageBox msgBox;
    msgBox.setText("Dane pracownika: " + imie + " " + nazwisko + " " + stanowisko + " Haslo: " + haslo);
    msgBox.exec();

}

