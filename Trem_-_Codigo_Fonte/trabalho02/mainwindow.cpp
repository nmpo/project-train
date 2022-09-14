#include "mainwindow.h"
#include "trem.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Cria o trem com seu (ID, posição X, posição Y)
    trem1 = new Trem(1,60,30);
    trem2 = new Trem(2,330,30);
    trem3 = new Trem(3,600,30);
    trem4 = new Trem(4,190,150);
    trem5 = new Trem(5,460,150);

    /*
     * Conecta o sinal UPDATEGUI à função UPDATEINTERFACE.
     * Ou seja, sempre que o sinal UPDATEGUI foi chamado, será executada a função UPDATEINTERFACE.
     * Os 3 parâmetros INT do sinal serão utilizados na função.
     * Trem1 e Trem2 são os objetos que podem chamar o sinal. Se um outro objeto chamar o
     * sinal UPDATEGUI, não haverá execução da função UPDATEINTERFACE
     */
    connect(trem1,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));
    connect(trem2,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));
    connect(trem3,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));
    connect(trem4,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));
    connect(trem5,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));
}

//Função que será executada quando o sinal UPDATEGUI for emitido
void MainWindow::updateInterface(int id, int x, int y){
    switch(id){
    case 1: //Atualiza a posição do objeto da tela (quadrado) que representa o trem1
        ui->label_trem1->setGeometry(x,y,21,17);
        break;
    case 2: //Atualiza a posição do objeto da tela (quadrado) que representa o trem2
        ui->label_trem2->setGeometry(x,y,21,17);
        break;
    case 3: //Atualiza a posição do objeto da tela (quadrado) que representa o trem3
        ui->label_trem3->setGeometry(x,y,21,17);
        break;
    case 4: //Atualiza a posição do objeto da tela (quadrado) que representa o trem4
        ui->label_trem4->setGeometry(x,y,21,17);
        break;
    case 5: //Atualiza a posição do objeto da tela (quadrado) que representa o trem5
        ui->label_trem5->setGeometry(x,y,21,17);
        break;
    default:
        break;
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_vel_trem1_sliderReleased()
{
    trem1->velocidade = 200 - ui->vel_trem1->value();
    trem1->start();
}
void MainWindow::on_vel_trem2_sliderReleased()
{
    trem2->velocidade = 200 - ui->vel_trem2->value();
    trem2->start();
}
void MainWindow::on_vel_trem3_sliderReleased()
{
    trem3->velocidade = 200 - ui->vel_trem3->value();
    trem3->start();
}
void MainWindow::on_vel_trem4_sliderReleased()
{
    trem4->velocidade = 200 - ui->vel_trem4->value();
    trem4->start();
}
void MainWindow::on_vel_trem5_sliderReleased()
{
    trem5->velocidade = 200 - ui->vel_trem5->value();
    trem5->start();
}


void MainWindow::on_MainWindow_destroyed()
{

}
