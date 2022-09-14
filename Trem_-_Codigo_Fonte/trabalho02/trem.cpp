#include "trem.h"
#include "mainwindow.h"
#include <QtCore>
#include <QMutex>
#include <QSemaphore>

static QMutex mutex[7];
//static QSemaphore *sem = new QSemaphore(3);

//Construtor
Trem::Trem(int ID, int x, int y){
    this->ID = ID;
    this->x = x;
    this->y = y;
    velocidade=0;
}

//Função a ser executada após executar trem->START
void Trem::run(){
    while(true){
        switch(ID){
        case 1:
            /*              Trem 1

                    30 *-------------------------*
                       :                         :
                       :                         :
                       :                         :\ 1
                       :                         :/
                       :                         :
                       :                3 /\     :
                   150 *-------------------------*
                      60                        330
            */
            if (y == 30 && x <330)
                x+=10;
            else if (x == 330 && y < 150) //REGIAO CRITICA 1
                y+=10;
            else if (x > 60 && y == 150) //REGIAO CRITICA 3
                x-=10;
            else
                y-=10;
            emit updateGUI(ID, x,y);    //Emite um sinal
            break;
        case 2:
            /*              Trem 2

                    30 *-------------------------*
                       :                         :
                       :                         :
                    1 /:                         :\ 2
                      \:                         :/
                       :                         :
                       :    /\ 4         5 /\    :
                   150 *-------------------------*
                      330                       600
            */
            if (y == 30 && x <600)
                x+=10;
            else if (x == 600 && y < 150) //REGIAO CRITICA 2
                y+=10;
            else if (x > 330 && y == 150)
                //if(x<460) //REGIAO CRITICA 4
                //else //REGIAO CRITICA 5
                x-=10;
            else //REGIAO CRITICA 1
                y-=10;
            emit updateGUI(ID, x,y);    //Emite um sinal
            break;
        case 3:
            /*              Trem 3

                    30 *-------------------------*
                       :                         :
                       :                         :
                    2 /:                         :
                      \:                         :
                       :                         :
                       :   /\ 5                  :
                   150 *-------------------------*
                      600                       870
            */
            if (y == 30 && x <870)
                x+=10;
            else if (x == 870 && y < 150)
                y+=10;
            else if (x > 600 && y == 150)
                //if(x<730)//REGIAO CRITICA 5
                x-=10;
            else //REGIAO CRITICA 2
                y-=10;
            emit updateGUI(ID, x,y);    //Emite um sinal
            break;
        case 4:
            /*              Trem 4

                   150 *-------------------------*
                       :    \/ 3        4 \/     :
                       :                         :
                       :                         :\ 7
                       :                         :/
                       :                         :
                       :                         :
                   270 *-------------------------*
                      190                       460
            */
            if (y == 150 && x <460)
                //if(x<330) //REGIAO CRITICA 3
                //else //REGIAO CRITICA 4
                x+=10;
            else if (x == 460 && y < 270)//REGIAO CRITICA 7
                y+=10;
            else if (x > 190 && y == 270)
                x-=10;
            else
                y-=10;
            emit updateGUI(ID, x,y);    //Emite um sinal
            break;
        case 5:
            /*              Trem 5

                   150 *-------------------------*
                       :     \/ 5      6 \/      :
                       :                         :
                    7 /:                         :
                      \:                         :
                       :                         :
                       :                         :
                   270 *-------------------------*
                      460                       730
            */
            if (y == 150 && x <730)
                //if(x<600)//REGIAO CRITICA 5
                //else //REGIAO CRITICA 6
                x+=10;
            else if (x == 730 && y < 270)
                y+=10;
            else if (x > 460 && y == 270)
                x-=10;
            else //REGIAO CRITICA 7
                y-=10;
            emit updateGUI(ID, x,y);    //Emite um sinal
            break;
        default:
            break;
        }
        msleep(velocidade);
    }
}

/*REGIAO CRITICA: ( x , y )
REGIAO CRITICA 1: (330,80)
REGIAO CRITICA 2: (600,80)
REGIAO CRITICA 3: (260,150)
REGIAO CRITICA 4: (390,150)
REGIAO CRITICA 5: (550,150)
REGIAO CRITICA 6: (670,150)
REGIAO CRITICA 7: (460,200)
*/


