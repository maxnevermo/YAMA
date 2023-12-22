#include "yama.h"
#include "ui_yama.h"
#include <QTimer>

SOCKET clientSocket;
bool weatherActive;
bool currencyActive;
bool stocksActive;


YAMA::YAMA(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::YAMA)
{
    ui->setupUi(this);

    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        std::cerr << "Failed to initialize Winsock." << std::endl;
    }

    clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket == INVALID_SOCKET) {
        std::cerr << "Failed to create socket." << std::endl;
        WSACleanup();
    }

    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = inet_addr("127.0.0.1");
    serverAddress.sin_port = htons(5555);

    if (::connect(clientSocket, reinterpret_cast<struct sockaddr*>(&serverAddress), sizeof(serverAddress)) == SOCKET_ERROR) {
        std::cerr << "Failed to connect to server. Error: " << WSAGetLastError() << std::endl;
        closesocket(clientSocket);
        WSACleanup();
    } else {

        std::cout << "Connected to server." << std::endl;
    }
    QTimer* timer = new QTimer(this);

    connect(timer, &QTimer::timeout, this, &YAMA::sendWeatherRequest);
    connect(timer, &QTimer::timeout, this, &YAMA::sendCurrencyRequest);
    connect(timer, &QTimer::timeout, this, &YAMA::sendStocksRequest);

    timer->start(1000);
}

void YAMA::delimiterWeather(const char *buffer, bool active)
{
    if (active == true)
    {
        double temperature;
        int pressure;
        int humidity;
        double windSpeed;
        char mainWeather[256];

        int result = std::sscanf(buffer, "Weather in Lviv: Temp: %lfC Pressure: %d hPa Humidity: %d Wind speed: %lf km/h Main weather: \"%[^\"]\"", &temperature, &pressure, &humidity, &windSpeed, mainWeather);

        if (result == 5)
        {
            ui->temperatureTextBrowser->setText(QString::number(temperature) + " C");
            //std::cout<<temperature;
            ui->atmoPressTextBrowser->setText(QString::number(pressure) + " hPa");
            //std::cout << pressure;
            ui->humidityTextBrowser->setText(QString::number(humidity) + " %");
            //std::cout << humidity;
            ui->windTextBrowser->setText(QString::number(windSpeed) + " km/h");
            //std::cout << windSpeed;
            ui->mainweatherTextBrowser->setText(QString::fromUtf8(mainWeather));
            //std::cout << mainWeather;
        }
        else
        {
            qDebug() << "Failed to parse input string\n";
        }
    }
    if (active == false)
    {
        ui->temperatureTextBrowser->clear();
        ui->atmoPressTextBrowser->clear();
        ui->humidityTextBrowser->clear();
        ui->windTextBrowser->clear();
        ui->mainweatherTextBrowser->clear();
    }
}

void YAMA::delimiterCurrency(const char *buffer, bool active)
{
    if (active == true)
    {
        double usdPrice, eurPrice;

        int result = std::sscanf(buffer, "USD price to 1UAH: %lf EUR price to 1UAH: %lf", &usdPrice, &eurPrice);

        if (result == 2)
        {
            ui->buyDollarTextBrowser->setText(QString::number(1/usdPrice));
            //std::cout << usdPrice;
            ui->buyEuroTextBrowser->setText(QString::number(1/eurPrice));
            //std::cout << eurPrice;
        }
        else
        {
            qDebug() << "Failed to parse input string\n";
        }
    }
    if (active == false)
    {
        ui->buyDollarTextBrowser->clear();
        ui->buyEuroTextBrowser->clear();
    }
}

