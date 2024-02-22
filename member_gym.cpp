/*
  judul : membuat program menejemen kasir member di sebuah gym 
  oleh  : rico 
  waktu : semarang, tembalang 17 februari 2024 - bertahap

  program ini menyakup 
    -pendaftaran menjadi member   sudah
    -penjadwalan pembayaran member belum
    -pemantauan waktu member  belum
    -cek data member   sudah
    -jenis keanggotaan   belum
    -penjadwalan pembayaran   belum
    -pendataan pengunjung   sudah
    -penbayaran pengunjung  belum
*/
#include<iostream> 
#include<iomanip>
#include<string>
#include<vector>//library untuk menggunakan vector untuk menyimpan data 
#include<ctime> //library untuk menampilkan waktu
using namespace std; 


//kamus 

const int MAX_MEMBER = 3;  //MAKSIMAL MEMBER

//membuat tipe data bentukan untuk formulir pengisian data 
struct formulir{

  string nama,tanggal,alamat,email, no_tlp,no_ktp;
  int berat_badan, tinggi_badan,umur,nomor_kartu; 
};

//untuk menampilkan garis pemisah agar tampilan tidak terlalu amburadul
//garis single 
void single(){
  //kamus lokal 
  int x;
  //deskripsi 
  while(x < 60 )
  {
    cout << "-";
    x = x + 1 ;
  }
    cout << endl;
}
void garis()
{
  //kamus lokal 
  int x;
  //deskripsi 
  while(x < 60 )
  {
    cout << "=";
    x = x + 1 ;
  }
    cout << endl;
}

//variabel untuk menyimpan data tanggal
int tanggal,bulan,tahun;
//vector untuk menyimpan tanggal



//fungsi untuk mengubah tanggal ke dalam bentuk string


//vector untuk menyimpan data pengunjung
vector <formulir> data_pengunjung;

int jumlah_data;


//untuk mencari data pengunjung
void cari_pengunjung( const vector<formulir>& data_pengunjung, const string &nama_pengunjung){

  //kamus lokal 
  bool terdata = false;

  //deskripsi 

  //melakukan perulangan dengan menyertakan kondisi di dalam perulangan tersebut 
  for(const auto&formulir : data_pengunjung){
    //kondisi untuk menampilkan dan mencari nama yang sesuai dengan yang di inputkan 
    if(formulir.nama == nama_pengunjung){

      cout << "Data di temukan!!" << endl; 
      cout << "nama : " << formulir.nama << endl;
      cout << "alamat : " << formulir.alamat << endl; 
      cout << "no-telpon : " << formulir.no_tlp << endl;
      terdata = true; 
      break;
    }

    if(!terdata){
      //logika jika nama yang di cari tidak terdata atau tidak ada di dalam vector
      cout << "Data tidak di temukan atas nama : " << nama_pengunjung << endl; 
      cout << "Anda tidak terdaftar !! :_( \n"; 

    }

  }

};


vector <formulir> member; //vector untuk menaruh data member


//variabel untuk inisialisasi nomor kartu member
int nomorkartu = 1;
int jumlahpendaftar = 0;
//fungsi untuk mengisi data formulir dan memasukkan data ke dalam array
void pendaftaran_member(vector<formulir>& member,formulir data,int &nomorkartu,int &jumlahpendaftar){

  //kamus lokal 
  
  //deskripsi 
  
  //mengisi data formulir pendaftaran member sesuai jumlah orang yang daftar
  cout << "DAFTAR MEMBER :) \n";
  garis();
  cout << "Masukkan Jumlah Pendaftar : "; cin >> jumlahpendaftar; cin.ignore();
  single();
  cout << "MOHON ISI DATA YANG DIMINTA !!\n";
  garis();
  for(int y = 1; y <= jumlahpendaftar; y++){
    cout << "formulir pendaftaran !! \n";
    cout << endl;
    cout << "masukkan nama : ";
    getline(cin, data.nama);
    cout << "masukkan umur : ";
    cin >> data.umur;
    cout << "masukkan berat : "; 
    cin >> data.berat_badan;
    cout << "masukkan tinggi : "; 
    cin >> data.tinggi_badan; 
    cin.ignore();//untuk mengabaikan karakter newline setelah membeca tipe data non-string
    cout << "masukkan alamat : "; 
    getline(cin, data.alamat);
    cout << "masukkan no-telpon anda : ";
    getline(cin, data.no_tlp);
    cout << "masukkan no-ktp anda : ";
    getline(cin, data.no_ktp);
    cout << "masukkan e-mail anda : ";
    getline(cin, data.email);
    single();
    cout << "INI no-kartu member anda : " << nomorkartu << endl; 
    cout << endl;
    cout << "pastikan semua sudah terisi !! " << endl;
    single();
    data.nomor_kartu = nomorkartu;
    nomorkartu++; 
    member.push_back(data);
  }
    cout << "Selamat pendaftaran berhasil!!" << endl; 
    garis();
  

}

