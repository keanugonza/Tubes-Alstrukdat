#ifndef INISIALISASI_H
#define INISIALISASI_H

#include <stdio.h>
#include "data.h"
#include "../main.c"
#include "bacatulisConfig/readConfig.c"
#include <sys/stat.h>

boolean checkFolder(char *path);
void pesanpembuka();
void takeConfig();

#endif