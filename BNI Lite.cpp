// Header
#include <iostream>
#include <stdlib.h>
#include <conio.h>

// Fungsi
using namespace std;
// deklarasi tipe data variabel
int norek, isi, tr;

// pengimplementasian materi struct
struct node
{
    // deklarasi tipe data variabel
    int nomor_rekening;
    string nama;
    string alamat;
    int saldo;
    struct node *next;
}
    // pengimplementasian materi pointer
    *front = NULL,
    *rear, *temp;
// pengimplementasian materi fungsi (untuk menu input data)
void ins()
{
    temp = new node;
    string asal;
    string n;
    cout << " Masukan no.rekening\t: ";
    cin >> norek;
    cin.ignore(1, '\n');
    cout << " Masukan nama\t\t: ";
    getline(cin, n);
    cout << " Masukan alamat\t\t: ";
    getline(cin, asal);
    cout << " Masukan saldo awal\t: ";
    cin >> isi;
    temp->nomor_rekening = norek;
    temp->nama = n;
    temp->saldo = isi;
    temp->next = NULL;

    if (front == NULL)
        front = rear = temp;
    else
    {
        rear->next = temp;
        rear = temp;
    }
}
// pengimplementasian materi fungsi (untuk menu penghapusan data)
void del()
{
    if (front == NULL)
    {
        cout << " Belum ada nasabah!\n";
        getch();
    }
    else
    {
        temp = front;
        front = front->next;
        cout << " No.rekening " << temp->nomor_rekening << " dihapus beserta datanya\n";
        delete (temp);
        getch();
    }
}
// pengimplementasian materi fungsi (untuk menu menampilkan daftar nasabah)
void dis()
{
    if (front == NULL)
    {
        cout << " Belum ada nasabah!\n";
        getch();
    }
    else
    {
        temp = front;
        while (temp != NULL)
        {
            cout << " No.rek\t: " << temp->nomor_rekening << endl;
            cout << " Nama\t: " << temp->nama << endl;
            cout << " Saldo\t: " << temp->saldo << endl;
            cout << " ------------------------------" << endl;
            temp = temp->next;
        }
        getch();
    }
}
// penimplementasian materi fungsi (untuk menu pencarian data)
void cari()
{
    node *temp;
    temp = front;
    int caridata;
    int ketemu = 0;
    // Jika front bukan sama dengan null
    if (front != NULL)
    {
        cout << "\n Input no.rekening yang dicari\t: ";
        cin >> caridata;
        while (temp != NULL)
        {
            temp->nomor_rekening;
            if (caridata == temp->nomor_rekening)
            {
                cout << "\n\n>>>  Data Yang Anda Cari Ditemukan  <<<" << endl;
                cout << " Nama\t: " << temp->nama << endl;
                cout << " Saldo\t: " << temp->saldo << endl;
                cout << " ------------------------------" << endl;
                cout << "\n\n";
                ketemu = 1;
            }
            temp = temp->next;
        }
        if (ketemu == 0)
        {
            cout << " Data tidak ditemukan";
        }
    }
    else
        cout << " Belum ada nasabah!";
    getch();
}
// pengimplementasian materi fungsi (untuk menu transaksi)
void transaksi()
{
    node *temp;
    temp = front;
    int ketemu = 0;
    //....................
    if (front != NULL)
    {
        cout << "\n Input no.rekening\t: ";
        cin >> norek;
        cout << endl;
        while (temp != NULL)
        {
            temp->nomor_rekening;
            //..................
            if (norek == temp->nomor_rekening)
            {
            cobalagi:
                cout << " [1].Isi Saldo";
                cout << "\n [2].Tarik Tunai";
                cout << "\n Masukkan Pilihan : ";
                cin >> tr;
                if (tr == 1)
                {
                    cout << " Saldo awal\t\t: " << temp->saldo << endl;
                    cout << " Input Nominal Setoran\t: ";
                    cin >> isi;
                    temp->saldo = temp->saldo + isi;
                    cout << " Total saldo\t\t: " << temp->saldo << endl;
                    cout << " ------------------------------" << endl;
                    cout << "\n";
                    ketemu = 1;
                }
                else if (tr == 2)
                {
                    cout << " Saldo awal\t\t: " << temp->saldo;
                lagi:
                    cout << "\n Input jumlah penarikan\t: ";
                    cin >> isi;
                    //...................
                    if (temp->saldo < isi)
                    {
                        cout << " Maaf Saldo Anda Kurang";
                        goto lagi;
                    }
                    else
                    {
                        temp->saldo = temp->saldo - isi;
                        cout << " Sisa saldo\t\t: " << temp->saldo << endl;
                        cout << " ------------------------------" << endl;
                        cout << "\n";
                    }
                    ketemu = 1;
                }
                else
                {
                    cout << "Pilihan Salah!\n";
                    goto cobalagi;
                }
            }
            temp = temp->next;
        }
        if (ketemu == 0)
        {
            cout << " Data tidak ditemukan";
        }
    }
    else
        cout << " Belum ada nasabah!";
    getch();
}
// pengimplementasian materi fungsi (untuk menu cek saldo)
void cek()
{
    node *temp;
    temp = front;
    int ketemu = 0;
    //.......................
    if (front != NULL)
    {
        cout << "\n Input no rekening\t: ";
        cin >> norek;
        while (temp != NULL)
        {
            temp->nomor_rekening;
            if (norek == temp->nomor_rekening)
            {
                cout << " Sisa saldo saat ini\t: " << temp->saldo;
                ketemu = 1;
            }
            temp = temp->next;
        }
        if (ketemu == 0)
        {
            cout << " Data tidak ditemukan";
        }
    }
    else
        cout << " Belum ada nasabah!";
    getch();
}
// fungsi exit
void exit()
{
    cout << "   Terimakasih Telah Berkunjung   \n";
    cout << "                :)                \n\n";
    exit(EXIT_FAILURE); // digunakan untuk mengakhiri sebuah program
}
// fungsi utama
int main()
{
    int ch, nr, isi;
    while (1)
    {
        system("cls");
        cout << "\n\n ===============================================";
        cout << "\n|                                               |";
        cout << "\n|                 BANK BNI LITE                 |";
        cout << "\n|                                               |";
        cout << "\n ===============================================";
        cout << "\n|                     MENU                      |";
        cout << "\n ===============================================";
        cout << "\n|      [1]. Input Data Nasabah                  |";
        cout << "\n|      [2]. Hapus Data Nasabah                  |";
        cout << "\n|      [3]. Transaksi                           |";
        cout << "\n|      [4]. Cek Saldo                           |";
        cout << "\n|      [5]. Tampilkan Daftar Nasabah            |";
        cout << "\n|      [6]. Cari Data Nasabah                   |";
        cout << "\n|      [7]. Keluar                              |";
        cout << "\n ===============================================";
        cout << "\n\n Masukkan Pilihan (1-7): ";
        cin >> ch;
        cout << "\n ===============================================";
        cout << "\n";
        /*percabangan yg membandingkan isi variabel dengan beberapa nilai
        jika pproses perbandingan tsb menghasilkan true*/
        switch (ch)
        {
        case 1:
            ins();
            break;
        case 2:
            del();
            break;
        case 3:
            transaksi();
            break;
        case 4:
            cek();
            break;
        case 5:
            dis();
            break;
        case 6:
            cari();
            break;
        case 7:
            exit();
            break;
        default:
            cout << "Input salah, silahkan input ulang!(press any key)";
            getch(); // digunakan untuk membaca sebuah karakter
        }
    }
    return 0;
}