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

## Contoh Input–Output

### 1) Inverse the Sequence
**Contoh 1**
```
Input
5
120 -450 0 7 9000

Output
21 -54 0 7 9
```
**Contoh 2**
```
Input
4
-123 4050 -10 0

Output
-321 504 -1 0
```

Jalankan cepat:
```bash
./inverse < samples/inverse_sample1.in
# expected ->
# 21 -54 0 7 9
```

### 2) Lost and Found
**Encode (mode 1)** — plaintext → digit-string dibalik
```
Input
1
halo

Output
411011890401
```
```
Input
1
TLS25

Output
750350580770480
```

**Decode (mode 2)**
```
Input
2
411011890401

Output
halo
```

**Partial decode (mode 3), k=4**
```
Input
3
990601011321501630411011890401
4

Output
halo
```

Jalankan cepat:
```bash
./lostfound < samples/lostfound_mode1_halo.in
./lostfound < samples/lostfound_mode2_decode_halo.in
./lostfound < samples/lostfound_mode3_partial4.in
```

### 3) Strange Traffic Lights
**Contoh 1** — `G=5, Y=2, R=4`
```
Input
5 2 4
6
0
4
5
6
11
12

Output
Green
Green
Yellow
Red
Red
Green
```
**Contoh 2** — `G=3, Y=1, R=2`
```
Input
3 1 2
7
0
1
2
3
4
5
6

Output
Green
Green
Green
Yellow
Red
Red
Green
```

Jalankan cepat:
```bash
./traffic < samples/traffic_sample1.in
```
