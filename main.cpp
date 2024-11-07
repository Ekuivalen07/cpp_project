#include <iostream>
#include <string>
#include <vector> // Untuk menggunakan vektor (array dinamis)
#include <limits> // Untuk mendapatkan nilai batas dari tipe data
#include <ctime>

using namespace std;

// Fungsi untuk menunda eksekusi // lab 4
void delay(int milliseconds) {
    clock_t start_time = clock();
    while (clock() < start_time + milliseconds);
}

// Fungsi untuk membersihkan layar
void clear() {
    cout << "\033[2J\033[1;1H";
}


// Fungsi untuk menunggu pengguna sebelum melanjutkan
void pause() {
    cout << "Tekan enter untuk melanjutkan...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

// Struct untuk menyimpan data pengguna
struct User {
    string name;
    int age;
    string email;
};

// Fungsi untuk menambahkan pengguna ke database
void addUser(vector<User>& database) {
    User newUser;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Bersihkan buffer sebelum mengambil input
    cout << "Masukkan nama: ";
    getline(cin, newUser.name);
    cout << "Masukkan umur: ";
    cin >> newUser.age;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Bersihkan buffer sebelum mengambil email
    cout << "Masukkan email: ";
    getline(cin, newUser.email);
    database.push_back(newUser);
    cout << "Pengguna berhasil ditambahkan!\n";
    pause(); // Tunggu sebelum kembali ke menu
}

// Fungsi untuk menampilkan semua pengguna di database
void displayUsers(const vector<User>& database) {
    cout << "Debug: Memasuki fungsi displayUsers\n"; // Debugging tambahan
    if (database.empty()) {
        cout << "Database kosong!\n";
    } else {
        cout << "Daftar Pengguna:\n";
        for (const auto& user : database) {
            cout << "Nama: " << user.name << ", Umur: " << user.age << ", Email: " << user.email << '\n';
        }
    }
    pause(); // Tunggu sebelum kembali ke menu
}

// Fungsi untuk mencari pengguna berdasarkan nama
void searchUser(const vector<User>& database) {
    string name;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Bersihkan buffer sebelum mengambil nama
    cout << "Masukkan nama pengguna yang dicari: ";
    getline(cin, name);

    bool found = false;
    for (const auto& user : database) {
        if (user.name == name) {
            cout << "Pengguna ditemukan: Nama: " << user.name << ", Umur: " << user.age << ", Email: " << user.email << '\n';
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Pengguna dengan nama " << name << " tidak ditemukan.\n";
    }
    pause(); // Tunggu sebelum kembali ke menu
}

// Fungsi untuk login // lab 1 Variable
void login() {
    bool isLogged = false;
    cout << "==================================" << endl;
    cout << "============Login Gate============" << endl;
    cout << "==================================" << endl << endl;
    // lab 3 while
    while (!isLogged) {
        string user, pwd;
        cout << "Masukkan username: ";
        cin >> user;
        cout << "\nMasukkan password: ";
        cin >> pwd;
        // lab 2 if nested
        if (user == "admin") {
            if (pwd == "admin") {
                isLogged = true;
                cout << "\nMencari kredensial";
                delay(3000);
                clear();
                cout << "\e[42mLogged in as Admin!\033[0m" << endl << endl;
            } else {
                cout << "\e[41mPassword salah!\033[0m" << endl;
            }
        } else {
            cout << "\e[41mUsername salah!\033[0m" << endl;
        }
    }
}

// Fungsi untuk menampilkan menu dan mengelola tindakan pengguna
void menu(vector<User>& database) {
    int choice;

    do {
        clear();
        cout << "Selamat Datang, Admin!" << endl << endl;
        cout << "1. Tambah Pengguna\n";
        cout << "2. Tampilkan Pengguna\n";
        cout << "3. Cari Pengguna\n";
        cout << "4. Keluar\n";
        cout << "Pilih opsi (1-4): ";
        cin >> choice;

        switch (choice) {
            case 1:
                addUser(database);
                break;
            case 2:
                displayUsers(database);
                break;
            case 3:
                searchUser(database);
                break;
            case 4:
                cout << "Keluar dari program. Terima kasih!\n";
                break;
            default:
                cout << "\e[41mERROR! Pilihan tidak valid!\033[0m\n";
                pause(); // Tunggu sebelum kembali ke menu
                break;
        }
    } while (choice != 4);
}

// Fungsi utama
int main() {
    vector<User> database;
    login();  // Panggil fungsi login terlebih dahulu
    menu(database);  // Tampilkan menu setelah login
    return 0;
}
