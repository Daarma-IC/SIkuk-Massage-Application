#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct customer {
    char nama[100], username[100], pass[100];
} datacustomer;

struct jasa {
    char nama[100];
    char deskripsi[500];
    float harga;
    int kontak;
} datajasa;

struct feedback {
    char username[100]; 
    char feedback[500];
} datafeedback;

struct order {
    char username[100];
    char serviceName[100];
    float servicePrice;
} dataorder;

#define MAX_FEEDBACK 500
#define MAX_LINES 100

char username[30], pass[30];

int loginPenjual();
int logregCustomer();
int loginCustomer();
int regisCustomer();
int menuCustomer();
int menuPenjual();

void viewCustomer();
void delCustomer();
int viewJasa();
int viewJasaC();
int addJasa();
int compare(const void *a, const void *b);
void viewJasaNoPause();
void viewFeedback();

void searchJasa();
void pesanJasa();
void addFeedback();
void changePass();
void delAcc();
void sortJasa(struct jasa *jasaList, int count);

FILE *filecustomer;
FILE *filejasa;
FILE *filefeedback;
FILE *fileOrder;

int main() {
    system("cls");

    int pilihan;
    printf("\n======= D'Frame Craft ======\n");
    printf("Pilih Kategori : \n");
    printf("1. Penjual\n");
    printf("2. Customer\n");
    printf("Pilihan anda : ");
    scanf("%d", &pilihan);
    getchar();

    switch (pilihan) {
        case 1:
            loginPenjual();
            break;
        case 2:
            logregCustomer();
            break;
        default:
            printf("Pilihan anda tidak valid, silahkan pilih menu yang tersedia");
            system("pause");
            break;
    }
    main();
}

int loginPenjual() {
    system("cls");

    int repeat;
    for (repeat = 3; repeat > 0; repeat--) { 
        printf("\n==== Selamat Datang! ====\n");
        fflush(stdin);
        printf("Username : ");
        gets(username);
        printf("Password : ");
        gets(pass);
        if (strcmp(username, "admin") == 0 && strcmp(pass, "admin123") == 0) {
            printf("Anda berhasil login, Selamat Datang.\n"); 
            menuPenjual();
        } else {
            printf("Username atau Password salah\n");
            if (repeat > 1) {
                printf("Tersisa %d kesempatan lagi\n\n", repeat - 1);
            } else {
                printf("Anda sudah tidak dapat login kembali\n");
            }
        }
    }
    return 0;
}

int logregCustomer() {
    system("cls");

    int menu;
    printf("\n=======================================================\n");
    printf("===Pilih Menu===\n");
    printf("1. Log in\n");
    printf("2. Sign Up\n");
    printf("0. Keluar\n");
    printf("Pilih menu : ");
    scanf("%d", &menu);
    getchar(); 

    switch (menu) {
        case 1:
            loginCustomer();
            break;
        case 2:
            regisCustomer();
            break;
        case 0:
            main();
            break;
        default:
            printf("Pilihan anda tidak valid, silahkan pilih menu yang tersedia\n");
            system("pause");
            logregCustomer();
    }
}

int loginCustomer() {
    system("cls");

    int repeat;
    FILE *filecustomer;
    int loginSuccess = 0;

    for (repeat = 3; repeat > 0; repeat--) {
        filecustomer = fopen("akuncustomer.dat", "rb");
        if (filecustomer == NULL) {
            printf("Error dalam membuka file!\n");
            return 0;
        }

        printf("\n=======================================================\n");
        printf("\n==== Log In ====\n");
        fflush(stdin);
        printf("Username : ");
        gets(username);
        printf("Password : ");
        gets(pass);

        while (fread(&datacustomer, sizeof(datacustomer), 1, filecustomer)) {
            if (strcmp(username, datacustomer.username) == 0 && strcmp(pass, datacustomer.pass) == 0) {
                printf("Anda berhasil log in, silahkan melanjutkan ke menu utama.\n");
                fclose(filecustomer);
                menuCustomer();
                return 0;
            }
        }

        fclose(filecustomer);

        if (repeat > 1) {
            printf("Username atau Password salah\n");
            printf("Tersisa %d kesempatan lagi\n\n", repeat - 1);
        } else {
            printf("Anda sudah tidak dapat login kembali\n");
        }
    }

    return 0;
}