void YAMA::delimiterStocks(const char *buffer, bool active)
{
    if (active == true)
    {
        double abnbPrice, amznPrice, pyplPrice;
        int result = std::sscanf(buffer, "ABNB stock price: %lf $ AMZN stock price: %lf $ PYPL stock price: %lf $", &abnbPrice, &amznPrice, &pyplPrice);
        if (result == 3)
        {
            ui->airBnbTextBrowser->setText(QString::number(abnbPrice) + " $");
            std::cout << abnbPrice;
            ui->amazonTextBrowser->setText(QString::number(amznPrice) + " $");
            std::cout << amznPrice;
            ui->payPalTextBrowser->setText(QString::number(pyplPrice) + " $");
            std::cout << pyplPrice;
        }
        else
        {
            qDebug() << "Failed to parse input string\n";
        }
    }
    if (active == false)
    {
        ui->airBnbTextBrowser->clear();
        ui->amazonTextBrowser->clear();
        ui->payPalTextBrowser->clear();
    }
}

void YAMA::sendWeatherRequest() {
    if (weatherActive) {
        char buffer[256];
        timeval timeout = { 5, 0 };
        setsockopt(clientSocket, SOL_SOCKET, SO_RCVTIMEO, reinterpret_cast<char*>(&timeout), sizeof(timeout));

        int bytesRead = recv(clientSocket, buffer, sizeof(buffer) - 1, 0);

        timeout = { 0, 0 };
        setsockopt(clientSocket, SOL_SOCKET, SO_RCVTIMEO, reinterpret_cast<char*>(&timeout), sizeof(timeout));

        if (bytesRead > 0) {
            buffer[bytesRead] = '\0';
            std::cout << "Server response: " << buffer << std::endl;
            delimiterWeather(buffer, true);
        }
    } else {
        char buffer[256];
        //timeval timeout = { 5, 0 };  // 5-second timeout
        //setsockopt(clientSocket, SOL_SOCKET, SO_RCVTIMEO, reinterpret_cast<char*>(&timeout), sizeof(timeout));

        //int bytesRead = recv(clientSocket, buffer, sizeof(buffer) - 1, 0);
        delimiterWeather(buffer, false);
        //        timeout = { 0, 0 };
        //        setsockopt(clientSocket, SOL_SOCKET, SO_RCVTIMEO, reinterpret_cast<char*>(&timeout), sizeof(timeout));

        //        if (bytesRead > 0) {
        //            buffer[bytesRead] = '\0';
        //            //std::cout << "Server response: " << buffer << std::endl;
        //            //delimiterWeather(buffer, false);
        //        }
    }
}

void YAMA::sendCurrencyRequest() {
    if (currencyActive) {
        char buffer[256];
        timeval timeout = { 5, 0 };
        setsockopt(clientSocket, SOL_SOCKET, SO_RCVTIMEO, reinterpret_cast<char*>(&timeout), sizeof(timeout));

        int bytesRead = recv(clientSocket, buffer, sizeof(buffer) - 1, 0);

        timeout = { 0, 0 };
        setsockopt(clientSocket, SOL_SOCKET, SO_RCVTIMEO, reinterpret_cast<char*>(&timeout), sizeof(timeout));

        if (bytesRead > 0) {
            buffer[bytesRead] = '\0';
            std::cout << "Server response: " << buffer << std::endl;
            delimiterCurrency(buffer, true);
        }
    } else {
        char buffer[256];
        //timeval timeout = { 5, 0 };  // 5-second timeout
        //setsockopt(clientSocket, SOL_SOCKET, SO_RCVTIMEO, reinterpret_cast<char*>(&timeout), sizeof(timeout));

        //        int bytesRead = recv(clientSocket, buffer, sizeof(buffer) - 1, 0);
        delimiterCurrency(buffer, false);
        //        timeout = { 0, 0 };
        //        setsockopt(clientSocket, SOL_SOCKET, SO_RCVTIMEO, reinterpret_cast<char*>(&timeout), sizeof(timeout));

        //        if (bytesRead > 0) {
        //            buffer[bytesRead] = '\0';
        //            std::cout << "Server response: " << buffer << std::endl;
        //            delimiterCurrency(buffer, true);
        //        }
    }
}

