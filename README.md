# Media Sosial BurBir
> Tugas Besar Algoritma dan Struktur Data Kelas 02 Kelompok G **[IF2110_TB_02_G]**
> 
> Oleh Kelompok G:<br>
> 1. 13522061 Maximilian Sulistiyo<br>
> 2. 13522082 Keanu Amadius Gonza W.<br>
> 3. 13522094 Andhika Tantyo Anugrah<br>
> 4. 13522107 Rayendra Althaf Taraka Noor<br>
> 5. 13522112 Dimas Bagoes Hendrianto<br>
> 
> Sekolah Teknik Elektro dan Informatika<br>
> Institut Teknologi Bandung<br>
> Semester III Tahun 2023/2024

Pada tugas besar ini kami diminta untuk mengimplementasikan bermacam - macam jenis struktur data yang telah diajarkan di mata kuliah IF2110 Algoritma dan Struktur Data. Dalam hal ini asisten menugaskan mahasiswa untuk membuat sebuah aplikasi media sosial bernama “BurBir”. Program ini berdasarkan CLI dan dibuat menggunakan bahasa C. Pada program BurBir ini mahasiswa diminta untuk membuat fitur-fitur seperti pengguna, profil, teman, permintaan pertemanan, kicauan, balasan, draf kicauan, dan utas. Tak lupa juga dibuat program untuk proses inisialisasi dan daftar perintah yang akan dipanggil ketika menjalankan program. Selain itu mahasiswa diminta untuk membuat sebuah fitur muat agar program dapat membaca dan menyimpan pada file config.

