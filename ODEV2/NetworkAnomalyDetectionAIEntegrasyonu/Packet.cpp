#include "Packet.h"

// Yapıcı metot (Constructor) uygulaması
Packet::Packet(std::string src, std::string dest, std::string data, int packetSize) {
    sourceIP = src;
    destIP = dest;
    payload = data;
    size = packetSize;
}

// Getter metotlarının uygulamaları
std::string Packet::getSourceIP() const { 
    return sourceIP; 
}

std::string Packet::getDestIP() const { 
    return destIP; 
}

std::string Packet::getPayload() const { 
    return payload; 
}

int Packet::getSize() const { 
    return size; 
}
