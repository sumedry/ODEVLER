#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include "Packet.h"
#include "AnomalyDetector.h"
#include "MalwareAnalyzer.h"

void printHeader() {
    std::cout << "========================================================\n";
    std::cout << "   AG GUVENLIK VE ZARARLI YAZILIM ANALIZ SISTEMI V2.0   \n";
    std::cout << "========================================================\n\n";
    std::cout << "Sistem baslatiliyor";
    for(int i=0; i<3; i++) {
        std::cout << ".";
        std::this_thread::sleep_for(std::chrono::milliseconds(400));
    }
    std::cout << "\nMotorlar yukleniyor...\n\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(800));
}

int main() {
    printHeader();

    // 1. KAPSULLEME (ENCAPSULATION) TESTI: Farkli senaryolar icin ag paketleri olusturuyoruz.
    // Nesnelerimizi yaratiyoruz ve onlara ilk degerlerini veriyoruz.
    Packet normalPacket("192.168.1.10", "8.8.8.8", "Sadece bir ping istegi, zararli degil.", 64);
    
    // Buyuk boyutlu bir paket (Yapay Zekanin "Anomali" yakalamasi icin)
    Packet largePacket("10.0.0.5", "192.168.1.20", "Sistem yedegi aktariliyor...", 15000); 
    
    // Icinde zararli yazilim komutu barindiran paket (Malware Analizi yakalamasi icin)
    Packet maliciousPacket("172.16.0.4", "192.168.1.10", "Hack denemesi: cmd.exe /c format c:", 128);

    // 2. COK BICIMLILIK (POLYMORPHISM) TESTI:
    std::vector<Analyzer*> analyzers;
    
    // AI motoruna esik degeri olarak 10000 veriyoruz (10000 byte uzeri supheli)
    analyzers.push_back(new AnomalyDetector(10000)); 
    // Zararli yazilim arayan motoru da listeye ekliyoruz
    analyzers.push_back(new MalwareAnalyzer());

    // 3. SISTEMI CALISTIRMA (SIMULASYON):
    std::vector<Packet> networkTraffic = { normalPacket, largePacket, maliciousPacket };

    for (size_t i = 0; i < networkTraffic.size(); ++i) {
        std::cout << "--------------------------------------------------------\n";
        std::cout << ">>> YENI PAKET YAKALANDI (Sira: " << i+1 << ") <<<\n";
        std::cout << "Kaynak IP: " << networkTraffic[i].getSourceIP() << " | Hedef IP: " << networkTraffic[i].getDestIP() << "\n";
        std::cout << "--------------------------------------------------------\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(600));
        
        for (size_t j = 0; j < analyzers.size(); ++j) {
            analyzers[j]->analyze(networkTraffic[i]);
            std::cout << "\n";
        }
    }

    for (size_t j = 0; j < analyzers.size(); ++j) {
        delete analyzers[j];
    }

    std::cout << "========================================================\n";
    std::cout << "          TUM ANALIZLER TAMAMLANDI - SISTEM KAPALI      \n";
    std::cout << "========================================================\n";
    return 0;
}
