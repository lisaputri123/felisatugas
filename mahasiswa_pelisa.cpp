#include <iostream>
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

struct mahasiswa {
    string nama;
    int umur;
    string jurusan;
    tanggal lahir;
    nilai dd;
};

float hitungtotal(nilai dd) {
    return (dd.uts * 0.35) + (dd.uas * 0.40) + (dd.tugas * 0.25);
}

void input(int total,mahasiswa pelajar[]){
     for (int i=0;i<total;i++){

    cout<<"DATA MAHASISWA KE-"<<(i+1)<<endl;
    cout << "masukkan nama: ";
    cin >> pelajar[i].nama;
    cout << "masukkan umur: ";
    cin >> pelajar[i].umur;
    cout << "masukkan jurusan: ";
    cin >> pelajar[i].jurusan;

    cout << "masukkan tanggal: ";
    cin >> pelajar[i].lahir.hari;
    cout << "masukkan bulan: ";
    cin >> pelajar[i].lahir.bulan;
    cout << "masukkan tahun: ";
    cin >> pelajar[i].lahir.tahun;

    cout << "masukkan nilai UTS: ";
    cin >> pelajar[i].dd.uts;
    cout << "masukkan nilai UAS: ";
    cin >> pelajar[i].dd.uas;
    cout << "masukkan nilai tugas: ";
    cin >> pelajar[i].dd.tugas;
}
}
void output(int total,mahasiswa pelajar[]){
        for (int i =0; i<total;i++){

    cout<<"DATA MAHASISWA KE-"<<(i+1)<<endl;
    cout << "Nama : " << pelajar[i].nama << endl;
    cout << "Umur : " << pelajar[i].umur << endl;
    cout << "Jurusan : " << pelajar[i].jurusan << endl;
    cout << "Tanggal,bulan,lahir "<< "=" << pelajar[i].lahir.hari << "-" << pelajar[i].lahir.bulan << "-" <<pelajar[i].lahir.tahun<<endl;
    cout << "Nilai UTS : " << pelajar[i].dd.uts << endl;
    cout << "Nilai UAS : " << pelajar[i].dd.uas << endl;
    cout << "Nilai tugas : " << pelajar[i].dd.tugas << endl;
    cout<<"nilai akhir siswa: "<<hitungtotal(pelajar[i].dd)<<endl;
}
}
int main() {
    int total;
    cout<<"masukkan jumlah data mahasiswa:";
    cin>>total;
    mahasiswa pelajar[total];
    input(total, pelajar);
    output(total, pelajar);
    return 0;
}