#pragma once

#include <iostream>
#include <cstring>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>

class TcpClient {
public:
    TcpClient(const std::string& address, const std::string& port) {
        sockfd_ = socket(AF_INET, SOCK_STREAM, 0);
        if (sockfd_ < 0) {
            perror("Error creating socket");
            exit(EXIT_FAILURE);
        }

        server_addr_.sin_family = AF_INET;
        server_addr_.sin_port = htons(std::stoi(port));
        if (inet_pton(AF_INET, address.c_str(), &server_addr_.sin_addr) <= 0) {
            perror("Error in inet_pton");
            close(sockfd_);
            exit(EXIT_FAILURE);
        }

        if (connect(sockfd_, (struct sockaddr*)&server_addr_, sizeof(server_addr_)) < 0) {
            perror("Error connecting to server");
            close(sockfd_);
            exit(EXIT_FAILURE);
        }

        
        int flags = fcntl(sockfd_, F_GETFL, 0);
        if (flags == -1 || fcntl(sockfd_, F_SETFL, flags | O_NONBLOCK) == -1) {
            perror("Error setting socket to non-blocking");
            close(sockfd_);
            exit(EXIT_FAILURE);
        }
    }

    ~TcpClient() {
        close(sockfd_);
    }

    void send(const std::string& username, int number) {
        std::string message = username + " " + std::to_string(number) + "\r\n";
        const char* msg = message.c_str();
        ssize_t total_bytes_sent = 0;
        ssize_t bytes_to_send = message.size();

        fd_set writefds;
        FD_ZERO(&writefds);

        
        while (total_bytes_sent < bytes_to_send) {
            FD_SET(sockfd_, &writefds);
            timeval timeout;
            timeout.tv_sec = 1; 
            timeout.tv_usec = 0;

            int retval = select(sockfd_ + 1, NULL, &writefds, NULL, &timeout);
            if (retval == -1) {
                perror("select() error during sending");
                return;
            } else if (retval == 0) {
                
                continue;
            } else if (retval > 0) {
                if (FD_ISSET(sockfd_, &writefds)) {
                    ssize_t bytes_sent = ::send(sockfd_, msg + total_bytes_sent, bytes_to_send - total_bytes_sent, 0);
                    if (bytes_sent < 0) {
                        perror("Error sending message");
                        return;
                    }
                    total_bytes_sent += bytes_sent;
                }
            }
        }
    }

    std::string readResponse() {
        std::string response;
        char buffer[1024];
        fd_set readfds;
        timeval timeout;
        timeout.tv_sec = 5; 
        timeout.tv_usec = 0;

        while (true) {
            FD_SET(sockfd_, &readfds);
            int retval = select(sockfd_ + 1, &readfds, NULL, NULL, &timeout);
            if (retval == -1) {
                perror("select() error during receiving");
                return "";
            } else if (retval == 0) {
                
                break;
            } else if (retval > 0) {
                if (FD_ISSET(sockfd_, &readfds)) {
                    ssize_t bytes_received = recv(sockfd_, buffer, sizeof(buffer) - 1, 0);
                    if (bytes_received < 0) {
                        perror("Error receiving response");
                        return "";
                    } else if (bytes_received == 0) {
                        break; 
                    }
                    buffer[bytes_received] = '\0';
                    response += buffer;

                    
                    if (response.find("\r\n") != std::string::npos) {
                        break;
                    }
                }
            }
        }

        return response;
    }

private:
    int sockfd_;
    struct sockaddr_in server_addr_;
};
