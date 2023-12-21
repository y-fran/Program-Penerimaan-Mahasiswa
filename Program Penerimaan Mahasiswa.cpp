#include <iostream>
#include <string>
#include <algorithm>
#include <queue>


using namespace std;



struct Mahasiswa {
    string nama;
    int skor[7];
    int totalSkor;
};



int hitungTotalSkor(Mahasiswa& mahasiswa) {
    int total = 0;
    for (int i = 0; i < 7; ++i) {
        total += mahasiswa.skor[i];
    }
    return total;
}


bool lulus(Mahasiswa& mahasiswa) {
    return hitungTotalSkor(mahasiswa) > 600;
}




// Sorting 
bool perbandinganSkor(const Mahasiswa& a, const Mahasiswa& b) {
    return a.totalSkor > b.totalSkor;
}

int cariMahasiswa(const Mahasiswa* mahasiswa, int jumlah, const string& nama) {
    for (int i = 0; i < jumlah; ++i) {
        if (mahasiswa[i].nama == nama) {
            return i;
        }
    }
    return -1;
}



int main() {
	cout << "====================" << endl;
	cout << "Penerimaan Mahasiswa" << endl;
	cout << "====================" << endl;
	
	cout << "| 1. Matematika      | " << endl;
	cout << "| 2. Biologi         |" << endl;
	cout << "| 3. B.inggris       |" << endl;
	cout << "| 4. B.Indonesia     |" << endl;
	cout << "| 5. Kewarganegaraan |" << endl;
	cout << "| 6. Fisika          |" << endl;
	cout << "| 7. kimia           |" << endl;
	
	
    const int jumlahMahasiswa = 3;
    Mahasiswa mahasiswa[jumlahMahasiswa];
    queue<Mahasiswa> mahasiswaQueue;

    for (int i = 0; i < jumlahMahasiswa; ++i) {
        cout << "Masukkan nama mahasiswa " << i + 1 << ": ";
        getline(cin, mahasiswa[i].nama);
        cout << "Masukkan skor untuk 7 mata pelajaran:\n";
        for (int j = 0; j < 7; ++j) {
            cout << "Skor " << j + 1 << ": ";
            cin >> mahasiswa[i].skor[j];
        }
        
        

        mahasiswa[i].totalSkor = hitungTotalSkor(mahasiswa[i]);
        cin.ignore();

        mahasiswaQueue.push(mahasiswa[i]); 
    }



    sort(mahasiswa, mahasiswa + jumlahMahasiswa, perbandinganSkor);
    
    

    // Output mahasiswa yang lulus gesyakkkk
    cout << "\nMahasiswa yang lulus:\n";
    for (int i = 0; i < jumlahMahasiswa; ++i) {
        if (lulus(mahasiswa[i])) {
            cout << mahasiswa[i].nama << " - Total Skor: " << mahasiswa[i].totalSkor << "\n";
        }
    }




    //  queue
    cout << "\nSkor Mahasiswa\n";
    while (!mahasiswaQueue.empty()) {
        Mahasiswa frontStudent = mahasiswaQueue.front(); 
        cout << frontStudent.nama << " - Total Skor: " << frontStudent.totalSkor << "\n";
        mahasiswaQueue.pop(); 
    }




    // Searching 
    string namaCari;
    cout << "\nCari mahasiswa berdasarkan nama: ";
    getline(cin, namaCari);
    int indeks = cariMahasiswa(mahasiswa, jumlahMahasiswa, namaCari);
    if (indeks != -1) {
        cout << "Mahasiswa ditemukan - Total Skor: " << mahasiswa[indeks].totalSkor << "\n";
    } else {
        cout << "Mahasiswa tidak ditemukan.\n";
    }

    return 0;
}
