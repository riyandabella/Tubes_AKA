#include <iostream>
using namespace std;

// Fungsi rekursif untuk menghitung peluang dadu sama
double peluang_dadu_sama_rekursif(int n, int dadu1 = 1, int dadu2 = 1, int hasil = 0) {
    // Basis kasus: jika kedua dadu mencapai angka n
    if (dadu1 > n) {
        // Total kombinasi yang mungkin adalah n * n
        int total_kombinasi = n * n;

        // Peluangnya adalah kombinasi_sama / total_kombinasi
        return static_cast<double> (hasil) / total_kombinasi;
    }

    // Jika angka pada kedua dadu sama, tambahkan ke hasil
    if (dadu1 == dadu2) {
        hasil++;
    }

    // Jika dadu2 mencapai nilai maksimum n, lanjutkan ke dadu1 berikutnya dan reset dadu2 ke 1
    if (dadu2 < n) {
        return peluang_dadu_sama_rekursif(n, dadu1, dadu2 + 1, hasil);
    } else {
        return peluang_dadu_sama_rekursif(n, dadu1 + 1, 1, hasil);
    }
}

// Fungsi iteratif untuk menghitung peluang dadu sama
double peluang_dadu_sama_iteratif(int n) {
    // Inisialisasi jumlah kombinasi yang sama
    int kombinasi_sama = 0;

    // Inisialisasi nilai dadu1 dan dadu2
    for (int dadu1 = 1; dadu1 <= n; dadu1++) {
        for (int dadu2 = 1; dadu2 <= n; dadu2++) {
            // Jika angka pada kedua dadu sama, tambahkan ke kombinasi_sama
            if (dadu1 == dadu2) {
                kombinasi_sama++;
            }
        }
    }

    // Total kombinasi yang mungkin adalah n * n
    int total_kombinasi = n * n;

    // Peluangnya adalah kombinasi_sama / total_kombinasi
    return static_cast<double>(kombinasi_sama) / total_kombinasi;
}

int main() {
    int n, pilihan;

    while (true) {
        cout << "-----------------Pilih menu----------------- \n";
        cout << "1. Peluang dadu sama (rekursif)\n";
        cout << "2. Peluang dadu sama (iteratif)\n";
        cout << "3. Keluar\n";
        cout << "-------------------------------------------- \n";
        cout << "by: \n";
        cout << "Riyanda Wiesya Bella (103022300001) \n";
        cout << "Shinta Alya Aulya Ningrum (103022300049) \n";
        cout << "Masukkan pilihan: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                // Menggunakan metode rekursif
                cout << "Masukkan jumlah sisi dadu: ";
                cin >> n;
                cout << "Peluang muncul dadu angka sama (rekursif): "
                     << peluang_dadu_sama_rekursif(n) << endl;
                cout << endl;
                break;

            case 2:
                // Menggunakan metode iteratif
                cout << "Masukkan jumlah sisi dadu: ";
                cin >> n;
                cout << "Peluang muncul dadu angka sama (iteratif): "
                     << peluang_dadu_sama_iteratif(n) << endl;
                cout << endl;
                break;

            case 3:
                // Keluar dari program
                cout << "Keluar dari program...\n";
                return 0;

            default:
                // Jika pilihan tidak valid
                cout << "Pilihan tidak valid, coba lagi.\n";
                cout << endl;
        }
    }

    return 0;
}
