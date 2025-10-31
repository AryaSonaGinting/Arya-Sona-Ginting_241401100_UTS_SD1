// Arya Sona Ginting
// 241401100
// LAb 1 SD

#include <iostream>
#include <string>    // supaya bisa pakai tipe data string
using namespace std; // biar nggak perlu nulis std:: terus

struct hewan
{
    string nama;  // nama hewan
    string jenis; // jenis hewan
    int umur;     // umur hewan
    int darurat;  // tingkat darurat 1-5
};

int main()
{
    int n;                                    // jumlah pasien yang akan dimasukkan
    cout << "Masukkan jumlah pasien hewan: "; // minta user input jumlah pasien
    cin >> n;                                 // baca jumlah pasien
    cin.ignore();                             // buang newline tersisa agar getline berikutnya bekerja

    hewan *hewans = new hewan[n]; // buat array dynamic berisi n elemen hewan

    for (int i = 0; i < n; ++i) // loop input tiap pasien
    {
        cout << "\npasien ke-" << (i + 1) << "\n"; // tampilkan nomor pasien
        cout << "Nama hewan: ";                    // minta nama
        getline(cin, hewans[i].nama);              // baca nama lengkap (boleh ada spasi)
        cout << "Jenis hewan: ";                   // minta jenis
        getline(cin, hewans[i].jenis);             // baca jenis hewan
        cout << "Umur : ";                         // minta umur
        cin >> hewans[i].umur;                     // baca umur
        cout << "Tingkat darurat (1-5): ";         // minta tingkat darurat
        cin >> hewans[i].darurat;                  // baca darurat (angka 1-5)
        cin.ignore();                              // buang newline sebelum iterasi berikutnya
    }

    // Buat array of pointers untuk 5 queue (index 1..5 dipakai)
    hewan **queues = new hewan *[6];    // antrian per level, index 0 tidak dipakai
    int qcount[6] = {0, 0, 0, 0, 0, 0}; // hitung berapa elemen di tiap queue

    for (int i = 1; i <= 5; ++i) // alok ruang untuk tiap queue sebanyak n (paling aman)
    {
        queues[i] = new hewan[n]; // tiap queue adalah array hewan ukuran n
    }

    // Masukkan setiap pasien ke queue sesuai tingkat daruratnya
    for (int i = 0; i < n; ++i)
    {
        int lvl = hewans[i].darurat; // ambil tingkat darurat pasien i
        if (lvl < 1)                 // jaga-jaga kalau input kurang dari 1
            lvl = 1;
        if (lvl > 5) // jaga-jaga kalau input lebih dari 5
            lvl = 5;
        queues[lvl][qcount[lvl]++] = hewans[i]; // enqueue: simpan di queue dan increment count
    }

    hewan *stack = new hewan[n]; // buat stack sederhana untuk demo
    int top = 0;                 // pointer top

    cout << "\n-Daftar Pasien-\n"; // header tampilan daftar pasien
    int idx = 1;                   // nomor urut tampilan

    // Print mulai dari level darurat 5 sampai 1
    for (int lvl = 5; lvl >= 1; --lvl)
    {
        for (int j = 0; j < qcount[lvl]; ++j) // untuk tiap elemen di queue level lvl
        {
            hewan p = queues[lvl][j];                                                               // ambil pasien dari queue
            cout << "Nama: " << p.nama << " umur: " << p.umur << " Darurat: " << p.darurat << "\n"; // nampilin data
            stack[top++] = p;                                                                       // push ke stack
            ++idx;                                                                                  // naikin nomor urut
        }
    }

    cout << "\nSelesai.\n"; // yeee siap no 1
    return 0;
}