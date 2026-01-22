#include <iostream>
#include <cstring>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main() {
    int sockfd;
    struct sockaddr_in server_addr;
    const char* message = "Halo dari client UDP!";

    // 1. Buat socket UDP
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        std::cerr << "Gagal buat socket\n";
        return 1;
    }

    // 2. Isi alamat server
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080); // port 8080
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1"); // IP lokal (localhost)

    // 3. Kirim data ke server
    ssize_t sent = sendto(sockfd, message, strlen(message), 0,
                          (struct sockaddr*)&server_addr, sizeof(server_addr));
    if (sent < 0) {
        std::cerr << "Gagal kirim data\n";
        close(sockfd);
        return 1;
    }

    std::cout << "Pesan terkirim ke server\n";

    close(sockfd);
    return 0;
}
