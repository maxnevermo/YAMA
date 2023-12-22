#ifndef YAMA_H
#define YAMA_H

#include <QMainWindow>
#include <iostream>
#include <winsock2.h>

#pragma comment(lib, "ws2_32.lib")

QT_BEGIN_NAMESPACE
namespace Ui {
class YAMA;
}
QT_END_NAMESPACE

class YAMA : public QMainWindow
{
    Q_OBJECT

public:
    YAMA(QWidget *parent = nullptr);
    ~YAMA();

    void delimiterWeather(const char *buffer, bool active);
    void delimiterCurrency(const char *buffer, bool active);
    void delimiterStocks(const char *buffer, bool active);

    void sendWeatherRequest();
    void sendCurrencyRequest();
    void sendStocksRequest();

private slots:
    void on_weatherCheckBox_stateChanged(int arg1);

    void on_currencyCheckBox_stateChanged(int arg1);

    void on_stocksCheckBox_stateChanged(int arg1);

private:
    Ui::YAMA *ui;
};
#endif // YAMA_H
