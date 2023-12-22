#include <iostream>
#include <vector>
#include <algorithm>
#include <winsock2.h>
#include <Windows.h>
#include <winhttp.h>
#include <string>
#include <iomanip> 
#include <sstream> 

#pragma comment(lib, "ws2_32.lib")
#pragma comment(lib, "winhttp.lib")

std::string findData(std::string responseData, const char* word) {
    std::string str = "\"" + std::string(word) + "\":";
    size_t pricePos = responseData.find(str);
    if (pricePos != std::string::npos) {
        size_t colonPos = responseData.find(":", pricePos);
        if (colonPos != std::string::npos) {
            size_t valueStartPos = responseData.find_first_not_of(" \t\n\r\f\v", colonPos + 1);
            size_t commaPos = responseData.find(",", valueStartPos);
            size_t bracePos = responseData.find("}", valueStartPos);
            size_t valueEndPos = min(commaPos, bracePos);

            std::string wordStr = responseData.substr(valueStartPos, valueEndPos - valueStartPos);
            return wordStr;
        }
    }
    return "";
}

std::string GetStockPrice(const char* symbol) {
    BOOL bResults = FALSE;
    HINTERNET hSession = NULL,
        hConnect = NULL,
        hRequest = NULL;

    // Use WinHttpOpen to obtain a session handle.
    hSession = WinHttpOpen(L"A WinHTTP Example Program/1.0",
        WINHTTP_ACCESS_TYPE_DEFAULT_PROXY,
        WINHTTP_NO_PROXY_NAME,
        WINHTTP_NO_PROXY_BYPASS, 0);

    // Specify an HTTP server.
    if (hSession)
        hConnect = WinHttpConnect(hSession, L"financialmodelingprep.com",
            INTERNET_DEFAULT_HTTPS_PORT, 0);

    std::wstring ws(symbol, symbol + strlen(symbol));
    // Create an HTTP Request handle.
    if (hConnect) {
        std::wstring requestUri = L"/api/v3/profile/" + std::wstring(ws) + L"?apikey=QkVG763pBqZVVLgdDRFzwzCqD0xfpeqW";
        hRequest = WinHttpOpenRequest(hConnect, L"GET",
            requestUri.c_str(),
            NULL, WINHTTP_NO_REFERER,
            WINHTTP_DEFAULT_ACCEPT_TYPES,
            WINHTTP_FLAG_SECURE);
    }

    // Send a Request.
    if (hRequest)
        bResults = WinHttpSendRequest(hRequest,
            WINHTTP_NO_ADDITIONAL_HEADERS,
            0, WINHTTP_NO_REQUEST_DATA, 0,
            0, 0);

    // End the request.
    if (bResults)
        bResults = WinHttpReceiveResponse(hRequest, NULL);

    // Read and display the response content.
    if (bResults) {
        DWORD bytesRead = 0;
        std::string responseData;
        do {
            BYTE buffer[4096];
            bResults = WinHttpReadData(hRequest, buffer, sizeof(buffer), &bytesRead);
            if (bResults && bytesRead > 0) {
                responseData.append(reinterpret_cast<const char*>(buffer), bytesRead);
            }
        } while (bResults && bytesRead > 0);

        std::ostringstream weatherInfo;
        weatherInfo << std::fixed << std::setprecision(2); // Set precision for double values
        std::string errorMessage = findData(responseData, "Error Message");
        if (!errorMessage.empty()) {
            return "Limit reached";
        }
        else {
            std::string wstr = findData(responseData, "price");
            weatherInfo << symbol << " stock price: " << wstr << " $ ";

            if (hRequest) WinHttpCloseHandle(hRequest);
            if (hConnect) WinHttpCloseHandle(hConnect);
            if (hSession) WinHttpCloseHandle(hSession);

            return weatherInfo.str();
        }
    }

    // Report any errors.
    if (!bResults)
        std::wcout << L"Error " << GetLastError() << L" has occurred." << std::endl;

    // Close any open handles.
    if (hRequest) WinHttpCloseHandle(hRequest);
    if (hConnect) WinHttpCloseHandle(hConnect);
    if (hSession) WinHttpCloseHandle(hSession);
}
std::string GetCurrencyPrice(const char* symbol) {
    BOOL bResults = FALSE;
    HINTERNET hSession = NULL,
        hConnect = NULL,
        hRequest = NULL;

    // Use WinHttpOpen to obtain a session handle.
    hSession = WinHttpOpen(L"A WinHTTP Example Program/1.0",
        WINHTTP_ACCESS_TYPE_DEFAULT_PROXY,
        WINHTTP_NO_PROXY_NAME,
        WINHTTP_NO_PROXY_BYPASS, 0);

    // Specify an HTTP server.
    if (hSession)
        hConnect = WinHttpConnect(hSession, L"open.er-api.com",
            INTERNET_DEFAULT_HTTPS_PORT, 0);

    // Create an HTTP Request handle.
    if (hConnect) {
        std::wstring requestUri = L"/v6/latest/UAH";
        hRequest = WinHttpOpenRequest(hConnect, L"GET",
            requestUri.c_str(),
            NULL, WINHTTP_NO_REFERER,
            WINHTTP_DEFAULT_ACCEPT_TYPES,
            WINHTTP_FLAG_SECURE);
    }

    // Send a Request.
    if (hRequest)
        bResults = WinHttpSendRequest(hRequest,
            WINHTTP_NO_ADDITIONAL_HEADERS,
            0, WINHTTP_NO_REQUEST_DATA, 0,
            0, 0);

    // End the request.
    if (bResults)
        bResults = WinHttpReceiveResponse(hRequest, NULL);

    // Read and display the response content.
    if (bResults) {
        DWORD bytesRead = 0;
        std::string responseData;
        do {
            BYTE buffer[4096];
            bResults = WinHttpReadData(hRequest, buffer, sizeof(buffer), &bytesRead);
            if (bResults && bytesRead > 0) {
                responseData.append(reinterpret_cast<const char*>(buffer), bytesRead);
            }
        } while (bResults && bytesRead > 0);

        std::ostringstream weatherInfo;
        weatherInfo << std::fixed << std::setprecision(2); // Set precision for double values

        std::string wstr = findData(responseData, symbol);
        weatherInfo << symbol << " price to 1UAH: " << wstr << " ";

        if (hRequest) WinHttpCloseHandle(hRequest);
        if (hConnect) WinHttpCloseHandle(hConnect);
        if (hSession) WinHttpCloseHandle(hSession);

        return weatherInfo.str();
    }

    // Report any errors.
    if (!bResults)
        std::cout << "Error " << GetLastError() << " has occurred." << std::endl;

    // Close any open handles.
    if (hRequest) WinHttpCloseHandle(hRequest);
    if (hConnect) WinHttpCloseHandle(hConnect);
    if (hSession) WinHttpCloseHandle(hSession);
}
std::string GetWheather(const char* symbol) {
    BOOL bResults = FALSE;
    HINTERNET hSession = NULL,
        hConnect = NULL,
        hRequest = NULL;

    // Use WinHttpOpen to obtain a session handle.
    hSession = WinHttpOpen(L"A WinHTTP Example Program/1.0",
        WINHTTP_ACCESS_TYPE_DEFAULT_PROXY,
        WINHTTP_NO_PROXY_NAME,
        WINHTTP_NO_PROXY_BYPASS, 0);

    // Specify an HTTP server.
    if (hSession)
        hConnect = WinHttpConnect(hSession, L"api.openweathermap.org",
            INTERNET_DEFAULT_HTTPS_PORT, 0);

    std::wstring ws(symbol, symbol + strlen(symbol));
    // Create an HTTP Request handle.
    if (hConnect) {
        std::wstring requestUri = L"/data/2.5/weather?q=" + std::wstring(ws) + L"&appid=0815bbca2422f402dd3549cbf054fe6f";
        hRequest = WinHttpOpenRequest(hConnect, L"GET",
            requestUri.c_str(),
            NULL, WINHTTP_NO_REFERER,
            WINHTTP_DEFAULT_ACCEPT_TYPES,
            WINHTTP_FLAG_SECURE);
    }

    // Send a Request.
    if (hRequest)
        bResults = WinHttpSendRequest(hRequest,
            WINHTTP_NO_ADDITIONAL_HEADERS,
            0, WINHTTP_NO_REQUEST_DATA, 0,
            0, 0);

    // End the request.
    if (bResults)
        bResults = WinHttpReceiveResponse(hRequest, NULL);

    // Read and display the response content.
    if (bResults) {
        DWORD bytesRead = 0;
        std::string responseData;
        do {
            BYTE buffer[4096];
            bResults = WinHttpReadData(hRequest, buffer, sizeof(buffer), &bytesRead);
            if (bResults && bytesRead > 0) {
                responseData.append(reinterpret_cast<const char*>(buffer), bytesRead);
            }
        } while (bResults && bytesRead > 0);

        std::ostringstream weatherInfo;
        weatherInfo << std::fixed << std::setprecision(2); // Set precision for double values
        weatherInfo << "Weather in Lviv: ";

        std::string wordStr = findData(responseData, "temp");
        double ftemp = std::stod(wordStr);
        double ctemp = ftemp - 273.15;
        weatherInfo << "Temp: " << ctemp << "C ";

        // Extract pressure
        wordStr = findData(responseData, "pressure");
        weatherInfo << "Pressure: " << wordStr << " hPa ";

        wordStr = findData(responseData, "humidity");
        weatherInfo << "Humidity: " << wordStr << " ";

        // Extract wind speed in km/h
        wordStr = findData(responseData, "speed");
        double msSpeed = std::stod(wordStr);
        double kmhSpeed = msSpeed * 3.6;
        weatherInfo << "Wind speed: " << kmhSpeed << " km/h ";

        // Extract weather condition
        wordStr = findData(responseData, "main");
        weatherInfo << "Main weather: " << wordStr;

        if (hRequest) WinHttpCloseHandle(hRequest);
        if (hConnect) WinHttpCloseHandle(hConnect);
        if (hSession) WinHttpCloseHandle(hSession);
        return weatherInfo.str();
    }

    // Report any errors.
    if (!bResults)
        std::wcout << L"Error " << GetLastError() << L" has occurred." << std::endl;

    // Close any open handles.
    if (hRequest) WinHttpCloseHandle(hRequest);
    if (hConnect) WinHttpCloseHandle(hConnect);
    if (hSession) WinHttpCloseHandle(hSession);
}

