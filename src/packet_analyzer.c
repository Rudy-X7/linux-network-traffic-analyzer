#include "../include/headers.h"

#define BUFFER_SIZE 65536

int tcp_count = 0;
int udp_count = 0;
int icmp_count = 0;
int other_count = 0;

void process_packet(unsigned char *buffer) {
    struct iphdr *ip_header;
    struct sockaddr_in source, dest;

    ip_header = (struct iphdr *)(buffer + sizeof(struct ethhdr));

    memset(&source, 0, sizeof(source));
    memset(&dest, 0, sizeof(dest));

    source.sin_addr.s_addr = ip_header->saddr;
    dest.sin_addr.s_addr = ip_header->daddr;

    switch (ip_header->protocol) {
        case IPPROTO_TCP:
            tcp_count++;
            printf("[TCP ] ");
            break;
        case IPPROTO_UDP:
            udp_count++;
            printf("[UDP ] ");
            break;
        case IPPROTO_ICMP:
            icmp_count++;
            printf("[ICMP] ");
            break;
        default:
            other_count++;
            printf("[OTHR] ");
            break;
    }

    printf("Source: %s | Destination: %s\n",
           inet_ntoa(source.sin_addr),
           inet_ntoa(dest.sin_addr));

    printf("Stats -> TCP: %d | UDP: %d | ICMP: %d | Others: %d\n\n",
           tcp_count, udp_count, icmp_count, other_count);
}

int main() {
    int sockfd;
    unsigned char buffer[BUFFER_SIZE];

    sockfd = socket(AF_PACKET, SOCK_RAW, htons(ETH_P_ALL));
    if (sockfd < 0) {
        perror("Socket creation failed");
        return 1;
    }

    printf("Linux Network Traffic Analyzer Started...\n");
    printf("Press Ctrl+C to stop.\n\n");

    while (1) {
        int data_size = recvfrom(sockfd, buffer, BUFFER_SIZE, 0, NULL, NULL);
        if (data_size < 0) {
            perror("Recv failed");
            break;
        }

        process_packet(buffer);
    }

    close(sockfd);
    return 0;
}
