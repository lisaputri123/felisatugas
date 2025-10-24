#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct tanggal {
    int hari;
    int bulan;
    int tahun;
};

struct nilai {
    float uts;
    float uas;
    float tugas;
};

struct mapel {
    float mtk;
    float bin;
    float big;
    float IPA;
};

struct mahasiswa {
    string nama;
    string nisn;
    int umur;
    string jurusan;
    tanggal lahir;
    nilai dd;
    mapel m;
};

float hitungtotal(nilai dd) {
    return (dd.uts * 0.35) + (dd.uas * 0.40) + (dd.tugas * 0.25);
}

float totalmapel(mapel m) {
    return (m.mtk * 0.35) + (m.bin * 0.2) + (m.big * 0.2) + (m.IPA * 0.25);
}

void input(int total, mahasiswa pelajar[]) {
    for (int i = 0; i < total; i++) {
        cout << "DATA MAHASISWA KE-" << (i + 1) << endl;
        cin.ignore();
        cout << "Masukkan nama: ";
        getline(cin, pelajar[i].nama);
        cout << "Masukkan NISN: ";
        getline(cin, pelajar[i].nisn);
        cout << "Masukkan umur: ";
        cin >> pelajar[i].umur;
        cin.ignore();
        cout << "Masukkan jurusan: ";
        getline(cin, pelajar[i].jurusan);
        cout << "Masukkan tanggal lahir: ";
        cin >> pelajar[i].lahir.hari;
        cout << "Masukkan bulan lahir: ";
        cin >> pelajar[i].lahir.bulan;
        cout << "Masukkan tahun lahir: ";
        cin >> pelajar[i].lahir.tahun;
        cout << "Masukkan nilai UTS: ";
        cin >> pelajar[i].dd.uts;
        cout << "Masukkan nilai UAS: ";
        cin >> pelajar[i].dd.uas;
        cout << "Masukkan nilai tugas: ";
        cin >> pelajar[i].dd.tugas;
        cout << "Masukkan nilai MTK: ";
        cin >> pelajar[i].m.mtk;
        cout << "Masukkan nilai B.Indo: ";
        cin >> pelajar[i].m.bin;
        cout << "Masukkan nilai B.Inggris: ";
        cin >> pelajar[i].m.big;
        cout << "Masukkan nilai IPA: ";
        cin >> pelajar[i].m.IPA;
    }
}

void output(int total, mahasiswa pelajar[]) {
    ofstream file("siswa.txt", ios::app);
    for (int i = 0; i < total; i++) {
        file << "DATA MAHASISWA KE-" << (i + 1) << endl;
        file << "Nama : " << pelajar[i].nama << endl;
        file << "NISN : " << pelajar[i].nisn << endl;
        file << "Umur : " << pelajar[i].umur << endl;
        file << "Jurusan : " << pelajar[i].jurusan << endl;
        file << "Tanggal lahir : " << pelajar[i].lahir.hari << "-"
             << pelajar[i].lahir.bulan << "-" << pelajar[i].lahir.tahun << endl;
        file << "Nilai MTK = " << pelajar[i].m.mtk << endl;
        file << "Nilai B.Indo = " << pelajar[i].m.bin << endl;
        file << "Nilai B.Inggris = " << pelajar[i].m.big << endl;
        file << "Nilai IPA = " << pelajar[i].m.IPA << endl;
        file << "Nilai UTS : " << pelajar[i].dd.uts << endl;
        file << "Nilai UAS : " << pelajar[i].dd.uas << endl;
        file << "Nilai tugas : " << pelajar[i].dd.tugas << endl;
        file << "Nilai akhir mapel: " << totalmapel(pelajar[i].m) << endl;
        file << "Nilai akhir siswa: " << hitungtotal(pelajar[i].dd) << endl;
        file << "---------------------------------------------" << endl;
    }
    file.close();
}

void memecahkan() {
    string nisn;
    cout << "Masukkan NISN: ";
    cin >> nisn;

    ifstream file("siswa.txt");
    bool mendapatkan = false;
    string baris, prev_line = "";

    while (getline(file, baris)) {
        if (baris.find("NISN : " + nisn) != string::npos) {
            mendapatkan = true;
            cout << "\nData siswa yang dicari:\n";
            cout << prev_line << endl;
            cout << baris << endl;
            for (int i = 0; i < 10 && getline(file, baris); i++) {
                cout << baris << endl;
            }
            break;
        }
        prev_line = baris;
    }

    if (!mendapatkan) {
        cout << "Siswa dengan NISN: " << nisn << " tidak ditemukan.\n";
    }

    file.close();
}

void ranking_siswa(int total, mahasiswa pelajar[]) {
    for (int f = 0; f < total - 1; f++) {
        for (int l = 0; l < total - f - 1; l++) {
            if (totalmapel(pelajar[l].m) < totalmapel(pelajar[l + 1].m)) {
                mahasiswa tukar = pelajar[l];
                pelajar[l] = pelajar[l + 1];
                pelajar[l + 1] = tukar;
            }
        }
    }

    cout << "\n======== RANGKING SISWA ========\n";
    for (int k = 0; k < total; k++) {
        cout << "Rangking " << k + 1 << endl;
        cout << "Nama: " << pelajar[k].nama << endl;
        cout << "NISN: " << pelajar[k].nisn << endl;
        cout << "Jurusan: " << pelajar[k].jurusan << endl;
        cout << "Nilai akhir: " << totalmapel(pelajar[k].m) << endl;
        cout << "---------------------------------\n";
    }
}

int main() {
    ifstream file("siswa.txt");
    if (file.peek() == ifstream::traits_type::eof()) {
        int total;
        cout << "Masukkan jumlah siswa: ";
        cin >> total;
        mahasiswa pelajar[total];
        input(total, pelajar);
        output(total, pelajar);
        ranking_siswa(total, pelajar);
        cout << "Data siswa telah ditambahkan dan disimpan di file siswa.txt\n";
    } else {
        string deret;
        while (getline(file, deret)) {
            cout << deret << endl;
        }
        file.close();

        char pilihan;
        cout << "\nApakah kamu ingin menambahkan data siswa lagi? (y): ";
        cin >> pilihan;
        if (pilihan == 'y' || pilihan == 'Y') {
            int total;
            cout << "Masukkan jumlah siswa: ";
            cin >> total;
            mahasiswa pelajar[total];
            input(total, pelajar);
            output(total, pelajar);
            ranking_siswa(total, pelajar);
            cout << "Data telah ditambahkan dan disimpan di file siswa.txt\n";
        }

        char opsi2;
        cout << "Apakah kamu ingin mencari siswa (s)? ";
        cin >> opsi2;
        if (opsi2 == 's' || opsi2 == 'S') {
            memecahkan();
        }
    }
    return 0;
}