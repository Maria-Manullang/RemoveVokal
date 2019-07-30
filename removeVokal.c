#include <stdio.h>
#include <string.h>
#ifndef FALSE
#define FALSE 0
#endif
#ifndef TRUE
#define TRUE 1
#endif

//program ini akan menghapus semua huruf vokal kecuali huruf vokal diawal kalimat


void func (char *ptr)
{
    int begin = TRUE;
    int cnt   = 0;

    while(ptr[cnt] != 0) {
        switch(ptr[cnt]) {


        	//huruf hidup dimasukkan kedalam case
        case 'a': case 'e': case 'i': case 'o': case 'u':
        case 'A': case 'E': case 'I': case 'O': case 'U':


			if (begin == FALSE) {					//jika huruf tidak ada di case
                strcpy(ptr + cnt, ptr + (cnt + 1));
            }
			else {					//jika huruf ada di case, lewatkan
                begin = FALSE;
                cnt   = cnt + 1;
            }
            break;

		//case ada spasi
		case ' ':
            begin = TRUE;
            cnt   = cnt + 1;
        default:
            if (begin == TRUE) {
                begin = FALSE;
            }
            cnt = cnt + 1;
            break;
        }
    }
}

int main (void)
{
    char buf[1 << 7] = { 0 };							//deklarasi variabel buf, ini sebenarnya maksudnya buat variabel namanya buf, tipenya array, sizenya 2^1 s.d 2^7
    													//set nilainya/isinya diawal itu kosong. Bukan NULL ya!
    													//kalau tidak salah ya hahaha

    printf("Input : ");
    fgets(buf, sizeof(buf) - 1, stdin); 				//fgets itu fungsi yang disediakan oleh C. Cari referensi yah :)
    													//jadi.. line 58 artinya begini
    													//itu semacam looping for nya
    													//param buf itu macam permulaannya. jadi dimulai dari 0, lihat line 55
    													//param sizeof(buf)-1 itu artinya size bufnya terus dikurang"i 1
    													//param stdin, sebenarnya ini juga fungsi. namun dijadikan parameter yang fungsinya untuk menerima inputan user

    if (buf[strlen(buf) - 1] == 0xa) {					//ini semacam pengecekan ajanya.
        buf[strlen(buf) - 1] = 0;						//dilihat-lihat aja ya.
    }

    func(buf);											//pemanggilan fungsi func, dengan parameter buf

    printf("Output : %s\n", buf);

    return(0);
}
