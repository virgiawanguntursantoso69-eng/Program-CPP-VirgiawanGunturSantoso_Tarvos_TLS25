# Program-CPP-VirgiawanGunturSantoso_Tarvos_TLS25

Nama lengkap: **Virgiawan Guntur Santoso**  
Kelompok: **Tarvos**

## Berkas
- `01_inverse_sequence.cpp`
- `02_lost_and_found.cpp`
- `03_strange_traffic_lights.cpp`

## Kompilasi
```bash
g++ -std=c++17 -O2 01_inverse_sequence.cpp -o inverse
g++ -std=c++17 -O2 02_lost_and_found.cpp -o lostfound
g++ -std=c++17 -O2 03_strange_traffic_lights.cpp -o traffic
```

## 1) Inverse the Sequence
**Input**
```
n
a1 a2 ... an
```
**Output**: setiap bilangan dibalik digitnya (pakai *mathematical reversal*, mendukung negatif & 0).

## 2) Lost and Found (dua arah)
Mode:
- `1` → encode (masukkan satu baris plaintext)
- `2` → decode (masukkan satu baris digit sandi)
- `3` → partial decode (digit sandi diikuti angka k)

Catatan:
- Tidak menggunakan `std::reverse`, hanya `myReverse` (user-defined).
- ASCII selalu disimpan sebagai *integer* dulu (triplet), baru dibalik seluruh digitnya.

## 3) Strange Traffic Lights
**Input**
```
G Y R
q
t1
t2
...
tq
```
**Output**: status lampu pada tiap `t_i` dengan modulus+loop (tanpa if-else chain panjang).

## Langkah Push ke GitHub
1. Buat repo **public** bernama **Program-CPP-VirgiawanGunturSantoso_Tarvos_TLS25** di akun GitHub kamu.
2. Jalankan perintah berikut di dalam folder proyek:
```bash
git init
git add .
git commit -m "TLS25: tugas Pemrograman 2 (C++)"
git branch -M main
git remote add origin https://github.com/<username>/Program-CPP-VirgiawanGunturSantoso_Tarvos_TLS25.git
git push -u origin main
```
Ganti `<username>` dengan username GitHub kamu.
