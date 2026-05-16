#ifndef ANALYZER_H
#define ANALYZER_H

#include "Packet.h"

// Soyutlama (Abstraction) Prensibi:
// Bu sınıf bir "Arayüz" (Interface) görevi görecektir.
// Kendi başına bir nesnesi oluşturulamaz. Diğer analiz motorlarına (Yapay Zeka veya Malware) şablon olur.
class Analyzer {
public:
    // Sanal Yıkıcı (Virtual Destructor)
    // Kalıtım kullanılan sınıflarda bellek sızıntısını (memory leak) önlemek için standart bir güvenlik önlemidir.
    virtual ~Analyzer() {}

    // Saf Sanal Fonksiyon (Pure Virtual Function)
    // Sonundaki "= 0" ifadesi, bu fonksiyonun içinin BU SINIFTA doldurulmayacağını belirtir.
    // Bu sınıftan türetilecek olan alt sınıflar (Örn: MalwareAnalyzer, AnomalyDetector) 
    // bu fonksiyonu KENDİ İÇLERİNDE yazmak ve içini doldurmak ZORUNDADIR.
    // Bu kural, Çok Biçimlilik (Polymorphism) prensibinin temelidir.
    virtual void analyze(const Packet& packet) = 0;
};

#endif
