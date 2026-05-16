#ifndef PACKET_H
#define PACKET_H

#include <string>

// Kapsülleme (Encapsulation) Prensibi:
// Sınıfın verileri (değişkenleri) 'private' yapılarak dışarıdan doğrudan erişime kapatılır.
// Bu verilere sadece bizim izin verdiğimiz 'public' fonksiyonlar üzerinden erişilebilir.
class Packet {
private:
    std::string sourceIP;
    std::string destIP;
    std::string payload; // Paketin içindeki asıl veri (Malware analizi için burayı okuyacağız)
    int size;            // Paket boyutu (Anomali tespiti için buraya bakacağız)

public:
    // Yapıcı Metot (Constructor): Yeni bir nesne oluşturulduğunda ilk değerleri atar.
    Packet(std::string src, std::string dest, std::string data, int packetSize);

    // Getters: Dışarıdan değişkenleri okumak için kullandığımız fonksiyonlar.
    std::string getSourceIP() const;
    std::string getDestIP() const;
    std::string getPayload() const;
    int getSize() const;
};

#endif