## Table of Contents
* [Getting started](#getting-started)
* [Developing](#developing)
* [Building](#building)
* [Features](#features)
* [Credits](#tabel-pembagian-kerja)
* [Program's Specification](#spesifikasi-program)
* [Links](#links)

## Getting started

Needs <em>make</em> in order to automate run. Linux based OS recommended for running.

```shell
cd ./src
make
```

Here, <em>make</em> program will run as scripted, the user can type <code>./main</code> to run the program.

## Developing

Here's a brief intro about what a developer must do in order to start developing
the project further:

```shell
git clone https://github.com/keanugonza/Tubes-Alstrukdat
cd Tubes-Alstrukdat/
```

Start developing in your favorite IDE.

### Building

Additional steps for the developer to build the project after some code changes.

```shell
cd ./src
make
```

Here, make will clean and recompile everything. Devs can type <code>./main</code> to run and test the program.

## Features

What's all the bells and whistles this project can perform?
* BurBir Social Media

## Tabel Pembagian Kerja
<table>
    <tr>
      <td><b>NIM</b></td>
      <td><b>Nama</b></td>
      <td><b>Pembagian Pekerjaan</b></td>
    </tr>
    <tr>
      <td>13522061</td>
      <td>Maximilian Sulistiyo</td>
      <td>Mengerjakan fitur utas dan graph pertemanan serta bagian laporan fitur tersebut.</td>
    </tr>
    <tr>
      <td>13522082</td>
      <td>Keanu Amadius Gonza W.</td>
      <td>PMengerjakan seluruh fitur yang berkaitan dengan kicauan dan draf. Membuat dan menyatukan main.</td>
    </tr>
    <tr>
      <td>13522094</td>
      <td>Andhika Tantyo Anugrah</td>
      <td>Membuat ADT Prioqueue, permintaan_pertemanan, Makefile, bagian laporan ADT tersebut, README, serta membuat config untuk permintaan_pertemanan dan merapikan config secara umum.</td>
    </tr>
    <tr>
      <td>13522107</td>
      <td>Rayendra Althaf Taraka Noor</td>
      <td>Mengerjakan fitur balasan, wordmachine, charmachine, muat, dan bagian laporan ADT tersebut.</td>
    </tr>
    <tr>
      <td>13522112</td>
      <td>Dimas Bagoes Hendrianto</td>
      <td>Mengerjakan fitur berhubungan dengan pengguna beserta profil, laporan bagian tersebut, serta notulen asistensi.</td>
    </tr>
</table>

## Spesifikasi Program
<table>
    <tr>
      <td><b>Function Name</b></td>
      <td><b>Progress</b></td>
    </tr>
    <tr>
      <td>Inisialisi</td>
      <td>Done</td>
    </tr>
    <tr>
      <td>Perintah</td>
      <td>Done</td>
    </tr>
    <tr>
      <td>Pengguna: DAFTAR</td>
      <td>Done</td>
    </tr>
    <tr>
      <td>Pengguna: MASUK</td>
      <td>Done</td>
    </tr>
    <tr>
      <td>Pengguna: KELUAR</td>
      <td>Done</td>
    </tr>
    <tr>
      <td>Pengguna: TUTUP_PROGRAM</td>
      <td>Done</td>
    </tr>
    <tr>
      <td>Profil: GANTI_PROFIL</td>
      <td>Done</td>
    </tr>
    <tr>
      <td>Profil: LIHAT_PROFIL [NAMA]</td>
      <td>Done</td>
    </tr>
    <tr>
      <td>Profil: ATUR_JENIS_AKUN</td>
      <td>Done</td>
    </tr>
    <tr>
      <td>Profil: UBAH_FOTO_PROFIL</td>
      <td>Done</td>
    </tr>
    <tr>
      <td>Teman: DAFTAR_TEMAN</td>
      <td>Done</td>
    </tr>
    <tr>
      <td>Teman: HAPUS_TEMAN</td>
      <td>Done</td>
    </tr>
    <tr>
      <td>Permintaan Pertemanan: TAMBAH_TEMAN</td>
      <td>Done</td>
    </tr>
    <tr>
      <td>Permintaan Pertemanan: DAFTAR_PERMINTAAN_PERTEMANAN</td>
      <td>Done</td>
    </tr>
    <tr>
      <td>Permintaan Pertemanan: SETUJUI_PERTEMANAN</td>
      <td>Done</td>
    </tr>
    <tr>
      <td>Kicauan: KICAU</td>
      <td>Done</td>
    </tr>
    <tr>
      <td>Kicauan: KICAUAN</td>
      <td>Done</td>
    </tr>
    <tr>
      <td>Kicauan: SUKA_KICAUAN [IDKicau]</td>
      <td>Done</td>
    </tr>
    <tr>
      <td>Kicauan: UBAH_KICAUAN [IDKicau]</td>
      <td>Done</td>
    </tr>
    <tr>
      <td>Balasan: BALAS [IDKicau] [IDBalasan]</td>
      <td>Done</td>
    </tr>
    <tr>
      <td>Balasan: BALASAN [IDKicau]</td>
      <td>Done</td>
    </tr>
    <tr>
      <td>Balasan: HAPUS_BALASAN [IDKicau] [IDBalasan]</td>
      <td>Done</td>
    </tr>
    <tr>
      <td>Draf Kicauan: BUAT_DRAF</td>
      <td>Done</td>
    </tr>
    <tr>
      <td>Draf Kicauan: LIHAT_DRAF</td>
      <td>Done</td>
    </tr>
    <tr>
      <td>Utas: UTAS [IDKicau]</td>
      <td>Done</td>
    </tr>
    <tr>
      <td>Utas: SAMBUNG_UTAS [IDUtas] [index]</td>
      <td>Done</td>
    </tr>
    <tr>
      <td>Utas: HAPUS_UTAS [IDUtas] [index]</td>
      <td>Done</td>
    </tr>
    <tr>
      <td>Utas: CETAK_UTAS [IDUtas]</td>
      <td>Done</td>
    </tr>
    <tr>
      <td>Simpan dan Muat: SIMPAN</td>
      <td>Not Done</td>
    </tr>
    <tr>
      <td>Simpan dan Muat: MUAT</td>
      <td>Done</td>
    </tr>
</table>

## Links

- [Spesifikasi Tugas Besar IF2110 Algoritma dan Struktur Data](https://docs.google.com/document/d/1yy0SLsXEE0e-ZBxMSrd0Gz9AOSWqJw1trtTqDjeyfsk/edit)
- [Repository](https://github.com/keanugonza/Tubes-Alstrukdat)
- [Laporan Tugas Besar [email std]](https://docs.google.com/document/d/13FiCwNaodDXhQTX-_tc6YiBfYZEoP3xyrRykBRO1lnw/edit?usp=sharing)