//prsedur konversi tanggal 
//void waktu(int tgl, int bln, int thn){
  //kamus lokal 
  
  

  //deskripsi
  /*
  time_t waktusekarang = time(nullptr);

  tm *waktulokal = localtime(&waktusekarang);

  //mengkonversi waktu 
  tgl = waktulokal -> tm_mday; 
  bln = waktulokal -> tm_mon + 1;
  thn = waktulokal -> tm_year + 1900; 
  */
  

//}

//prosedur tampil waktu
void tampilwaktu(){
  auto wkt = time(nullptr);
  auto wkt_skr = *localtime(&wkt);
  cout << put_time(&wkt_skr, "%d-%m-%Y") << endl;

}


int totalharga; 
void pembayaran(int &totalharga){

  int totalpembayaran = 0; // variabel untuk menyimpan nominal pembayaran 
  
    do {
        cout << "Pembayaran saat ini " << ": ";
        int pembayaranSaatIni; //variabel untuk nominal pertama 
        cin >> pembayaranSaatIni;

        if (pembayaranSaatIni > 0) {
            totalpembayaran += pembayaranSaatIni;

            if (totalpembayaran < totalharga) {
                cout << "yahh uang kamu kurang nihh !!\n";
                cout << "uang kamu sekarang :  " << totalpembayaran << endl;
                cout << "uang kamu kurang : " << totalharga - pembayaranSaatIni << endl; 
            }
        } else {
            cout << "Pembayaran harus lebih dari 0.\n";
        }

    } while (totalpembayaran < totalharga);
  
  cout << "kembalian : " << totalpembayaran - totalharga << endl;
  cout << "transaksi berhasil :)\n";
  tampilwaktu();

}

//prosedur pemilihan jenis member 
/*

  ada 5 penawaran member
  - 1 bulan   = 445.000   
  - 3 bulan   = 385.000   
  - 6 bulan   = 325.000

*/
//array data harga
int dataharga[3] = {445000,385000,325000};
/*
int pilihan_1 = 445000; 
int pilihan_2 = 385000;
int pilihan_3 = 325000; 
*/
void harga_member(const formulir &data, int &jumlahpendaftar){

  //kamus lokal 
  int pilih;

  //deskripsi
  cout << "Daftar membership MAK GYM" << endl; 
  garis();
  cout << "pilihan 1 \n" "\t1(satu) bulan\n" "\t\t 445.000\n";
  single();
  cout << "pilihan 2 \n" "\t3(tiga) bulan\n" "\t\t 385.000\n";
  single();
  cout << "pilihan 3 \n" "\t6(enam) bulan\n" "\t\t 325.000\n";
  garis();

  cout << "Silahkan tentukan pilihan anda !!" << endl; 
  cout << "Pilih : " ; cin >> pilih;  
  //kondisi jika kita memilih dari tiga pilihan di atas 
  if(pilih == 1){
    single();
    cout << "anda memilih pilihan 1 " << endl; 
    for(const auto&data : member){
      cout << "nama : " << data.nama << endl;
      cout << "alamat : " << data.alamat << endl; 
      cout << "no-telpon : " << data.no_tlp << endl; 
    }
    cout << endl;
    cout << "harga yang harus di bayar adalah : " << endl; 
    totalharga = (dataharga[0] * jumlahpendaftar); 
    cout << "total harga : " << totalharga << endl;
    single();
    //memanggil fungsi pembayaran 
    pembayaran(totalharga);
    
  }else if(pilih == 2){

    cout << "anda memilih pilihan 2 " << endl; 
    for(const auto&data : member){
      cout << "nama : " << data.nama << endl;
      cout << "alamat : " << data.alamat << endl; 
      cout << "no-telpon : " << data.no_tlp << endl; 
    }
    cout << endl;
    cout << "berikut harga yang harus anda bayar " << endl; 
    totalharga = (dataharga[1] * jumlahpendaftar);
    cout << "total harga : " << totalharga << endl;
    single();
    //memanggil fungsi pembayaran 
    pembayaran(totalharga);

  }else if(pilih == 3){

    cout << "anda memilih pilihan 3 " << endl; 
    for(const auto&data : member){
      cout << "nama : " << data.nama << endl;
      cout << "alamat : " << data.alamat << endl; 
      cout << "no-telpon : " << data.no_tlp << endl; 
    }
    cout << endl;
    cout << "berikut harga yang harus anda bayar " << endl; 
    totalharga = (dataharga[2] * jumlahpendaftar);
    cout << "total harga : " << totalharga<< endl;
    single();
    //memanggil fungsi pembayaran 
    pembayaran(totalharga);

  }else {
    cout << "pilihan yang anda masukan tidak tersedia !!" << endl; 
    cout << "MATANE PICEK TA RA ONO BLOQ " << endl; 
  }

}