int regisCustomer() {
    system("cls");
    FILE *filecustomer;

    filecustomer = fopen("akuncustomer.dat", "ab");
    if (filecustomer == NULL) {
        printf("Error dalam membuka file!\n");
        return 1;
    }

    printf("\n==== Sign Up ====\n");

    printf("Masukkan nama anda: ");
    gets(datacustomer.nama);

    printf("Buat Username: ");
    gets(datacustomer.username);

    printf("Buat Password: ");
    gets(datacustomer.pass);

    fwrite(&datacustomer, sizeof(datacustomer), 1, filecustomer);
    fclose(filecustomer);

    printf("Anda sudah melakukan Sign up\n");

    logregCustomer();
}

int menuPenjual() {
    system("cls");
    int pilih;
    printf("==== Anda telah Log in menjadi Operator ====\n");
    printf("Menu yang dapat anda akses\n");
    printf("1. Melihat akun customer.\n");
    printf("2. Hapus akun customer.\n");
    printf("3. Melihat list jasa.\n");
    printf("4. Input list jasa.\n");
    printf("5. Melihat feedback .\n");
    printf("0. Keluar.\n");
    printf("Pilihan : ");
    scanf("%d", &pilih);

    switch (pilih) {
        case 1: 
            viewCustomer();
            break;
        case 2:
            delCustomer();
            break;
        case 3: 
            viewJasa();
            break;
        case 4: 
            addJasa();
            break;
        case 5: 
            viewFeedback();
            break;
        case 0: 
            main();
            break;
        default:
            printf("Pilihan anda tidak valid");
            menuPenjual();
            break;
    }
}

int menuCustomer() {
    system("cls");
    int choice;
    do {
        printf("\n==== Menu Customer ====\n");
        printf("1. Lihat Jasa\n");
        printf("2. Pesan Jasa\n");
        printf("3. Pencarian Jasa\n");
        printf("4. Berikan Feedback\n");
        printf("5. Mengganti Password\n");
        printf("6. Menghapus Akun\n");
        printf("0. Keluar\n");
        printf("Pilihan Anda: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                viewJasaC();
                break;
            case 2:
                pesanJasa();
                break;
            case 3:
                searchJasa();
                break;
            case 4:
                addFeedback();
                break;
            case 5:
                changePass();
                break;
            case 6:
                delAcc();
                break;
            case 0:
                printf("Terima kasih telah menggunakan layanan kami.\n");
                main();
                break;
            default:
                printf("Pilihan tidak valid.\n");
                menuCustomer();
        }
    } while (choice != 6);

    return 0;
}

int viewJasaC() {
    system("cls");
    FILE *filejasa;
    struct jasa *data;
    int count = 0;
    int size = 10;

    data = (struct jasa *)malloc(size * sizeof(struct jasa));
    if (data == NULL) {
        printf("Alokasi Memori gagal!\n");
        system("pause");
        return menuCustomer();
    }

    filejasa = fopen("datajasa.dat", "rb");
    if (filejasa == NULL) {
        printf("Error dalam membuka file!\n");
        system("pause");
        free(data);
        return menuCustomer();
    }

    while (fread(&data[count], sizeof(struct jasa), 1, filejasa)) {
        count++;
        if (count >= size) {
            size *= 2;
            data = (struct jasa *)realloc(data, size * sizeof(struct jasa));
            if (data == NULL) {
                printf("Memory reallocation failed!\n");
                fclose(filejasa);
                system("pause");
                return menuCustomer();
            }
        }
    }

    fclose(filejasa);

    qsort(data, count, sizeof(struct jasa), compare);

    printf("\n==== Daftar Jasa ====\n");
    for (int i = 0; i < count; i++) {
        printf("Nama Jasa: %s\n", data[i].nama);
        printf("Deskripsi: %s\n", data[i].deskripsi);
        printf("Harga: %.2f\n", data[i].harga);
        printf("\n");
    }

    free(data);
    system("pause");
    return menuCustomer();
}

