#include "secondwindow.h"
#include "ui_secondwindow.h"
#include <QMessageBox>

bool RussianRullet::realshot()
{
    if (nowBullet == realBullet)
    {
        return true;
    }
    else
    {
        nowBullet = (nowBullet + 1) % 6;     //nowbullet은 1씩 커짐
        return false;
    }
}

void RussianRullet::spin()      //새로운 라운드 시작을 위한 재장전
{
    realBullet = rand() % 6;
    nowBullet = 0;
}

secondwindow::secondwindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::secondwindow)
    , playerTurn(0)                 //첫턴을 정하기 위한 변수
    , round(1)                      //라운드 카운트
    , playerHP(4)
    , opponentHP(4)
    , opponentTimer(new QTimer(this))   //실제 플레이할 때 딜레이를 줘서 상대방이 사람이 플레이하는 것처럼 느끼도록
{
    ui->setupUi(this);

    srand(static_cast<unsigned int>(time(NULL)));
    RR.spin();                          //게임 시작!!!

    ui->my_hp_lcd->display(playerHP);
    ui->enemy_hp_lcd->display(opponentHP);

    playerTurn = rand() % 2;            //첫턴 정하기
    QString fixturnMessage;             //출력
    if(playerTurn == 0)
        fixturnMessage = "당신이 먼저 시작합니다.";
    else
        fixturnMessage = "상대방이 먼저 시작합니다.";
    displayText(fixturnMessage);

    connect(opponentTimer, &QTimer::timeout, this, &secondwindow::opponentTurn);

    if(playerTurn == 1)
    {
        startOpponentTurn();
    }
}

secondwindow::~secondwindow()
{
    delete ui;
}

int dropmode;
void secondwindow::on_shoot_btn_clicked()           //shoot버튼 및 상호작용키
{
    dropmode = 1;

    if(playerTurn != 0)
    {
        QMessageBox::information(this, "정보", "지금은 당신의 턴이 아닙니다.");
        return;
    }
    bool save_result = RR.realshot();       //저장을 해주는 과정으로 함수를 한번 사용 -> realshot 함수를 써야만 nowbullet이 1더해짐
    if(save_result)
    {
        shakeGunImg();
        playerHP--;
        displayText("당신이 실탄을 쏘았습니다! 당신의 HP가 1 감소했습니다.");
        ui->my_hp_lcd->display(playerHP);

        if(playerHP > 0)
            roundOver();

        checkGameOver();
    }
    else
    {
        displayText("당신이 실탄을 맞지 않았습니다.");
    }
}

void secondwindow::opponentTurn()
{
    dropmode = 2;
    opponentTimer->stop();

    displayText("상대방이 방아쇠를 당깁니다...");

    QTimer::singleShot(1000, [this]()
    {

        bool save_result = RR.realshot();
        if(save_result)
        {
            shakeGunImg();
            opponentHP--;
            displayText("상대방이 실탄을 쏘았습니다! 상대방의 HP가 1 감소했습니다.");
            ui->enemy_hp_lcd->display(opponentHP);
            if(opponentHP > 0)
                roundOver();

            checkGameOver();
        }
        else
        {
            displayText("상대방이 실탄을 맞지 않았습니다.");
            dropItem();
        }


    });
}

void secondwindow::nextTurn()
{
    if(playerHP <= 0 || opponentHP <= 0)
        return;

    QTimer::singleShot(1500, [this]() {  // 1.5초 딜레이 후에 턴 교체 메시지 출력
        playerTurn = (playerTurn + 1) % 2;  // 턴 교체
        QString turnMessage;
        if (playerTurn == 0)
            turnMessage = "당신의 턴입니다.";
        else
            turnMessage = "상대방의 턴입니다.";
        displayText(turnMessage);

        if (playerTurn == 1)
        {
            startOpponentTurn();
        }
    });
}

void secondwindow::displayText(const QString &text)
{
    ui->text_label->setText(text);
}

void secondwindow::roundOver()
{
    round++;

    QTimer::singleShot(2000, [this]()
    {  // 2초 딜레이 후에 다음 동작 실행
        RR.spin();
        nextTurn();
    });
}

void secondwindow::checkGameOver()
{
    if(playerHP <= 0)
    {
        QMessageBox::information(this, "게임 종료", "당신이 패배했습니다!");
        this->close();
    }
    else if(opponentHP <= 0)
    {
        QMessageBox::information(this, "게임 종료", "당신이 승리했습니다!");
        this->close();
    }
}