void tampildata(const formulir &data){
  
  cout << "nama : " << data.nama << endl;
  cout << "umur : " << data.umur << endl; 
  cout << "berat badan : " << data.berat_badan << endl; 
  cout << "tinggi badan : " << data.tinggi_badan << endl; 
  cout << "alamat : " << data.alamat << endl; 
  cout << "no-telpon : " << data.no_tlp << endl; 
  cout << "no-ktp : " << data.no_ktp << endl; 
  cout << "e-mail : " << data.email << endl;      
  cout << "no-kartu member : " << data.nomor_kartu << endl;   
  cout << endl; 
}
string mencarinama;
//untuk mencari nama member
void carimember( const vector<formulir>& member, string &mencarinama, const formulir &data){

  //kamus lokal 
  bool terdaftar = false; 
  string cari;
  //deskripsi
  cout << "Cek Data Member \n";
  garis(); 
  cout << "masukkan nama yang ingin di cek : ";
  getline(cin, mencarinama);
  cout << "Tunggu sebentar :)\n"; 
  single(); 
  for(const auto& data : member){
    if(data.nama.find(mencarinama) !=string::npos){
      
      cout << "Data di temukan!! \n";
      tampildata(data);
  
      terdaftar = true; 
      break;
    }

  }
  // kondisi jika tidak di temukan 
  if(!terdaftar){
    single();
    cout << "data tidak di temukan untuk nama : " << mencarinama << endl; 
    cout << "data anda tidak terdaftar!! \n";
  }

}

//membuat prosedur yang menjalankan tiga prosedur di bawah ini 
void utama(vector<formulir>& member, const formulir &data, int &nomorkartu,int &jumlahpendaftar ){
  //memanggil semua fungsi yang di butuhkan  
  pendaftaran_member(member,data,nomorkartu,jumlahpendaftar);
  harga_member(data,jumlahpendaftar);
  jumlahpendaftar = (jumlahpendaftar - jumlahpendaftar);
}

//daftar harga

int harga_kunjungan = 30000;

//prosedur untuk mengisi data jika ada pengunjung/single visit 
void pengunjung(vector <formulir>& data_pengunjung, vector<formulir>& member, const formulir &data){

  //kamus lokal 
  formulir data_kunjung;
  string daftar;
  int total_pengunjung; 

  //deskripsi 
  //penawaran masuk member atau tidak 
  cout << "HAI ANDA BELUM MEMBER \n";
  cout << "apakah anda ingin menjadi anggota member ? \n";
  cout << "-DAFTAR :)\n";
  cout << "-Tidak :( \n";
  cout << " jawaban : " ;
  cin >> daftar;
  cin.ignore();
  if(daftar == "daftar"){

    //memanggil prosedur pendaftaran member 
    //utama(member,data,nomorkartu);
   
  }else if(daftar == "tidak"){
    //mengisi data formulir pendaftaran member berdasarkan berapa orang yang berkunjung
    cout << "Form pengunjung \n";
    cout << "masukkan total pengunjung : "; cin >> total_pengunjung;
    
    for(int x = 1;x <= total_pengunjung; x++){

      cout << "MOHON ISI DATA YANG DIMINTA !!\n";
      garis();
      cout << "masukkan nama pengunjung ke : ";
      getline(cin, data_kunjung.nama);
      cout << "masukkan alamat : "; 
      getline(cin, data_kunjung.alamat);
      cout << "masukkan no-telpon anda : ";
      getline(cin, data_kunjung.no_tlp);
      data_pengunjung.push_back(data_kunjung);
      garis();

    }
    int total_tagihan = (harga_kunjungan*total_pengunjung);
    cout << "harga kunjungan per-orang : " << harga_kunjungan << endl;
    cout << "total tagihan anda : " << total_tagihan << endl; 
    pembayaran(total_tagihan);


    }
  else{
   
    cout << "pilihane ra ono cok!!\n";
    cout << "MATANE PICEK TA, ISO NDELOK PO ORA!!!\n";
  }
  

}