void viewCustomer() {
    system("cls");
    FILE *filecustomer;
    struct customer akunList[MAX_LINES];
    struct customer akun;
    int count = 0, i, j;

    filecustomer = fopen("akuncustomer.dat", "rb");
    if (filecustomer == NULL) {
        printf("Error dalam membuka file!\n");
        return;
    }

    while (fread(&akun, sizeof(akun), 1, filecustomer) && count < MAX_LINES) {
        akunList[count++] = akun;
    }
    fclose(filecustomer);

    // Insertion Sort
    for (i = 1; i < count; i++) {
        struct customer key = akunList[i];
        j = i - 1;

        while (j >= 0 && strcmp(akunList[j].username, key.username) > 0) {
            akunList[j + 1] = akunList[j];
            j = j - 1;
        }
        akunList[j + 1] = key;
    }

    printf("\n==== Daftar Customer ====\n");
    for (i = 0; i < count; i++) {
        printf("Username: %s\n", akunList[i].username);
        printf("\n");
    }

    system("pause");
    menuPenjual();
    return;
}

void delCustomer() {
    system("cls");
    FILE *filecustomer, *fileTemp;
    struct customer akun;
    char delakun[100];

    printf("Masukkan username yang akan dihapus: ");
    fflush(stdin);
    gets(delakun);

    filecustomer = fopen("akuncustomer.dat", "rb");
    fileTemp = fopen("temp.dat", "wb");
    if (filecustomer == NULL || fileTemp == NULL) {
        printf("Error dalam membuka file!\n");
        delCustomer();
    }

    int deleted = 0;
    while (fread(&akun, sizeof(akun), 1, filecustomer)) {
        if (strcmp(akun.username, delakun) != 0) {
            fwrite(&akun, sizeof(akun), 1, fileTemp);
        } else {
            deleted = 1;
        }
    }

    fclose(filecustomer);
    fclose(fileTemp);

    if (deleted) {
        remove("akuncustomer.dat");
        rename("temp.dat", "akuncustomer.dat");
        printf("\nData customer dengan username %s telah dihapus.\n", delakun);
    } else {
        remove("temp.dat");
        printf("\nCustomer dengan username %s tidak ditemukan.\n", delakun);
    }

    system("pause");
    menuPenjual();
}

void sortJasa(struct jasa *jasaList, int count) {
    int i, j;
    struct jasa temp;

    for (i = 0; i < count - 1; i++) {
        for (j = 0; j < count - i - 1; j++) {
            if (strcmp(jasaList[j].nama, jasaList[j + 1].nama) > 0) {
                temp = jasaList[j];
                jasaList[j] = jasaList[j + 1];
                jasaList[j + 1] = temp;
            }
        }
    }
}
int compare(const void *a, const void *b) {
    struct jasa *jasaA = (struct jasa *)a;
    struct jasa *jasaB = (struct jasa *)b;
    return strcmp(jasaA->nama, jasaB->nama);
}

int viewJasa() {
    system("cls");
    FILE *filejasa;
    struct jasa *data;
    int count = 0;
    int size = 10;

    data = (struct jasa *)malloc(size * sizeof(struct jasa));
    if (data == NULL) {
        printf("Alokasi Memori gagal!\n");
        system("pause");
        return menuPenjual();
    }

    filejasa = fopen("datajasa.dat", "rb");
    if (filejasa == NULL) {
        printf("Error dalam membuka file!\n");
        system("pause");
        free(data);
        return menuPenjual();
    }

    while (fread(&data[count], sizeof(struct jasa), 1, filejasa)) {
        count++;
        if (count >= size) {
            size *= 2;
            data = (struct jasa *)realloc(data, size * sizeof(struct jasa));
            if (data == NULL) {
                printf("Memory reallocation failed!\n");
                fclose(filejasa);
                system("pause");
                return menuPenjual();
            }
        }
    }

    fclose(filejasa);

    qsort(data, count, sizeof(struct jasa), compare);

    printf("\n==== Daftar Jasa ====\n");
    for (int i = 0; i < count; i++) {
        printf("Nama Jasa: %s\n", data[i].nama);
        printf("Deskripsi: %s\n", data[i].deskripsi);
        printf("Harga: %.2f\n", data[i].harga);
        printf("\n");
    }

    free(data);
    system("pause");
    return menuPenjual();
}


