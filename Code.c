#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Max_BOOKING 100

// Struktur data pasien
struct pasien {
    char nama[100];
    char username[100];
    char pass[100];
}data;

FILE *filepasien;
FILE *keluh;
FILE *lihat;

// Deklarasi fungsi
void loginpasien();
void regispasien();
void menupasien();
void viewpasien();
void checkup();
void alasan();
void jadwalKonsultasi();
void book();
void tengok();
void admin();

int main() {
    
    int pilihan;
    printf("\n====================== SiKuk =========================\n");
    printf("\n============= Sikat Pegal Dengan Kusuk ====================\n");
    printf("\n== Selamat Datang Di Aplikasi Refleksi Pijat =========\n");
    printf("\n====================== SiKuk ====================\n");
    printf("1. Log In\n");
    printf("2. Sign Up\n");
    printf("3. Admin Only\n");
    printf("Pilihan anda : ");
    scanf("%d", &pilihan);
    
    // Membersihkan buffer stdin
    fflush(stdin); 

    switch (pilihan) {
        case 1:
            loginpasien();
            break;
        case 2:
            regispasien();
            break;
        case 3:
            admin();
            break;
        default:
            printf("Pilihan anda tidak valid, silahkan pilih menu yang tersedia");
            break;
    }
    return 0;
    system("cls");
}

void regispasien() {
    system("cls"); // Membersihkan layar di lingkungan Windows
    struct pasien datapasien;
    char opsi[5];


    filepasien = fopen("akunpasien.dat", "ab");
    printf("\n=======================================================\n");
    printf("\n==== Sign Up ====\n");
    fflush(stdin);
    printf("Masukkan nama anda : ");
    gets(datapasien.nama);
    fflush(stdin);
    printf("Buat Username : ");
    gets(datapasien.username);
    fflush(stdin);
    printf("Buat Password : ");
    gets(datapasien.pass);

    fwrite(&datapasien, sizeof(datapasien), 1, filepasien);

    printf("Anda sudah melakukan Sign up\n");

    printf("Apakah anda ingin Log In sekarang? (y/n): ");
    fgets(opsi, 5, stdin);
    opsi[strcspn(opsi, "\n")] = 0;
    if (strcmp(opsi, "y") == 0) {
        fclose(filepasien);
        loginpasien();
    } else {
        printf("Silakan log in nanti.\n");
        main();
    }

    fclose(filepasien);
}

void loginpasien() {
    struct pasien datapasien, temp;

    system("cls"); // Membersihkan layar di lingkungan Windows

    int repeat;
    for (repeat = 3; repeat > 0; repeat--) {
        filepasien = fopen("akunpasien.dat", "rb");
        printf("\n=======================================================\n");
        printf("\n==== Log In ====\n");
        fflush(stdin);
        printf("Masukkan Username : ");
        gets(datapasien.username);
        fflush(stdin);
        printf("Masukkan Password : ");
        gets(datapasien.pass);

        int found = 0;
        while (fread(&temp, sizeof(temp), 1, filepasien)) {
            if (strcmp(temp.username, datapasien.username) == 0 && strcmp(temp.pass, datapasien.pass) == 0) {
                found = 1;
                break;
            }
        }

        if (found) {
            printf("Anda berhasil log in, silahkan melanjutkan ke menu utama.\n");
            fclose(filepasien);
            menupasien();
            return;
        } else {
            if (repeat > 1) {
                printf("Username atau Password salah\n");
                printf("Tersisa %d kesempatan lagi\n\n", repeat - 1);
            } else {
                printf("Anda sudah tidak dapat login kembali\n");
                fclose(filepasien);
            }
        }
    }
}
void admin() {
    system("cls");

    int repeat;
    char username[100];
    char pass[100];

    for (repeat = 3; repeat > 0; repeat--) { 
        printf("\n==== Selamat Datang! ====\n");
        printf("Username : ");
        fgets(username, sizeof(username), stdin);
        username[strcspn(username, "\n")] = 0;
        printf("Password : ");
        fgets(pass, sizeof(pass), stdin);
        pass[strcspn(pass, "\n")] = 0;
        if (strcmp(username, "saya") == 0 && strcmp(pass, "bewok123") == 0) {
            printf("Anda berhasil login, Selamat Datang.\n"); 
            tengok();
        } else {
            printf("Username atau Password salah\n");
            if (repeat > 1) {
                printf("Tersisa %d kesempatan lagi\n\n", repeat - 1);
            } else {
                printf("Anda sudah tidak dapat login kembali\n");
            }
        }
    }
    main();
}
void menupasien() {

    system("cls");

    int menu;
    printf("\n=======================================================\n");
    printf("\n=== Selamat datang ===\n");
    printf("\n=== Menu Utama ===\n");
    printf("\nSilahkan pilih menu : \n");
    printf("1. Checkup Fisik\n");
    printf("2. Booking Jadwal Kusuk\n");
    printf("3. Cek Jadwal Yang Tersedia\n");
    printf("4. Lihat daftar booking\n");
    printf("5. Keluar\n");

    printf("Menu : ");
    scanf("%d", &menu);
    fflush(stdin); // Membersihkan buffer sebelum mengambil input berikutnya

    switch (menu) {
        case 1:
            checkup();
            break;
        case 2:
            alasan();
            break;
        case 3:
            jadwalKonsultasi();
            break;
        case 4:
            book();
            break;
        case 5:
            printf("Terima Kasih Telah Menggunakan Layanan Kami\n");
            printf("Sampai Jumpa Kembali");
            exit(0);
            break;
        default:
            printf("Pilihan tidak valid.\n");
            break;
    }
}

