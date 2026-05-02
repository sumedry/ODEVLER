# Docker AI Monitoring & Analysis System

Bu proje, Docker konteynırlarını anlık olarak izleyen ve meydana gelen olayları (durdurma, hata vb.) Groq AI kullanarak analiz eden bir otomasyon sistemidir.

## Özellikler

- **Gerçek Zamanlı İzleme:** Docker olaylarını (Events) anlık yakalar.
- **AI Analizi:** Groq AI ile logları teknik olarak yorumlar.
- **Çok Kanallı Bildirim:** Analiz sonuçlarını Notion, Telegram ve Discord'a profesyonel formatta iletir.

## Kurulum

1. n8n üzerinden `docker-ai-monitor.json` dosyasını import edin.
2. Kendi API anahtarlarınızı (Groq, Telegram, Discord) n8n içinde tanımlayın.
3. `monitor.ps1` scriptini PowerShell üzerinden çalıştırarak izlemeyi başlatın.

---

_Hazırlayan: Sümeyye DİLE - Kastamonu Üniversitesi Bilgisayar Mühendisliği_