void secondwindow::startOpponentTurn()      //지연을 위한 함수
{
    displayText("상대방의 턴입니다.");
    // 상대방의 행동을 1초 지연 후 실행

    QTimer::singleShot(1000, [this]()
    {
        opponentUseItems();
    });

    opponentTimer->start(2000);
}

void secondwindow::startPlayerTurn()
{
    displayText("당신의 턴입니다.");
}

void secondwindow::on_turn_btn_clicked()
{
    dropItem();
}


void secondwindow::on_cookie_btn_clicked()
{
    if (playeritem[0] > 0) { // 쿠키 수량 체크
        playeritem[0]--; // 쿠키 사용
        playerHP += 1; // 플레이어 HP 1 증가
        displayText("쿠키를 사용했습니다! 당신의 HP가 1 증가했습니다.");
        ui->my_hp_lcd->display(playerHP);
    }
    else
    {
        displayText("쿠키가 없습니다! 사용할 수 없습니다.");
    }
}


void secondwindow::on_reload_btn_clicked()
{
    if (playeritem[1] > 0) { // 재장전 수량 체크
        playeritem[1]--; // 재장전 사용
        RR.nowBullet = (RR.nowBullet + 1) % 6; // nowBullet을 1 증가, 6으로 랩핑
        displayText("재장전 아이템을 사용했습니다! 현재 총알 위치가 변경되었습니다.");
    }
    else
    {
        displayText("재장전 아이템이 없습니다! 사용할 수 없습니다.");
    }
}


void secondwindow::on_critical_btn_clicked()
{
    if (playeritem[2] > 0) { // 치명타 수량 체크
        playeritem[2]--; // 치명타 사용
        if((RR.nowBullet % 6) == RR.realBullet)
        {
            opponentHP -= 2; // 상대 HP 2 감소
            displayText("치명타 아이템을 사용했습니다! 상대의 HP가 2 감소했습니다.");
            ui->enemy_hp_lcd->display(opponentHP); // 디스플레이 업데이트
        }
        else
        {
            displayText("가짜 총알입니다. 데미지를 입히지 못했습니다.");
        }
        checkGameOver(); // HP 변경 후 게임 종료 확인
    }
    else
    {
        displayText("치명타 아이템이 없습니다! 사용할 수 없습니다.");
    }
}


void secondwindow::on_insight_btn_clicked()
{
    if (playeritem[3] > 0) { // 통찰 수량 체크
        playeritem[3]--; // 통찰 사용
        bool nextShotIsReal = (RR.nowBullet == RR.realBullet); // 다음 총알이 실탄인지 확인
        if (nextShotIsReal) {
            displayText("다음 총알은 실탄입니다!");
        }
        else
        {
            displayText("다음 총알은 가짜 총알입니다.");
        }
    }
    else
    {
        displayText("통찰 아이템이 없습니다! 사용할 수 없습니다.");
    }
}

void secondwindow::on_flash_btn_clicked()
{
    if (playeritem[4] > 0)
    {
        playeritem[4]--;
        int target = rand() % 2;

        if (target == 0)
        {
            bool save_result = RR.realshot(); // 사용자가 실탄을 쏘는 메소드 호출
            if (save_result)
            {
                opponentHP--;
                displayText("플래시 아이템을 사용했습니다! 당신이 상대방에게 실탄을 발사했습니다! 상대방의 HP가 1 감소했습니다.");
                ui->enemy_hp_lcd->display(opponentHP);
            }
            else
            {
                displayText("플래시 아이템을 사용했지만 상대방에게 가짜 총알이 발사되었습니다.");
            }
        }
        else
        {
            bool save_result = RR.realshot(); // 상대방이 실탄을 쏘는 메소드 호출
            if (save_result)
            {
                playerHP--;
                displayText("플래시 아이템을 사용했습니다! 상대방이 당신에게 실탄을 발사했습니다! 당신의 HP가 1 감소했습니다.");
                ui->my_hp_lcd->display(playerHP);
            }
            else
            {
                displayText("플래시 아이템을 사용했지만 당신에게 가짜 총알이 발사되었습니다.");
            }
        }
        checkGameOver(); // 게임 종료 확인
    }
    else
    {
        displayText("플래시 아이템이 없습니다! 사용할 수 없습니다.");
    }
}