void YAMA::sendStocksRequest() {
    if (stocksActive) {

        char buffer[256];
        timeval timeout = { 5, 0 };
        setsockopt(clientSocket, SOL_SOCKET, SO_RCVTIMEO, reinterpret_cast<char*>(&timeout), sizeof(timeout));

        int bytesRead = recv(clientSocket, buffer, sizeof(buffer) - 1, 0);

        timeout = { 0, 0 };
        setsockopt(clientSocket, SOL_SOCKET, SO_RCVTIMEO, reinterpret_cast<char*>(&timeout), sizeof(timeout));

        if (bytesRead > 0) {
            buffer[bytesRead] = '\0';
            std::cout << "Server response: " << buffer << std::endl;
            delimiterStocks(buffer, true);
        }
    } else {
        char buffer[256];
        //        timeval timeout = { 5, 0 };
        //        setsockopt(clientSocket, SOL_SOCKET, SO_RCVTIMEO, reinterpret_cast<char*>(&timeout), sizeof(timeout));

        //        int bytesRead = recv(clientSocket, buffer, sizeof(buffer) - 1, 0);
        delimiterStocks(buffer, false);
        //        timeout = { 0, 0 };
        //        setsockopt(clientSocket, SOL_SOCKET, SO_RCVTIMEO, reinterpret_cast<char*>(&timeout), sizeof(timeout));

        //        if (bytesRead > 0) {
        //            buffer[bytesRead] = '\0';
        //            std::cout << "Server response: " << buffer << std::endl;
        //        }
    }
}

YAMA::~YAMA()
{
    closesocket(clientSocket);
    WSACleanup();
    delete ui;
}

void YAMA::on_weatherCheckBox_stateChanged(int arg1)
{
    if (arg1 == 2) {
        weatherActive = true;
        const char* subscribeCommand = "subscribe weather";
        if (send(clientSocket, subscribeCommand, strlen(subscribeCommand), 0) == SOCKET_ERROR) {
            std::cerr << "Failed to send subscribe command. Error: " << WSAGetLastError() << std::endl;
        }
    }
    if (arg1 == 0) {
        weatherActive = false;
        const char* subscribeCommand = "unsubscribe weather";
        if (send(clientSocket, subscribeCommand, strlen(subscribeCommand), 0) == SOCKET_ERROR) {
            std::cerr << "Failed to send unsubscribe command. Error: " << WSAGetLastError() << std::endl;
        }
    }
}


void YAMA::on_currencyCheckBox_stateChanged(int arg1)
{
    if (arg1 == 2) {
        currencyActive = true;
        const char* subscribeCommand = "subscribe currency";
        if (send(clientSocket, subscribeCommand, strlen(subscribeCommand), 0) == SOCKET_ERROR) {
            std::cerr << "Failed to send subscribe command. Error: " << WSAGetLastError() << std::endl;
        }
    }
    if (arg1 == 0) {
        currencyActive = false;
        const char* subscribeCommand = "unsubscribe currency";
        if (send(clientSocket, subscribeCommand, strlen(subscribeCommand), 0) == SOCKET_ERROR) {
            std::cerr << "Failed to send unsubscribe command. Error: " << WSAGetLastError() << std::endl;
        }
    }
}


void YAMA::on_stocksCheckBox_stateChanged(int arg1)
{
    if (arg1 == 2) {
        stocksActive = true;
        const char* subscribeCommand = "subscribe stocks";
        if (send(clientSocket, subscribeCommand, strlen(subscribeCommand), 0) == SOCKET_ERROR) {
            std::cerr << "Failed to send subscribe command. Error: " << WSAGetLastError() << std::endl;
        }
    }
    if (arg1 == 0) {
        stocksActive = false;
        const char* subscribeCommand = "unsubscribe stocks";
        if (send(clientSocket, subscribeCommand, strlen(subscribeCommand), 0) == SOCKET_ERROR) {
            std::cerr << "Failed to send unsubscribe command. Error: " << WSAGetLastError() << std::endl;
        }
    }
}

