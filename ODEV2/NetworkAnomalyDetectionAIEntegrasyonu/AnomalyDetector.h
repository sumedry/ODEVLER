#ifndef ANOMALY_DETECTOR_H
#define ANOMALY_DETECTOR_H

#include "Analyzer.h"

// Kalıtım (Inheritance) Prensibi:
// AnomalyDetector sınıfı, "Analyzer" sınıfından "public" olarak türetilir.
// Yani bir AnomalyDetector, aslında özelleştirilmiş bir Analyzer'dır.
class AnomalyDetector : public Analyzer {
private:
    int thresholdSize; // Yapay Zeka modelimizin öğrendiği "normal" boyut eşiği

public:
    // Yapıcı Metot
    AnomalyDetector(int threshold);

    // Çok Biçimlilik (Polymorphism) Prensibi:
    // Ana sınıfta "= 0" olarak bıraktığımız fonksiyonu, burada "override" anahtar 
    // kelimesi ile "ezeriz" ve kendi yapay zeka mantığımıza göre içini doldururuz.
    void analyze(const Packet& packet) override;
};

#endif
