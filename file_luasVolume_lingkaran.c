#include <stdio.h>
#include <string.h>

void hitungSilinder(float *radius, float *tinggi, float *volume, float *luasPermukaan) {
    const float PI = 3.14159;
    *volume = PI * (*radius) * (*radius) * (*tinggi);
    *luasPermukaan = 2 * PI * (*radius) * ((*radius) + (*tinggi));
}

int main() {
    float radius, tinggi, volume, luasPermukaan;
    FILE *input, *output;
    char line[100];
    char count;

    input = fopen("radius_tinggi.txt", "r");
    if(input == NULL){
        printf("gagal membaca data pada file\n");
        return 1;
    }

    output = fopen("volume_luaspermukaan.txt", "w");
    if(output == NULL){
        printf("Gagal membuka file\n", "w");
        fclose(input);
        return 1;
    }

    fprintf(output, "          HASIL PERHITUNGAN\n");
    fprintf(output, "=====================================\n");

    while (fgets(line, sizeof(line), input)) {
        if (strncmp(line, "radius = ", 8) == 0){
            sscanf(line, "radius = %f", &radius);

            if (fgets(line, sizeof(line), input) && strncmp(line, "tinggi = ", 8) == 0) {
                sscanf(line, "tinggi = %f", &tinggi);

            
            hitungSilinder(&radius, &tinggi, &volume, &luasPermukaan);

            count++;

            fprintf(output, "Silinder ke-%d:\n", count);
            fprintf(output, "Radius: %.2f cm\n", radius);
            fprintf(output, "Tinggi: %.2f cm\n", tinggi);
            fprintf(output, "Volume: %.2f cm^3\n", volume);
            fprintf(output, "Luas Permukaan: %.2f cm^2\n", luasPermukaan);
            fprintf(output, "-------------------------\n\n");
        }
        
    }
}

    fprintf(output, "\nTotal silinder yang dihitung: %d\n", count);
    printf("\nTotal silinder yang dihitung: %d\n", count);
    printf("Hasil telah disimpan ke dalam file 'volume_luaspermukaan.txt'\n");
    
    fclose(input);
    fclose(output);
    

    return 0;
}
