/********************************************************************************
** Form generated from reading UI file 'yama.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_YAMA_H
#define UI_YAMA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_YAMA
{
public:
    QWidget *centralwidget;
    QCheckBox *weatherCheckBox;
    QCheckBox *currencyCheckBox;
    QCheckBox *stocksCheckBox;
    QLabel *temperatureLabel;
    QLabel *windLabel;
    QLabel *humidityLabel;
    QLabel *atmosphericLabel;
    QLabel *pressureLabel;
    QTextBrowser *temperatureTextBrowser;
    QTextBrowser *atmoPressTextBrowser;
    QTextBrowser *windTextBrowser;
    QTextBrowser *humidityTextBrowser;
    QTextBrowser *buyDollarTextBrowser;
    QLabel *dollarLabel;
    QTextBrowser *buyEuroTextBrowser;
    QLabel *EuroLabel;
    QLabel *amazonLabel;
    QLabel *airbnbLabel;
    QLabel *payPalLabel;
    QLabel *priceAmazonLabel;
    QTextBrowser *amazonTextBrowser;
    QTextBrowser *airBnbTextBrowser;
    QLabel *priceAirBnbLabel;
    QTextBrowser *payPalTextBrowser;
    QLabel *pricePayPalLabel;
    QTextBrowser *mainweatherTextBrowser;
    QLabel *mainweatherLabel;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *YAMA)
    {
        if (YAMA->objectName().isEmpty())
            YAMA->setObjectName("YAMA");
        YAMA->resize(605, 471);
        YAMA->setStyleSheet(QString::fromUtf8("background-color: rgb(253, 253, 255);\n"
"\n"
""));
        centralwidget = new QWidget(YAMA);
        centralwidget->setObjectName("centralwidget");
        weatherCheckBox = new QCheckBox(centralwidget);
        weatherCheckBox->setObjectName("weatherCheckBox");
        weatherCheckBox->setGeometry(QRect(20, 10, 181, 20));
        weatherCheckBox->setStyleSheet(QString::fromUtf8("QCheckBox {\n"
"    background-color: rgb(236, 230, 255)\n"
"}\n"
"\n"
"QCheckBox {\n"
"    font-family: Roboto;\n"
"    font-size: 15px;\n"
"        font-weight: bold;\n"
"}"));
        currencyCheckBox = new QCheckBox(centralwidget);
        currencyCheckBox->setObjectName("currencyCheckBox");
        currencyCheckBox->setGeometry(QRect(210, 10, 191, 20));
        currencyCheckBox->setStyleSheet(QString::fromUtf8("QCheckBox {\n"
"    background-color: rgb(236, 230, 255)\n"
"}\n"
"\n"
"QCheckBox {\n"
"    font-family: Roboto;\n"
"    font-size: 15px;\n"
"        font-weight: bold;\n"
"}"));
        stocksCheckBox = new QCheckBox(centralwidget);
        stocksCheckBox->setObjectName("stocksCheckBox");
        stocksCheckBox->setGeometry(QRect(420, 10, 171, 20));
        stocksCheckBox->setStyleSheet(QString::fromUtf8("QCheckBox {\n"
"    background-color: rgb(236, 230, 255)\n"
"}\n"
"\n"
"QCheckBox {\n"
"    font-family: Roboto;\n"
"    font-size: 15px;\n"
"        font-weight: bold;\n"
"}"));
        temperatureLabel = new QLabel(centralwidget);
        temperatureLabel->setObjectName("temperatureLabel");
        temperatureLabel->setGeometry(QRect(20, 130, 101, 16));
        temperatureLabel->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    background-color: rgb(247, 246, 255)\n"
"}\n"
"\n"
"QLabel {\n"
"    font-family: Roboto;\n"
"    font-size: 13px;\n"
"        font-weight: bold;\n"
"}"));
        windLabel = new QLabel(centralwidget);
        windLabel->setObjectName("windLabel");
        windLabel->setGeometry(QRect(20, 290, 101, 16));
        windLabel->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    background-color: rgb(247, 246, 255)\n"
"}\n"
"\n"
"QLabel {\n"
"    font-family: Roboto;\n"
"    font-size: 13px;\n"
"        font-weight: bold;\n"
"}"));
        humidityLabel = new QLabel(centralwidget);
        humidityLabel->setObjectName("humidityLabel");
        humidityLabel->setGeometry(QRect(20, 360, 101, 16));
        humidityLabel->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    background-color: rgb(247, 246, 255)\n"
"}\n"
"\n"
"QLabel {\n"
"    font-family: Roboto;\n"
"    font-size: 13px;\n"
"        font-weight: bold;\n"
"}"));
        atmosphericLabel = new QLabel(centralwidget);
        atmosphericLabel->setObjectName("atmosphericLabel");
        atmosphericLabel->setGeometry(QRect(20, 200, 101, 16));
        atmosphericLabel->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    background-color: rgb(247, 246, 255)\n"
"}\n"
"\n"
"QLabel {\n"
"    font-family: Roboto;\n"
"    font-size: 13px;\n"
"        font-weight: bold;\n"
"}"));
        pressureLabel = new QLabel(centralwidget);
        pressureLabel->setObjectName("pressureLabel");
        pressureLabel->setGeometry(QRect(20, 220, 101, 16));
        pressureLabel->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    background-color: rgb(247, 246, 255)\n"
"}\n"
"\n"
"QLabel {\n"
"    font-family: Roboto;\n"
"    font-size: 13px;\n"
"        font-weight: bold;\n"
"}"));
        temperatureTextBrowser = new QTextBrowser(centralwidget);
        temperatureTextBrowser->setObjectName("temperatureTextBrowser");
        temperatureTextBrowser->setGeometry(QRect(20, 150, 101, 31));
        temperatureTextBrowser->setStyleSheet(QString::fromUtf8("QTextBrowser {\n"
"        border-radius: 10px;\n"
"        border: 1.5px solid rgb(236, 230, 255);\n"
"}\n"
"\n"
"QTextBrowser {\n"
"    font-family: Roboto;\n"
"    font-size: 15px;\n"
"        font-weight: bold;\n"
"}\n"
""));
        atmoPressTextBrowser = new QTextBrowser(centralwidget);
        atmoPressTextBrowser->setObjectName("atmoPressTextBrowser");
        atmoPressTextBrowser->setGeometry(QRect(20, 240, 101, 31));
        atmoPressTextBrowser->setStyleSheet(QString::fromUtf8("QTextBrowser {\n"
"        border-radius: 10px;\n"
"        border: 1.5px solid rgb(236, 230, 255);\n"
"}\n"
"\n"
"QTextBrowser {\n"
"    font-family: Roboto;\n"
"    font-size: 15px;\n"
"        font-weight: bold;\n"
"}\n"
""));
        windTextBrowser = new QTextBrowser(centralwidget);
        windTextBrowser->setObjectName("windTextBrowser");
        windTextBrowser->setGeometry(QRect(20, 310, 101, 31));
        windTextBrowser->setStyleSheet(QString::fromUtf8("QTextBrowser {\n"
"        border-radius: 10px;\n"
"        border: 1.5px solid rgb(236, 230, 255);\n"
"}\n"
"\n"
"QTextBrowser {\n"
"    font-family: Roboto;\n"
"    font-size: 15px;\n"
"        font-weight: bold;\n"
"}\n"
""));
        humidityTextBrowser = new QTextBrowser(centralwidget);
        humidityTextBrowser->setObjectName("humidityTextBrowser");
        humidityTextBrowser->setGeometry(QRect(20, 380, 101, 31));
        humidityTextBrowser->setStyleSheet(QString::fromUtf8("QTextBrowser {\n"
"        border-radius: 10px;\n"
"        border: 1.5px solid rgb(236, 230, 255);\n"
"}\n"
"\n"
"QTextBrowser {\n"
"    font-family: Roboto;\n"
"    font-size: 15px;\n"
"        font-weight: bold;\n"
"}\n"
""));
        buyDollarTextBrowser = new QTextBrowser(centralwidget);
        buyDollarTextBrowser->setObjectName("buyDollarTextBrowser");
        buyDollarTextBrowser->setGeometry(QRect(220, 80, 121, 31));
        buyDollarTextBrowser->setStyleSheet(QString::fromUtf8("QTextBrowser {\n"
"        border-radius: 10px;\n"
"        border: 1.5px solid rgb(236, 230, 255);\n"
"}\n"
"\n"
"QTextBrowser {\n"
"    font-family: Roboto;\n"
"    font-size: 15px;\n"
"        font-weight: bold;\n"
"}\n"
""));
        dollarLabel = new QLabel(centralwidget);
        dollarLabel->setObjectName("dollarLabel");
        dollarLabel->setGeometry(QRect(220, 60, 121, 16));
        dollarLabel->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    background-color: rgb(247, 246, 255)\n"
"}\n"
"\n"
"QLabel {\n"
"    font-family: Roboto;\n"
"    font-size: 13px;\n"
"        font-weight: bold;\n"
"}"));
        buyEuroTextBrowser = new QTextBrowser(centralwidget);
        buyEuroTextBrowser->setObjectName("buyEuroTextBrowser");
        buyEuroTextBrowser->setGeometry(QRect(220, 150, 121, 31));
        buyEuroTextBrowser->setStyleSheet(QString::fromUtf8("QTextBrowser {\n"
"        border-radius: 10px;\n"
"        border: 1.5px solid rgb(236, 230, 255);\n"
"}\n"
"\n"
"QTextBrowser {\n"
"    font-family: Roboto;\n"
"    font-size: 15px;\n"
"        font-weight: bold;\n"
"}\n"
""));
        EuroLabel = new QLabel(centralwidget);
        EuroLabel->setObjectName("EuroLabel");
        EuroLabel->setGeometry(QRect(220, 130, 121, 16));
        EuroLabel->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    background-color: rgb(247, 246, 255)\n"
"}\n"
"\n"
"QLabel {\n"
"    font-family: Roboto;\n"
"    font-size: 13px;\n"
"        font-weight: bold;\n"
"}"));
        amazonLabel = new QLabel(centralwidget);
        amazonLabel->setObjectName("amazonLabel");
        amazonLabel->setGeometry(QRect(470, 60, 121, 16));
        amazonLabel->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    background-color: rgb(247, 246, 255)\n"
"}\n"
"\n"
"QLabel {\n"
"    font-family: Roboto;\n"
"    font-size: 13px;\n"
"        font-weight: bold;\n"
"}"));
        airbnbLabel = new QLabel(centralwidget);
        airbnbLabel->setObjectName("airbnbLabel");
        airbnbLabel->setGeometry(QRect(470, 140, 121, 16));
        airbnbLabel->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    background-color: rgb(247, 246, 255)\n"
"}\n"
"\n"
"QLabel {\n"
"    font-family: Roboto;\n"
"    font-size: 13px;\n"
"        font-weight: bold;\n"
"}"));
        payPalLabel = new QLabel(centralwidget);
        payPalLabel->setObjectName("payPalLabel");
        payPalLabel->setGeometry(QRect(470, 220, 121, 16));
        payPalLabel->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    background-color: rgb(247, 246, 255)\n"
"}\n"
"\n"
"QLabel {\n"
"    font-family: Roboto;\n"
"    font-size: 13px;\n"
"        font-weight: bold;\n"
"}"));
        priceAmazonLabel = new QLabel(centralwidget);
        priceAmazonLabel->setObjectName("priceAmazonLabel");
        priceAmazonLabel->setGeometry(QRect(420, 90, 31, 16));
        priceAmazonLabel->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    background-color: rgb(247, 246, 255)\n"
"}\n"
"\n"
"QLabel {\n"
"    font-family: Roboto;\n"
"    font-size: 13px;\n"
"        font-weight: bold;\n"
"}"));
        amazonTextBrowser = new QTextBrowser(centralwidget);
        amazonTextBrowser->setObjectName("amazonTextBrowser");
        amazonTextBrowser->setGeometry(QRect(460, 80, 131, 31));
        amazonTextBrowser->setStyleSheet(QString::fromUtf8("QTextBrowser {\n"
"        border-radius: 10px;\n"
"        border: 1.5px solid rgb(236, 230, 255);\n"
"}\n"
"\n"
"QTextBrowser {\n"
"    font-family: Roboto;\n"
"    font-size: 15px;\n"
"        font-weight: bold;\n"
"}\n"
""));
        airBnbTextBrowser = new QTextBrowser(centralwidget);
        airBnbTextBrowser->setObjectName("airBnbTextBrowser");
        airBnbTextBrowser->setGeometry(QRect(460, 160, 131, 31));
        airBnbTextBrowser->setStyleSheet(QString::fromUtf8("QTextBrowser {\n"
"        border-radius: 10px;\n"
"        border: 1.5px solid rgb(236, 230, 255);\n"
"}\n"
"\n"
"QTextBrowser {\n"
"    font-family: Roboto;\n"
"    font-size: 15px;\n"
"        font-weight: bold;\n"
"}\n"
""));
        priceAirBnbLabel = new QLabel(centralwidget);
        priceAirBnbLabel->setObjectName("priceAirBnbLabel");
        priceAirBnbLabel->setGeometry(QRect(420, 170, 31, 16));
        priceAirBnbLabel->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    background-color: rgb(247, 246, 255)\n"
"}\n"
"\n"
"QLabel {\n"
"    font-family: Roboto;\n"
"    font-size: 13px;\n"
"        font-weight: bold;\n"
"}"));
        payPalTextBrowser = new QTextBrowser(centralwidget);
        payPalTextBrowser->setObjectName("payPalTextBrowser");
        payPalTextBrowser->setGeometry(QRect(460, 240, 131, 31));
        payPalTextBrowser->setStyleSheet(QString::fromUtf8("QTextBrowser {\n"
"        border-radius: 10px;\n"
"        border: 1.5px solid rgb(236, 230, 255);\n"
"}\n"
"\n"
"QTextBrowser {\n"
"    font-family: Roboto;\n"
"    font-size: 15px;\n"
"        font-weight: bold;\n"
"}\n"
""));
        pricePayPalLabel = new QLabel(centralwidget);
        pricePayPalLabel->setObjectName("pricePayPalLabel");
        pricePayPalLabel->setGeometry(QRect(420, 250, 31, 16));
        pricePayPalLabel->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    background-color: rgb(247, 246, 255)\n"
"}\n"
"\n"
"QLabel {\n"
"    font-family: Roboto;\n"
"    font-size: 13px;\n"
"        font-weight: bold;\n"
"}"));
        mainweatherTextBrowser = new QTextBrowser(centralwidget);
        mainweatherTextBrowser->setObjectName("mainweatherTextBrowser");
        mainweatherTextBrowser->setGeometry(QRect(20, 80, 101, 31));
        mainweatherTextBrowser->setStyleSheet(QString::fromUtf8("QTextBrowser {\n"
"        border-radius: 10px;\n"
"        border: 1.5px solid rgb(236, 230, 255);\n"
"}\n"
"\n"
"QTextBrowser {\n"
"    font-family: Roboto;\n"
"    font-size: 15px;\n"
"        font-weight: bold;\n"
"}\n"
""));
        mainweatherLabel = new QLabel(centralwidget);
        mainweatherLabel->setObjectName("mainweatherLabel");
        mainweatherLabel->setGeometry(QRect(20, 60, 101, 20));
        mainweatherLabel->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    background-color: rgb(247, 246, 255)\n"
"}\n"
"\n"
"QLabel {\n"
"    font-family: Roboto;\n"
"    font-size: 13px;\n"
"        font-weight: bold;\n"
"}"));
        YAMA->setCentralWidget(centralwidget);
        menubar = new QMenuBar(YAMA);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 605, 22));
        YAMA->setMenuBar(menubar);
        statusbar = new QStatusBar(YAMA);
        statusbar->setObjectName("statusbar");
        YAMA->setStatusBar(statusbar);

        retranslateUi(YAMA);

        QMetaObject::connectSlotsByName(YAMA);
    } // setupUi

    void retranslateUi(QMainWindow *YAMA)
    {
        YAMA->setWindowTitle(QCoreApplication::translate("YAMA", "YAMA", nullptr));
        weatherCheckBox->setText(QCoreApplication::translate("YAMA", "Weather subscription", nullptr));
        currencyCheckBox->setText(QCoreApplication::translate("YAMA", "Currency subscription", nullptr));
        stocksCheckBox->setText(QCoreApplication::translate("YAMA", "Stocks subscription", nullptr));
        temperatureLabel->setText(QCoreApplication::translate("YAMA", "Temperature:", nullptr));
        windLabel->setText(QCoreApplication::translate("YAMA", "Wind", nullptr));
        humidityLabel->setText(QCoreApplication::translate("YAMA", "Humidity", nullptr));
        atmosphericLabel->setText(QCoreApplication::translate("YAMA", "Atmospheric", nullptr));
        pressureLabel->setText(QCoreApplication::translate("YAMA", "pressure", nullptr));
        dollarLabel->setText(QCoreApplication::translate("YAMA", "Dollar", nullptr));
        EuroLabel->setText(QCoreApplication::translate("YAMA", "Euro", nullptr));
        amazonLabel->setText(QCoreApplication::translate("YAMA", "Amazon", nullptr));
        airbnbLabel->setText(QCoreApplication::translate("YAMA", "Airbnb", nullptr));
        payPalLabel->setText(QCoreApplication::translate("YAMA", "PayPal", nullptr));
        priceAmazonLabel->setText(QCoreApplication::translate("YAMA", "Price", nullptr));
        priceAirBnbLabel->setText(QCoreApplication::translate("YAMA", "Price", nullptr));
        pricePayPalLabel->setText(QCoreApplication::translate("YAMA", "Price", nullptr));
        mainweatherLabel->setText(QCoreApplication::translate("YAMA", "Main weather", nullptr));
    } // retranslateUi

};

namespace Ui {
    class YAMA: public Ui_YAMA {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_YAMA_H
