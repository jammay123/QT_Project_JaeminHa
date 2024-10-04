#ifndef SECONDWINDOW_H
#define SECONDWINDOW_H

#include <QDialog>
#include <QTimer>
#include <cstdlib>
#include <ctime>
#include <QPropertyAnimation>

namespace Ui {
class secondwindow;
}

class RussianRullet
{
private:

    int maxShots;       // 최대 방아쇠 당기기 횟수

public:
    RussianRullet(): nowBullet(0)
    {
        spin();
    }
    int realBullet;     // 실탄이 들어있는 총알 위치 (0-5)
    int nowBullet;      // 현재 총알 위치
    bool realshot();    // 실탄인지 여부를 반환
    bool isDepleted();  // 총알이 소진되었는지 여부
    void spin();        // 총을 돌림

};

class secondwindow : public QDialog
{
    Q_OBJECT

public:
    explicit secondwindow(QWidget *parent = nullptr);
    ~secondwindow();
    int playeritem[6] = {0,};
    int opponentitem[6] = {0,};

private slots:
    void on_shoot_btn_clicked();
    void opponentTurn();

    void on_turn_btn_clicked();

    void on_cookie_btn_clicked();

    void on_reload_btn_clicked();

    void on_critical_btn_clicked();

    void on_insight_btn_clicked();

    void on_flash_btn_clicked();

    void on_inventory_btn_clicked();

private:
    Ui::secondwindow *ui;
    int playerTurn;          // 0: 플레이어, 1: 상대방
    int round;
    int playerHP;            // 플레이어 HP
    int opponentHP;          // 상대방 HP
    RussianRullet RR;
    QTimer *opponentTimer;

    void nextTurn();
    void displayText(const QString &text);
    void roundOver();
    void checkGameOver();
    void startOpponentTurn();
    void startPlayerTurn();
    void dropItem();
    void enemydropItem();
    QString getInventoryText();
    void opponentUseItems();
    bool haveinsight = false;
    void shakeGunImg();
};
#endif // SECONDWINDOW_H
