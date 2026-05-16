import customtkinter as ctk
import subprocess
import threading
import os

# Arayüz ayarları (Koyu Tema)
ctk.set_appearance_mode("Dark")
ctk.set_default_color_theme("blue")

class CyberSecApp(ctk.CTk):
    def __init__(self):
        super().__init__()

        # Pencere başlığı ve boyutu
        self.title("Ağ Güvenlik ve Zararlı Yazılım Analiz Sistemi - Kontrol Paneli")
        self.geometry("950x650")
        self.minsize(800, 500)

        # ---------------- Sol Menü (Sidebar) ----------------
        self.sidebar_frame = ctk.CTkFrame(self, width=200, corner_radius=0)
        self.sidebar_frame.grid(row=0, column=0, rowspan=4, sticky="nsew")
        self.sidebar_frame.grid_rowconfigure(4, weight=1) # Alt kısımdaki boşluğu yaymak için

        # Logo / Başlık
        self.logo_label = ctk.CTkLabel(self.sidebar_frame, text="🛡️ CyberSec AI", font=ctk.CTkFont(size=22, weight="bold"))
        self.logo_label.grid(row=0, column=0, padx=20, pady=(30, 20))

        # Butonlar
        self.start_button = ctk.CTkButton(self.sidebar_frame, text="▶️ Analizi Başlat", command=self.start_analysis, height=40, font=ctk.CTkFont(weight="bold"))
        self.start_button.grid(row=1, column=0, padx=20, pady=10)

        self.clear_button = ctk.CTkButton(self.sidebar_frame, text="🗑️ Ekranı Temizle", command=self.clear_terminal, fg_color="#E67E22", hover_color="#D35400", height=40, font=ctk.CTkFont(weight="bold"))
        self.clear_button.grid(row=2, column=0, padx=20, pady=10)

        self.exit_button = ctk.CTkButton(self.sidebar_frame, text="❌ Çıkış", command=self.destroy, fg_color="#C0392B", hover_color="#922B21", height=40, font=ctk.CTkFont(weight="bold"))
        self.exit_button.grid(row=3, column=0, padx=20, pady=10)

        self.dev_label = ctk.CTkLabel(self.sidebar_frame, text="Proje Arayüzü v1.0", font=ctk.CTkFont(size=12), text_color="gray")
        self.dev_label.grid(row=5, column=0, padx=20, pady=20, sticky="s")


        # ---------------- Sağ Ana Ekran (Terminal) ----------------
        self.main_frame = ctk.CTkFrame(self, corner_radius=10)
        self.main_frame.grid(row=0, column=1, rowspan=4, padx=20, pady=20, sticky="nsew")
        
        # Grid ayarları (Büyütülünce esnemesi için)
        self.grid_columnconfigure(1, weight=1)
        self.grid_rowconfigure(0, weight=1)

        self.terminal_label = ctk.CTkLabel(self.main_frame, text="Canlı Ağ Trafiği ve Analiz Çıktısı", font=ctk.CTkFont(size=18, weight="bold"))
        self.terminal_label.pack(pady=(15, 5))

        # Gerçekçi bir terminal görünümü için siyah arka plan, yeşil metin
        self.textbox = ctk.CTkTextbox(self.main_frame, font=("Consolas", 15), text_color="#00FF00", fg_color="#0a0a0a")
        self.textbox.pack(padx=15, pady=15, fill="both", expand=True)

        self.process = None

    def start_analysis(self):
        self.start_button.configure(state="disabled") # Tıklanmayı kapat
        self.textbox.insert("end", "[SİSTEM]: Güvenlik motorları aktif ediliyor...\n")
        
        # C++ exe dosyasının tam yolunu bul
        exe_path = os.path.join(os.path.dirname(__file__), "SecurityProject.exe")
        
        if not os.path.exists(exe_path):
            self.textbox.insert("end", f"[HATA]: C++ uygulaması ({exe_path}) bulunamadı!\nLütfen önce kodu derleyin.\n")
            self.start_button.configure(state="normal")
            return

        # Arka planda donmadan exe'yi çalıştırmak için bir thread (iş parçacığı) kullanıyoruz
        threading.Thread(target=self.run_exe, args=(exe_path,), daemon=True).start()

    def run_exe(self, exe_path):
        # subprocess ile exe'yi arka planda aç, çıktısını yakala
        # Windows'ta siyah CMD penceresinin anlık açılmasını engellemek için CREATE_NO_WINDOW (0x08000000) kullanıyoruz
        CREATE_NO_WINDOW = 0x08000000
        
        self.process = subprocess.Popen(
            [exe_path], 
            stdout=subprocess.PIPE, 
            stderr=subprocess.STDOUT, 
            creationflags=CREATE_NO_WINDOW
        )
        
        # Çıktıyı harf harf veya satır satır okuma
        # Harf harf okuyoruz ki simülasyondaki "..." bekleme efektlerini canlı görelim
        while True:
            char = self.process.stdout.read(1)
            if not char:
                break
            
            # Byte'ı string'e çevir
            text = char.decode('utf-8', errors='ignore')
            
            # Textbox'a ekle ve en alta kaydır
            self.textbox.insert("end", text)
            self.textbox.see("end")
            
        self.process.wait()
        self.textbox.insert("end", "\n[SİSTEM]: İşlem tamamlandı. Analiz motoru durduruldu.\n")
        
        # İşlem bitince butonu tekrar aktif et
        self.start_button.configure(state="normal")

    def clear_terminal(self):
        self.textbox.delete("1.0", "end")

if __name__ == "__main__":
    app = CyberSecApp()
    app.mainloop()