void secondwindow::dropItem()
{

    int randomindex = rand() % 5;
    int dropValue = rand() % 100;
    if(dropValue < 100)
    {
        if(dropmode == 1)
        {
            ++playeritem[randomindex];            //ex)item[index] = 갯수 -> index는 아이템 종류
            displayText("아이템 획득!");
        }
        else if(dropmode == 2)
        {
            ++opponentitem[randomindex];;
            displayText("상대방 아이템 획득!");

        }
    }

    else
        displayText("아이템이 드랍되지 않았습니다.");

    QTimer::singleShot(1000, this, &secondwindow::nextTurn);

}


QString secondwindow::getInventoryText()
{
    QString inventoryText = "소지한 아이템:\n";

    inventoryText += QString("쿠키: %1\n").arg(playeritem[0]);
    inventoryText += QString("재장전: %1\n").arg(playeritem[1]);
    inventoryText += QString("치명타: %1\n").arg(playeritem[2]);
    inventoryText += QString("통찰: %1\n").arg(playeritem[3]);
    inventoryText += QString("플래시: %1\n").arg(playeritem[4]);

    return inventoryText;
}



void secondwindow::on_inventory_btn_clicked()
{
    QString inventoryText = getInventoryText();
    displayText(inventoryText);
}

void secondwindow::opponentUseItems()
{
    // 1. 쿠키 사용
    if (opponentitem[0] > 0)
    {
        opponentitem[0]--;
        opponentHP++;
        displayText("상대방이 쿠키를 사용했습니다! 상대방의 HP가 1 증가했습니다.");
        ui->enemy_hp_lcd->display(opponentHP);
    }

    if (opponentitem[3] > 0)
    {
        opponentitem[3]--;
        bool isReal = RR.nowBullet == RR.realBullet;
        haveinsight= isReal;

        if (isReal)
        {
            displayText("상대방이 통찰을 사용했습니다! 다음 총알은 실탄입니다.");

            if (opponentitem[1] > 0)
            {
                opponentitem[1]--;
                RR.nowBullet = (RR.nowBullet + 1) % 6;
                displayText("상대방이 재장전 아이템을 사용했습니다! 총알 위치가 변경되었습니다.");
            }
            else if (opponentitem[2] > 0)
            {
                opponentitem[2]--;
                if (RR.realshot())
                {
                    playerHP -= 2;
                    displayText("상대방이 치명타 아이템을 사용했습니다! 당신의 HP가 2 감소했습니다.");
                    ui->my_hp_lcd->display(playerHP);
                    checkGameOver();
                }
                else
                {
                    displayText("상대방이 치명타 아이템을 사용했지만 가짜 총알이 발사되었습니다.");
                }
            }
        }
        else
        {
            displayText("상대방이 통찰을 사용했습니다! 다음 총알은 가짜 총알입니다.");
        }
    }

    if (opponentHP == 1 && opponentitem[4] > 0)
    {
        opponentitem[4]--;
        bool target = rand() % 2; // 50% 확률로 플레이어를 공격

        if (target == 0)
        {
            bool shotResult = RR.realshot();
            if (shotResult)
            {
                playerHP--;
                displayText("상대방이 플래시 아이템을 사용했습니다! 당신에게 실탄이 발사되었습니다! 당신의 HP가 1 감소했습니다.");
                ui->my_hp_lcd->display(playerHP);
            }
            else
            {
                displayText("상대방이 플래시 아이템을 사용했지만 당신에게 가짜 총알이 발사되었습니다.");
            }
        }
        else
        {
            bool shotResult = RR.realshot();
            if (shotResult)
            {
                opponentHP--;
                displayText("상대방이 플래시 아이템을 사용했습니다! 상대방에게 실탄이 발사되었습니다! 상대방의 HP가 1 감소했습니다.");
                ui->enemy_hp_lcd->display(opponentHP);
            }
            else
            {
                displayText("상대방이 플래시 아이템을 사용했지만 상대방에게 가짜 총알이 발사되었습니다.");
            }
        }
        checkGameOver();
    }
}

void secondwindow::shakeGunImg()
{
    QPropertyAnimation *shakeAnimation = new QPropertyAnimation(ui->gunlabel, "pos");
    shakeAnimation->setDuration(500);
    shakeAnimation->setStartValue(ui->gunlabel->pos());
    shakeAnimation->setKeyValueAt(0.25, ui->gunlabel->pos() + QPoint(10, 0));
    shakeAnimation->setKeyValueAt(0.75, ui->gunlabel->pos() + QPoint(-10, 0));
    shakeAnimation->setEndValue(ui->gunlabel->pos());
    shakeAnimation->start(QAbstractAnimation::DeleteWhenStopped);
}
