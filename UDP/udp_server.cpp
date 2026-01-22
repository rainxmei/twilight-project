#include <iostream>
#include <cstring>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main() {
    int sockfd;
    struct sockaddr_in server_addr, client_addr;
    char buffer[1024];
    socklen_t addr_len = sizeof(client_addr);

    // 1. Buat socket UDP
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        std::cerr << "Gagal buat socket\n";
        return 1;
    }

    // 2. Isi alamat server
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080); // port 8080
    server_addr.sin_addr.s_addr = INADDR_ANY; // bind ke semua interface

    // 3. Bind socket ke alamat dan port
    if (bind(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        std::cerr << "Bind gagal\n";
        close(sockfd);
        return 1;
    }

    std::cout << "Server siap menerima data...\n";

    // 4. Terima data dari client
    while (true) {
        ssize_t n = recvfrom(sockfd, buffer, sizeof(buffer) - 1, 0,
                             (struct sockaddr*)&client_addr, &addr_len);
        if (n < 0) {
            std::cerr << "Gagal menerima data\n";
            break;
        }

        buffer[n] = '\0'; // beri null terminator
        std::cout << "Diterima: " << buffer << "\n";
    }

    close(sockfd);
    return 0;
}