void checkup(){
    system("cls");
    int a,b,c,d,e,f,g,h,i;
    int total = 0;

    printf("Selamat datang! Silahkan jawab pertanyaan berikut sesuai keluhan anda\n");
    printf("\nApakah anda mengalami Pegal?\n1. Ya\n2. Tidak\n");
    printf("Pilih jawaban : ");
    scanf("%d", &a);
    if (a==1)
    {
        printf("\nSejak Kapan anda merasa pegal?\n1. 1-3 hari\n2. 3-5 hari\n3. Lebih dari 5 hari\n");
        printf("Pilih jawaban : ");
        scanf("%d", &b);
        if (b==1)
        {
            total = total + 5;
        } else if (b==2){
            total = total + 10;
        } else {
            total = total + 15;
        }

        printf("\nDibagian mana anda merasakan pegal?\n1. Sebagian kepala hingga pinggang\n2. seluruh bagian tubuh\n");
            printf("Pilih jawaban : ");
            scanf("%d", &c);
            if (c==2)
            {
                total = total + 5;
            }
    }

    printf("\nApakah anda pernah mengalami patah tulang ?\n1. Ya\n2. Tidak\n");
    printf("Pilih jawaban : ");
    scanf("%d", &d);
    if (d==1)
    {
        printf("\nSudah berapa lama?\n1. Kurang dari setahun\n2. 1-3tahun\n3. Lebih dari 3 tahun\n");
        printf("Pilih jawaban : ");
        scanf("%d", &e);
        if (e==1)
        {
            total = total + 5;
        }
        else if (e==2)
        {
            total = total + 10;
        }
        else
        {
            total = total + 15;
        }

        printf("\nApakah anda yakin untuk tetap dikusuk?\n1. ya\n2. tidak\n");
        printf("Pilih jawaban : ");
        scanf("%d", &f);
        if (f==1)
        {
            total = total + 10;
        }
    }

    printf("\nApakah anda merasakan sakit pinggang?\n1. Ya\n2. Tidak\n");
    printf("Pilih jawaban : ");
    scanf("%d", &g);
    if (g==1)
    {
        total = total + 5;
    }

    printf("\nApakah anda mengalami sakit dibagian punggung?\n1. Ya\n2. Tidak\n");
    printf("Pilih jawaban : ");
    scanf("%d", &h);
    if (h==1)
    {
        total = total + 5;
    }

    printf("\nApakah anda mengalami kram setelah kejadian?\n1. Ya\n2. Tidak\n");
    printf("Pilih jawaban : ");
    scanf("%d", &i);
    if (i==1)
    {
        total = total + 5;
    }

    printf("\n\n");

    if (total<=20){
        printf("Sepertinya gejala tersebut masih bisa diatasi dengan obat rumahan, seperti diolesi balsem ataupun kerok\n");
    } else if (total > 20 && total <=40){
        printf("Anda seharusnya segera untuk dikusuk, dikhawatirkan bisa menghambat aktifitas harian karena nyeri yang dirasakan.");
    } else {
        printf("Sepertinya anda tidak perlu dikusuk, khawatir ada permasalahan pada bagian tulang,"); 
        printf("sehendaknya anda melakukan checkup ke medis, jika semakin parah, maka segera lakukan operasi!!");
    }

    printf("\n\n");

    if (f==1 && g==1 && i==1)
    {
        printf("Namun dikhawatirkan, anda mengalami permasalahan serius pada tulang anda!!!\n");
    }
    
    printf("\n\n");
    system("pause");

    menupasien();
}void alasan() {
    char jawaban[100];
    char pilih[3];
    FILE *keluh;

    keluh = fopen("booking.dat", "ab");
    if (keluh == NULL) {
        printf("Gagal.\n");
        return alasan();
    }
    printf("\n=======================================================\n");
    printf("Booking Jadwal Anda Dengan Format(Hari/NamaAnda/Jam) >_<\n");
    printf("\n=======================================================\n");
    
    // Membersihkan buffer sebelum mengambil input
    fflush(stdin);

    // Menggunakan gets untuk mengambil input
    gets(jawaban);

    fwrite(&jawaban, sizeof(jawaban), 1, keluh);

    printf("Pesanan anda telah diterima dan sedang diproses\n");
    printf("Terima Kasih Telah Menggunakan Layanan Kami\n");

    printf("Apakah anda ingin Kembali Ke Menu sekarang? (y/n): ");
    fflush(stdin); // Membersihkan buffer lagi sebelum mengambil input berikutnya
    gets(pilih);
    if (strcmp(pilih, "y") == 0) {
        fclose(keluh);
        menupasien();
    } else {
        printf("Baiklah.\n");
        fclose(keluh);
        alasan();
    }
}

