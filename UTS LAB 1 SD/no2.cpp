// Arya Sona Ginting
// 241401100

#include <iostream>
#include <string> // biar bisa pakai tipe data string
using namespace std;

struct Node
{
    string judul; // judul film
    int tahun;    // tahun rilis film
    int rating;   // rating film (1–10)
    Node *next;   // penunjuk ke film berikutnya

    // constructor untuk mengisi data langsung saat node dibuat
    Node(string j, int t, int r) : judul(j), tahun(t), rating(r), next(nullptr) {}
};

int main()
{
    int n;
    cout << "Masukkan jumlah film: "; // nanya berapa film yang mau ditambah
    if (!(cin >> n))                  // kalau input bukan angka, program berhenti
        return 0;
    cin.ignore(); // hapus enter sisa input sebelumnya

    Node *head = nullptr; // penunjuk ke film pertama
    Node *tail = nullptr; // penunjuk ke film terakhir

    // perulangan untuk input data film
    for (int i = 0; i < n; i++)
    {
        string judul;
        int tahun, rating;

        cout << "\nJudul : ";
        getline(cin, judul); // input nama film
        cout << "Tahun : ";
        cin >> tahun; // input tahun rilis
        cout << "Rating: ";
        cin >> rating; // input rating film
        cin.ignore();  // hapus enter biar input selanjutnya aman

        Node *p = new Node(judul, tahun, rating); // buat node baru

        if (!head) // kalau belum ada film, jadikan head & tail
            head = tail = p;
        else // kalau sudah ada, taruh di akhir daftar
        {
            tail->next = p;
            tail = p;
        }
    }

    cout << "\nBerapa banyak film yang sudah ditonton? ";
    int m;
    cin >> m; // input jumlah film yang mau dihapus
    cin.ignore();

    // proses penghapusan film yang sudah ditonton
    for (int i = 0; i < m; i++)
    {
        cout << "Masukkan judul film yang sudah ditonton: ";
        string target;
        getline(cin, target); // input judul film yang mau dihapus

        if (!head) // kalau daftar kosong
        {
            cout << "Daftar kosong.\n";
            continue;
        }

        // kalau film pertama yang mau dihapus
        if (head->judul == target)
        {
            Node *t = head;
            head = head->next; // geser head ke film berikutnya
            delete t;          // hapus node lama
            cout << "Dihapus: " << target << "\n";
            continue;
        }

        Node *prev = head;      // simpan node sebelumnya
        Node *cur = head->next; // node yang sedang dicek
        bool found = false;     // penanda kalau film ketemu

        // cari film dalam daftar
        while (cur)
        {
            if (cur->judul == target) // kalau judul cocok
            {
                prev->next = cur->next; // lewati node ini
                if (cur == tail)        // kalau yang dihapus adalah film terakhir
                    tail = prev;
                delete cur; // hapus film dari memori
                cout << "Dihapus: " << target << "\n";
                found = true;
                break;
            }
            prev = cur; // pindah ke node berikutnya
            cur = cur->next;
        }

        if (!found) // kalau gak ketemu
            cout << "Error: \"" << target << "\" tidak ditemukan.\n";
    }

    // nampilin sisa film yang belum ditonton
    cout << "\n=== Film yang belum ditonton ===\n";
    for (Node *p = head; p; p = p->next)
        cout << "- " << p->judul << " (" << p->tahun << ") rating " << p->rating << "\n";

    // hapus semua node dari memori (biar gak bocor)
    while (head)
    {
        Node *t = head;
        head = head->next;
        delete t;
    }

    return 0; // siap no 2 :) capek euy
}