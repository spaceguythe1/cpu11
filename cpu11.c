#define _DEFAULT_SOURCE
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
// globals
uint8_t accum = 0b00000000;
int clockvalue = 0;
int count = 0;
int aluz;

void clok(){

    if(clockvalue == 0){
        clockvalue = 1;
    }
    else if(clockvalue == 1){
        clockvalue = 0;
    };

    printf("CLOK = %i\n", clockvalue);

};

void counter(char func[], int set){

    if(((strcmp(func, "upd")) == 0)){
        if(clockvalue == 0){
            printf("clock is drop\n");
        }
        if(clockvalue == 1){
            count += 1;
            printf("clock is up (good) \n");
        }
        printf("COUNT %i\n", count);
    };
    if(((strcmp(func, "set")) == 0)){
        count = set;
    };

};

void alu(char func[]){
    if((strcmp(func,"zero")) == 0){
        printf("Checking for zero...\n");
        if(accum == 0b00000000){
            aluz = 1;
            printf("aluz = 1\n");
        };
        if(accum != 0b00000000){
            aluz = 0;
            printf("aluz = 0\n");
        };
    };
};

int main(){

    char UPPERquery[] = "im very blank and i hope that my length dosent trigger you";
    char FILEquery[] = "oh im a long name oh im a long name oh im a long name oh im a long name oh im a long name oh im a long name oh im a long name oh im a long name oh im a long name oh im a long name oh im a long name oh im a long name oh im a long name oh im a long name oh im a long name oh im a long name oh im a long name oh im a long name oh im a long name oh im a long name oh im a long name oh im a long name oh im a long name oh im a long name oh im a long name oh im a long name oh im a long name oh im a long name oh im a long name oh im a long name oh im a long name oh im a long name oh im a long name oh im a long name oh im a long name oh im a long name oh im a long name oh im a long name oh im a long name oh im a long name oh im a long name oh im a long name oh im a long name oh im a long name oh im a long name oh im a long name oh im a long name ";

    printf("CPU11 -- a cpu/compiler for my cpu\n");
    printf("\n");
    printf("------------\n");
    printf("pick one lol\n");
    printf("------------\n");
    printf("\n");
    printf("run - runs the cpu based off a text file\n");
    scanf("%s", UPPERquery);
    printf("you have selected = %s\n", UPPERquery);
    usleep(50000);

    if((strcmp(UPPERquery, "run" ) == 0) || (strcmp(UPPERquery, "hahasecret" ) == 0)){
        printf("File to run (include /x/y/z.txt to make sure it works): ");
        scanf("%s", FILEquery);

        if((strcmp(FILEquery, "snake" ) == 0)){
            strcpy(FILEquery, "/home/joseph/cpu11/snake.txt");
        };
        if((strcmp(FILEquery, "line" ) == 0)){
            strcpy(FILEquery, "/home/joseph/cpu11/line.txt");
        };
        if((strcmp(FILEquery, "badapple" ) == 0)){
            strcpy(FILEquery, "/home/joseph/cpu11/apple.txt");
        };

        FILE *fiee = fopen(FILEquery, "r");

        if(fiee == NULL){
            printf("\nthats wrong bru\n");
            return 1;
        };


        char bugger[256];
        while (fgets(bugger, sizeof(bugger), fiee) != NULL) {
            printf("%s", bugger);
        };

        usleep(10000);
        system("clear");
        printf("\n");

        uint8_t mem[256] = {0b00000000};
        printf("int mem[256] = {00000000};\n");
        usleep(1000);
        char current[] = "bbb";
        char d1[] = "0b00000000";
        char aa[9];
        printf("char current[] = ''bbb'';\n");
        usleep(1000);
        usleep(1000);
        printf("EMUL START \n\n\n");
        sleep(1);

        // load txt file
        char buffer[256];
        int target_line;
        int current_line = 1;
        int found = 0;

        while (1){
            clok();
            counter("upd", 0);

        if (clockvalue == 1) {




            FILE *file = fopen(FILEquery, "r");

            found = 0;
            target_line = count;
            current_line = 1;
            printf("looking for line: %i\n", target_line);
            while (fgets(buffer, sizeof(buffer), file) != NULL) {
                if (current_line == target_line) {
                    found = 1;
                    break;
                }
                current_line++;
            }
            fclose(file);
            printf("Executing line: %s", buffer);

            current[0] = buffer[0];
            current[1] = buffer[1];
            current[2] = buffer[2];
            printf("\n");
            printf("INSTRUCT: %s\n", current);
            d1[2] = buffer[4];
            d1[3] = buffer[5];
            d1[4] = buffer[6];
            d1[5] = buffer[7];
            d1[6] = buffer[8];
            d1[7] = buffer[9];
            d1[8] = buffer[10];
            d1[9] = buffer[11];
            printf("D1 = %s\n", d1);

            // strcmp my beloved =0 enemy =1

            if(strcmp(current, "SCA") == 0){
                char ba[9];
                printf("8 bit input: ");
                scanf("%8s", ba);
                uint8_t bb = (uint8_t)strtoul(ba, NULL, 2);
                accum = bb;
            };
            if((strcmp(current, "HAL")) == 0){
                printf("Halting...\n");
                return 0;
            };
            if((strcmp(current, "LOD")) == 0){
                accum = (uint8_t)strtol(d1, NULL, 2);
                printf("accum: 0b%08b\n", accum);
            };
            if((strcmp(current, "CLR")) == 0){
                for(int i = 0; i < 256; i++){
                    if(i % 10 == 0){
                        printf("0b%08b\n", mem[i]);
                    }
                    else if(i != 0){
                        printf("0b%08b ", mem[i]);
                    }
                    else if(i == 0){
                        printf("\n0b%08b", mem[i]);
                    };
                    mem[i] = 0b00000000;
                    usleep(1000);
                };
            };
            if((strcmp(current, "STA")) == 0){
                aa[0] = d1[2];
                aa[1] = d1[3];
                aa[2] = d1[4];
                aa[3] = d1[5];
                aa[4] = d1[6];
                aa[5] = d1[7];
                aa[6] = d1[8];
                aa[7] = d1[9];
                aa[8] = '\0';

                int ab = (int)strtol(aa, NULL, 2);
                mem[ab] = accum;
                printf("MEM CHANGE @%s, SET TO 0b%08b\n", aa, accum);
            };

            if((strcmp(current, "LDA")) == 0){
                int ac = (int)strtol(d1 + 2, NULL, 2);
                accum = mem[ac];
                printf("accum: 0b%08b\n", accum);
            };

            if((strcmp(current, "ADD")) == 0){
                int ad = (int)strtol(d1 + 2, NULL, 2);
                accum += mem[ad];
                printf("accum: 0b%08b\n", accum);
            };
            
            if((strcmp(current, "SUB")) == 0){
                int ae = (int)strtol(d1 + 2, NULL, 2);
                accum -= mem[ae];
                printf("accum: 0b%08b\n", accum);
            };
            if((strcmp(current, "AND")) == 0 ){
                int af = (int)strtol(d1 + 2, NULL, 2);
                accum &= mem[af];
                printf("accum: 0b%08b\n", accum);
            };
            if((strcmp(current, "ORR")) == 0){
                int ag = (int)strtol(d1 + 2, NULL, 2);
                accum |= mem[ag];
                printf("accum: 0b%08b\n", accum);
            };

            if((strcmp(current, "TAC")) == 0){
                if (count >= 0 && count <= 65535) {
                    uint16_t u16_count = (uint16_t)count;
                    mem[1] = (uint8_t)((u16_count >> 8) & 0xFF);
                    mem[0] = (uint8_t)(u16_count & 0xFF);
                    printf("TAC: mem[1] = 0x%02X, mem[0] = 0x%02X (Counter: %d)\n", mem[1], mem[0], count);
                } else {
                    printf("OVERFLOW - ESCAPE @ LINE %d\n", count + 1);
                    return 1;
                };
            };
            if((strcmp(current, "JMP")) == 0){
                count = (mem[1] << 8) | mem[0];
                printf("Jumping to line: %d\n", count + 1);
            };

            if((strcmp(current, "JZE")) == 0){
                alu("zero");
                if(aluz == 1){
                    count = (mem[1] << 8) | mem[0];
                    printf("Jumping to line: %d\n", count + 1);
                };
            };

            if((strcmp(current, "DIS")) == 0){
                for(int y = 0; y < 8; y++){
                    uint8_t z = mem[y];
                    char line[] = "00000000";
                    for(int x = 0; x < 8; x++){
                        if ((z >> x) & 1) {
                            line[x] = '#';
                        } else {
                            line[x] = ' ';
                        };
                    };
                    printf("%s\n", line);
                };
            };
            if((strcmp(current, "DIF")) == 0){
                system("clear");
                for(int y = 0; y < 16; y++){
                    uint8_t z = mem[y*2];
                    uint8_t zx = mem[(y*2)+1];
                    char line[] = "0000000000000000";
                    for(int x = 0; x < 8; x++){
                        if ((z >> x) & 1) {
                            line[x] = '#';
                        } else {
                            line[x] = ' ';
                        };
                    };
                    for(int x = 0; x < 8; x++){
                        if ((zx >> x) & 1) {
                            line[x+8] = '#';
                        } else {
                            line[x+8] = ' ';
                        };
                    };
                    printf("%s\n", line);
                };
                printf("count: %i\n", count);
                usleep(10000);
            };
            if((strcmp(current, "BLK")) == 0){
                printf("Instruction BLK, Nothing to do!");
            };

            printf("\n");
        };
        };

    };

    return 0;
};
