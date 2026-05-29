#include <iostream>
#include <fstream>
using namespace std;

string namaTugas[100];
string mataKuliah[100];
string deadline[100];
string status[100];

int jumlahTugas = 0;

void tambahTugas() {

    cin.ignore();

    cout << "\n=== TAMBAH TUGAS ===" << endl;

    cout << "Nama Tugas : ";
    getline(cin, namaTugas[jumlahTugas]);

    cout << "Mata Kuliah : ";
    getline(cin, mataKuliah[jumlahTugas]);

    cout << "Deadline : ";
    getline(cin, deadline[jumlahTugas]);

    status[jumlahTugas] = "Aktif";

    jumlahTugas++;

    cout << "\nTugas berhasil ditambahkan!\n";
}

void lihatTugas() {

    cout << "\n=== DAFTAR TUGAS AKTIF ===" << endl;

    for (int i = 0; i < jumlahTugas; i++) {

        if (status[i] == "Aktif") {

            cout << "\nTugas ke-" << i + 1 << endl;
            cout << "Nama Tugas : " << namaTugas[i] << endl;
            cout << "Mata Kuliah: " << mataKuliah[i] << endl;
            cout << "Deadline   : " << deadline[i] << endl;
        }
    }
}

void hapusTugas() {

    int hapus;

    lihatTugas();

    cout << "\nNomor tugas yang ingin dihapus : ";
    cin >> hapus;

    if (hapus > 0 && hapus <= jumlahTugas) {

        status[hapus - 1] = "Dihapus";

        cout << "\nTugas berhasil dihapus!\n";
    }

    else {

        cout << "\nNomor tidak valid!\n";
    }
}

void tandaiSelesai() {

    int selesai;

    lihatTugas();

    cout << "\nNomor tugas yang selesai : ";
    cin >> selesai;

    if (selesai > 0 && selesai <= jumlahTugas) {

        status[selesai - 1] = "Selesai";

        cout << "\nTugas berhasil ditandai selesai!\n";
    }

    else {

        cout << "\nNomor tidak valid!\n";
    }
}

void lihatRiwayat() {

    cout << "\n=== RIWAYAT TUGAS SELESAI ===" << endl;

    for (int i = 0; i < jumlahTugas; i++) {

        if (status[i] == "Selesai") {

            cout << "\nTugas ke-" << i + 1 << endl;
            cout << "Nama Tugas : " << namaTugas[i] << endl;
            cout << "Mata Kuliah: " << mataKuliah[i] << endl;
            cout << "Deadline   : " << deadline[i] << endl;
        }
    }
}

void simpanFile() {

    ofstream file("FileTugas.txt");

    file << "=== DAFTAR TUGAS ===" << endl;

    for (int i = 0; i < jumlahTugas; i++) {

        file << "\nTugas ke-" << i + 1 << endl;
        file << "Nama Tugas : " << namaTugas[i] << endl;
        file << "Mata Kuliah: " << mataKuliah[i] << endl;
        file << "Deadline   : " << deadline[i] << endl;
        file << "Status     : " << status[i] << endl;
    }

    file.close();

    cout << "\nData berhasil disimpan ke file!\n";
}

int main() {

    string username, password;
    string userInput, passInput;

    int pilihan;

    cout << "TASKKU (Manajemen Tugas Harian)" << endl;
    cout << "\n=== BUAT AKUN TASKKU ===" << endl;

    cout << "Username : ";
    cin >> username;

    cout << "Password : ";
    cin >> password;

    cout << "\nAkun berhasil dibuat!\n";

    cout << "\n=== LOGIN AKUN TASKKU ===" << endl;

    cout << "Username : ";
    cin >> userInput;

    cout << "Password : ";
    cin >> passInput;

    if (userInput == username && passInput == password) {

        cout << "\nLogin berhasil!\n";

        do {

            cout << "\n=== MENU ===" << endl;
            cout << "1. Tambah Tugas" << endl;
            cout << "2. Lihat Tugas Aktif" << endl;
            cout << "3. Hapus Tugas" << endl;
            cout << "4. Tandai Tugas Selesai" << endl;
            cout << "5. Lihat Riwayat Tugas" << endl;
            cout << "6. Simpan ke File" << endl;
            cout << "7. Keluar" << endl;
            cout << "Pilih Menu : ";
            cin >> pilihan;

            if (pilihan == 1) {

                tambahTugas();
            }

            else if (pilihan == 2) {

                lihatTugas();
            }

            else if (pilihan == 3) {

                hapusTugas();
            }

            else if (pilihan == 4) {

                tandaiSelesai();
            }

            else if (pilihan == 5) {

                lihatRiwayat();
            }

            else if (pilihan == 6) {

                simpanFile();
            }

            else if (pilihan == 7) {

                cout << "\nProgram selesai.\n";
            }

            else {

                cout << "\nPilihan tidak valid!\n";
            }

        } while (pilihan != 7);
    }

    else {

        cout << "\nLogin gagal!\n";
    }

    return 0;
}