struct ClientInfo {
    int id = 0;
    SOCKET socket;
    bool isSubscribedWeather = false;
    bool isSubscribedStocks = false;
    bool isSubscribedCurrency = false;

    bool operator==(const ClientInfo& other) const {
        return socket == other.socket;
    }
};

int main() {
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        std::cerr << "Failed to initialize Winsock." << std::endl;
        return -1;
    }

    SOCKET serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == INVALID_SOCKET) {
        std::cerr << "Failed to create socket." << std::endl;
        WSACleanup();
        return -1;
    }

    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    serverAddress.sin_port = htons(5555);

    if (bind(serverSocket, reinterpret_cast<struct sockaddr*>(&serverAddress), sizeof(serverAddress)) == SOCKET_ERROR) {
        std::cerr << "Bind failed." << std::endl;
        closesocket(serverSocket);
        WSACleanup();
        return -1;
    }

    if (listen(serverSocket, 5) == SOCKET_ERROR) {
        std::cerr << "Listen failed." << std::endl;
        closesocket(serverSocket);
        WSACleanup();
        return -1;
    }

    u_long nonBlocking = 1;
    if (ioctlsocket(serverSocket, FIONBIO, &nonBlocking) != 0) {
        std::cerr << "Failed to set server socket to non-blocking." << std::endl;
        closesocket(serverSocket);
        WSACleanup();
        return -1;
    }

    std::cout << "Server listening on port 5555..." << std::endl;

    std::vector<ClientInfo> clients;

    while (true) {
        fd_set readSet;
        FD_ZERO(&readSet);
        FD_SET(serverSocket, &readSet);

        for (const auto& client : clients) {
            FD_SET(client.socket, &readSet);
        }

        timeval timeout = { 1, 0 };  // 10 second timeout

        int selectResult = select(0, &readSet, nullptr, nullptr, &timeout);

        if (selectResult == SOCKET_ERROR) {
            std::cerr << "Select error." << std::endl;
            break;
        }

        if (FD_ISSET(serverSocket, &readSet)) {
            SOCKET clientSocket = accept(serverSocket, nullptr, nullptr);
            if (clientSocket != INVALID_SOCKET) {
                std::cout << "Client connected." << std::endl;
                u_long nonBlocking = 1;
                ioctlsocket(clientSocket, FIONBIO, &nonBlocking);  // Set client socket to non-blocking
                int curId = clients.size() + 1;
                clients.push_back({ curId, clientSocket, false, false, false });
            }
        }

        for (auto& client : clients) {
            if (FD_ISSET(client.socket, &readSet)) {
                char buffer[256];
                int bytesRead = recv(client.socket, buffer, sizeof(buffer), 0);
                if (bytesRead > 0) {
                    buffer[bytesRead] = '\0';

                    if (strcmp(buffer, "subscribe weather") == 0) {
                        std::cout << "Client " << client.id << " subscribed to weather" << std::endl;
                        client.isSubscribedWeather = true;
                    }
                    else if (strcmp(buffer, "unsubscribe weather") == 0) {
                        std::cout << "Client " << client.id << " unsubscribed to weather" << std::endl;
                        client.isSubscribedWeather = false;
                    }
                    else if (strcmp(buffer, "subscribe stocks") == 0) {
                        std::cout << "Client " << client.id << " subscribed to stocks" << std::endl;
                        client.isSubscribedStocks = true;
                    }
                    else if (strcmp(buffer, "unsubscribe stocks") == 0) {
                        std::cout << "Client " << client.id << " unsubscribed to stocks" << std::endl;
                        client.isSubscribedStocks = false;
                    }
                    else if (strcmp(buffer, "subscribe currency") == 0) {
                        std::cout << "Client " << client.id << " subscribed to currency" << std::endl;
                        client.isSubscribedCurrency = true;
                    }
                    else if (strcmp(buffer, "unsubscribe currency") == 0) {
                        std::cout << "Client " << client.id << " unsubscribed to currency" << std::endl;
                        client.isSubscribedCurrency = false;
                    }
                }
                else if (bytesRead == 0) {
                    // Connection closed by the client
                    std::cout << "Client disconnected." << std::endl;
                    closesocket(client.socket);
                    auto it = std::find(clients.begin(), clients.end(), client);
                    if (it != clients.end()) {
                        clients.erase(it);
                    }
                    continue;
                }
                else if (WSAGetLastError() != WSAEWOULDBLOCK) {
                    // Handle other recv errors
                    std::cerr << "Recv error on client socket " << client.socket << ": " << WSAGetLastError() << std::endl;
                    closesocket(client.socket);
                    auto it = std::find(clients.begin(), clients.end(), client);
                    if (it != clients.end()) {
                        clients.erase(it);
                    }
                }
            }
        }

        // Send updates to subscribed clients based on their subscriptions
        for (auto& client : clients) {
            if (client.isSubscribedWeather) {
                std::string weath;
                weath.append(GetWheather("Lviv"));
                send(client.socket, weath.c_str(), weath.length(), 0);
            }

            if (client.isSubscribedStocks) {
                std::string stock;
                stock.append(GetStockPrice("ABNB"));
                stock.append(GetStockPrice("AMZN"));
                stock.append(GetStockPrice("PYPL"));
                send(client.socket, stock.c_str(), stock.length(), 0);
            }

            if (client.isSubscribedCurrency) {
                std::string curr;
                curr.append(GetCurrencyPrice("USD"));
                curr.append(GetCurrencyPrice("EUR"));
                send(client.socket, curr.c_str(), curr.length(), 0);
            }
        }
    }

    for (const auto& client : clients) {
        closesocket(client.socket);
    }

    closesocket(serverSocket);
    WSACleanup();

    return 0;
}