void jadwalKonsultasi() {
    int hari;

    do {
        printf("Pilih hari Refleksi Kusuk (1-7) atau 0 untuk kembali ke menu utama:\n");
        printf("1. Ahad\n");
        printf("2. Senin\n");
        printf("3. Selasa\n");
        printf("4. Rabu\n");
        printf("5. Kamis\n");
        printf("6. Jumat\n");
        printf("7. Sabtu\n");
        printf("0. Untuk Kembali Ke Menu Utama\n");
        printf("Masukkan pilihan Anda: ");
        scanf("%d", &hari);
        fflush(stdin);

        switch (hari) {
            case 0:
                printf("Kembali ke menu utama.\n");
                return menupasien();
            case 1:
                printf("================================== Tersedia Hari Ahad ================================.\n");
                printf("================================ 15:00 WIB s/d 20:00 WIB ================================.\n");
                printf("=================================== Reiki Reflexology ================================ .\n");
                printf("=====Jl. Mekar Utama No.98, Mekarwangi, Kec. Bojongloa Kidul, Kota Bandung, Jawa Barat======.\n");
                break;
            case 2:
                printf("================================ Tersedia Hari Senin ========================= .\n");
                printf("============================== 14:00 WIB s/d 22:00 WIB ========================= .\n");
                printf("============================== Tevia'N Family Refleksi ============================.\n");
                printf("=====Jl. Mekar Utama No.1K, Mekarwangi, Kec. Bojongloa Kidul, Kota Bandung, Jawa Barat======.\n");
                break;
            case 3:
                printf("=================================== Tersedia Hari Selasa =======================================.\n");
                printf("================================= 13:00 WIB s/d 10:00 WIB =====================================.\n");
                printf("=================== De WAVE Family Massage & Reflexology Buah Batu ============================.\n");
                printf("========== Jl. Buah Batu No.252, Cijagra, Kec. Lengkong, Kota Bandung, Jawa Barat ===============.\n");
                break;
            case 4:
                printf("=================================== Tersedia Hari Rabu ===============================================.\n");
                printf("================================= 09:00 WIB s/d 17:00 WIB ===========================================.\n");
                printf("==================== KIA family Pijat massage reflexologi dan Bekam ================================.\n");
                printf("==== Jl. Babakan Leuwi Bandung, RT.02 RW01, Citeureup, Kec. Dayeuhkolot, Kabupaten Bandung, Jawa Barat =====.\n");
                break;
            case 5:
                printf("================================ Tersedia Hari Kamis ================================.\n");
                printf("============================== 12:00 WIB s/d 20:00 WIB ================================.\n");
                printf("=====================De WAVE Family Massage & Reflexology Buah Batu ===================.\n");
                printf("===== Jl. Buah Batu No.252, Cijagra, Kec. Lengkong, Kota Bandung, Jawa Barat ===========.\n");
                break;
            case 6:
                printf("================================= Tersedia Hari Jum'at ================================ .\n");
                printf("================================ 14:00 WIB s/d 20:00 WIB ================================ .\n");
                printf("================================== Reiki Reflexology ================================ .\n");
                printf("=====Jl. Mekar Utama No.98, Mekarwangi, Kec. Bojongloa Kidul, Kota Bandung, Jawa Barat======.\n");
                break;
            case 7:
                printf("================================ Tersedia Hari Sabtu ================================ .\n");
                printf("============================== 09:00 WIB s/d 12:00 WIB ================================ .\n");
                printf("============================== Tevia'N Family Refleksi ===============================.\n");
                printf("=====Jl. Mekar Utama No.1K, Mekarwangi, Kec. Bojongloa Kidul, Kota Bandung, Jawa Barat======.\n");
                break;
            default:
                printf("Pilihan hari tidak valid.\n");
        }
    } while (1); 
}void tengok() {
    system("cls");
    FILE *lihat;
    char search[100];
    data;

    printf("\n==== Cari Akun pelanggan ====\n");
    printf("Masukkan nama pelanggan yang dicari: ");
    scanf("%s", search); // Menggunakan scanf untuk membaca input

    lihat = fopen("akunpasien.dat", "rb");
    if (lihat == NULL) {
        printf("Data tidak ada!\n");
        system("pause");
        menupasien();
        return;
    }

    int found = 0;
    while (fread(&data, sizeof(data), 1, lihat)) {
        if (strcmp(data.nama, search) == 0) {   
            printf("Nama Pelanggan: %s\n", data.nama);
            printf("Username: %s\n", data.username);
            printf("Password: %s\n", data.pass);
            printf("================================================\n");
            printf("============================================\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Pelanggan dengan nama %s tidak ditemukan.\n", search);
    }

    fclose(lihat);
    system("pause");
    main();
}

void book() {
    system("cls");
    FILE *keluh;
    char jawaban[Max_BOOKING][100];
    int urut = 0;
    int i,j;

    keluh = fopen("booking.dat", "rb");
    if (keluh == NULL) {
        printf("Data Booking tidak tersedia <:(\n");
        system("pause");
        menupasien();
        return;
    }

    // Membaca semua booking dari file
    while (fread(jawaban[urut], sizeof(jawaban[urut]), 1, keluh)) {
        urut++;
        if (urut >= Max_BOOKING) break; // Membatasi jumlah booking yang dibaca
    }

    fclose(keluh);

    // Mengurutkan daftar booking secara ascending menggunakan bubble sort
    for (int i = 0; i < urut - 1; i++) {
        for (int j = 0; j < urut - i - 1; j++) {
            if (strcmp(jawaban[j], jawaban[j + 1]) > 0) {
                char temp[100];
                strcpy(temp, jawaban[j]);
                strcpy(jawaban[j], jawaban[j + 1]);
                strcpy(jawaban[j + 1], temp);
            }
        }
    }

    // Mencetak daftar booking yang sudah diurutkan
    printf("\nDaftar Booking:\n");
    for (int i = 0; i < urut; i++) {
        printf("%s\n", jawaban[i]);
    }
    printf("============================================\n");
    printf("===============================================\n");
    printf("\n");
    system("pause");
    menupasien();
}
