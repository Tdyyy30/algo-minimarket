#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main() {
    const int MAX = 50;
    string nama[MAX];
    int qty[MAX];
    long long harga[MAX], sub[MAX];

    int n;
    cout << "=== KASIR MINIMARKET ===\nJumlah item (1-" << MAX << "): ";
    cin >> n;
    if (n < 1 || n > MAX) return cout << "Jumlah item tidak valid.\n", 0;

    long long total = 0;
    for (int i = 0; i < n; i++) {
        cout << "\nItem ke-" << i + 1 << "\nNama barang : ";
        cin >> ws; getline(cin, nama[i]);
        cout << "Harga (Rp)  : "; cin >> harga[i];
        cout << "Qty         : "; cin >> qty[i];

        if (harga[i] < 0 || qty[i] < 0) return cout << "Input tidak boleh negatif!\n", 0;
        total += (sub[i] = harga[i] * 1LL * qty[i]);
    }

    int member, metode;
    cout << "\nMember? (1=Ya, 0=Tidak): "; cin >> member;
    cout << "Metode bayar (1=Cash, 2=QRIS, 3=Debit): "; cin >> metode;

    long long diskon = (member == 1 ? total * 5 / 100 : 0) + (total >= 200000 ? total * 10 / 100 : 0);
    long long pajak  = total * 11 / 100;
    long long grand  = total + pajak - diskon;

    cout << "\n========== STRUK ==========\n";
    cout << left << setw(20) << "Barang" << right << setw(6) << "Qty"
         << setw(12) << "Harga" << setw(14) << "Subtotal\n";
    cout << "-----------------------------------------------\n";
    for (int i = 0; i < n; i++)
        cout << left << setw(20) << nama[i]
             << right << setw(6) << qty[i]
             << setw(12) << harga[i]
             << setw(14) << sub[i] << "\n";
    cout << "-----------------------------------------------\n";
    cout << left << setw(20) << "Total"       << right << setw(32) << total  << "\n";
    cout << left << setw(20) << "Pajak 11%"   << right << setw(32) << pajak  << "\n";
    cout << left << setw(20) << "Diskon"      << right << setw(32) << diskon << "\n";
    cout << left << setw(20) << "Grand Total" << right << setw(32) << grand  << "\n";

    const char* bayarTxt = (metode==1 ? "CASH" : metode==2 ? "QRIS" : metode==3 ? "DEBIT" : "(metode tidak dikenal)");
    cout << "Pembayaran: " << bayarTxt << "\n";

    if (metode == 1) {
        long long bayar;
        cout << "Uang bayar (Rp): "; cin >> bayar;
        if (bayar < grand) return cout << "Uang kurang!\n", 0;
        cout << "Kembalian (Rp): " << (bayar - grand) << "\n";
    } else {
        cout << "Silakan proses pembayaran non-cash.\n";
    }

    cout << "Terima kasih!\n";
    return 0;
}