//deksripsi 
int main(){

  formulir data;  
  while (true){

    string pilihan;
    //variabel yang diunakan untuk parameter pencarian member dan pengunjung 
    string nama_pengunjung;
    string memilih; 
    //memanggil prosedur pembukaan 
    garis();
    cout << "SELAMAT DATANG DI MAK GYM :) \n";
    garis();
    cout << "Silahkan Pilih Program Yang Kamu Ingin :) \n";
    single();
    cout << "-MEMBER \n";
    cout << "-PENGUNJUNG \n";
    single();
    cout << "-KELUAR <-- \n";
    cout << "Masukan Pilihan Anda : ";
    cin >> pilihan;cin.ignore();
    cout << endl;
    //kondisi jika memilih program member 
    if(pilihan == "member"){
     
        //kamus lokal 
        string input,mencari;
      //melakukan perulangan pilihan member ini 
        while(true){
      
          //deskripsi 
          single();
          cout << "Selamat Datang Di MAK GYM!! :)" << endl; 
          single();
          cout << "Menu : \n";
          single();
          cout << "-Cek Anggota Member \n" "-Daftar Keanggotaan Member \n" "-Lihat Data Keanggotaan\n" "-Kembali Menu Awal \n"; 
          cout << "Masukkan pilihan : "; cin >> input; cin.ignore();
          garis();

            //kondisi untuk ketiga pilihan tersebut 
            if(input == "cek"){
                carimember(member,mencarinama,data);
                garis();
          
              }else if(input == "daftar"){
                
                  garis();
                  utama(member,data,nomorkartu,jumlahpendaftar);
                  garis();

              
                }else if(input == "lihat" ){
                
                    garis();
                    cout << "Daftar Keanggotaan Member MAK GYM !! \n";
                    single();
                      for(const auto &data : member){
                        tampildata(data);
                      }
                    garis();
                  }else if(input == "kembali"){
                      
                    break;

                  }
            else{
              cout << "Pilihan Tidak Tersedia" << endl; 
              cout << "WOI COK MATANE DELOK EN RA ONO COK !!!" << endl; 
            }          
        }        
      }else if(pilihan == "pengunjung"){
        cout << "Data pengunjung MAK GYM" << endl; 
        cout << "MENU : \n" "masuk\n" "keluar\n";
        cout << "pilih : "; cin >> memilih; 
        cin.ignore();
        //kondisi untuk menjalankan menu di atas tersebut 
      
          if(memilih == "masuk"){
            //memanggil prosedur pengunjung 
            pengunjung(data_pengunjung,member,data);

          }else if(memilih == "keluar"){
              cout << "Cek data pengunjung" << endl; 
              garis();
              cout << "Masukkan nama pengunjung : " ;
              getline(cin, nama_pengunjung);
              cout << "tunggu sebentar!!" << endl;
              cari_pengunjung(data_pengunjung, nama_pengunjung);
            }
          else{
            cout << "PILIHAN YANG ANDA MASUKKAN TIDAK ADA!!\n";
            cout << "goblok ta COK, wes ngerti ra ono malah di pilih tolol \n"; 
          }
        }else if(pilihan == "keluar"){
          break;
          }
      else{

        cout << "PILIHAN YANG ANDA MASUKKAN TIDAK ADA!!\n";
      }    

  }
  
  return 0; 
  
}