int addJasa() {
    system("cls");
    FILE *filejasa;
    struct jasa data;

    filejasa = fopen("datajasa.dat", "ab");
    if (filejasa == NULL) {
        printf("Error dalam membuka file!\n");
        return 1;
    }

    printf("\n==== Tambah Jasa ====\n");
    fflush(stdin);
    printf("Nama Jasa: ");
    gets(data.nama);
    printf("Deskripsi: ");
    gets(data.deskripsi);
    printf("Harga: ");
    scanf("%f", &data.harga);
    printf("Kontak\t: ");
    scanf("%d", &data.kontak);

    fwrite(&data, sizeof(data), 1, filejasa);
    fclose(filejasa);

    printf("Jasa telah ditambahkan.\n");
    system("pause");
    return menuPenjual();
}


void viewFeedback() {
    system("cls");
    FILE *filefeedback;
    struct feedback *fb;
    int count = 0;
    int size = 10;

    // Alokasi awal untuk array feedback
    fb = (struct feedback *)malloc(size * sizeof(struct feedback));
    if (fb == NULL) {
        printf("Memory allocation failed!\n");
        system("pause");
        return menuPenjual();
    }

    filefeedback = fopen("datafeedback.dat", "rb");
    if (filefeedback == NULL) {
        printf("Error dalam membuka file!\n");
        system("pause");
        free(fb);
        return menuPenjual();
    }

    while (fread(&fb[count], sizeof(struct feedback), 1, filefeedback)) {
        count++;
        if (count >= size) {
            size *= 2;
            fb = (struct feedback *)realloc(fb, size * sizeof(struct feedback));
            if (fb == NULL) {
                printf("Memory reallocation failed!\n");
                fclose(filefeedback);
                system("pause");
                return menuPenjual();
            }
        }
    }

    fclose(filefeedback);

    printf("\n==== Daftar Feedback ====\n");
    for (int i = count - 1; i >= 0; i--) {
        printf("Username: %s\n", fb[i].username);
        printf("Feedback: %s\n", fb[i].feedback);
        printf("\n");
    }

    free(fb);
    system("pause");
    menuPenjual();
}



