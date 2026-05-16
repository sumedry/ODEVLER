#include "AnomalyDetector.h"
#include <iostream>
#include <thread>
#include <chrono>

// Yapici metot uygulamasi
AnomalyDetector::AnomalyDetector(int threshold) {
    thresholdSize = threshold;
}

// Analiz fonksiyonunun bu sinifa (Yapay Zekaya) ozel uygulamasi
void AnomalyDetector::analyze(const Packet& packet) {
    std::cout << "[AI ANOMALI TESPITI] Paket inceleniyor... Kaynak: " << packet.getSourceIP() << "\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(800)); // Simulasyon gecikmesi
    
    if (packet.getSize() > thresholdSize) {
        std::cout << "  -> [!!!] UYARI (Anomali)! Paket boyutu (" << packet.getSize() 
                  << " bytes) normalin cok uzerinde!\n";
        std::cout << "  -> [!!!] Olasi bir DDoS veya Veri Sizintisi (Exfiltration) saldirisi.\n";
    } else {
        std::cout << "  -> [+] Trafik normal gorunuyor. Anomali yok.\n";
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(500)); // Simulasyon gecikmesi
}
