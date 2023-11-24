#include "inisialisasi.h"

boolean checkFolder(char *path) {
    struct stat statbuf;
    if (stat(path, &statbuf) != 0) {
        return 0;
    }
    return S_ISDIR(statbuf.st_mode);
}

void pesanpembuka(){
    printf(".______    __    __  .______      .______    __  .______ \n");
    printf("|   _  \\  |  |  |  | |   _  \\     |   _  \\  |  | |   _  \\\n");
    printf("|  |_)  | |  |  |  | |  |_)  |    |  |_)  | |  | |  |_)  |\n");
    printf("|   _  <  |  |  |  | |      /     |   _  <  |  | |      /\n");
    printf("|  |_)  | |  `--'  | |  |\\  \\----.|  |_)  | |  | |  |\\ \\----.\n");
    printf("|______/   \\______/  | _| `._____||______/  |__| | _| `._____|   \n");
    printf("\n");
    printf("Selamat datang di BurBir.\n");
    printf("\n");
    printf("Aplikasi untuk studi kualitatif mengenai perilaku manusia dengan menggunakan metode\n(pengambilan data berupa) Focused Group Discussion kedua di zamannya.\n");
    printf("Silahkan masukan folder konfigurasi untuk dimuat: ");
    takeConfig();
    printf("\n");
    printf("File konfigurasi berhasil dimuat! Selamat berkicau!\n");
}

void takeConfig(){
    Word pathCheck, path;
    STARTWORD();
    do{
        for(;;){
            path = currentWord;
            pathCheck = currentWord;
            pathCheck.TabWord[path.Length] = '\0';
            if(checkFolder(pathCheck.TabWord)){
                break;
            }else{
                printf("\nFolder tidak ditemukan, silahkan ulangi input!\n");
                ADVWORD_takeBlank();
            }
        }
    }while(!checkFolder(path.TabWord));
    Word penggunaPath, kicauanPath, balasanPath, drafPath, utasPath, folderConfig;
    folderConfig = stringToWord("config/");
    penggunaPath = concateWord(folderConfig, concateWord(path, stringToWord("/pengguna.config")));
    kicauanPath = concateWord(folderConfig, concateWord(path, stringToWord("/kicauan.config")));
    balasanPath = concateWord(folderConfig, concateWord(path, stringToWord("/balasan.config")));
    drafPath = concateWord(folderConfig, concateWord(path, stringToWord("/draf.config")));
    utasPath = concateWord(folderConfig, concateWord(path, stringToWord("/utas.config")));
    
}