void searchJasa() {
    system("cls");
    FILE *filejasa;
    struct jasa data;
    char search[100];

    printf("\n==== Cari Jasa ====\n");
    printf("Masukkan nama jasa yang dicari: ");
    fflush(stdin);
    gets(search);

    filejasa = fopen("datajasa.dat", "rb");
    if (filejasa == NULL) {
        printf("Error dalam membuka file!\n");
        return;
    }

    int found = 0;
    while (fread(&data, sizeof(data), 1, filejasa)) {
        if (strcmp(data.nama, search) == 0) {
            printf("Nama Jasa: %s\n", data.nama);
            printf("Deskripsi: %s\n", data.deskripsi);
            printf("Harga: %.2f\n", data.harga);
            printf("Kontak\t: %d\n", data.kontak );
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Jasa dengan nama %s tidak ditemukan.\n", search);
    }

    fclose(filejasa);
    system("pause");
}

void pesanJasa() {
    FILE *fileJasa, *fileOrder;
    struct jasa datajasa;
    struct order newOrder;
    int choice, found = 0;

    viewJasaNoPause();

    printf("Masukkan nomor jasa yang ingin Anda pesan: ");
    scanf("%d", &choice);
    getchar(); 

    fileJasa = fopen("datajasa.dat", "rb");
    if (fileJasa == NULL) {
        printf("Error dalam membuka file jasa!\n");
        return;
    }

    int index = 1;
    while (fread(&datajasa, sizeof(datajasa), 1, fileJasa)) {
        if (index == choice) {
            found = 1;
            break;
        }
        index++;
    }

    fclose(fileJasa);

    if (!found) {
        printf("Jasa dengan nomor %d tidak ditemukan!\n", choice);
        return;
    }

    printf("\nDetail Jasa:\n");
    printf("Nama: %s\n", datajasa.nama);
    printf("Deskripsi: %s\n", datajasa.deskripsi);
    printf("Harga: Rp%.2f\n", datajasa.harga);
    printf("Kontak:\t %d", datajasa.kontak);

    printf("\nApakah Anda yakin ingin memesan jasa ini? (y/n): ");
    char confirm;
    scanf(" %c", &confirm);

    if (confirm == 'y' || confirm == 'Y') {
        // Pastikan 'username' didefinisikan di sini atau diambil dari sumber lain
        extern char username[]; 
        strcpy(newOrder.username, username);
        strcpy(newOrder.serviceName, datajasa.nama);
        newOrder.servicePrice = datajasa.harga;

        fileOrder = fopen("orders.dat", "ab");
        if (fileOrder == NULL) {
            printf("Error dalam membuka file order!\n");
            return;
        }

        fwrite(&newOrder, sizeof(newOrder), 1, fileOrder);
        fclose(fileOrder);

        printf("Anda telah berhasil memesan %s seharga Rp%.2f\n", newOrder.serviceName, newOrder.servicePrice);
        system("pause");
    } else {
        printf("Pemesanan dibatalkan.\n");
        system("pause");
    }
}

void addFeedback() {
    system("cls");
    FILE *filefeedback;
    struct feedback fb;

    printf("\n==== Berikan Feedback ====\n");
    fflush(stdin);
    printf("Feedback: ");
    gets(fb.feedback);
    strcpy(fb.username, username);

    filefeedback = fopen("datafeedback.dat", "ab");
    if (filefeedback == NULL) {
        printf("Error dalam membuka file!\n");
        return;
    }

    fwrite(&fb, sizeof(fb), 1, filefeedback);
    fclose(filefeedback);

    printf("Feedback telah ditambahkan.\n");
    system("pause");
}

void changePass() {
    system("cls");
    FILE *filecustomer, *fileTemp;
    struct customer akun;
    char newPass[100];

    printf("Masukkan password baru: ");
    fflush(stdin);
    gets(newPass);

    filecustomer = fopen("akuncustomer.dat", "rb");
    fileTemp = fopen("temp.dat", "wb");
    if (filecustomer == NULL || fileTemp == NULL) {
        printf("Error dalam membuka file!\n");
        return;
    }

    while (fread(&akun, sizeof(akun), 1, filecustomer)) {
        if (strcmp(akun.username, username) == 0) {
            strcpy(akun.pass, newPass);
        }
        fwrite(&akun, sizeof(akun), 1, fileTemp);
    }

    fclose(filecustomer);
    fclose(fileTemp);

    remove("akuncustomer.dat");
    rename("temp.dat", "akuncustomer.dat");

    printf("Password berhasil diganti.\n");
    system("pause");
}

void delAcc() {
    system("cls");
    FILE *filecustomer, *fileTemp;
    struct customer akun;

    filecustomer = fopen("akuncustomer.dat", "rb");
    fileTemp = fopen("temp.dat", "wb");
    if (filecustomer == NULL || fileTemp == NULL) {
        printf("Error dalam membuka file!\n");
        return;
    }

    while (fread(&akun, sizeof(akun), 1, filecustomer)) {
        if (strcmp(akun.username, username) != 0) {
            fwrite(&akun, sizeof(akun), 1, fileTemp);
        }
    }

    fclose(filecustomer);
    fclose(fileTemp);

    remove("akuncustomer.dat");
    rename("temp.dat", "akuncustomer.dat");

    printf("Akun berhasil dihapus.\n");
    system("pause");
    main();
}


void viewJasaNoPause() {
    FILE *filejasa;
    struct jasa data;

    filejasa = fopen("datajasa.dat", "rb");
    if (filejasa == NULL) {
        printf("Error dalam membuka file!\n");
        return;
    }

    printf("\n==== Daftar Jasa ====\n");
    int index = 1;
    while (fread(&data, sizeof(data), 1, filejasa)) {
        printf("%d. Nama Jasa: %s\n", index, data.nama);
        printf("   Deskripsi: %s\n", data.deskripsi);
        printf("   Harga: %.2f\n", data.harga);
        printf("\n");
        index++;
    }

    fclose(filejasa);
}